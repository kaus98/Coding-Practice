class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r,d;
        for(int i = 0; i < senate.length(); i++){
            if(senate[i]==82) r.push(i);
            else d.push(i);
        }
        int i = senate.length();

        while(r.size() && d.size()){
            if(r.front() > d.front()) d.push(i++);
            else r.push(i++);
            r.pop();
            d.pop();
        }
        if(r.size() > d.size()) return "Radiant";
        else return "Dire";
    }
};
