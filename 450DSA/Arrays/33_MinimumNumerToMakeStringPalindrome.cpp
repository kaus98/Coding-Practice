class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        
        int i = 0; int j = s.length()-1;

        int count = 0;
        while( i < j){
            // If both sides are equal
            if (s[i] == s[j]){
                i++;
                j--;
            }
            else {
                //Check the left side of palindrome for swaps

                int left = i+1;
                while(left < j){
                    if(s[j] == s[left]) break;
                    left++;
                }

                //Check the right side of palindrome for swaps

                int right = j-1;
                while(right > i){
                    if(s[right] == s[i])break;
                    right--;
                }
                //Should swap start with left or right
                if ((left - i) < (j-right)){
                    //Going with left side swap 
                    while(s[i] != s[j]){
                        swap(s[left], s[left-1]);
                        left--;
                        count++;
                    }
                }
                else{
                    //Going with right side swap
                    while(s[i] != s[j]){
                        swap(s[right], s[right+1]);
                        right++;
                        count++;
                    }
                }

            }

        }

        return count;
    }
};