/*
Merge k sorted linked lists and return it as one sorted list.

Example :

1 -> 10 -> 20
4 -> 11 -> 13
3 -> 8 -> 9
will result in

1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
*/
/*
Yeah. Using just priority queue, it worked.
Put all elements in queue, and created linked list again using new elements.
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

ListNode *solve(vector<ListNode*> heads){
    ListNode *result;

    priority_queue<int, vector<int>, greater<int>> sorted;
    int n = heads.size();
    for(int i=0; i<n; i++){
        ListNode *head = heads[i];
        while(head != 0){
            sorted.push(head -> val);
            head = head -> next;
        }
    }

    // print priority queue
    // cout << "Sorted linked lists are: " << endl;
    // priority_queue<int, vector<int>, greater<int>> tempSorted = sorted;
    // while(!tempSorted.empty()){
    //     cout << tempSorted.top() << " ";
    //     tempSorted.pop();
    // }
    // cout << endl;
    // delete &heads;

    ListNode *head = 0;
    ListNode *tail = 0;
    while(!sorted.empty()){
        int val = sorted.top();
        sorted.pop();
        ListNode *node = new ListNode(val);
        if(head == 0){
            head = node;
            tail = node;
        } else {
            tail -> next = node;
            tail = node;
        }
    }
    result = head;

    return result;
}

int main(){
    vector<int> a = {1, 10, 20};
    vector<int> b = {4, 11, 13};
    vector<int> c = {3, 8, 9};
    ListNode *headA = createLinkedList(a);
    ListNode *headB = createLinkedList(b);
    ListNode *headC = createLinkedList(c);
    vector<ListNode*> heads;
    heads.push_back(headA);
    heads.push_back(headB);
    heads.push_back(headC);
    cout << "Given arrays are: " << endl;
    printVector(a);
    printVector(b);
    printVector(c);

    ListNode *result = solve(heads);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11