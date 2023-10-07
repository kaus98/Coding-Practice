//Merge the string and look for first string

int isCyclicRotation(string &p, string &q) 
{
    // Write your code here

    if (p.size() != q.size()) return 0;
    string res = p+p;
    if(res.find(q) != string::npos) return 1;
    return 0;

}