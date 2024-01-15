int solve(vector<int> &cost, int idx, int leftMoney, vector<vector<int>> &dp)
{
    // out of bound
    if (idx == cost.size())
        return 0;

    // if ans already exists
    if (dp[idx][leftMoney] != -1)
        return dp[idx][leftMoney];

    int take = 0, notTake = 0;

    notTake = solve(cost, idx + 1, leftMoney, dp);
    // take if possible           [leftMoney = currMoney - (curMoney - 90% of  cost[idx])]
    if (leftMoney >= cost[idx])
    {
        take = 1 + solve(cost, idx + 1, leftMoney - cost[idx] + floor(0.9 * cost[idx]), dp);
    }

    return dp[idx][leftMoney] = max(take, notTake);
}

public:
int max_courses(int n, int total, vector<int> &cost)
{
    // Code Here
    vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));
    int ans = solve(cost, 0, total, dp);

    return ans;
}