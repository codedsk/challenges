#include <sstream>
#include <vector>
#include <iostream>
using namespace std;


vector<int> parseInts(string str) {

    vector<int> v;
    int num;
    char ch = ',';
    stringstream ss(str);

    while (!ss.eof()) {
        ss >> num >> ch;
        v.push_back(num);
    }

    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(size_t i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
