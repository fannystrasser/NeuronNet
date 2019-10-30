#include "random.h"


RandomNumbers::RandomNumbers(unsigned long int seed ) {
	if (seed == 0) {
        std::random_device rd;
        seed = rd();
    }
    rng = std::mt19937(seed);
}



void RandomNumbers::uniform_double(std::vector<double>& v, double lower, double upper) {
	for ( size_t i(0) ; i<v.size() ; ++i ) {
		v[i] = uniform_double(lower, upper); 
	}
}
 
double RandomNumbers::uniform_double(double lower, double upper) {
	 std::uniform_real_distribution<> unif(lower, upper);
    return unif(rng);
}
    
void RandomNumbers::normal(std::vector<double>& v, double mean, double sd) {
	for ( size_t i(0) ; i<v.size() ; ++i ) {
		v[i] = normal(mean, sd); 
	}
}
    
double RandomNumbers::normal(double mean, double sd) {
	std::normal_distribution<> norm(mean, sd);
    return norm(rng);
}
    
void RandomNumbers::poisson(std::vector<int>& v, double mean) {
	for (size_t i(0) ; i<v.size() ; ++i ) {
		v[i] = poisson(mean);
	}
}
    
int RandomNumbers::poisson(double mean) {
	std::poisson_distribution<int> pois(mean);
	return pois(rng);
}
    
