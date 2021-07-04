#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the sumXor function below.
long sumXor(long n) {
    // When we write sum in terms of xor
    // Sum value is a^b, and carry value is a & b.
    // The values will always be equal for those numbers
    // where carry is 0.
    // So we calculate the number of zeros in n's bit representation.
    long result;
    long value = n;
    int count = 0;
    while(value > 0){
        if(value % 2 == 0){
            // End is 0
            count++;
        }
        value = value / 2;
    }
    result = (long) pow(2,count);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    long result = sumXor(n);

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
