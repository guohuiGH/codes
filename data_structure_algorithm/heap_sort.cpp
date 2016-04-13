/*************************************************************************
    > File Name: heap_sort.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月28日 星期一 15时45分15秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

void maxHeap(vector<int>&ve, int root) {
	int left = root*2+1;
	int right = root*2+2;
	int size = ve.size();
	int largest = root;
	if (left < size && ve[left] > ve[root]) {
		largest = left;
	}
	if (right < size && ve[right] > ve[largest]) {
		largest = right;
	}
	if (largest != root) {
		int temp = ve[root];
		ve[root] = ve[largest];
		ve[largest] = temp;
		maxHeap(ve, largest);
	}
}

void buildHeap(vector<int>&ve) {
	int size = ve.size();
	for (int i = size/2; i >=0; i--) {
		maxHeap(ve, i);
	}
}


int main () {
	int a[] = {4,1,3,2,16,9,10,14,8,7};
	vector<int>ve(a, a+10);
	buildHeap(ve);
	int size =ve.size();
	int len = size-1;
	for (int i = size-1; i>=0; i--) {
		cout << ve[0] << endl;
		int temp = ve[0];
		ve[0] = ve[i];
		ve.pop_back();
		maxHeap(ve,0);

	}
}
