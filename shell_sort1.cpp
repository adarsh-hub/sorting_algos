//
// Created by Adarsh on 4/6/2021.
//
#include "project1.h"
#include <iostream>
using namespace std;

//Original Shell Sequence
void shell_sort1(std::vector<int>& nums){
	
	int n = nums.size();
	int x,y,temp;
	for(int gap = n/2; gap>0;gap/=2){
		for(x = gap; x<n;x++){
			temp = nums[x];
			for(y = x; y>= gap && nums[y-gap]>temp; y-=gap){
				nums[y] = nums[y-gap];
			}
			nums[y] = temp;
		}
	}
	
}
