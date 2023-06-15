//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  string ifpalin(string s,int n)
  {
      string temp="";
      int l=0,r=n-1;
    //   cout<<s<<" ";
      while(l<r)
      {
          if(s[l]!=s[r])
          {
              return temp;
          }
          l++;
          r--;
      }
      
      return s;
  }
    string longestPalin (string S) {
        // code here
        int n=S.length();
        string ans="";
        int c=0;
        for (int i=0;i<S.length();i++)
        {
            
            for(int j=n-i+1;j>=1 && j>c ;j--)
            {
                
                string temp=ifpalin(S.substr(i,j),j);
                if(temp.length()>ans.length()) ans=temp,c=temp.length();
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends