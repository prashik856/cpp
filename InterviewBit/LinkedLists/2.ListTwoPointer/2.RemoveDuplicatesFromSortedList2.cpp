/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.
*/
/*
Since no space issue, let's use map and see which values are repeated.
And then recreate the linked list.
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

ListNode *solve(ListNode *head){
    if(head == 0){
        return head;
    }

    if(head -> next == 0){
        return head;
    }
    unordered_map<int, int> mapping;
    vector<int> neededValues;
    ListNode *temp = head;

    while(temp != 0){
        int listValue = temp -> val;
        int value = mapping[listValue];
        if(value == 0){
            mapping[listValue] = 1;
        } else {
            mapping[listValue] = value + 1;
        }
        temp = temp -> next;
    }

    temp = head;
    while(temp != 0){
        int listValue = temp -> val;
        int mapValue = mapping[listValue];
        if(mapValue <= 1){
            neededValues.push_back(listValue);
        }
        temp = temp -> next;
    }

    head = 0;
    for(int i=neededValues.size() - 1; i>=0; i--){
        ListNode *newNode = new ListNode(neededValues[i]);
        if(head == 0){
            head = newNode;
        } else {
            newNode -> next = head;
            head = newNode;
        }
    }

    return head;
}

int main(){
    vector<int> a = {1,2,3,3,4,5,5};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);

    ListNode *result = solve(head);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11