#include <vector>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;

string path2string(vector<string> p) {
    string s = "";
    for (auto &i : p) {
        s = s + i + ".";
    }
    if (s.length() > 0) {
        s.pop_back();
    }
    return s;
}

struct Attribute {
    string key;
    string value;

    bool operator==(const Attribute& rhs) const {
        return key == rhs.key && value == rhs.value;
    }
};

struct TagDetail {
    string name;
    bool opentag;
    vector<Attribute> attributes;

    bool operator==(const TagDetail& rhs) const {
        return name == rhs.name
            && opentag == rhs.opentag
            && attributes == rhs.attributes;
    }
};

TagDetail parse_hrml_line(string hrml) {
    TagDetail t;

    if (hrml[1] == '/') {
        // closing tag
        t.opentag = false;
        t.name = hrml.substr(2,(hrml.length()-3));
        // exit function early
        // nothing else in tag to process
        return t;
    }

    // opening tag
    t.opentag = true;

    // pick off the angle brackets
    stringstream ss;
    ss.str(hrml.substr(1,(hrml.length()-2)));

    // parse the tag name
    ss >> t.name;

    // check to see if there are attributes
    // if not, ss's internal error flag will be set
    // and we will skip the while loop
    ss.peek();

    // parse the attributes
    while (ss) {
        string junk;
        Attribute a;
        // attributes have the form: name = "value"
        ss >> a.key >> junk >> a.value;
        t.attributes.push_back(a);
        // set internal error flag if end of attributes
        ss.peek();
    }

    return t;
}

stringstream stringifyTagDetail (const TagDetail &t) {
    stringstream ss;
    ss << "Tag name: " << t.name << endl
       << "    opentag: " << t.opentag << endl
       << "    attrs: " << endl;
    for (auto &a : t.attributes) {
        ss << "        " << a.key << " -> " << a.value << endl;
    }
    return ss;
}

void digestHRML(istream &is, size_t hrml_cnt, map<string,string> &hrml_map) {

    vector<string> pathv;

    for (size_t i = 0; i < hrml_cnt; i++) {
        TagDetail t;
        string line;

        // read 1 tag per line
        getline(is,line);

        // parse the tag info into a TagData object
        t = parse_hrml_line(line);

        // generate the base path name
        if (t.opentag == true) {
            pathv.push_back(t.name);
        } else {
            // don't do validation of the tag order
            // because the problem doesn't describe
            // what we should do for bad inputs
            if (pathv.size() > 0) {
                pathv.pop_back();
            }
        }

        // for each attribute:
        // merge the base path with the attribute name
        // to get the attribute path
        // add the attribute path path and value to our map
        string paths = path2string(pathv);
        for (auto &a : t.attributes) {
            string k = paths + "~" + a.key;
            // strip off quotes
            string v = a.value.substr(1,a.value.length()-2);
            hrml_map[k] = v;
        }
    }
}


void evaluateQueries(istream &is, size_t query_cnt, map<string,string> &hrml_map, vector<string> &results) {

    for (size_t i = 0; i < query_cnt; i++) {
        string line;
        string result;

        // read 1 query per line
        getline(is,line);

        // search the map for the query
        auto iter = hrml_map.find(line);
        if (iter == hrml_map.end()) {
            // key not found in map
            results.push_back("Not Found!");
        } else {
            results.push_back(iter->second);
        }
    }
}
