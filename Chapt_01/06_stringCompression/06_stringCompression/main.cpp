//
//  main.cpp
//  06_stringCompression
//  Implement a method to perform basic string compression using the counts of repeated characters.
//  If the compressed string is not smaller than the original one, return the original string.
//  Assume the string only has uppercase and lowercase letters (a-z).
//
//  Created by carakitty on 9/20/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

// Method 1:
string compressedString_1(string s) {
    string t;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        count++;
        if (i+1 >= s.length() || s[i] != s[i+1]) {
            t += s[i] + to_string(count);
            count = 0;
        }
    }
    if (s.length() <= t.length()) return s;
    return t;
}

// Method 2:
// Check the length of compressed string before create new compressed string
// sometimes original string is shorter than the compressed one
// we can check the length of the compressed string first without
// actually create a new compressed string we do not use

int lengthCompressedString(string s) {
    int length = 0;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        count++;
        if (i+1 >= s.length() || s[i] != s[i+1]) {
            length += 1 + to_string(count).length();
        }
    }
    return length;
}

string compressedString_2(string s) {
    if (s.length() <= lengthCompressedString(s)) return s;
    
    string t;
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        count++;
        if (i+1 >= s.length() || s[i] != s[i+1]) {
            t += s[i] + to_string(count);
            count = 0;
        }
    }
    if (s.length() <= t.length()) return s;
    return t;
}

int main() {
    string str = "aabbbbcdeffgff";
    cout << "Method 1:\n";
    cout << "The compressed string of " << str << " is " << compressedString_1(str) << endl;
    cout << "Method 2:\n";
    cout << "The compressed string of " << str << " is " << compressedString_2(str) << endl;
    return 0;
}
