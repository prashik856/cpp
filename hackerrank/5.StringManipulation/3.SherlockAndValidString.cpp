#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector<int> count(26,0);
    for(int i=0; i<s.size(); i++){
        int val = (int) s[i];
        int index = val - 97;
        count[index]++;
    }
    
    // We can only subtract values
    vector< vector<int> > diffValues(count.size());
    
    int index = 0;
    for(int i=0; i<count.size(); i++){
        int val = count[i];
        int freq = 0;
        if(val == 0){
            continue;
        } else if(val > 0){
            // Check if val is already calculated.
            bool valuePresent = false;
            for(int j=0; j<index; j++){
                int diffVal = diffValues[j][0];
                if(val == diffVal){
                    // Value already present
                    valuePresent = true;
                    break;
                }
            }
            
            if(!valuePresent){
                for(int j=i; j<count.size(); j++){
                    if(count[j] == val){
                        freq++;
                    }
                }
                diffValues[index] = vector<int>();
                diffValues[index].push_back(val);
                diffValues[index].push_back(freq);  
                index++; 
            }
        }
    }
    
    // for(int i=0; i<index; i++){
    //     cout << "Value: " << diffValues[i][0] << endl;
    //     cout << "Freq: " << diffValues[i][1] << endl;;
    // }
    // cout << endl;
    
    if(index > 2){
        return "NO";
    }
    
    if(index == 1){
        return "YES";
    }
    bool freq1Bool = false;
    bool freq2Bool = false;
    int freq1 = diffValues[0][1];
    int freq2 = diffValues[1][1];
    int val1 = diffValues[0][0];
    int val2 = diffValues[1][0];
    cout << "Value1 " << val1 << endl;
    cout << "Freq1 " << freq1 << endl;
    cout << "Value2: " << val2 << endl;
    cout << "Freq2 " << freq2 << endl;
    if(freq1 == 1){
        val1--;
        // After decreasing, if 
        if(val1 == val2 || val1 == 0){
            return "YES";
        }
    } else if(freq2 == 1){
        val2--;
        if(val1 == val2 || val2 == 0){
            return "YES";
        }
    }
    
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
