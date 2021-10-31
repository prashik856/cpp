/*
Problem Description

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .



Input Format
First argument is an integer array A containing arrival time of booking.

Second argument is an integer array B containing departure time of booking.

Third argument is an integer C denoting the count of rooms.



Output Format
Return True if there are enough rooms for N bookings else return False.

Return 0/1 for C programs.



Example Input
Input 1:

 A = [1, 3, 5]
 B = [2, 6, 8]
 C = 1


Example Output
Output 1:

 0


Example Explanation
Explanation 1:

 At day = 5, there are 2 guests in the hotel. But I have only one room.
*/
/*
Solution approach:
https://www.geeksforgeeks.org/find-k-bookings-possible-given-arrival-departure-times/
Approach 2 
The idea is to simply sort the 2 arrays (Array for arrival dates and Array for departure dates) first. 
Now, the next step would be to check how many overlaps are present in one particular range. 
If the number of overlaps are greater than the number of rooms, we can say that we have less rooms to accommodate guests. 

So, for a particular range where arrival date(ith of Arrival array) being the start date and departure date(ith of departure array) 
being the end date, overlap can be only possible if the next arrival dates(from i+1th) are less than end date of the range and greater 
than or equal to start date of the range (Since this is a sorted array, we don’t need to take care about the latter condition). 

Considering the fact, that we have sorted array, we directly need to check if the next Kth (i+Kth) arrival date falls in the range, 
if it does, all the dates before that arrival date will also fall in the taken range, 
resulting in K+1 overlaps with the range in question, hence exceeding the number of rooms. 


Understood the aproach.
Need to take care of if condition for x2 < y1 -> here, <= is not possible because even if departure is equal to arrival, people will
depart first!
*/
#include<bits/stdc++.h>
using namespace std;

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << "|";
        }
        cout << " ";
    }
    cout << endl;
}

bool solve(vector<int> arrival, vector<int> departure, int rooms){
    int n = arrival.size();
    bool result = false;
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    for(int i=0; i<n-rooms; i++){
        int x1 = arrival[i];
        int x2 = arrival[i+rooms];

        int y1 = departure[i];
        int y2 = departure[i+rooms];

        if(x2 < y1){
            return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << "Number of bookings: " << endl;
        cout << n << endl;
        
        vector<int> arrival;
        vector<int> departure;
        int rooms;

        cout << "Given arrival array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arrival.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;
        
        cout << "Given departure array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            departure.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        cout << "Number of rooms: " << endl;
        cin >> rooms;
        cout << rooms << endl;

        bool result = solve(arrival, departure, rooms);
        cout << "Result: " << result << endl;
        cout << endl;
    }
    return 0;
}