#include <iostream>
#include <queue>
#include <iomanip>


std::priority_queue<long double> lower;
std::priority_queue<long double, std::vector <long double>, std::greater<long double>> higher;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long n;
    std::cin >> n;

   long double median = 0;

    
    for (long long i = 0; i < n; i++) {
        long long money;
        std::cin >> money;
        
        if (lower.size() > higher.size()){
            if (money < median){
                higher.push(lower.top());
                lower.pop();
                lower.push(money);
            }
            else {
                higher.push(money);
            }
    
            median = (lower.top() + higher.top()) / 2.0;
        }

        else if (lower.size() == higher.size()){
            if (money < median){
                lower.push(money);
                median =(long double)lower.top();
            }else{
                higher.push(money);
                median = (long double)higher.top();
            }
        }
        else{
            if (money > median){
                lower.push(higher.top());
                higher.pop();
                higher.push(money);
            }
            else {
                lower.push(money);
            }
            median = (lower.top() + higher.top()) / 2.0;
        }
    
    
        std::cout.precision(1);
        std::cout << std::fixed << median << "\n";
    }


    
    return 0;
}
