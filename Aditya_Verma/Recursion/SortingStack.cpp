// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;

void insertion(stack<int>& nums, int temp){

        if (nums.size() == 0) {nums.push(temp); return;}
        if (nums.top() >= temp) {nums.push(temp); return;}

        
        int x = nums.top();
        nums.pop();
        insertion(nums, temp);
        nums.push(x);

    };
void sorting(stack<int>& nums){
        if (nums.size() == 1) return;
        
        int temp = nums.top();
        nums.pop();
        sorting(nums);
        insertion(nums, temp);
    };


int main() {
    // Write C++ code here
    std::cout << "Hello world!";
    stack<int> ans;
    ans.push(5);
    ans.push(4);
    ans.push(6);
    ans.push(1);
    ans.push(8);
    ans.push(0);
    
    
    sorting(ans);
    
    while(!ans.empty())
    {
        int w = ans.top();
        cout << w;
        ans.pop();
    }

    return 0;
}
