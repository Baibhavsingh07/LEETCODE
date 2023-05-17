//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int n, int m, string s){
        int x = 0, y = 0;
        int minx = 0, miny = 0;
        int maxx = 0, maxy = 0;
        
        for(auto i: s) {
            switch(i) {
                case 'L': y--; break;
                case 'R': y++; break;
                case 'U': x++; break;
                case 'D': x--; break;
            }
            
            minx = min(x, minx);
            maxx = max(x, maxx);
            
            miny = min(y, miny);
            maxy = max(y, maxy);
        }
        
        return ((maxx - minx < n) and (maxy - miny < m));
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends