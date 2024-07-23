/*
Permutations of String

Flow: 
1. Inputs and Outputs
2. Input and output methods
3. Recrusive Tree - Number of choices are large and controlled recursion.
4. Code
5. Time Complexity

Input: 
String: abc
Output: vector<string> - This should be all possible combinations which are unique.

E.g. for abc
Output should be:
abc
acb
bac
bca
cab
cba

Input Output Method:
IP      OP
abc     

Using input, we try to get the output in the leaf.
root is ""
Now, for "", we have 3 choices
either a, b, or c.
So, for empty root, we will get three children, a,b, and c as output

IP      OP
"bc"    "a"
"ac"    "b"
"ab"    "c"

Now, in the next recursive step, we will get this
"c" "ab"
"b" "ac"
"c" "ba"
"a" "bc"
"b" "ca"
"a" "cb"

In the next recursive step, input will be empty, and we will get all our outputs
""  "abc"
""  "acb"
"" "bac"
""  "bca"
""  "cab"
""  "cba"
Since input is empty, our base condition does not satisfy.

Now, what about unique permutations?
what if we have duplicates in our input string.

E.g. Input: aab
Out outputs will be this:
aab
aba
aab
aba
baa
baa

We can use controlled recursion for this.
We can remove duplicates.
Or
We can avoid doing duplicates. (Better solution. This is controlled recursion. We cut branches.)
or
We can remove duplicates from input first?

*/


#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<string>
#include<set>
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

// function to get a new string after removing an index
string getNewInput(string input, int index) {
    string output = "";
    for(int i=0; i<input.length(); i++) {
        if(i == index) {
            continue;
        } else {
            output.push_back(input[i]);
        }
    }
    return output;
}

void solve(string input, vector<string> &output, string tempOutput) {
    // cout << "Current Input: " << input << endl;
    // cout << "Current Output: " << tempOutput << endl;

    if(input.length() == 0) {
        // cout << "Got some output: " << tempOutput << endl;
        output.push_back(tempOutput);
        // base condition reached. 
        return;
    }

    // Set or a dict needed here to handle duplicates
    set<char> choiceTaken = set<char>();

    // Number of choices is actually the input length
    for(int i=0; i<input.length(); i++) {
        char item = input[i];
        if(choiceTaken.find(item) == choiceTaken.end()) {
            choiceTaken.insert(item);
            // I have not taken this choice
            // cout << "Item: " << item << " not found in the output" << endl;
            // I did not found duplicates
            // new input
            string newInput = getNewInput(input, i);
            
            // new output
            string currentOutput = tempOutput;
            currentOutput.push_back(item);
            
            // Recursion
            solve(newInput, output, currentOutput);
        } else {
            // cout << "I have already used " << item << endl;
        }
        
    }
    // cout << endl;
}

vector<string> getAllPermutationsRecursion(string input) {
    vector<string> output = vector<string>();
    solve(input, output, "");
    return output;
}


vector<string> getAllPermutationsBacktracking(string input) {
    vector<string> output = vector<string>();

    return output;
}

int main(){
    string input = "aaadha";
    cout << "Input: " << input << endl;

    vector<string> output = getAllPermutationsRecursion(input);
    
    cout << "Output: " << endl;
    printStrings(output);

    // vector<string> output = getAllPermutationsBacktracking(input);
    
    // cout << "Output: " << endl;
    // printStrings(output);
}
// g++ -std=c++11