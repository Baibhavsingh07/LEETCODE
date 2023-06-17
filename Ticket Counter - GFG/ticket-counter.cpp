//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void reverseQueue(queue<int>& qt)
{
    stack<int> Stack;
    while (!qt.empty()) {
        Stack.push(qt.front());
        qt.pop();
    }
    while (!Stack.empty()) {
        qt.push(Stack.top());
        Stack.pop();
    }
}
    int distributeTicket(int N, int K) {
        // code here
        queue<int> qt;
        for(int i=1;i<=N;i++){
            qt.push(i);
        }
       int s= qt.size();
       while(s>K){
           for(int i=0;i<K;i++) qt.pop();
           s=qt.size();
           reverseQueue(qt);
       }       
       reverseQueue(qt);
       return qt.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends