#include <bits/stdc++.h> 
string shortestSubstring(string str)
{
    // Your code goes here   
        unordered_set<char> count;
        for(int i = 0; i < str.size(); i++) count.insert(str[i]);
        
        int count_size = count.size();
        map<char, int> temp;
        int start = 0;
        int end = -1;
        int temp_count = 0;
        string solution;
        
        while(temp_count < count_size){
            end++;
            temp[str[end]]++;
            if(temp[str[end]] == 1) temp_count++;
            
        }
        int result = end-start+1;
        solution = str.substr(start, result);
        // cout<<"First Setting the Result : "<<result<<" "<<start<<" "<<end<<endl;
        
        while( end < str.size()){
            
            
            while(temp[str[start]] > 1) {
                
                temp[str[start]]--;
                start++;
            }
            
            // cout<<"Resetting the Result : "<<result<<" "<<start<<" "<<end<<endl;
            if((end-start+1) < result){
                result = min(result, end-start+1);
                solution = str.substr(start, result);
            }
            
            end++;
            temp[str[end]]++;
            
        }
        
        return solution;
}