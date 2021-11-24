/*
Problem Description
 
 

You are given a string A which is a serialized string. You have to restore the original array of strings.

The string in the output array should only have lowercase english alphabets.

Serialization: Scan each element in a string, calculate its length and append it with a string and a element separator or deliminator (the deliminator is ~). We append the length of the string so that we know the length of each element.

For example, for a string 'interviewbit', its serialized version would be 'interviewbit12~'.



Problem Constraints
1 <= |A| <= 106


Input Format
The first argument is the string A.


Output Format
Return an array of strings which are deserialized.


Example Input
Input 1:
A = 'scaler6~academy7~'
Input 2:

A = 'interviewbit12~'


Example Output
Output 1:
['scaler', 'academy']
Output 2:

['interviewbit']


Example Explanation
Explanation 1:
Length of 'scaler' is 6 and academy is 7. So, the resulting string is scaler6~academy7~.
We hve to reverse the process.
Explanation 2:

Explained in the description above.
*/
/*
Solution Approach:
Assuming everything is lowercased.
It worked.  
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<string> solve(string a){
    vector<string> result;
    int n = a.size();

    vector< vector<int> > allStrings;

    int index = 0;
    string tempString = "";
    for(int i=0; i<n; i++){
        if(a[i] >= 'a' && a[i] <= 'z'){
            tempString.push_back(a[i]);
            continue;
        }
        if(a[i] == '~'){
            result.push_back(tempString);
            tempString = "";
            continue;
        }

    }

    return result;
}

int main(){
    string a = "scaler6~academy7~";
    vector<string> result = solve(a);
    cout << "Result is: " << endl;
    printVector(result);
    return 0;
}