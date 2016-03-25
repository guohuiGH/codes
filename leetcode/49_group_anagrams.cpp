/*************************************************************************
    > File Name: 49_group_anagrams.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月25日 星期五 14时57分28秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<string.h>
//#include<trl/unordered_map>
#include<map>
using namespace std;

class Solution {
public:
	long int charValue[26];
	long int charToInt(int& i) {
		return long(round(pow(2.0,i*1.0)));
	}
	long int strToInt(string& str) {
		long int result = 0;
		for (int i = 0; i < str.length(); i++) {
			result += charValue[str[i]-'0'];
		}
		return result;
	}

	vector<vector<string> > groupAnagrams(vector<string>& strs) {
		memset(charValue,0,sizeof(int)*26);
		for (int i = 0; i < 26; i++) {
			charValue[i] = charToInt(i);
		}
		//unordered_map<string,int> hash;
		map<long int,int>hash;
		int counter = 0;
		vector<vector<string> > ve;

		for (int i = 0; i < strs.size(); i++) {
			long int value = -1;
			if (strs[i] != "")
				value = strToInt(strs[i]);
			//cout << value << endl;
			if (hash.find(value) == hash.end())	{
				hash[value] = counter;
				counter++;
				vector<string> temp;
				temp.push_back(strs[i]);
				ve.push_back(temp);
			}else {
				int index = hash[value];
				ve[index].push_back(strs[i]);
			}
		}

		for (int i = 0; i < ve.size(); i++) {
			sort(ve[i].begin(), ve[i].end());
		}
		cout << ve.size() << endl;
		return ve;
	}
};

int main () {
	Solution s;
	vector<string> ve;
	string str;
	//for (int i = 0; i < 6; i++) {
	//	ve.push_back(str);
	//}
	//
	ve.push_back("ape");

	ve.push_back("pea");
	ve.push_back("tax");
	//ve.push_back("nat");
	//ve.push_back("tan");
	//ve.push_back("bat");
//	ve.push_back("");
	vector<vector<string> > v = s.groupAnagrams(ve);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0;j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
