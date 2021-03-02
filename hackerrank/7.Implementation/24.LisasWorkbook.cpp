#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the workbook function below.
int workbook(int n, int k, vector<int> arr) {
    int result=0;
    int currentPage=1;
    for(int i=0; i<n; i++){
        //cout << "Current Chapter: " << i+1 << endl;
        int problems = arr[i];
        
        // We start from page1
        int fullPage=0;
        int remain = 0;
        for(int j=0; j<problems; j++){
            int currentProblem = j+1;
            // cout << "Current Problem: " << currentProblem << endl;
            // cout << "Current Page: " << currentPage << endl;
            // See where currentProblem belongs
            fullPage = currentProblem/k;
            remain = currentProblem % k;
            if(fullPage == 0){
                // We are on the same page
                //cout << "Checking in Page: " << currentPage << endl;
                if(currentProblem == currentPage){
                    result++;
                }
            } else if(fullPage > 0 && remain == 0){
                //cout << "Checking in Page: " << currentPage + fullPage - 1 << endl;
                if(currentProblem == currentPage + fullPage - 1){
                    result++;
                }
            } 
            else if(fullPage > 0 && remain != 0){
                // We are on currentProblem + fullPage
                //cout << "Checking in Page: " << currentPage + fullPage << endl;
                if(currentProblem == currentPage + fullPage){
                    result++;
                }
            }
            //cout << endl;
        }
        if(remain !=0){
            currentPage = currentPage + fullPage + 1;    
        }
        else{
            currentPage = currentPage + fullPage;
        }
        //cout << endl << endl;
    }    
    
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = workbook(n, k, arr);

    fout << result << "\n";

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
