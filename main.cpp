#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int _calculate(const vector<int>& grades) {
    if (grades.empty()) return 0.0;
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / grades.size();
}

int main() {
    map<string, vector<int>> _grades;
    string name;
    int grade;

    while (true) {
		cout << "-----------------------------------------" << endl;
        cout << "Enter student name (or 'exit' to finish): ";
        cin >> name;
        if (name == "exit") break;

        vector<int> grades;
        cout << "Enter grades (finish with '-1'): ";
        while (true) {
            cin >> grade;
            if (grade == -1) break;
            grades.push_back(grade);
        }
        _grades[name] = grades;
    }

    cout << "Results: \n";
    for (const auto& student : _grades) {
        double average = _calculate(student.second);
        cout << student.first << ": average grade = " << average << endl;
    }

	system("pause");
    return 0;
}