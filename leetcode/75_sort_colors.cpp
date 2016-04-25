/*************************************************************************
    > File Name: 75_sort_colors.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月23日 星期六 16时53分27秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void sortColors2(vector<int>& nums) {
		vector<int> ve = nums;

		int c[3] = {0};
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			c[nums[i]] += 1;
		}

		for (int i = 1; i <=2; i++)
			c[i] += c[i-1];
		for (int i = 0; i < size; i++) {
			ve[c[nums[i]]-1] = nums[i];
			c[nums[i]]--;
		}
		for (int i = 0; i < size; i++)
			nums[i] = ve[i];

	}

	void sortColors(vector<int>& nums) {
		int size = nums.size();
		int p = 0,t = size-1;
		for (int i = 0; i < size; i++) {
			if (nums[i] == 0) {
				int temp = nums[i];
				nums[i] = nums[p];
				nums[p] = temp;
				p++;
			}
			if (i <= t && nums[i] == 2) {
				int temp = nums[i];
				nums[i] = nums[t];
				nums[t] = temp;
				t--;
				i--;
			}
		}

	}
};

int main () {
	int a[] = {1,2,1,0,2,1,0};
	vector<int> ve(a, a+7);
	Solution s;
	s.sortColors(ve);

	for (int i = 0; i < ve.size(); i++) {
		cout << ve[i];
	}
	cout << "zz";
}
