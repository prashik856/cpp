/*
Problem Description

Given an integer array A, find if an integer p exists in the array such that the number of integers 
greater than p in the array equals to p.

Input Format
First and only argument is an integer array A.



Output Format
Return 1 if any such integer p is found else return -1.



Example Input
Input 1:

 A = [3, 2, 1, 3]
Input 2:

 A = [1, 1, 3, 3]


Example Output
Output 1:

 1
Output 2:

 -1


Example Explanation
Explanation 1:

 For integer 2, there are 2 greater elements in the array. So, return 1.
Explanation 2:

 There is no such integer exists.
*/


/*
Solution approach:
Just sort and calculate the number of values via index.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    int result = -1;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for(int i=0; i< n; i++){
        if(i < n-1 && arr[i] == arr[i+1]){
            continue;
        } else {
            int noOfValuesGreater = n - 1 - i;
            if(arr[i] == noOfValuesGreater){
                result = 1;
                break;
            }
        }
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
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;
        
        int result = solve(arr);
        cout << "Result: " << result << endl;
        cout << endl;
    }
    return 0;
}