/*
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4
*/
/*
Yeah, this worked.

> Find the two versions first
> Strip the leading zeros.
> compare size 
> if equal size, do string compare.

*/
#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b){
    int result = 0;
    bool found = false;
    int n = a.size();
    int m = b.size();
    int i=0; 
    int j=0;
    while(!found){
        string v1;
        string v2;

        int v1Size = 0;
        int v2Size = 0;

        // Create v1
        for(; i<n; i++){
            if(a[i] != '.'){
                v1.push_back(a[i]);
            } else if(a[i] == '.'){
                i++;
                break;
            }
        }

        // Create v2
        for(; j<m; j++){
            if(b[j] != '.'){
                v2.push_back(b[j]);
            } else if(b[j] == '.'){
                j++;
                break;
            }
        }

        // If size 0, break
        if(v1.size() == 0 && v2.size() == 0){
            break;
        }

        // remove leading zeros
        if(v1.size() > 0){
            v1.erase(0, v1.find_first_not_of('0'));
        }
        if(v2.size() > 0){
            v2.erase(0, v2.find_first_not_of('0'));
        }

        // if compare only if size of both strings is equal
        int x=0;
        if(v1.size() == v2.size()){
            x = v1.compare(v2);
        } else if(v1.size() > v2.size()){
            // if v1 is greater
            return 1;
        } else if(v2.size() > v1.size()){
            // if v2 is greater
            return -1;
        }

        // if both equal
        if(x == 0){
            continue;
        } else if(x > 0){
            return 1;
        } else if(x < 0){
            return -1;
        }
    }

    return result;
}

int main(){
    string a = "00001.13.1";
    string b = "1.13.4";
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}