//http://www.nayuki.io/page/next-lexicographical-permutation-algorithm
#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
// Finding longest non-increasing sequence
    //cout << "Input: " << w << endl;
    int pivot = -1;
    int n = w.size();
    
    for(int i=n-1; i>0; i--){
        if(w[i] > w[i-1]){
            // Found the pivot
            // pivot is i
            pivot = i - 1;
            break;
        }
    }
    
    if(pivot == -1){
        return "no answer";
    }
    //cout << "Pivot: " << pivot << " | Value: " << w[pivot] << endl;

    // Find Rightmost successor to pivot
    int successor = n-1;
    for(int i=pivot+1; i<n; i++){
        if(w[pivot] >= w[i]){
            successor = i-1;
            break;
        }
    }
    //cout << "Successor: " << successor << " | Value: " << w[successor] << endl;

    // Swap successor and pivot
    char temp = w[pivot];
    w[pivot] = w[successor];
    w[successor] = temp;
    //cout << "String after swapping pivot and rightmost successor: " << w << endl;

    // Reverse the suffix
    string reverseSuffix;
    for(int i=pivot+1; i<n; i++){
        reverseSuffix.push_back(w[i]);
    }
    int index = pivot + 1;
    for(int i=reverseSuffix.size()-1; i>=0; i--){
        w[index] = reverseSuffix[i];
        index++;
    }

    //cout << "String after reversing the suffix: " << w << endl;

    //cout << endl;
    return w;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
