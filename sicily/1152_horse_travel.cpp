/*************************************************************************
    > File Name: 1152_horse_travel.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月05日 星期二 21时01分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int tag = 0;
int po[8][2] = {-2,-1, -2,1, -1,-2, -1,2, 1,-2, 1,2, 2,-1, 2,1};

void dfs(int x, int y, vector<int> &ve, int color[]) {
	int root = x*8+y;
	ve.push_back(root);
	
	color[root] = 1;

	if (tag || ve.size() == 64) {
		tag = 1;
		return;
	}

	for (int i = 0; i < 8; i++) {
		int xx = x + po[i][0];
		int yy = y + po[i][1];
		
		int value = xx*8 + yy;

		if (xx < 8 && xx >= 0 && yy <= 8 && yy > 0 && !color[value]) {	
			//color[value] = 1;
			dfs(xx,yy,ve,color);
			//color[value] = 0;
		}
	}
	if (tag)
		return;
	color[root] = 0;
	ve.pop_back();
}

int main () {
	int n;

	while(cin >> n && n != -1) {
		tag = 0;
		vector<int>ve;

		int color[65] = {0};
		int x = (n-1) / 8;
		int y = n- x*8;
		color[n] = 1;
		dfs(x, y,ve,color);
		if (ve.size() < 64) {
			cout << "-1";
		}
		else {

			cout << ve[0];
			for (int i = 1; i < ve.size(); i++) {
				cout << " "<< ve[i];
			}
		}
		cout << endl;
	}
}
