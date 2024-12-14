#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value = 0;
    Node* next = nullptr;
    
    Node(int value, Node* next = nullptr):value(value), next(next) {   
    }
};

struct List {
    Node* head, *tail;
    
    List() : head(nullptr), tail(nullptr) {}
    
    void add(int value) {
        Node* node = new Node(value);
        if(!head && !tail){
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
};

int main() {
    List l;
    
    int num = 0;
    while(cin >> num) {
        l.add(num);
    }
    
    Node* temp = l.head;
    int minNum = 10000;
    int maxNum = 1;
    size_t sum = 0;
    while(temp) {
        minNum = min(minNum, temp->value);
        maxNum = max(maxNum, temp->value);
        sum += temp->value;
        temp = temp->next;
    }
    
    cout << minNum << ' ' << maxNum << ' ' << sum;
    
    return 0;
}
