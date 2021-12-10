/*
Problem Description

Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.



Problem Constraints
1 <= length of the string <= 100000



Input Format
The only argument given is string A.



Output Format
Return a string B after processing the stream of lowercase alphabets A.



Example Input
Input 1:

 A = "abadbc"
Input 2:

 A = "abcabc"


Example Output
Output 1:

 "aabbdd"
Output 2:

 "aaabc#"


Example Explanation
Explanation 1:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "aba"    -   first non repeating character 'b'
    "abad"   -   first non repeating character 'b'
    "abadb"  -   first non repeating character 'd'
    "abadbc" -   first non repeating character 'd'
Explanation 2:

    "a"      -   first non repeating character 'a'
    "ab"     -   first non repeating character 'a'
    "abc"    -   first non repeating character 'a'
    "abca"   -   first non repeating character 'b'
    "abcab"  -   first non repeating character 'c'
    "abcabc" -   no non repeating character so '#'
*/
/*
Solution Approach:
For this, we can use a queue and a hash!
Let's try!
Use a hashmap to store the count of character values.
Use a queue to keep track of the first element which is non repeating.
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

string solve(string a){
    string result = "";
    int n = a.size();
    if(n == 1){
        return a;
    }
    queue<char> q;
    unordered_map<char, int> mapping;
    for(int i=0; i<n; i++){
        char value = a[i];
        int mapValue = mapping[value];

        if(mapValue == 0){
            // first time
            mapping[value] = 1;
            q.push(value);
        } else if(mapValue >= 1){
            // First Repeat
            mapping[value] = mapValue + 1;
            // Find the first non repeating character
            // This will be stored in qfront.
            while(!q.empty()){
                char qValue = q.front();
                int qMapValue = mapping[qValue];
                if(qMapValue > 1){
                    q.pop();
                } else {
                    break;
                }
            }
        }

        if(!q.empty()){
            result.push_back(q.front());
        } else {
            result.push_back('#');
        }
    }

    return result;
}

int main(){
    string a = "abcabc";
    cout << "Given string is: " << endl;
    cout << a << endl;

    string result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11