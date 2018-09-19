//
//  main.cpp
//  04_palindromePermutation
//  Given a string, write a function to check if it is a permutation of a palindrome. A
//
//  Created by carakitty on 9/19/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

// two method: sort and hash

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

int main() {
    string str = "tacct ooa";
    cout << "Is string \"" << str << "\" palindrome permutation? " << boolalpha
    << (isPalindromePermutation_sort(str)) << endl;
    return 0;
}
