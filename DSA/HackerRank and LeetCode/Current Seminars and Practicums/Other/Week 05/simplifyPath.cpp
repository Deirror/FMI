class Solution {
public:
    string simplifyPath(string path) {
        string res = "/";
        for(int i = 1; i < path.length(); i++) {
            if(!res.length()) {
                res.push_back(path[i]);
                continue;
            }

            if(res.back() == '/' && path[i] == '/') {
                continue;
            }

            if(res.back() == '/' && path[i] == '.') {            
                if(path[i + 1] == '.') {
                    if(path[i + 2] == '.') {
                        res.push_back(path[i]);
                    } else {                  
                    res.pop_back();
                    if(!res.length()) {
                        return "/";
                    }
                    while(res.back() != '/') {
                        res.pop_back();
                    }
                    i += 2;
                    }
                } else {
                    i++;
                }
            } else {
                res.push_back(path[i]);
            }
        }

        if(res.back() == '/') {
            res.pop_back();
        }

        return res;
    }
};
