
int minCharsforPalindrome(string str) {
	// Write your code here.

	int start = 0;
	int end = str.size()-1;

	while(end>0){
		int j = end;
		start = 0;

		while(j>start){
			if(str[j] != str[start]){
				// j--;
				break;

			}
			start++;
			j--;
		}
		if(j <= start) { return str.size()-end-1;}
		end--;
	}	
	return str.size()-1;
}
