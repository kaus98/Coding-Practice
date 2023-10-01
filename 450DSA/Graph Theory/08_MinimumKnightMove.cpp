
int solve(int dx, int dy){
    queue<pair<int, int>> qu;
    map<pair<int,int>, bool> visit;

    vector<int> mx{1, 2, 2, 1, -1, -2, -2, -1};
    vector<int> my{2, 1, -1, -2, -2, -1, 1, 2};

    qu.push({0,0});
    visit[{0,0}] = true;
    pair<int, int> temp;
    int steps = 0;

    while(!qu.empty()){
        int size = qu.size();

        while(size--){
            temp = qu.front();
            qu.pop();
            if(temp.first == dx && temp.second == dy) return steps;

            for(int i = 0; i < 8; i++){
                if(!visit[{temp.first + mx[i] , temp.second + my[i]}]){
                    visit[{temp.first + mx[i] , temp.second + my[i]}] = true;
                    qu.push({temp.first + mx[i] , temp.second + my[i]});
                }
            }
        }
        steps++;
        
    }

}


int minimumKnightMoves(int x, int y) {
    // Write your code here

    return solve(x, y);
}