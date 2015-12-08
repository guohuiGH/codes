/*************************************************************************
    > File Name: 2_insert_sort.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 04 Oct 2015 10:06:23 PM CST
 ************************************************************************/

void insert_sort(int *p, int size) {
	
	for (int i = 1; i < size; i++) {
		int j = i - 1;
		int temp = p[i];
		while (j >=0 && p[j] < temp) {
			p[j + 1] = p[j];
			j--;
		}
		p[j+1] = temp;
	}
}

#include<iostream>
using namespace std;
int main() {
	int a[9] = {1,5,2,7,0,4,6,8, 0};
	insert_sort(a, 9);
	for (int i = 0; i < 9; i++)
		cout << a[i] << endl;
	return 0;
}
