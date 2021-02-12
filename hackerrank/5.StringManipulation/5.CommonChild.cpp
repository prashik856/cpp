// wiki link: https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
// Length of Longest Common subsequence
// For LCS, follow the above
#include <bits/stdc++.h>

using namespace std;

void printArray(vector< vector<int>> arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int result = 0;
    vector< vector<int> > arr(s1.size()+1);
    for(int i=0; i<arr.size(); i++){
        arr[i] = vector<int>(s1.size()+1);
    }

    //printArray(arr); 
    
    // Fill the table
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            // Comparing empty string
            if(i==0 || j==0){
                arr[i][j] = 0;
            }
            else {
                if(s1[i-1] == s2[j-1]){
                    arr[i][j] = arr[i-1][j-1] + 1;
                } else{
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
                }
            }
        }
    }
    
    result = arr[arr.size()-1][arr.size()-1];
       
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
