/*************************************************************************
    > File Name: 1150_longest_path.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 02 Apr 2016 10:48:29 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int LE = 10005;

class Solution {
public:

	int getLength(vector<int>ve[],int root, int first[],int second[], int color[]) {
		int size = ve[root].size();
		int i = 0;
		color[root] = 1;
		int one = 0, two = 0;
		for (; i < size; i++) {
			int node = ve[root][i];
			int len = 0;
			if (!color[node]) {
				len = getLength(ve,node,first,second,color);
			}else
				len = first[node];
			if (len > one) {	
				two = one;
				one = len;

			}else if (len > two) {
				two = len;
			}
		}
		one++; two++;
		first[root] = one;
		second[root] = two;
		return one;
	}

	int getMaxPath(vector<int>v[],int root) {
		
		int first[LE], second[LE], color[LE];
		memset(first,0,sizeof(first));
		memset(second,0,sizeof(second));
		memset(color,0,sizeof(color));
		
		getLength(v, root, first, second, color);

		int maxValue = 0, i = 0;
		while(i < LE) {
			maxValue = max(first[i] + second[i],maxValue);
			i++;
		}
		return maxValue-2;
	}
};

int main () {

	int N;
	cin >> N;
	vector<int>ve[LE];
	int i = 0;
	for (; i < N-1; i++) {
		int l,r;
		cin >> l >> r;
		ve[l].push_back(r);
		ve[r].push_back(l);
	}

	Solution s;
	i = 0;

	while(ve[i].empty()) {
		i++;
	}
	
	cout << s.getMaxPath(ve,i) << endl;
}
