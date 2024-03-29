#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int maxValue = numeric_limits<int>::min();
    vector<vector<int>> sumVector(4, vector<int>(4));
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            sumVector[i-1][j-1] = arr[i][j] + arr[i-1][j-1] + arr[i+1][j+1] + 
                                    arr[i-1][j] + arr[i+1][j] +
                                    arr[i+1][j-1] + arr[i-1][j+1];
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(sumVector[i][j] > maxValue){
                maxValue = sumVector[i][j];
            }
        }
    }
    
    cout << maxValue;
    return maxValue;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
