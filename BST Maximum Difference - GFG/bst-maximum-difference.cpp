//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   int maxdiff(Node *cur, int sum, int tempsum) {
        
        int l=INT_MIN, r=INT_MIN;
        if(cur->left) {
           l=maxdiff(cur->left,sum,tempsum+cur->data);
        }
        if(cur->right) {
           r=maxdiff(cur->right,sum,tempsum+cur->data);
        }
        if(!cur->left and !cur->right) {
            return sum-(tempsum+cur->data);
        }
        return max(l,r);
    }
    Node* findtarget(Node *cur, int target, int &sum) {
        
        if(cur==NULL) return NULL;
        
        sum+=cur->data;
        
        if(target<cur->data) {
           return findtarget(cur->left,target,sum);
        }
        else if(target>cur->data) {
           return findtarget(cur->right,target,sum);
        }
        else {
            return cur;
        }
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int sum=0;
        Node* ans=findtarget(root,target,sum);
        if(ans==NULL) return -1;
        return maxdiff(ans,sum,0);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends