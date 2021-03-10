#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    int result = 0;
    int n = s.size();
    if(n%2==1){
        return -1;
    }
    string s1,s2;
    int mid = n/2;
    for(int i=0; i<mid; i++){
        s1.push_back(s[i]);
    }
    for(int i=mid; i<n; i++){
        s2.push_back(s[i]);
    }
    
    // Got our two substrings
    // sort them
    vector<int> count1(26,0);
    vector<int> count2(26,0);
    for(int i=0; i<s1.size(); i++){
        int val1 = (int) s1[i] - 97;
        int val2 = (int) s2[i] - 97;
        count1[val1]++;
        count2[val2]++;
    }
    
    for(int i=0; i<26; i++){
        int diff = abs(count1[i] - count2[i]);
        result = result + diff;
    }
    
    return result/2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
