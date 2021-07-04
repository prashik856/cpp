#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfStones function below.
string gameOfStones(int n) {
    /*
    It's proof by induction.

The hypothesis:
For n % 7 in [0, 1], the first player loses, otherwise the first player wins.

The anchor:

Clearly, for 0 or 1 stones, the first player has no move, so he loses.
For any of 2, 3, 4, 5, or 6 stones, the first player can make a move that leaves 0 or 1 stones for the second player, so the first player wins.

Induction step:
Now, for a given starting position n we assume that our hypothesis is true for all m < n.

If n % 7 in [0, 1], we can only leave the second player with positions (n - 2) % 7 in [5, 6], (n - 3) % 7 in [4, 5], or (n - 5) % 7 = [2, 3], all of which mean – by induction – that the second player will be in a winning position. Thus, for n % 7 in [0, 1], the first player loses.

If n % 7 in [2, 3, 4, 5, 6], there's always a move to leave the second player with an m % 7 in [0, 1], thus – again by induction – forcing a loss on the second player, leaving the first player to win.

That concludes the proof.
*/  
    int value = n % 7;
    if(value == 0 || value == 1){
        return "Second";
    } else {
        return "First";
    }
    return "Second";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = gameOfStones(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
