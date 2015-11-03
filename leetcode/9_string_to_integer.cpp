/*************************************************************************
    > File Name: 9_string_to_integer.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 31 Oct 2015 09:45:21 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<limits.h>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		long int result = 0;
		int size = str.size();
		if (!size)
			return 0;
		string temp;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ' || str[i] == '\t')
				continue;
			else {
				temp += str.substr(i,size-i);
				break;
			}

		}
		size = temp.size();
		int flag = 0;
		int tag = 0;
		if (temp[0] == '-')
			flag = 1;
		if (temp[0] == '+')
			tag = 1;
		if ((flag || tag) && size == 1)
			return 0;

		int i = 0;
		if (flag || tag)
			i = 1;

		for (; i < size; i++) {
			if (temp[i] <= '9' && temp[i] >= '0') {
				result = result *10 + (temp[i] - '0');
			}
			else
				break;

			if (flag && (0-result) <= INT_MIN)
				return INT_MIN;
			else(!flag && result > INT_MAX)
				return INT_MAX;
		}
		
		if (flag) 
			return int(0-result);
		else
			return int(result);

	}
};
int main () {

	Solution s;
	cout << s.myAtoi("    +22  34");
	return 0;
}

