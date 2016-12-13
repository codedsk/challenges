#include <iostream>

using namespace std;

#define NMARKS 6

class Person {
    public:
        string name;
        int age;

        Person();
        ~Person();
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};


Person::Person() {
    this->name = "";
    this->age = 0;
}

Person::~Person() {
    // nothing to do
}

class Professor : public Person {
    public:
        int publications;
        int id;
        static int _cnt;

        Professor(void);
        ~Professor();
        void getdata(void);
        void putdata(void);
};

int Professor::_cnt = 1;

Professor::Professor() : Person() {
    this->publications = 0;
    this->id = _cnt++;
}

Professor::~Professor() {
    // nothing to do
}

void Professor::getdata(void) {
    cin >> this->name >> this->age >> this->publications;
}

void Professor::putdata(void) {
    cout << this->name << " "
         << this->age << " "
         << this->publications << " "
         << this->id << endl;
}

class Student : public Person {
    public:
        int marks[NMARKS];
        int id;
        static int _cnt;

        Student();
        ~Student();
        void getdata(void);
        void putdata(void);
};

int Student::_cnt = 1;

Student::Student() : Person() {
    this->id = _cnt++;
    for (int i=0; i < NMARKS; i++) {
        this->marks[i] = 0;
    }
}

void Student::getdata(void) {
    cin >> this->name >> this->age;
    for (int i=0; i < NMARKS; i++) {
        cin >> this->marks[i];
    }
}

void Student::putdata(void) {
    cout << this->name << " "
         << this->age << " ";
    int s = 0;
    for (int i=0; i < NMARKS; i++) {
        s += this->marks[i];
    }
    cout << s << " " << this->id << endl;
}

int main() {
    int n,val;

    // The number of objects that is going to be created.
    cin >> n;

    Person *per[n];

    for(int i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;
        } else {
            // Else the current object is of type Student
            per[i] = new Student;
        }

        // Get the data from the user.
        per[i]->getdata();
    }

    for (int i = 0; i < n; i++) {
        // Print the required output for each object.
        per[i]->putdata();
    }

    return 0;
}
