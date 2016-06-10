/*************************************************************************
    > File Name: 200_number_of_islands.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 09 Jun 2016 03:06:28 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<string>
using namespace std;

class Solution {


public:
	int numIslands1(vector<vector<char> >&grid) {
		int row = grid.size();
		if (row == 0)
			return 0;
		int col = grid[0].size();
		if (col == 0) return 0;
		int direction[4][2] = {-1,0,1,0,0,-1,0,1};
		vector<vector<int> >visit(row, vector<int>(col,0));
		int counter = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (visit[i][j] == 0 && grid[i][j] == '1') {
					pair<int,int>p(i,j);
					queue<pair<int,int> >q;
					visit[i][j] = 1;
					q.push(p);
					while(!q.empty()) {
						pair<int,int>front = q.front();

						q.pop();
						for (int t = 0; t < 4; t++) {
							int x = front.first + direction[t][0];
							int y = front.second + direction[t][1];
							if (x>=0&&x<row&&y>=0&&y<col&&visit[x][y]==0 && grid[x][y] == '1') {
								q.push(make_pair(x,y));
								visit[x][y] = 1;
							}
						}
					}
					counter++;
				}
			}
		}
		return counter;
	}

	vector< vector<int> > color;

	void dfs(int x, int y, int row, int col,vector<vector<char> >&grid) {
		int direction[4][2] = {-1,0,1,0,0,-1,0,1};
		for (int i = 0; i < 4; i++) {
			int xx = x + direction[i][0];
			int yy = y + direction[i][1];
			if (xx>=0&&xx<row&&yy>=0&&yy<col&&color[xx][yy]==0&&grid[xx][yy]=='1') {
				color[xx][yy] = 1;
				dfs(xx,yy,row,col,grid);
			}
		}
	}
	int numIslands(vector<vector<char> >&grid) {
		int row = grid.size();
		if (row == 0) return 0;
		int col = grid[0].size();
		if (col == 0) return 0;
		for (int i = 0; i < row; i++) {
			vector<int> v(col,0);
			color.push_back(v);
		}
		int counter = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (color[i][j] ==0 && grid[i][j] == '1') {
					color[i][j] = 1;
					dfs(i,j,row, col,grid);
					counter++;
				}
			}
		}
		return counter;

	}
};

int main() {

	vector<vector<char> >ve;
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		vector<char>v;

		for (int j = 0; j < str.size(); j++) {
			v.push_back(str[j]);
		}
		ve.push_back(v);
	}
	Solution s;
	cout << s.numIslands(ve) << endl;
}
