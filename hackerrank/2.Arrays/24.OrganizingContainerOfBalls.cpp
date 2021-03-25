#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    vector<int> typeSum(n,0);
    unordered_map<int, int> containerSum;
    for(int i=0; i<n; i++){
        int sumValue = 0;
        for(int j=0; j<n; j++){
            int value = container[i][j];
            sumValue = sumValue + value;
        }
        int value = containerSum[sumValue];
        if(value == 0){
            containerSum[sumValue] = 1;
        } else {
            containerSum[sumValue] = value + 1;
        }
        //cout << "Container: " << i << " | Balls: " << sumValue << endl;
    }
    
    for(int j=0; j<n; j++){
        int sumValue = 0;
        for(int i=0; i<n; i++){
            int value = container[i][j];
            sumValue = sumValue + value;
        }
        typeSum[j] = sumValue;
        //cout << "Type: " << j << " | Sum: " << sumValue << endl;
        int value = containerSum[sumValue];
        if(value == 0){
            // Impossible
            return "Impossible";
        }
        else {
            containerSum[sumValue] = value - 1;
        }
    }
    
    //cout << endl;
    
    return "Possible";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
