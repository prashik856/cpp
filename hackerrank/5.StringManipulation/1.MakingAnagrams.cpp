#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int anagram = 0;
    vector<int> count1(26,0);
    vector<int> count2(26,0);
    for(int i=0; i<a.size(); i++){
        int val = (int) a[i];
        int index = val - 97;
        count1[index]++;
    }
    for(int i=0; i<b.size(); i++){
        int val = (int) b[i];
        int index = val - 97;
        count2[index]++;
    }
    for(int i=0; i<count1.size(); i++){
        int diff = count1[i] - count2[i];
        anagram = anagram + abs(diff);
    }
    
    return anagram;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
