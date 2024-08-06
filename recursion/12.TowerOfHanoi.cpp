/**
 * Tower of Hanoi
 * 
 * Story
 * Hanoi - Vietnam
 * 
 * We have three poles, with some disks placed on it.
 * The number of plates are equal to 64.
 * Disks are in ascending order.
 * 
 * Conditions:
 * 1. Disks should be in ascending order.
 * 2. We need to move one disk at a time.
 * 3. We have one more tower to work with.
 * 
 * 
 * 
 * Problem Statement, Input, Output
 * We are given three poles, 1, 2, and 3.
 * Assuming 1 is source, and 2 is helper pole, 3 is destination pole.
 * Conditions:
 * 1. Pick 1 plate at a time.
 * 2. We cannot have a bigger plate on a smaller plate.
 * 
 * Output:
 * We need to print the steps.
 * E.g. Move plate 1 from Pole 1 to Pole 2.
 * 
 * In General
 * Move plate x from Pole y to Pole z.
 * 
 * Induction-BaseCondition-Hypothesis
 * 
 * Hypothesis:
 * solve(n, s->d, h)
 * 
 * What will be smaller input?
 * If n plates are there, 
 * say we call solve(n-1, s->d, h) 
 * So, solve(n-1,..) will solve our solution for n-1, using helper
 * solve(n-1, s->h, d)
 * We transfer our n-1 plates to the helper pole as destination using d as helper.
 * 
 * Induction:
 * Now, our induction step will be to put the nth plate from s to d.
 * And then put all n-1 plates from helper h to destination d.
 * 
 * 
 * Base Condition:
 * Since we are decreasing our input n, 
 * if(n == 1) will be the smallest valid input in source s.
 * If only one plate, we directly put this plate from source s to destination d.
 * 
 * Code:
 * void solve(int s, int d, int h, int n) {
 *  if(n==1) {
 *      output.append("Move plate n from pole s to pole d")
 *      return
 *  }
 * 
 *  // Hypothesis
 *  // put n-1 plates to helper. So our new destination is h. And helper is d.
 *  solve(s, h, d, n-1);
 * 
 *  // only 1 rod left here
 *  output.append("Move plate n from pole s to pole d")
 * 
 *  // Now, after putting last plate from source to destination, our source is empty.
 *  // And we have n-1 plates in helper.
 *  // We need to put these n-1 plates from helper to destination.
 *  // So, our new source will he helper h, new destination will be d, and new helper will be 
 *  // source h.
 *  solve(h, d, s, n-1);
 *  
 *  return;
 * }
 */
#include<bits/stdc++.h>
using namespace std;

void print(int n, char source, char destination) {
    cout << "Move plate " << n << " from pole " << source << " to pole " << destination << "." << endl;
}

void solve(char source, char destination, char helper, int n) {
    // Our base condition is when n == 1
    if(n==1) {
        print(n, source, destination);
        return;
    }

    // Hypothesis
    // We assume that we put n-1 plates on helper h as destination
    // using destination d as helper from source s.
    solve(source, helper, destination, n-1);

    // Now we have 1 plate in source s, n-1 plates on helper h, 0 plates in destination d.
    // put this 1 plate from source s to destination d.
    print(n, source, destination);

    // Now source is empty, helper has n-1 plates, destination has 1 plate
    // put n-1 plates from helper to destination using source as helper
    solve(helper, destination, source, n-1);

    return;
}

int main() {
    int n = 4;
    solve('s', 'd', 'h', n);
    return 0;
}