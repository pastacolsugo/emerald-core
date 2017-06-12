
TIME getTime (){
	TIME res;
	// printf ("Inserisci:MM\tGG\thh\tmm\n");
 	scanf ("%hu %hu %hu %hu", &res.month, &res.day, &res.hour, &res.minute);
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
	// return getTemp();
	return 0;
}

usi getHum (){
	usi res = 0;
	// printf("Inserisci l'umidita: ");
	// scanf ("%hu", &res);
	return res;
}

// DEPRECATED
// with old output
// black_magic_data packItUp (TIME tempo_attuale, usi temperatura_in,
// 	usi temperatura_out, usi umidita, OUT old_output){

// 	black_magic_data res = {
// 		tempo_attuale, 
// 		temperatura_in, 
// 		temperatura_out, 
// 		umidita, 
// 		old_output
// 	};

// 	return res;
// }

void packItUp (TIME* time_now, usi* temperature_in,
	usi* temperature_out, usi* hum, black_magic_data* res){

	res->time = *time_now;
	res->temperature_inside =  *temperature_in;
	res->temperature_outside = *temperature_out;
	res->humidity = *hum;	

}

black_magic_data getData (){
	black_magic_data response;

	// reading time from the RTC
	TIME current_time = getTime();

	// reading inside temperature
	usi current_temp_inside = getTempInside();
	// usi act_temp_inside = 0;

	// reading outside temperature
	usi current_temp_outside = getTempOutside();
	// usi act_temp_outside = 0;

	// reading inside humidity
	usi current_hum = getHum();

	// create a variable containing all the data needed
	// time, sensor reading and last output configuration
	packItUp (&current_time, &current_temp_inside, &current_temp_outside,
		&current_hum, &response);

	return response;
}
