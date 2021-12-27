/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
*/
/*
Since we have an int, the max lenght of this int number will be 9
We can just generate all possible subsequences.
Get the product of each digit of these subsequences and check the result.
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

int getDigits(int a){
    int result = 0;
    while(a > 0){
        result++;
        a = a/10;
    }
    return result;
}

int getMultiplicationValue(int a){
    int temp = a;
    int result = 1;
    while(temp > 0){
        // get the last digit
        int value = temp % 10;
        // multiply by result
        result = result * value;
        // decrease value
        temp = temp / 10;
    }
    return result;
}

int solve(int a){
    int result = 1;
    a = abs(a);
    string strA = to_string(a);
    vector<string> subsequences;
    unordered_map<int, int> mapping;

    int n = getDigits(a);
    // first size
    for(int i=0; i<n; i++){
        // start with first index
        for(int j=0; j<n-i; j++){
            // end till size
            string subString = "";
            for(int k=j; k<=j+i; k++){
                subString.push_back(strA[k]);
            }
            subsequences.push_back(subString);
            // cout << subString << endl;
        }
    }

    for(int i=0; i<subsequences.size(); i++){
        int intSubsequence = stoi(subsequences[i]);
        int multValue = getMultiplicationValue(intSubsequence);
        int value = mapping[multValue];
        // cout << "Mult Value: " << multValue << endl;
        if(value > 0){
            return 0;
        } else {
            mapping[multValue] = 1;
        }
    }

    return result;
}

int main(){
    int a = 3245;
    cout << "Given number is: " << a << endl;
    
    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11