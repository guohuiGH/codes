/*************************************************************************
    > File Name: 1081_short_path_dijkstra.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月18日 星期一 15时26分09秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>
#include<queue>
#include<string.h>

using namespace std;

const int SIZE = 100005;
const int MAX = 100000005;

int visit[SIZE];
int dis[SIZE];
vector<map<int, int> >ve;

void initial(int u, int v, int val) {
	map<int, int> temp = ve[u];
	if (temp.find(v) == temp.end() || temp[v] > val) {
		ve[u][v] = val;
	}
}

int findTarget(int root) {
	visit[root] = 1;
	queue<int>qu;
	qu.push(root);
	while(!qu.empty()) {
		int u = qu.front();
		qu.pop();
		visit[u] = 0;
		map<int,int>temp = ve[u];
		map<int,int>::iterator it;
		for (it = temp.begin(); it != temp.end(); it++) {
			int v = it->first;
			int val = it->second;
			//dis[v] = min(dis[v], dis[u] + val);
		    if (dis[v] < (dis[u] + val)) {
         		if (!visit[v]) {
        			visit[v] = 1;
        			qu.push(v);
        		}
		    }
			
		}

	}
}

void findTarget1(int root) {

	int size = ve.size();
	for (int i = 0; i < size; i++) {
		int minV = dis[0];
		int po = 0;
		for (int j = 1; j <= size; j++) {
			if (!visit[j] && dis[j] < minV) {
				minV = dis[j];
				po = j;
			}
		}
		visit[po] = 1;

		for (int j = 1; j <= size; j++) {
			if (!visit[j] && ve[po].find(j) != ve[po].end())	
				dis[j] = min(dis[j], dis[po] + ve[po][j]);
		}

	}
}

int main () {
	int N,M,S,T;

	cin >> N >> M >> S >> T;
	
	for (int i = 0; i < N + 1; i++) {
		map <int,int>  temp;
		ve.push_back(temp);
		dis[i] = MAX;
	}
		
	for (int i = 0; i < M; i++) {
		int u, v, len;
		cin >> u >> v >> len;
		initial(u,v,len);
		initial(v,u,len);
	}
	memset(visit, 0, sizeof(visit));
	//memset(dis, 0x3f, sizeof(dis));
	
	dis[S] = 0;
	findTarget(S);
	cout << dis[T] << endl;
}
