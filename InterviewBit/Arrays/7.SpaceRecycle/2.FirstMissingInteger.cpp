/*

Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

*/

/*
Solution Approach:

*/

/*
Solution Approach:
https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
-> The smallest positive integer is 1. 
-> First we will check if 1 is present in the array or not. If it is not present then 1 is the answer.
-> If present then, again traverse the array. 
    The largest possible answer is N+1 where N is the size of array. 
    This will happen when array have all the elements from 1 to N. 
    When we are traversing the array, if we find any number less than 1 or greater than N, then we will change it to 1. 
    This will not change anything as answer will always between 1 to N+1. Now our array has elements from 1 to N.
-> Now, for every ith number, increase arr[ (arr[i]-1) ] by N. 
    But this will increase the value more than N. 
    So, we will access the array by arr[(arr[i]-1)%N]. 
    What we have done is for each value we have increased value at that index by N.
-> We will find now which index has value less than N+1. Then i+1 will be our answer.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> arr) {
    int result=0;

    int n = arr.size();
    // How shall we do this???

    bool found = false;
    for(int i=0; i<n; i++){
        if(arr[i] == 1){
            found = true;
        }

        if(arr[i] <= 0) {
            arr[i] = 1;
        } else if(arr[i] > n){
            arr[i] = 1;
        }
    }

    // cout << "1s applied: " << endl;
    // printVector(arr);

    if(!found){
        result = 1;
        return result;
    }

    for(int i=0; i<n; i++){
        int index = (arr[i] - 1) % n;
        arr[index] += n;
    }

    // cout << "Added N to indexes" << endl;
    // printVector(arr);

    for(int i=0; i<n; i++) {
        if(arr[i] < n + 1) {
            result = i + 1;
            break;
        }
    }

    if(result == 0){
        return n + 1;
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << "Given size of array is: " << n << endl;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
                int temp;
                cin >> temp;
                arr[i] = temp;
                cout << temp << " ";
        }
        cout << endl;
        
        int result = solve(arr);
        cout << "Result: " <<  result << endl;

        cout << endl;
    }
    return 0;
}