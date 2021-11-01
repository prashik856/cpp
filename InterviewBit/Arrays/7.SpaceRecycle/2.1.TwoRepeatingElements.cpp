/*
https://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/
Find the two repeating elements in a given array

You are given an array of n+2 elements. 
All elements of the array are in range 1 to n. 
And all elements occur once except two numbers which occur twice. 
Find the two repeating numbers. 
*/
/*
Method 3 (Make two equations) 

Let the numbers which are being repeated are X and Y. 
We make two equations for X and Y and the simple task left is to solve the two equations. 
We know the sum of integers from 1 to n is n(n+1)/2 and product is n!. 
We calculate the sum of input array when this sum is subtracted from n(n+1)/2, we get X + Y because X and Y are the two numbers missing 
from set [1..n]. 
Similarly calculate the product of input array, 
when this product is divided from n!, we get X*Y. 

Given the sum and product of X and Y, we can find easily out X and Y.
Let summation of all numbers in the array be S and product be P
X + Y = S – n(n+1)/2 
XY = P/n!
Using the above two equations, we can find out X and Y. For array = 4 2 4 5 2 3 1, we get S = 21 and P as 960.
X + Y = 21 – 15 = 6
XY = 960/5! = 8
X – Y = sqrt((X+Y)^2 – 4*XY) = sqrt(4) = 2
Using below two equations, we easily get X = (6 + 2)/2 and Y = (6-2)/2 
X + Y = 6 
X – Y = 2
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

long long fact(int n){
    long long result=1;

    if(n==1){
        return 1;
    }

    for(int i=1; i<=n; i++){
        result = result * i;
    }

    return result;
}

void solve(vector<int> arr) {
    int result;
    int n = arr.size() - 2;

    long sumArray = 0;
    long long mulArray = 1;

    for(int i=0; i<arr.size(); i++) {
        sumArray += arr[i];
        mulArray *= arr[i];
    }

    long S = n * (n+1);
    S = S / 2;
    cout << "Sum of n: " << S << endl;

    long long M = fact(n);
    cout << "Fact n: " << M << endl;

    int sumOfTwo = sumArray - S;
    int mulOfTwo = mulArray/M;
    cout << "Sum of 2: " << sumOfTwo << endl;
    cout << "Mul of 2: " << mulOfTwo << endl;

    int x = (sumOfTwo + sqrt(sumOfTwo * sumOfTwo - 4 * mulOfTwo))/2;
    int y = sumOfTwo - x;

    cout << x << " and " << y << endl;
    // return result;
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
        
        solve(arr);
        // cout << "Result: " <<  result << endl;

        cout << endl;
    }
    return 0;
}