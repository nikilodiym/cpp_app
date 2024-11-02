#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string text;
    cout << "Enter the text: ";
    getline(cin, text);

    map<string, int> frequency;

    string word;
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            if (c >= 'A' && c <= 'Z') {
                c += 'a' - 'A'; 
            }
            word += c;
        } else if (word.length() > 0) {
            frequency[word]++;
            word = "";
        }
    }

    cout << "Word Frequency:" << endl;
    for (auto it = frequency.begin(); it != frequency.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }

    system("pause");
    return 0;
}