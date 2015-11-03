/*************************************************************************
    > File Name: 219_contain_duplicate2.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 21 Oct 2015 03:45:07 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	bool containsNearDuplicate(vector<int>& nums, int k) {
		if (nums.size()==0 || k== 0)
			return true;
		vector<int>temp;
		if (k > nums.size()) {
			sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size()-1; i++) {
				if (nums[i] == nums[i+1])
					return true;
			}
			return false;
		}
		
		for (int i = 0; i < k+1; i++) {
			temp.push_back(nums[i]);
		}
		sort(temp.begin(), temp.begin()+k+1);
		for (int i = 0; i < k; i++) {
			if (temp[i] == temp[i+1])
				return true;
		}
		for (int i = k+1; i < nums.size(); i++) {
			for (int j = i-k; j < i;j++ ) {
				if (nums[i] == nums[j])
					return true;
			}
		}
		return false;
	}

};

int main () {

	int a[] = {1,8,6,7,8,4};
	vector<int> v(a, a+7);
	Solution s;
	cout << s.containsNearDuplicate(v,20);
}
