#include "XMLReader.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>

using namespace std;
using namespace xercesc;

namespace Gta4Roy {
    namespace XMLJSONConvertor
    {
        XMLReader::XMLReader(const std::string & xmlFileName,Node & rootNode)
        :
            m_fileName(xmlFileName),
            m_rootNode(rootNode)
        {

        }

        void XMLReader::DomNodeParser(DOMNode * nodeItem,Node & elementNode)
        {
            if(nodeItem->getNodeType() && nodeItem->getNodeType() == DOMNode::ELEMENT_NODE)
            {
                char * nodeNameS = XMLString::transcode(nodeItem->getNodeName());  

                elementNode.setNodeName(nodeNameS);
                elementNode.setNodeType(NodeType::ELEMENT_NODE);

                if(nodeItem->hasAttributes())
                {
                   DOMNamedNodeMap * attributeMaps = nodeItem->getAttributes();
                   int sizeOfAttributes = attributeMaps->getLength();
                   for(int i = 0 ; i < sizeOfAttributes ; i++)
                   {
                       DOMNode * attributeDom= attributeMaps->item(i);
                       char * attributeName = XMLString::transcode(attributeDom->getNodeName());  
                       char * attributeValue = XMLString::transcode(attributeDom->getNodeValue());  
                       elementNode.addAttribute(attributeName,attributeValue);
                   }
                }

                if(nodeItem->hasChildNodes())
                {
                    DOMNodeList * elementChilds = nodeItem->getChildNodes();
                    
                    for(int i = 0; i < elementChilds->getLength() ; i++)
                    {
                        Node childNodeData;
                        elementNode.addChildNode(childNodeData);
                        DomNodeParser(elementChilds->item(i),elementNode.getChildNodeModifieble(i));
                    }
                }
            }
            else if(nodeItem->getNodeType() && nodeItem->getNodeType() == DOMNode::TEXT_NODE)
            {
                char * nodeNameSt = XMLString::transcode(nodeItem->getNodeValue());
                char * parentNodeName = XMLString::transcode(nodeItem->getParentNode()->getNodeName());
                std::string nodeValue = std::string(nodeNameSt);
                nodeValue.erase(std::remove(nodeValue.begin(), nodeValue.end(), '\n'),nodeValue.end());
                nodeValue.erase(std::remove(nodeValue.begin(), nodeValue.end(), '\t'),nodeValue.end());
                if(!nodeValue.empty())
                {
                    elementNode.setNodeValue(nodeNameSt);
                    elementNode.setNodeType(NodeType::TEXT_NODE);
                }
                else 
                {
                    elementNode.setNodeType(NodeType::SKIP_NODE);
                }           
            } 
        }

        void XMLReader::read()
        {
            // Initialize xerces
            try 
            { 
                XMLPlatformUtils::Initialize(); 
                m_parser.reset(new XercesDOMParser());
                m_parser->setValidationScheme(XercesDOMParser::Val_Never);
                m_parser->setDoNamespaces(false);
                m_parser->setDoSchema(false);
                m_parser->setValidationConstraintFatal(false);
                m_parser->parse(XMLString::transcode(m_fileName.c_str()));

                DOMElement * docRootNode;
                DOMDocument * doc;
           
                doc = m_parser->getDocument();
                std::string NodeName=  XMLString::transcode(doc->getNodeName());
                m_rootNode.setNodeName(NodeName);

                docRootNode = doc->getDocumentElement();
                if(!docRootNode)
                {
                    std::cout <<"Empty XML";
                   return;
                }
                DOMNodeList * childNodes = docRootNode->getChildNodes();
                int noOfChild = childNodes->getLength();

                for(int i = 0; i < noOfChild; i++)
                {         
                    DOMNode * currentItem = childNodes->item(i);
                    Node nodeElement ;
                    std::string childNodeName = XMLString::transcode(currentItem->getNodeName());
                    nodeElement.setNodeName(childNodeName);
                    m_rootNode.addChildNode(nodeElement);
                    DomNodeParser(currentItem,m_rootNode.getChildNodeModifieble(i));             
                }     

                std::cout <<"Parsing completed\n";    
                m_rootNode.print();      

            }
            catch (const XMLException& toCatch) 
            {
                char* message = XMLString::transcode(toCatch.getMessage());
                cout << "Error during initialization! :\n"
                    << message << "\n";
                XMLString::release(&message);
            }
        }
    }
}