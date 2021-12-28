/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].

(order does not matter).
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/find-starting-indices-substrings-string-s-made-concatenating-words-listl/

Approach :
We can use Hashing Technique to solve the above problem. Let’s see the steps :

Declare a map (hash_map) which stores all words of List L corresponding to their occurrences inside list L.
Traverse through all possible substrings in string S which are equal to 
size_L (total number of characters produced if all the words in list L are concatenated).
Create a temporary map (temp_hash_map) and initialize it with original map(hash_map) for every possible substring.
Extract the words from the substring and if the word is present in temp_hash_map we decrease 
it’s corresponding count, if it’s not present in temp_hash_map we simply break.
After traversing the substring we traverse temp_hash_map and look for any key which has it’s count > 0. 
If we found no such key it means that all the words in list L were found in substring and store
the given starting index of the substring, if we find a key which has it’s count > 0 it means we did not 
traversed whole substring because we came across a word which was not in temp_hash_map.

Solvable, let's do it.
This worked.
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
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}

class ListNode{
    public: 
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> arr){
    ListNode *head = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int value = arr[i];
        ListNode *newNode = new ListNode(value);

        if(head == 0){
            head = newNode;
        } else {
            ListNode *temp = head;
            while(temp->next != 0){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    return head;
}

void printLinkedList(ListNode *head){
    ListNode *temp = head;
    while(temp != 0){
        cout << temp->val << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int getLinkedListLength(ListNode *head){
    ListNode *temp = head;
    int count = 0;
    while(temp !=0){
        temp = temp -> next;
        count++;
    }
    return count;
}

vector<int> solve(string a, vector<string> b){
    vector<int> result;
    
    int n = a.size();
    int m = b.size();
    if(m == 0){
        return result;
    }
    unordered_map<string, int> mapping;
    // Create original mapping
    for(int i=0; i<m; i++){
        mapping[b[i]] = mapping[b[i]] + 1;
    }

    int sizeOfSingleSubstring = b[0].size();
    int subStringLength = sizeOfSingleSubstring * m;
    int start = 0;
    // cout << "All substrings are: " << endl;
    while(start + subStringLength <= n){
        int include = true;
        unordered_map<string, int> temp = mapping;
        string subString;
        for(int i=start; i<start + subStringLength; i++){
            subString.push_back(a[i]);
            if(subString.size() == sizeOfSingleSubstring){
                // check here
                // cout << "Substring: " << subString << endl;
                int value = temp[subString];
                if(value == 0){
                    // the substring is present but not in mapping
                    include = false;
                    break;
                } else {
                    temp[subString] = temp[subString] - 1;
                }
                subString.clear();
            }
        }
        // cout << endl;

        // Check if all the substring values are 0
        for(int i=0; i<m; i++){
            int value = temp[b[i]];
            if(value != 0){
                include = false;
                break;
            }
        }

        // include the index
        if(include){
            result.push_back(start);
        }
        start++;
    }

    return result;
}

int main(){
    string a = "barfoothefoobarman";
    vector<string> b = {"foo", "bar"};
    cout << "Given input string is: " << a << endl;
    cout << "Given substrings are : " << endl;
    printStrings(b);

    vector<int> result = solve(a, b);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11