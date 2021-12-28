/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)
Sample Output :

2
You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/count-maximum-points-on-same-line/
We can solve above problem by following approach – 
For each point p, calculate its slope with other points and use a map to record how many points have same slope, 
by which we can find out how many points are on same line with p as their one point. 
For each point keep doing the same thing and update the maximum number of point count found so far.
Some things to note in implementation are: 
1) if two point are (x1, y1) and (x2, y2) then their slope will be (y2 – y1) / (x2 – x1) which can be a double value 
and can cause precision problems. 
To get rid of the precision problems, we treat slope as pair ((y2 – y1), (x2 – x1)) instead of ratio and 
reduce pair by their gcd before inserting into map. 
In below code points which are vertical or repeated are treated separately.
2) If we use unordered_map in c++ or HashMap in Java for storing the slope pair, 
then total time complexity of solution will be O(n^2)
 
Let's try this.
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

int getGcd(int a, int b){
    a = abs(a);
    b = abs(b);
    bool negative = false;
    if(a == 0){
        return b;
    } 

    if(b == 0){
        return a;
    }

    int remainder = INT_MAX;
    int greater = 0;
    int smaller = 0;
    if(a > b){
        greater = a;
        smaller = b;
    } else {
        greater = b;
        smaller = a;
    }

    while(remainder > 0){
        remainder = greater % smaller;
        if(remainder == 0){
            return smaller;
        } else {
            greater = smaller;
            smaller = remainder;
        }
    }
    return smaller;
}

int solve(vector<int> a, vector<int> b){
    if(a.size() == 0){
        return 0;
    }
    int result = 1;

    unordered_map<string, int> mapping;
    int n = a.size();
    for(int i=0; i<n; i++){
        // mapping.clear();
        for(int j=i+1; j<n; j++){
            int y2y1 = b[j] - b[i];
            int x2x1 = a[j] - a[i];

            int gcd = getGcd(y2y1, x2x1); 

            y2y1 = y2y1 / gcd;
            x2x1 = x2x1 / gcd;
            if(y2y1 == 0){
                x2x1 = 0;
                y2y1 = 0;
            }
            else if(x2x1 == 0){
                x2x1 = INT_MAX;
                y2y1 = INT_MAX;
            }
            string key = "";
            if(y2y1 < 0 && x2x1 < 0){
                y2y1 = abs(y2y1);
                x2x1 = abs(x2x1);
                key = to_string(y2y1) + " " + to_string(x2x1);
            } else if((y2y1 > 0 && x2x1 < 0) || (y2y1 < 0 && x2x1 > 0)){
                y2y1 = abs(y2y1);
                x2x1 = abs(x2x1);
                y2y1 = -1 * y2y1;
                key = to_string(y2y1) + " " + to_string(x2x1);
            } else {
                key = to_string(y2y1) + " " + to_string(x2x1);
            }
            // cout << key << endl;

            int value = mapping[key];
            if(value == 0){
                mapping[key] = 2;
                result = max(result, mapping[key]);
            } else {
                mapping[key] = value + 1;
                result = max(result, mapping[key]);
            }
        }
    }

    return result;
}

int main(){
    // {-1, 1}, {0, 0}, {1, 1}, 
                    // {2, 2}, {3, 3}, {3, 4} 
    vector<int> a = {-6, 5, -18, 2, 5, -2};
    vector<int> b = {-17, -16, -17, -4, -13, 20};
    cout << "Given x-axis input is: " << endl;
    printVector(a);
    cout << "Given y axis input is: " << endl;
    printVector(b);

    int result = solve(a, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11