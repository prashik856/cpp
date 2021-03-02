#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {
    vector<int> result;
    set<int> s;
    vector< vector<int> > dp(n, vector<int>(n, 0));
    
    // Create our matrix
    for(int i=0; i<dp.size(); i++){
        for(int j=0; j<dp[i].size(); j++){
            
            int val = i*b + j*a;
            
            if(i+j > n-1){
                break;
            }
            
            if(i+j<=n-1){
                dp[i][j] = val;
            }
            
            if(i+j == n-1){
                // Add to set
                s.insert(val);
            }
        }
    }

    set<int>::iterator itr;
    for(itr = s.begin(); itr!=s.end(); itr++){
        result.push_back(*itr);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
