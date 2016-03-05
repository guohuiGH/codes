/*************************************************************************
    > File Name: 1024_magic_island.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月01日 星期二 11时14分46秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
const int LENGTH = 10001;

struct Node {
	int x, y, dis;
};

vector<Node> ve[LENGTH];
int color[LENGTH];

int dfs(int root) {

	int max = 0;
	for (int i = 0; i < ve[root].size(); i++) {
		int j = ve[root][i].y;
		if (!color[j]) {
			color[j] = 1;
			int temp = dfs(j);
			if (max < temp + ve[root][i].dis)
				max = temp + ve[root][i].dis;
			color[j] = 0;
		}
	}
	return max;
}

int main () {
	int N, K;
	while (cin >> N >> K) {
		for (int i = 0; i < LENGTH; i++) {
			ve[i].clear();
		}
		memset(color, 0, LENGTH);

		int x, y, d;
		for (int i = 0; i < N-1; i++) {
			cin >> x >> y >> d;
			Node node;
			node.x = x; node.y = y; node.dis = d;
			ve[x].push_back(node);
			node.x = y; node.y = x; node.dis = d;
			ve[y].push_back(node);
		}
		color[K] = 1;
		cout << dfs(K) << endl;

	}
}
