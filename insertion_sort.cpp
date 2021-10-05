//
// Created by Adarsh on 4/6/2021.
//
#include "project1.h"
#include <iostream>
using namespace std;

void insertion_sort(std::vector<int>& nums) {
	int i,j,temp;
	int size = nums.size();
	for(i = 1; i<size; i++){
		j=i;
		temp = nums[i];
		while(j>0 && nums[j-1]>temp){
			nums[j] = nums[j-1];
			j--;
		}
		nums[j] = temp;
	}
}
