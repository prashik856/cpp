#include <bits/stdc++.h>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {
    int result = 0;
    int maxValue = numeric_limits<int>::min();
    for(int i=l; i<=r; i++){
        for(int j=i+1; j<=r; j++){
            int val1 = i;
            int val2 = j;
            int value = val1 ^ val2;
            if(value > maxValue){
                maxValue = value;
            }
        }
    }
    result = maxValue;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int l;
    cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int r;
    cin >> r;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = maximizingXor(l, r);

    fout << result << "\n";

    fout.close();

    return 0;
}
