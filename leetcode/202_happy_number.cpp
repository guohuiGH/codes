/*************************************************************************
    > File Name: 202_happy_number.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 07 Oct 2015 09:27:18 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
	bool isHappy(int n) {
		map<int,int>m;
		while(true) {
			if (n== 1)
				return true;
			if (m[n] == 0) {
				m[n] = 1;
				int temp = 0;
				while(n) {
					int t = n %10;
					n = n /10;
					temp += t *t;
				}
				n = temp;
			}else
				return false;
		}
		return false;
	}
};
int main() {
	Solution s;
	cout << s.isHappy(19);
	return 0;
}
