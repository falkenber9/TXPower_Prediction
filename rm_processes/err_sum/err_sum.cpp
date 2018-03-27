#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <set>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <random>

int main(int argc, char** argv){
	std::default_random_engine G;

	const size_t total_summands = 256; // multiple of 4
	const size_t tvals = total_summands/4+2;

	const size_t M = 10000; // repetitions

	std::vector<std::string> methods = {"NN","LIN","RF"};
	const size_t runs = 10;

	float eresult[methods.size()*tvals];
	float vresult[methods.size()*tvals];

	std::memset(eresult,0,3*tvals*sizeof(float));
	std::memset(vresult,0,3*tvals*sizeof(float));

	for(size_t m=0; m<methods.size(); ++m){
		for(size_t r=1; r<=runs; ++r){
			// READ RESULTS

			std::stringstream fns;
			fns << "TX_" << methods[m] << "_" << r;
			const std::string fn(fns.str());

			std::vector<std::pair<float,float>> D;
			
			bool first = true;
			std::ifstream input(fn);
			while(!input.eof()){
				std::string row;
				std::getline(input,row);
				if(row.size() && !first){
					std::stringstream rowS(row);

					std::string col1;
					std::getline(rowS,col1,',');
					std::stringstream colS1(col1);
					double val1;
					colS1 >> val1;

					std::string col2;
					std::getline(rowS,col2,',');
					std::stringstream colS2(col2);
					double val2;
					colS2 >> val2;

					D.emplace_back(val1,val2);
				}
				first = false;
			}
			input.close();

			// COMPUTE EXPECTED ERROR SUMS

			const size_t N = D.size();

			std::uniform_int_distribution<size_t> U(0,N-1);

			std::set<size_t> L = {1,2};
			for(size_t l=4; l<=total_summands; l+=4) L.insert(l);
			for(auto l : L){
				float sumL = 0;
				for(size_t j=0; j<M; ++j){
					float sum = 0;
					for(size_t i=0; i<l; ++i){
						const size_t I = U(G);

						const float y    = D[I].first;
						const float yhat = D[I].second;

						sum += (yhat-y)/l;
					}
					sumL += std::abs(sum/M);
				}

				const size_t idx = m*tvals+((l<=2)?(l/2):(l/4+1));

				eresult[idx] += sumL/runs;
				vresult[idx] += sumL*sumL/runs;
			}
		}
	}

	std::ofstream output("err_sum.csv");
	output << "terms" << ',' << methods[0] << ',' << methods[0] << "_SDEV" << ',' << methods[1] << ',' << methods[1] << "_SDEV" << ',' << methods[2] << ',' << methods[2] << "_SDEV" << std::endl;
	for(size_t i=0; i<tvals; ++i){
		const size_t idx = (i<2)?(i+1):(i-1)*4;
		output << idx << ',' << eresult[i] << ',' << std::sqrt(vresult[i]-eresult[i]*eresult[i]) << ',' << eresult[1*tvals+i] << ',' << std::sqrt(vresult[1*tvals+i]-eresult[1*tvals+i]*eresult[1*tvals+i]) << ',' << eresult[2*tvals+i] << ',' << std::sqrt(vresult[2*tvals+i]-eresult[2*tvals+i]*eresult[2*tvals+i]) << std::endl;
	}
	output.close();

	return 0;
}
