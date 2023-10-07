vector<int> stringMatch2(string text, string pattern) {
	// Write your code here.
	// This the pattern for Basic Searching

	vector<int> result;

	for(int i = 0; i < (text.size() - pattern.size() + 1); i++){
		// int  j = 0;
		int j;
		for(j = 0; j < pattern.size(); j++){
			if(text[i+j] != pattern[j]) break;
		}
		if(j==pattern.size()) 
			result.push_back(i+1);
	}
	return result;
}

bool check(string text , string pattern, int i){
	int j = 0;
	while(j < pattern.size()) if(text[i+j] != pattern[j++]) return false;
	return true;
}

vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	// This the pattern for Basic Searching

	vector<int> result;

	int has_pat = 0;
	int has_text = 0;
	for(int i = 0; i < pattern.size(); i++){
		has_pat += (pattern[i] - '0');
		has_text += (text[i] - '0');
	}

	if(has_pat == has_text && check(text, pattern, 0)) result.push_back(1);

	int start = 0;
	int end = pattern.size();
	while(end < text.size()){
		has_text -= (text[start++] - '0');
		has_text += (text[end++] - '0');
		if(has_pat == has_text && check(text, pattern, start)) result.push_back(start+1);
	}
	return result;
}
