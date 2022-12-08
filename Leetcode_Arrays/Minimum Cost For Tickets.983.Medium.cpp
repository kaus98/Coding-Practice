class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int arr[366] = {0};
        int t=1;
        int temp;
        for(auto x: days){
            while(t!=x && t<366){
                // cout<<"Setting to Previous : "<<t << endl;
                arr[t] = arr[t-1];
                t++;
            }

            // cout<<"Setting X : "<<x << endl;
            temp = arr[x-1] + costs[0];
            temp = min(temp, arr[max(0, x-7)] + costs[1]);
            temp = min(temp, arr[max(0, x-30)] + costs[2]);
            arr[x] = temp;
            t++;

        }
        while(t<366){
            // cout<<"Setting to Previous : "<<t << endl;
            arr[t] = arr[t-1];
            t++;
        }
        // for(auto x: arr) cout<<x<<" ";
        return arr[365];
    }   
};
