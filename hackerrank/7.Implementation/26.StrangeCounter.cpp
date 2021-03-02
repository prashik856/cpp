#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long result = 0;
    long currentTime = 0;
    long n =0;
    long powerValue;
    long counterValue;
    while(currentTime < t){
        powerValue = (long)pow(2,n);
        counterValue = 3*powerValue;
        if(currentTime + counterValue < t){
            currentTime = currentTime + counterValue;
            n++;
        } else {
            break;
        }
    }
    
    // We have currentTime closest to t to the left
    // cout << "Time left: " << t - currentTime << endl;
    // cout << "CounterValue: " << counterValue << endl;
    // cout << "Current Time: " << currentTime << endl;
    // cout << "N: " << n << endl;
    // cout << "Valure required: " << counterValue - (t - currentTime) + 1 << endl;
   
    result = counterValue - (t - currentTime) + 1;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
