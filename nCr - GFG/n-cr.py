#User function Template for python3

class Solution:
    def nCr(self, n, r):
        if(n>=r):
            import math
            k=math.factorial(n)
            l=(math.factorial(n-r))*(math.factorial(r))
            ans=k//l
        if(n>=r and ans<(10**9)):
            return (ans)
        elif(n>=r and ans>(10**9)):
            return (ans%((10**9)+7))
        else:
            return (0)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, r = [int(x) for x in input().split()]
        
        ob = Solution()
        print(ob.nCr(n, r))
# } Driver Code Ends