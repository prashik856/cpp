/*
Solution Approach:
https://www.geeksforgeeks.org/allocate-minimum-number-pages/

The idea is to use Binary Search. 
We fix a value for the number of pages as mid of current minimum and maximum. 
We initialize minimum and maximum as 0 and sum-of-all-pages respectively. 

> If a current mid can be a solution, then we search on the lower half, else we search in higher half.
> Now the question arises, how to check if a mid value is feasible or not? 
Basically, we need to check if we can assign pages to all students in a way that the maximum number doesn’t exceed current value. 
> To do this, we sequentially assign pages to every student while the current number of assigned pages doesn’t exceed the value. 
> In this process, if the number of students becomes more than m, then the solution is not feasible. Else feasible.

Below is an implementation of above idea.
*/
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> a, int b, int currentMinimum) {
    int n = a.size();
    int currentSum = 0;
    int students = 1;
    for(int i=0; i<n; i++){
        // We assumed that a is sorted, but it is not.
        // If any book page value is greater than currentMinimum, solution is impossible [at least one book, man!]!
        if(a[i] > currentMinimum){
            return false;
        }

        // If our currentSum of Pages is greater than the currentMinimum value, we need to give this current book to 
        // different student.
        if(currentSum + a[i] > currentMinimum){
            currentSum = a[i];
            students++;

            // If our current Number of students exceeds max students, then this solution is impossible
            if(students > b){
                return false;
            }
        } 
        // If our current sum + a[i] is less than currentMinimum, no need to give a[i] to next student, 
        // we can just give it to current student. No need to increase student.
        else {
            currentSum += a[i];
        }
    }
    
    return true;
}

int solve(vector<int> a, int b){
    int n = a.size();

    // We need to assign at least 1 book to a student.
    // If number of books are actually less than number of students, that means the solution is not possible
    if(b > n) {
        return -1;
    }

    // The minimum Possible value is:
    int minValue = 0;
    int result = -1;
    // The max possible value will be the sum of all pages
    int maxValue = 0;
    for(int i=0; i<n; i++){
        maxValue += a[i];
    }

    // Need to check for equality as well, as it might be entirely possible.
    while(minValue <= maxValue) {
        int mid = (minValue + maxValue)/2;

        bool possible = isPossible(a, b, mid);

        if(possible){
            // We have one combination which is possible, so we store that combination.
            result = mid;
            
            // But since we need to find the actual minimum value of pages, we should decrease the value of maxValue
            // and check using this new maxValue, is the result possible?
            // We now already know that using maxValue = mid, the result is actually possible. 
            // Now, let's try using a lower maxValue
            maxValue = mid - 1;
        } else {
            // If our current minValue is impossible, we increase the value of our minValue
            // No need to check the max value, as it is always possible.
            minValue = mid + 1;
        }
    }
    
    return result;
}

int main(){
    vector<int> a = {73, 58, 30, 72, 44, 78, 23, 9};
    int b = 5;
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}