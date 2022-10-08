class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        string nw = "";
        for(int i=0; i<numRows; i++){
            int j=0+i;
            int temp = 0;
            bool flag = false;
            while(true){
                
                if (j >= s.length()) break;
                else {
                    nw.push_back(s[j]);
                    if(i==0 || i==(numRows-1))
                    {
                        j+=(2*numRows-2);
                        cout << "Updated J is : "<< j<<"\n";
                    }
                    else
                    {
                        if (flag){
                            j = temp + i;
                            flag = false;
                        }
                        else{
                            temp+=(2*numRows-2);
                            j = temp-i;
                            flag = true;
                        }

                    }
                }
            }
        }
        return nw;
    }
};
