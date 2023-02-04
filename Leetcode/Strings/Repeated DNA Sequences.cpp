class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // My Solution : Time -	260 ms Memory - 19.6 MB
        vector<string> ans;
        
        unordered_set <string> sentences;        
        unordered_set <string> uniques;
        
        string temp = s.substr(0,10);
        
        sentences.insert(temp);
        int i = 10;
        while(i < s.length()){
            temp.erase(0,1);temp.push_back(s[i]);
            
            // cout<<"sentences.insert(\""<< temp << "\");\n";
            if(sentences.find(temp) != sentences.end()){
                cout<<"Inserting the Uniques : " << temp << "\n";
                uniques.insert(temp);
            }

            sentences.insert(temp);
            i++; 
            
        }
        cout << "\nAll constitutes are : " <<endl;
        unordered_set<string> :: iterator itr;
        for (itr = sentences.begin(); itr != sentences.end(); itr++)
            cout << (*itr) << endl;
        
        ans.insert(ans.end(), uniques.begin(), uniques.end());
        return ans;

        
    }
    
    vector<string> findRepeatedDnaSequences(string s) 
{
        // Checking other solutions : Time -	117 ms Memory - 23.36 MB
    if(s.size()<10)
        return {};
    
    unordered_map<string,int>mp;
    vector<string>ans;
    
    for(int i=0;i<s.size()-9;++i)
        ++mp[s.substr(i,10)];
    
    for(auto it:mp)
        if(it.second>1)
            ans.emplace_back(it.first);
    
    return ans;
}
    
        vector<string> findRepeatedDnaSequences(string s) {
            // More Faster Solution: time : 85ms
        if (s.size() < 10) return {};
        unordered_map<char, int> dna {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_set<int> candidates;
        unordered_set<string> duplicates;
        int pw = pow(4,9);
        int p = 10000007;
        int i = 0;
        int hash = 0;
        while (i < 10) {
            hash = (hash * 4 + dna[s[i]]) % p;
            ++i;
        }
        candidates.insert(hash);
        i = 1;
        while (i + 9 < s.size()) {
            hash = ((hash - pw * dna[s[i-1]] ) % p + p) % p;
            hash = ((hash * 4) + dna[s[i + 9]]) % p;
            if (candidates.find(hash) != candidates.end()) duplicates.insert(s.substr(i,10));
            else candidates.insert(hash);
            ++i;
        }
        return vector<string>(duplicates.begin(), duplicates.end());
    }
};
