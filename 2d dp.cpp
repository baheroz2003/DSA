#problem 1:ninja training/paint house 
class Solution {
public:
    int f(int day, int last, vector<vector<int>>& pts, vector<vector<int>>& dp) {
        if(day == 0) {
            int maxi = 0;
            for(int t=0; t<3; t++) if(t != last) maxi = max(maxi, pts[0][t]);
            return maxi;
        }
        if(dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for(int t=0; t<3; t++) if(t != last)
            maxi = max(maxi, pts[day][t] + f(day-1, t, pts, dp));

        return dp[day][last] = maxi;
    }

    int ninjaTraining(int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n-1, 3, points, dp);
    }
};
