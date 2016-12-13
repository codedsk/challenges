#include "soln.cc"
#include <gtest/gtest.h>

TEST (Path2StringTest, ValidPaths) {
    vector<string> p1 {"a","b","c"};
    ASSERT_STREQ("a.b.c",path2string(p1).c_str());

    vector<string> p2 {"a"};
    ASSERT_STREQ("a",path2string(p2).c_str());

    vector<string> p3 {};
    ASSERT_STREQ("",path2string(p3).c_str());
}

TEST (StringifyTagDetailTest, ValidTagObjects) {
    Attribute a1 = {"value","\"HelloWorld\""};
    Attribute a2 = {"name","\"Name1\""};

    // name, opentag, attributes
    TagDetail t1 = { "tag1", true, {} };

    const char *r1 = "Tag name: tag1\n    opentag: 1\n    attrs: \n";

    TagDetail t2 = { "tag2", true, {a1} };

    const char *r2 = "Tag name: tag2\n    opentag: 1\n    attrs: \n        value -> \"HelloWorld\"\n";

    TagDetail t3 = { "tag3", true, {a2} };

    const char *r3 = "Tag name: tag3\n    opentag: 1\n    attrs: \n        name -> \"Name1\"\n";

    TagDetail t4 = { "tag4", true, {a1,a2} };

    const char *r4 = "Tag name: tag4\n    opentag: 1\n    attrs: \n        value -> \"HelloWorld\"\n        name -> \"Name1\"\n";

    TagDetail t5 = { "tag5", false, {} };

    const char *r5 = "Tag name: tag5\n    opentag: 0\n    attrs: \n";


    ASSERT_STREQ(r1,stringifyTagDetail(t1).str().c_str());
    ASSERT_STREQ(r2,stringifyTagDetail(t2).str().c_str());
    ASSERT_STREQ(r3,stringifyTagDetail(t3).str().c_str());
    ASSERT_STREQ(r4,stringifyTagDetail(t4).str().c_str());
    ASSERT_STREQ(r5,stringifyTagDetail(t5).str().c_str());
}

TEST (ParseHrmlLineTest, ValidHrml) {
    string hrml1 = "<tag1>";
    string hrml2 = "<tag2 value = \"HelloWorld\">";
    string hrml3 = "<tag3 name = \"Name1\">";
    string hrml4 = "<tag4 value = \"HelloWorld\" name = \"Name1\">";
    string hrml5 = "</tag1>";

    Attribute a1 = {"value","\"HelloWorld\""};
    Attribute a2 = {"name","\"Name1\""};

    TagDetail t1 = { "tag1", true, {} };
    TagDetail t2 = { "tag2", true, {a1} };
    TagDetail t3 = { "tag3", true, {a2} };
    TagDetail t4 = { "tag4", true, {a1,a2} };
    TagDetail t5 = { "tag1", false, {} };

    /*
    cout << stringifyTagDetail(t5).str();
    cout << stringifyTagDetail(parse_hrml_line(hrml5)).str();
    */

    ASSERT_EQ(t1,parse_hrml_line(hrml1));
    ASSERT_EQ(t2,parse_hrml_line(hrml2));
    ASSERT_EQ(t3,parse_hrml_line(hrml3));
    ASSERT_EQ(t4,parse_hrml_line(hrml4));
    ASSERT_EQ(t5,parse_hrml_line(hrml5));
}


TEST (DigestHRMLTest, ValidHrml) {

    map<string,string> hrml_map;

    // tag without attributes should not be stored
    stringstream hrml1;
    hrml1.str("<tag1>");
    digestHRML(hrml1,1,hrml_map);
    ASSERT_EQ(size_t(0),hrml_map.size());
    hrml_map.clear();

    stringstream hrml2;
    hrml2.str("<tag1>\n<tag2 value = \"HelloWorld\">");
    digestHRML(hrml2,2,hrml_map);
    ASSERT_EQ(size_t(1),hrml_map.size());
    ASSERT_STREQ("HelloWorld",hrml_map["tag1.tag2~value"].c_str());
    hrml_map.clear();

    stringstream hrml3;
    hrml3.str("<tag1>\n"
              "<tag2 value = \"HelloWorld\">\n"
              "<tag3 name = \"Name1\">");
    digestHRML(hrml3,3,hrml_map);
    ASSERT_EQ(size_t(2),hrml_map.size());
    ASSERT_STREQ("HelloWorld",hrml_map["tag1.tag2~value"].c_str());
    ASSERT_STREQ("Name1",hrml_map["tag1.tag2.tag3~name"].c_str());
    hrml_map.clear();

    stringstream hrml4;
    hrml4.str("<tag4 value = \"HelloWorld\" name = \"Name1\">");
    digestHRML(hrml4,1,hrml_map);
    ASSERT_EQ(size_t(2),hrml_map.size());
    ASSERT_STREQ("HelloWorld",hrml_map["tag4~value"].c_str());
    ASSERT_STREQ("Name1",hrml_map["tag4~name"].c_str());
    hrml_map.clear();

    stringstream hrml5;
    hrml5.str("</tag1>");
    digestHRML(hrml5,1,hrml_map);
    ASSERT_EQ(size_t(0),hrml_map.size());
    hrml_map.clear();

}


int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
