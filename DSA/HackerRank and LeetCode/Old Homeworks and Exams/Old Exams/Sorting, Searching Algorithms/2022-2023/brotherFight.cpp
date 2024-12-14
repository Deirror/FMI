#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int N; 
    cin >> N;
    
    vector<int> ivancho_stickers(N);
    vector<int> brother_requests(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> ivancho_stickers[i];
    }
    
    for (int i = 0; i < N; ++i) {
        cin >> brother_requests[i];
    }
    
    unordered_map<int, int> ivancho_collection;
    int hit_days = 0;

    for (int i = 0; i < N; ++i) {
        int current_sticker = ivancho_stickers[i];
        int requested_sticker = brother_requests[i];
    
        ivancho_collection[current_sticker]++;
      
        if (ivancho_collection[requested_sticker] > 0) {
            ivancho_collection[requested_sticker]--; 
            if (ivancho_collection[requested_sticker] == 0) {
                ivancho_collection.erase(requested_sticker);
            }
        } else {
            ++hit_days;
        }
    }
    
    cout << hit_days << '\n';
    
    return 0;
}
