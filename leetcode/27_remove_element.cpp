/*************************************************************************
    > File Name: 27_remove_element.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 10 Oct 2015 10:16:04 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>&nums, int val) {
		int size = nums.size();
		int tx = size -1;
		for (int i = 0; i < size; i++) {
			if (i > tx)
				break;
			if (nums[i] == val) {
				while(tx>=1&&nums[tx]==val)
					tx--;
				if (i > tx)
					break;
				int temp = nums[i];
				nums[i] = nums[tx];
				nums[tx] = nums[i];
				tx--;
			}
		}
		for (int i = 0; i < size-tx-1; i++)
			nums.pop_back();
		return nums.size();
	}
};
int main () {
	int a[] = {2,4,3,4,4,4};
	vector<int> ve(a, a+6);
	Solution s;
	cout << s.removeElement(ve, 4);
	for (int i = 0; i < ve.size(); i++)
		cout << ve[i] << endl;

}
