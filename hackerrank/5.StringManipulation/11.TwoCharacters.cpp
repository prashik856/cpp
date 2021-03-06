#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

void printArray(vector<int> count){
    for(int i=0; i<count.size(); i++){
        cout << count[i] << " ";
    }
    cout << endl;
}

void printArrayWithIndex(string s){
    
    for(int i=0; i<s.size(); i++){
        cout << s[i] << "->" << i << " ";
    }    
    cout << endl;
}

// Complete the alternate function below.
int alternate(string s) {
    int result = 0;
    vector<int> count(26,0);
    for(int i=0; i<s.size(); i++){
        int value = (int) s[i] - 97;
        count[value]++;
    }
    
    printArray(count);
    printArrayWithIndex(s);
    
    for(int i=0; i<count.size(); i++){
        for(int j=i+1; j<count.size(); j++){
            int intVal1 = count[i];
            int intVal2 = count[j];
            int countValue = 0;
            if(intVal1 == 0 || intVal2 == 0){
                continue;
            }
            
            int diff = abs(intVal1 - intVal2);
            if(diff > 1){
                // if diff > 1, there can never be alternating characters
                continue;
            }
            
            if(diff <= 1){
                // Possible alternating characters
                char val1 = (char)(97 + i);
                char val2 = (char)(97 + j);
                cout << "Possible Pairs are: " << val1 << " " << val2 << endl;
                cout << "Count values are: " << intVal1 << " " << intVal2 << endl;
                
                // Required Variables
                bool startAlter = false;
                char prevVal;
                char curVal;
                bool loopEnded = false;
                
                
                for(int k=0; k<s.size(); k++){
                    char val = s[k];
                    // If alter has not started
                    if(!startAlter){
                        if(val == val1 || val == val2){
                            cout << "First Character: " << val << endl;
                            cout << "Index: " << k << endl;
                            startAlter = true;
                            prevVal = val;
                            countValue++;
                            cout << "Current Count: " << countValue << endl;
                            continue;
                        }    
                    }
                    
                    // If alter has stared
                    if(startAlter){
                        // Alter has started.
                        if(val == val1 || val == val2){
                            cout << "Possible Alternate: " << val << endl;
                            cout << "Index: " << k << endl;
                            curVal = val;
                            
                            // Not alternating
                            if(curVal == prevVal){
                                break;
                            }
                            
                            // Alternating
                            if(curVal != prevVal){
                                
                                countValue++;
                                prevVal = curVal;
                                cout << "Current Count: " << countValue << endl;
                            }
                        }
                    }
                    
                    // Check if loop has ended
                    if(k == s.size() - 1){
                        loopEnded = true;
                    }
                    
                }
                
                if(loopEnded){
                    cout << "Loop Ended. Calculating result value." << endl;
                    if(countValue > result){
                        result = countValue;
                    }
                }
                cout << endl;
            }
        }
    }
    
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
