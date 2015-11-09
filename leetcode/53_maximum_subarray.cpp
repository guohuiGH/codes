/*************************************************************************
    > File Name: 53_maximum_subarray.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 08 Nov 2015 07:21:45 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();
		if (!size)
			return 0;
		int *sum = new int[size];
		int m = nums[0];
		sum[0] = nums[0];
		for (int i = 1; i < size; i++) {
			sum[i] = max(sum[i-1] + nums[i], nums[i]);
			if (m < sum[i])
				m = sum[i];
		}
		return m;
	}
};

int main () {
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int>ve(a,a+9);
	Solution s;
	cout << s.maxSubArray(ve);
}
