/**
 * Permute a String by changing case
 * 
 * Given string, print all permutations of a string keeping the sequence 
 * but changing cases.
 * 
 * E.g. 
 * Input: ab
 * Output: AB Ab ab aB
 * 
 * Input: ABC
 * Output: abc Abc aBc ABc abC AbC aBC ABC
 * 
 * Only difference is to write a revertCharCase() function.
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

        return;
    }

int main() {
    string input = "AbC";
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