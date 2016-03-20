/*************************************************************************
    > File Name: 1_two_sum.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月20日 星期日 15时47分27秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum1(vector<int> &nums, int target) {
		sort(nums.begin(), nums.end());
		vector<int> ve;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > target)
				break;
			for (int j = i+1; j < nums.size(); j++) {
				if(nums[i]+nums[j] > target)
					break;
				if (nums[i] + nums[j] == target) {
					ve.push_back(i);
					ve.push_back(j);
					return ve;
				}
			}
		}
	}
	vector<int>twoSum (vector<int> &nums, int target) {
		unordered_map<int, int>hash;
		vector<int>ve;
		for (int i = 0; i < nums.size(); i++) {
			int value = target - nums[i];
			if (hash.find(value) == hash.end()) {
				hash[nums[i]] = i;
			}else {
				ve.push_back(hash[value]);
				ve.push_back(i);
				return hash;
			}
		}
	}
};

int main () {
	Solution s;
	int a[] = {2,7,14,15};
	vector<int>ve(a,a+4);
	vector<int> v = s.twoSum(ve, 9);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}
