// You are given an integer array A.

// You have to find the number of occurences of each number.

// Return an array containing only the occurences with the smallest value's occurence first.

// For example, A = [4, 3, 3], you have to return an array [2, 1], where 2 is the number of occurences for element 3, 
// and 1 is the number of occurences for element 4. But, 2 comes first because 3 is smaller than 4.

vector<int> Solution::findOccurences(vector<int> &A) {
    set<int> st;
    map<int, int> mp;
    
    for(auto x: A){
        mp[x]++;
    }
    
    vector<int> result;
    
    for(auto m: mp){
        result.push_back(m.second);
    }
    
    return result;
    
    
}
