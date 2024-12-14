#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* next = nullptr;
    
    Node(int value, Node* next = nullptr) : value(value) {
        this->next = next;
    }
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    void add(int value) {
        Node* node = new Node(value);
        if(!head && !tail) {
            head = tail = node;
        } else {
            Node* temp = tail;
            tail = node;
            temp->next = node;
        }
    }
    
    void print() const {
        Node* node = head;
        while(node) {
            cout << node->value << ' ';
            node = node->next;
        }
    }
};

int main() {
    List list;
    
    int n;
    cin >> n;
    int size = 0;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        list.add(num);
        size++;
    }
    
    int k;
    cin >> k;

    if(k > 1) {
         int times = size / k;
         int realSize = times;
         if(size % k != 0) {
             realSize++;
         }
         List sublists[realSize];
         Node* node = list.head;
         int idx = 0;
         int counter = 0;
         while(node) {
             sublists[idx].add(node->value);
             counter++;
             if(counter % k == 0) {
                 idx++;
             }
             node = node->next;
         }  
        
         for(int i = 0; i < times; i++) {
             Node* prev = nullptr;
             Node* curr = sublists[i].head;
             for(int j = 0; j < k; j++) {
                 Node* next = curr->next;
                 curr->next = prev;
                 prev = curr;
                 curr = next;
             }
             swap(sublists[i].head, sublists[i].tail);
        }
        
        for(int i = 0; i < times - 1; i++) {
            sublists[i].tail->next = sublists[i + 1].head;
        }
        
        if(size % k != 0) {
            sublists[realSize - 2].tail->next = sublists[realSize - 1].head;
        }
        
        sublists[0].print();
        return 0;
    }
    
    list.print();
    
    return 0;
}
