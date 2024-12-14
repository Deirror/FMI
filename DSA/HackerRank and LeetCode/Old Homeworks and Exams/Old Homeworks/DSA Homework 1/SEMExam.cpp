#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<int, string>> infoExams;

    short T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        int K;
        cin >> K;

        string letters;
        cin >> letters;
        sort(letters.begin(), letters.end());

        infoExams.emplace_back(pair<int, string>(K, letters));

    }

    for (int i = 0; i < T; i++) {
        int counter = 1;
        for (int j = 0; j < infoExams[i].second.length(); j++) {
            char ch = infoExams[i].second[j];

            if (ch < 'A' || ch > 'Z') continue;

            if (j == infoExams[i].second.length() - 1) {
                if (counter >= infoExams[i].first) {
                    cout << infoExams[i].second[j];
                    break;
                }
            }

            if (ch == infoExams[i].second[j + 1])
            {
                counter++;
            }
            else
            {
                if (counter >= infoExams[i].first) {
                    cout << infoExams[i].second[j];
                }
                counter = 1;
            }
        }
        cout << endl;
    }

    return 0;
}
