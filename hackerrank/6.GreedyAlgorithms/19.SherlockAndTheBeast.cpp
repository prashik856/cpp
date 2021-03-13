#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the decentNumber function below.
void decentNumber(int n) {
    string result;
    // Given n, I want this
    // 5 * x + 3 * y = n; s.t. x % 3 == 0 && y%5 == 0;
    if(n<3){
        cout << -1 << endl;
    }
    
    else if(n%3 == 0){
        // Divisible by 3, just all 5s
        for(int i=0; i<n; i++){
            result.push_back('5');
        }
        cout << result << endl;
    }
    
    else{
        int y = 0;
        int x = n;
        bool found = false;
        while(x>=0 && !found){
            if(x%3 == 0 && y%5 == 0){
                found = true;
                break;
            }
            else{
                x--;
                y++;
            }
        }
        if(!found){
            cout << -1 << endl;
        } else {
            for(int i=0; i<x; i++){
                result.push_back('5');
            }
            for(int i=0; i<y; i++){
                result.push_back('3');
            }
            cout << result << endl;
        }
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        decentNumber(n);
    }

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
