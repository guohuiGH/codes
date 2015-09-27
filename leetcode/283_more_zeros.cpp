/*************************************************************************
    > File Name: 283_more_zeros.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 21 Sep 2015 11:20:09 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void moreZeros(vector<int>& nums){
		int length = nums.size();
		int i = 0;
		for (int t = 0; t < length; t++) {
			
			if (nums[i] == 0) {
				int j = i;
				while(j < length-1){
					nums[j] = nums[j+1];
					j++;
				}
				nums[j] = 0;
				i--;
			}
			i++;
		}
	}
};

int main() {
	vector <int> a;
	a.push_back(0);
	a.push_back(0);
	a.push_back(5);
	a.push_back(0);
	a.push_back(2);
	Solution s;
	s.moreZeros(a);
	for (int i = 0; i < 5; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
