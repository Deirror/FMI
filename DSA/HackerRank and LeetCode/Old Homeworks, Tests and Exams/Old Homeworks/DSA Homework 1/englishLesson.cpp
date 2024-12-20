#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;

    int N;
    cin >> N;

    char S;
    cin >> S;

    long long counter = 0;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == S) {
            counter++;
        }
    }

    int times = N / word.length();
    counter *= times;

    for (int i = 0; i < N - (times * word.length()); i++) {
        if (word[i] == S) {
            counter++;
        }
    }

    cout << counter;

    return 0;
}
