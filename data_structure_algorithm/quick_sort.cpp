/*************************************************************************
    > File Name: quick_sort.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月28日 星期一 11时06分56秒
 ************************************************************************/

#include<iostream>
using namespace std;


int partition(int *a, int l, int r) {
	int p = l;
	int key = a[r];
	for (int i = l; i <=r- 1; i++) {
		if (a[i] <= key) {
			int temp = a[p];
			a[p] = a[i];
			a[i] = temp;
			p++;
		}
	}
	a[r] = a[p];
	a[p] = key;
	return p;
}

void quickSort(int *a, int l, int r) {
	if (l < r) {
		int p = partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}

int main () {
	int a[] = {3,1,6,2,7,4,8,5};
	quickSort(a, 0, 7);
	for (int i = 0; i <=7; i++)
		cout << a[i] << endl;
}
