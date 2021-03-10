#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    int result = 0;
    vector<int> count1(26, 0);
    vector<int> count2(26, 0);
    for(int i=0; i<s1.size(); i++){
        int val = (int)s1[i] - 97;
        count1[val]++;
    }
    for(int i=0; i<s2.size(); i++){
        int val = (int)s2[i] - 97;
        count2[val]++;
    }
    
    for(int i=0; i<26; i++){
        int diff = abs(count1[i] - count2[i]);
        result = result + diff;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
