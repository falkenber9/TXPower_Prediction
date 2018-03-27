#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <random>

#include "TXPOWER_forest.h"

int main(int argc, char** argv){

	const size_t N = 6172;
	const size_t n = 6;

	float* XY = new float[N*n]; // storage for observed data
	int idx = 0;

	bool first = true;
	std::ifstream input("txpower_p2.csv");
	while(!input.eof()){
		std::string row;
		std::getline(input,row);
		if(row.size() && !first){
			std::stringstream rowS(row);
			while(!rowS.eof()){
				std::string col;
				std::getline(rowS,col,',');
				if(col.size()){
					std::stringstream colS(col);
					double val;
					colS >> val;
					XY[idx++] = val;
				}
			}
		}
		first = false;
	}
	input.close();

	float mae = 0;

	float* Yhat = new float[N];
	for(size_t i=0; i<N; ++i){
		Yhat[i] = txpower_predict(XY+i*n);
	}

	for(size_t i=0; i<N; ++i){
		const float y    = (XY+i*n)[5];
		const float yhat = Yhat[i];
		mae += std::abs(y-yhat)/N;
	}
	std::cout << "MAE on training data = " << mae << std::endl;

	delete[] XY;
	delete[] Yhat;

	return 0;
}
