void printOutput (OUT* data){
	char out_buf[100] = "light1:  \nlight2:  \nwater:  \nheater:  \ncooler:  \nair_source:  \nhum:  \ndehum:  \n-------------\n";

	out_buf[8] 	= data->light 	+ '0';
	out_buf[18] = data->light2 	+ '0';
	out_buf[27] = data->water 	+ '0';
	out_buf[37] = data->heater 	+ '0';
	out_buf[47] = data->cooler 	+ '0';
	out_buf[61] = data->air_source + '0';
	out_buf[68] = data->hum 	+ '0';
	out_buf[76] = data->dehum 	+ '0';

	Serial.print(out_buf);
}

void applyOutput (OUT* data){
	// printOutput (data);

	if (CONTROL_LIGHT1) {
		dw (PIN_LIGHT1, (PIN_LIGHT1_INV)? !(data->light) : (data->light));
	}

	if (CONTROL_LIGHT2) {
		dw (PIN_LIGHT2, (PIN_LIGHT2_INV)? !(data->light2) : (data->light2));
	}

	if (CONTROL_WATER) {
		dw (PIN_WATER, (PIN_WATER_INV)? !(data->water) : (data->water));
	}

	if (CONTROL_HEAT) {
		dw (PIN_HEATER, (PIN_HEATER_INV)? !(data->heater) : (data->heater));
	}

	if (CONTROL_HUMIDITY) {
		dw (PIN_HUMI, (PIN_HUMI_INV)? !(data->hum) : (data->hum));
	}

	if (CONTROL_AIR_SOURCE){
		dw (PIN_AIR_SOURCE, (PIN_AIR_SOURCE_INV)? !(data->air_source) : (data->air_source));
	}
}
