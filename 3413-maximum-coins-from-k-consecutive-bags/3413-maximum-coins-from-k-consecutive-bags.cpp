
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());

        int n = coins.size();
        long long ans = 0;
        long long currentSum = 0;

        // Case 1: Window starts at coins[i][0]
        for (int i = 0, j = 0; i < n; i++) {

            while (j < n && coins[j][1] <= coins[i][0] + k - 1) {
                currentSum += (long long)(coins[j][1] - coins[j][0] + 1)* coins[j][2];
                j++;
            }

            if (j < n) {
                long long partial = max(0LL,
                    (long long)(coins[i][0] + k - coins[j][0])* coins[j][2]);
                
                ans = max(ans, currentSum + partial);
            }

            currentSum -= (long long)(coins[i][1] - coins[i][0] + 1)* coins[i][2];
        }

        // Case 2: Window ends at coins[i][1]
        currentSum = 0;

        for (int i = 0, j = 0; i < n; i++) {

            currentSum += (long long)(coins[i][1] - coins[i][0] + 1)* coins[i][2];

            while (j < n && coins[j][1] < coins[i][1] - k + 1) {
                currentSum -= (long long)(coins[j][1] - coins[j][0] + 1)* coins[j][2];
                j++;
            }

            long long partial = max(0LL,
                (long long)(coins[i][1] - k + 1 - coins[j][0])* coins[j][2]);

            ans = max(ans, currentSum - partial);
        }

        return ans;
    }
};
