#pragma once 
#include <iostream>
#include <map>
#include <memory>
#include <vector>

namespace Gta4Roy {
    namespace XMLJSONConvertor
    {
        using namespace std;

        enum class NodeType
        {
            ELEMENT_NODE,TEXT_NODE,SKIP_NODE
        };

        class Node;
        class Node
        {
            public:
                Node();
                void setNodeName(std::string  nodeName);
                std::string getNodeName() const;

                void setNodeValue(std::string nodeValue);
                std::string getNodeValue() const;

                void setNodeType(NodeType nodeType);
                NodeType getNodeType() const;

                void addChildNode(Node elementNode);
                int  getChildCount() const;
                const Node & getChildNode(int index) const;
                Node & getChildNodeModifieble(int index);

                void addAttribute(std::string  key, std::string value);
                std::string getAttributeValue(std::string key);
                std::vector<std::string> getAttributeNames() const;

                void print() const;
            private:
                std::vector<Node>                 childNodes;
                std::map<std::string,std::string> attributeMap;
                std::string                       nodeValue;
                std::string                       nodeName;
                NodeType                          nodeType;
        };
    }
}