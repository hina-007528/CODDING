#include <iostream>
#include <string>

using namespace std;

bool areAnagrams(string str1, string str2) {
   
    if (str1.length() != str2.length()) {
        return false;
    }

    for (int i = 0; i < str1.length(); i++) {
     
        size_t found = str2.find(str1[i]);

       
        if (found == string::npos) {
            return false;
        }
        str2.erase(found, 1);
    }

    return true;
}

int main() {
    string str1, str2;

 
    cout << "Enter the first string: ";
    cin >> str1;
    
    cout << "Enter the second string: ";
    cin >> str2;
    
 
    if (areAnagrams(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}