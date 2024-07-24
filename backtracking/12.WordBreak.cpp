/**
 * Word Break Problem
 * 
 * Given an input string and a dictionary of words, find out if the input string
 * can be segmented into space separated sequence of dictionary words.
 * 
 * Example:
 * Input Dictionary:
 * {i, like, sam, sung, samsung, mobile, ice, cream, icecream, man, go, mango}
 * 
 * Input: ilike
 * Output: Yes
 * The string can be segmented as "I Like"
 * 
 * Input: ilikesamsung
 * Output: Yes
 * The string can be segmented as "i like samsung"
 * or "i like sam sung".
 */

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<long> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<bool> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<char> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print4DVector(vector< vector< vector< vector<int>>>> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << i << " : " << endl;
        for(int j=0; j<arr[i].size(); j++) {
            cout << j << " : " << endl;
            for(int k=0; k<arr[j].size(); k++) {
                for(int l=0; l<arr[k].size(); l++) {
                    cout << arr[i][j][k][l] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

void print2DStrings(vector< vector<string> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(string &input, int index, unordered_map<string, int> &dictionary, 
    int &output) {
    cout << "Current Index Value: " << index << endl;

    // Break Point
    // Once output is Yes, return all the way.
    if(index == input.size() || output == 1) {
        // got some output
        output = 1;
        return;
    }

    string word = "";
    for(int i=index; i<input.size(); i++) {
        word.push_back(input[i]);

        // check if word is in dictionary
        if(dictionary.find(word) != dictionary.end()) {
            // found it.
            cout << "Found in dictionary" << endl;
            solve(input, i+1, dictionary, output);
        }
    }
}

int wordbreak(vector<string> dictionary, string input) {
    int intoutput = 0;
    // create dictionary
    unordered_map<string, int> mapping = unordered_map<string, int>();
    for(int i=0; i<dictionary.size(); i++) {
        mapping[dictionary[i]] = 1;
    }

    solve(input, 0, mapping, intoutput);

    return intoutput;
}

int main() {
    vector<string> dictionary = vector<string>({"i", "like", "sam", "sung", "samsung", "mobile", 
    "ice", "cream", "icecream", "man", "go", "mango"});
    string input = "ilikesamsung";

    int output = wordbreak(dictionary, input);

    cout << "Output: " << output << endl;
    return 0;
}