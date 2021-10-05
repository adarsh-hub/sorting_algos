//
// Created by Adarsh on 4/6/2021.
//
#include "project1.h"
#include <iostream>
#include <math.h>

void insertion_sort3(std::vector<int>& nums) {
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

std::vector<int> merge3(std::vector<int>& arr1, std::vector<int>& arr2)
{
    int i = 0, j = 0, k = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();
 	std::vector<int> arr3;
 	
    while (i<n1 && j <n2)
    {
        if (arr1[i] < arr2[j])
            arr3.push_back(arr1[i++]);
        else
            arr3.push_back(arr2[j++]);
    }
 
    while (i < n1)
        arr3.push_back(arr1[i++]);
 
    while (j < n2)
        arr3.push_back(arr2[j++]);
        
	return arr3;
}

void hybrid_sortr3(std::vector<int>& nums, int H){
	
	if(nums.size()>H)
	{	
    	std::size_t const half_size = nums.size() / 2;
    	std::vector<int> S1(nums.begin(), nums.begin() + half_size);
    	std::vector<int> S2(nums.begin() + half_size, nums.end());
    	hybrid_sortr3(S1, H);
    	hybrid_sortr3(S2, H);
    	std::vector<int> S = merge3(S1,S2);
    	nums.swap(S);
	}
	else{
        insertion_sort3(nums);
	}

}

void hybrid_sort3(std::vector<int>& nums){
	
	int len = nums.size();
	double pw = 1.0/6.0;
	int H = pow(len,pw);
	hybrid_sortr3(nums, H);
}
