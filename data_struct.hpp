
typedef unsigned short int usi;

struct HM { //hour minute
	unsigned short int hour;
	unsigned short int minute;
};

struct DMS { //day month season = DMS
	unsigned short int month;
	unsigned short int day;
	unsigned short int season;
};

struct HML { //hour minute light = HML
	HM time;
	bool state;
};

typedef HML HMW; // hour minute water

struct HMT { //hour minute temperature
	HM time;
	unsigned short int temperature;
};

struct HMH { //hour minute humidity
	HM time;
	unsigned short int humidity;
};

struct TIME {
	usi month;
	usi day;
	usi hour;
	usi minute;
};

struct OUT {
	bool light;
	bool light2;
	bool water;
	bool heater;
	bool cooler;
	bool air_source;
	bool hum;
	bool dehum;
};

struct black_magic_data {
	TIME time;
	usi temperature_inside;
	usi temperature_outside;
	usi humidity;
	OUT output;
};

struct HYS {
	bool state;
	int value;
	int zero;
	int d_inf;
	int d_sup;
};

struct screen {
	TIME time;
	OUT out;
	usi stag;
	usi temperature;
};

struct bool_pair {
	bool first;
	bool second;
};

struct bool_triple {
	bool first;
	bool second;
	bool third;
};

bool_pair makeBoolPair (bool a, bool b){
	bool_pair res = {a, b};
	return res;
}

// if they are in correct order timewise (t1 then t2) = 1
// if they are the same istant (t1 == t2) = 0
// if they are in reverse order timewise (t2 then t1) = -1
short int compareTIME (TIME* t1, TIME* t2){		
	if (t1->month < t2->month){				
		return 1;
	}
	if (t1->month > t2->month){
		return -1;
	}

	if (t1->day < t2->day){
		return 1;
	}	
	if (t1->day > t2->day){
		return -1;
	}

	if (t1->hour < t2->hour){
		return 1;
	}
	if (t1->hour > t2->hour){
		return -1;
	}

	if (t1->minute < t2->minute){
		return 1;
	}
	if (t1->minute > t2->minute){
		return -1;
	}
	return 0;
}


