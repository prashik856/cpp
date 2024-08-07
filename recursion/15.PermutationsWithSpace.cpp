/**
 * Permutations With Space
 * 
 * Input: a string, s: "ABC"
 * Output:
 * ["ABC", "AB C", "A BC", "A B C"]
 * 
 * We need to get all possible combination where we can put a space in between string.
 * 
 * For this, we can use our input/output method.
 */
#include<bits/stdc++.h>
using namespace std;

void getAllSpacePermutations(string &input, int index, string &currentOutput, 
set<string> &allOutputs) {
    // cout << "Current Index: " << index << endl;
    // cout << "Current Output: " << currentOutput << endl;

    // if index is last
    if(index == input.size()) {
        // cout << "Got some output: " << endl;
        allOutputs.insert(currentOutput);
        
        // return 
        return;
    }

    // don't put space
    currentOutput.push_back(input[index]);
    index++;
    getAllSpacePermutations(input, index, currentOutput, allOutputs);

    // backtrack
    currentOutput.pop_back();
    index--;

    // put space
    currentOutput.push_back(' ');
    currentOutput.push_back(input[index]);
    index++;
    getAllSpacePermutations(input, index, currentOutput, allOutputs);

    // backtrack
    currentOutput.pop_back();
    currentOutput.pop_back();
    return;
}

int main() {
    string input = "ABCDE";
    cout << "Input: " << input << endl;

    string currentOutput = "";
    set<string> allOutputs = set<string>();
    int index = 0;
    // init for index
    currentOutput.push_back(input[index]);
    index++;

    getAllSpacePermutations(input, index, currentOutput, allOutputs);
    cout << "Output: " << endl;
    for(set<string>::iterator it=allOutputs.begin(); it!=allOutputs.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}