#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A){
A.push_back(-1);

    long currentSum = 0;
    long currentLenght = 0;
    int startingIndex = 0;
    int endingIndex = 0;


    vector<int> result;
    long maxSum = 0;
    long maxLength = 0;
    int resultStartingIndex = 1000000;
    int resultEndingIndex = 1000000;

    for(int i=0; i<A.size(); i++){
        if(A[i] < 0){
            // set ending index
            endingIndex = i;

            // We need to break our subarray here
            if(maxSum < currentSum) {
                // update indices
                resultStartingIndex = startingIndex;
                resultEndingIndex = endingIndex;
                maxSum = currentSum;
                maxLength = currentLenght;
            }

            else if(maxSum == currentSum) {
                if(currentLenght > maxLength) {
                    // set our result parameters
                    maxLength = currentLenght;
                    resultStartingIndex = startingIndex;
                    resultEndingIndex = endingIndex;
                }
            }

            currentSum = 0;
            currentLenght = 0;
        }

        else {
            // starting index
            if(currentLenght == 0){
                startingIndex = i;
            }

            currentLenght++;
            currentSum = currentSum + A[i];
        }
    }

    // Create result array
    if(resultStartingIndex == 1000000){
        return result;
    }

    for(int i=resultStartingIndex; i<resultEndingIndex; i++){
        result.push_back(A[i]);
    }

    return result;
}

int main(){
    int t;
    cin >> t;
    for(int z=0; z<t; z++){
        cout << "Case: " << z << endl;
        int n;
        cin >> n;
        vector<int> arr;
        cout << "Given array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl << endl;

        vector<int> result = solve(arr);
        cout << "Result Obtained is: " << endl;
        for(int i=0; i<result.size(); i++){
            cout << result[i] << " ";
        }
        cout << endl << endl;
    }

}