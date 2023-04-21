//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct Node{
    Node *child[26];
    Node(){
        
        for(int i=0;i<26;i++)child[i]=NULL;
    }
};

void insert(string &s,Node *root){
    for(int i=0;i<s.size();i++){
        if(root->child[s[i]-'a']){
            root= root->child[s[i]-'a'];
        }else{
            root->child[s[i]-'a'] = new Node();
            root = root->child[s[i]-'a'];
        }
    }
   
}

bool find(Node* root, string &s){
    for(int i=0;i<s.size();i++){
        if(root->child[s[i]-'a']){
            root = root->child[s[i]-'a'];
        }else{
            return false;
        }
    }
    return true;
}

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string>&s2){
        
    Node *t1= new Node(),*t2=new Node();
    
    
    for(auto &it:s1){
        insert(it,t1);
        reverse(it.begin(),it.end());
        insert(it,t2);
    }
    int cnt=0;
    for(auto &it:s2){
        bool ok=false;
        ok|=find(t1,it);
        reverse(it.begin(),it.end());
        ok|=find(t2,it);
        if(ok)cnt++;
    }
    return cnt;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends