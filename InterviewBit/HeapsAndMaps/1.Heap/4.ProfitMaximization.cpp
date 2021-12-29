/*
Problem Description

 Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= 1000000



Input Format
First argument is the array A.

Second argument is integer B.



Output Format
Return one integer, the answer to the problem.



Example Input
Input 1:

A = [2, 3]
B = 3
Input 2:

A = [1, 4]
B = 2


Example Output
Output 1:

7
Output 2:

7


Example Explanation
Explanation 1:

 First you serve the seat with number = 3. Then with 2 and then with 2. hence answer = 3 + 2 + 2 = 7.
Explanation 2:

 You give bith tickets from the row with 4 seats. 4 + 3 = 7.
*/
/*
solution approach:
Assuming initially all seats are empty.
Just use a priority queue, and find the most vacant seats.
pop top, decrement it, and push it again.
Get the result.
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

int solve(vector<int> a, int b){
    int result = 0;
    priority_queue<int> ticketPrice;
    for(int i=0; i<a.size(); i++){
        ticketPrice.push(a[i]);
    }

    while(b > 0){
        int maxPrice = ticketPrice.top();
        result += maxPrice;
        maxPrice--;
        ticketPrice.pop();
        ticketPrice.push(maxPrice);
        b--;
    }

    return result;
}

int main(){
    vector<int> a = {2, 3};
    int b = 3;
    cout << "Given seats array is: " << endl;
    printVector(a);
    cout << "Number of tickets to sell: " << b << endl;

    int result = solve(a, b);
    cout << "Result: " << result << endl;

    return 0;
}

// g++ -std=c++11