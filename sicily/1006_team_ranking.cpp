/*************************************************************************
    > File Name: 1006_team_ranking.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月02日 星期三 16时49分45秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
using namespace std;


int calculate (string stra, string strb) {
	//cout << stra << endl << strb<< endl;
	int result = 0;
	map<char, int> ma;
	for (int i = 0; i < stra.length(); i++)
		ma[stra[i]] = i;
	map<char, int> mb;
	for (int i = 0; i < strb.length(); i++)
		mb[strb[i]] = i;

	for (int i = 0; i < stra.length(); i++) {
		for (int j = i+1; j < strb.length(); j++) {
			if (mb[stra[i]] > mb[stra[j]])
				result++;
		}
	}
	return result;
}

int main () {
	int N;
	while (cin >> N && N) {

		vector<string> ve;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			ve.push_back(str);
		}		

		char a[5] = {'A','B','C','D','E'};
		string target = a; 
		int value = 10000;
		do  {
			int count = 0;
			//cout << (string)a << endl;
			for (int i = 0; i < ve.size(); i++) {
				count += calculate(ve[i],a);
				//cout << calculate(ve[i], a) << endl;
			}
							
			//cout << count << endl;
			if (count < value) {
				target = a;
				value = count;
			}
			
		}while(next_permutation(a, a+5));
		cout << target << " is the median ranking with value " << value<< "." << endl;

	}
}



