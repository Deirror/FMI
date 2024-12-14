#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = int(10e5);
int arr[MAX_SIZE]{};

int calcArea(int fWall, int sWall, int fIndex, int sIndex) {
    int min = std::min(fWall, sWall);   
    return std::abs(fIndex - sIndex) * min;
}

int main() {
    int N;
    cin >> N;
    
    for(int i =0 ;i <N; i++) {
        cin >> arr[i];
    }
    
    int max_area = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j != i) {
                int current_area = calcArea(arr[i], arr[j], i, j);           
                if(current_area > max_area) {
                    swap(current_area, max_area);
                }
            }
        }
    }
    
    cout << max_area;
    
    return 0;
}
