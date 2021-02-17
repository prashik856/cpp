#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    string result;
    if(year > 1918){
        // Learp year is divisible by 400
        // or
        // Leap year is divisible by 4 and not by 100
        int val = year % 400;
        if(val == 0){
            // Leap
            string date = "12.09.";
            for(int i=0; i<date.size(); i++){
                result.push_back(date[i]);
            }
            date = to_string(year);
            for(int i=0; i<date.size(); i++){
                result.push_back(date[i]);
            }
        } else {
            val = year % 4;
            int val2 = year % 100;
            if(val == 0 && val2 != 0){
                // Leap
                string date = "12.09.";
                for(int i=0; i<date.size(); i++){
                    result.push_back(date[i]);
                }
                date = to_string(year);
                for(int i=0; i<date.size(); i++){
                    result.push_back(date[i]);
                }
            } else {
                // Not leap
                // normal year
                string date = "13.09.";
                for(int i=0; i<date.size(); i++){
                    result.push_back(date[i]);
                }
                date = to_string(year);
                for(int i=0; i<date.size(); i++){
                    result.push_back(date[i]);
                }
            }
        }
    } else if(year < 1918){
        // Leap year is divisible by 4
        // Normal year
        // 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 = 243
        // 13.09.year
        
        // If leap
        // 31 + 28
        // 12.09.year
        int val = year % 4;
        if(val == 0){
            // leap
            string date = "12.09.";
            for(int i=0; i<date.size(); i++){
                result.push_back(date[i]);
            }
            date = to_string(year);
            for(int i=0; i<date.size(); i++){
                result.push_back(date[i]);
            }
        } else {
            // normal year
            string date = "13.09.";
            for(int i=0; i<date.size(); i++){
                result.push_back(date[i]);
            }
            date = to_string(year);
            for(int i=0; i<date.size(); i++){
                result.push_back(date[i]);
            }
        }
    } else if(year == 1918){
        // Here 
        // 31 + 15 + 31 + 30 + 31 + 30 + 31 + 31 + 26
        // 26.09.year
        string date = "26.09.";
        for(int i=0; i<date.size(); i++){
            result.push_back(date[i]);
        }
        date = to_string(year);
        for(int i=0; i<date.size(); i++){
            result.push_back(date[i]);
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
