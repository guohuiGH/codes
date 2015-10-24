/*************************************************************************
    > File Name: 223_rectangle_area.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Fri 23 Oct 2015 07:56:15 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

		int total = (C-A)*(D-B) + (G-E)*(H-F);
		int mid = 0;
		if (A < G && B < H && C > E && D > F) {
			mid = (min(G,C) - max(A,E))*(min(D,H)-max(B,F));


		}
		return total - mid;
	}
};

int main () {
	Solution s;
	cout << s.computeArea(-3,0,3,4,0,-1,9,2);
}
