#include <iostream>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

void try_1(size_t N, int S, int P, int Q) {

    int a[N];

    a[0] = S % long(pow(2,31));
    for (size_t i = 1; i < N; i++) {
        a[i] = (a[i-1]*P+Q) % long(pow(2,31));
    }

    unordered_set<int> s(a,a+N);

    /*
    cout << "unique values: ";
    for (const int& i: s) {
        cout << " " << i;
    }
    cout << endl;
    */

    cout << s.size() << endl;
}

void try_2(size_t N, int S, int P, int Q) {

    int a0, a1;
    set<int> s;

    a0 = S % long(pow(2,31));
    s.insert(a0);
    for (size_t i = 1; i < N; i++) {
        a1 = (a0*P+Q) % long(pow(2,31));
        s.insert(a1);
        a0 = a1;
    }
    cout << s.size() << endl;
}

int main() {
    size_t N;
    int S,P,Q;

    cin >> N >> S >> P >> Q;

    // try_1(N,S,P,Q);
    try_2(N,S,P,Q);


    return 0;
}
