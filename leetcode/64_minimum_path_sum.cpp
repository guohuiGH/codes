/*************************************************************************
    > File Name: 64_minimum_path_sum.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月01日 星期五 16时42分49秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int> >& grid) {
		int row = grid.size();
		int col = grid[0].size();
		vector<vector<int> >ve = grid;
		int sum = 0;
		for (int i = 0; i < row; i++) {
			sum += grid[i][0];
			ve[i][0] = sum;
		}
		sum = 0;
		for (int i = 0; i < col; i++) {
			sum += grid[0][i];
			ve[0][i] = sum;
		}
		for (int i = 1; i < row; i++) {
			for (int j = 1; j < col; j++) {
				ve[i][j] = min(ve[i-1][j],ve[i][j]) + grid[i][j];	
			}
		}
		return ve[row-1][col-1];
	}
};
int main () {
	Solution s;
	vector<int>ve;
	ve.push_back(1);ve.push_back(2);
	vector<int>v;
	v.push_back(3); v.push_back(4);
	vector<vector<int> > vv;
	vv.push_back(ve);
	vv.push_back(v);
	cout << s.minPathSum(vv);
}
