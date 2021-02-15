#include <bits/stdc++.h>

using namespace std;

void printArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }    
    cout << endl;
}

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int result = 0;
    sort(arr.begin(), arr.end());
    int minResult = numeric_limits<int>::max();
    for(int i=0; i<arr.size()-k+1; i++){
        int minValue = arr[i];
        int maxValue = arr[i+k-1];
        int diff = maxValue - minValue;
        if(diff < minResult){
            minResult = diff;
        }
    }
    printArray(arr);
    result = minResult;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
