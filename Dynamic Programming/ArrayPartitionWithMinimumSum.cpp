int minSubsetSumDifference(vector<int>& arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int k = sum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Initialize the dp array
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= k) dp[0][arr[0]] = true;

    // Fill the dp array
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            bool notPick = dp[i - 1][j];
            bool pick = false;
            if (j >= arr[i]) pick = dp[i - 1][j - arr[i]];
            dp[i][j] = pick || notPick;
        }
    }

    // Find the minimum difference
    int mini = INT_MAX;
    for (int i = 0; i <= sum / 2; i++) {
        if (dp[n - 1][i]) {
            mini = min(mini, abs(i - (sum - i)));
        }
    }
    return mini;
}
