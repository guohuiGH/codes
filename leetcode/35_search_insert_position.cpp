/*************************************************************************
    > File Name: 35_search_insert_position.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 05 Nov 2015 04:37:48 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>&nums, int target) {
		int size = nums.size();
		if (size == 0)
			return 0;
		int left = 0, right = size-1;
		while (left <= right) {
			int mid = left + (right-left)/2;
			if (nums[mid] > target)
				right = mid-1;
			else if (nums[mid] < target)
				left = mid +1;
			else
				return mid;
		}
		return left;
	}
};

int main () {
	int a[] = {1,3,5,6};
	vector<int>ve(a,a+4);
	Solution s;
	cout << s.searchInsert(ve, 0);
	return 0;
}
