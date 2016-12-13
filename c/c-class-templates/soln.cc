// https://www.hackerrank.com/challenges/c-class-templates

#include <iostream>
#include <string>
using namespace std;

template <class T>
class AddElements {
    public:

        AddElements (T arg);
        T add (T);

    private:

        T element_;
};

template <class T>
AddElements<T>::AddElements(T arg) {
    element_ = arg;
}

template <class T>
T AddElements<T>::add(T arg) {
    return (element_ + arg);
}


template <>
class AddElements <string> {
    public:

        AddElements (string);
        string concatenate (string);

    private:

        string element_;
};

AddElements<string>::AddElements(string arg) {
    element_ = arg;
}

string AddElements<string>::concatenate(string arg) {
    return (element_ + arg);
}

/*
template <>
class AddElements <string> {
    public:

        AddElements (string arg) {element_ = arg;}
        string concatenate (string arg) {return (element_ + arg);}

    private:

        string element_;
};
*/


int main() {
    int n,i;
    cin >> n;
    for (i=0;i<n;i++) {
        string type;
        cin >> type;
        if (type == "float") {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
        else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
        else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
