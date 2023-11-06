//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           //Create a priority Queue and insert first data of each to it
        
           priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
           
           for(int i = 0; i < K; i++){
               pq.push({arr[i]->data, i});
           }
           
           Node * top = NULL;
           Node * end = NULL;
           
          pair<int, int> temp;
           while(!pq.empty()){
               temp = pq.top();
               pq.pop();
               if(end == NULL){
                   //First node
                   top = arr[temp.second];
                   end = arr[temp.second];
                //   arr[temp.second] = arr[temp.second]->next;
               } else {
                   end->next = arr[temp.second];
                   end = end->next;
               }
               
               if(arr[temp.second]->next != NULL){
                   arr[temp.second] = arr[temp.second]->next;
                   pq.push({arr[temp.second]->data, temp.second});
               }
               
               
           }
           
           end->next = NULL;
           
           return top;
           
           
        //   top->data = 
           
           
    }
    
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends