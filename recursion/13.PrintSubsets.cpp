/**
 * Print All Subsets | Print all Powersets | Print all Subsequences
 * 
 * Input Output Method.
 * Subset
 * Subset Duplication and other variations
 * Permutations with space
 * Permutations with case change
 * Josephus problem
 * Print space string
 * 
 * 
 * Recap:
 * If Input: "ab"
 * and Output: ""
 * For every character, we need to make a decision,
 * whether to take that character or not to take that character.
 * 
 * "" "ab"
 * 
 * Deciding for a
 * "" "b"   "a""b"
 * 
 * Deciding for b
 * """"   "b"""     "a"""   "ab"""
 * 
 * We can see, at the leaf node, we have input as empty, and some outputs.
 * We actually got all the possible combinations.
 */
#include<bits/stdc++.h>
using namespace std;

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

void getAllSubsets(string input, string output, vector<string> &allSubsets) {

    if(input.size() == 0) {
        allSubsets.push_back(output);
        return;
    }

    char topElement = input.back();
    input.pop_back();

    // don't add this top element
    getAllSubsets(input, output, allSubsets);

    // add this top element
    output.push_back(topElement);
    getAllSubsets(input, output, allSubsets); 

}

void getAllSubsets(string &input, string &output, int index, vector<string> &allSubsets) {
    if(index == input.size()) {
        // got some output
        string newOutput = output;
        allSubsets.push_back(newOutput);
        return;
    }

    char firstElement = input[index];
    index++;

    // don't take topElement
    getAllSubsets(input, output, index, allSubsets);

    // take this value
    output.push_back(firstElement);
    getAllSubsets(input, output, index, allSubsets);
    
    // backtrack because of pointers
    output.pop_back();

    return;
}


int main() {
    // print all subsets
    string input = "ab";
    cout << "Input: " << input << endl;

    vector<string> output = vector<string>();
    // can be done using pointers and indices too.
    getAllSubsets(input, "", output);
    
    cout << "Output: " << endl;
    printStrings(output);

    cout << "Solving using Pointers and Index." << endl;
    string tempOutput = "";
    vector<string> output2 = vector<string>();
    getAllSubsets(input, tempOutput, 0, output2);

    cout << "Output using index: " << endl;
    printStrings(output2);

    return 0;
}