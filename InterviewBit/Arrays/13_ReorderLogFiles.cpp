
bool isLetterLog(string A){
    bool flag = false;
    for(int i = 0; i < A.size(); i++){
        if(A[i] == '-') flag = true;
        
        if(flag == true && isdigit(A[i])) return false;
    }
    
    return true;
}
bool comp(string &s1, string &s2){
    int i = 0;
    while(s1[i] != '-') i++;
    string a1 = s1.substr(0,i-1);
    string a2 = s1.substr(i+1);
    
    i = 0;
    while(s2[i] != '-') i++;
    string b1 = s2.substr(0, i-1);
    string b2 = s2.substr(i+1);
    
    if(a2 == b2) return a1 < b1;
    else return a2 < b2;
    
    
    
}
vector<string> Solution::reorderLogs(vector<string> &A) {
    vector<string> letterLog;
    vector<string> digitLog;
    
    for(int i = 0; i < A.size(); i++){
        if(isLetterLog(A[i])) letterLog.push_back(A[i]);
        else digitLog.push_back(A[i]);
    }
    
    sort(letterLog.begin(), letterLog.end(), comp);
    
    for(int i = 0; i < digitLog.size(); i++)letterLog.push_back(digitLog[i]);
    
    return letterLog;
    
}
