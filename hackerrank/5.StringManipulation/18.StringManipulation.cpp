#include <bits/stdc++.h>

using namespace std;

void printArray(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    int result = 0;
    
    // Count vector
    vector< vector<int> > count(arr.size(), vector<int>(26, 0));
    
    for(int i=0; i<arr.size(); i++){
        string s = arr[i];
        for(int j=0; j<s.size(); j++){
            int value = (int)s[j] - 97;
            count[i][value]++;
        }
    }
    
    //printArray(count);
    
    // Go through all qualities
    for(int j=0; j<26; j++){
        int val = 0;
        
        // Check for all stones
        for(int i=0; i<arr.size(); i++){
            if(count[i][j] == 0){
                break;
            }
            // If the stone has it, increase value of val
            val++;
        }
        
        if(val == arr.size()){
            result++;
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

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
