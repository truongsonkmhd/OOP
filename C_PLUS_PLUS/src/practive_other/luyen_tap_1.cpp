#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string first;
    string last;
    string midd;
    float gpa = 0.0f;
    string studentId = "N/A";

public:
    Student(string fullName) {
        vector<string> names;
        size_t pos = 0;
        string delimiter = " ";
        while ((pos = fullName.find(delimiter)) != string::npos) {
            names.push_back(fullName.substr(0, pos));
            fullName.erase(0, pos + delimiter.length());
        }
        names.push_back(fullName);

        if (names.size() == 1) {
            first = names[0];
        } else if (names.size() == 2) {
            first = names[1];
            last = names[0];
        } else if (names.size() >= 3) {
            last = names[0];
            first = names[names.size() - 1];
            for (size_t i = 1; i < names.size() - 1; i++) {
                midd += names[i];
            }
        }
    }

    Student(string studentId, string fullName, float gpa = 0.0f) : Student(fullName) {
        this->gpa = gpa;
        this->studentId = studentId;
    }

    void showInfo() {
        cout << "Ma SV: " << studentId << endl;
        cout << "Ho: " << last << endl;
        cout << "Diem: " << midd << endl;
        cout << "Ten: " << first << endl;
        cout << "Diem Gpa: " << gpa << endl;
        cout << "========================" << endl;
    }
};

int main() {
    Student student("Tran Dinh Quan");
    Student otherStudent("B25DCCN102", "Le Hong Oanh", 3.37f);

    student.showInfo();
    otherStudent.showInfo();

    return 0;
}

