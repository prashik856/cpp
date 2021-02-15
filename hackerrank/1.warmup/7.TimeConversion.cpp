#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
     // AM = 0, PM = 1
     string result = "";
     
     int meridian = 0;
     char meri = s[s.size()-2];
     if(meri == 'P'){
         meridian = 1;
     } else {
         meridian = 0;
     }
     
     if(meridian == 0){
         if(s[0] == '1' && s[1] == '2'){
             result.push_back('0');
             result.push_back('0');
             for(int i=2; i<s.size() -2; i++){
                 result.push_back(s[i]);
             }
         }
         else{
            for(int i=0; i<s.size() -2; i++){
                result.push_back(s[i]);
            }
         }
     } else {
         if(s[0] == '1' && s[1] == '2'){
            for(int i=0; i<s.size()-2; i++){
                result.push_back(s[i]);
            }
         } else {
            string hour;
            hour.push_back(s[0]);
            hour.push_back(s[1]);
            stringstream integerValue(hour);
            int intHour = 0;
            integerValue >> intHour;
            intHour = intHour + 12;
            ostringstream str1;
            str1 << intHour;
            result = str1.str();
            for(int i=2; i<s.size()-2; i++){
                result.push_back(s[i]);
            }
         }
         
     }
     
     return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
