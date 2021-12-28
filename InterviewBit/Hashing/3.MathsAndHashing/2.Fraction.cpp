/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example :

Given numerator = 1, denominator = 2, return "0.5"
Given numerator = 2, denominator = 1, return "2"
Given numerator = 2, denominator = 3, return "0.(6)"
*/

/*
Let's give it a try ourselves.
Nope. Not working.

https://www.geeksforgeeks.org/represent-the-fraction-of-two-numbers-in-the-string-format/
Approach: 
The idea is to first calculate the integral quotient (absolute part before decimal point) 
and then calculate the fractional part. 
To check if the fractional part is repeating, insert the remainder (numerator % denominator) 
in a map with key as remainder and value as the index position at which this remainder occurs. 
If at any point of time, the remainder becomes zero, then there doesn’t exist a repeating fraction otherwise 
if the remainder is already found in the map, then there exists a repeating fraction.

The above method worked, and I was able to implement it.
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

string solve(int a, int b){
    string result = "";

    long A = (long)a;
    long B = (long)b;
    if((A < 0 && B > 0) || (A > 0 && B < 0)){
        result = "-";
        A = abs(A);
        B = abs(B);
    }
    if(A < 0 && B < 0){
        A = abs(A);
        B = abs(B);
    }
    unordered_map<long, int> remainderHash;
    long quotient = A/B;
    long remainder = A % B;
    if(remainder == 0){
        result = to_string(quotient);
        return result;
    }
    else {
        result = result + to_string(quotient) + ".";
        if(remainder < 0){
            remainder = remainder * -1;
        }
        bool repeat = false;
        string decimalString = "";
        int index = result.size();
        while(!repeat && remainder != 0){
            // we first multiply
            remainder = remainder * 10;
            // check if remainder is repeated
            int mapValue = remainderHash[remainder];
            if(mapValue > 0){
                // repeated
                result.push_back(')');
                int insertIndex = mapValue;
                result.insert(result.begin()+insertIndex, '(');
                return result;
            } else {
                // not repeating
                remainderHash[remainder] = index;

                // get quotient
                quotient = remainder / B;
                // get remainder
                remainder = remainder % B;
                result = result + to_string(quotient);
                index = result.size();
            }
        }
    }

    return result;
}

int main(){
    int a = -1;
    int b = 2;
    cout << "Given input is: " << a << " " << b << endl;

    string result = solve(a, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11