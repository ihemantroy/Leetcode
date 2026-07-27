class Solution {
public:
    int solve(int i, string &s, vector<int> &dp)
    {
        // Reached the end -> one valid decoding
        if(i == s.size())
            return 1;

        // Strings starting with '0' are invalid
        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // Take one digit
        int ways = solve(i + 1, s, dp);

        // Take two digits if valid (10 to 26)
        if(i + 1 < s.size())
        {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            if(num >= 10 && num <= 26)
                ways += solve(i + 2, s, dp);
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, dp);
    }
};