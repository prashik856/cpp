/*
Problem Description

Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum value of j - i;



Example Input
Input 1:

 A = [3, 5, 4, 2]


Example Output
Output 1:

 2


Example Explanation
Explanation 1:

 Maximum value occurs for pair (3, 4).
*/
/*
Solution approach:
https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
Method 2 – 
Improvising the Brute Force Algorithm and looking for BUD, i.e Bottlenecks, unnecessary and duplicated works. 
A quick observation actually shows that we have been looking to find the first greatest element traversing from 
the end of the array to the current index. 
We can see that we are trying to find the first greatest element again and again for each element in the array. 
Let’s say we have an array with us for example [1, 5, 12, 4, 9] now we know that 9 is the element that is greater 
than 1, 5, and 4 but why do we need to find that again and again. 
We can actually keep a track of the maximum number moving from the end to the start of the array. 
The approach will help us understand better and also this improvisation is great to come up with in an interview. 

Approach :  
Traverse the array from the end and keep a track of the maximum number to the right of the current index including self
Now we have a monotonous decreasing array, and we know we can use binary search to find the index of the rightmost greater element
Now we will just use binary search for each of the elements in the array and 
store the maximum difference of the indices and that’s it we are done.
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> arr){
    int result = 0;
    int n = arr.size();

    vector<int> maxSuffixArray(n, 0);

    int currentMax = numeric_limits<int>::min();
    // Need to implement merge sort
    for(int i=n-1; i>=0; i--){
        if(arr[i] > currentMax){
            currentMax = arr[i];
            maxSuffixArray[i] = currentMax;
        } else {
            maxSuffixArray[i] = currentMax;
        }
    }
    // cout << "Max suffix array is: " << endl;
    // printVector(maxSuffixArray);

    int ans = -1;
    for(int i=0; i<arr.size(); i++){
        int value = arr[i];
        // find value closest to arr[i]
        int low = i; int high = n - 1;
        while(low <= high){
            int mid = (low + high)/2;
            // if smaller, move to right
            if(value <= maxSuffixArray[mid]){
                // since here j > i, and arr[j] > arr[i], we get the local max value (ans)
                ans = max(ans, mid);
                low = mid+1;
            } 
            // else move to left
            else {
                high = mid-1;
            }
        }
        // global max values
        result = max(result, ans - i);
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