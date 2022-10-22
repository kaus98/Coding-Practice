class Solution {
public:
    
    int compareVersion1(string version1, string version2) {
        int i=0,j=0;
        int v1L = version1.length();
        int v2L = version2.length();
        
        while(i < v1L && j < v2L){
            if ( version1[i] == '.' && version2[j] == '.'){
                i++;j++;
                while(version1[i]=='0' && i < v1L) i++;
                while(version2[j]=='0' && j < v2L) j++;
            }
            else {
                if(version1[i] != version2[j]){
                    if((version1[i]-'0') > version2[j] - '0') return 1;
                    else return -1;
                }
                else{
                    i++;j++;
                }
            }
        }
        while(i<v1L){}
        return 0;
    }
    
    
    int compareVersion(string version1, string version2) {
        // This method is failing for Long Strings with large Numbers. Changing to Long Long
        int i=0,j=0;
        while(true){
            long long temp1=0,temp2=0;
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
