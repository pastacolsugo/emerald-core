#include "data_struct.hpp"
#include <cstdio>

bool hysteresis (HYS req){
	// proven working correctly
	// 2 April 2017
	if (req.stato == false){
		if (req.value >= req.zero + req.d_sup){
			return 1;
		} else {
			return 0;
		}
	} else {
		if (req.value <= req.zero - req.d_inf){
			return 0;
		} else {
			return 1;
		}
	}
}

bool reverse_hysteresis (HYS req){
	// proven working correctly
	// 2 April 2017
	if (req.stato == true){
		if (req.value >= req.zero + req.d_sup){
			return 0;
		} else {
			return 1;
		}
	} else {
		if (req.value <= req.zero - req.d_inf){
			return 1;
		} else {
			return 0;
		}
	}
}

bool k (HYS t){
	// return hysteresis(t);
	return reverse_hysteresis(t);
}

int main (){
	freopen ("output.txt", "w", stdout);

	HYS alpha = {false, 0, 150, 10, 10};

	for (int i=0; i<=300; i++){
		alpha.value = i;
		int out = k(alpha);
		printf("%i\t%i\n", i, out == 1? 100 : 0);
		alpha.stato = out;
	}

	for (int i=300; i>=0; i--){
		alpha.value = i;
		int out = k(alpha);
		printf("%i\t%i\n", i, out == 1? 100 : 0);
		alpha.stato = out;
	}
}