//
//  main.cpp
//  03_URLify
//  Write a method to replace all spaces in a string with "%20". You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
//
//  Created by carakitty on 9/19/18.
//  Copyright © 2018 carakitty. All rights reserved.
//

#include <iostream>

using namespace std;

void urlify(string &str, int trueLength) {
    int count = 0; // count the number of space in str
    int i = 0, j = 0;
    for (i = 0; i < trueLength; i++) {
        if (str[i] == ' ') count++;
    }
    
    int extendedLength = trueLength + 2 * count;
    j = extendedLength - 1;
    for (i = trueLength - 1; i >= 0; i--) {
        if (str[i] != ' ') str[j--] = str[i];
        else {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
    }
    
}

int main() {
    string str = "Mr John Smith    ";
    int len = 13;
    cout << "Actual string is: " << str << endl;
    urlify(str, len);
    cout << "urlified string is: " << str << endl;
    return 0;
}
