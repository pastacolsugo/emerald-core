void findHum (TIME req, usi stag, usi hum_sens, bool_pair stato, OUT* res){
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

	HYS humReq = {
		stato.first, hum_sens, hum_zero-dU_inf, hum_dU_inf, hum_dU_sup
	};
	res->hum = reverse_hysteresis (&humReq);

	HYS dehumReq = {
		stato.second, hum_sens, hum_zero+dU_sup, hum_dU_inf, hum_dU_sup
	};
	res->dehum = hysteresis (&dehumReq);

	if (res->hum == true && res->dehum == true){
		char msg1[] = "%i/%i - %i:%i :: findHum reported double true output\n";
		char msg2[] = "\tseason: %i + hum: %i + state: %i %i\n";
		
		printf(msg1, req.day, req.month, req.hour, req.minute);
		printf(msg2, stag, hum_sens, stato.first, stato.second);
		printf("System override, switching both off... ");
		res->hum = false;
		res->dehum = false;
		printf("done.\n");
	}
}