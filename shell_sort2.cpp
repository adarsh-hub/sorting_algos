//
// Created by Adarsh on 4/6/2021.
//
#include "project1.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> gap_sequence1(int n){
	//A083318 = 2^k + 1
	vector<int> gap_seq;
	gap_seq.push_back(1);
	int gap;
	for(int i = 1; i<=n;i++){
		gap = pow(2,i) + 1;
		gap_seq.push_back(gap);
	}
	sort(gap_seq.begin(), gap_seq.end());
	return gap_seq;
}

void shell_sort2(std::vector<int>& nums){
	int i,j,temp;
	int len = nums.size();
	vector<int> gaps = gap_sequence1(len);
	int gap = gaps.back();
	gaps.pop_back();
	while(gap>0){
		for(i = gap; i<len;i++){
			temp = nums[i];
			j = i;
			while(j>=gap && nums[j-gap]>temp){
				nums[j] = nums[j-gap];
				j-=gap;
			}
			nums[j] = temp; 
		}
		gap = gaps.back();
		gaps.pop_back();
	}
}

