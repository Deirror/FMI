#include <iostream>
#include <unordered_set>


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::unordered_set<int> s;
    int num, N;
    cin >> num >> N;

    s.insert(num);

    int numNext;
    while (N--)
    {
        cin >> num >> numNext;
        if (s.find(num) != s.end())
        {
            s.insert(numNext);
        }
    }
    cout << s.size();
    return 0;
}
