/*************************************************************************
    > File Name: 121_best_time_to_buy_and_sell_stock.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sun 01 Nov 2015 09:16:13 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (size == 0)
			return 0;
		int profit = 0;
		for (int i = 0; i < size; i++) {
			int min_value = min(min_value, prices[i]);
			profit = max(profit, prices[i] - min_value);
		}
		return profit;
	}

};

int main () {
	Solution s;
	int a[] = {10,6,8,1};
	vector<int>ve(a, a+4);
	cout << s.maxProfit(ve);
	return 0;
}
