#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int trees_count;
    scanf("%i", &trees_count);

    int trees[trees_count];
    for (int i = 0; i < trees_count; i++) {
        scanf("%i", &trees[i]);
    }

    stack<int> trees_stack;
    int max_count = 0;
    int max_count_position = 0;

    int current_count = 0;
    int i;
    for (i = trees_count - 1; i >= 0; i--) {

        if (trees_stack.empty() || trees_stack.top() > trees[i]) {
            trees_stack.push(trees[i]);
            current_count++;
        }
        else {
            if (current_count >= max_count) {
                max_count = current_count;
                max_count_position = i + 1;
            }

            while (!trees_stack.empty() && trees_stack.top() <= trees[i]) {
                trees_stack.pop();
                current_count--;
            }

            trees_stack.push(trees[i]);
            current_count++;
        }
    }

    if (current_count >= max_count) {
        max_count = current_count;
        max_count_position = i + 1;
    }

    cout << max_count_position << endl;

    return 0;
}
