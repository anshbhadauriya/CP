class Solution {
public:

//This works because of Zeckendorf's Theorem:
// Every positive integer can be represented as the sum of distinct non-consecutive Fibonacci numbers, and the greedy choice always leads to the optimal answer.


    int findMinFibonacciNumbers(int k) {
        vector<int>fibo;

        fibo.push_back(1);
        fibo.push_back(1);

        while(fibo.back()<=k){
            int n=fibo.size();
            fibo.push_back(fibo[n-1]+fibo[n-2]);
        }
        int count=0;
        int n=fibo.size();
        for(int i=n-1;i>=0;i--){
            if(fibo[i]<=k){
                k=k-fibo[i];
                ++count;
            }
            if(k==0) break;
        }

        return count;
        
        
    }
};
