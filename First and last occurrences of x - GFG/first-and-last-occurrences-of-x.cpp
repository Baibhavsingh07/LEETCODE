//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int first(int a[],int n,int k){
        int h=n-1;
        int l=0;
        int ans=-1;
        
        while(l<=h){
            int m=l+(h-l)/2;
            if(a[m]==k){
                ans=m;
                h=m-1;
            } else if(a[m]>k){
                h=m-1;
            } else{
                l=m+1;
            }
        }
        return ans;
    }
    
    int last(int a[],int n,int k){
        int h=n-1;
        int l=0;
        int ans=-1;
        
        while(l<=h){
            int m=l+(h-l)/2;
            if(a[m]==k){
                ans=m;
                l=m+1;
            } else if(a[m]>k){
                h=m-1;
            } else{
                l=m+1;
            }
        }
        return ans;
    }
    
    vector<int> find(int a[], int n , int x )
    {
        vector<int>v(2,-1);
        
        v[0]=first(a,n,x);
        v[1]=last(a,n,x);
        
        return v;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends