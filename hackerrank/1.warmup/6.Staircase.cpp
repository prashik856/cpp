#include <bits/stdc++.h>

using namespace std;

// Complete the staircase function below.
void staircase(int n) {
    int count = 1;
    int spaces = n-1;
    while(count <= n){
        for(int i=0; i<spaces; i++){
            cout << " ";
        }
        for(int i=0; i<count; i++){
            cout << "#";
        }
        count++;
        spaces--;
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
