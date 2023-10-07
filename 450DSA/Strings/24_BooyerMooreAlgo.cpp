#include <bits/stdc++.h> 
vector<int> patternSearch(string text, string pattern) {
    // Write your code here.

    int i = pattern.size() - 1; // For Pattern
    int j = pattern.size() - 1; // For Text
    int counter = 0;
    vector<int> result;
    while(j < text.size()){
        int start = 0;
        i = pattern.size() - 1;

        while(start < pattern.size()) {
            if(text[j - start] == pattern[i-start]){
                start++;
                if(start == pattern.size()) {
                    result.push_back(j-start+1);
                    j++;
                }

            }
            else{
                // Implementing First -> Bad Character Heuristic
                int temp = j-start;
                while(start<pattern.size() && text[temp] != pattern[i-start]){
                    start++; 
                }
                j = temp + start;
                cout<<"Skipping the j to : "<<j<<endl;

                start = pattern.size(); // To Break the Loop
            }
        }

        
    }
    if (result.size()==0) result.push_back(-1);
    return result;

}

// Implementing Boyer Moore Algo
// So this have 2 parts
// First Implementing First -> Bad Character Heuristic
    