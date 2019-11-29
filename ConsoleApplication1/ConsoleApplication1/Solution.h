#pragma once
class Solution
{
public:
	vector<int> partial_sum;
	int sum = 0;
	Solution(vector<int>& w) {
		for (int x : w) {
			sum += x;
			partial_sum.push_back(sum);
		}

	}

	int pickIndex() {
		int n = rand() % sum;
		int l = 0, r = partial_sum.size() - 1;
		while(l<=r)
		{
			int mid = (l + r) / 2;
			if (n >= partial_sum[mid]) l = mid + 1;
			else r = mid;
		}
		return l;
	}

	vector<int> maxDepthAfterSplit(string seq) 
	{
		int left = 0;
		vector<int> result;
		int lMax = 0;
		for(char c: seq)
		{
			if(c == '(')
			{
				result.push_back(left);
				lMax = max(lMax, lMax);
				left++;
			}
			else
			{
				left--;
				result.push_back(max(lMax,left));
				lMax = left;
			}
		}
		return result;
	}

	int findLength(vector<int>& A, vector<int>& B) 
	{
		int maxLen = 0;
		vector<vector<int>> dp(A.size());
		for (int i = 0; i < A.size();i++)
		{
			dp[i] = vector<int>(B.size());
		}
		for (int i = 0; i < A.size();i++)
		{
			if (A[i] == B[0])
				dp[i][0] = 1;
		}
		for (int i = 0; i < B.size(); i++)
		{
			if (B[i] == A[0])
				dp[0][i] = 1;
		}
		for (int i = 1; i < A.size();i++)
		{
			for (int j = 1; j < B.size();j++)
			{
				if (A[i] == B[j]) 
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					maxLen = max(maxLen, dp[i][j]);
				}
			}
		}
		return maxLen;
	}
	int search(vector<int>& nums, int target) 
	{
		int l = 0, r = nums.size()-1;
		while(l<=r)
		{
			int mid = (l + r) / 2;
			if(nums[mid] == target)
			{
				return mid;
			}
			else if(nums[mid]<target)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		return -1;
	}
};

