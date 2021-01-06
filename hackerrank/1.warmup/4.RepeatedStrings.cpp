#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
long count = 0;
long aCount = 0;
long len = s.size();
// Get the count of a in substring.
for(int i=0; i<len; i++){
    if(s[i] == 'a'){
        aCount++;
    }
}

// Now, we got count of a, what is the size of our string
long repeatition = n/len;
count = count + aCount*repeatition;

// Get the remaining string size
long remainingStringLength = n%len;
for(int i=0; i<remainingStringLength; i++){
    if(s[i]=='a'){
        count++;
    }
}

return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
