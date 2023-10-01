#include <bits/stdc++.h> 

//Check if graph is connected and not in multiple parts
void isConnected(unordered_map<int, vector<pair<int, int>>> &mp, vector<bool> &visit, int node){
    visit[node] = true;

    for(auto x: mp[node]){
        if(!visit[x.first]){
            isConnected(mp, visit, x.first);
        }
    }
}

//Determine the odd Vertex in Graph
vector<int> determineOdd( unordered_map<int, vector<pair<int, int>>> &mp){
    vector<int> result;
    for(auto x: mp){
        if(x.second.size()%2 == 1){
            result.push_back(x.first);
        }
    }

    return result;
}

//shortest Distance between a->b vertex using Floyd Warshall
vector<vector<int>> floydWarshall(int n, vector<vector<int>> &edges) {
    // Write your code here.

    vector<vector<int>> dp(n+1 , vector<int>(n+1, 1000000000));

    for(auto x: edges) {
        dp[x[0]][x[1]] = x[2];
        dp[x[1]][x[0]] = x[2];
    }

    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }

    for(int k = 1; k <=n ; k++){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(dp[i][k] != 1000000000 && dp[k][j] != 1000000000 && dp[i][j] > (dp[i][k] + dp[k][j])){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
    
    return dp;
}

//Main Function to calucalte the minimum extra distance
int extraDistance(deque<int> odds, vector<vector<int>> &dp){
    //If its last pair return
    if(odds.size() == 2){
        return dp[odds.front()][odds.back()];
    }

    //Calculate the extra distance
    //Take one node(Fix it) and take any other node and calculate the remaining min distance;

    int last = odds.back();
    odds.pop_back();
    int minWeight = INT_MAX;
    int n = odds.size();

    for(int i = 0; i < n; i++){
        int front = odds.front();
        odds.pop_front();
        int temp = dp[front][last];
        temp+=extraDistance(odds,dp);
        odds.push_back(front);
        
        if(temp < minWeight) minWeight = temp;
    }

    return minWeight;
}




int minTravelTime(int n, vector<vector<int>> &roads)
{
    // Write your code here
    unordered_map<int, vector<pair<int, int>>> mp;
    int weight = 0;
    vector<vector<int>> dp;
    vector<int> odds;
    deque<int> oddsde;
    vector<bool> visit(n+1, false);

    //Creating the Adjacent matrix map
    for(auto x: roads){
        mp[x[0]].push_back({x[1], x[2]});
        mp[x[1]].push_back({x[0], x[2]});
        weight+=x[2];
    } 

    // Check if the graph is connected.
    isConnected(mp, visit, 1);
    for(int i = 2; i <= n; i++) if(!visit[i]) return -1;


    //Calculate the distnace for each node with other using floyd warshall method    
    dp = floydWarshall(n,roads);

    // Determine the odds nodes
    odds = determineOdd(mp);

    //If this euclid circuit
    if(odds.size() == 0) return weight;

    //Create queue to share with next function
    for (auto x : odds) {
        oddsde.push_back(x);
    }
    //Calculate the extra distance
    int ext = extraDistance(oddsde, dp);
    
    return ext+weight;

}

