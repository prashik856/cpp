#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the gridSearch function below.
string gridSearch(vector<string> G, vector<string> P) {
    int length = P.size();
    int width = P[0].size();
    
    int GridLength = G.size();
    int GridWidth = G[0].size();
    
    for(int i=0; i<G.size(); i++){
        for(int j=0; j<G[i].size(); j++){
            // Get possible condidate for grid search
            if(j + width - 1 < GridWidth && i + length - 1< GridLength){
                char first = G[i][j];
                char second = G[i][j + width - 1];
                char third = G[i + length - 1][j];
                char fourth = G[i + length - 1][j + width - 1];
                // cout << "Four corners are: " << endl;
                // cout << first << " | " << second << endl;
                // cout << third << " | " << fourth << endl;
                
                char PFirst = P[0][0];
                char PSecond = P[0][width - 1];
                char PThird = P[length - 1][0];
                char PFourth = P[length - 1][width - 1];
                // cout << "Four corners of Pattern are: " << endl;
                // cout << PFirst << " | " << PSecond << endl;
                // cout << PThird << " | " << PFourth << endl;
                
                // Possible condidate when
                if(first == PFirst
                && second == PSecond
                && third == PThird
                && fourth == PFourth){
                    //cout << "Possible Candidate" << endl;
                    // k and l
                    int count = 0;
                    for(int k=i; k<=i+length-1; k++){
                        for(int l=j; l<=j+width-1; l++){
                            if(G[k][l] == P[k-i][l-j]){
                                count++;
                            } else {
                                break;
                            }
                        }
                    }
                    //cout << "Count Value: " << count << endl;
                    if(count == length*width){
                        // Found the pattern
                        return "YES";
                    }
                }
            } else {
                break;
            }
        }
        // cout << endl;
    }
    // cout << endl;
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string RC_temp;
        getline(cin, RC_temp);

        vector<string> RC = split_string(RC_temp);

        int R = stoi(RC[0]);

        int C = stoi(RC[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string rc_temp;
        getline(cin, rc_temp);

        vector<string> rc = split_string(rc_temp);

        int r = stoi(rc[0]);

        int c = stoi(rc[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

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
