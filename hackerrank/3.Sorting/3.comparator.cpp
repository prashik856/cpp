#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct Player {
    int score;
    string name;
};

class Checker{
public:
    
  	// complete this method
    static int comparator(Player a, Player b)  {
        int compareResult;
        if(a.score > b.score){
            compareResult = 1;
        }
        else if(a.score < b.score){
            compareResult =  -1;
        }
        
        else if(a.score == b.score){
            // Check names
            compareResult = a.name.compare(b.name);
            if(compareResult > 0){
                compareResult = -1;
            }
            else if(compareResult < 0){
                compareResult = 1;
            }
            else{
                compareResult = 0;
            }
        }
        return compareResult;
    }
};




bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }
    sort(players.begin(), players.end(), compare);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }
    return 0;
}