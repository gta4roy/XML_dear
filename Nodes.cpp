#include "Nodes.h"
#include <map>

namespace Gta4Roy {
    namespace XMLJSONConvertor{
            using namespace std;

            Node::Node()
            {
                this->nodeName="";
                this->nodeValue="";
            }
            void Node::setNodeName(std::string nodeName)
            {
                this->nodeName = nodeName;
            }
            std::string Node::getNodeName() const
            {
                return this->nodeName;
            }

            void Node::setNodeValue(std::string  nodeValue)
            {
                this->nodeValue = nodeValue;
            }
            std::string Node::getNodeValue() const
            {
                return this->nodeValue;
            }

            void Node::addChildNode(Node elementNode)
            {
                this->childNodes.push_back(elementNode);
            }
            int  Node::getChildCount() const
            {
                return (int)this->childNodes.size();
            }
            const Node & Node::getChildNode(int index) const
            {
                return this->childNodes.at(index);
            }
            Node & Node::getChildNodeModifieble(int index)
            {
                return this->childNodes.at(index);
            }
            void Node::addAttribute(std::string key, std::string value)
            {
                this->attributeMap[key] = value;
            }

            std::string Node::getAttributeValue(std::string key)
            {
                return this->attributeMap[key];
            }
            std::vector<std::string> Node::getAttributeNames() const
            {
                std::vector<std::string> keySets;
                for(const std::pair<std::string , std::string> & element: attributeMap)
                {
                    keySets.push_back(element.first);
                }
                return keySets;
            }
            void Node::setNodeType(NodeType nodeType)
            {
                this->nodeType = nodeType;
            }
            NodeType Node::getNodeType() const
            {
                return this->nodeType;
            }
            void Node::print() const
            {
                if(this->nodeType != NodeType::SKIP_NODE)
                {
                      cout <<"\n-----------------Node---------------";    
                    cout << "\nName:"<< this->nodeName;
                    cout << "\nValue:"<< this->nodeValue;
                
                    for(const std::pair<std::string , std::string> & mapPair : this->attributeMap)
                    {   
                        cout << "\n Attribute";
                        cout << std::endl;
                        cout <<"\t\t";
                        cout << mapPair.first;
                        cout <<"=";
                        cout << mapPair.second;
                    }
                    for(const Node & e: this->childNodes)
                    {
                        e.print();
                    }
                }
            }
    }
}