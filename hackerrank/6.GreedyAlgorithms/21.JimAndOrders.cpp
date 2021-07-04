#include <bits/stdc++.h>

using namespace std;

// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orders) {
    int n = orders.size();
    vector<int> result;
    vector< vector<int> > totalTime(n, vector<int>(2,0));
    for(int i=0; i<n; i++){
        int orderNumber = orders[i][0];
        int prepTime = orders[i][1];
        int sumValue = orderNumber + prepTime;
        totalTime[i][0] = sumValue;
        totalTime[i][1] = i;
    }
    sort(totalTime.begin(), totalTime.end());
    for(int i=0; i<n; i++){
        int value = totalTime[i][1];
        result.push_back(value + 1);
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> orders[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = jimOrders(orders);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
