#include <vector>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pqToCome;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pqWaiting;

int main()
{
    int N;
    cin >> N;

    int t, f;
    for (int i = 0; i < N; i++)
    {
        cin >> t >> f;
        auto task = make_pair(t, make_pair(f, i));
        pqToCome.push(task);
    }

    long long time = 0;

    while (!pqToCome.empty() || !pqWaiting.empty()) {
        while (!pqToCome.empty() && pqToCome.top().first <= time) {                                         
            pqWaiting.push(pqToCome.top().second);
            pqToCome.pop();
        }

        if (pqWaiting.empty() && !pqToCome.empty())
        {
            time = pqToCome.top().first;
            continue;
        }

        auto taskJustTaken = pqWaiting.top();
        pqWaiting.pop();
        cout << taskJustTaken.second << " ";
        time += taskJustTaken.first;
    }

    return 0;
}
