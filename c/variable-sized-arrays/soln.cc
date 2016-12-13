#include <iostream>
using namespace std;

int main() {
    int N = 0;
    int Q = 0;
    int **v = NULL;

    cin >> N >> Q;

    v = new int* [N];

    // read in all of the sequences
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        v[i] = new int[c];
        for (int j = 0; j < c; j++) {
            cin >> v[i][j];
        }
    }

    // read in the queries and print the indexed values
    for (int i = 0; i < Q; i++) {
        int q1, q2;
        cin >> q1 >> q2;
        cout << v[q1][q2] << endl;
    }

    // delete v
    for (int i = 0; i < N; i++) {
        delete v[i];
    }
    delete v;

    return 0;
}
