#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	string filename;
	cin>> filename;

	ifstream file (filename);

	if (!file.is_open()){
		cout <<"ERROR: input file not found"<< endl;
		return 0;
	}

	vector <int> V;
	int num;
	while (file >> num){
		V.push_back(num);
	}

	if (V.size()== 0){
		cout<< "Error: input file is empty" << endl;
		return 0;	}

	//initialize variables
	double sum =0;
	double mean;
	double median;
	double squared_sum = 0;
	double std_dev;
	for (double i: V){
		sum +=i;
	}

	//calculate mean
    mean= sum/V.size();


	//calculate median
    sort (V.begin(), V.end());

    if (V.size() % 2 == 0){
    	median = (V[V.size()/2-1] + V[V.size()/2])/2.0;
    }else{
    	median= V[V.size()/2];
    }
    
    //calculate standard deviation

    for (double i: V){
    	squared_sum += pow(i- mean, 2);
    }

	std_dev = sqrt(squared_sum / V.size());


	//output results
	cout<< "mean: "<<mean<< endl;
	cout<< "median: "<<median<< endl;
	cout<< "std dev: "<<std_dev<< endl;
    
	
	return 0;
	
}

