/*************************************************************************
    > File Name: 2_merge_sort.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 04 Oct 2015 10:25:28 PM CST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;
void merge(int *p, int low, int mid, int high) {
	int *temp = (int *)malloc((high-low)*sizeof(int));
	int i = low, j = mid;
	int count = 0;
	while(i < mid && j < high) {
		if (p[i] < p[j]){
			temp[count] = p[i];
			i++;
		}
		else {
			temp[count] = p[j];
			j++;
		}
		count++;
	}
	while(i < mid) {
		temp[count] = p[i];
		i++;
		count++;
	}
	while (j < high) {
		temp[count] = p[j];
		j++;
		count++;
	}
	for (int i = low; i < high; i++)
		//cout << temp[i] << "sf";
	//cout << endl;
		p[i] = temp[i-low];
	free(temp);
}

void merge_sort(int *p, int low, int high) {
	int mid = (high + low)/2;
	if (high - low > 1) {
		
		merge_sort(p, low, mid);
		merge_sort(p, mid, high);
		merge(p, low, mid, high);
	}


}


int main() {
	int a[12] = {3,4,2,1,7,4,6,8,4,9,3,6};
	int b[3] = {
		3,2,4
	};
	merge_sort(a,0, 12);
	for (int i = 0; i < 12; i++) 
		cout << a[i] << endl;
	return 0;
}
