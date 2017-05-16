#define on true
#define off false

// IMPORTANTE: non mettere zeri inutili prima dei numeri. Se l'orario e' ore 08:00 mettere 8, 00. NON 08, 00.

typedef unsigned short int usi;


struct HM { //ore minuti
	unsigned short int ore;
	unsigned short int minuti;
};

struct GMS { //giorno mese stagione = GMS
	unsigned short int mese;
	unsigned short int giorno;
	unsigned short int stagione;
};

struct HML { //ore minuti luce = HML
	HM orario;
	bool stato;
};

struct HMT { //ore minuti temperatura
	HM orario;
	unsigned int temperatura;
};

struct HMU { //ore minuti umidita
	HM orario;
	unsigned short int umidita;
};

struct TIME {
	usi mese;
	usi giorno;
	usi ore;
	usi minuti;
};

struct OUT {
	bool luci;
	bool crepuscolo;
	bool heater;
	bool cooler;
	bool air_source;
	bool hum;
	bool dehum;
};

struct black_magic_data {
	TIME time;
	usi temperatura_inside;
	usi temperatura_outside;
	usi umidita;
	OUT output;
};

struct HYS {
	bool stato;
	int value;
	int zero;
	int d_inf;
	int d_sup;
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


