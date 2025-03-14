class Solution {
public:
    bool isValid(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];
            diff[l] += x;
            if (r + 1 < n) diff[r + 1] -= x;
        }
        int csum = 0;
        for (int i = 0; i < n; i++) {
            csum += diff[i];
            if (nums[i] > csum) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) return 0;
        int Q = queries.size();
        int left = 0, right = Q - 1, answer = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(nums, queries, mid)) {
                answer = mid + 1;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};
