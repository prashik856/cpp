/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.

Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

Note:

If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
Method 1 ( Brute force solution ) 
1- Generate all substrings of string1 (“this is a test string”) 
2- For each substring, check whether the substring contains all characters of string2 (“tist”) 
3- Finally, print the smallest substring containing all characters of string2.
  
Method 2 ( Efficient Solution ) 
> First check if the length of the string is less than the length of the given pattern, 
if yes then “no such window can exist “.
> Store the occurrence of characters of the given pattern in a hash_pat[].
> we will be using two pointer technique basically
> Start matching the characters of pattern with the characters of string i.e. increment count if a character matches.
5.> Check if (count == length of pattern ) this means a window is found.
> If such a window found, try to minimize it by removing extra characters from the beginning of the current window.
> delete one character from first and again find this deleted key at right, once found apply step 5 .
> Update min_length.
> Print the minimum length window.

Goooott it.
Let's try it.

Understand the minWindow property properly!
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

string solve(string a, string b){
    string result = "";
    
    int n = a.size();
    int m = b.size();
    if(m > n){
        return result;
    }
    int minLength = INT_MAX;
    int foundSubstring = false;
    // let's use 2 maps, one for pattern and other for our string
    unordered_map<char, int> patternMap;
    unordered_map<char, int> stringMap;
    
    // store mapping
    for(int i=0; i<m; i++){
        patternMap[b[i]]++;
    }

    int start = 0;
    int startIndex = -1;
    int count = 0;
    for(int i=0; i<n; i++){
        char value = a[i];
        stringMap[value]++;

        // check if our current value matches the pattern
        // first check if character is present in pattern
        // second check if this character is to be included in our string or not.
        if(patternMap[value] > 0 && 
            stringMap[value] <= patternMap[value] ){
            count++;
        }
        
        // this is the current sized window
        if(count == m){
            // Minimizing window
            // Here, Our first check is to check if first string character is present in 
            // pattern.
            // The second check is, if string has extra character (start index) in it. 
            // If string does, that means we can remove it.
            // for any case, we increase our start index.
            // This will ensure the minLength window
            while(patternMap[a[start]] == 0 ||
                stringMap[a[start]] > patternMap[a[start]]){
                    if(stringMap[a[start]] > patternMap[a[start]]){
                        stringMap[a[start]]--;
                    }
                    start++;
                }
            // Update maxLength
            int currentLength = i - start + 1;
            if(currentLength < minLength){
                minLength = currentLength;
                startIndex = start;
            }
        }
    }

    if(startIndex == -1){
        return result;
    }
    else {
        for(int i =startIndex; i<startIndex + minLength; i++){
            result.push_back(a[i]);
        }
    }
    return result;
}

int main(){
    string a = "ADOBECODEBANC";
    string b = "ABC";
    cout << "Given string is: " << a << endl;
    cout << "Given pattern is: " << b << endl;
    
    string result = solve(a, b);
    cout << "Result: " << result << endl;

    return 0;
}

// g++ -std=c++11