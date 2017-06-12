#include <cstdio>
#include "../data_struct.hpp"

class liquid {
	// setCursor(row, col);
public:
	char visual[2][17];

	int cursor_riga;
	int cursor_colonna;

	// constructor
	// initialize empty matrix
	liquid(){
		cursor_colonna = 0;
		cursor_riga = 0;
		for (int i=0; i<2; i++){
			for (int j=0; j<17; j++){
				visual[i][j] = ' ';
				if (j==16)
					visual[i][j] = 0;
			}
		}
	}

	// empties the matrix
	void clear(){
		for (int i=0; i<2; i++){
			for (int j=0; j<17; j++){
				visual[i][j] = ' ';
				if (j==16)
					visual[i][j] = 0;
			}
		}
	}

	// moves the cursor
	void setCursor (int riga, int colonna){
		cursor_riga = riga;
		cursor_colonna = colonna;
	}

	// prints a string to the matrix at the cursor location
	void print(char* s){
		for (int i=0; *s!=0 && cursor_colonna<16; i++, s++){
			visual[cursor_riga][cursor_colonna] = *s;
			cursor_colonna++;
		}
	}

	// prints a single character at cursor location
	void print (char c){
		visual[cursor_riga][cursor_colonna] = c;
	}

	// prints out the matrix to the console
	void show (){
		for (int i=0; i<2; i++){
			for (int j=0; j<17; j++){
				printf("%c", visual[i][j]);
			}
			printf("\n");
		}
	}

	// update the screen view with latest data
	void update (char* first, char* second){
		setCursor (0, 0);
		print (first);

		setCursor (1, 0);
		print (second);
	}
};

char* firstLine (char* first_line, TIME now){

	// insert day
	if (now.giorno < 10){
		first_line[0] = '0';
	} else {
		first_line[0] = ((now.giorno/10)%10) + '0';
	}
	first_line[1] = (now.giorno%10) + '0';

	// insert month
	if (now.mese < 10){
		first_line[3] = '0';
	} else {
		first_line[3] = '1';
	}
	first_line[4] = (now.mese%10) + '0';

	// insert year
	// first_line[6] = ((now.anno/10)%10) + '0';
	// first_line[7] = (now.anno%10) + '0';

	// insert hours
	if (now.ore < 10) {
		first_line[11] = '0';
	} else {
		first_line[11] = ((now.ore/10)%10) + '0';
	}
	first_line[12] = (now.ore%10) + '0';

	// insert minutes	
	if (now.minuti < 10){
		first_line[14] = '0';
	} else {
		first_line[14] = ((now.minuti/10)%10) + '0';
	}
	first_line[15] = (now.minuti%10) + '0';

	return first_line;
}

void secondLine (char* second_line, OUT out, usi stag, usi temperature){

	second_line[2] = ((temperature/100)%10) + '0';
	second_line[3] = ((temperature/10)%10) + '0';

	if (out.water){
		second_line[7] = '1';
	} else {
		second_line[7] = '0';
	}

	if (out.luci){
		second_line[11] = '1';
	} else {
		second_line[11] = '0';
	}

	second_line[15] = stag + '0';

}

void showTime (screen data, liquid* lcd_p){
	char first_line[17] = "gg/mm/aa   hh:mm";
	char second_line[] = "T:__ W:_ L:_ S:_";

	firstLine (first_line, data.time);

	secondLine (second_line, data.out, data.stag, data.temperature);

	lcd_p -> update (first_line, second_line);
}

int main (){

	liquid lcd, *pointer;
	pointer = &lcd;

	screen in = {
		{ 3, 2, 11, 23 },	// TIME
		{ 1, 0, 0, 0, 0, 0, 0, 0 }, // OUT
		3,	// stag
		284 // temperature [10^-1 C]
	};

	showTime (in, pointer);

	lcd.show();
}

/*
##################
#gg/mm/aa   hh:mm#
#T:23 W:1 L:0 S:1#
##################

*/

//data ora
//cosa sta facendo (?)
//se spingo un pulsante cambio l'orario e la data

