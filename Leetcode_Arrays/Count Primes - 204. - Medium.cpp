class Solution {
public:
    int countPrimes(int n) {
        if(n<3) {return 0;}
        // if(n<3) {return}
        vector<bool> arr(n,true);
        arr[0] = arr[1] = false;
        int counter = 1;
        for(int i = 4; i < n; i+=2){
            arr[i] = false;
        }
        for(int i = 3; i < n; i+=2){
            if(!arr[i]) continue;

            else{
                counter++;
                for(int j = i*2; j<n; j+=i) arr[j] = false;
            }
        }
        return counter;
    }
};
