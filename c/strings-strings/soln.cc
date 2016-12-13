#include <iostream>
#include <string>
using namespace std;

int main() {
    size_t l_a = 0;
    size_t l_b = 0;
    string a, b, c, a1, b1;

    cin >> a;
    cin >> b;

    l_a = a.length();
    l_b = b.length();

    c = a + b;

    a1 = a;
    a1[0] = b[0];
    b1 = b;
    b1[0] = a[0];

    cout << l_a << " " << l_b << endl;
    cout << c << endl;
    cout << a1 << " " << b1 << endl;

    return 0;
}
