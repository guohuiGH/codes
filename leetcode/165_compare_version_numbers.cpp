/*************************************************************************
    > File Name: 165_compare_version_numbers.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 30 Oct 2015 11:34:54 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class Solution {
public:

	vector<int> change(string str) {
		vector<int> ve;
		str.push_back('.');
		int j = 0;
		for (int i = 0; i < str.size() && j < str.size(); i++) {
			if (str[i] == '.') {
				string s = str.substr(j,i-j);
				j = i+1;
				int temp = atoi(s.c_str());
				ve.push_back(temp);
			}
		}
		
		return ve;
	}

	int compareVersion(string version1, string version2) {
		if (version1 == version2)
			return 0;
		vector<int> v1, v2;
		v1 = change(version1);
		v2 = change(version2);
		int len = min(v1.size(), v2.size());

		for (int i = 0; i < len; i++) {
			if (v1[i] > v2[i])
				return 1;
			else if (v1[i] < v2[i])
				return -1;
		}
		if (v1.size() > v2.size()) {
			for (int i = len; i < v1.size(); i++) {
				if (v1[i] > 0)
					return 1;
				else if (v1[i] < 0)
					return -1;
			}
		}

		else if (v1.size() < v2.size()) {
			for (int i = len; i < v2.size(); i++) {
				if (v2[i] > 0)
					return 1;
				else if (v2[i] < 0)
					return -1;
			}
		}
		return 0;


	}
};

int main () {
	Solution s;
	cout << s.compareVersion("1.0.1", "1");

}
