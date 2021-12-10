/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.




Input Format

The only argument given is character array A.
Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.
For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6
*/
/*
Okay. My solution works
Logic:
1-> if stack is empty, push the value
    else 
        if top is operand -> push the value
        else 
            top is not an operand
            value = a[i];
            while(stack is not empty && top is not an operand){
                evaulate value with st.top and it's operand
                value = evaluated value
            }
return stack.top()
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

bool isOperand(string value){
    if(value.size() > 1){
        return false;
    } else {
        if( value[0] == '-' || 
            value[0] == '*' || 
            value[0] == '+' ||
            value[0] == '/'){
                return true;
            }
    }
    return false;
}

int solve(vector<string> a){
    int result = 0;
    int n = a.size();

    stack<string> st;
    for(int i=n-1; i>=0; i--){
        string value = a[i];
        // cout << "Current value is: " << value << endl;
        if(st.empty()){
            // cout << "Stack is empty" << endl; 
            st.push(value);
        } else {
            // check if this value is expression
            if(isOperand(value)){
                // cout << "Current Value is an operand" << endl;
                st.push(value);
            } else {
                // We check if stack top is an operand
                string topStack = st.top();
                if(isOperand(topStack)){
                    // top stack is an operand
                    // cout << "Top Stack is an operand" << endl;
                    st.push(value);
                } 
                // top stack is an integer.
                else {
                    // cout << "Top stack is an integer" << endl;
                    int currentResult = 0;
                    int intValue = stoi(value);
                    // cout << "Evaluating value in int is: " << intValue << endl;
                    while(!st.empty() && !isOperand(st.top())){
                        int intTopStack = stoi(st.top());
                        // cout << "Top Stack value in int is: " << intTopStack << endl;
                        st.pop();
                        string operand = st.top();
                        // cout << "Operand is: " << operand << endl;
                        st.pop();
                        if(operand[0] == '-'){
                            // cout << "Subtracting" << endl;
                            currentResult = intValue - intTopStack;
                        } else if(operand[0] == '+'){
                            // cout << "Adding" << endl;
                            currentResult = intValue + intTopStack;
                        } else if(operand[0] == '*'){
                            // cout << "Multiplying" << endl;
                            currentResult = intValue * intTopStack;
                        } else if(operand[0] == '/'){
                            // cout << "Dividing" << endl;
                            currentResult = intValue / intTopStack;
                        }
                        // cout << "Current Result in int is: " << currentResult << endl;
                        intValue = currentResult;
                    }
                    string currentResultString = to_string(currentResult);
                    st.push(currentResultString);
                }
            }
        }
        // cout << endl;
    }

    result = stoi(st.top());
    return result;
}

int main(){
    vector<string> a = {"4", "13", "5", "/", "+"};
    cout << "Given expression is: " << endl;
    printStrings(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11