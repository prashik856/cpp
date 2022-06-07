/*
Given a sorted set, find if there exist three elements in Arithmetic Progression or not 
- Please note that, the answer is true if there are 3 or more elements in AP, otherwise false.
- To find the three elements, we first fix an element as middle element and search for other two (one smaller and one greater).
- We start from the second element and fix every element as middle element. 
- For an element set[j] to be middle of AP, there must exist elements ‘set[i]’ and ‘set[k]’ such that 
    set[i] - d + set[k] + d= 2*set[j] where 0 <= i < j and j < k <=n-1. 
- How to efficiently find i and k for a given j? We can find i and k in linear time using following simple algorithm. 
-> Initialize i as j-1 and k as j+1
-> Do following while i >= 0 and k <= n-1
-> If set[i] + set[k] is equal to 2*set[j], then we are done.
        If set[i] + set[k] > 2*set[j], 
            then decrement i (do i–).
        Else if set[i] + set[k] < 2*set[j], 
            then increment k (do k++).
1 2 5 9 10 7 11 12 16 20 25
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {1, 2, 3, 5, 9, 10, 7, 11, 12, 16, 20, 25};
    cout << "Given vector is:" << endl;
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;

    // Check if there exists 3 numbers in AP
    // a - d, a, a + d.
    // Assuming middle element as a, we need to find two elements such that their sum is twice of middle element

    int result = 0;
    int j=1;
    for(int j=1; j<a.size() - 1 && result == 0; j++){
        int i=j-1,k=j+1;
        while(i>=0 && k<a.size()){
            if(a[i] + a[k] == 2 * a[j]){
                result = 1; 
                break;
            } else if(a[i] + a[k] < 2 * a[j]){
                k++;
            } else if(a[i] + a[k] > 2 * a[j]){
                i--;
            }
        }
    }
    
    cout << "Result: " << result << endl;
}