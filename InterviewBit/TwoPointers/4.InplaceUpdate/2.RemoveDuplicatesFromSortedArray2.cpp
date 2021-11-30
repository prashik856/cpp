/*
https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/
Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Note that even though we want you to return the new length, make sure to change the original array as well in place

For example,

Given input array A = [1,1,1,2],

Your function should return length = 3, and A is now [1,1,2].
*/
/*
Easy question, but many corner cases.
Need to take care of them first!!!
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

int solve(vector<int> &a){
    if(a.size() == 1){
        return 1;
    }
    int result = 1;
    int n = a.size();
    int count = 1;
    int index = 1;

    // Let's fist do for the first element
    int i = 1;
    while(a[i] == a[i-1]){
        i++;
        count++;
    }
    // cout << "Repeating elements till " << i << " index" << endl;
    if(count >= 2){
        index = 2;
        result = 2;
    }

    // For the second repeating element
    int temp = i;
    count = 1;    
    for(i=temp+1; i<n; i++){
        if(a[i] == a[i-1]){
            count++;
        } else {
            if(count == 1){
                a[index] = a[i-1];
                index++;
                result++;
                count = 1;
            }
            else if(count >= 2){
                a[index] = a[i-1];
                index++;
                a[index] = a[i-1];
                index++;
                result += 2;
                count = 1;
            }            
        }
    }

    cout << "Before evaluating last index" << endl;
    printVector(a);

    if(count == 1){
        a[index] = a[n-1];
        index++;
        result++;
    }
    if(count >=2){
        a[index] = a[n-1];
        index++;
        a[index] = a[n-1];
        index++;
        result += 2;
    }
    cout << "After evaluating last index" << endl;
    printVector(a);

    return result;
}

int main(){
    vector<int> a = {0, 1, 1, 2, 2};
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}

// g++ -std=c++11