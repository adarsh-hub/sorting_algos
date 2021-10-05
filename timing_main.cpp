#include "project1.h"
#include <chrono>
#include <functional>
#include <cmath>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include <locale.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdio>
#include <unordered_map>
#include <time.h>
#include <random>
#include <algorithm>


typedef std::function<void(std::vector<int>&)> SORT_FUNCTION;
typedef std::function<std::vector<int>(unsigned)> GET_VECTOR_FUNCTION;


/*** INSERT SORTING ALGORITHM HERE ***/
std::vector<int> gap_sequence3(int n){
	//A033622 = 9*(2^k - 2^k/2) +1 if k is even
	//		  = 8*(2^k) - 6*(2)^(k+1/2) + 1 if k is odd
	std::vector<int> gap_seq;
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
	std::vector<int> gaps = gap_sequence3(len);
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
/************************************/

static const std::unordered_map<std::string, SORT_FUNCTION> SORT_MAP = {

	{"shell_sort4", shell_sort4}

};

std::vector<int> get_reverse_vector(int n){
	//Generate vector in reverse order
	std::default_random_engine generator;

	srand(time(0));
	int a = rand() % 10;
	int b = rand() % 10000;

	std::uniform_int_distribution<int> distribution(a, b);

	std::vector<int> result;
	for (int i = 0; i < n; ++i) {
		int number = distribution(generator);
		result.push_back(number);
	}
	sort(result.begin(), result.end(), std::greater<int>());
	return result;
}

std::vector<int> get_random_vector(int n){
	//Generate vector in random order
	std::default_random_engine generator;

	srand(time(0));
	int a = rand() % 10;
	int b = rand() % 10000;

	std::uniform_int_distribution<int> distribution(a, b);

	std::vector<int> result;
	for (int i = 0; i < n; ++i) {
		int number = distribution(generator);
		result.push_back(number);
	}
	
	return result;
}

std::vector<int> get_almost_sorted_vector(int n){
	//Generate vector that is almost sorted
	std::default_random_engine generator;

	srand(time(0));
	int a = rand() % 10;
	int b = rand() % 10000;

	std::uniform_int_distribution<int> distribution(a, b);

	std::vector<int> result;
	for (int i = 0; i < n; ++i) {
		int number = distribution(generator);
		result.push_back(number);
	}
	
	sort(result.begin(), result.end());
	
	std::vector<int>::iterator i1, i2, i3, i4, i5;
	i1 = result.begin()+1;
	i2 = result.begin()+2;
	i3 = result.begin()+3;
	i4 = result.begin()+4;
	i5 = result.begin()+5;
	
	std::vector<int>::iterator e1, e2, e3, e4, e5;
	e1 = result.end()-1;
	e2 = result.end()-2;
	e3 = result.end()-3;
	e4 = result.end()-4;
	e5 = result.end()-5;
	
	std::iter_swap(i1, e3);
	std::iter_swap(i3, e2);
	std::iter_swap(i5, e4);
	std::iter_swap(i2, e1);
	std::iter_swap(i4, e2);
	
	return result;
}

static const std::unordered_map<std::string, GET_VECTOR_FUNCTION> GET_VECTOR_MAP = { 

	/* These functions below need to be implemented. You can use uniform_int_distribution<int> in the process of 
	generating a random or almost sorted vector
	*/
	{"reverse", get_reverse_vector},
	{"random", get_random_vector},
	{"almost_sorted", get_almost_sorted_vector},
};

void save_data(const std::string& dir_name, const std::string& file_name,
	unsigned input_size, uint64_t elapsed_time_sum, uint64_t num_comparisons_sum, unsigned num_runs)
{

	std::ofstream out;
	out.open("C:\\Users\\Adarsh\\Desktop\\UCI\\SPRING 2021\\CS 165\\project_1\\phase 2\\" +dir_name + "\\"+ file_name + ".csv", std::ofstream::out | std::ofstream::app);
	out << input_size << ",";
	out <<  static_cast<uint64_t>(round(elapsed_time_sum / num_runs))<<",";
	out << (int) round(num_comparisons_sum /  num_runs)<< "\n";
	out.close();
}

void run_experiment(unsigned min_input_size, unsigned input_size, unsigned num_runs)
{

	for (const auto& file_name_func : GET_VECTOR_MAP)
	{
		std::string file_name = file_name_func.first;

		std::vector<int> nums = file_name_func.second(input_size);
		 
		for (const auto& dir_name_func : SORT_MAP)
		{

			std::string dir_name = dir_name_func.first;
			if(min_input_size == input_size){ // this is expected to delete the file if we are at the beginning of the experiment. Late in save_data() it would be
			// created and getting appended 
				 std::string file_temp = "C:\\Users\\Adarsh\\Desktop\\UCI\\SPRING 2021\\CS 165\\project_1\\phase 2\\" +dir_name + "\\"+ file_name + ".csv";
				 std::remove(file_temp.c_str());
				 std::cout << file_temp << std::endl; 
			}
			auto temp = nums;
			uint64_t  elapsed_time_sum = 0;
			uint64_t num_comparisons_sum = 0;
			for (unsigned i = 0; i < num_runs; ++i)
			{
				auto start_time = std::chrono::steady_clock::now();

			    dir_name_func.second(temp); // calling your sort function on the input temp; alter the arguments as needed

				auto end_time = std::chrono::steady_clock::now();
				elapsed_time_sum += std::chrono::nanoseconds(end_time - start_time).count();
			}
			save_data(dir_name, file_name, input_size, elapsed_time_sum, num_comparisons_sum, num_runs);
		}

	}
}

void run_experiments(unsigned min_input_size, unsigned max_input_size, double factor, unsigned num_runs)
{

	for (unsigned input_size = min_input_size; input_size <= max_input_size; input_size *= factor)
	{
		
		run_experiment(min_input_size, input_size, num_runs);
		std::cout << "Experiments with input size "<< input_size <<" for "<< num_runs <<" runs"<<" are done" << std::endl;
	}
}

int main()
{ 


	run_experiments(2, 100, 2, 10);
	
	return 0;

}
