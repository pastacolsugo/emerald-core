#include <cstdio>
#include "programma.hpp"
#include "getters.hpp"

using namespace std;

usi index = 0;

void printout (OUT req, black_magic_data t){
	// printf("luci: %d\the: %d\tcool: %d\thum: %d\tdehum: %d\n", req.luci, req.heater, req.cooler, req.hum, req.dehum);
	printf("%i) %i %i - %i:%i\t", index++, t.time.giorno, t.time.mese, t.time.ore, t.time.minuti);
	printf("%i\t", t.temperatura_inside);
	// printf("luci: %i ", req.luci);
	// printf("crep: %i ", req.crepuscolo);
	printf("heat: %i ", req.heater);
	printf("cool: %i ", req.cooler);
	// printf("humi: %i ", req.hum);
	// printf("dehu: %i ", req.dehum);
	printf("\n");

}

bool_pair makeBoolPair (bool a, bool b){
	bool_pair res = {a, b};
	return res;
}

black_magic_data packItUp (TIME tempo_attuale, usi temperatura_in, usi temperatura_out, usi umidita, OUT old_output){
	
	black_magic_data res = {tempo_attuale, temperatura_in, temperatura_out, umidita, old_output};

	return res;
}

// se sono nell'ordine temporale corretto (t1 prima di t2) = 1
// se sono lo stesso momento  (t1 == t2) = 0
// se sono nell'ordine temporale inverso (t1 dopo t2) = -1
short int compareTIME (TIME t1, TIME t2){		// 1 t1 before t2 / 0 t1==t2 / -1 t1 after t2
	if (t1.mese < t2.mese){				
		return 1;
	}
	if (t1.mese > t2.mese){
		return -1;
	}

	if (t1.giorno < t2.giorno){
		return 1;
	}	
	if (t1.giorno > t2.giorno){
		return -1;
	}

	if (t1.ore < t2.ore){
		return 1;
	}
	if (t1.ore > t2.ore){
		return -1;
	}

	if (t1.minuti < t2.minuti){
		return 1;
	}
	if (t1.minuti > t2.minuti){
		return -1;
	}
	return 0;
}

usi findStagione (TIME req){
	usi res = nS-1;
	for (usi i=1; i<nS; i++){
		TIME temp = { STAGIONI[i].mese, STAGIONI[i].giorno, 0, 0};
		if (compareTIME(req, temp) == 1){
			res = STAGIONI[i-1].stagione;
			break;
		}
	}
	return res;
}

bool findLuci (TIME req, usi stag){
	bool res = LUCI[stag][nL-1].stato;
	for (int i=1; i<nL; i++){
		TIME temp = {req.mese, req.giorno, LUCI[stag][i].orario.ore, LUCI[stag][i].orario.minuti};	//creo un TIME con mese e giorno odierni, ore e minuti del programma
		if (compareTIME(req, temp) == 1){		//per poter fare il paragone delle date
			res = LUCI[stag][i-1].stato;
			break;
		}
	}
	return res;
}

bool findCrepuscolo (TIME req, usi stag){
	bool res = CREPUSCOLO[stag][nCrep-1].stato;
	for (int i=1; i<nCrep; i++){
		TIME temp = {req.mese, req.giorno, CREPUSCOLO[stag][i].orario.ore, CREPUSCOLO[stag][i].orario.minuti};	//creo un TIME con mese e giorno odierni, ore e minuti del programma
		if (compareTIME(req, temp) == 1){		//per poter fare il paragone delle date
			res = CREPUSCOLO[stag][i-1].stato;
			break;
		}
	}
	return res;
}

bool hysteresis (HYS req){
	// proven working correctly
	// 2 April 2017
	if (req.stato == false){
		if (req.value >= req.zero + req.d_sup){
			return 1;
		} else {
			return 0;
		}
	} else {
		if (req.value <= req.zero - req.d_inf){
			return 0;
		} else {
			return 1;
		}
	}
}

bool reverse_hysteresis (HYS req){
	// proven working correctly
	// 2 April 2017
	if (req.stato == true){
		if (req.value >= req.zero + req.d_sup){
			return 0;
		} else {
			return 1;
		}
	} else {
		if (req.value <= req.zero - req.d_inf){
			return 1;
		} else {
			return 0;
		}
	}
}

bool_triple findHeater (TIME req, usi stag, usi temperatura_inside, usi temperatura_outside, bool_pair stato){
	// res.first	=	heater output value
	// res.second	=	cooler output value
	// res.third	=	air source [inside = true - outside = false]

	// find the temperature to be mantained
	unsigned int t_zero = TEMPERATURA[stag][nT-1].temperatura;
	for (int i=1; i<nT; i++){
		TIME temp = {req.mese, req.giorno, TEMPERATURA[stag][i].orario.ore, TEMPERATURA[stag][i].orario.minuti};
		if (compareTIME(req, temp) == 1){
			t_zero = TEMPERATURA[stag][i-1].temperatura;
			break;
		}
	}

	bool_triple res;
	res.first = false;
	res.second = false;
	res.third = false;

	// computing inside delta temperature
	usi delta_in = t_zero - temperatura_inside;

	// taking the absolute value
	delta_in = (delta_in > 0)? delta_in : -delta_in;

	// computing outside delta temperature
	usi delta_out = t_zero - temperatura_outside;

	// taking the absolute value
	delta_out = (delta_out > 0)? delta_out : -delta_out;

	usi temp_sens;
	bool air_from_inside = 0; // false = aria da fuori - true aria da dentro

	// choose between inside and outside air
	if (delta_out < delta_in) { 
		// taking air from outside
		air_from_inside = false;
		temp_sens = temperatura_outside;
	} else {
		// taking air from inside
		air_from_inside = true;
		temp_sens = temperatura_inside;
	}

	// setting the third output value as the air source
	res.third = air_from_inside;

	HYS heatReq = {stato.first, temp_sens, t_zero-dT_inf, heat_dT_inf, heat_dT_sup};
	res.first = reverse_hysteresis (heatReq);

	HYS coolReq = {stato.second, temp_sens, t_zero+dT_sup, cool_dT_inf, cool_dT_sup};
	res.second = hysteresis (coolReq);

	if (res.first == true && res.second == true){
		printf("%i/%i - %i:%i :: ERROR :: findHeater reported double true output\n", req.giorno, req.mese, req.ore, req.minuti);
		printf("\tseason: %i + hum: %i + state: %i %i\n", stag, temp_sens, stato.first, stato.second);
		printf("System override, switching both off... ");
		res.first = false;
		res.second = false;
		printf("done.\n");
	}

	return res;
}

bool_pair findHum (TIME req, usi stag, usi hum_sens, bool_pair stato){
	// res.first	=	humidifier output
	// res.second	=	dehumidifier output

	unsigned int hum_zero = HUMIDITY[stag][nU-1].umidita;
	for (int i=1; i<nU; i++){
		TIME temp = {req.mese, req.giorno, HUMIDITY[stag][i].orario.ore, HUMIDITY[stag][i].orario.minuti};
		if (compareTIME(req, temp) == 1){
			hum_zero = HUMIDITY[stag][i-1].umidita;
			break;
		}
	}
	bool_pair res;

	HYS humReq = {stato.first, hum_sens, hum_zero-dU_inf, hum_dU_inf, hum_dU_sup};
	res.first = reverse_hysteresis (humReq);

	HYS dehumReq = {stato.second, hum_sens, hum_zero+dU_sup, hum_dU_inf, hum_dU_sup};
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

OUT black_magic_box (black_magic_data req){
	// find actual season
	usi stagione_att = findStagione (req.time);
	// printf ("stagione = %d\n", stagione_att);

	// compute light status
	bool luci_output = findLuci(req.time, stagione_att);
	bool crepuscolo_output = findCrepuscolo(req.time, stagione_att);
	
	// create state variable for temperature managing group
	bool_pair heat_group_state = makeBoolPair (req.output.heater, req.output.cooler);

	// computing temperature management output
	bool_triple heater_output = findHeater(req.time, stagione_att, req.temperatura_inside, req.temperatura_outside, heat_group_state);
	
	// create state variable for humidity managing group
	bool_pair hum_state = makeBoolPair (req.output.hum, req.output.dehum);

	// computing humidity management output
	bool_pair hum_output = findHum(req.time, stagione_att, req.umidita, hum_state);
	
	// pack output data to be send back
	OUT res = {
		luci_output, 
		crepuscolo_output, 
		heater_output.first, // heater
		heater_output.second, // cooler 
		heater_output.third, // air source
		hum_output.first, // humidifier
		hum_output.second // dehumidifier
	};

	return res;
}

int main (){

	freopen ("/Users/sugo/Google Drive/serra_mirko/v2/day_sim.txt", "r", stdin);

	// create output configuration
	// output1 is the one that will be applied
	// output2 is the one that has last been applied
	OUT output1, output2 = {0, 0, 0, 0, 0};

	while (true){
		black_magic_data input;

		// reading time from the RTC
		TIME act_time = getTime();

		// fake check to terminate testing
		if (act_time.mese == 0){
			return 0;
		}

		// reading inside temperature
		usi act_temp_inside = getTempInside();	

		// reading outside temperature
		// usi act_temp_outside = getTempOutside();
		usi act_temp_outside = 0;

		// reading inside humidity
		usi act_hum = getHum();

		// create a variable containing all the data needed
		// time, sensor reading and last output configuration
		input = packItUp(act_time, act_temp_inside, act_temp_outside, act_hum, output2);

		// black_magic_box is going to compute the next output configuration
		// taking the actual state as input
		output1 = black_magic_box (input);
		// printf("%i\t%hu\t\t", input.output.heater, input.temperatura);
		printout (output1, input);
		//apply output1
		output2 = output1;
	}
}