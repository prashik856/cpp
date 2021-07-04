#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k, int r_q, int c_q, vector< vector<int> > obstacles){
    int result = 0;
    int r = r_q - 1;
    int c = c_q - 1;
    cout << "Queens Position: ( " << r_q << " " << c_q << " )" << endl;
    unordered_map<long, long> keys;
    for(int i=0; i<obstacles.size(); i++){
        long row = obstacles[i][0] - 1;
        long col = obstacles[i][1] - 1;
        long value = n * row + col;
        keys[value] = 1;
    }
    cout << endl;

    // Go right
    // i constant, increase j
    int rightSum = 0;
    for(int j=c+1; j<n; j++){
        long row = r;
        long col = j;
        long value = n * row + col;
        long obstacle = keys[value];
        if(obstacle == 1){
            // obstacle present
            cout << "Obstacle Present: ( " << row+1 << " " << col+1 << " )" << endl;
            break;
        } else {
            // No obstacle
            rightSum++;
            result++;
        }
    }
    cout << "Right Sum: " << rightSum << endl;
    cout << endl;
    
    // Go left
    // row constant, decrease j
    int leftSum = 0;
    for(int j=c-1; j>=0; j--){
        long row = r;
        long col = j;
        long value = n * row + col;
        long obstacle = keys[value];
        if(obstacle == 1){
            // obstacle
            cout << "Obstacle Present: ( " << row+1 << " " << col+1 << " )" << endl;
            break;
        } else {
            leftSum++;
            result++;
        }
    }
    cout << "Left Sum: " << leftSum << endl;
    cout << endl;
    
    // Go up
    // column constant, increasae i
    int upSum = 0;
    for(int i=r+1; i<n; i++){
        long row = i;
        long col = c;
        long value = n * row + col;
        long obstacle = keys[value];
        if(obstacle == 1){
            cout << "Obstacle Present: ( " << row+1 << " " << col+1 << " )" << endl;
            break;
        } else {
            upSum++;
            result++;
        }
    }
    cout << "Up Sum: " << upSum << endl;
    cout << endl;

    // Go down
    // column constant, increase i
    int downSum= 0;
    for(int i=r-1; i>=0; i--){
        long row = i;
        long col = c;
        long value = n * row + col;
        long obstacle = keys[value];
        if(obstacle == 1){
            cout << "Obstacle Present: ( " << row+1 << " " << col+1 << " )" << endl;
            break;
        } else {
            downSum++;
            result++;
        }
    }
    cout << "Down Sum: " << downSum << endl;
    cout << endl;

    // Go right up
    // increase i, increase j
    int rightUpSum = 0;
    for(int i=r+1,j=c+1; i<n && j < n; i++,j++){
        long row = i;
        long col = j;
        long value = n * row + col;
        long obstacle = keys[value];
        if(obstacle == 1){
            cout << "Obstacle Present: ( " << row+1 << " " << col+1 << " )" << endl;
            break;
        } else {
            rightUpSum++;
            result++;
        }
    }
    cout << "Right Up Sum: " << rightUpSum << endl;
    cout << endl;
    
    // Go right down
    // decrease i, increase j
    int rightDownSum = 0;
    for(int i=r-1,j=c+1; i>=0 && j<n; i--,j++){
        long row = i;
        long col = j;
        long value = n * row + col;
        long obstacle = keys[value];
        if(obstacle == 1){
            cout << "Obstacle Present: ( " << row+1 << " " << col+1 << " )" << endl;
            break;
        } else {
            rightDownSum++;
            result++;
        }
    }
    cout << "Right Down Sum: " << rightDownSum << endl;
    cout << endl;
    
    // Go left up
    // increase i, decrease j
    int leftUpSum = 0;
    for(int i=r+1,j=c-1; i<n && j>=0; i++,j--){
        long row = i;
        long col = j;
        long value = n * row + col;
        long obstacle = keys[value];
        if(obstacle == 1){
            cout << "Obstacle Present: ( " << row+1 << " " << col+1 << " )" << endl;
            break;
        } else {
            leftUpSum++;
            result++;
        }
    }
    cout << "Left Up Sum: " << leftUpSum << endl;
    cout << endl;

    // Go left down
    // decrease i, decrease j
    int leftDownSum = 0;
    for(int i=r-1,j=c-1; i>=0 && j>=0; i--,j--){
        long row = i;
        long col = j;
        long value = n * row + col;
        long obstacle = keys[value];
        if(obstacle == 1){
            cout << "Obstacle Present: ( " << row+1 << " " << col+1 << " )" << endl;
            break;
        } else {
            leftDownSum++;
            result++;
        }
    }
    cout << "Left Down Sum: " << leftDownSum << endl;
    cout << endl;

    return result;
}

int main(){
    int n,k;
    cin >> n >> k;

    int r_q,c_q;
    cin >> r_q >> c_q;

    vector< vector<int> > obstacles(k, vector<int>(2,0));
    for(int i=0; i<k; i++){
        int a,b;
        cin >> a >> b;
        obstacles[i][0] = a;
        obstacles[i][1] = b;
    }

    int result = solve(n,k,r_q,c_q,obstacles);

    cout << result << endl;
    return 0;
}