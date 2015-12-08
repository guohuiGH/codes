/*************************************************************************
    > File Name: 303_range_sum_query_immutable.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 30 Nov 2015 08:49:39 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
class NumArray {
public:
	vector<int>ve;
	
	vector<vector<int> > v;

	int dfs (int left, int right) {
		if (left == right)
			return ve[left];
		if (v[left][right] != INT_MIN)
			return v[left][right];
		int mid = left + (right-left)/2;

		v[left][right] = dfs(left, mid) + dfs(mid+1, right);
		return v[left][right];
	}
	NumArray(vector<int> &nums) {
		int size = nums.size();
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += nums[i];
			ve.push_back(sum);
		}

	}
	int sumRange(int i, int j) {
		if (i == 0)
			return ve[j];
		else
			return ve[j]-ve[i-1];
	}
};
int main() {
	int a[] = {-2,0,3,-5,2,-1};
	vector<int> nums(a, a+6);
	NumArray numArray(nums);
	cout << numArray.sumRange(0,1);
	cout << numArray.sumRange(1,2);

	return 0;
}
