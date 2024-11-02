#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void _add(map<string, vector<string>>& groups, const string& group, const string& student) {
    groups[group].push_back(student);
}

void _remove(map<string, vector<string>>& groups, const string& group, const string& student) {
    auto& students = groups[group];
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (*it == student) {
            students.erase(it);
            cout << "Student " << student << " removed from group " << group << "." << endl;
            return;
        }
    }
    cout << "Student " << student << " not found in group " << group << "." << endl;
}

void _show(const map<string, vector<string>>& groups, const string& group) {
    auto it = groups.find(group);
    if (it != groups.end()) {
        cout << "Group " << group << ": ";
        for (const auto& student : it->second) {
            cout << student << ", ";
        }
        cout << endl;
    }
    else {
        cout << "Group " << group << " not found." << endl;
    }
}

void _show_all(const map<string, vector<string>>& groups) {
    cout << "All Groups:" << endl;
    for (const auto& group : groups) {
        cout << "Group " << group.first << ": ";
        for (const auto& student : group.second) {
            cout << student << ", ";
        }
        cout << endl;
    }
}

int main() {
    map<string, vector<string>> studentGroups;

    string group, student;
    char choice;

    while (true) {
        cout << "\nChoose an action:\n";
        cout << "1. Add student\n";
        cout << "2. Remove student\n";
        cout << "3. Show group\n";
        cout << "4. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == '1') {
            cout << "Enter group: ";
            getline(cin, group);
            cout << "Enter student name: ";
            getline(cin, student);
            _add(studentGroups, group, student);
        }
        else if (choice == '2') {
            cout << "Enter group: ";
            getline(cin, group);
            cout << "Enter student name to remove: ";
            getline(cin, student);
            _remove(studentGroups, group, student);
        }
        else if (choice == '3') {
            cout << "Enter group to display: ";
            getline(cin, group);
            _show(studentGroups, group);
        }
        else if (choice == '4') {
            break;
        }
        else {
            cout << "Error\n";
        }
    }

	for (const auto& group : studentGroups) {
		cout << "Group " << group.first << ": ";
		for (const auto& student : group.second) {
			cout << student << ", ";
		}
		cout << endl;
	}
    
	system("pause");
    return 0;
}