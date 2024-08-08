/**
 * Letter Case Permutation
 * 
 * Given string s, we can transform every letter individually to be lowercase or uppercase
 * to create another string.
 * 
 * return all possible strings.
 * 
 * Input: s = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * s = "3z4"
 * Output: ["3z4", "3Z4"]
 */

#include<bits/stdc++.h>
using namespace std;

char revertCharCase(char item) {
    int diff = int('a') - int('A');

    int charInt = -1;
    if(int(item) >= 97) {
        // Do Upper
        charInt = int(item) - diff;
        // cout << "Upper: " << char(charInt) << endl;
    } else {
        // Do Lower
        charInt = int(item) + diff;
        // cout << "Lower: " << char(charInt) << endl;
    }
    return char(charInt);
}

void getAllCasePermutations(string &input, int index, string &currentOutput, 
    vector<string> &allOutput) {
        if(index == input.size()) {
            // Got some output
            allOutput.push_back(currentOutput);
            return;
        }

        char item = input[index];
        index++;

        if(int(item) >= int('0') && int(item) <= int('9')) {
            // a digit obtained
            currentOutput.push_back(item);
            getAllCasePermutations(input, index, currentOutput, allOutput);

            // backtrack
            currentOutput.pop_back();
        } else {
            // an english char obtained
            // don't revert
            currentOutput.push_back(item);
            getAllCasePermutations(input, index, currentOutput, allOutput);

            // backtrack
            currentOutput.pop_back();

            // revert
            char revertItem = revertCharCase(item);
            currentOutput.push_back(revertItem);
            getAllCasePermutations(input, index, currentOutput, allOutput);

            // backtrack
            currentOutput.pop_back();
        }

        return;
    }

int main() {
    string input = "3z4";
    cout << "Input: " << input << endl;

    vector<string> allOutput = vector<string>();
    string currentOutput = "";
    int index = 0;

    getAllCasePermutations(input, index, currentOutput, allOutput);
    cout << "Output: " << endl;
    for(int i=0; i<allOutput.size(); i++) {
        cout << allOutput[i] << " ";
    }
    cout << endl;

    return 0;
}