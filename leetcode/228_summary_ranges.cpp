/*************************************************************************
    > File Name: 228_summary_ranges.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 28 Oct 2015 02:10:05 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int> & nums) {
		int size = nums.size();
		vector<string> result;
		if (!size)
			return result;
		string s= "";

		for (int i = 0; i < size-1; i++) {
			char temp[100];
			sprintf(temp, "%d", nums[i]);
			if (abs(nums[i+1]-nums[i]) ==1) {
				if(s.empty())
					s = string(temp);
				continue;
			}
			if (s.empty())
				s = string(temp);
			else
				s += "->" + string(temp);
			result.push_back(s);
			s = "";
		}
		char temp[100];
		sprintf(temp, "%d", nums[size-1]);
		if (s.empty())
			s = string(temp);
		else
			s += "->" + string(temp);
		result.push_back(s);
		return result;
	}
};

int main () {
	int a[] = {0,1,2,4,5,7};
	vector<int> ve (a, a+6);
	vector<string>v;
	Solution s;
	v = s.summaryRanges(ve);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
