//
//  main.cpp
//  05_oneAway
//  There are three types of edits can be performed on strings: insert a character, remove a character, replace a character. Given two strings, write a function to check if they are one edit or zero edits away.
//
//  Created by carakitty on 9/20/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

bool isReplacement(string s, string t) {
    bool found = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) {
            if (found) return false;
            found = true;
        }
    }
    return true;
}

bool isInsertion(string s, string t) {
    bool found = false;
    for (int i = 0; i < s.length(); i++) {
        if (found) {
            if (s[i] != t[i+1]) return false;
        } else {
            if (s[i] != t[i]) {
                found = true;
                i--;
            }
        }
    }
    return  true;
}

// check the length of two string to see the kinds of the edit
bool isOneAway_2(string str1, string str2) {
    int len1 = int (str1.length()), len2 = int (str2.length());
    if (len1 == len2) return isReplacement(str1, str2);
    else if (len1 + 1 == len2) return isInsertion(str1, str2);
    else if (len1 == len2 + 1) return isInsertion(str2, str1);
    return false;
}

// as we can see, these is some duplicate codes in isRepalcement and isInsertion
// so we can combine the two cases in one function
bool isOneAway_1(string s, string t) {
    int len1 = int (s.length()), len2 = int (t.length());
    
    // str1 will always shorter than or equal to str2
    if (abs(len1 - len2) > 1) return false;
    else if (len1 > len2) {
        s.swap(t);
        int tmp = len1;
        len1 = len2;
        len2 = tmp;
    }
    
    bool found = false;
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (s[i] != t[j]) {
            if (found) return false;
            found = true;
            if (len1 != len2) i--;
        }
        i++;
        j++;
    }
    return true;
}

int main() {
    string str1 = "aple", str2 = "apple";
    cout << "Is " << str1 << " one edit away from " << str2 << "?\n";
    cout << "Method 1:\n";
    cout << boolalpha << isOneAway_1(str1, str2) << endl;
    cout << "Method 2:\n";
    cout << boolalpha << isOneAway_2(str1, str2) << endl;
    
    return 0;
}











