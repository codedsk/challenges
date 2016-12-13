#include <iostream>
#include <sstream>
#include <string>

int main() {
    // std::string s1 = "<tag1 value = \"HelloWorld\">";
    std::string s1 = "<tag1 value = \"HelloWorld\" name = \"Name1\">";
    std::string tagname;
    std::string aname;
    std::string avalue;
    std::stringstream ss;

    std::cout << "s: " << s1 << std::endl;
    std::cout << "len: " << s1.length() << std::endl;

    // pick off the angle brackets
    ss.str(s1.substr(1,(s1.length()-2)));
    std::cout << "ss: " << ss.str() << std::endl;
    std::cout << "len: " << ss.str().length() << std::endl;

    // grab the tagname
    ss >> tagname;
    std::cout << "tag: " << tagname << std::endl;

    // parse the attributes
    while (ss) {
        ss >> aname >> avalue >> avalue;
        std::cout << "attribute: " << aname << " -> " << avalue << std::endl;
        ss.peek();
    }

    return 0;
}
