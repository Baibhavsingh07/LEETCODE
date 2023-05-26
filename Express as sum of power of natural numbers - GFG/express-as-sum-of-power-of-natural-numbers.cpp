//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long f(int i,int n,int x,vector<vector<int>>&dp)
    {
        if(pow(i,x)==n)
        return 1;
        if (pow(i, x) > n)
            return 0;
            if(dp[i][n]!=-1)
            return dp[i][n];
        int nottake=f(i+1,n,x,dp);
        int take=f(i+1,n-pow(i,x),x,dp);
        return dp[i][n]=(nottake+take)%1000000007;
    }
    int numOfWays(int n, int x)
    {
      vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int j=1;
        return f(j,n,x,dp)%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends