/*************************************************************************
    > File Name: 3499_score_count.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 09 Jun 2016 05:49:53 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main () {
	int t; cin >> t;
	while(t--) {
		int m; cin >> m;
		vector<int>ve;
		for (int i = 0; i < m; i++) {
			int tt; cin >> tt;
			ve.push_back(tt);
		}
		sort(ve.begin(),ve.end());
		float sum = 0;
		for (int i = 1; i < m-1; i++)
			sum += ve[i];

		printf("%.2f\n",sum/(m-2));
	}		
}
