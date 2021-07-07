// Explanation: https://www.youtube.com/watch?v=lsQTYlCiU6c&ab_channel=Knapsak
// Question: https://www.hackerrank.com/challenges/largest-rectangle/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=stacks-queues

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

void printStack(stack<long> p){
    cout << "Value in stack is" << endl;
    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }
    cout << endl;
}

long largestRectangle(vector<int> h) {
    long result = 0;
    // Prepare stacks to store positions and heights
    stack<long> pStack;
    stack<long> hStack;
    long lastIndex = numeric_limits<long> :: max();
    
    // Add this value to process all the available rectanges 
    // at the end in our while loop
    h.push_back(0);
    
    // Start our loop
    for(int i=0; i<h.size(); i++){
        // cout << "Current height: " << h[i] << endl;
        // Stack shouldn't be empty

        // we use lastIndex only when both while loop 
        // and if conditions are being executed
        bool useLastIndex = false;
        while(!pStack.empty() && h[i] < hStack.top()) {
            // cout << "Height is less than hStack top" << endl;
            // cout << "Height in stack: " << hStack.top() << endl;
            lastIndex = pStack.top();
            useLastIndex = true;
            // cout << "Value of lastIndex is: " << lastIndex << endl;
            // Calculate width and height
            long width = (i - pStack.top());
            long height = hStack.top();
            long area = width * height;
            // cout << "Current Rectangle Area: " << area << endl;
            result = max(result, area);
            // cout << "Current Result: " << result << endl;
            pStack.pop();
            hStack.pop();
            // printStack(pStack);
            // printStack(hStack);
        } 
        
        // If either stack is empty or a height greater than stack top
        if(pStack.empty() || h[i] > hStack.top()){
            // set minValue between lastIndex and i
            // cout << "Height greater than hstack top" << endl;
            if(useLastIndex){
                if(lastIndex < i){
                    pStack.push(lastIndex);
                } else {
                    pStack.push(i);
                }
            } else {
                pStack.push(i);
            }
            // put height in stack
            hStack.push(h[i]);
            // printStack(pStack);
            // printStack(hStack);
        }
        
        // cout << endl;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
