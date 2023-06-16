//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    #define ll long long
    unordered_map<ll, pair<ll, ll>> mp;
    vector<int> typs;
    ll dp[100004][3];
public:
    ll solve(int i, int j) {
        ll pos = 0;
        
        if(j == 0)
            pos = mp[typs[i - 1]].first; // going left need last right most location
        else if(j == 1)
            pos = mp[typs[i - 1]].second; // going right need last left most location
            
        if(i == typs.size())
            return abs(pos);
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        ll ans = 1e18, dist = abs(mp[typs[i]].second - mp[typs[i]].first);
        
        ans = min(ans, dist + abs(mp[typs[i]].first - pos) + solve(i + 1, 1));
        ans = min(ans, dist + abs(mp[typs[i]].second - pos) + solve(i + 1, 0));
        
        return dp[i][j] = ans;
    } 

    ll minTime(int n, vector<int> &locations, vector<int> &types) {
        for(int i = 0; i < n; i++) {
            int loc = locations[i], ty = types[i];

            if(mp.count(ty)) {
                int s = mp[ty].first, e = mp[ty].second;
                s = min(s, loc), e = max(e, loc);
                mp[ty] = {s, e};
            } else
                mp[ty] = {loc, loc};
        }
        
        for(auto i: mp) typs.push_back(i.first);
        sort(typs.begin(), typs.end());
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 2); // 0->left, 1->right;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends