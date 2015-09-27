/*************************************************************************
    > File Name: 171_excel_sheet_column_number.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 24 Sep 2015 08:54:33 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

class Solution {
public:
	int titleToNumber (string s) {
		int len = s.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return (s[0] - 'A' + 1);
		int result = s[len-1] - 'A' + 1;
		for (int i = len - 2; i >= 0; i--) {
			
			result += (s[i]-'A' + 1)*pow(26,len-i-1);
			
		}
		return result;
	}
};

int main () {
	Solution s;
	cout << s.titleToNumber("AA") << endl;
}
