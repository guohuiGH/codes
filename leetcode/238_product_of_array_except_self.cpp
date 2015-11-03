/*************************************************************************
    > File Name: 238_product_of_array_except_self.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 02 Nov 2015 10:42:32 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		vector<int> v;
		v.push_back(1);
		for (int i = 1; i < size; i++) {
			v.push_back(v[i-1]*nums[i-1]);
		}
		int t = 1;
		for (int i = size-2; i >= 0; i--) {
			t *= nums[i+1];
			v[i] *= t;
		}
		return v;

	}
};

int main () {
	int a[] = {1,2,3,4};
	vector<int> ve(a, a+4);
	Solution s;
	vector<int>vv;
	vv = s.productExceptSelf(ve);
	for (int i = 0; i < vv.size(); i++) {
		cout << vv[i] << endl;
	}
	return 0;
}
