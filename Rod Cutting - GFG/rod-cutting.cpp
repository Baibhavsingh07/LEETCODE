//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int solve(int n ,int need,int sum,int price[],vector<int>&dp){
        if(need==0) return sum;
        if(dp[need-1]!= -1) return sum+dp[need-1];
        int maxi=0;
        for(int j=1;j<=need;j++){
            maxi= max(maxi,solve(n,need-j,sum+price[j-1],price,dp));
        }
        dp[need-1]=maxi-sum;
        return maxi;
    }
    int cutRod(int price[], int n) {
        vector<int>dp(n,-1);
        int x =solve(n,n,0,price,dp);
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends