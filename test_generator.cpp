#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <stdlib.h>
#include "project1.h"
#include <math.h>
#include <vector>
#include <algorithm>
#include <iterator>

/*** INSERT SORTING ALGORITHM HERE ***/
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
/************************************/

std::vector<int> generateTest(int sz, int maxVal, int type)
{
	// sz: size of generated sequence,  maxVal: maximum value that the sequence can have
	// type = 1: random sequence
	// type = 2: almost sorted
	// type = 3: sorted in reverse
	std::vector<int> result;
	for (int i = 0; i < sz; i++) {
		result.push_back(rand() % maxVal + 1);
	}
	switch(type) {
		case 1:
			break;
		case 2:
			std::sort(result.begin(), result.end());
			// 10% unsorted
			for (int i = 0; i < sz/10; i++) {
				std::swap(result[rand() % sz], result[rand() % sz]);
			}
			break;
		case 3:
			std::sort(result.rbegin(), result.rend());
			break;
	}
	return result;
}

void testAlgorithm(std::vector<int> test, void (*algorithm)(std::vector<int>&))
{
	std::vector<int> v1 = test, v2 = test;
	std::sort(v1.begin(), v1.end());
	algorithm(v2);
	if (v1 == v2) {
		std::cout << "CORRECT" << std::endl;
	} else {
		std::cout << "INCORRECT" << std::endl;
	}
}

int main()
{
	// generate new tests
	std::vector<std::vector<int> > tests; 
	tests.push_back(generateTest(10, 10, 1));
	tests.push_back(generateTest(100, 100, 2));
	tests.push_back(generateTest(1000, 1000, 3));

	// try algorithms on generated tests
	// remember to add the '&' operator before the function name
	for (auto test: tests) {
		testAlgorithm(test, &hybrid_sort3);
	}

	return 0;
}
