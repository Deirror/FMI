#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    pair<int, int> times[3];
    
    for(int i = 0; i < 3; i++) {
        int startHours, startMins, endHours, endMins;
        cin >> startHours >> startMins >> endHours >> endMins;
        
        if(startHours > endHours) {
            times[i].first = ((24 - startHours) + endHours);
        } else {
            times[i].first = endHours - startHours;
        }
        
        if(startMins > endMins) {            
            times[i].second = (60 - startMins) + endMins;
            times[i].first--;
        } else {
            times[i].second = endMins - startMins;
        }
    }
    
    sort(times, times + 3);
    
    cout << times[0].first << ':';        
    if(times[0].second < 9) {
        cout << '0' << times[0].second << '\n';
    }
    else {
        cout << times[0].second << '\n';
    }
   
    cout << times[2].first << ':';        
    if(times[2].second < 9) {
        cout << '0' << times[2].second << '\n';
    }
    else {
        cout << times[2].second << '\n';
    }
    return 0;
}
