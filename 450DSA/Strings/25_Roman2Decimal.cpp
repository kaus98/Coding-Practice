int romanToInt(string s) {
    // Write your code here

    map<char,int>mp;
    mp['I']=1;
    mp['V']=5;
    mp['X']=10;
    mp['L']=50;
    mp['C']=100;
    mp['D']=500;
    mp['M']=1000;

    int i = s.size()-1;
    int result = 0;

    result = mp[s[i]];
    int temp = result;
    i--;
    while(i>=0){

        if(mp[s[i]] < temp)
            result -= mp[s[i]];
        else
            result += mp[s[i]];

        temp = mp[s[i]];
        
        i--;

    }

    return result;

}