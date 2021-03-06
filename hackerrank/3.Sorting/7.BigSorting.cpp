#include <bits/stdc++.h>

using namespace std;

int getMinimum(string a, string b){
    int lenA = a.size();
    if(a.size() < b.size()){
        return 1;
    } else if(b.size() < a.size()){
        return 2;
    }
    else{
        // Both of their lenght is same
        for(int i=0; i<lenA; i++){
            int val1 = (int)a[i];
            int val2 = (int)b[i];
            if(val1 < val2){
                return 1;
            } else if(val2 < val1){
                return 2;
            }
            else if(val1 == val2){
                continue;
            }
        }
    }
    // Values are equal
    return 1;
}

void merge(vector<string> &unsorted, int start, int mid, int end){
    vector<string> sortedArray(end - start + 1);
    int index=0;
    int i,j;
    
    for(i=start, j=mid+1; i<=mid && j<=end; ){
        string a = unsorted[i];
        string b = unsorted[j];
        int minValue = getMinimum(a, b);
        if(minValue == 1){
            sortedArray[index] = a;
            i++;
            index++;
        } else if(minValue == 2){
            sortedArray[index]= b;
            j++;
            index++;
        }
    }
    
    while(i<=mid){
        string a = unsorted[i];
        sortedArray[index]= a;
        index++;
        i++;
    }
    
    while(j<=end){
        string a = unsorted[j];
        sortedArray[index]= a;
        index++;
        j++;
    }
    
    int index2 = 0;
    for(int i=start; i<=end; i++){
        unsorted[i] = sortedArray[index2];
        index2++;
    }
}

void mergeSort(vector<string> &unsorted, int start, int end){
    if(start >= end){
        return;
    }
    int mid = (start + end)/2;
    mergeSort(unsorted, start, mid);
    mergeSort(unsorted, mid+1, end);
    merge(unsorted, start, mid, end);
}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {
    int lenArr = unsorted.size();
    mergeSort(unsorted, 0, lenArr - 1);
    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
