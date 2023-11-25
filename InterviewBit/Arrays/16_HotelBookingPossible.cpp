// A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    int i = 0; int j = 0;
    int count = 0;
    
    
    while(i < arrive.size()){
        if(arrive[i] <= depart[j]){
            count++;
            i++;
        } else{
            j++;
            count--;
        }
        
        if(count > K) return false;
    }
    
    return true;
}
