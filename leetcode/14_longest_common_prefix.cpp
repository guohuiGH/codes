/*************************************************************************
    > File Name: 14_longest_common_prefix.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 25 Oct 2015 09:49:44 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		int size = strs.size();
		if (size == 0)
			return "";
		if (size == 1)
			return strs[0];
		string str1 = strs[0];
		string str2 = strs[1];
		int len = min(str1.size(), str2.size());
		string temp ="";
		for (int i = 0; i < len; i++) {
			if (str1[i] == str2[i])
				temp.push_back(str1[i]);
			else
				break;
		}
		string result = temp;
		temp = "";
		for (int i = 2; i < size; i++) {
			len = min(result.size(), strs[i].size());
			for (int j = 0; j < len; j++) {
				if (result[j] == strs[i][j])
					temp.push_back(result[j]);
				else
					break;
			}
			result = temp;
			temp = "";
		}
		return result;
	}
};
int main () {
	Solution s;
	string a = "cde", b = "cabcfg", c = "abji";
	vector<string> ve;
	ve.push_back(a); ve.push_back(c); ve.push_back(c);
	cout << s.longestCommonPrefix(ve);
}
