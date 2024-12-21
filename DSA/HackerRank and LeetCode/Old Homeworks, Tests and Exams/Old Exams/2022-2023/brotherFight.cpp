#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int N; 
    std::cin >> N;
    
    std::vector<int> ivancho_stickers(N);
    std::vector<int> brother_requests(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> ivancho_stickers[i];
    }
    
    for (int i = 0; i < N; ++i) {
        std::cin >> brother_requests[i];
    }
    
    std::unordered_map<int, int> ivancho_collection;
    int hit_days = 0;

    for (int i = 0; i < N; ++i) {
        int current_sticker = ivancho_stickers[i];
        int requested_sticker = brother_requests[i];
        
        // Ivancho gets a new sticker, increase its count in the map
        ivancho_collection[current_sticker]++;
        
        // Check if brother's requested sticker is in Ivancho's collection
        if (ivancho_collection[requested_sticker] > 0) {
            ivancho_collection[requested_sticker]--;  // Brother takes the sticker
            if (ivancho_collection[requested_sticker] == 0) {
                ivancho_collection.erase(requested_sticker);  // Remove from map if count is zero
            }
        } else {
            ++hit_days;  // Ivancho "gets hit"
        }
    }
    
    std::cout << hit_days << std::endl;
    
    return 0;
}
