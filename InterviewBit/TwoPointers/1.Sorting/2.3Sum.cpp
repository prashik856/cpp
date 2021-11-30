/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 

Return the sum of the three integers.

Assume that there will only be one solution

Example: 

given array S = {-1 2 1 -4}, 

and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/

/*
n^2 complexity solution:
Sort the array
we start from i=0, and then we set l=i+1, r=n-1.
We have given sum as b. then remaining value that we need to check is b-a[i].
Now, using 2 sum, we check if we have some l and r such that a[l] + a[r] = b - a[i].
We take the closest value using this technique.

No need for 2 absolute differences -_-
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int b){
    int result = 0;
    int n = a.size();

    sort(a.begin(), a.end());
    int minimumDifference = INT_MAX;

    for(int i=0; i<n; i++){
        // cout << "Current Value is: " << a[i] << endl;
        int valueToFind = b - a[i];
        // cout << "Value to find: " << valueToFind << endl;
        // cout << endl;
        // Initializations
        int j=i+1,k=n-1;

        while(j<n && k>i){
            // cout << a[j] << " : " << a[k] << endl; 
            int currentSum = a[j] + a[k];
            // cout << "Curent Sum : " << currentSum << endl;

            // If our sum is equal
            if(currentSum == valueToFind && j != k){
                // cout << "Sum equal" << endl;
                return b;
            } 

            // If unequal values
            else if(currentSum != valueToFind && j != k) {
                // cout << "Unequal sums" << endl;
                // total sum
                int totalSum = currentSum + a[i];
                // cout << "Current Total Sum: " << totalSum << endl;

                // difference from required value
                int currentDifference = b - totalSum;
                int currentDifference2 = totalSum - b;
                // cout << "Currrent Difference: " << currentDifference << endl;
                // cout << "Current Difference 2: " << currentDifference2 << endl;

                // it's absolute difference
                int absoluteDifference = abs(currentDifference);
                int absoluteDifference2 = abs(currentDifference2);
                // cout << "Current Absolute Difference: " << absoluteDifference << endl;
                // cout << "Current Absolute Difference 2: " << absoluteDifference2 << endl;
    
                int minimumAbsoluteDifference = min(absoluteDifference, absoluteDifference2);

                // minimum of absolute difference
                minimumDifference = min(minimumDifference, minimumAbsoluteDifference);
                // cout << "Minimum Difference: " << minimumDifference << endl;

                // Got our value
                if(minimumDifference == minimumAbsoluteDifference){
                    result = currentSum + a[i];
                    // cout <<"Running result: " << result << endl;
                }
            }

            // Increments
            if(currentSum > valueToFind){
                k--;
                // cout << "Trying to decrese current sum" << endl;
            } else {
                j++;
                // cout << "Trying to increase current sum" << endl;
            }

            // cout << endl;
        }
        // cout << endl;

    }

    return result;
}

int main(){
    vector<int> a = {5, -2, -1, -10, 10};
    int b = 5;
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}