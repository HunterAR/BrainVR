#include "xmlparser.h"

XMLParser::XMLParser()
{

    // tag::code[]
        pugi::xml_document doc;

//        if (!doc.load_file("XMLExample_case.xml")) return -1;
        pugi::xml_parse_result result = doc.load_file("/Users/nimibassi/DesignProject/XMLExample_case.xml");

        cout << "Load result: " << result.description() << ", Case #: " << doc.child("case").attribute("caseid").value() << endl;
    // end::code[]

        for (pugi::xml_node node = doc.child("case").first_child(); node; node = node.next_sibling()) {

            cout << node.name() << ": " << node.child_value() << endl;
            for (pugi::xml_node_iterator it = node.begin(); it != node.end(); ++it){
                cout << it->name() << ": " << it->child_value() <<endl;
            }

        }

        cout << endl;

        // tag::code[]
        pugi::xml_parse_result parseRes = doc.load_file("/Users/nimibassi/DesignProject/XMLExample_study.xml");
        cout << "Load result: " << parseRes.description() << ", Study #: " << doc.child("study").attribute("userid").value() << endl;

        for (pugi::xml_node node = doc.child("study").first_child(); node; node = node.next_sibling()) {

            cout << node.name() << ": " << node.child_value() << endl;
            for (pugi::xml_node_iterator it = node.begin(); it != node.end(); ++it){
                cout << it->name() << ": " << it->child_value() <<endl;
            }

        }
        // end::code[]

}
