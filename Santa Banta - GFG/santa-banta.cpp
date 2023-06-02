//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    vector<int> primes;
public:
    void precompute(){
        int n=1e6;
        vector<bool> ans(n+1,1);
        ans[0]=0;
        ans[1]=0;
    
        for(int i=2;i*i<=n;i++){
            if(ans[i]==1){
    
            for(int j=i*i;j<=n;j+=i){
                ans[j]=0;
            }
            }
    
        }
        int count=0;
        for(int i=2;i<=n;i++){
            if(ans[i]){
                primes.push_back(i);
                
            }
        }
    }
    
    
    
    void dfs(int i,int &cnt,vector<int> adj[],vector<int> &vis){
        vis[i]=1;
        cnt++;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfs(x,cnt,adj,vis);
            }
        }
        return;
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        vector<int> vis(n+1,0);
        vector<int> adj[n+1];
          for(int i=1;i<=n;i++)
        {
           for(auto it: g[i])
          {
              adj[i].push_back(it);
              adj[it].push_back(i);
          }
            
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int cnt=0;
                dfs(i,cnt,adj,vis);
                maxi=max(maxi,cnt);
            }
        }
        if(maxi==1)return -1;
        return primes[maxi-1];
        
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends