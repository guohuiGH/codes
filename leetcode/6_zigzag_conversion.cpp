/*************************************************************************
    > File Name: 6_zigzag_conversion.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Tue 27 Oct 2015 07:09:37 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string convert (string s, int numRows) {
		vector<string>ve;
		for (int i = 0; i < numRows; i++) {
			ve.push_back("");
		}
		int tag = 0;
		int flag = 0;
		for (int i = 0; i < s.size(); ) {
			if (!flag) {
				for (int j = 0; j < numRows && i < s.size(); j++) {
					ve[j].push_back(s[i]);
					i++;
				}
				flag = 1;
				if(tag == 0)
					tag = 1;
				else
					tag = 0;
			}
			if (tag && flag) {
				for (int j = numRows-2; j>0 && i < s.size(); j--) {
					ve[j].push_back(s[i]);
					i++;
				}
				flag = 0;
				tag = 0;
			}
			if (!tag && flag) {
				for (int j = 1; j < numRows - 1; j++) {
					ve[j].push_back(s[i]);
					i++;
				}
				flag = 0;
				tag = 1;
			}
		}
		string result = "";
		for (int i = 0; i < numRows; i++) {
			result += ve[i];
		}
		return result;
	}
};

int main () {
	Solution s;
	cout << s.convert("PAYPALISHIRING",2);
}
