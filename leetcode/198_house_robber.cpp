/*************************************************************************
    > File Name: 198_house_robber.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 14 Oct 2015 02:55:22 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rob (vector<int>&nums){
		int size = nums.size();
		if (size == 0)
			return 0;
		int *s = (int*) malloc(sizeof(int)*size);
		if (size==1)
			return nums[0];
		s[0] = nums[0];
		if (size==2)
			return max(nums[0], nums[1]);
		s[1] = max(nums[0], nums[1]);
		for (int i = 2; i < size; i++) {
			s[i] = max(s[i-1], s[i-2]+nums[i]);
		}
		return s[size-1];
	}
};

int main () {
	int a[] = {1,3,4,2,4,1,5};
	vector<int>v(a,a+7);
	Solution s;
	cout << s.rob(v);
	return 1;
}
