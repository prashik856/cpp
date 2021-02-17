#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {
    int result = 0;
    int currentHeight = 1;
    int currentPeriod = 1;
    while(n>0){
        if(currentPeriod % 2 == 0){
            // Summer
            currentHeight++;
            currentPeriod++;
        } else {
            // Spring
            currentHeight = currentHeight * 2;
            currentPeriod++;
        }
        n--;
    }
    result = currentHeight;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = utopianTree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
