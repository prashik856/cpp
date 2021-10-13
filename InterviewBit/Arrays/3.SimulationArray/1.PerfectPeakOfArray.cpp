/*
Problem Description

Given an integer array A of size N.

You need to check that whether there exist a element which is strictly greater than all the elements on left of it and strictly smaller than all the elements on right of it.

If it exists return 1 else return 0.

NOTE:

Do not consider the corner elements i.e A[0] and A[N-1] as the answer.


Problem Constraints
3 <= N <= 105

1 <= A[i] <= 109



Input Format
First and only argument is an integer array A containing N integers.



Output Format
Return 1 if there exist a element that is strictly greater than all the elements on left of it and strictly  smaller than all the elements on right of it else return 0.



Example Input
Input 1:

 A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
Input 2:

 A = [5, 1, 4, 4]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 A[4] = 6 is the element we are looking for.
 All elements on left of A[4] are smaller than it and all elements on right are greater.
Explanation 2:

 No such element exits.
*/

/*
Solution Approach:
1. Just normal for loops will do the trick
2. Take care of corner cases
    First element and last element does not count!
    Strictly word is very important here, we have to use less than equal to or greater than equal to!
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    int result=0;
    int n = arr.size();
    int valueFound = 0;
    for(int i=1; i<n-1; i++){
        int val = arr[i];
        bool found = true;

        for(int j=i-1; j>=0; j--){
            int left = arr[j];
            if(left >= val){
                found = false;
                break;
            }
        }

        if(found){
            for(int j=i+1; j<n; j++){
                int right = arr[j];
                if(right <= val) {
                    found = false;
                    break;
                }
            }
        }
        
        if(found){
            result = 1;
            valueFound = val;
            break;
        }
    }
    cout << "Result value: " << valueFound << endl;

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
        cout << "Result: " << result << endl;;
        cout << endl;
    }
    return 0;
}