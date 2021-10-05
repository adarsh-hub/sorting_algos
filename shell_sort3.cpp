//
// Created by Adarsh on 4/6/2021.
//
#include "project1.h"
#include <iostream>
#include <math.h>
using namespace std;

vector<int> gap_sequence2(int n){
	//A003586 = 2^p * 3^q
	vector<int> gap_seq;
	int pow2;
	int pow3 = 1;
	while(pow3<=n){
		pow2 = pow3;
		while(pow2<=n){
			gap_seq.push_back(pow2);
			pow2 = pow2*2;
		}
		pow3 = pow3*3;
	}
	//sort(gap_seq.begin(), gap_seq.end(), greater<int>());
	return gap_seq;
}

void shell_sort3(std::vector<int>& nums){
	int i,j,temp;
	int len = nums.size();
	vector<int> gaps = gap_sequence2(len);
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


