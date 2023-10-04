int maximumMeetings(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<int, int>> res;

    for(int i = 0; i < start.size(); i++){
        res.push_back({end[i], start[i]});
    }

    sort(res.begin(), res.end());

    int visit = res[0].first;
    int count = 1;

    for(auto x: res){
        if(visit < x.second){
            count++;
            visit = x.first;
        }
    }

    return count;
}