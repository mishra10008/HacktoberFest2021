const int mod = 1000000007;
const int maxn = 100009;
int dp[maxn];
int solve(int index, string & A) {
  if (index >= A.size())
    return 1;
  if (dp[index] != -1)
    return dp[index];
  if (A[index] == '0')
    return dp[index] = 0;
  int ans = solve(index + 1, A);
  ans %= mod;
  if (index + 1 < A.size()) {
    int num = ((A[index] - '0') * 10) + (A[index + 1] - '0');
    if (num >= 10 && num <= 26)
      ans += solve(index + 2, A);
    ans %= mod;
  }
  return dp[index] = ans;
  ans %= mod;
}
int Solution::numDecodings(string A) {
  memset(dp, -1, sizeof(dp));
  return solve(0, A);
}
