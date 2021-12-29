/*
Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example :

Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 

*/

/*
Solution Approach:
https://www.geeksforgeeks.org/lru-cache-implementation/
But here, rather than using list<int>
we need to use list< vector<int> >, and in the vector, we need to store key and values both.
This is because we need the reverse mapping as well, key-value
Now, mapping only need to store key, but the list need to store both key and value.
This is because when we are deleting the last element form the list, we need to erase it
from the mapping as well. And while erasing in mapping, we can just use erase in map from 
the key-val vector that we got.
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}

class ListNode{
    public: 
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> arr){
    ListNode *head = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int value = arr[i];
        ListNode *newNode = new ListNode(value);

        if(head == 0){
            head = newNode;
        } else {
            ListNode *temp = head;
            while(temp->next != 0){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    return head;
}

void printLinkedList(ListNode *head){
    ListNode *temp = head;
    while(temp != 0){
        cout << temp->val << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int getLinkedListLength(ListNode *head){
    ListNode *temp = head;
    int count = 0;
    while(temp !=0){
        temp = temp -> next;
        count++;
    }
    return count;
}

class LRUCache {
    private:
        int capacity;
        // doubly linked list to store elements
        list< vector<int> > lru;
        unordered_map<int, list< vector<int> >::iterator> mapping;
    public:
        LRUCache(int val){
            // cout << "Capacity is: " << val << endl;
            capacity = val;
        }

        int get(int key){
            list< vector<int> > :: iterator it;
            if(mapping.find(key) == mapping.end()){
                // not found
                // cout << "Not found in the map" << endl;
                return -1;
            } else {
                // cout << "Found in the map" << endl;
                it = mapping[key];
                vector<int> temp = *it;

                // Update the lru
                lru.erase(it);

                // Push in the fron
                lru.push_front(temp);
                // Update the map
                mapping[temp[0]] = lru.begin();
                return temp[1];
            }
        }

        void set(int key, int val){
            // check if it already exists in the memory
            list< vector<int> > :: iterator it;
            if(mapping.find(key) == mapping.end()){
                // Not present in the memory
                // cout << "Not Present in the memory" << endl;

                // Capacity is not available
                if(lru.size() == capacity){
                    // cout << "Capacity full" << endl;
                    // cout << "Popping last element" << endl;
                    
                    // get last element
                    vector<int> lastVal = lru.back();
                    // cout << "Last element is: " << lastVal[0] << endl;
                    mapping.erase(lastVal[0]);
                    lru.pop_back();

                    // Check if the element is erased?
                    // if(mapping.find(lastVal[0]) == mapping.end()){
                        // cout << "Element deleted" << endl;
                    // } else {
                        // cout << "Element not deleted" << endl;
                    // }

                    // Push the key in lru
                    vector<int> temp = {key, val};
                    lru.push_front(temp);
                    // set the map
                    mapping[key] = lru.begin();
                } else {
                    // cout << "Capacity Available" << endl;
                    // Capacity is available
                    // push in the lru
                    vector<int> temp = {key, val};
                    lru.push_front(temp);
                    // map our key
                    mapping[key] = lru.begin();
                }

            } else {
                // present
                // cout << "Present in the memory" << endl;

                // cout << "Erasing from lru" << endl;
                // erase from the lru first
                it = mapping[key];
                lru.erase(it);

                // cout << "Adding it in the front again" << endl;
                // add it in the front
                vector<int> temp = {key, val};
                lru.push_front(temp);
                // set the map
                mapping[key] = lru.begin();
            }
        }
};

int main(){
    int capacity = 1;
    LRUCache lruCache(capacity);
    lruCache.set(2, 1);
    lruCache.set(2, 2);
    cout << lruCache.get(2) << endl;
    lruCache.set(1, 1);
    lruCache.set(4, 1);
    cout << lruCache.get(2) << endl;
    return 0;
}

// g++ -std=c++11

