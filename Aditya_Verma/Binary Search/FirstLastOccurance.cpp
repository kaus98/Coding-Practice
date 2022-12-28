#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

int SearchFirstBinarySearch(vector<int> arr, int search, int head, int tail){
    cout<<"Searching for First. Head : "<<head<<" Tail : "<<tail<<endl;
    if(head == tail) return head;
    int temp = (head + tail)/2;
    if(arr[temp] == search) return SearchFirstBinarySearch(arr, search, head, temp);
    if(arr[temp]<search) return SearchFirstBinarySearch(arr, search, temp+1, tail);
    return -1;
}


int SearchLastBinarySearch(vector<int> arr, int search, int head, int tail){
    cout<<"Searching for Last. Head : "<<head<<" Tail : "<<tail<<endl;
    if(head == tail) return head;
    int temp = floor((head + tail)/2);
    if(arr[temp] == search){
        if(arr[temp+1] == search) return SearchLastBinarySearch(arr, search, temp, tail);
        else return temp;
    } 
    if(arr[temp] > search) return SearchLastBinarySearch(arr, search, head, temp);
    return -1;
}

int BinarySearch(vector<int> arr, int search, int head, int tail){
    
    if(head > tail) return -1;
    if(head == tail) {
        if(arr[head] == search) return head;
        else return -1;
        }

        
    int bin  = (head + tail)/2;

    if(arr[bin] > search) return BinarySearch(arr, search, head, bin);
    if(arr[bin] == search) {
        cout<< "Searching for First OCR. Head : "<<head<<" And Bin : "<<bin<<endl;
        int first =  SearchFirstBinarySearch(arr, search, head, bin);

        cout<< "Searching for Last OCR. Head : "<<bin<<" And Bin : "<<tail<<endl;
        int last =  SearchLastBinarySearch(arr, search, bin, tail);

        return last-first + 1;
    }
    if(arr[bin] < search) return BinarySearch(arr, search, bin+1, tail);

    return -1;
}

int main(){
    vector<int> arr = {1,3,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,9,12,16,19,25,31,53,62,72,83,92,100};
    int result;

    result = BinarySearch(arr, 7, 0, arr.size());
    cout<< "Count is : "<<result<<endl;


    return -1;
}