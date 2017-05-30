#include <cstdio>
#include "data_struct.hpp"
#include "programma.hpp"
#include "getters.hpp"
#include "hysteresis.hpp"
#include "finder_1.hpp"
#include "find_heater.hpp"
#include "find_hum.hpp"

using namespace std;

usi index = 0;

void printout (OUT req, black_magic_data t){
	// printf("luci: %d\the: %d\tcool: %d\thum: %d\tdehum: %d\n", 
	// 	req.luci, req.heater, req.cooler, req.hum, req.dehum);
	// printf("%i) %i %i - %i:%i\t", 
	// 	index, t.time.giorno, t.time.mese, t.time.ore, t.time.minuti);
	// printf("%i\t", t.temperatura_inside);
	// printf("%i\t", t.umidita);
	// printf("luci: %i ", req.luci);
	// printf("crep: %i ", req.crepuscolo);
	// printf("water: %i ", req.water);
	// printf("heat: %i ", req.heater);
	// printf("cool: %i ", req.cooler);
	// printf("%i ", req.heater == 1? 10 : 0);
	// printf("%i ", req.cooler == 1? 10 : 0);
	// printf("%i ", req.hum == 1? 10 : 0);
	// printf("%i", req.dehum == 1? 10 : 0);
	printf("\n");

}

OUT black_magic_box (black_magic_data req){
	// find actual season
	usi stagione_att = findStagione (req.time);
	// printf ("stagione = %d\n", stagione_att);

	// compute light status
	bool luci_output 		= findLuci 	(req.time, stagione_att);
	bool crepuscolo_output 	= findCrepuscolo (req.time, stagione_att);
	bool water_output		= findWater (req.time, stagione_att);
	
	// create state variable for temperature managing group
	bool_pair heat_state = makeBoolPair (req.output.heater, req.output.cooler);

	// computing temperature management output
	bool_triple heater_output = findHeater (req.time, stagione_att, 
		req.temperatura_inside, req.temperatura_outside, heat_state);
	
	// create state variable for humidity managing group
	bool_pair hum_state = makeBoolPair (req.output.hum, req.output.dehum);

	// computing humidity management output
	bool_pair hum_output = findHum (req.time, stagione_att,
		req.umidita, hum_state);
	// bool_pair hum_output = makeBoolPair (false, false);
	
	// pack output data to be send back
	OUT res = {
		luci_output, 
		crepuscolo_output, 
		water_output,
		heater_output.first, // heater
		heater_output.second, // cooler 
		heater_output.third, // air source
		hum_output.first, // humidifier
		hum_output.second // dehumidifier
	};

	return res;
}

int main (){
	char file_path[] = "/Users/sugo/Google Drive/serra_mirko/v2/day_sim2.txt";
	freopen (file_path, "r", stdin);

	// create output configuration
	// output1 is the one that will be applied
	// output2 is the one that has last been applied
	OUT output1, output2 = {0, 0, 0, 0, 0};

	while (true){
		black_magic_data input;

		input = getData();	

		input.output = output2;
		
		if (input.time.mese == 0){
			return 0;
		}
		
		// black_magic_box is going to compute the next output configuration
		// taking the actual state as input
		output1 = black_magic_box (input);

		// printf("%i\t%hu\t\t", input.output.heater, input.temperatura);
		printout (output1, input);

		//apply output1

		output2 = output1;

		index++;
	}
}