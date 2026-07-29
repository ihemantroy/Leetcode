class Solution {
public:
    static const long long LIM = 1000000LL + 5;

    long long combCap(int n, int r, long long cap) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        __int128 ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= cap) return cap;
        }

        return (long long)ans;
    }

    long long countWays(vector<int>& cnt, long long cap) {
        int total = 0;
        for (int x : cnt) total += x;

        long long res = 1;
        int remain = total;

        for (int c : cnt) {
            if (c == 0) continue;

            long long cur = combCap(remain, c, cap);

            __int128 val = (__int128)res * cur;
            if (val >= cap) return cap;

            res = (long long)val;
            remain -= c;
        }

        return min(res, cap);
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        char mid = 0;
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1) mid = char('a' + i);
        }

        string left;

        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {

            bool found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countWays(half, k);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    found = true;
                    break;
                }

                k -= ways;
                half[c]++;
            }

            if (!found) return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;

        return left + right;
    }
};