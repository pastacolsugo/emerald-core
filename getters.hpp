
void getTime (TIME* res){
	// printf ("Inserisci:MM\tGG\thh\tmm\n");
 	scanf ("%hu %hu %hu %hu", &res->month, &res->day, &res->hour, &res->minute);

 	if (res->month > 12 || res->day > 31 || res->hour > 24 || res->minute > 59){
 		res->month = 0;
 		res->day = 0;
 		res->hour = 0;
 		res->minute = 0;
 	}		
}

void getTemp (usi* res){
	// printf("Inserisci la temperatura: ");
	scanf ("%hu", res);
}

void getTempInside (usi* res){
	getTemp(res);
}

void getTempOutside (usi* res){
	getTemp(res);
}

void getHum (usi* res){
	getTemp(res);
}

void packItUp (TIME* time_now, usi* temperature_in,
	usi* temperature_out, usi* hum, black_magic_data* res){

	res->time = *time_now;
	res->temperature_inside =  *temperature_in;
	res->temperature_outside = *temperature_out;
	res->humidity = *hum;	

}

void getData (black_magic_data* response){
	// reading time from the RTC
	getTime (&(response->time));

	// reading inside temperature
	if (CONTROL_HEAT){
		getTempInside(&(response->temperature_inside));
		// usi act_temp_inside = 0;
	}

	// reading outside temperature
	if (CONTROL_AIR_SOURCE){
		getTempOutside(&(response->temperature_outside));
		// usi act_temp_outside = 0;
	}

	// reading inside humidity
	if (CONTROL_HUMIDITY){
		getHum(&(response->humidity));
	}

	// create a variable containing all the data needed
	// time, sensor reading and last output configuration
	// packItUp (&current_time, &current_temp_inside, &current_temp_outside,
		// &current_hum, &response);

}
