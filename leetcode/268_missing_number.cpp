/*************************************************************************
    > File Name: 268_missing_number.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 04 Nov 2015 08:29:49 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 1; i <= nums.size(); i++) {
			result ^= (i^nums[i-1]); 
		}
		return result;
	}
};

int main () {
	int a[] = {0,1};
	vector<int> ve(a, a+2);
	Solution s;
	cout << s.missingNumber(ve);
	return 0;
}
