bool_pair findHum (TIME req, usi stag, usi hum_sens, bool_pair stato){
	// res.first	=	humidifier output
	// res.second	=	dehumidifier output

	unsigned int hum_zero = HUMIDITY[stag][nU-1].umidita;
	for (int i=1; i<nU; i++){
		usi ore = HUMIDITY[stag][i].orario.ore;
		usi min = HUMIDITY[stag][i].orario.minuti;
		TIME temp = { req.mese, req.giorno,	ore, min};

		if (compareTIME(req, temp) == 1){
			hum_zero = HUMIDITY[stag][i-1].umidita;
			break;
		}
	}

	bool_pair res;

	HYS humReq = {
		stato.first, hum_sens, hum_zero-dU_inf, hum_dU_inf, hum_dU_sup
	};
	res.first = reverse_hysteresis (humReq);

	HYS dehumReq = {
		stato.second, hum_sens, hum_zero+dU_sup, hum_dU_inf, hum_dU_sup
	};
	res.second = hysteresis (dehumReq);

	if (res.first == true && res.second == true){
		printf("%i/%i - %i:%i :: ERROR :: findHum reported double true output\n", req.giorno, req.mese, req.ore, req.minuti);
		printf("\tseason: %i + hum: %i + state: %i %i\n", stag, hum_sens, stato.first, stato.second);
		printf("System override, switching both off... ");
		res.first = false;
		res.second = false;
		printf("done.\n");
	}

	return res;
}