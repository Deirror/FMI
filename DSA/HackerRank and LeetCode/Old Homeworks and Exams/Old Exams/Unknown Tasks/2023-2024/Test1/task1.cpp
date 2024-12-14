#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct CustomSet {
    pair<int, int> LowerLetters[26]{};
    pair<int, int> UpperLetters[26]{};
    pair<int, int> Digits[10]{};
};

bool isLower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

bool isUpper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int main() {
    CustomSet custSet;

    string text;
    cin >> text;

    for (int i = 0; i < text.length(); i++) {
        if (isLower(text[i])) {
            custSet.LowerLetters[text[i] - 'a'].first++;
            custSet.LowerLetters[text[i] - 'a'].second = i;
        }
        else if (isUpper(text[i])) {
            custSet.UpperLetters[text[i] - 'A'].first++;
            custSet.UpperLetters[text[i] - 'A'].second = i;
        }
        else if (isDigit(text[i])) {
            custSet.Digits[text[i] - '0'].first++;
            custSet.Digits[text[i] - '0'].second = i;
        }
    }


    for (int i = 0; i < text.length(); i++) {
        if (isLower(text[i])) {

            if (custSet.LowerLetters[text[i] - 'a'].first == 1) {
                cout << custSet.LowerLetters[text[i] - 'a'].second << ' ';
            }
        }
        else if (isUpper(text[i])) {
            if (custSet.UpperLetters[text[i] - 'A'].first == 1) {
                cout << custSet.UpperLetters[text[i] - 'A'].second << ' ';
            }
        }
        else if (isDigit(text[i])) {
            if (custSet.Digits[text[i] - '0'].first == 1) {
                cout << custSet.Digits[text[i] - '0'].second << ' ';
            }
        }
    }

    return 0;
}
