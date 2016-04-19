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
	int root = x*6+y;
	ve.push_back(root);
	
	color[root] = 1;

	if (tag || ve.size() == 30) {
		tag = 1;
		return;
	}


	for (int i = 0; i < 8; i++) {
		int xx = x + po[i][0];
		int yy = y + po[i][1];
		
		int value = xx*6 + yy;

		if (xx < 5 && xx >= 0 && yy <= 6 && yy > 0 && !color[value]) {	
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
		int color[31] = {0};
		int x = (n-1) / 6;
		int y = n- x*6;
		color[n] = 1;
		dfs(x, y,ve,color);
		if (ve.size() < 30) {
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
