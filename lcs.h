#include <iostream>
#include <algorithm>
#include <vector>

// largest common subsequence

namespace algo{
    template <typename T >
    int LCS(std::vector<T> lhs, std::vector<T> rhs){
        size_t n = lhs.size(), m = rhs.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int> (m + 1));
        for (int i = 1; i < n + 1; ++i){
            for (int j = 1; j < m + 1; ++j){
                if (lhs[i] == rhs[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
}
