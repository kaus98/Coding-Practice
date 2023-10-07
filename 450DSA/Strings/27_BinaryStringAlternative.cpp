int makeBeautiful(string str) {
	// Write your code here

	// There are 2 posibble scenerios
	// 101010....
	// 010101....

	int count0 = 0;
	int count1 = 0;

	for(int i = 0; i < str.length(); i++){
		if(i%2 == 0){
			if(str[i] == '1') count0++;
			else count1++;
		} else {
			if(str[i] == '1') count1++;
			else count0++;
		}
	}

	return min(count1, count0);
}