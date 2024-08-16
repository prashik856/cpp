/**
 * Allocate minimum number of pages
 * 
 * Given number of pages in n different books and m students.
 * The books are arranged in ascending order of number of pages.
 * 
 * Every student is assigned to read some consecutive books.
 * The task is to assign books in such a way that the maximum number of pages
 * assigned to a student is minimum.
 * 
 * Input:
 * pages[]: {12, 34, 67, 90}
 * m = 2
 * Output = 113
 * 
 * There are 2 students,
 * books can be distributed in the following fashion.
 * 1. [12] and [34, 67, 90]
 * Max pages to student 2:
 * 34 + 67 + 90 = 191
 * 
 * 2. [12, 34] and [67, 90]
 * Max pages to student 2: 67 + 90 = 157
 * 
 * 3. [12, 34, 67] and [90]
 * Maximum number of Pages to student 1
 * 12 + 34 + 67 = 113
 * 
 * Approach:
 * We have 3 restrictions on us:
 * 1. Book needs to be read as a whole
 * 2. Every student needs to have atleast one book.
 * 3. if multiple books are assigned to a student, the books assigned needs to be 
 * continuous
 * 
 * Example
 * Input: {10, 20, 30, 40}
 * k = 2
 * 
 * We can allocate books this way
 * 10 - 20, 30, 40
 * So, 10 - 90, here 90 is max.
 * 
 * Another way:
 * 10, 20  - 30 40
 * So, 30 - 70, here 70 is max
 * 
 * Another way
 * 10, 20, 30 - 40
 * So, 60 - 40, here 60 is max.
 * 
 * Using all different distributions, the max pages are 90, 70 and 60.
 * Out of which, 60 is the minimum out of all maximum values.
 * 
 * Our output is 60.
 * 
 * The given array may, or may not be sorted.
 * 
 * HOW DO WE USE BINARY SEARCH HERE?
 * Since we have to search for 60 somewhere, 
 * we need to have an array which stores maximum number of pages.
 * 
 * Now, minimum value of this array whill be 0,
 * And maximum number of pages will be sum of the array.
 * 
 * We can improve this array's minimum value.
 * We have to give atleast one book to one student.
 * So, the minimum value of the array will be max of the input array.
 * 
 * For given example.
 * Our binary search array, 
 * minValue = 40 (max of input array)
 * maxValue = 100 (sum of all elements of input array)
 * 
 * let's just put our low at 0
 * Now, our low is at 0, and high is at 100.
 * our mid will be 50.
 * Now, we want none of our students to read more thatn 50.
 * With this in mind, what will be our distribution
 * s1 = 10 + 20 (cannot have 30 as it will exceed mid)
 * s2 = 30 (cannot have 40 as it will exceed mid)
 * s3 = 40
 * So, we need minimum of 3 students to satisfy this condition.
 * But, we are given 2 students.
 * That means, we cannot make this scheme.
 * So that means, we need to increase our number of pages.
 * 
 * How do we increase the capacity?
 * How do we calculate the new mid?
 * 
 * 
 * New mid = (50+100)/2 = 75
 * With new scheme:
 * s1 = 10 + 20 + 30 (cannot have 40 as it will increase mid)
 * s2 = 40
 * Now, this value 75 matches our current scheme, and we can work with it.
 * 
 * Now, we want to find an even more efficient solution,
 * so we need to go to the left.
 * let our high = 75, and low = 50
 * New mid = 62.
 * With our new scheme:
 * s1 = 10 + 20 + 30
 * s2 = 40
 * it works
 * 
 * let this be our new high
 * new mid = (50 + 62)/2 = 56
 * It won't work
 * 
 * we go higher
 * low = 56 high = 62
 * new mid = (56 + 62)/2 = 118/2 = 59
 * won't work
 * 
 * low = 59 high = 62
 * new mid = (59 + 62)/2 = 121/2 = 60
 * it will work
 * 
 * And with 60, we have perfect number of pages.
 * That will be our answer.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int allocatePagesOfBooks(vector<int> &input, int key) {
    int output = -1;

    int low = -1;
    int high = 0;
    for(int i=0; i<input.size(); i++) {
        high = high + input[i];
        if(input[i] > low) {
            low = input[i];
        }
    }

    cout << "Init low: " << low << "| Init high: " << high << endl;
    cout << endl;

    vector<int> scheme = vector<int>();
    int mid = high;
    while(true) {
        mid = low + (high - low)/2;
        cout << "low: " << low << " | high: " << high << "| Mid: " << mid << endl;

        if(low == mid) {
            break;
        }

        // if we satisfy our schema perfectly
        int index = 0;
        int currentSum = 0;
        while(index != input.size()) {
            int item = input[index];
            if(currentSum + item <= mid) {
                currentSum = currentSum + item;
            } else {
                scheme.push_back(currentSum);
                currentSum = item;
            }
            index++;
            if(index == input.size()) {
                scheme.push_back(currentSum);
            }
        }
        cout << "Scheme Vector: " << endl;
        printVector(scheme);

        if(scheme.size() == key) {
            cout << "Got some output: " << mid << endl;
            output = mid;

            // can we optimize it by decreasing the value
            high = mid;
        } else if(scheme.size() < key) {
            // decrease the mid value
            high = mid;
        } else if(scheme.size() > key){
            // increase the mid value
            low = mid;
        }

        scheme.clear();
        cout << endl;
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({10, 20, 30, 40});
    cout << "Input vector: " << endl;
    printVector(input);

    int students = 2;
    cout << "Number of students: " << students << endl;
    cout << endl;

    int output = allocatePagesOfBooks(input, students);
    cout << "Output: " << output << endl;

    return 0;
}