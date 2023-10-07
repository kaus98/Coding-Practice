int solve(string str, int i, int j){
    int sol = 0;

    //Even Solution
    
    //Odd Solution
    while(i>=0 && j <str.length() && str[i]==str[j]){
        i--;
        j++;
    }

    return j-i-1;
}

string longestPalinSubstring(string str) {
    // Write your code here.
    //We will take each character and grow around that. If it satifies the condition we will find the solution

    int max_sol = 0;
    int left;
    int right;
    int ind;
    for(int i = 0; i < str.length(); i++){
        int max_len = max(solve(str, i, i), solve(str, i, i+1));

        if(max_len > max_sol){

            max_sol = max_len;

            left = i - (max_len-1)/2;
            right = i + max_len/2;
            ind = i;
            // cout<<"New Max Found : "<<max_sol<<" "<<left<<" "<<right<<" "<<i<<endl;
        }

    }

    return str.substr(left, max_sol);
}

