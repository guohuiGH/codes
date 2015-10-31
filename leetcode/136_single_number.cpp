/*************************************************************************
    > File Name: 136_single_number.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 31 Oct 2015 11:08:28 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	int singleNumber (vector<int> & nums) {
		int sig = 0;
       		for (int i = 0; i < nums.size(); i++) {
            		sig ^= nums[i]; 
        	}
        	return sig;
	}
};

int main () {
	Solution s;
	int a[] = {
	}
}
