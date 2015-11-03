/*************************************************************************
    > File Name: 34_search_for_range.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 30 Oct 2015 10:26:15 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		if (!nums.size()) {
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}

		int left = 0, right = nums.size()-1;
		int indexMin = -1, indexMax =-1;
		while(left <= right) {
			int mid = left + (right-left)/2;
			if (nums[mid] <= target) {
				indexMin = mid;
				left = mid + 1;
				continue;
			}
			right = mid-1;
		}
		left = 0; right = nums.size() - 1; 
		while (left <=right) {
			int mid = left + (right-left)/2;
		
			if (nums[mid] >= target) {
				indexMax = mid;
				right = mid -1;
				continue;
			}
			left = mid+1;
		}
		if (indexMin==-1 || indexMax == -1 || indexMax > indexMin) {
			result.push_back(-1); result.push_back(-1);
			return result;
		}
		result.push_back(indexMax);
		result.push_back(indexMin);
		return result;
	}
};

int main () {
	int a[] = {1,5,6};
	Solution s;
	vector<int> ve(a, a+2);
	vector<int> v;
	v = s.searchRange(ve, 4);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}


