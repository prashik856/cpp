/*
Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists of elements where the number
of elements and the number of possible key values are approximately the same.
It requires O(n + Range) time where n is number of elements in input array and ‘Range’ is number of possible values in array. 

Working of Algorithm : 
1. Find minimum and maximum values in array. 
Let the minimum and maximum values be ‘min’ and ‘max’ respectively. 
Also find range as ‘max-min+1’. 
2. Set up an array of initially empty “pigeonholes” the same size as of the range.
Visit each element of the array and then put each element in its pigeonhole. 
An element arr[i] is put in hole at index arr[i] – min.
Start the loop all over the pigeonhole array in order and put the elements from non-empty holes back into the original array.

Comparison with Counting Sort : 
It is similar to counting sort, but differs in that it “moves items twice: once to the bucket array and again to the final destination “.

*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> pegionHoleSort(vector<int> arr) {
    vector<int> result;
    int maxValue=numeric_limits<int>::min(), minValue=numeric_limits<int>::max();
    int range;
    for(int i=0; i<arr.size(); i++) {
        maxValue = max(maxValue, arr[i]);
        minValue = min(minValue, arr[i]);
    }

    range = maxValue - minValue + 1;

    cout << "Max value is: " << maxValue << endl;
    cout << "Min value if: " << minValue << endl;
    cout << "Range value is: " << range << endl;

    vector<int> rangeArray(range, 0);

    for(int i=0; i<arr.size(); i++) {
        int value = arr[i];
        int indexValue = value - minValue;

        rangeArray[indexValue]++;
    }

    // put values back 
    for(int i=0; i<rangeArray.size(); i++) {
        if(rangeArray[i] == 0) {
            continue;
        } else {
            int value = minValue + i;
            int count = rangeArray[i];
            while(count > 0){
                result.push_back(value);
                count--;
            }
        }
    }

    return result;
}

int main(){
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        vector<int> result = pegionHoleSort(arr);
        cout << "Result: " << endl;
        printVector(result);
        cout << endl;
    }

    return 0;
}