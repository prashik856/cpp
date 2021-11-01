/*
Problem Description

You're given a read only array of n integers.
Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
If so, return the integer. 
If not, return -1.

If there are multiple solutions, return any one.

Example:

Input: [1 2 3 1 1]
Output: 1 
1 occurs 3 times which is more than 5/3 times.
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/n3-repeated-number-array-o1-space/
We make use of Moore's Voting Algorithm!

But rather than finding just one majority element, we actually find two majority elements,
and find the actual counts of these two elements.

Difficulties?
-> How do we find the two major elements?
Take care of implementation of how we have calculated the first and second majority elements!
// if this element is previously seen,
        // increment count1.
        if (first == arr[i])
            count1++;
 
        // if this element is previously seen,
        // increment count2.
        else if (second == arr[i])
            count2++;
     
        else if (count1 == 0) {
            count1++;
            first = arr[i];
        }
 
        else if (count2 == 0) {
            count2++;
            second = arr[i];
        }
 
        // if current element is different from
        // both the previously seen variables,
        // decrement both the counts.
        else {
            count1--;
            count2--;
        }
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
    int result = -1;

    int first = numeric_limits<int>::max();
    int count1 = 0;
    int second = numeric_limits<int>::max();
    int count2 = 0;

    // find first majority
    for(int i=0; i<arr.size(); i++){
        if(first == arr[i]){
            count1++;
        }
        else if(second == arr[i]){
            count2++;
        } else if(count1 == 0){
            count1 = 1;
            first = arr[i];
        } else if(count2 == 0){
            count2 = 1;
            second = arr[i];
        } else {
            count1--;
            count2--;
        }
    }

    // find second majority
    // cout << "Value first majority element index is: " << first << endl;
    // cout << "Second majority element value is: " << second << endl;

    // Let's check counts
    count1 = 0;
    count2 = 0;
    for(int i=0; i<arr.size(); i++){
        if(first == arr[i]){
            count1++;
        }
        if(second == arr[i]){
            count2++;
        }
    }

    // cout << "Count of Majority 1 element: " << count1 << endl;
    // cout << "Count of majority 2 element: " << count2 << endl;

    int limit = arr.size()/3;
    if(count1 > limit){
        result = first;
        return result;
    } else if(count2 > limit){
        result = second;
        return result;
    } else {
        result = -1;
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
        cout << "Result: " << result << endl;

        cout << endl;
    }
    return 0;
}