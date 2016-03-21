/*************************************************************************
    > File Name: 15_3sum.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月21日 星期一 14时09分01秒
 ************************************************************************/

#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		vector<vector<int> >ve;
		set<vector<int> > s;
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0)
				break;
			hash.clear();
			for (int j = i+1; j< nums.size(); j++) {
			    
				int value = 0 - nums[i] - nums[j];
				if (hash.find(value) == hash.end()) {
					hash[nums[j]] = j;
				}else {
					vector<int>v;
					v.push_back(nums[i]);
					v.push_back(min(value,nums[j]));
					v.push_back(max(value,nums[j]));
					ve.push_back(v);
					while (j+1 < nums.size() && nums[j] == nums[j+1])
					    j++;
				}
			}
			while (i+1 < nums.size() && nums[i] == nums[i+1])
				i++;
			
		}/*
		set<vector<int>>::iterator it;
		for (it = s.begin(); it != s.end(); it++) {
			ve.push_back(*it);
		}*/
		return ve;
    }
};

int main () {
	int a[] = {-1,0,1,2,-1,-4};
	vector<int>ve(a,a+6);
	Solution s;
	s.threeSum(ve);
}
