#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    string result;
    if(k==0){
        return s;
    }
    for(int i=0; i<s.size(); i++){
        char cVal = s[i];
        if(cVal >= 'a' && cVal <= 'z'){
            int val = (int)s[i] - 97;
            val = val + k;
            if(val >= 26){
                val = val % 26;
            }
            cVal = (char) 97 + val;
            result.push_back(cVal);
        } else if(cVal >= 'A' && cVal <='Z') {
            int val = (int)s[i] - 65;
            cout << "Value in int: " << val << endl;
            val = val + k;
            cout << "Value after adding: " << val << endl;
            if(val >= 26){
                val = val % 26;
            }
            cout << "Value after moduling: " << val << endl;
            val = val + 65;
            cVal = (char) val;
            cout << "Value after adding: " << val << endl;
            cout << "Char value after moduling: " << cVal << endl;
            result.push_back(cVal);
        } else{
            result.push_back(cVal);
        }
        
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
