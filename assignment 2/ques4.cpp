#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

void concatenateStrings(string s1, string s2) {
    cout << "Concatenated String: " << s1 + s2 << endl;
}

void reverseString(string s) {
    reverse(s.begin(), s.end());
    cout << "Reversed String: " << s << endl;
}

void deleteVowels(string s) {
    string result = "";
    for (size_t i = 0; i < s.size(); i++) {
        char ch = tolower(s[i]);
        if (ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u')
            result += s[i];
    }
    cout << "String without vowels: " << result << endl;
}
void sortStrings(string s1, string s2) {
    if (s1 > s2) swap(s1, s2);
    cout << "Strings in alphabetical order:\n";
    cout << s1 << "\n" << s2 << endl;
}
void toLowercase(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    cout << "Lowercase String: " << s << endl;
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);

    concatenateStrings(s1, s2);

    reverseString(s1);

    deleteVowels(s1);

    sortStrings(s1, s2);

    toLowercase(s1);

    return 0;
}
