// https://www.geeksforgeeks.org/maximum-subarray-sum-modulo-m/
// https://www.quora.com/What-is-the-logic-used-in-the-HackerRank-Maximise-Sum-problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maximumSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER_ARRAY a
 *  2. LONG_INTEGER m
 */

//https://www.geeksforgeeks.org/maximum-subarray-sum-modulo-m/
//https://www.quora.com/What-is-the-logic-used-in-the-HackerRank-Maximise-Sum-problem
long maximumSum(vector<long> a, long m) {
    long result = 0;
    int n = a.size();
    
    // Create set (a sorted array that we need)
    set<long> s;
    
    // Create prefix array
    long prefix;
    
    long long sum = 0;
    for(int i=0; i<n; i++){
        // Get sum till now
        sum = sum + a[i];
        
        // Get prefix value
        prefix = sum % m;
        
        // Check if prefix + 1 is available
        // This gets a closest value greater than prefix
        auto it = s.lower_bound(prefix + 1);
        
        // If we find a value greater than prefix
        // Check for result
        // This takes care of all sub arrays max
        if(it != s.end()){
            result = max(result, prefix - (*it) + m);
        }
        
        // geeks problem needs to add this condition
        // this takes care of sub till current index
        result = max(result, prefix);
        
        s.insert(prefix);
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        long m = stol(first_multiple_input[1]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<long> a(n);

        for (int i = 0; i < n; i++) {
            long a_item = stol(a_temp[i]);

            a[i] = a_item;
        }

        long result = maximumSum(a, m);

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
