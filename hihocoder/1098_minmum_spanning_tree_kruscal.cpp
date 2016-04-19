/*************************************************************************
    > File Name: 1098_minmum_spanning_tree_kruscal.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月19日 星期二 15时07分53秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int SIZE = 100005;
int finds[SIZE];
vector<map<int,int> >ve;

struct Node {
	int from,to,val;
}node[1000005];

void initial(int u, int v, int val) {
	if (ve[u].find(v) == ve[u].end() || ve[u][v] > val) {
		ve[u][v] = val;
	}
}

bool cmp (Node a, Node b) {
	return a.val < b.val;
}

int find_sets(int x) {
	if (finds[x] == x)
		return x;
	else
		return find_sets(finds[x]);
}

int kruscal(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int u = node[i].from;
		int v = node[i].to;
		int val = node[i].val;
		int x = find_sets(u);
		int y = find_sets(v);
		if (x != y) {
			sum += val;
			finds[max(x,y)] = min(x,y);
		}
	}
	return sum;
}

int main () {
	int N,M;
	cin >> N >> M;
	
	for (int i = 0; i <=N; i++) {
		map<int,int>temp;
		ve.push_back(temp);
		finds[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int u,v,len;
		cin >> u >> v >> len;
		initial (u,v,len);
		initial (v,u,len);
	}
	int size = ve.size();
	int counter = 0;
	for (int i = 0; i < size; i++) {
		map<int,int>::iterator it;
		for (it = ve[i].begin(); it!= ve[i].end(); it++) {
			node[counter].from = i;
			node[counter].to = it->first;
			node[counter].val = it->second;
			counter++;
		}
	}
	sort(node,node+counter,cmp);
	cout << kruscal(counter);

}
