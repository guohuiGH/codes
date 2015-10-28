/*************************************************************************
    > File Name: 204_count_primes.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Wed 28 Oct 2015 09:03:33 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:


	int countPrimes(int n) {
		if (n == 0 || n == 1)
			return 0;
		int count = 0;
		int *isPrime = new int[n];
		for (int i = 2; i < n; i++)
			isPrime[i] = 0;
		for (int i = 2; i *i < n; i++) {
			if (isPrime[i]) 
				continue;
			for (int j = i*i; j <n;) {
				isPrime[j] = 1;
				j = j+i;
			}

		}
		for (int i = 2; i < n; i++) {
			if (!isPrime[i])
				count++;
		}

		return count;
	}
};

int main () {
	Solution s;
	cout << s.countPrimes(6);
}
