//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            long N;
            N = Long.parseLong(br.readLine().trim());
            
            Solution obj = new Solution();
            long res = obj.countBits(N);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static long countBits(long N) {
        long count=0;
        for(long i=1;i<=N;i++){
            count+=setBits(i);
        }
        return count;
    }
    public static long setBits(long num) {
        int count = 0;
      while (num > 0){
         num &= (num - 1);
         count++;
      }
      return count;
    }
}
        
