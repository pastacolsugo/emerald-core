
bool airSource (usi* target, usi* temp_in, usi* temp_out){
	// computing inside delta temperature
	short int delta_in = (int)*target - (int)*temp_in;

	// taking the absolute value
	delta_in = (delta_in > 0)? delta_in : -delta_in;

	// computing outside delta temperature
	short int delta_out = (int)*target - (int)*temp_out;

	// taking the absolute value
	delta_out = (delta_out > 0)? delta_out : -delta_out;

	// false = air from outside - true air from inside
	bool air_from_inside = 0;

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