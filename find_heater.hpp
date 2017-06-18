#include "air_source.hpp"

void findHeat (TIME req, usi stag, usi temperatura_inside, 
						usi temperatura_outside, bool_pair stato, OUT* res){
	
	// find the temperature to be mantained
	unsigned short int t_zero = TEMPERATURE[stag][nT-1].temperature;
	
	usi* t_in = &temperatura_inside;
	usi* t_out = &temperatura_outside;

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
	
	usi* temp_best;
	if (CONTROL_AIR_SOURCE){
		res -> air_source = airSource(&t_zero, t_in, t_out);	

		temp_best = (res->air_source)? t_in : t_out;
	} else {
		res -> air_source = true; // air from inside
		temp_best = t_in;
	}

	HYS heat_Req = {
		stato.first, 
		*temp_best, 
		t_zero-dT_inf, 
		heat_dT_inf, 
		heat_dT_sup
	};	
	res->heater = reverse_hysteresis (&heat_Req);

	HYS cool_Req = {
		stato.second, 
		*temp_best, 
		t_zero+dT_sup, 
		cool_dT_inf, 
		cool_dT_sup
	};
	res->cooler = hysteresis (&cool_Req);

	if (res->heater == true && res->cooler == true){
		char msg1[] = "%i/%i %i:%i | findHeater reported double true output\n";
		char msg2[] = "\tseason: %i + hum: %i + state: %i %i\n";

		// printf(msg1, req.day, req.month, req.hour, req.minute);
		// printf(msg2, stag, temp_best, stato.first, stato.second);
		// printf("Override, switching both off... ");
		res->heater = false;
		res->cooler = false;
		// printf("done.\n");
	}
}
