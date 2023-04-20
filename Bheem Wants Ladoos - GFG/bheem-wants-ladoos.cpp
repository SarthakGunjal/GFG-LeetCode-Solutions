//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/


class Solution{

    public:
    
    
    
   int ans;
    void make_mat(Node* root,  map<int,vector<int>> &adj){
        
        if(root->left!=NULL){
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
            make_mat(root->left, adj);
        }
        if(root->right!=NULL){
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
              make_mat(root->right, adj);
        }
        
        
    }
    void dfs(int node,int dept,int k, map<int,vector<int>> &adj,map<int,bool>&vis){
        vis[node]=true;
        if(dept<=k)
            ans+=node;
   
        for(auto child : adj[node]){
            if(!vis[child] and dept+1<=k){
                dfs(child,dept+1,k,adj,vis);
            }
        }
    }
    
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        map<int,vector<int>>adj;
        map<int,bool>vis;
        ans=0;
        make_mat(root,adj);
        
       
        dfs(home,0,k,adj,vis);
        
        return ans;
        
        
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends