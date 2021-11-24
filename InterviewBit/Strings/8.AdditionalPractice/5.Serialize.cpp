/*
Problem Description
 
 

You are given an array A of strings and we have to serialize it and return the serialized string.

Serialization: Scan each element in a string, calculate its length and append it with a string and a element separator or deliminator (the deliminator is ~). We append the length of the string so that we know the length of each element.

For example, for a string 'interviewbit', its serialized version would be 'interviewbit12~'.



Problem Constraints
1 <= |A| <= 1000
1 <= |Ai| <= 1000
Ai only contains lowercase english alphabets.


Input Format
The first argument A is the string array A.


Output Format
Return a single integer denoting the serialized string.


Example Input
Input 1:
A = ['scaler', 'academy']
Input 2:

A = ['interviewbit']


Example Output
Output 1:
scaler6~academy7~
Output 2:

interviewbit12~


Example Explanation
Explanation 1:
Length of 'scaler' is 6 and academy is 7. So, the resulting string is scaler6~academy7~.
Explanation 2:

Explained in the description above.
*/
/*
Easy enough
*/
#include<bits/stdc++.h>
using namespace std;

string solve(vector<string> a){
    string result = "";
    int n = a.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<a[i].size(); j++){
            result.push_back(a[i][j]);
        }
        int length = a[i].size();
        string lengthString = to_string(length);
        for(int j=0; j<lengthString.size(); j++){
            result.push_back(lengthString[j]);
        }
        result.push_back('~');
    }

    return result;
}

int main(){
    vector<string> a = {"scaler", "academy"};
    string result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}