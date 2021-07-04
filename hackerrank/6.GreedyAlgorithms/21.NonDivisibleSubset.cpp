#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

int nonDivisibleSubset(int k, vector<int> s) {
    int result = 0;
    vector< vector<int> > remainders(k, vector<int>());
    
    for(int i=0; i<s.size(); i++){
        int value = s[i] % k;
        remainders[value].push_back(s[i]);
    }
    
    // I want to find couple values where their sum is not divisible by k
    // for(int i=0; i<k; i++){
    //     cout << "For remainder: " << i << endl;
    //     for(int j=0; j<remainders[i].size(); j++){
    //         cout << remainders[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    // let's add remainder 0 values
    if(remainders[0].size() > 0){
        result++;
    }
    
    for(int i=1, j=k-1; i<=j; i++, j--){
    //    cout << "Checking: " << i << " | " << j << endl;
        
        if(i!=j){
            int iSize = remainders[i].size();
            int jSize = remainders[j].size();
            cout << iSize << " | " << jSize << endl;
            if(iSize > jSize){
                result = result + iSize;
            } else {
                    result = result + jSize;
            }    
        } else if(i==j){
            int iSize = remainders[i].size();
            if(iSize>0){
                result++;
            }
        }
        
    }
    
    
    // if(result == 1){
    //     // we need pairs
    //     return 0;
    // }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

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
