/**
 * Find the index of 1st 1 in a Binary Sorted Array.
 * 
 * Given an infinite sorted array consisting of 0s and 1s, 
 * the problem is to find the index of first 1 in that array.
 * 
 * Very similar to our previous problem.
 * The first task is to find the index where 1 comes, so that 
 * we have our low and high.
 * 
 * Once we have low and high, and elements, we can find the first occurance
 * of 1 using binary search.
 */
#include<bits/stdc++.h>
using namespace std;

int indexOfFirst1(vector<int> &input) {
    int output = -1;

    int low = 0;
    int high = 0;
    while(input[high] != 1) {
        low = high;
        high = high * 2;
    }

    // Now we have our limits, where low and high are present,
    // let's write the code to find the first occurance.
    while(high >= low) {
        int mid = (high + low)/2;

        if(input[mid] == 1) {
            output = mid;
            // go left
            // find efficient solution
            high = mid - 1;
        } else {
            // go right
            low = mid + 1;
        }
    }

    return output;
}