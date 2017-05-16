
TIME getTime (){
	TIME res;
	// printf ("Inserisci:MM\tGG\thh\tmm\n");
 	scanf ("%hu %hu %hu %hu", &res.mese, &res.giorno, &res.ore, &res.minuti);
	return res;
}

usi getTemp (){
	usi res = 0;
	// printf("Inserisci la temperatura: ");
	scanf ("%hu", &res);
	return res;
}

usi getTempInside (){
	return getTemp();
}

usi getTempOutside (){
	return getTemp();
}

usi getHum (){
	usi res = 0;
	// printf("Inserisci l'umidita: ");
	// scanf ("%hu", &res);
	return res;
}

black_magic_data packItUp (TIME tempo_attuale, usi temperatura_in,
	usi temperatura_out, usi umidita, OUT old_output){

	black_magic_data res = {
		tempo_attuale, 
		temperatura_in, 
		temperatura_out, 
		umidita, 
		old_output
	};

	return res;
}

black_magic_data packItUp (TIME tempo_attuale, usi temperatura_in,
	usi temperatura_out, usi umidita){

	black_magic_data res = {
		tempo_attuale, 
		temperatura_in, 
		temperatura_out, 
		umidita
	};

	return res;
}

black_magic_data getData (){
	// reading time from the RTC
	TIME act_time = getTime();

	// reading inside temperature
	usi act_temp_inside = getTempInside();	

	// reading outside temperature
	// usi act_temp_outside = getTempOutside();
	usi act_temp_outside = 0;

	// reading inside humidity
	usi act_hum = getHum();

	// create a variable containing all the data needed
	// time, sensor reading and last output configuration
	black_magic_data response = packItUp(act_time, act_temp_inside, act_temp_outside, act_hum);

	return response;
}
