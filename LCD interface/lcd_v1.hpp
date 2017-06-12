// #include <cstdio>
// #include "../data_struct.hpp"

class liquid {
	// setCursor(row, col);
public:
	char visual[2][17];

	int cursor_row;
	int cursor_column;

	// constructor
	// initialize empty matrix
	liquid(){
		cursor_column = 0;
		cursor_row = 0;
		for (int i=0; i<2; i++){
			for (int j=0; j<17; j++){
				visual[i][j] = ' ';
				if (j==16)
					visual[i][j] = 0;
			}
		}
	}

	// empties the matrix
	// (fills it with white spaces)
	void clear(){
		for (int i=0; i<2; i++){
			for (int j=0; j<17; j++){
				visual[i][j] = ' ';
				if (j==16)
					visual[i][j] = 0;
			}
		}
	}

	// moves the cursor to position
	void setCursor (int row, int column){
		cursor_row = row;
		cursor_column = column;
	}

	// insert a string into the matrix at cursor location
	void print(char* s){
		for (int i=0; *s!=0 && cursor_column<16; i++, s++){
			visual[cursor_row][cursor_column] = *s;
			cursor_column++;
		}
	}

	// insert a single character at cursor location
	void print (char c){
		visual[cursor_row][cursor_column] = c;
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

	// update the screen view with latest view
	void update (char* first, char* second){
		setCursor (0, 0);
		print (first);

		setCursor (1, 0);
		print (second);
	}
};

void firstLine (char* first_line, screen* data){

	// insert day
	if (data->time.day < 10){
		first_line[0] = '0';
	} else {
		first_line[0] = ((data->time.day/10)%10) + '0';
	}
	first_line[1] = (data->time.day%10) + '0';

	// insert month
	if (data->time.month < 10){
		first_line[3] = '0';
	} else {
		first_line[3] = '1';
	}
	first_line[4] = (data->time.month%10) + '0';

	// insert year
	// first_line[6] = ((now.anno/10)%10) + '0';
	// first_line[7] = (now.anno%10) + '0';

	// insert hours
	if (data->time.hour < 10) {
		first_line[11] = '0';
	} else {
		first_line[11] = ((data->time.hour/10)%10) + '0';
	}
	first_line[12] = (data->time.hour%10) + '0';

	// insert minutes	
	if (data->time.minute < 10){
		first_line[14] = '0';
	} else {
		first_line[14] = ((data->time.minute/10)%10) + '0';
	}
	first_line[15] = (data->time.minute%10) + '0';

}

void secondLine (char* second_line, screen* data){

	second_line[2] = ((data->temperature/100)%10) + '0';
	second_line[3] = ((data->temperature/10)%10) + '0';

	if (data->out.water){
		second_line[7] = '1';
	} else {
		second_line[7] = '0';
	}

	if (data->out.light){
		second_line[11] = '1';
	} else {
		second_line[11] = '0';
	}

	second_line[15] = data->stag + '0';

}

void showTime (screen* data, liquid* lcd_p){
	char first_line[] = "gg/mm/aa   hh:mm";
	char second_line[] = "T:__ W:_ L:_ S:_";

	firstLine (first_line, data);

	secondLine (second_line, data);

	lcd_p -> update(first_line, second_line);
}

// int main (){

// 	liquid lcd, *pointer;
// 	pointer = &lcd;

// 	screen in = {
// 		{ 3, 2, 11, 23 },	// TIME
// 		{ 1, 0, 0, 0, 0, 0, 0, 0 }, // OUT
// 		3,	// stag
// 		284 // temperature [10^-1 C]
// 	};

// 	showTime (in, pointer);

// 	lcd.show();
// }

/*
##################
#gg/mm/aa   hh:mm#
#T:23 W:1 L:0 S:1#
##################

*/

//data ora
//cosa sta facendo (?)
//se spingo un pulsante cambio l'orario e la data

