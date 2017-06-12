bool_pair findHum (TIME req, usi stag, usi hum_sens, bool_pair stato){
	// res.first	=	humidifier output
	// res.second	=	dehumidifier output

	unsigned int hum_zero = HUMIDITY[stag][nU-1].humidity;
	for (int i=1; i<nU; i++){
		usi hour = HUMIDITY[stag][i].time.hour;
		usi minute = HUMIDITY[stag][i].time.minute;
		TIME temp = { req.month, req.day, hour, minute};

		if (compareTIME(&req, &temp) == 1){
			hum_zero = HUMIDITY[stag][i-1].humidity;
			break;
		}
	}

	bool_pair res;

	HYS humReq = {
		stato.first, hum_sens, hum_zero-dU_inf, hum_dU_inf, hum_dU_sup
	};
	res.first = reverse_hysteresis (&humReq);

	HYS dehumReq = {
		stato.second, hum_sens, hum_zero+dU_sup, hum_dU_inf, hum_dU_sup
	};
	res.second = hysteresis (&dehumReq);

	if (res.first == true && res.second == true){
		char msg1[] = "%i/%i - %i:%i :: findHum reported double true output\n";
		char msg2[] = "\tseason: %i + hum: %i + state: %i %i\n";
		
		printf(msg1, req.day, req.month, req.hour, req.minute);
		printf(msg2, stag, hum_sens, stato.first, stato.second);
		printf("System override, switching both off... ");
		res.first = false;
		res.second = false;
		printf("done.\n");
	}

	return res;
}