int minimumCoins(int v) {
    // Write your code here.
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    int count = 0;

    for(int i = coins.size()-1; i >= 0; i--){
        if(v==0) break;
        while(coins[i] <= v){
            count++;
            v -= coins[i];
        }
    }
    return count;

}
