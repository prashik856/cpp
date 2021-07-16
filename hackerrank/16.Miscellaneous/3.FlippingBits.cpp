// Problem : https://www.hackerrank.com/challenges/flipping-bits/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=miscellaneous
// Intuition: Store the bit value in a vector
#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) {
    unsigned int value = n;
    unsigned int result = 0;
    int count = 0;
    vector<int> bitValue(32,0);
    while(value > 0){
        if(value%2 == 0){
            // Zero here
            bitValue[count] = 0;
        } else {
            bitValue[count] = 1;
        }
        count++;
        value = value / 2;
    }
    // cout << "N: " << n << endl;
    // cout << "Count: " << count << endl;    
    // Reconstructing bit
    // unsigned int reconstructed = 0;
    // for(int i=0; i<bitValue.size(); i++){
    //     unsigned int val = bitValue[i] * (long)pow(2,i);
    //     reconstructed = reconstructed + val;
    // }
    // cout << "Re: " << reconstructed << endl;
    
    // cout << "Bit Value: " << endl;
    // for(int i=bitValue.size() - 1; i>=0; i--){
    //     cout << bitValue[i];
    // }
    // cout << endl;
    
    for(int i=0; i<bitValue.size(); i++){
        if(bitValue[i] == 0){
            bitValue[i] = 1;
        } else {
            bitValue[i] = 0;
        }
    } 
    
    // cout << "BitValue Reversed: " << endl;
    // for(int i=bitValue.size() - 1; i>=0 ; i--){
    //     cout << bitValue[i];
    // }
    // cout << endl << endl;
    
    for(int i=0; i<bitValue.size(); i++){
        unsigned int val = bitValue[i] * (long)pow(2, i);
        result = result + val;
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
