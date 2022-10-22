class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i=0,j=0;
        while(true){
            int temp1=0,temp2=0;
            if(i>=version1.length() && j >= version2.length()) return 0;
            while(i< version1.length() && version1[i] != '.'){
                temp1 = temp1*10 + version1[i] - '0';
                i++;
            }
            while(j< version2.length() && version2[j] != '.'){
                temp2 = temp2*10 + version2[j] - '0';
                j++;
            }
            if (temp1>temp2) return 1;
            else if (temp1<temp2) return -1;
            i++;
            j++;
        }
    }
};
