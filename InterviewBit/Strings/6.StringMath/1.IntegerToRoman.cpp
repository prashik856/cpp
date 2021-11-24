/*
Another question which belongs to the category of questions which are intentionally stated vaguely. 

Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output”

For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations.




Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
*/
/*
My solution worked.
Start from the decimal place, and look for the values that we need.
Create a map for ease.
*/

#include<bits/stdc++.h>
using namespace std;

string solve(int a){
    string result;

    unordered_map<int, string> romanIntegers;
    // Decimal
    romanIntegers[0] = "";
    romanIntegers[1] = "I";
    romanIntegers[2] = "II";
    romanIntegers[3] = "III";
    romanIntegers[4] = "IV";
    romanIntegers[5] = "V";
    romanIntegers[6] = "VI";
    romanIntegers[7] = "VII";
    romanIntegers[8] = "VIII";
    romanIntegers[9] = "IX";
    // Tens
    romanIntegers[10] = "X";
    romanIntegers[20] = "XX";
    romanIntegers[30] = "XXX";
    romanIntegers[40] = "XL";
    romanIntegers[50] = "L";
    romanIntegers[60] = "LX";
    romanIntegers[70] = "LXX";
    romanIntegers[80] = "LXXX";
    romanIntegers[90] = "XC";
    // Hundreds
    romanIntegers[100] = "C";
    romanIntegers[200] = "CC";
    romanIntegers[300] = "CCC";
    romanIntegers[400] = "CD";
    romanIntegers[500] = "D";
    romanIntegers[600] = "DC";
    romanIntegers[700] = "DCC";
    romanIntegers[800] = "DCCC";
    romanIntegers[900] = "CM";
    // Thousands
    romanIntegers[1000] = "M";
    romanIntegers[2000] = "MM";
    romanIntegers[3000] = "MMM";
    
    int temp = a;
    if(temp == 0){
        return "";
    }

    // start with 10s place
    int place = 10;

    while(temp > 0){
        // cout << "Current temp value: " << temp << endl;
        int num = temp % place;
        // cout << "Value of num is: " << num << endl;

        string numRoman = romanIntegers[num];
        // cout << "Num in roman numbers: " << numRoman << endl;
        result = numRoman + result;
        // cout << "Current Roman result: " << result << endl;

        temp = temp/place;
        temp = temp * place;
        place = place * 10;
    }

    return result;
}

int main(){
    int a = 3999;
    string result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}