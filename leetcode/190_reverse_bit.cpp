/*************************************************************************
    > File Name: 190_reverse_bit.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 18 Oct 2015 09:05:00 AM CST
 ************************************************************************/

#include<iostream>
#include<stdint.h>
#include<stack>
using namespace std;
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		stack<int>s;
		for (int i = 0; i < 32; i++) {
			s.push(n%2);
			n = n>>1;
		}

		uint32_t result = 0;
		int count = 0;
		while(!s.empty()) {
			result += s.top()<<count;
			s.pop();
			count++;
		}
		return result;
	}

};

int main () {
	uint32_t a= 43261596;
	Solution s; 
	cout << s.reverseBits(a);
	//cout << (4<<2);
	return 0;
}
