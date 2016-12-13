// https://www.hackerrank.com/challenges/attribute-parser

#include "soln.cc"

int main() {
    size_t hrml_cnt = 0;
    size_t query_cnt = 0;
    string line;
    stringstream ss;
    map<string,string> hrml_map;

    // parse the number of hrml lines and queries
    getline(cin,line);
    ss.str(line);
    ss >> hrml_cnt >> query_cnt;

    // parse the hrml code
    digestHRML(cin,hrml_cnt,hrml_map);

    // parse the queries
    vector<string> results;
    evaluateQueries(cin,query_cnt,hrml_map,results);

    for (auto &i : results) {
        cout << i << endl;
    }

    return 0;
}
