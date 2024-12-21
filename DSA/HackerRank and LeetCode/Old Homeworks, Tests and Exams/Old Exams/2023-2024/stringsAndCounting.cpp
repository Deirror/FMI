#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string lowerLetters;
        cin >> lowerLetters;

        int hist[26]{};

        for (int j = 0; j < lowerLetters.length(); j++) {
            hist[lowerLetters[j] - 'a']++;
        }

        bool isPossible = true;
        for (int j = 0; j < 26; j++) {
            if (hist[j] > 0) {
                hist[j]--;
                int times = 0;
                bool isFound = false;
                for (int t = 0; t < 26; t++) {
                    if (hist[t] > 0) {

                        if (!isFound) {
                            times = hist[t];
                            isFound = true;
                            isPossible = true;
                        }

                        if (times != hist[t]) {
                            isPossible = false;
                            break;
                        }
                    }
                }
                hist[j]++;
                
                  if (isPossible) {
                    break;
                }
            }
        }

        cout << isPossible << endl;

    }

    return 0;
}
