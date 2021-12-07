/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:

Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:

Given m, n satisfy the following condition:

1 ≤ m ≤ n ≤ length of list.

Note 2:

Usually the version often seen in the interviews is reversing the whole linked list which is obviously an easier version of this question.
*/
/*
I don't know man, using stack it worked.
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

ListNode *solve(ListNode *head, int m, int n){
    if(head == 0){
        return head;
    }
    if(head -> next == 0){
        return head;
    }
    if(m == n){
        return head;
    }

    stack<int> st;
    int len = 0;
    ListNode *temp = head;
    while(temp != 0){
        len++;
        if(len >= m && len <= n){
            st.push(temp -> val);
        }
        temp = temp -> next;
    }

    // cout << "Lenght of linked list is: " << len << endl;
    // cout << "Number of nodes to reverse: " << st.size() << endl;

    temp = head;
    len = 0;
    while(!st.empty() && temp != 0){
        len++;
        if(len >=m && len <= n){
            int top = st.top();
            temp -> val = top;
            st.pop();
        }
        temp = temp -> next;
    }

    return head;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);
    int m = 2,n=4;

    ListNode *result = solve(head, m, n);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11