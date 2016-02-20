/*************************************************************************
    > File Name: 46_permutations.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年02月20日 星期六 15时52分33秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	vector<vector<int> > vv;
	int *flag;
	void per(vector<int> & temp, vector<int>& nums, int fg) {
		int size = nums.size();
		if (fg==size) {

			for (int i = 0; i < size; i++)
				cout << temp[i] << " ";
			cout << endl;
			vv.push_back(temp);
			return;
		}
		for (int i = 0; i < size; i++) {
			if (flag[i] == 0) {
				temp[fg] = nums[i];
				flag[i] = 1;
				per(temp, nums, fg+1);
				flag[i] = 0;
			}else
				continue;
		}

	}

	vector<vector<int> > permute(vector<int>& nums) {
		vector<vector<int> > v;
		int size = nums.size();
		flag = (int*)malloc(sizeof(int)*size);
		vector<int> temp;
		for (int j = 0; j < size; j++) {
			flag[j] = 0;
			temp.push_back(0);
		}
		per(temp, nums, 0);
		
		return vv;
		
	}
};

int main () {
	int a[] = {1,2,3};
	vector<int> ve(a, a+3);
	Solution s;
	s.permute(ve);
	return 0;
}
