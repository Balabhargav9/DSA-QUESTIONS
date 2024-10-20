class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        vector<int> f(26, 0);
        int ans = 0, n = s.size(), left = 0;

        for (int right = 0; right < n; ++right) {
            f[s[right] - 'a']++; 
        
            while (*max_element(f.begin(), f.end()) >= k) {
                ans += n - right; 
                f[s[left] - 'a']--; 
                left++; 
            }
        }
        return ans;
    }
};
