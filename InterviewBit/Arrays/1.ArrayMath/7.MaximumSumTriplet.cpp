/*
Problem Description

Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.



Problem Constraints
3 <= N <= 105.

1 <= A[i] <= 108.



Input Format
First argument is an integer array A.



Output Format
Return a single integer denoting the maximum sum of triplet as described in the question.



Example Input
Input 1:

 A = [2, 5, 3, 1, 4, 9]
Input 2:

 A = [1, 2, 3]


Example Output
Output 1:

 16
Output 2:

 6


Example Explanation
Explanation 1:

 All possible triplets are:-
    2 3 4 => sum = 9
    2 5 9 => sum = 16
    2 3 9 => sum = 14
    3 4 9 => sum = 16
    1 4 9 => sum = 14
  Maximum sum = 16
Explanation 2:

 All possible triplets are:-
    1 2 3 => sum = 6
 Maximum sum = 6
*/
#include<bits/stdc++.h>
using namespace std;

void printSet(set<int> arr) {
    set<int> :: iterator it;
    it = arr.begin();
    while(it != arr.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

void printArray(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> A) {

   vector<int> arr = A;

    int result = 0;
    int n = arr.size();

    // Let's create max suffix array first
    vector<int> suffixArray(n, 0);

    int maxValue = 0;
    // std::cout << "Suffix array is: " << endl;
    for(int i=n-1; i>=0; i--) {
        // cout << arr[i] << " -> ";
        maxValue = max(maxValue, arr[i]);
        suffixArray[i] = maxValue;
        // std::cout << suffixArray[i] << " ";
    }
    // std::cout << endl;

    set<int> left;
    left.insert(arr[0]);

    for(int i=1; i < n - 1; i++) {
        // std::cout << "For: " << arr[i] << endl;

        // std::cout << "Left set is: " << endl;
        // printSet(left);

        // maxright
        int maxRight = suffixArray[i];
        // std::cout << "Max Right: " << maxRight << endl;
        // maxleft
        int maxLeft = 0;

        set<int> :: iterator it;
        it = left.end();
        it--;
        if(arr[i] <= *left.begin()) {
            // std::cout << "Smaller" << endl;
            maxLeft = *left.begin();
        } 
        
        else if(arr[i] >= *it) {
            // std::cout << "Greater" << endl;
            maxLeft = *it;
        } 
        
        else if(arr[i] > *left.begin() && arr[i] < *it) {
            it = left.lower_bound(arr[i]);
            it--;
            maxLeft = *it;
        }

        // std::cout << "Max Left: " << maxLeft << endl;

        int middle = arr[i];

        if(maxLeft < middle && middle < maxRight) {
            int sumValue = maxLeft + middle + maxRight;
            result = max(result, sumValue);
        }

        left.insert(arr[i]);

        // std::cout << endl;
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
        cout << "Result: " << result << endl;;
        cout << endl;
    }
    return 0;
}


/*
Solution Approach
Simple Approach is to traverse for every triplet with three nested ‘for loops’ and find update the sum of all triplets one by one. Time complexity of this approach is O(N3) which is not sufficient for larger value of ‘N’.


Better approach is to make further optimization in above approach.
Instead of traversing through every triplets with three nested loops, we can traverse through two nested loops.
While traversing through each number(assume as middle element(Aj)), find maximum number(Ai) smaller than Aj preceding it and maximum number(Ak) greater than Aj beyond it.
Now after that, update the maximum answer with calculated sum of Ai + Aj + Ak.
Time complexity: O(N2)
Auxiliary space: O(1)
This approach is also that much efficient we are looking for.


Best Approach:
Best and efficient approach is use the concept of maximum suffix-array and binary search.

For finding maximum number greater than given number beyond it,
we can maintain a maximum suffix-array array such that for any number(suffix[i]) it would contain maximum number 
from index i, i+1, … N-1. 
Suffix array can be calculated in O(N) time.

For finding maximum number smaller than the given number preceding it, we can maintain a sorted list of numbers before a given number such we can simply perform a binary search to find a number which is just smaller than the given number. In C++ language, we can perform this by using set associative container of STL library.

Time complexity: O(NlogN)
Auxiliary space: O(N)
*/