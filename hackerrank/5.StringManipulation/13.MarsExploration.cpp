#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int result=0; 
    string sos = "SOS";
    int index = 0;
    for(int i=0; i<s.size(); i++){
        char value = s[i];
        if(s[i] != sos[index]){
            result++;
        }
        index++;
        if(index >= 3){
            index = index % 3;
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
