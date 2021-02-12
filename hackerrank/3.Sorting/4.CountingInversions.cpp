#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
void printArray(vector<int> &arr){
    int sizeOfArray = arr.size();
    for(int i=0; i<sizeOfArray; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeArrays(vector<int> &arr, int start, int mid, int end, long *requiredCounts){
    int i, j;
    vector<int> sortedArray;
    // Merge sorted arrays
    for(i=start, j=mid+1; i<=mid && j<=end; ){
        if(arr[i] > arr[j]){
            long inversions = mid - i + 1;
            *requiredCounts = *requiredCounts + inversions;
            sortedArray.push_back(arr[j]);
            j++;
        }
        else{
            sortedArray.push_back(arr[i]);
            i++;
        }
    }
    
    // put all elements from 1st sub array
    while(i<=mid){
        sortedArray.push_back(arr[i]);
        i++;
    }
    
    // Put all elements from 2nd sub array
    while(j<=end){
        sortedArray.push_back(arr[j]);
        j++;
    }
    
    // Put back sortedArray to arr
    int index = 0;
    for(i=start; i<=end; i++){
        arr[i] = sortedArray[index];
        index++;
    }
}

void mergeSort(vector<int> &arr, int start, int end, long *requiredCounts){
    // Exit condition
    if(end <= start){
        return;
    }
    // Calculate mid
    int mid = (start + end)/2;
    mergeSort(arr, start, mid, requiredCounts);
    mergeSort(arr, mid + 1, end, requiredCounts);
    
    mergeArrays(arr, start, mid, end, requiredCounts);
    
}

// Complete the countInversions function below.
long countInversions(vector<int> arr) {
    // We implement merge sort for this bitch
    // cout << "Before sort: " << endl;
    // printArray(arr);
    // cout << endl;
    long requiredCounts = 0;
    long *ptr = &requiredCounts;
    int start = 0;
    int end = arr.size() - 1;
    mergeSort(arr, start, end, ptr);
    // cout << "After sort: " << endl;
    // printArray(arr);
    // cout << endl;
    
    return requiredCounts;
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

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long result = countInversions(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
