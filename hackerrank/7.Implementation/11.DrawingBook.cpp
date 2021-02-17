#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    int result = 0;
    // Given n, first get the last page
    // 0 1 | 2 3 | 
    // If n % 2 == 0, then last page on left, else on right.
    int currentPage = 1;
    int lastPage = n;
    bool foundPage = false;
    int fromFront = 0;
    int fromBack = 0;
    if(n%2 == 0){
        // from front
        if(p == currentPage){
            foundPage = true;
        }
        
        while(!foundPage){
            fromFront++;
            currentPage = currentPage + 2;
            if(p<=currentPage){
                foundPage = true;
                break;
            }
        }
        
        // From back
        foundPage = false;
        currentPage = n;
        if(p == currentPage){
            foundPage = true;
        }
        
        while(!foundPage){
            fromBack++;
            currentPage = currentPage - 2;
            if(p>=currentPage){
                foundPage = true;
                break;
            }
        }
        
        // Check which is minimum
        if(fromFront < fromBack){
            result = fromFront;
        } else {
            result = fromBack;
        }
    } else {
        // In this case, the last page on right side.
        // From front
        if(p == currentPage){
            foundPage = true;
        }
        
        while(!foundPage){
            fromFront++;
            currentPage = currentPage + 2;
            if(p<=currentPage){
                foundPage=true;
                break;
            }
        }
        
        // From back
        foundPage = false;
        currentPage = n;
        currentPage--;
        if(p>=currentPage){
            foundPage = true;
        }
        while(!foundPage){
            fromBack++;
            currentPage = currentPage -2;
            if(p>=currentPage){
                foundPage = true;
                break;
            }
        }
        
        if(fromFront < fromBack){
            result = fromFront;
        } else {
            result = fromBack;
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

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
