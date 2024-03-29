/*
Problem Description

Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



Problem Constraints
1 <= |A| <= 105



Input Format
First argument is an string A.



Output Format
Return 1 if parantheses in string are balanced else return 0.



Example Input
Input 1:

 A = "(()())"
Input 2:

 A = "(()"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Given string is balanced so we return 1
Explanation 2:

 Given string is not balanced so we return 0
*/

/*
we just learned this from the DS and Algo course
Solution Approach:
when '(' just push in stack
When ) 
    -> if stack empty or top != ( => return 0
    -> else pop stack
At the end, if stack is not empty, return 0
else return 1
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

int solve(string a){
    int result = 1;

    stack<int> st;
    for(int i=0; i<a.size(); i++){
        char val = a[i];
        if(val == '('){
            st.push(val);
        }
        else {
            // we have ) but stack is empty
            if(st.empty()){
                return 0;
            }

            // top is not equal to (
            char top = st.top();
            if(top != '('){
                return 0;
            }

            // top is equal to (
            st.pop();
        }
    }

    // our stack should be empty
    if(!st.empty()){
        return 0;
    }

    // All good
    return result;
}

int main(){
    string a = "(()";
    cout << "Given input is: " << endl;
    cout << a << endl;

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11