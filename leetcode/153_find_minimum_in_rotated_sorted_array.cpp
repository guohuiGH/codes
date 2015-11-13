/*************************************************************************
    > File Name: 153_find_minimum_in_rotated_sorted_array.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 10 Nov 2015 10:15:39 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int> & nums) {
		int size = nums.size();
		if (!size)
			return 0;
		if (size==1)
			return nums[0];
		int left = 0, right = size-1;
		while(left < right) {
			if (nums[left] < nums[right])
				return nums[left];
			int mid = left + (right-left)/2;
			if(nums[mid] > nums[left])
				left = mid;
			else
				right = mid;	
		}
		return nums[left+1];
	}
};

int main () {

	int a[] = {4,2};
	vector<int> ve(a, a+2);
	Solution s;
	cout << s.findMin(ve);
	return 0;
}
