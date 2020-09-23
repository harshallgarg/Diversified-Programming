class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.empty())
            return string();

        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        // memset(dp, 0, sizeof(dp));

        int start = 0, max_length = 1;

        for (int i = 0; i < s.length(); i++)
        {
            dp[i][i] = true;
        }

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                max_length = 2;
            }
        }

        for (int k = 3; k <= s.length(); k++)
        {
            for (int i = 0; i <= s.length() - k; i++)
            {
                int j = i + k - 1;
                if (s[i] == s[j] and dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    if (k > max_length)
                    {
                        start = i;
                        max_length = k;
                    }
                }
            }
        }

        return s.substr(start, max_length);
    }
};