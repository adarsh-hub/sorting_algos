//
// Created by Adarsh on 4/6/2021.
//
#include <bits/stdc++.h>
using namespace std;
#include "project1.h"

void merge(std::vector<int>& v, int init, int mid, int end)
{
	int temp = mid + 1;

	if (v[mid] <= v[temp]) {
		return;
	}
	while (init <= mid && temp <= end) {

		if (v[init] <= v[temp]) {
			init++;
		}
		else {
			int value = v[temp];
			int index = temp;

			while (index != init) {
				v[index] = v[index - 1];
				index--;
			}
			v[init] = value;

			init++;
			mid++;
			temp++;
		}
	}
}

void mergeSort(std::vector<int>& arr, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}


void merge_sort(std::vector<int>& nums){    
    mergeSort(nums, 0 , nums.size()-1);
}




