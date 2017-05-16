
bool airSource (usi target, usi temp_in, usi temp_out){
	// computing inside delta temperature
	usi delta_in = target - temp_in;

	// taking the absolute value
	delta_in = (delta_in > 0)? delta_in : -delta_in;

	// computing outside delta temperature
	usi delta_out = target - temp_out;

	// taking the absolute value
	delta_out = (delta_out > 0)? delta_out : -delta_out;

	bool air_from_inside = 0; // false = aria da fuori - true aria da dentro

	// choose between inside and outside air
	if (delta_out < delta_in) { 
		// taking air from outside
		air_from_inside = false;
		// temp_sens = temperatura_outside;
	} else {
		// taking air from inside
		air_from_inside = true;
		// temp_sens = temperatura_inside;
	}

	// setting the third output value as the air source
	return air_from_inside;
}

bool_triple findHeater (TIME req, usi stag, usi temperatura_inside, 
						usi temperatura_outside, bool_pair stato){
	// res.first	=	heater output value
	// res.second	=	cooler output value
	// res.third	=	air source [inside = true - outside = false]

	// find the temperature to be mantained
	unsigned int t_zero = TEMPERATURA[stag][nT-1].temperatura;
	for (int i=1; i<nT; i++){
		TIME temp = {req.mese, req.giorno, TEMPERATURA[stag][i].orario.ore, TEMPERATURA[stag][i].orario.minuti};
		if (compareTIME(req, temp) == 1){
			t_zero = TEMPERATURA[stag][i-1].temperatura;
			break;
		}
	}

	bool_triple res;
	res.first = false;
	res.second = false;
	res.third = false;
	
	res.third = airSource(t_zero, temperatura_inside, temperatura_outside);	

	usi temp_choose = (res.third)? temperatura_inside : temperatura_outside;

	HYS heatReq = {stato.first, temp_choose, t_zero-dT_inf, heat_dT_inf, heat_dT_sup};
	res.first = reverse_hysteresis(heatReq);

	HYS coolReq = {stato.second, temp_choose, t_zero+dT_sup, cool_dT_inf, cool_dT_sup};
	res.second = hysteresis (coolReq);

	if (res.first == true && res.second == true){
		printf("%i/%i - %i:%i :: ERROR :: findHeater reported double true output\n", req.giorno, req.mese, req.ore, req.minuti);
		printf("\tseason: %i + hum: %i + state: %i %i\n", stag, temp_choose, stato.first, stato.second);
		printf("System override, switching both off... ");
		res.first = false;
		res.second = false;
		printf("done.\n");
	}

	return res;
}