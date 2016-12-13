// https://www.hackerrank.com/challenges/classes-objects

#include <iostream>
#include <vector>
using namespace std;

class Student {
    public:

        void input();
        int calculateTotalScore();

    private:

        vector<int> scores_;
};


void Student::input() {
    int s;
    scores_.reserve(5);
    for (int i = 0; i < 5; i++) {
        cin >> s;
        scores_.push_back(s);
    }
}


int Student::calculateTotalScore() {
    int s = 0;
    for (auto &i : scores_) {
        s += i;
    }
    return s;
}


int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }


    //calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
