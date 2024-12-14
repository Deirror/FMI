class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int i = 0; i < asteroids.size(); i++) {
            if(!st.size()) {
                st.push_back(asteroids[i]);
            } else {
                if(st.back() > 0 && asteroids[i] < 0) { // bojjj
                    bool flag = true;
                    while(st.size() && st.back() > 0) {
                        if(st.back() == asteroids[i] * (-1)) {
                            st.pop_back();
                            flag = false;
                            break;
                        } else if(st.back() > asteroids[i] * (-1)) {
                            flag = false;
                            break;
                        } else if(st.back() < asteroids[i] * (-1)){
                            st.pop_back();
                        }
                    }
                    if(flag) {
                        st.push_back(asteroids[i]);
                    }
                } else {
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};
