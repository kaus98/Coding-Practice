vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    // Write your code here.
    vector<int> temp (nums.size()+1, 0);

    for(auto x: nums) temp[x]++;

    vector<int> result(2, 0);
    for(int i = 1; i<=nums.size(); i++){
        if(temp[i] == 2) result[0] = i;
        if(temp[i] == 0) result[1] = i;
    }

    return result;
}