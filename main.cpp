#include<iostream>
#include "XMLReader.h"
#include "JSonWriter.h"
#include "Nodes.h"
using namespace std;
/*
    XML to JSON and JSON to XML
*/
using namespace  Gta4Roy::XMLJSONConvertor;
int main()
{
    std::cout <<"Reading XML Values ";
    Node  m_rootNode;
    XMLReader xmlReader("sample2.xml",m_rootNode);
    xmlReader.read();
    JSonWriter jsonWriter("sampleJson.json",m_rootNode);
    //jsonWriter.writeJson();
}