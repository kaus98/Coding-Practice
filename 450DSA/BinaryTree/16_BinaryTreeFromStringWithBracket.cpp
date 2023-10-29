//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    
    int getdigits(string str, int i){
        int j = i;
        
        while(j<str.size()){
            if(str[j] == '(' || str[j] == ')') {return j-1;}
            j++;
        }
        return j;
    }
    
    int getdigits2(string str, int i, int j){
        string sub = str.substr(i , j-i+1);
        return stoi(sub);
    }
    
    
    Node *treeFromString(string str){
        // code here
        
        stack<Node *> st;
        int i = 0;
        
        int j = getdigits(str, 0);
        Node* root;
        Node* temp;
        root = new Node(getdigits2(str, 0, j));
        
        
        st.push(root);
        i = j+1;
        
        while(i < str.size()){
            if(str[i] == '('){
                
                int j = getdigits(str, i+1);
                temp = new Node(getdigits2(str, i+1, j));
                
                if(st.top()->left == NULL){
                    st.top()->left = temp;
                }else{
                    st.top()->right = temp;
                }
                st.push(temp);
                i = j;    
            } else if(str[i]==')'){
                //Closing the document here
                st.pop();
                
            }
            i++;
            
        }
        return root;
        
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends