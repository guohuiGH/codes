/*************************************************************************
    > File Name: 2403_voting.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Thu 09 Jun 2016 06:06:50 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int main () {
	string str;
	while(cin >> str && str != "#") {
		int length = str.size();
		map<char, int>hash;
		for (int i = 0; i < length; i++)
			hash[str[i]]++;
		if ((length%2==0 && hash['A'] >= length/2)|| (length%2!=0 && hash['A']>=length/2+1))
			cout << "need quorum" << endl;
		else if (hash['Y'] == hash['N'])
			cout << "tie" << endl;
		else if (hash['Y'] > hash['N'])
			cout << "yes" << endl;
		else if (hash['Y'] < hash['N'])
			cout << "no" << endl;
	}
}
