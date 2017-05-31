#include "../../data_struct.hpp"
#include "../../air_source.hpp"
#include <cstdio>

int main (){
	FILE *in;
	in = fopen ("air_source_test_input.txt", "r");
	if (in == NULL){
		return -1;
	}

	int target, inside, outside;


	while (true) {
		fscanf (in, "%i %i %i", &target, &inside, &outside);

		if (target == inside == outside == 0){
			break;
		}

		int d_in = target - inside;
		int d_out = target - outside;
		d_in = (d_in > 0)? d_in :  d_in;
		d_out = (d_out > 0)? d_out : -d_out;	

		bool res = airSource(target, inside, outside);

		printf("%i %i %i %i %i %i\n", target, inside, outside, d_in, d_out, res);
	}
}