
void remove(string &arr, char a){
    if(arr.size()>0 && arr[arr.size()-1] != a){
        arr.push_back(a);
    } else if(arr.size() == 0){
        arr.push_back(a);
    }
}

string removeDuplicate(string &s)
{
    // Write your code here
    string temp;

    for(int i = 0; i < s.size(); i++){
        remove(temp, s[i]);
    }

    return temp;
}
