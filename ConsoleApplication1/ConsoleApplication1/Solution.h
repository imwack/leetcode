#pragma once

class Solution
{
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) 
	{
		int l = 0, r = arr.size() - 1;
		int find = 0;
		while(l<=r)
		{
			int mid = (l + r) / 2;
			if (arr[mid] == x)
			{
				find = mid;
				break;
			}
			if(arr[mid]<x)
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
	}

	vector<int> findRightInterval(vector<vector<int>>& intervals)
	{
		vector<int> result(intervals.size());
		unordered_map<int, int> map; //
		for (int i = 0; i < intervals.size();i++)
		{
			map[intervals[i][0]] = i;
		}
		sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {return v1[0] < v2[0]; });
		for (int i = 0; i < intervals.size(); i++)
		{
			int start = intervals[i][0];
			int end = intervals[i][1];
			int l = 0, r = intervals.size() - 1;
			int find = r + 1;
			while(l<=r)
			{
				int mid = (l + r) / 2;
				 if(intervals[mid][0]<end)
				 {
					 l = mid + 1;
				 }
				 else
				 {
					 r = mid - 1;
					 find = min(mid, find);
				 }
			}
			if (find != intervals.size())
				result[map[intervals[i][0]]] = (map[intervals[find][0]]);
			else
				result[map[intervals[i][0]]] = -1;

		}
		return result;
	}


	vector<int> partial_sum;
	int sum = 0;
	void pickIndex(vector<int>& w) {
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

