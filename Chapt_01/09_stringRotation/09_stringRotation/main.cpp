//
//  main.cpp
//  09_stringRotation
//  Given two strings s1 and s2, check if s2 is rotation of s1 using only one call to function isSubstring.
//
//  Created by carakitty on 9/22/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

// check if s2 is the substring of s1
// can also use the lib function in <string>, see githubompressedString_1(str)
bool isSubstring(string s1, string s2) {
    int l1 = int (s1.length());
    int l2 = int (s2.length());
    
    if (l2 > l1) return false;
    
    int i = 0, j = 0;
    while (i < l1 && j < l2) {
        if (s1[i] != s2[j]) {
            if (j == 0) i++;
            j = 0;
        } else {
            i++;
            j++;
            if (j == l2) return true;
        }
    }
    return false;
}

// check if s2 is the rotation of s1
bool isRotation(string s1, string s2) {
    if (s1.length() == 0 || s1.length() != s2.length()) return false;
    return isSubstring(s1+s1, s2);
}

int main() {
    string s = "appleapple", sub = "pleap";
    cout << "Is " << sub << " substring of " << s << "?   " << boolalpha << isSubstring(s, sub) << endl;
    string s1 = "apple", s2 = "leapp";
    cout << "Is " << s2 << " rotation of " << s1 << "?   " << boolalpha << isRotation(s1, s2) << endl;
    return 0;
}
