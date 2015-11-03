/*************************************************************************
    > File Name: 122_best_time_to_buy_and_sell_stock2.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 01 Nov 2015 05:26:56 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int size = nums.size();
		int profit = 0;
		for (int i = 0; i < size-1; i++) {
			if (nums[i+1] > nums[i])
				profit += nums[i+1] - nums[i];
		}
		return profit;
	}
};

int main () {
	int a[] = {9,2,5,3,7};
	Solution s;
	vector<int> ve(a,a+5);
	cout << s.singleNumber(ve);
	return 0;
}
