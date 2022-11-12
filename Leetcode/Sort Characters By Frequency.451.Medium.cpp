bool cmp(pair<char, int>& a,
         pair<char, int>& b)
{
    return a.second > b.second;
}

class Solution {
public:

    string frequencySort(string s) {
        int lower[256] = {0};

        for(int i = 0; i< s.length(); i++){
            lower[s[i]]++;
        }

        vector<pair<char, int> > L;
        for(int i = 0; i<256; i++){
            if (lower[i]>0) L.push_back(pair(i , lower[i]));
        }

        sort(L.begin(), L.end(), cmp);
        string S;

        for(int i = 0; i<L.size(); i++){
            if(L[i].second > 0) for(int j = L[i].second; j>0; j--) {S.push_back(L[i].first);}
            else break;
        }

        return S;
    }
};
