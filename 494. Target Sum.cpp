class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto n:nums)sum+=n;
        if((S+sum)%2!=0) return 0;
        if(sum<S) return 0;
        return help(nums,(S+sum)/2);
    }
    int help(vector<int>& nums,int sum){
        int cnt=0;
        int dp[sum+1]={0};
        dp[0] = 1;
        for(int n:nums){
            for(int i=sum;i>=n;--i){
                dp[i] += dp[i-n];
            }
        }
        return dp[sum];
    }
};