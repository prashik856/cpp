#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int result = 0;
    int shared = 5;
    int liked = shared/2;
    result = result + liked;
    int day = 1;
    while(day < n){
        shared = liked * 3;
        liked = shared/2;
        result = result + liked;
        day++;
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
