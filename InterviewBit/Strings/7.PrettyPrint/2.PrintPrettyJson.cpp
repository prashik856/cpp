/*
Given a string A representating json object. Return an array of string denoting json object with proper indentaion.

Rules for proper indentaion:

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Note:

[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.




Input Format

The only argument given is the integer array A.
Output Format

Return a list of strings, where each entry corresponds to a single line. The strings should not have "\n" character in them.
For Example

Input 1:
    A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"
Output 1:
    { 
        A:"B",
        C: 
        { 
            D:"E",
            F: 
            { 
                G:"H",
                I:"J"
            } 
        } 
    }

Input 2:
    A = ["foo", {"bar":["baz",null,1.0,2]}]
Output 2:
   [
        "foo", 
        {
            "bar":
            [
                "baz", 
                null, 
                1.0, 
                2
            ]
        }
    ]
*/
/*
Okay. 
this logic worked.
But I think it will fail, if the value (values inside quotes will contain a bracket.)
*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<string> a){
    for(int i=0; i<a.size(); i++){
        cout << a[i] << endl;
    }
}

vector<string> solve(string a){
    vector<string> result;
    int n = a.size();
    string indentation = "";
    string tempString;
    for(int i=0; i<n; i++){
        bool notABracket = (a[i] != '{' && a[i] != '}' && a[i] != '[' && a[i] != ']');
        bool aComma = (a[i] == ',');
        bool aColon = (a[i] == ':');

        if(a[i] == '{' || a[i] == '['){
            // show bracket
            tempString.push_back(a[i]);
            // go to next line
            result.push_back(tempString);
            tempString = "";
            // increase identation
            indentation.push_back('\t');
            // add identation
            tempString = tempString + indentation;
            continue;
        }

        if(a[i] == '}' || a[i] == ']'){
            // Go to next line
            result.push_back(tempString);
            // Decrease identation
            indentation.pop_back();
            // Add identation
            tempString = "";
            tempString = tempString + indentation;
            // show bracket
            tempString.push_back(a[i]);
            continue;
        }

        if(aColon && (a[i+1] == '{' || a[i+1] == '[')){
            tempString.push_back(a[i]);
            result.push_back(tempString);
            tempString = "";
            tempString = tempString + indentation;
            continue;
        }

        // if no { } or ,
        if(notABracket && !aComma){
            tempString.push_back(a[i]);
            continue;
        }

        if(notABracket && aComma){
            tempString.push_back(a[i]);
            result.push_back(tempString);
            tempString = "";
            tempString = tempString + indentation;
            continue;
        }

    }
    result.push_back(tempString);

    return result;
}

int main(){
    string a = "[\"foo\", {\"bar\":[\"baz\",null,1.0,2]}]";
    a = "{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}";
    vector<string> result = solve(a);
    cout << "Result is: " << endl;
    printVector(result);
    return 0;
}