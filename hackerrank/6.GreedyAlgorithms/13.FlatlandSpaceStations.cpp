#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    int result = -1;
    sort(c.begin(), c.end());
    stack<int> front;
    stack<int> back;
    
    // Push every station in c
    for(int i=c.size() - 1; i>=0; i--){
        front.push(c[i]);
    }
    
    for(int i=0; i<n; i++){
        int value = i;
        int nearestRight=-1;
        int nearestLeft=-1; 
        
        // Get the nearest stations
        if(!front.empty()){
            nearestRight = front.top();
        }
        if(!back.empty()){
            nearestLeft = back.top();
        }
        
        int minRight = 1000000;
        int minLeft = 1000000;
        // Minimum distance from right
        if(nearestRight != -1){
            // Station exists in right
            int diff = abs(nearestRight - value);
            if(diff < minRight){
                minRight = diff;
            }
        }
        
        // Minimum distance from left
        if(nearestLeft != -1){
            // Station exists in left
            int diff = abs(value - nearestLeft);
            if(diff < minLeft){
                minLeft = diff;
            }
        }
        
        // Get minimum Distance
        int minDistance;
        if(minRight < minLeft){
            minDistance = minRight;
        }
        else {
            minDistance = minLeft;
        }
        
        // cout << "City: " << value << endl;
        // cout << "Minimum Distance Left: " << minLeft << endl;
        // cout << "Nearest Station Left: " << nearestLeft << endl;
        // cout << "Minimum Distance Right: " << minRight << endl;
        // cout << "Nearest Station Right: " << nearestRight << endl;
        // cout << "Minimum distance: " << minDistance << endl;
        // cout << endl;
        
        
        // Get max value
        if(minDistance > result){
            result = minDistance;
        }
        
        // Update stacks
        // If value is equal to top, pop it and push it to back
        if(!front.empty()){
            if(value == front.top()){
                int spaceStation = front.top();
                front.pop();
                back.push(spaceStation);
            }   
        }
    }
    // cout << "Max Distance: " << result << endl;
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

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
