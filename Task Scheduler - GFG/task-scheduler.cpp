//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int k, vector<char> &tasks) {
        // code here
        vector<int> v(26,0);
        for(auto x:tasks)++v[x-'A'];
        int n=*max_element(v.begin(),v.end());
        int f=0, res=(n-1)*k+n;
        for(int i=0;i<26;++i)
        {
            if(v[i]<n)continue;
            if(v[i]==n&&f==0)f=1;
            else if(v[i]==n)
            {
                ++res;
            }
        }
        return max(res,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends