#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */
 
double getMedian(vector<int> count, int n,  bool even=false){
    double median = 0;
    if(even){
        int pos1 = n/2 - 1;
        int pos2 = n/2;
        double result1 = 0;
        double result2 = 0;
        bool pos1Set = false;
        bool pos2Set = false;
        int currentSum1 = 0;
        int currentSum2 = 0;
        for(int i=0; i<count.size(); i++){
            if(count[i] <= 0){
                continue;
            }
            
            // else
            int value = count[i];
            // for pos1
            if(currentSum1 + value <= pos1){
                currentSum1 = currentSum1 + value;
            } else {
                // if pos1 is not set
                if(!pos1Set) {
                    //cout << "Position 1 set with value: " << i << endl; 
                    result1 = (double) i;
                    pos1Set = true;
                }
            }
            
            if(currentSum2 + value <= pos2){
                currentSum2 = currentSum2 + value; 
            } else {
                if(!pos2Set){
                    //cout << "Position 2 set with value: " << i << endl;
                    result2 = (double) i;
                    pos2Set = true;
                }
            }
            
            if(pos2Set && pos1Set){
                break;
            }
        }
        median = (result1 + result2)/2;
    } else {
        // not even
        int pos = n/2;
        int currentSum = 0;
        for(int i=0; i<count.size(); i++){
            // if count is zero, continue
            if(count[i]<=0){
                continue;
            }
            
            // else
            int value = count[i];
            if(currentSum + value <= pos){
                currentSum = currentSum + value;
            } else {
                // we get currentSum + value >= pos
                // Got our median
                median = (double) i;
                break;
            }
        }
    }
    
    return median;
}

int activityNotifications(vector<int> expenditure, int d) {
    int result = 0;
    int n = expenditure.size();
    // Initialize array
    vector<int> count(201,0);
    int front = d-1;
    int back = 0;
    // Start count
    for(int i=back; i<=front; i++){
        int value = expenditure[i];
        count[value]++;
    }
    
    // even
    if(d%2 == 0){
       for(int i=d; i<n; i++){
           int cost = expenditure[i];
            //cout << "Current Cost: " << cost << endl;
            double median = getMedian(count, d, true);
            //cout << "Median Obtained: " << median << endl;
            if(cost >= 2*median){
                result++;
            }
            // remove back
            count[expenditure[back]]--;
            // increment back
            back++;
            // increment front
            front++;
            // add front
            count[expenditure[front]]++;
            cout << endl;
       }
    } else {
        for(int i=d; i<n; i++){
            int cost = expenditure[i];
            //cout << "Current Cost: " << cost << endl;
            double median = getMedian(count, d);
            //cout << "Median Obtained: " << median << endl;
            if(cost >= 2*median){
                result++;
            }
            // remove back
            count[expenditure[back]]--;
            // increment back
            back++;
            // increment front
            front++;
            // add front
            count[expenditure[front]]++;
            cout << endl;
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
