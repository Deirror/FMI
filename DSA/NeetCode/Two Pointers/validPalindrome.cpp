class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.length(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 'a' - 'A';
            }
        }
       
        for(int i = 0; i < s.length();) {
            if((s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9')) {
                s.erase(i, 1);
            } else {
                i++;
            }
        }
        cout << s;
        auto beg = s.begin();
        auto end = s.end();
        end--;
        while(beg < end) {
            if(*beg != *end) {
                return false;
            }
            beg++;
            end--;
        }
        return true;
    }
};
