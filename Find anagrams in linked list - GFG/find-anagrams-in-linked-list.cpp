//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
   vector<Node*> findAnagrams(struct Node* head, string s) {

        // code here

        vector<char>ans;

        Node* temp=head;

        while(temp!=NULL)

        {

         ans.push_back(temp->data);

         temp=temp->next;

        }

        int h=s.length();

        int arr[26]={0};

        for(int i=0;i<h;i++)

        {

            arr[s[i]-'a']++;

        }

        bool t=false;

        vector<Node*>mera;

        for(int i=0;i<ans.size();i++)

        {

            if(arr[ans[i]-'a']>0)

            {

                int arr1[26]={0};

                if(i+h>ans.size())

                {

                    break;

                }

                for(int j=i;j<i+h;j++)

                {

                    arr1[ans[j]-'a']++;

                }

                for(int i1=0;i1<26;i1++)

                {

                    if(arr[i1]!=arr1[i1])

                    {

                        arr1[0]=-1;

                        break;

                    }

                }

                if(arr1[0]!=-1)

                {

                    

                    Node* kal=new Node(ans[i]);

                    Node* tempo=kal;

                    for(int j=i+1;j<i+h;j++)

                    {

                        Node *pal=new Node(ans[j]);

                        tempo->next=pal;

                        tempo=tempo->next;

                    }

                    t=true;

                    mera.push_back(kal);

                    i=i+h-1;

                }

            }

            

        }

     

        return mera;

    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends