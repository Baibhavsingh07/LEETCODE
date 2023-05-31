//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int a = INT_MAX,b=0;
        for(auto i: m){
            if(i.second<=a && b<i.first){
                a= i.second;
                b= i.first;
            }
        }
        return b;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends