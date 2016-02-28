/*************************************************************************
    > File Name: 1051_biker_trip_odomete.cpp
    > Author: guohui
    > Mail: guohui1029@foxmail.com 
    > Created Time: Sat 27 Feb 2016 11:15:02 AM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;
const double PI = 3.1415927;
int main () {
	double diameter, time;
	int revolution;
	int count = 1;
	while(cin >> diameter >> revolution >> time && revolution > 0) {
		double distance = PI*diameter*revolution/(12*5280);
		double total_time = time/(60*60);
		printf("Trip #%d: %.2f %.2f\n",count,distance,distance/total_time);
		count++;
	}
}
