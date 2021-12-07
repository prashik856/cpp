/*
Problem Description

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Try solving it using constant additional space.

Example:

Input: 


              ______
             |     |
             \/    |
    1 -> 2 -> 3 -> 4


Return the node corresponding to node 3. 
*/

/*
Solution Approach: 
Use fast and slow approach.
Yes, if fast == slow -> that means we have a cycle.
if fast == 0, no cycle.

Now, when fast == slow, go through the cycle and store all of the nodes inside the cycle 
in a map.
Now traverse through the linked list and wait for a visited node to appear.
That is our answer.
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

ListNode *createCycledLinkedList(vector<int> arr){
    srand(time(0));
    int randomIndex = rand();
    randomIndex = randomIndex % arr.size();
    cout << "List is cycled at: " << arr[randomIndex] << endl;

    ListNode *cycledNode = 0;
    ListNode *head = 0;
    ListNode *tail = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout << arr[i] << " -> ";
        int value = arr[i];
        ListNode *newNode = new ListNode(value);
        if(i == randomIndex){
            cycledNode = newNode;
        }
        if(head == 0){
            head = newNode;
            tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    tail -> next = cycledNode;
    cout << cycledNode -> val << endl;
    return head;
}

ListNode *solve(ListNode* head){
    // let's go fast and slow
    ListNode *fast = head->next;
    ListNode *slow = head;
    unordered_map<ListNode *, int> mapping;

    while(fast != slow && fast != 0){
        fast = fast -> next;
        if(fast != 0){
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    if(fast == 0){
        // cout << "No cycle at all" << endl;
        return 0;
    }
    // cout << "A node inside the cycle is: " << slow -> val << endl;
    // Put nodes of the cycle inside the hashmap
    ListNode *cycleRef = slow;
    mapping[cycleRef] = 1;
    cycleRef = cycleRef -> next;
    while(cycleRef != slow){
        mapping[cycleRef] = 1;
        cycleRef = cycleRef -> next;
    }

    ListNode *temp = head;
    ListNode *result = 0;
    while(temp != 0){
        int value = mapping[temp];
        if(value == 1){
            result = temp;
            break;
        }
        temp = temp -> next;
    }

    return result;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    ListNode *head = createCycledLinkedList(a);

    ListNode *result = solve(head);
    cout << "Result: " << result -> val << endl;
    return 0;
}

// g++ -std=c++11