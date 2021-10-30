/*
Given a positive integer n and a string s consisting only of letters D or I, 
you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes

Length of given string s will always equal to n - 1
Your solution should run in linear time and space.
Example :

Input 1:

n = 3

s = ID

Return: [1, 3, 2]
*/

/*
IB Solution?
vector Solution::findPerm(const string A, int B){
    vector ans;
    int l=1,r=B;
    for(int i=0;i<B;i++){
        switch(A[i]){
            case ‘I’: {
                ans.push_back(l++);
                break;
            }
            case ‘D’: {
                ans.push_back(r–);
                break;
            }
        }
    }

    switch(A[B-2]){
        case ‘I’:{
            ans.push_back(l++);
            break;
        }
        case ‘D’:{
            ans.push_back(r–);
            break;
        }
    }
return ans;
}
This looks just a easy way of increasing and decreasing a value!

*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> solve(string A, int B) {
    vector<int> result;
    int l=1;
    int r=B;
    for(int i=0; i<A.size(); i++){
        switch (A[i]) {
            case('I'): {
                result.push_back(l++);
                break;
            }
            case('D'): {
                result.push_back(r--);
                break;
            }
        }
    }
    if(A[B-2] == 'I'){
        result.push_back(l++);
    } else {
        result.push_back(r--);
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        string arr;
        cout << "Given input array is: " << endl;
        cin >> arr;
        cout << arr << endl;
        vector<int> result = solve(arr, n);
        cout << "Result: " << endl;
        printVector(result);
        cout << endl;
    }
    return 0;
}