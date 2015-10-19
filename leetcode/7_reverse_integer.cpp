/*************************************************************************
    > File Name: 9_reverse_integer.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 18 Oct 2015 09:33:31 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<limits.h>
using namespace std;

class Solution {
public:

	int reverse(int x) {
		int temp = x;
		queue<int>s;
		while(temp) {
			s.push(temp%10);
			temp /= 10;
		}
		
		long int result = 0;
		
		int count = 0;
		while(!s.empty()) {
			result = result*10 + s.front();
			cout << s.front() << endl;
			s.pop();
		}

		if (result >= INT_MAX || result <= INT_MIN)
			return 0;
		
		return result;
	}
};

int main () {
	Solution s;
	cout << s.reverse(-2147483640);
	return 0;
}
