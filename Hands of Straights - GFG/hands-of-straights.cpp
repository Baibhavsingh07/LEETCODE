//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand)
    {
        // base case : less or more no of cards we have
        if (N%groupSize != 0)
            return false;
        
        // trivial case 
        if(groupSize == 1)
            return true;

        map<int, int> count;

        // counting elements
        for (int i : hand)
            count[i]++;

        // for each element x there must exist x+1 except for the greatest element
        int largest = count.end()->first;

        while (!count.empty())
        {
            int ele = count.begin()->first;
            int cnt = count.begin()->second;
            
            // if last element exists more than 1 times then it must be balanced by previous elements
            // and only 1 occurance can be left unbalanced as it can be the terminating one
            if(ele == largest)
            {
                return cnt <= 1;
            }
            
            // find ele+1
            if (count.find(ele + 1) != count.end())
            {
                // it cant be balanced
                if (cnt - count[ele + 1] > 0)
                    return false;
                else
                {
                    // ele can balance ele+1 as ele+1 may be the terminal of any group
                    count[ele + 1] -= cnt;
                }

                count.erase(ele); // delete
            }
            else if(cnt <= 0)
            {
                count.erase(ele); // delete
            }
            else
                return false;
        }

        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends