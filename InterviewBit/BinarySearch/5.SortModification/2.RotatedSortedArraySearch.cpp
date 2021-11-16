/*
Problem:
Given an array of integers A of size N and an integer B.

array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value B to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

NOTE:- Array A was sorted in non-decreasing order before rotation.

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*
Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return index of B in array A, otherwise return -1
Constraints

1 <= N <= 1000000
1 <= A[i] <= 10^9
all elements in A are disitinct.
For Example

Input 1:
    A = [4, 5, 6, 7, 0, 1, 2, 3]
    B = 4
Output 1:
    0
Explanation 1:
 Target 4 is found at index 0 in A.


Input 2:
    A = [5, 17, 100, 3]
    B = 6
Output 2:
    -1
*/
/*
Well well well, my solution worked.

Trick:
First find the pivot.
Then find the required value.
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> a, int b, int low, int high){
    int n = a.size();
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == b){
            return mid;
        }
        if(b > a[mid]){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int solve(vector<int> a, int b){
    int result = -1;
    int n = a.size();
    int low = 0;
    int high = n-1;
    // No pivot
    if(a[high] > a[low]){
        result = binarySearch(a, b, low, high);
        if(a[result] == b){
            return result;
        } else {
            return -1;
        }
    }

    int endPivot = -1;
    int startPivot = -1;
    while(low < high) {
        int mid = (low + high)/2;
        
        if(a[mid] == b){
            return mid;
        }

        if(mid + 1 < n && mid - 1 >= 0){
            if(a[mid] > a[mid+1] && a[mid] > a[mid - 1]){
                endPivot = mid;
                cout << "End Pivot is: " << a[mid] << endl;
                break;
            }
            if(a[mid] < a[mid-1] && a[mid] < a[mid + 1]){
                startPivot = mid;
                cout << "Start Pivot is: " << a[mid] << endl;
                break;
                
            }
        }

        if(a[mid] > a[high]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }

    }
    if(endPivot != -1){
        // we got endpivot
        if(b >= a[0]){
            result = binarySearch(a, b, 0, endPivot);
            if(a[result] == b){
                return result;
            } else {
                return -1;
            }
        } else {
            result = binarySearch(a, b, endPivot+1, n-1);
            if(a[result] == b){
                return result;
            } else {
                return -1;
            }
        }
    } else if(startPivot != -1){
        // we got start pivot
        if(b >= a[0]){
            result = binarySearch(a, b, 0, startPivot - 1);
            if(a[result] == b){
                return result;
            } else {
                return -1;
            }
        } else {
            result = binarySearch(a, b, startPivot, n-1);
            if(a[result] == b){
                return result;
            } else {
                return -1;
            }
        }
    }

    return -1;
}

int main(){
    vector<int> a = { 180, 181, 182, 183, 184, 187, 188, 189, 191, 192, 193, 194, 195, 196, 201, 202, 203, 204, 3, 4, 5, 6, 7, 8, 9, 10, 14, 16, 17, 18, 19, 23, 26, 27, 28, 29, 32, 33, 36, 37, 38, 39, 41, 42, 43, 45, 48, 51, 52, 53, 54, 56, 62, 63, 64, 67, 69, 72, 73, 75, 77, 78, 79, 83, 85, 87, 90, 91, 92, 93, 96, 98, 99, 101, 102, 104, 105, 106, 107, 108, 109, 111, 113, 115, 116, 118, 119, 120, 122, 123, 124, 126, 127, 129, 130, 135, 137, 138, 139, 143, 144, 145, 147, 149, 152, 155, 156, 160, 162, 163, 164, 166, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177};
    int b = 42;
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}