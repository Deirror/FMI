#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int eliminations[1000000];

int main() 
{
    int  N;
    cin >> N;
    vector<int> players;
    
    for(int i = 0; i < N; i++) 
    {
        int number;
        cin>>number;
        players.push_back(number);
    }
    
    stack<int> s;
    int max = 0;   
    int counter = 0;  
    
    for(int i = N-1; i>=0; i--) 
    {      
        while(!s.empty() && players[i] < players[s.top()]) 
        {   
            eliminations[i] = std::max(eliminations[i]+1, eliminations[s.top()]);
            s.pop();
        }   

        
        s.push(i);     
        if (max <= eliminations[i]) 
        {
            max = eliminations[i];            
        }               
    }
    
    cout<<max<<endl;
}
