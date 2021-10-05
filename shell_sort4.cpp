//
// Created by Adarsh on 4/6/2021.
//
#include "project1.h"
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> gap_sequence3(int n){
	//A033622 = 9*(2^k - 2^k/2) +1 if k is even
	//		  = 8*(2^k) - 6*(2)^(k+1/2) + 1 if k is odd
	vector<int> gap_seq;
	int gap;
	for(int i = 0; i <=n; i++){
		if(i%2 == 0){
			gap = 9*(pow(2,i) - pow(2,i/2)) + 1;
		}
		else{
			gap = 8*(pow(2,i)) - 6*(pow(2,(i+1)/2)) + 1;
		}
		gap_seq.push_back(gap);
	}
	
	sort(gap_seq.begin(), gap_seq.end());
	return gap_seq;
}

void shell_sort4(std::vector<int>& nums){
	int i,j,temp;
	int len = nums.size();
	vector<int> gaps = gap_sequence3(len);
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


