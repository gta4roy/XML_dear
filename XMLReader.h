#pragma once 
#include <iostream>
#include <map>
#include <memory>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include "Nodes.h"
namespace Gta4Roy {
    namespace XMLJSONConvertor
    {
        using namespace std;
        using namespace xercesc;
        class XMLReader
        {
            public:
                XMLReader(const std::string & xmlFileName,Node & rootNode);
                void read();
            private:

                void DomNodeParser(DOMNode * nodeItem,Node & elementNode);
                const std::string & m_fileName;
                std::map<std::string,std::pair<int,int> > parsedXMLData;
                std::unique_ptr<XercesDOMParser> m_parser;
                Node & m_rootNode;
        };
    }
}