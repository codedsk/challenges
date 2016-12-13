// https://www.hackerrank.com/challenges/c-tutorial-class

#include <iostream>
#include <sstream>
using namespace std;

class Student {
    public:

        int get_age();
        void set_age(int);

        string get_first_name();
        void set_first_name(string);

        string get_last_name();
        void set_last_name(string);

        int get_standard();
        void set_standard(int);

        string to_string();

    private:

        int age_;
        string first_name_;
        string last_name_;
        int standard_;
};


int Student::get_age() {
    return age_;
}


void Student::set_age(int age) {
    age_ = age;
}


string Student::get_first_name() {
    return first_name_;
}


void Student::set_first_name(string name) {
    first_name_ = name;
}


string Student::get_last_name() {
    return last_name_;
}


void Student::set_last_name(string name) {
    last_name_ = name;
}


int Student::get_standard() {
    return standard_;
}


void Student::set_standard(int standard) {
    standard_ = standard;
}


string Student::to_string() {
    stringstream ss;
    ss << age_ << ","
       << first_name_ << ","
       << last_name_ << ","
       << standard_ << endl;
    return ss.str();
}


int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    return 0;
}
