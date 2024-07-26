/** Maximum Sum Subarray of Size K
 * 
 * Flow: 
 * 1. Problem Statement Input Output
 * 2. Identification
 * 3. Abstract - Code
 * 4. Code
 * 
 * Given an array: 2,3,5,2,9,7,1
 * Input n = 3.
 * 
 * Subarray is a continuous segment of the array.
 * 
 * Now, for any subarray of size n, sum them up, get the maximum value.
 * 
 * So for any given array, return the maximum sum of subarray of size n.
 * 
 * Brute force can be done with two for loops.
 * 
 * Improvements can be done. Can we remove some repetivie work?
 * 
 * If i is first index, and j is the second index,
 * window size can be represented as (j - i + 1)
 * 
 * Once (j-i+1) == k, we can then slide the window.
 * Till we hit this point, we can keep on increasing the value of j while keeping i constant.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxSubarraySumWindow(vector<int>&arr, int n) {
    int output = 0;
    int sum = 0;
    int i=0,j=0;
    while(j<arr.size()) {
        sum = sum + arr[j];
        if(j-i+1 < n) {
            j++;
        } else if(j-i+1 == n) {
            if(sum > output) {
                output = sum;
            }

            sum = sum - arr[i];
            i++;
            j++;
        }
    }

    return output;
}

int maxSubarraySum(vector<int>&arr, int n) {
    int output = 0;

    int sum = 0;
    if(n >=arr.size() - 1) {
        for(int i=0; i<arr.size(); i++) {
            sum = sum + arr[i];
        }
        return sum;
    }

    if(n < arr.size()-1) {
        for(int i=0; i<n; i++) {
            sum = sum + arr[i];
        }
        if(sum > output) {
            output = sum;
        }

        int i = 0,j=n;
        while(j<arr.size()) {
            sum = sum - arr[i];
            sum = sum + arr[j];
            if(sum > output) {
                output = sum;
            }
            i++;j++;
        }
    } 
    
    return output;
}

int main() {
    vector<int> arr = vector<int>({2, 3, 5, 2, 9, 7, 8});
    int n = 3;
    cout << "Input Array: " << endl;
    printVector(arr);
    cout << "Window Size: " << n << endl;

    int output = maxSubarraySum(arr, n);
    cout << "Output: " << output << endl;

    output = maxSubarraySumWindow(arr, n);
    cout << "Output Window: " << output << endl;
}