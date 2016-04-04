/*************************************************************************
    > File Name: 210_course_schedule.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年04月04日 星期一 14时43分50秒
 ************************************************************************/

#include<iostream>
#include<utility>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

class Solution {

public:

	int flag;
	Solution () {
		flag = 0;
	}
	void subDfs(vector<int> &value, int root, int *color, vector<vector<int> >&ve) {

		if (color[root] == 2)
			return;
		else {
			color[root] = 1;
			int size = ve[root].size();
			for (int i = 0; i != size; i++) {
				int child = ve[root][i];

				if (color[child] == 1)
					flag = 1;
				if (color[child] == 0)
					subDfs(value, child, color, ve);
			}
			color[root] = 2;
			value.push_back(root);
		}
	}

	vector<int> dfs(int numCourses, vector<vector<int> >&ve) {
		vector<int> value;
		int* color = new int[numCourses];
		int size = ve.size();
		memset(color,0,sizeof(int)*numCourses);
		for (int i = 0; i < size; i++) {
			subDfs(value, i,color,ve);
		}
		if (flag == 1){
			value.clear();
			return value;
		}

		return value;
	}

	bool bfs(int numCourses, vector<vector<int> > &ve) {
		int size = ve.size();
		int*in = new int[numCourses];
		
		memset(in, 0, sizeof(int)*numCourses);
		for (int i = 0; i < size; i++) {
			int len = ve[i].size();
			for (int j = 0; j < len; j++) {
				in[ve[i][j]]++;
			}
		}
		queue<int> qu;

		for (int i = 0; i < numCourses; i++) {
			if (!in[i]) {
				qu.push(i);
			}
		}
		
		while(!qu.empty()) {
			int top = qu.front();
			qu.pop();
			size = ve[top].size();
			for (int i = 0; i < size; i++) {
				in[ve[top][i]]--;
				if (!in[ve[top][i]])
					qu.push(ve[top][i]);
			}
		}
		for (int i = 0; i < numCourses; i++) {
			if (in[i] > 0)
				return false;
		}
		return true;


	}

	vector<int> canFinish(int numCourses,vector<pair<int,int> >&prerequisites) {
		vector<vector<int> >ve;
		for (int i = 0; i < numCourses; i++) {
			vector<int> temp;
			ve.push_back(temp);
		}
		int size = prerequisites.size();
		for (int i = 0; i < size; i++) {
			int f = prerequisites[i].first;
			int s = prerequisites[i].second;
			ve[f].push_back(s);
		}
	
		return dfs(numCourses, ve);
	}
};

int main () {
	pair<int,int>p1;
	pair<int,int>p2;
	p1 = make_pair(1,0);
	p2 = make_pair(0,1);
	vector<pair<int,int> >ve;
	ve.push_back(p1); ve.push_back(p2);
	int n = 2;
	Solution s;
	vector<int>t = s.canFinish(n,ve);
	int size = t.size();
	for (int i = 0; i < size; i++)
		cout << t[i] << endl;
}
