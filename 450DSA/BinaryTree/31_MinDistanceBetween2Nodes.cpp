//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int result = -1;
    int leftHeight = 0;
    int rightHeight = 0;
    
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* temp = Kth(root, a, b);
        
        int ah = distanceKth(temp, a, 0);
        int bh = distanceKth(temp, b, 0);
        
        // cout<<"A Height : "<<ah<<endl;
        // cout<<"B Height : "<<bh<<endl;
        // cout<<"Temp : "<<temp->data<<endl;
        return ah+bh;
        
    }
    
    Node* Kth(Node* root, int a, int b){
        if(!root) return NULL;
        
        if(root->data == a){
            return root;
        }
        if(root->data == b){
            return root;
        }
        
        Node* leftH =  Kth(root->left, a,  b);
        Node* rightH =  Kth(root->right, a,  b);
        
    
        
        if(leftH != NULL && rightH != NULL) return root;
        if(leftH != NULL) return leftH;
        if(rightH != NULL) return rightH;
        
        return NULL;
        
    }
    
    int distanceKth(Node *root, int a, int level){
        if(!root) return 0;
        if(root->data == a) return level;
        
        int leftH = distanceKth(root->left, a, level+1);
        int rightH = distanceKth(root->right, a, level+1);
        return max(leftH, rightH);
    }
    
    int minH(int a, int b){
        if(a==NULL && b==NULL) return NULL;
        if(a==NULL) return b+1;
        if(b==NULL) return a+1;
        return min(a,b)+1;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends