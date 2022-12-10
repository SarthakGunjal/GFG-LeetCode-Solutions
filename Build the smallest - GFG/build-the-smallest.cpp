//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)

{

    //code here.

    string ans="";

    stack<int> st;

    

    for(int i=0; i<num.length();i++){

        if(st.empty()==true && num[i]=='0'){

            continue;

        }

        

        if((st.empty()==false && st.top()>int(num[i]-'0') ) && k) {

            while(st.empty()==false && st.top()>int(num[i]-'0') && k){

            st.pop();

            k--;

            }

            

            if(st.empty()==true && num[i]=='0') continue;

            else {

                st.push(int(num[i]-'0'));

            }

              

            

        }

        

        else {

            st.push(int(num[i]-'0'));

        }

       

    }

    

    while(k && st.empty()==false){

        st.pop();

        k--;

    }

    

    while(st.empty()==false){

             ans+=to_string(st.top());

             st.pop();

    }

    

    reverse(ans.begin(),ans.end());

    

    

    

    return ans.length()==0 ? "0" : ans;

}