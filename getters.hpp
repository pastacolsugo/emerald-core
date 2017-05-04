

TIME getTime (){
	TIME res;
	// printf ("Inserisci:MM\tGG\thh\tmm\n");
 	scanf ("%hu %hu %hu %hu", &res.mese, &res.giorno, &res.ore, &res.minuti);
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
	return getTemp();
}

usi getHum (){
	usi res = 0;
	// printf("Inserisci l'umidita: ");
	// scanf ("%hu", &res);
	return res;
}

