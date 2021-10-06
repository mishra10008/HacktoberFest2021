int Solution::numTrees(int n) {
   if (n == 0)
                return 1;
            if (n == 1)
                return 1;
            int result[n + 1];
            memset(result, 0, sizeof(result));
            result[0] = 1;
            result[1] = 1;
            if (n < 2) {
                return result[n];
            }
            for (int i = 2; i <= n; i++) {
                for (int k = 1; k <= i; k++) {
                    result[i] = result[i] + result[k - 1] * result[i - k];
                }
            }
            return result[n];
}
