/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Input Format

The only argument given is integer array A.
Output Format

Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.
For Example

Input 1:
    A = [4, 5, 2, 10, 8]
Output 1:
    G = [-1, 4, -1, 2, 2]
Explaination 1:
    index 1: No element less than 4 in left of 4, G[1] = -1
    index 2: A[1] is only element less than A[2], G[2] = A[1]
    index 3: No element less than 2 in left of 2, G[3] = -1
    index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
    index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]
    
Input 2:
    A = [3, 2, 1]
Output 2:
    [-1, -1, -1]
Explaination 2:
    index 1: No element less than 3 in left of 3, G[1] = -1
    index 2: No element less than 2 in left of 2, G[2] = -1
    index 3: No element less than 1 in left of 1, G[3] = -1
*/
/*
Solution Approach:
Method 1:
A Simple Solution is to use two nested loops. 
The outer loop starts from second element, the inner loop goes to all 
elements on left side of the element picked by outer loop and 
stops as soon as it finds a smaller element.  

Method 2:
There can be an Efficient Solution that works in O(n) time. 
The idea is to use a stack. 
Stack is used to maintain a subsequence of the values that have been processed so far 
and are smaller than any later value that has already been processed.

Let input sequence be 'arr[]' and size of array be 'n'
1) Create a new empty stack S
2) For every element 'arr[i]' in the input sequence 'arr[]',
   where 'i' goes from 0 to n-1.
    a) while S is nonempty and the top element of 
       S is greater than or equal to 'arr[i]':
           pop S
    b) if S is empty:
           'arr[i]' has no preceding smaller value
    c) else:
           the nearest smaller value to 'arr[i]' is 
           the top element of S
    d) push 'arr[i]' onto S
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

vector<int> solve(vector<int> a){
    int n = a.size();
    vector<int> result(n, 0);
    stack<int> st;
    for(int i=0; i<a.size(); i++){
        int val = a[i];
        while(!st.empty()){
            if(st.top() >= val){
                st.pop();
            } else {
                break;
            }
        }

        if(st.empty()){
            result[i] = -1;
        } else {
            result[i] = st.top();
        }

        st.push(a[i]);
    }
    return result;
}

int main(){
    vector<int> a = {7, 5, 7, 9, 8, 7};
    cout << "Given input array is: " << endl;
    printVector(a);

    vector<int> result = solve(a);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11