#include <cstdio>
#include "control.hpp"
#include "data_struct.hpp"
#include "programma.hpp"
#include "getters.hpp"
#include "hysteresis.hpp"
#include "finder_1.hpp"
#include "find_heater.hpp"
#include "find_hum.hpp"
#include "lcd.hpp"

using namespace std;

usi index = 0;

void printout (OUT req, black_magic_data t){
	// printf("light: %d\the: %d\tcool: %d\thum: %d\tdehum: %d\n", 
	// 	req.light, req.heater, req.cooler, req.hum, req.dehum);
	// printf("%i) %i %i - %i:%i\t", 
		// index, t.time.day, t.time.month, t.time.hour, t.time.minute);
	// printf("%i\t", t.temperature_inside);
	// printf("%i\t", t.humidity);
	// printf("light: %i ", req.light);
	// printf("light2: %i ", req.light2);
	// printf("water: %i ", req.water);
	// printf("heat: %i ", req.heater);
	// printf("cool: %i ", req.cooler);
	// printf("%i ", req.heater == 1? 10 : 0);
	// printf("%i ", req.cooler == 1? 10 : 0);
	// printf("%i ", req.hum == 1? 10 : 0);
	// printf("%i", req.dehum == 1? 10 : 0);
	// printf("\n");

}

OUT black_magic_box (black_magic_data req, usi* seas){
	// find current season
	usi current_season = findSeason (&req.time);
	*seas = current_season;
	// printf ("stagione = %d\n", current_season);

	OUT res = {false, false, false, false, false, false, false, false};
	
	// compute light status
	
	if (CONTROL_LIGHT1){
		res.light 	= findLight (&req.time, &current_season);
	}
	
	if (CONTROL_LIGHT2) {
		res.light2  = findLight2 (&req.time, &current_season);
	}

	if (CONTROL_WATER) {
		res.water 	= findWater (&req.time, &current_season);
	}
	
	if (CONTROL_HEAT){
		// create state variable for temperature managing group
		bool_pair heat_state = makeBoolPair (req.output.heater, req.output.cooler);

		// computing temperature management output
		findHeater (req.time, current_season, req.temperature_inside,
		req.temperature_outside, heat_state, &res);
	}
	
	if (CONTROL_HUMIDITY){
		// create state variable for humidity managing group
		bool_pair hum_state = makeBoolPair (req.output.hum, req.output.dehum);

		// computing humidity management output
		findHum (req.time, current_season,
			req.humidity, hum_state, &res);
	}

	return res;
}

int main (){
	// char file_path[] = "/Users/sugo/Google Drive/serra_mirko/v2/day_sim1.txt";
	// freopen (file_path, "r", stdin);

	liquid lcd;

	// create output configuration
	// output1 is the one that will be applied
	// output2 is the one that has last been applied
	OUT output1, output2 = {0, 0, 0, 0, 0};
	usi season = 0;

	while (true){
		black_magic_data input;

		input = getData();	

		input.output = output2;
		
		if (input.time.month == 0){
			return 0;
		}
		
		// black_magic_box is going to compute the next output configuration
		// taking the actual state as input
		output1 = black_magic_box (input, &season);

		// printf("%i\t%hu\t\t", input.output.heater, input.temperature);
		printout (output1, input);

		// 
		// apply output1
		// 



		// update screen
		screen lcd_data = {
			input.time,
			output1,
			season, //stagione
			input.temperature_inside
		};

		showTime (&lcd_data, &lcd);
		lcd.show();

		output2 = output1;

		index++;
	}
}