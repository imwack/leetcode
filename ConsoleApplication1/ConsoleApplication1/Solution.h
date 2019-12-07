#pragma once

class Solution
{
public:
	int sum = 0;

	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
		
	};



	void MergeSort(vector<int> &v)
	{
		MergeSortInneer(v, 0, v.size());
	}
	void MergeSortInneer(vector<int> &v, int l, int r)
	{
		if (l >= r) return;
		if(l<r)
		{
			int mid = (l + r) / 2;
			MergeSortInneer(v, l, mid);
			MergeSortInneer(v, mid + 1, r);
			Merge(v, l, mid, r);
		}
	}
	void Merge(vector<int> &v, int l, int mid, int r)
	{
		vector<int> a(v.begin() + l, v.begin() + mid);
		vector<int> b(v.begin() + mid+1 , v.begin() + r);
		int i = l, i1 = l, i2 = mid + 1;
		while(i1<=mid && i2<=r)
		{
			if (a[i1] < b[i2]) v[i++] = a[i1++];
			else v[i++] = b[i2++];
		}
		while (i1 <= mid) v[i++] = a[i1++];
		while (i2 <= r) v[i++] = b[i2++];

	}
	void QuickSort(vector<int> &v)
	{
		QuickSortInner(v, 0, v.size() - 1);
	}

	void QuickSortInner(vector<int> &v, int l, int r)
	{
		if (l <= r) return;

		int flag = l;
		int left = l + 1, right = r;
		while(left<right)
		{
			while (v[left] <= v[flag])left++;
			while (v[right >= v[flag]]) right--;
			if (left <= right) swap(v[left], v[right]);
		}
		swap(v[left], v[flag]);
		QuickSortInner(v, l, left - 1);
		QuickSortInner(v, left + 1, r);
	}

	bool isSubtree(TreeNode* s, TreeNode* t)
	{
		if (s == nullptr && t == nullptr) return true;
		if (s == nullptr || t == nullptr) return false;

		bool a = false;
		if (s->val == t->val)
		{
			a = isSameTree(s, t);
		}
		return a || isSubtree(s->left, t) || isSubtree(s->right, t);
	}
	bool isSameTree(TreeNode* s, TreeNode* t)
	{
		if (s == nullptr && t == nullptr) return true;
		if (s == nullptr || t == nullptr)return false;
		if (s->val != t->val) return false;
		return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);

	}
	int findTilt(TreeNode* root)
	{
		dfs(root);
		return sum;
	}
	int dfs(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int l = 0, r = 0;
		if (root->left != nullptr)
		{
			l = findTilt(root->left);
		}
		if (root->right != nullptr)
		{
			r = findTilt(root->right);
		}
		sum += abs(l - r);
		return l + r + root->val;
	}


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

