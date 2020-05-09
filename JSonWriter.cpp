#include "JSonWriter.h"
#include "Nodes.h"
namespace Gta4Roy {
    namespace XMLJSONConvertor
    {
        using namespace std;
        using namespace rapidjson;

        JSonWriter::JSonWriter(const std::string & xmlFileName,const Node & rootNode)
        :
            m_fileName(xmlFileName),
            m_rootNode(rootNode)
        {
            rapidjson::Document document;
 
            // define the document as an object rather than an array
            document.SetObject();
        
            // create a rapidjson array type with similar syntax to std::vector
            rapidjson::Value array(rapidjson::kArrayType);
        
            // must pass an allocator when the object may need to allocate memory
            rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
        
            // chain methods as rapidjson provides a fluent interface when modifying its objects
            array.PushBack("hello", allocator).PushBack("world", allocator);//"array":["hello","world"]
        
            document.AddMember("Name", "XYZ", allocator);
            document.AddMember("Rollnumer", 2, allocator);
            document.AddMember("array", array, allocator);
        
            // create a rapidjson object type
            rapidjson::Value object(rapidjson::kObjectType);
            object.AddMember("Math", "50", allocator);
            object.AddMember("Science", "70", allocator);
            object.AddMember("English", "50", allocator);
            object.AddMember("Social Science", "70", allocator);
            document.AddMember("Marks", object, allocator);
            //	fromScratch["object"]["hello"] = "Yourname";
        
            StringBuffer strbuf;
            Writer<StringBuffer> writer(strbuf);
            document.Accept(writer);
            std::cout << strbuf.GetString() << std::endl;

        }    

        // rapidjson::Value &  JSonWriter::createJSonObject(const Node & nodeObject,rapidjson::Value & jsonObject)
        // {
            
        // }

        void JSonWriter::writeJson()
        {
            rapidjson::Document document;
 
            // define the document as an object rather than an array
            document.SetObject();

          //  document = createJSonObject(m_rootNode,document.GetObject());
        }     
    }
}