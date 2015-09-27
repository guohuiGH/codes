/*************************************************************************
    > File Name: 191_number_1_bit.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 23 Sep 2015 08:01:22 PM CST
 ************************************************************************/

#include<iostream>
#include<stdint.h>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while(n > 0) {
			count += n&0x1;
			n = n>>1;
		}
		return count;
		
	}
};

int main() {
	Solution s;
	cout << s.hammingWeight(2);
}
