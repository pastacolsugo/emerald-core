
usi findStagione (TIME req){
	usi res = nS-1;
	
	for (usi i=1; i<nS; i++){
		TIME temporary = { STAGIONI[i].mese, STAGIONI[i].giorno, 0, 0};
		
		if (compareTIME(req, temporary) == 1){
			res = STAGIONI[i-1].stagione;
			break;
		}
	}
	return res;
}

bool findLuci (TIME req, usi stag){
	bool res = LUCI[stag][nL-1].stato;
	
	for (int i=1; i<nL; i++){
		TIME temporary = {
			req.mese, 
			req.giorno, 
			LUCI[stag][i].orario.ore, 
			LUCI[stag][i].orario.minuti
		};	//creo un TIME con mese e giorno odierni, ore e minuti del programma

		//per poter fare il paragone delle date
		if (compareTIME(req, temporary) == 1){		
			res = LUCI[stag][i-1].stato;
			break;
		}
	}
	return res;
}

bool findCrepuscolo (TIME req, usi stag){
	bool res = CREPUSCOLO[stag][nCrep-1].stato;
	
	for (int i=1; i<nCrep; i++){
		TIME temporary = {
			req.mese, 
			req.giorno, 
			CREPUSCOLO[stag][i].orario.ore,
			CREPUSCOLO[stag][i].orario.minuti
			};	
		//creo un TIME con mese e giorno odierni, ore e minuti del programma
		
		//per poter fare il paragone delle date
		if (compareTIME(req, temporary) == 1){		
			res = CREPUSCOLO[stag][i-1].stato;
			break;
		}
	}
	return res;
}

bool findWater (TIME req, usi stag){
	bool res = WATER[stag][nW-1].stato;

	for (int i=1; i<nW; i++){
		TIME temporary = {
			req.mese, 
			req.giorno, 
			WATER[stag][i].orario.ore, 
			WATER[stag][i].orario.minuti
		};

		if (compareTIME(req, temporary) == 1){
			res = WATER[stag][i-1].stato;
			break;
		}
	}
	return res;
}