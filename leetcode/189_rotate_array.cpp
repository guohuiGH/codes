/*************************************************************************
    > File Name: 189_rotate_array.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 30 Oct 2015 09:28:27 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k%nums.size();
		if (!nums.size() || !k)
			return;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin()+k);
		reverse(nums.begin()+k, nums.end());
	}
};

int main () {
	Solution s;
	int a[7] = {1,2,3,4,5,6,7};
	vector<int>nu(a,a+7);
	s.rotate(nu, 3);
	for (int i = 0; i < nu.size(); i++)
		cout << nu[i] << endl;
}
