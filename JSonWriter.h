#pragma once 
#include <iostream>
#include <map>
#include <memory>
#include "Nodes.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
namespace Gta4Roy {
    namespace XMLJSONConvertor
    {
        using namespace std;
        class JSonWriter
        {
            public:
                JSonWriter(const std::string & xmlFileName,const Node & rootNode);
                void writeJson();

            private:

               // rapidjson::Value & createJSonObject(const Node & nodeObject,rapidjson::Value & jsonObject);
                const std::string & m_fileName;
                const Node & m_rootNode;
                rapidjson::Document mRootDocument;
        };
    }
}