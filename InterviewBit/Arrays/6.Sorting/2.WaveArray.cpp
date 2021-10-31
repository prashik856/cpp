/*
Problem Description

Given an array of integers A, sort the array into a wave like array and return it, In other words, arrange the elements into a sequence such that 

a1 >= a2 <= a3 >= a4 <= a5.....
NOTE : If there are multiple answers possible, return the one that's lexicographically smallest.



Problem Constraints
1 <= len(A) <= 106

1 <= A[i] <= 106



Input Format
First argument is an integer array A.



Output Format
Return an array arranged in the sequence as described.



Example Input
Input 1:

A = [1, 2, 3, 4]
Input 2:

A = [1, 2]


Example Output
Output 1:

[2, 1, 4, 3]
Output 2:

[2, 1]


Example Explanation
Explanation 1:

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
First answer is lexicographically smallest. So, return [2, 1, 4, 3].
Explanation 1:

Only possible answer is [2, 1].
*/

/*
Solution Approach:
We need wave like array.
First sort the array, we get increasing order of the elements.
Now, we need a wave, with first number greater than second.
So, we firt need even element, and then odd element, and continue till the end.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> solve(vector<int> arr) {
    vector<int> result;
    int n = arr.size();

    sort(arr.begin(), arr.end());
    // cout << "Sorted Array" << endl;
    
    // even 1 2 3 4
    if( n % 2 == 0){
        for(int i=0; i<=n - 1; i++){
            if( i % 2 == 0){
                result.push_back(arr[i+1]);
            } else {
                result.push_back(arr[i-1]);
            }
        }
    } 
    // odd 1 2 3 4 5
    else {
        for(int i=0; i<n - 1; i++){
            if( i % 2 == 0){
                result.push_back(arr[i+1]);
            } else {
                result.push_back(arr[i-1]);
            }
        }
        result.push_back(arr[n-1]);
    }
    // printVector(result);

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;
        
        vector<int> result = solve(arr);
        cout << "Result: " << endl;
        printVector(result);
        cout << endl;
    }
    return 0;
}