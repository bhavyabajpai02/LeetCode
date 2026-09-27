class Solution {
public:
    bool check(vector<int>& chars, vector<int>& compare) {
        for(int i = 0; i < 128; i++) {
            if(chars[i] > compare[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        if(t.empty() || s.empty())
            return "";

        vector<int> chars(128, 0);
        vector<int> compare(128, 0);

        for(char c : t)
            chars[c]++;

        int min_len = INT_MAX;
        int start = 0;
        int left = 0;

        for(int i = 0; i < s.length(); i++) {
            compare[s[i]]++;
            while(left <= i && check(chars, compare)) {
                if(i - left + 1 < min_len) {
                    min_len = i - left + 1;
                    start = left;
                }
                compare[s[left]]--;
                left++;
            }
        }
        if(min_len == INT_MAX)
            return "";
        return s.substr(start, min_len);
    }
};