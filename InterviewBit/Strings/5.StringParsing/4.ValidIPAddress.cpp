/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/

Check all possible combination where we can put three '.'s
n^3 complexity. Max complexity: 12x12x12 -> So it's okay.

[0:i] -> temp1
[i+1: j] -> temp2
[j+1: k] -> temp3
[k+1: n-1] -> temp4

Check if all strings are valid.
check if substrings are properly created. That's very important.!
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<string> solve(string a){
    vector<string> result;
    int n = a.size();
    if(n > 12){
        return result;
    }
    if(n == 4){
        string tempResult;
        tempResult.push_back(a[0]);
        tempResult.push_back('.');
        tempResult.push_back(a[1]);
        tempResult.push_back('.');
        tempResult.push_back(a[2]);
        tempResult.push_back('.');
        tempResult.push_back(a[3]);
        result.push_back(tempResult);
        return result;
    }
    if(n < 4){
        return result;
    }


    if(n <= 12){
        // cout << "Acceptable length" << endl;
        string temp1, temp2, temp3, temp4;

        for(int i=0; i<n; i++){
            temp1.push_back(a[i]);
            for(int j=i+1; j<n; j++){
                temp2.push_back(a[j]);
                for(int k=j+1; k<n; k++){
                    temp3.push_back(a[k]);

                    for(int l=k+1; l<n; l++){
                        temp4.push_back(a[l]);
                    }
                    if(temp1.size() <=3 &&
                        temp1.size() > 0 && 
                        temp2.size() <=3 &&
                        temp2.size() > 0 &&
                        temp3.size() <=3 &&
                        temp3.size() > 0 &&
                        temp4.size() <=3 && 
                        temp4.size() > 0){
                            // cout << temp1 << endl;
                            // cout << temp2 << endl;
                            // cout << temp3 << endl;
                            // cout << temp4 << endl;
                            // cout << "Fine" << endl << endl;
                            if((temp1[0] == '0' && temp1.size() > 1) ||
                                (temp2[0] == '0' && temp2.size() > 1) ||
                                (temp3[0] == '0' && temp3.size() > 1) ||
                                (temp4[0] == '0' && temp4.size() > 1) ){
                                    temp4 = "";
                                    continue;
                                } else {
                                    int temp1int = stoi(temp1);
                                    int temp2int = stoi(temp2);
                                    int temp3int = stoi(temp3);
                                    int temp4int = stoi(temp4);
                                    if(temp1int >=0 &&
                                        temp1int <= 255 &&
                                        temp2int >=0 &&
                                        temp2int <= 255 &&
                                        temp3int >=0 &&
                                        temp3int <= 255 &&
                                        temp4int >=0 &&
                                        temp4int <= 255){
                                            string tempString = temp1 + "." + temp2 + "." + temp3 + "." + temp4;
                                            result.push_back(tempString);
                                        }
                                }
                        }

                    temp4 = "";
                }
                temp4 = "";
                temp3 = "";
            }
            temp4 = "";
            temp3 = "";
            temp2 = "";
        }
    }

    return result;
}

int main(){
    string text = "0100100";
    cout << "Given input is: " << text << endl;
    vector<string> result = solve(text);
    cout << "Result is: " << endl;
    printVector(result);
    return 0;
}