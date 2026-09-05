class Solution {
public:
    int solve(vector<int>& nums, int target, int index,
              vector<vector<int>>& dp) {

        int n = nums.size();

        // agar target 0 ho gaya to koi operation nahi chahiye
        if (target == 0)
            return 0;

        // agar saare elements check ho gaye aur target abhi bhi bacha hai
        if (index == n)
            return 1e9;

        // agar current state pehle se calculate ho chuki hai
        if (dp[index][target] != -1)
            return dp[index][target];

        // current element ko nahi lena
        int notTake = solve(nums, target, index + 1, dp);

        int take = 1e9;

        int currentValue = nums[index];
        int operations = 0;

        // current value ko double karke target ke andar possible values try
        // karo
        while (currentValue <= target) {

            take = min(take, operations + solve(nums, target - currentValue,
                                                index + 1, dp));

            operations++;
            currentValue = currentValue * 2;
        }

        currentValue = nums[index];
        operations = 0;

        // current value ko half karte hue possible values check karo
        while (currentValue > 0) {

            int has_odd = 0;

            // agar current value target se chhoti ya equal hai
            if (target >= currentValue) {
                take = min(take, operations + solve(nums, target - currentValue,
                                                    index + 1, dp));
            }

            operations++;

            // agar current value odd hai to half karne ke baad
            // uske baad doubling wale options bhi check karne hain
            if (currentValue % 2 != 0) {
                has_odd = 1;
            }

            currentValue /= 2;

            int nextValue = currentValue;
            int nextOperations = operations;

            // odd value ke case mein half value se dobara double karke
            // saare possible options check karo
            while (has_odd == 1 and nextValue != 0 and nextValue <= target) {

                take =
                    min(take, nextOperations + solve(nums, target - nextValue,
                                                     index + 1, dp));

                nextOperations++;
                nextValue = nextValue * 2;
            }
        }

        // current element ko lena ya skip karna, dono mein minimum answer
        return dp[index][target] = min(take, notTake);
    }

    int minOperations(vector<int>& nums, int sum) {

        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));

        int answer = solve(nums, sum, 0, dp);

        // agar answer infinity hai to target banana possible nahi hai
        if (answer >= 1e9)
            return -1;

        return answer;
    }
};
