class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
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
};
