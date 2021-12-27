/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
Example : 

Given array S = {1 0 -1 0 -2 2}, and target = 0

A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)
Also make sure that the solution set is lexicographically sorted.

Solution[i] < Solution[j] 
iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])
*/
/*
Solution Approach:
We solve this using our approach like 2sum.
2sum -> O(n),
3Sum -> O(n^2),
4sum -> O(n^3)

Now, we take 3 loops, i,j,k which will start from 0th, 1st and 2nd index.
And we find if target - (a[i] + a[j] + a[k]) is present in the array.
if present, we check if the this solution is already present in our solution array.
We do this by using another map, where we store the key as the solution in terms of string.
If key does not exists, add the key in our map, add the vector in the resulting array, and move ahead.
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

vector< vector<int> > solve(vector<int> a, int b){
    vector< vector<int> > result;

    int n = a.size();
    sort(a.begin(), a.end());
    cout << "Sorted array is: " << endl;
    printVector(a);
    unordered_map<int, vector<int> > mapping;
    unordered_map<string, int> resultMap;

    // Saving our map
    for(int i=0; i<n; i++){
        int value = a[i];
        vector<int> mapValue = mapping[value];
        if(mapValue.size() == 0){
            vector<int> temp;
            temp.push_back(i+1);
            mapping[value] = temp;
        } else {
            mapValue.push_back(i+1);
            mapping[value] = mapValue;
        }
    }

    // Solving 4 sum.
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int sumValue = a[i] + a[j] + a[k];
                int valueToFind = b - sumValue;
                vector<int> mapValue = mapping[valueToFind];
                if(mapValue.size() == 0){
                    continue;
                } else {
                    for(int l=0; l<mapValue.size(); l++){
                        int indexValue = mapValue[l] - 1;
                        // got a perfect value
                        if(indexValue > i && 
                            indexValue > j && 
                            indexValue > k){
                                string key = to_string(a[i]) + " " + 
                                            to_string(a[j]) + " " + 
                                            to_string(a[k]) + " " + 
                                            to_string(a[indexValue]);
                                int resultMapValue = resultMap[key];
                                if(resultMapValue == 0){
                                    resultMap[key] = 1;
                                    vector<int> temp = {a[i], a[j], a[k], a[indexValue]};
                                    result.push_back(temp);
                                }
                            }
                    }
                }
            }
        }
    }

    return result;
}

int main(){
    vector<int> a = {1, 0, -1, 0, -2, 2};
    int b = 0;
    cout << "Given input array is: " << endl;
    printVector(a);
    cout << "Given target is: " << b << endl;

    vector< vector<int> > result = solve(a, b);
    cout << "Result is: " << endl;
    print2DVector(result);

    return 0;
}

// g++ -std=c++11