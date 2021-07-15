// Problem: https://www.hackerrank.com/challenges/ctci-big-o/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=miscellaneous
// Intuition: Upper bound of prime test. Just loop till it.
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'primality' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

string primality(int n) {
    int upperBound = ceil(sqrt(n));
    
    // base test
    if(n == 1){
        return "Not prime";
    }
    
    // base test
    if(n == 2){
        return "Prime";
    }
    
    // base test
    if(n == 3){
        return "Prime";
    }
    
    // Divisible by 2
    if(n % 2 == 0){
        return "Not prime";
    }
    
    // Divisible by 3
    if(n % 3 == 0){
        return "Not prime";
    }
    
    for(int i=4; i<=upperBound; i++){
        if(n % i == 0){
            return "Not prime";
        }
    }
    
    return "Prime";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    for (int p_itr = 0; p_itr < p; p_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string result = primality(n);

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
