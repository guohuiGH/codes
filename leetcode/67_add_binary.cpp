/*************************************************************************
    > File Name: 67_add_binary.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Mon 12 Oct 2015 02:49:53 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b){

		int len2 = max(a.size(), b.size());
		string result = "";
		int flag = 0;
		int a_size = a.size();
		int b_size = b.size();
		for (int i = 1; i <= len2; i++) {
			int al = a_size-i;
			int bl = b_size-i;
			int t1, t2;
			if (al>=0)
				t1 = a[al] - '0';
			else
				t1 = 0;
			if (bl>=0)
				t2 = b[bl] - '0';
			else
				t2 = 0;
			if (t1+t2+flag == 3) {
				flag = 1;
				result = "1" + result;
			}else if (t1+t2+flag == 2) {
				flag = 1;
				result = "0" + result;
			}else if (t1+t2+flag == 1) {
				flag = 0;
				result = "1" + result;
			}else {
				flag = 0;
				result = "0" + result;
			}
		}
		if (flag == 1)
			result = "1" + result;
		return result;
	}
};
int main() {
	string a = "1";
	string b = "1";
	Solution s;
	cout << s.addBinary(a, b);
	return 0;
}
