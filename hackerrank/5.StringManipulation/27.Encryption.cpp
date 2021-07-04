#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    string result;
    string s1;
    vector<string> reconstruct;
    // Removing spaces
    for(int i=0; i<s.size(); i++){
        if(s[i] != ' '){
            s1.push_back(s[i]);
        } else if(s[i] == ' '){
            continue;
        }
    }
    int L = s1.size();
    double squareRootL = sqrt(L);
    int floorL = floor(squareRootL);
    int ceilL = ceil(squareRootL);
    
    // Got the max and minimum value of L
    // check calculation
    int row=floorL, col=floorL;
    if(row * col >= L){
        // I choose this
        
        // Construct result
        int index = 0;
        for(int i=0; i<row && index < L; i++){
            string temp;
            for(int j=0; j<col && index < L; j++){
                temp.push_back(s1[index]);
                index++;
            }
            reconstruct.push_back(temp);
        }
        
        for(int i=0; i<col; i++){
            for(int j=0; j<reconstruct.size(); j++){
                if(reconstruct[j].size() - 1 >= i){
                    // Then only we can access reconstruct[j][j]
                    char value = reconstruct[j][i];
                    result.push_back(value);
                } else {
                    continue;
                }
            }
            if(i != col - 1){
                result.push_back(' ');
            } else {
                continue;
            }
        }
        
    } else if(row * col < L){
        row = floorL;
        col = ceilL;
        if(row * col >= L){
            // I choose this
        
            // Construct result
            int index = 0;
            for(int i=0; i<row && index < L; i++){
                string temp;
                for(int j=0; j<col && index < L; j++){
                    temp.push_back(s1[index]);
                    index++;
                }
                reconstruct.push_back(temp);
            }
            
            for(int i=0; i<col; i++){
                for(int j=0; j<reconstruct.size(); j++){
                    if(reconstruct[j].size() - 1 >= i){
                        // Then only we can access reconstruct[j][j]
                        char value = reconstruct[j][i];
                        result.push_back(value);
                    } else {
                        continue;
                    }
                }
                if(i != col - 1){
                    result.push_back(' ');
                } else {
                    continue;
                }
            }
        } else if(row * col < L){
            row = ceilL;
            col = ceilL;
            
            // Construct result
            int index = 0;
            for(int i=0; i<row && index < L; i++){
                string temp;
                for(int j=0; j<col && index < L; j++){
                    temp.push_back(s1[index]);
                    index++;
                }
                reconstruct.push_back(temp);
            }
            
            for(int i=0; i<col; i++){
                for(int j=0; j<reconstruct.size(); j++){
                    if(reconstruct[j].size() - 1 >= i){
                        // Then only we can access reconstruct[j][j]
                        char value = reconstruct[j][i];
                        result.push_back(value);
                    } else {
                        continue;
                    }
                }
                if(i != col - 1){
                    result.push_back(' ');
                } else {
                    continue;
                }
            }
        }
    }
        
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
