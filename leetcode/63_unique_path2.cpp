/*************************************************************************
    > File Name: 63_unique_path2.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 15 Nov 2015 02:35:01 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int uniquePathWithObstacles(vector<vector<int> > & obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		vector<vector<int> > dp(m, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			if (obstacleGrid[0][i] != 1)
				dp[0][i] = 1;
			else
				break;
		}
		for (int i = 0; i < m; i++) {
			if (obstacleGrid[i][0] != 1)
				dp[i][0] = 1;
			else
				break;
		}
		for(int i = 1; i < m; i ++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] != 1)
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
	}
};

int main () {
	vector<int>v1(3,0);
	int a[] = {0,1,0};
	vector<int>v2(a, a+3);
	vector<vector<int> > ve;
	ve.push_back(v2); ve.push_back(v2); ve.push_back(v2);
	Solution s;

	cout << s.uniquePathWithObstacles(ve);
}
