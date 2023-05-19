//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> kthSmallestNum(int n, vector<vector<int>> &range, int q, vector<int> queries)
    {
        // Write your code here
        sort(range.begin(), range.end());
        vector<vector<int>> newRange;

        newRange.push_back(range[0]);
        for (int i = 1; i < range.size(); i++)
        {
            if (range[i][0] <= newRange.back()[1] and newRange.back()[1] <= range[i][1])
                newRange.back()[1] = max(newRange.back()[1], range[i][1]);
            else if (range[i][0] <= newRange.back()[1] and range[i][1] <= newRange.back()[1])
                newRange.back()[1] = max(newRange.back()[1], range[i][1]);
            else
                newRange.push_back(range[i]);
        }

        vector<int> v;
        for (auto i : newRange)
            v.push_back(i[1] - i[0] + 1);

        for (int i = 1; i < v.size(); i++)
            v[i] += v[i - 1];

        vector<int> ans;

        for (auto i : queries)
        {
            int idx = lower_bound(v.begin(), v.end(), i) - v.begin();
            if (idx == v.size())
            {
                ans.push_back(-1);
            }
            else
            {
                int k = i;
                if (idx > 0)
                    k -= v[idx - 1];

                ans.push_back(newRange[idx][0] + k - 1);
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends