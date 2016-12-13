#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0;
    int Q = 0;

    vector< vector<int> > v;

    cin >> N >> Q;

    // read in all of the sequences
    for (int i = 0; i < N; i++) {
        int c;
        vector<int> b;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            b.push_back(x);
        }
        v.push_back(b);
    }

    // read in the queries and print the indexed values
    for (int i = 0; i < Q; i++) {
        int q1, q2;
        cin >> q1 >> q2;
        cout << v[q1][q2] << endl;
    }

    return 0;
}
