int maxGoldCollected(vector<vector<int>> mine, int n, int m) {
    // Write your code here.

    int m1 = m-2;

    while(m1>=0){
        for(int i = 0; i < n; i++){

            //Handling the First case
            if(i == 0){
                mine[i][m1] += max(mine[i][m1+1], mine[i+1][m1+1]);
            }

            else if(i == (n-1)){
                mine[i][m1] += max(mine[i][m1+1], mine[i-1][m1+1]);
            }

            else{
                mine[i][m1] += max({mine[i][m1+1], mine[i-1][m1+1], mine[i+1][m1+1]});
            }
        }
        m1--;
    }

    int maxi = 0;

    for(int i = 0; i < n; i++){
        maxi = max(maxi, mine[i][0]);
    }

    return maxi;
}