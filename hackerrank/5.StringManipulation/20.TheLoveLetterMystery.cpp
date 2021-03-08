#include <bits/stdc++.h>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {
    int result = 0;
    int n = s.size();
    if(n == 1){
        return result;;
    }
    if(n%2 == 1){
        // Odd
        int mid = s.size()/2;
        int left = mid - 1;
        int right = mid + 1;
        while(left >= 0){
            int diff = abs((int)s[left] - (int)s[right]);
            result = result + diff;
            left--;
            right++;
        }
    } else{
        int right = s.size()/2;
        int left = (s.size()-1)/2;
        while(left>=0){
            int diff = abs((int)s[left] - (int)s[right]);
            result = result + diff;
            left--;
            right++;
        }
    }
    return result;
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

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
