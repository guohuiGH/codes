/*************************************************************************
    > File Name: 5_longest_palindromic_subtring.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月04日 星期一 21时47分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		//vector<vector<int> >dp(len,vector<int>(len,0));
		int dp[1001][1001] = {0};
		int max = 0;
		int index = 0;

		for (int i = 0; i != len; i++) {
			for (int j = len-1; j != -1; j--) {
				if (s[i] == s[j]) {
					if (i == 0 || j == len -1)
						dp[i][j] = 1;
					else
						dp[i][j] = dp[i-1][j+1] + 1;
					if (max <= dp[i][j]) {
						max = dp[i][j];
						index = i;
					}
				}
			}
		}

		return s.substr(index-max+1, max);
	}
};

int main () {
	string test = "abcdcb";
	Solution s;
	cout << s.longestPalindrome(test);
}
