#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    cout << "Input: " << s << endl;
    cout << "Length: " << s.size() << endl;
    int result = -1;
    int i=0;
    int j=s.size() - 1;
    bool indexSkipped = false;
    bool isPhalindrome = false;
    int index = 0;
    int possibleIndexi = 0;
    int possibleIndexj = 0; 
    bool bothPossible = false;
    while(i<j){
        cout << "i: " << i << " | j: " << j << endl;
        char front = s[i];
        char back = s[j];
        cout << "front: " << front << endl;
        cout << "Back: " << back << endl;
        if(front == back){
            // cool cool
            i++;
            j--;
            cout << endl;
            if(i>=j){
                isPhalindrome = true;
            }
            continue;
        }
        
        if(front != back){
            // Problem
            cout << "Problem" << endl;
            if(!indexSkipped){
                cout << "Index not skipped" << endl;
                // if index is not skipped
                // which index to skip?
                // if j - i == 1
                //  skip anyone
                if((j - i) == 1){
                    index = j;
                    cout << "Skipping index: " << j << endl;
                    // will be a phalindrome
                    isPhalindrome = true;
                    indexSkipped = true;
                    break;
                }
                
                if(s[i+1] == s[j] && s[i] == s[j-1]){
                    // Both combinations are possible
                    possibleIndexi = i;
                    possibleIndexj = j;
                    bothPossible = true;  
                    
                    // Skip i first
                    index = i;
                    i++;
                    cout << "Both index possible" << endl;
                }
                
                else if(s[i+1] == s[j] && s[i] != s[j-1]){
                    // skip i
                    index = i;
                    cout << "Skipping index: " << i << endl;
                    i++;
                }
                else if(s[i] == s[j-1] && s[i+1] != s[j]){
                    // skip j
                    index = j;
                    cout << "Skipping index: " << j << endl;
                    j--;
                }
                indexSkipped = true;
            } 
            // Index is already skipped 
            // so not a phalindrome
            else if(indexSkipped){
                if(!bothPossible){
                    cout << "Index already skipped and both are not possible" << endl;
                    // if index is skipped
                    isPhalindrome = false;
                    break;    
                }
                
                else if(bothPossible){
                    cout << "Index already skipped but both are possible." << endl;
                    i = possibleIndexi;
                    j= possibleIndexj;
                    // skip j now;
                    index = j;
                    j--;
                    bothPossible = false;
                }
            }
            
            i++;
            j--;
            if(i>=j){
                isPhalindrome = true;
            }
        }
        cout << endl;
    }
    
    if(!isPhalindrome){
        // if string is not phalindrome
        result = -1;
    } 
        // If result is a phalindrome and index was skipped
    else if(isPhalindrome && indexSkipped){
        result = index;
    } 
        // If result is phalindrome and index was not skipped
    else if(isPhalindrome && !indexSkipped){
        result = -1;
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

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
