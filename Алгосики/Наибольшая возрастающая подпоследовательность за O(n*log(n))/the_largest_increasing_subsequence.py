n, m = map(int, input().split())
dp = [[0] * 9 for i in range(9)]
dp[m][n] = 1
for i in range(m + 1, 9):
    for j in range(1, 9):
        if j - 1 > 0 and j + 1 < 9:
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]
        elif j - 1 > 0:
            dp[i][j] = dp[i - 1][j - 1]
        elif j + 1 < 9:
            dp[i][j] = dp[i - 1][j + 1]
print(sum(dp[8]))