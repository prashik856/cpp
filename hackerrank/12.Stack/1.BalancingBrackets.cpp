//https://www.hackerrank.com/challenges/balanced-brackets/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=stacks-queues

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
 
void printStack(stack<char> st){
    cout << "Content of stack are: " << endl;
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
 

string isBalanced(string s) {
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        // If stack is empty, just push
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            // cout << "Pushing in stack" << endl;
            st.push(s[i]);
            // printStack(st);
        } else {
            if(s[i] == ')' && !st.empty()){
                if(st.top() == '('){
                    // cout << "Popping from stack" << endl;
                    st.pop();
                    // printStack(st);
                } else {
                    // not balanced
                    // cout << "Stack is not balanced" << endl;
                    return "NO";
                }
            }
            else if(s[i] == ')' && st.empty()){
                // cout << "Stack is empty and pushing ). Stack will become unbalanced" << endl;
                return "NO";
            }
            
            if(s[i] == ']' && !st.empty()){
                if(st.top() == '['){
                    // cout << "Popping stack " << endl;
                    st.pop();
                    // printStack(st);
                } else {
                    // cout << "Stack is not balanced" << endl;
                    return "NO";
                }
            } else if(s[i] == ']' && st.empty()){
                // cout << "Stack is empty and pushing ]. Stack will become unbalanced" << endl;
                return "NO";
            }
            
            if(s[i] == '}' && !st.empty()){
                if(st.top() == '{'){
                    // cout << "Popping stack" << endl;
                    st.pop();
                    // printStack(st);
                } else {
                    // cout << "Stack is not balanced" << endl;
                    return "NO";
                }
            } else if(s[i] == '}' && st.empty()){
                // cout << "Stack is empty and pushing }. Stack will become unbalanced" << endl;
                return "NO";
            }
        }
    }
    if(st.empty()){
        // cout << "Stack is finally empty" << endl;
        return "YES";
    }
    
    // cout << "Stack is not empty" << endl;
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
