//
//  main.cpp
//  02_checkPermutation
//  Given two strings, write a method to decide if one is a permutation of the other.
//  Hints: #1, #84, #122, #131
//  premutation: same characters different order
//
//  Created by carakitty on 9/17/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

// sort two strings and compare char one by one, time O(n lg n)
bool permutation_sort(string s, string t) {
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) return false;
    }
    return true;
}

// use hash table to flag numbers of each char in 1st string, and then check 2nd string and delete in table one by one
// time O(n), space O(1)
bool permutation_hash(string s, string t) {
    if (s.length() != t.length()) return false;
    int count[256] = {0};
    for (auto c : s) {
        count[int (c)]++;
    }
    for (auto c : t) {
        count[int (c)]--;
        if (count[int (c)] < 0) return false;
    }
    return true;
}

int main() {
    string str1 = "hello";
    string str2 = "llohe";
    
    cout << "useing the sort method to check permutation: " << endl;
    if (permutation_sort(str1, str2))
        cout << str1 << " and " << str2 << " are premutation of each other." << endl;
    else
        cout << str1 << " and " << str2 << " are not premutation of each other." << endl;
    
    cout << endl;
    cout << "useing the hash table method to check permutation: " << endl;
    if (permutation_sort(str1, str2))
        cout << str1 << " and " << str2 << " are premutation of each other." << endl;
    else
        cout << str1 << " and " << str2 << " are not premutation of each other." << endl;
    
    cout << endl;
    return 0;
}

