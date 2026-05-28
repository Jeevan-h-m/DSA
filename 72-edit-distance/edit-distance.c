int minDistance(char* word1, char* word2) {

    int m = strlen(word1);
    int n = strlen(word2);

    int dp[n + 1];

    // Initialize first row
    for (int j = 0; j <= n; j++) {
        dp[j] = j;
    }

    for (int i = 1; i <= m; i++) {

        int prev = dp[0];
        dp[0] = i;

        for (int j = 1; j <= n; j++) {

            int temp = dp[j];

            if (word1[i - 1] == word2[j - 1]) {
                dp[j] = prev;
            }
            else {

                int min = dp[j];

                if (dp[j - 1] < min)
                    min = dp[j - 1];

                if (prev < min)
                    min = prev;

                dp[j] = 1 + min;
            }

            prev = temp;
        }
    }

    return dp[n];
}