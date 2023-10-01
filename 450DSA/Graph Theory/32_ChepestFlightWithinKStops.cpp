int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains)
{
    // Write your code here
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>> > pq;
    // list<int> *l = new list<int>[n];
    unordered_map<int, vector<pair<int, int>>> mp;

	for(auto x: trains){
		mp[x[0]].push_back({x[1], x[2]});
	}

    vector<int> distance(n, INT_MAX);
    distance[source] = 0; 

    pq.push({0, source});
    int count = 0; 
    int dist, nd;

    while(!pq.empty() && count <= K){
        int size = pq.size();
        count++;

        while(size--){
            dist = pq.top().first;
            nd = pq.top().second;
            pq.pop();

            for(auto x: mp[nd]){
                if(distance[x.first] > dist + x.second){
                    distance[x.first] = dist + x.second;
                    pq.push({distance[x.first], x.first});
                }
            }
        }
    }

    return distance[destination]==INT_MAX?-1:distance[destination];
}

