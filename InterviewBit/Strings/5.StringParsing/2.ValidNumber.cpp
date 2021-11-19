/*
Note: It is intended for some problems to be ambiguous. You should gather all requirements up front before implementing one.

Please think of all the corner cases and clarifications yourself.

Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?

For this problem, no.

Is 0.1e10 valid?

Yes

-01.1e-10?

Yes

Hexadecimal numbers like 0xFF?

Not for the purpose of this problem

3. (. not followed by a digit)?

No

Can exponent have decimal numbers? 3e0.1?

Not for this problem.

Is 1f ( floating point number with f as prefix ) valid?

Not for this problem.

How about 1000LL or 1000L ( C++ representation for long and long long numbers )?

Not for this problem.

How about integers preceded by 00 or 0? like 008?

Yes for this problem
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    int result = 1;
    int n = a.size();
    bool gotNumber = false;
    bool gotDecimal = false;
    bool gotE = false;
    bool gotMinus = false;

    string number;
    for(int i=0; i<n; i++){
        bool isANumber = (a[i] >= '0' && a[i] <= '9') ;
        bool isMinus = (a[i] == '-');
        bool isDecimalPoint = (a[i] == '.');
        bool isE = (a[i] == 'e'); 
        // Check if first character starts with either from 0 to 9, or from minus sign
        if( i==0 && !(isANumber || isMinus) ){
            // not valid
            return 0;
        }

        if(i == 0 && a[i] == '-'){
            gotNumber = false;
            gotDecimal = false;
            gotE = false;
            gotMinus = true;
            // valid
            continue;
        }

        if(i > 0){
            
            if(gotMinus && !isANumber){
                // cannot have -e, or -.
                return 0;
            }


        }

    }

    return result;
}

int main(){
    string a = "0";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}