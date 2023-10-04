long long connectRopes(int* arr, int n)
{
    // Your code goes here
    priority_queue<long long, vector<long long>, greater<long long>>  pq;

    for(int i = 0; i < n; i++) pq.push(arr[i]);

    long long cost = 0;
    while(pq.size() > 1){
        long long item1 = pq.top(); pq.pop();
        long long item2 = pq.top(); pq.pop();

        cost+= (item1 + item2);
        pq.push(item1+item2);
    }

    return cost;
}
