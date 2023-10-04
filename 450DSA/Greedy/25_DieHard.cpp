#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    while(n--){
        int h,a;

        cin>>h>>a;
        bool start = true;
        int count = 0;
        while(true){
            count++;
            if(start){
                //Step to Air
                h+=3;
                a+=2;
                start=!start;
            } else{
                if(h>=20){
                    //Step to fire
                    h-=20;
                    a+=5;
                } else if(h>=5 && a >= 10){
                    //Step to Water
                    a-=10;
                    h-=5;
                } else break;
            }

        }
        cout<<count<<endl;
    }
}