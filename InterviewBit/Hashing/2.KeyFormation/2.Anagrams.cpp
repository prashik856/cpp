/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'

Note:  All inputs will be in lower-case.

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
cat and tca are anagrams which correspond to index 1 and 4. 

dog and god are another set of anagrams which correspond to index 2 and 3.

The indices are 1 based ( the first element has index 1 instead of index 0).

Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.
*/

/*
For every string, we will create a key with their count of words.
We will also need to use visited to see if the current string is included in the result.
Okay. My method worked.
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

string getCount(string a){
    vector<int> count(26, 0);
    string key = "";
    for(int i=0; i<a.size(); i++){
        int index = a[i] - 'a';
        count[index]++;
    }
    for(int i=0; i<count.size(); i++){
        key = key + to_string(count[i]);
        key.push_back(' ');
    }
    return key;
}

vector< vector<int> > solve(vector<string> a){
    vector< vector<int> > result;

    int n = a.size();
    unordered_map< string, vector<int> > mapping;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        string key = getCount(a[i]);
        vector<int> mapValue = mapping[key];
        if(mapValue.size() == 0){
            vector<int> temp;
            temp.push_back(i+1);
            mapping[key] = temp;
        } else {
            mapValue.push_back(i+1);
            mapping[key] = mapValue;
        }
    }

    for(int i=0; i<n; i++){
        // cout << a[i] << endl;
        if(visited[i]){
            continue;
        } else {
            string key = getCount(a[i]);
            // cout << key << endl;
            vector<int> mapValue = mapping[key];
            // printVector(mapValue);
            vector<int> temp;
            if(mapValue.size() == 0){
                continue;
            }
            for(int j=0; j<mapValue.size(); j++){
                int indexValue = mapValue[j] - 1;
                visited[indexValue] = true;
                temp.push_back(indexValue + 1);
            }
            result.push_back(temp);
        }
    }

    return result;
}

int main(){
    vector<string> a = {"cat", "dog", "god", "tca"};
    cout << "Given input is: " << endl;
    printStrings(a);

    vector< vector<int> > result = solve(a);
    cout << "Result is: " << endl;
    print2DVector(result);
    return 0;
}

// g++ -std=c++11