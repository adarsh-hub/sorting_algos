#include <bits/stdc++.h>
#include <chrono>
#include <vector>
using namespace std;



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
	std::uniform_int_distribution<int> distribution(0, n-1);
	std::vector<int> result = get_random_vector(n);
	sort(result.begin(), result.end());
	
	int a = distribution(generator);
	int b = distribution(generator);
	
	std::iter_swap(result.begin()+a, result.begin()+b);
	
	return result;
}

/*** INSERT SORTING FUNCTION HERE ******/
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
/**********************************/
double run_algo(int size, int md)
{
	
	auto start = chrono::high_resolution_clock::now();
	vector<int> v;
	ios_base::sync_with_stdio(false);
	if(md==1){
		v = get_random_vector(size);
	}
	else if(md==2){
		v = get_reverse_vector(size);
	}
	else if(md==3){
		v = get_almost_sorted_vector(size);
	}
	
	insertion_sort(v);

	auto end = chrono::high_resolution_clock::now();


	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	//time_taken *= 1e-9;

	cout << "Time taken by program is : " << fixed
		<< time_taken << setprecision(9);
	cout << " nanosec" << endl;
	
	return time_taken;
}


int main()
{
	//fstream fout;
    //fout.open("HybridSort2_Almost.csv", ios::out | ios::app);
	double t = 0.0;
	int sizes[] = {500,1000,1500,2000,2500,3000,3500,4000,4500,5000};
	int s;
	double times[10];
	for(int i = 0; i<10; i++){
		int s = sizes[i];
		for(int j = 0;j<10;j++){
			t += run_algo(s,2);
		}
		times[i] = t/10;
		//fout<<s<<", "<<times[i]<<"\n";
		t=0.0;
	}
	
	cout << "AVERAGE TIME by program for size 2500 is : " << fixed << times[4] << setprecision(9) << " nanosec" << endl;

	return 0;
}

