#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string result;
    
    vector<string> hours = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve"
    };
    
    vector<string> minutes = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "quarter",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty",
        "twenty one",
        "twenty two",
        "twenty three",
        "twenty four",
        "twenty five",
        "twenty six",
        "twenty seven",
        "twenty eight",
        "twenty nine",
        "half"
    };
    
    string full = "o' clock";
    string past = "past";
    string to = "to";
    string minuteString = "minute";
    string minutesString = "minutes";
    
    if(m == 0){
        // full
        string hour = hours[h - 1];
        for(int i=0; i<hour.size(); i++){
            result.push_back(hour[i]);
        }
        result.push_back(' ');
        for(int i=0; i<full.size(); i++){
            result.push_back(full[i]);
        }
        cout << result << endl;
    } else if(m >= 1 && m <= 30){
        
        // past
        string minute = minutes[m - 1];
        for(int i=0; i<minute.size(); i++){
            result.push_back(minute[i]);
        }
        result.push_back(' ');
        
        // Only 1 minute
        if(m == 1){
            for(int i=0; i<minuteString.size(); i++){
                result.push_back(minuteString[i]);
            }
            result.push_back(' ');
        }
        
        // More than one minute
        else if(m > 1 && m!=15 && m!=30){
            for(int i=0; i<minutesString.size(); i++){
                result.push_back(minutesString[i]);
            }
            result.push_back(' ');
        }
        
        // past
        for(int i=0; i<past.size(); i++){
            result.push_back(past[i]);
        }
        result.push_back(' ');
        
        // hour
        string hour = hours[h - 1];
        for(int i=0; i<hour.size(); i++){
            result.push_back(hour[i]);
        }
        cout << result << endl;
        
    } else if(m > 30 && m < 60){
        // to
        // When to, take care of next hour
        m = 60 - m;
        
        string minute = minutes[m - 1];
        for(int i=0; i<minute.size(); i++){
            result.push_back(minute[i]);
        }
        result.push_back(' ');
        
                // Only 1 minute
        if(m == 1){
            for(int i=0; i<minuteString.size(); i++){
                result.push_back(minuteString[i]);
            }
            result.push_back(' ');
        }
        
        // More than one minute
        else if(m > 1 && m!=15 && m!=30){
            for(int i=0; i<minutesString.size(); i++){
                result.push_back(minutesString[i]);
            }
            result.push_back(' ');
        }
        
        // to
        for(int i=0; i<to.size(); i++){
            result.push_back(to[i]);
        }
        result.push_back(' ');
        
        // hour
        if(h != 12){
            h = h + 1;
        } else if(h == 12){
            h = 1;
        }
        string hour = hours[h - 1];
        for(int i=0; i<hour.size(); i++){
            result.push_back(hour[i]);
        }
        cout << result << endl;
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
