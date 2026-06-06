class Solution {
public:
    int start = 0, maxLen = 1;

    bool solve(string& s, int l, int r, vector<vector<int>>& dp) {
        if (l >= r) return true;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] == s[r] && solve(s, l + 1, r - 1, dp)) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            return dp[l][r] = true;
        }

        return dp[l][r] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                solve(s, l, r, dp);
            }
        }

        return s.substr(start, maxLen);
    }
};