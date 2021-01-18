#include <bits/stdc++.h>

using namespace std;

int getAllSubstrings(string s){
    int noOfAnagrams = 0;
    int lengthOfString = s.length();
    vector<string> allSubstrings;
    for(int k=1; k<=lengthOfString; k++){
        int currentLength = k;
        vector<string> currentLengthSubstrings;
        vector< unordered_map<char, int> > substringHash;
        
        for(int i=0; i<lengthOfString; i++){
            // Actual substring
            string currentSubstring;
            // Hash of substring
            unordered_map<char, int> currentSubstringHash;
            
            if(i + currentLength <= lengthOfString ){
                for(int j=0; j<currentLength; j++){
                    // Substring starts from i,
                    int currentHashValue = currentSubstringHash[s[i+j]];
                    if(currentHashValue == 0){
                        currentSubstringHash[s[i+j]] = 1;
                    } else {
                        currentSubstringHash[s[i+j]] = currentHashValue + 1;
                    }
                    currentSubstring.push_back(s[i+j]); 
                }
            // Store the current lenght hash value.
            currentLengthSubstrings.push_back(currentSubstring);
            substringHash.push_back(currentSubstringHash);
            }
        }
        
        // We got all hash values for current length
        int allCurrentLengthSubstrings = currentLengthSubstrings.size();
        for(int i=0; i<allCurrentLengthSubstrings - 1; i++){
            string currentSubstring = currentLengthSubstrings[i];
            //cout << "Current Substring: " << currentSubstring << endl;
            
            for(int j=i+1; j<allCurrentLengthSubstrings; j++){
                // We need to compare hashvalues of currentSubstring and comparingSubstring.
                int count = 0;
                //cout << "Comparing Substring: " << currentLengthSubstrings[j] << endl;
                int sizeOfCurrentSubstring = currentSubstring.length();
                
                for(int l=0; l<sizeOfCurrentSubstring; l++){
                    char currentCharacter = currentSubstring[l];
                    if(substringHash[i][currentCharacter] == substringHash[j][currentCharacter]){
                        // has equal number of x characters 
                        count++;
                    }
                    else{
                        // does not have eaual numbre of characters
                        break;
                    }
                }
                
                if(count == sizeOfCurrentSubstring){
                    noOfAnagrams++;
                }
                // End of comparing string loop.
            }
            
            //cout << endl;
        }
    }
    cout << noOfAnagrams << endl;
    return noOfAnagrams;
}

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int noOfAnagrams = getAllSubstrings(s);
    
    return noOfAnagrams;
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
