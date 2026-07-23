// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

class Solution {
public:
    int calculate_profit(vector<int>& prices, int buy, int i, int n, vector<vector<int>> &dp) {
        if (i>=n) {
            return 0;
        }

        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int profit = 0;

        if (buy == 1) {
            profit = max(-prices[i]+calculate_profit(prices, 0, i+1, n, dp), calculate_profit(prices, 1, i+1, n, dp));
        } else {
            profit = max(prices[i]+calculate_profit(prices, 1, i+2, n, dp), calculate_profit(prices, 0, i+1, n, dp));
        }


        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));

        return calculate_profit(prices, 1, 0, n, dp);
    }
};