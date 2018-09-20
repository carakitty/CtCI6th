//
//  main.cpp
//  04_palindromePermutation
//  Given a string, write a function to check if it is a permutation of a palindrome.
//
//  Created by carakitty on 9/19/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

// two method: sort and hash
// ignore all non-letter characters

// method 1: sort
bool isPalindromePermutation_sort(string str) {
    sort(str.begin(), str.end());
    int odd_count = 0, count = 1;
    for (int i = 0; i < str.length() - 1; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'a' && str[i] <= 'z')) {
            if (str[i] != str[i+1]) {
                if (count % 2 == 1) odd_count++;
                count = 1;
            } else {
                count++;
            }
        }
    }
    
    if (count % 2 == 1) odd_count++;
    if (odd_count > 1) return false;
    return true;
}

// method 2: hash
// use a hash table to count the number of each char
// use another loop to count the number of odd count
bool isPalindromePermutation_hash(string str) {
    int count[26] = {0};
    for (int i = 0; i < str.length(); i++) {
        int val = -1;
        if (str[i] >= 'a' && str[i] <= 'z') {
            val = str[i] - 'a';
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            val = str[i] - 'A';
        }
        if (val > -1) {
            count[val]++;
        }
    }
    
    int odd_count = 0;
    for (auto c : count) {
        if (c % 2 != 0) {
            odd_count++;
        }
        if (odd_count > 1) return false;
    }
    
    return true;
}

int main() {
    string str = "ab";
    cout << "Method 1: sort" << endl;
    cout << "Is string \"" << str << "\" palindrome permutation? " << boolalpha
         << (isPalindromePermutation_sort(str)) << endl;
    
    cout << "Method 2: hash" << endl;
    cout << "Is string \"" << str << "\" palindrome permutation? " << boolalpha
         << (isPalindromePermutation_hash(str)) << endl;
    return 0;
}







