#include "air_source.hpp"

bool_triple findHeater (TIME req, usi stag, usi temperatura_inside, 
						usi temperatura_outside, bool_pair stato){
	// res.first	=	heater output value
	// res.second	=	cooler output value
	// res.third	=	air source [inside = true - outside = false]
	
	bool_triple res = {false, false, false};

	// find the temperature to be mantained
	unsigned int t_zero = TEMPERATURE[stag][nT-1].temperature;
	
	for (int i=1; i<nT; i++){
		TIME temp = {
			req.month, 
			req.day, 
			TEMPERATURE[stag][i].time.hour, 
			TEMPERATURE[stag][i].time.minute
		};

		if (compareTIME(&req, &temp) == 1){
			t_zero = TEMPERATURE[stag][i-1].temperature;
			break;
		}
	}
	
	res.third = airSource(&t_zero, &temperatura_inside, &temperatura_outside);	

	usi temp_best = (res.third)? temperatura_inside : temperatura_outside;

	HYS heat_Req = {
		stato.first, 
		temp_best, 
		t_zero-dT_inf, 
		heat_dT_inf, 
		heat_dT_sup
	};	
	res.first = reverse_hysteresis (&heat_Req);

	HYS cool_Req = {
		stato.second, 
		temp_best, 
		t_zero+dT_sup, 
		cool_dT_inf, 
		cool_dT_sup
	};
	res.second = hysteresis (&cool_Req);

	if (res.first == true && res.second == true){
		char msg1[] = "%i/%i %i:%i | findHeater reported double true output\n";
		char msg2[] = "\tseason: %i + hum: %i + state: %i %i\n";

		printf(msg1, req.day, req.month, req.hour, req.minute);
		printf(msg2, stag, temp_best, stato.first, stato.second);
		printf("Override, switching both off... ");
		res.first = false;
		res.second = false;
		printf("done.\n");
	}

	return res;
}


