/**
 * Find missing and duplicate numbers in an array
 * 
 * Given an unsorted array of size n. 
 * Array elements are in the range from 1 to n. 
 * One number from set {1, 2, …n} is missing and one number occurs twice in the array. 
 * Find these two numbers in order of one space.
 * Input:[3 1 2 5 3] 
 * Output:[3, 4] 
 * Duplicate = 3, Missing = 4 . 
 * 
 * Classical solution to solve 1 to N problems.
 * Need swap sort for this.
 * 
 * NEED:
 * Input:
 * arr[] : {}
 * 
 * In this array, we have numbers from 1 to n, where n is the size of array.
 * This array need not be sorted.
 * This is our ideal case where all numbers are present.
 * 
 * In our given array, one of our number is missing, and one of the number is duplicate.
 * So, instead of {1, 2, 3, 4, 5}
 * Our given array will be {1, 4, 3, 4, 5}
 * Here, 2 is missing, and 4 is duplicate.
 * 
 * These types of problems are called 1 to N problems.
 * 
 * 
 * SOLUTION:
 * Using extra space, we can use map to solve this problem.
 * We can traverse through the array once to store values in map. we can then use this map
 * to get our missing and duplicate number as we know, in our array
 * we have numbers from 1 to N.
 * 
 * But we are using O(N) extra space.
 * 
 * Can we do it in O(1) space?
 * 
 * We can do it with simple maths.
 * We know the ideal sum of numbers should be n(n+1)/2.
 * So, ideally, our sum of array should be n(n+1)/2.
 * let's say x and y are our missing and duplicate numbers.
 * So, if we subtract the duplicate number and add the missing number in our 
 * current sum, our ideal sum should be equal to n(n+1)/2.
 * 
 * So, x-y+sum(arr[]) = n(n+1)/2
 * This becomes our first equation.
 * 
 * Similarly, we know that ideally our sum of squares of array is n(n+1)(2n+1)/2
 * So, if we add x^2 and subtract y^2, our sum should be equal to n(n+1)(2n+1)/2.
 * 
 * So, our second equation becomes
 * x^2 - y^2 + sum(arr[i]^2) = n(n+1)(2n+1)/6
 * 
 * Now, we have two equations, and two unknows.
 * since x and y are distinct numbers, x-y != 0.
 * 
 * So (x+y)(x-y) = n(n+1)(2n+1)/6 - sum(arr[i]^2)
 * We know, value of x-y is n(n+1)/2 - sum(arr[i])
 * x+y = (n(n+1)(2n+1)/6 - sum(arr[i]^2))/(n(n+1)/2 - sum(arr[i]))
 * x-y = n(n+1)/2 - sum(arr[i])
 * 
 * x-y = c1
 * x+y = c2/c1
 * 
 * 2*x = c1 + c2/c1
 * x = (c1*c1 + c2)/2*c1
 * y = c2/c1 - x
 * 
 * And now, we have to equations, and two unknows, we can find our answer using maths.
 * 
 * This will be one way to solve this problem.
 * 
 * Alternatively, we can just use Swap Sort Algorithm.
 */
#include <iostream>
#include<vector>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

long getSum(vector<int> arr) {
    long sum = 0;

    for(int i=0; i<arr.size(); i++) {
        sum = sum + arr[i];
    }

    return sum;
}

long getSumOfSquares(vector<int> arr) {
    long sumOfSquares = 0;
    
    for(int i=0; i<arr.size(); i++) {
        sumOfSquares = sumOfSquares + arr[i]*arr[i];
    }

    return sumOfSquares;
}

vector<int> findMissingAndDuplicateUsingMath(vector<int> &arr) {
    vector<int> output = vector<int>(2, 0);
    int n = arr.size();

    long sumOfArray = getSum(arr);
    long sumOfSquares = getSumOfSquares(arr);

    long idealSum = (n * (n+1))/2;
    long idealSumOfSquares = (n*(n+1)*(2*n+1))/6;

    cout << "Sum of Array: " << sumOfArray << endl;
    cout << "Sum of Squares of Array: " << sumOfSquares << endl;

    cout << "Ideal sum of array: " << idealSum << endl;
    cout << "Ideal sum of squares of array: " << idealSumOfSquares << endl;

    long c1 = idealSum - sumOfArray;
    long c2 = idealSumOfSquares - sumOfSquares;

    cout << "Constant 1: " << c1 << endl;
    cout << "Constant 2: " << c2 << endl;

    long missingNumber = (c1*c1 + c2)/(2*c1);
    long duplicateNumber = c2/c1 - missingNumber;

    output[0] = missingNumber;
    output[1] = duplicateNumber;

    return output;
}

int main() {
    vector<int> arr = vector<int>({10, 1, 2, 5, 4, 3, 9, 8, 7, 9});
    cout << "Input: " << endl;

    vector<int> output = findMissingAndDuplicateUsingMath(arr);
    cout << "Missing: " << output[0] << " | Duplicate: " << output[1] << endl;

    return 0;
}