/*
Problem Description
 
 

 Given a string A with lowercase english alphabets and you have to return a string in which, with each character its frequency is written in adjacent.



Problem Constraints
1 <= |A| <= 105


Input Format
First argument is the string A with lowercase english alphabets.


Output Format
Return a string in which each character frequency is written in adjacent.


Example Input
Input 1:
abbhuabcfghh
Input 2:

a


Example Output
Ouput 1:
a2b3h3u1c1f1g1
Ouput 2:

a1


Example Explanation
Explanation 1:
‘a’ occurs in the string a total of 2 times so we write a2 then ‘b’ occurs a total of 3 times so next we write b3 and so on
Explanation 2:

‘a’ occurs in the string a total of 1 time only.
*/
/*
We need to maintain the order of the string!
*/
#include<bits/stdc++.h>
using namespace std;

string solve(string a){
    string result = "";

    int n = a.size();
    vector<int> count(26, 0);
    for(int i=0; i<n; i++){
        int start = 'a';
        int index = a[i] - start;
        if(count[index] == 0){
            result.push_back(a[i]);
        }
        count[index]++;
    }

    string temp = result;
    result = "";
    for(int i=0; i<temp.size(); i++){
        int start = 'a';
        int index = temp[i] - start;
        result.push_back(temp[i]);
        int frequency = count[index];
        string frequencyString = to_string(frequency);
        for(int i=0; i<frequencyString.size(); i++){
            result.push_back(frequencyString[i]);
        }
    }

    return result;
}

int main(){
    string a = "a";
    string result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}