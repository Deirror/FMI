class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,bool>> q;
        int i  = 0;
        for(auto ticket : tickets) {
            if(i == k) {
                q.push({ticket,1});
                i++;
                continue;
            }
            q.push({ticket,0});
            i++;
        }
        int times = 0;
        while(q.size()) {
            if(q.front().first > 0) {
                auto temp = q.front();
                temp.first--;
                q.pop();    
                if(temp.first) {
                    q.push(temp);    
                } else if(!temp.first && temp.second) {
                    times++;
                    break;
                }   
            }
            times++;
        }
        return times;
    }
};
