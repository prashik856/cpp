/**
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

    countAndSay(1) = "1"
    countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) 
with the concatenation of the character and the number marking the count of the characters (length of the run). 

For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". 
Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"


Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.

Constraints:

    1 <= n <= 30

*/
#include<bits/stdc++.h>
using namespace std;

int getCount(string &str, int insiderIndex, char val) {
    int count = 0;
    while(str[insiderIndex] == val) {
        count++;
        insiderIndex++;
    }
    return count;
}

string countAndSay(int n) {
    string result = "1";

    if(n == 1) {
        return result;
    }

    vector<string> outputs(n);

    outputs[0] = "1";

    int index = 1;
    while(index < n) {
        string currentResult = outputs[index - 1];
        // cout << "Current Result is: " << currentResult << endl;
        
        int insiderIndex = 0;
        while(insiderIndex < currentResult.size()) {
            // cout << "Current Insider Index: " << insiderIndex << endl;

            char val = currentResult[insiderIndex];
            // cout << "Current val: " << val << endl;
            
            int count = getCount(currentResult, insiderIndex, val);
            // cout << "Count of current val :" << count << endl;

            outputs[index] = outputs[index] + to_string(count);
            outputs[index].push_back(val);

            // cout << "Current Output is: " << outputs[index];

            insiderIndex = insiderIndex + count;
        }

        index++;
    }

    return outputs[index-1];
}

int main() {
    vector<int> inputs = {1, 2, 3, 4, 5, 6, 7, 8, 15, 20, 29, 30};
    vector<string> outputs = {"1", "11", "21", "1211", "111221", "312211", "13112221", "", "", "", "", ""};

    for(int i=0; i<inputs.size(); i++) {
        cout << "Input: " << inputs[i] << endl;

        string output = countAndSay(inputs[i]);

        cout << "Current Output: " << output << endl;

        cout << "Expected output: " << outputs[i] << endl;
        cout << endl;
    }

    return 0;
}