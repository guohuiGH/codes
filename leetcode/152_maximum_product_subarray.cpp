/*************************************************************************
    > File Name: 153_maximum_product_subarray.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 09 Nov 2015 10:01:40 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		int *maxValue = new int[size];
		int *minValue = new int[size];
		int result = nums[0];
		maxValue[0] = nums[0]; minValue[0] = nums[0];
		for (int i = 1; i < size; i++) {
			maxValue[i] = max(max(maxValue[i-1]*nums[i], nums[i]), minValue[i-1]*nums[i]);
			minValue[i] = min(min(minValue[i-1]*nums[i], nums[i]), maxValue[i-1]*nums[i]);
			result = max(maxValue[i], result);
		}
		return result;
	}
};

int main () {
	int a[] = {2,3,-2,4};
	vector<int>ve(a, a+4);
	Solution s;
	cout << s.maxProduct(ve);
}
