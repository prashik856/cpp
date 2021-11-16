/*
Problem Description

Given a string A consisting of lowercase characters.

You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.

Return the count of substring modulo 109 + 7.



Problem Constraints
1 <= |A| <= 105

A consists only of lower-case characters.



Input Format
First argument is an string A.



Output Format
Return a integer denoting the the number of substrings in A which starts with vowel and end with consonants or vice-versa with modulo 109 + 7.



Example Input
Input 1:

 A = "aba"
Input 2:

 A = "a"


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

 Substrings of S are : [a, ab, aba, b, ba, a]Out of these only 'ab' and 'ba' satisfy the condition for special Substring. So the answer is 2.
Explanation 2:

 No possible substring that start with vowel and end with consonant or vice-versa.
*/

/*
Solution approach:
Need to create two suffix arrays, one for vowels and one for consonant.
And thus we can solve this problem.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(string a){
    int MOD = 1000000007;
    int result = 0;
    int n = a.size();
    vector<int> consonantArray(n, 0);
    vector<int> vowelsArray(n,0);
    int consonantCount = 0;
    int vowelsCount = 0;
    for(int i=n-1; i>=0; i--){
        if(a[i] != 'a' && 
            a[i] != 'e' && 
            a[i] != 'i' && 
            a[i] != 'o' && 
            a[i] != 'u'){
                consonantCount++;
            } else {
                vowelsCount++;
            }
        consonantArray[i] = consonantCount;
        vowelsArray[i] = vowelsCount;
    }
    // printVector(consonantArray);
    // printVector(vowelsArray);

    for(int i=0; i<n; i++){
        if(a[i] == 'a' || 
            a[i] == 'e' || 
            a[i] == 'i' || 
            a[i] == 'o' || 
            a[i] == 'u') {
                int numberOfSubstrings = consonantArray[i];
                result += numberOfSubstrings;
                result = result % MOD;
            } else {
                int numberOfSubstrings = vowelsArray[i];
                result += numberOfSubstrings;
                result = result % MOD;
            }
    }

    return result;
}

int main(){
    string a = "a";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}