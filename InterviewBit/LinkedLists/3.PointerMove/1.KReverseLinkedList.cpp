/*
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
*/
/*
Let's get the lenght of linked list first.
Given int k, we first need to create a stack of length k.
Once we have a stack, we put nodes in stack till it's size if k.
Once it's size is k, we put all the nodes in the stack in the new linked list.
At the end, make sure that the stack is empty.
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

ListNode* solve(ListNode *head, int k){
    if(k == 0){
        return head;
    }

    if(head == 0){
        return head;
    }

    if(head -> next == 0){
        return head;
    }

    stack<ListNode *> st;
    ListNode *temp = head;
    ListNode *newHead = 0;
    ListNode *newTail = 0;

    while(temp != 0){
        if(st.size() == k){
            // empty it
            while(!st.empty()){
                ListNode *top = st.top();
                if(newHead == 0){
                    newHead = top;
                    newTail = top;
                } else {
                    newTail -> next = top;
                    newTail = top;
                }
                st.pop();
            }
        } else {
            ListNode* node = temp;
            temp = temp -> next;
            node -> next = 0;
            st.push(node);
        }
    }

    // Making sure stack is empty
    while(!st.empty()){
        ListNode *top = st.top();
        if(newHead == 0){
            newHead = top;
            newTail = top;
        } else {
            newTail -> next = top;
            newTail = top;
        }
        st.pop();
    }

    return newHead;
}

int main(){
    vector<int> a = {1,2,3,4,5,6};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);
    int k = 2;

    ListNode *result = solve(head, k);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11