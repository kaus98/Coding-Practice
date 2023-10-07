#include <bits/stdc++.h> 
void permut(string S, set<string> &st, int i, queue<char> &qu, string temp){
		    if(temp.size() == S.size()) {st.insert(temp); return;} // Breaking the condition
		    
		    //Loop to add one and pass the other 
		    for(int j = i; j < S.size(); j++){
		      //  temp  += qu.front();
		        char top = qu.front();
		        temp.push_back(top);
		        
		      //  cout<<"Added to Temp : "<<temp<<" i: "<<i<<" j:  "<<j<<" top: "<<top<<endl;
		        qu.pop();
		        
		        permut(S, st, i+1, qu, temp);
		        
		        qu.push(top);
		        temp.pop_back();
		    }
		}
        
vector<string> findPermutations(string &S) {
    // Code here there
		    set<string> result;
		    sort(S.begin(), S.end());
		    queue<char> qu;
		    
		    for(int i = 0; i < S.size(); i++){
		        qu.push(S[i]);
		      //  cout<<"Adding to Queue : "<<S[i]<<endl;
		    }
		    
		    permut(S, result, 0, qu, "");
		    
		    vector<string> res(result.begin(), result.end());
		    
		    return res;
}

