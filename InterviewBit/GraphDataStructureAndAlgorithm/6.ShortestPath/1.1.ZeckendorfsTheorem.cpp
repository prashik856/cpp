/*
Page:https://www.geeksforgeeks.org/zeckendorfs-theorem-non-neighbouring-fibonacci-representation/

Zeckendorf’s theorem states that every positive integer can be written uniquely as a 
sum of distinct non-neighbouring Fibonacci numbers. 
Two Fibonacci numbers are neighbours if they one come after other in Fibonacci Sequence 
(0, 1, 1, 2, 3, 5, ..). 
For example, 3 and 5 are neighbours, but 2 and 5 are not.
The idea is to use Greedy Algorithm. 
1) Let n be input number
2) While n >= 0
     a) Find the greatest Fibonacci Number smaller than n.
        Let this number be 'f'.  Print 'f'
     b) n = n - f 
*/
#include<bits/stdc++.h>
using namespace std;

int getFibo(int n){
    int a = 1;
    int b = 1;
    int val = a + b;
    b = a;
    a = val;
    if(n == 1){
        return 1;
    } 
    if(n == 2){
        return 1;
    }
    else {
        while(val < n){
            val = a + b;
            b = a;
            a = val;
        }
        return b;
    }
}

int main(){
    int n = 123982973;

    int sum = n;
    while(sum > 0){
        int val = getFibo(sum);
        cout << sum << " -> " << val << " " << endl;
        sum = sum - val;
    }
    cout << endl;
    return 0;
}