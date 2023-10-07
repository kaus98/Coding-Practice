bool isValidParenthesis(string s)
{
    // Write your code here.

    int i = 0;
    int j = 0;
    int k = 0;
    for(int x = 0; x < s.length(); x++){

        if(s[x] == '(') 
          i++;
        else if (s[x] == '{')
          j++;
        else if (s[x] == '[')
          k++;
        else if (s[x] == ')')
          i--;
        else if (s[x] == '}')
          j--;
        // else if(s[x]== ']') 
        else k--; 

        if(i < 0 || j < 0 || k < 0) return false;
        
    }
    return true;
}