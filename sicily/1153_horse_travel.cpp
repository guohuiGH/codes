/*************************************************************************
    > File Name: 1152_horse_travel.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月05日 星期二 21时01分00秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int tag = 0;
int po[8][2] = {-2,-1, -2,1, -1,-2, -1,2, 1,-2, 1,2, 2,-1, 2,1};
int color[65];
struct Node {
	int x, y, weight;
	Node(int xx, int yy, int w):x(xx),y(yy),weight(w) {}
};

int getNums(int x, int y) {
	int weight = 0;	
	for (int i = 0; i < 8; i++) {
		int xx = x + po[i][0];
		int yy = y + po[i][1];
		int value = xx*8 + yy;
		if (xx < 8 && xx >= 0 && yy <= 8 && yy > 0 && !color[value]) {	
			weight++;
		}
	}
		return weight;
}

bool cmp(Node a, Node b) {
	return a.weight < b.weight;
}

void dfs(int x, int y, vector<int> &ve, int color[]) {
	if (tag)
		return;
	int root = x*8+y;
	ve.push_back(root);
	
	color[root] = 1;

	if (tag || ve.size() == 64) {
		tag = 1;
		cout << ve[0];
		for (int i = 1; i < ve.size(); i++) {
			cout << " "<< ve[i];
		}
		return;
	}

	vector<Node> v;
	for (int i = 0; i < 8; i++) {
		int xx = x + po[i][0];
		int yy = y + po[i][1];
		
		int value = xx*8 + yy;

		if (xx < 8 && xx >= 0 && yy <= 8 && yy > 0 && !color[value]) {	
			//Node node = new Node(xx, yy, getNums(xx,yy));
			//v.push_back(node);
			v.push_back(Node(xx, yy, getNums(xx,yy)));
		}	
	}
	sort(v.begin(), v.end(), cmp);
	int size = v.size();
	for (int i = 0; i < size; i++) {
		dfs(v[i].x, v[i].y, ve, color);
	}

	color[root] = 0;
	ve.pop_back();
}

int main () {
	int n;

	while(cin >> n && n != -1) {
		tag = 0;
		vector<int>ve;

		memset(color, 0, sizeof(color));
		int x = (n-1) / 8;
		int y = n- x*8;
		color[n] = 1;
		dfs(x, y,ve,color);


		
		cout << endl;
	}
}
