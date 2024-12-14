#include <bits/stdc++.h>

using namespace std;

string superReducedString(string s) {
    string res;
    
    res.push_back(s[0]);
    for(int i = 1; i < s.length(); i++) {
        if(res.back() == s[i]) {
            res.pop_back();
        } else {
            res.push_back(s[i]);
        }
    }
    
    if(res.c_str()[0] == 0) {
        res = "Empty String";
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
