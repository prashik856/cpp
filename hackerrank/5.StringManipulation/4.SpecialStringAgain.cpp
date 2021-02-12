#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long count = n;
    int i=0;
    while(i<n){
        char cc = s[i];
        long repeat = 0;
        int pointer = 1;
        
        // check for repeat
        while(i+1<n){
            if(cc == s[i+1]){
                repeat++;
                i++;
            } else{
                break;
            }
        }
        
        // Repeat check finished
        count = count + ((repeat * (repeat+1))/2);
        
        // Check for special substring
        while((i+pointer) < n && (i-pointer) >=0 ){
            if(pointer == 1){
                if(s[i+pointer] == s[i-pointer]){
                    count++;
                    pointer++;
                } else{
                    break;
                }
            } else if(pointer > 1) {
                if(s[i+pointer] == s[i-pointer] && 
                   s[i+pointer] == s[i+pointer-1] &&
                   s[i-pointer] == s[i-pointer+1]){
                    count++;
                    pointer++;
                } 
                else{
                    break;
                }
            }
            
        }
        i++;
    }    
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
