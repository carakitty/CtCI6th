//
//  main.cpp
//  01_isUnique
//  Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
//
//  Created by carakitty on 9/17/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm> // for sort, if fine if not include

using namespace std;

bool isUnique(const string &str) {
    /* the total number of ascii characters is 128, if the length of string is longer than 128,
     there must be at least two same characters, thus helping saving time to check long strings */
    if (str.length() > 128) return false;
    
    // check strings shorter than 128 characters
    vector<bool> char_set(128);
    for (int i = 0; i < str.length(); i++) {
        int val = str[i]; // use int value to represent each char
        if (char_set[val]) return false;
        char_set[val] = true;
    }
    return true;
}

bool isUnique_bitvector(const string &str) {
    //Reduce space usage by a factor of 8 using bitvector.
    //Each boolean otherwise occupies a size of 8 bits.
    
    // ? why is 256 and not check the length of string
    bitset<256> bits(0); // initialize each bit with 0
    for (int i = 0; i < str.length(); i++) {
        int val = str[i];
        if (bits.test(val)) return false;
        bits.set(val);
    }
    return true;
}

bool isUnique_noDS(string str) {
    sort(str.begin(), str.end());
    
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i+1] == str[i]) return false;
    }
    return true;
}

int main() {
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
    for (auto word : words)
    {
        cout << word << string(" : ") << boolalpha << isUnique(word) << endl; // boolalpha is io manipulator, boolalpha: true/false
        // noboolalpha : 1/0
    }
    
    cout << endl << "Using bit vector" << endl;
    for (auto word : words)
    {
        cout << word << string(" : ") << boolalpha << isUnique_bitvector(word) << endl;
    }
    
    cout << endl << "Using no data structure" << endl;
    for (auto word : words)
    {
        cout << word << " : "  << isUnique_noDS(word) << endl;
    }
    return 0;
}
