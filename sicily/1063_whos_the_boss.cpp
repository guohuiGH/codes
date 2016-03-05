/*************************************************************************
    > File Name: 1063_whos_the_boss.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: 2016年03月05日 星期六 10时11分09秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Empolyee {
	int id, salary,height;
	int boss,count;
	Empolyee() {
		boss =0;
		count = 0;
	}
};

bool cmp(Empolyee e1, Empolyee e2) {
	return e1.salary < e2.salary;
}

bool cmp2(Empolyee e1, Empolyee e2) {
	return e1.id < e2.id;
}

int main () {
	int n;
	cin >> n;
	while (n--) {
		int m, q;
		cin >> m >> q;		
		vector<Empolyee> ve;
		for (int i = 0; i < m; i++) {
			Empolyee empolyee;
			cin >> empolyee.id >> empolyee.salary >> empolyee.height;
			empolyee.count = 0;
			ve.push_back(empolyee);
		}
		sort(ve.begin(),ve.end(),cmp);
		for (int i = 0; i < m-1; i++) {
			for (int j = i+1; j < m; j++) {
				if (ve[i].height <= ve[j].height) {
					ve[j].count += ve[i].count + 1;
					ve[i].boss = ve[j].id;
					break;
				}
			}
		}
		sort(ve.begin(), ve.end(), cmp2);
		int query;
		for (int i =0; i < q; i++)  {
			cin >> query;
			int b = 0, t = m-1;
			while (b <= t) {
				int mid = (b+t)/2;
				if (ve[mid].id == query) {
					cout << ve[mid].boss << " " << ve[mid].count << endl;
					break;
				}else if (ve[mid].id > query) {
					t = mid -1;
				}else
					b = mid + 1;
			}

		}
	}
}
