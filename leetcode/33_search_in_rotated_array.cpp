/*************************************************************************
    > File Name: 33_search_in_rotated_array.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 13 Nov 2015 10:42:09 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int binarch_search(int left, int right, int target, vector<int> &nums) {

		while(left < right) {
			if (nums[right] == target)
				return right;
			if (nums[left] == target)
				return left;
			int mid = left + (right-left)/2;
			
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				right = mid-1 ;
			else
				left = mid+1;
		}
		return -1;


	}
	int search(vector<int> &nums, int target) {
		int size = nums.size();
		if (size ==1 && nums[0] == target)
			return 0;
		else if (size == 1 && nums[0] != target)
			return -1;
		int left = 0, right = size-1;
		while (left < right) {
			if (nums[left] == target)
				return left;
			if (nums[right] == target)
				return right;
			int mid = left + (right-left)/2;
			if (nums[mid] == target)
				return mid;
			if (nums[mid] < nums[right]) {
				if (target < nums[right] && target > nums[mid])
					return binarch_search(mid,right,target,nums);
				else
					right = mid-1;
			}else {
				if (target > nums[left] && target < nums[mid])
					return binarch_search(left, mid, target, nums);
				else
					left = mid + 1;
			}
		}
		return -1;
	}
};

int main () {
	int a[] = {2,3,4,5,6,7,8,9,1};
	Solution s;
	vector<int>ve(a, a+9);

	cout << s.search(ve, 3);
	return 0;
}
