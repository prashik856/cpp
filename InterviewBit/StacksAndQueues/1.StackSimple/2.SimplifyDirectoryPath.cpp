/*
Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.




Input Format

The only argument given is string A.
Output Format

Return a string denoting the simplified absolue path for a file (Unix-style).
For Example

Input 1:
    A = "/home/"
Output 1:
    "/home"

Input 2:
    A = "/a/./b/../../c/"
Output 2:
    "/c"
*/

/*
Looks easy.
Store all the directory names in a stack
Take care while storing:
    -> if directoryname is . -> don't do anything
    -> if direcotryname is .. -> pop the stack if not empty
    -> if directoryname is empty -> don't do anything
    -> if directoryname is none of the three above, push it in the stack.
Reverse the stack
Create the relative path using the new stack.
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

string solve(string a){
    stack<string> st;
    int n = a.size();
    // Check if we need to return root path
    if(a[0] == '/' && n==1){
        return "/";
    }

    int i=0;
    if(a[i] == '/'){
        i++;
    }
    // cout << "Storing all directories in stack: " << endl;
    string directoryName = "";
    for(; i<n; i++){
        if(a[i] == '/'){
            // if ., don't do any thing
            int compareValue = directoryName.compare(".");
            if(compareValue == 0){
                directoryName = "";
                continue;
            }

            // if .., pop the stack if not empty
            compareValue = directoryName.compare("..");
            if(compareValue == 0){
                if(!st.empty()){
                    st.pop();
                }
                directoryName = "";
                continue;
            }
            
            // if it's not . nor .., push 
            if(directoryName.size() > 0){
                st.push(directoryName);
                directoryName = "";
                continue;
            }
            
        } else {
            directoryName.push_back(a[i]);
        }
    }

    // cout << "Checking for last directory" << endl;
    // Check the last directory
    if(directoryName.size() > 0){
        // if ., don't do any thing
        int compareValue = directoryName.compare(".");
        if(compareValue == 0){
            directoryName = "";
        } 
    }

    if(directoryName.size() > 0){
        // if .., pop the stack if not empty
        int compareValue = directoryName.compare("..");
        if(compareValue == 0){
            if(!st.empty()){
                st.pop();
            }
            directoryName = "";
        }
    }
            
    if(directoryName.size() > 0){
        // if it's not . nor .., push 
        st.push(directoryName);
        directoryName = "";
    }     

    // cout << "Return root if stack is empty " << endl;
    if(st.empty()){
        return "/";
    }

    // Create the relative path here
    string result = "/";
    
    // cout << "Reversing our stack" << endl;
    // Create reversed stack first
    stack<string> tempStack;
    while(!st.empty()){
        string top = st.top();
        tempStack.push(top);
        st.pop();
    }

    // cout << "Creating relative path ..." << endl;
    // Create relative path here
    while(!tempStack.empty()){
        string top = tempStack.top();

        for(i=0; i<top.size(); i++){
            result.push_back(top[i]);
        }

        if(tempStack.size() != 1){
            result.push_back('/');
        }

        tempStack.pop();
    }

    return result;
}

int main(){
    string a = "/home//foo";
    cout << "Given String is: " << endl;
    cout << a << endl;

    string result = solve(a);
    cout << "Result is: " << endl;
    cout << result << endl;
    return 0;
}

// g++ -std=c++11