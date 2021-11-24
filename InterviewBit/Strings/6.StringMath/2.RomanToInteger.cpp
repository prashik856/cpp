/*
Given a string A representing a roman numeral.

Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more 

details about roman numerals at Roman Numeric System




Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
*/
/*
Solution approach:
https://www.geeksforgeeks.org/converting-roman-numerals-decimal-lying-1-3999/
> Split the Roman Numeral string into Roman Symbols (character).
> Convert each symbol of Roman Numerals into the value it represents.
> Take symbol one by one from starting from index 0: 
> If current value of symbol is greater than or equal to the value of next symbol, then add this value to the running total.
> else subtract this value by adding the value of next symbol to the running total.
*/
#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    int result = 0;
    unordered_map<string, int> romanIntegers;

    // empty
    if(a.size() == 0){
        return 0;
    }
    if(a[0] == ' '){
        return 0;
    }

    // decimals
    romanIntegers[""] = 0;
    romanIntegers["I"] = 1;
    romanIntegers["IV"] = 4;
    romanIntegers["V"] = 5;
    romanIntegers["IX"] = 9;
    romanIntegers["X"] = 10;
    romanIntegers["XL"] = 40;
    romanIntegers["L"] = 50;
    romanIntegers["XC"] = 90;
    romanIntegers["C"] = 100;
    romanIntegers["CD"] = 400;
    romanIntegers["D"] = 500;
    romanIntegers["CM"] = 900;
    romanIntegers["M"] = 1000;

    for(int i=0; i<a.size(); i++){
        string temp1 = "";
        temp1.push_back(a[i]);
        int temp1Int = romanIntegers[temp1];

        string temp2 = "";
        if(i + 1 < a.size()){
            temp2.push_back(a[i+1]);
        }
        int temp2Int = romanIntegers[temp2];

        if(temp1Int < temp2Int){
            string temp3;
            temp3.push_back(a[i]);
            temp3.push_back(a[i+1]);
            int temp3Int = romanIntegers[temp3];
            result += temp3Int;
            i++;
        } else {
            result += temp1Int;
        }
        
    }

    return result;
}

int main(){
    string a = "MMMCMXCIX";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}