/*************************************************************************
    > File Name: 217_contain_duplicate.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 24 Sep 2015 03:59:00 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>&nums){
	int	len = nums.size();
		
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len-1; i++) {
			if (nums[i] == nums[i+1])
				return true;			
		}
		return false;
	}
};

int main () {
	Solution s;
	int aa[4] = {1,2,3,2};
	vector<int> a(aa, aa+4);
	cout << s.containsDuplicate(a);
}
