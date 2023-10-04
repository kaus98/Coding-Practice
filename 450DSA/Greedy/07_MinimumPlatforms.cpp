
bool comp(pair<int, int> &a, pair<int, int> &b){
    if(a.first == b.first) return a.second<b.second;

    return a.first < b.first;
}

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    vector<pair<int, int>> res;
    for(int i = 0; i < n; i++) res.push_back({at[i], 0});
    for(int i = 0; i < n; i++) res.push_back({dt[i], 1});

    sort(res.begin(), res.end(), comp);

    int track = 0;
    int maxtack = 0;
    for(auto x: res){
        if(x.second == 0) track++;
        else if(x.second == 1) track--;

        maxtack = max(maxtack, track);
    }

    return maxtack;
}