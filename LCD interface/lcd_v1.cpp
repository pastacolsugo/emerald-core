
#include <cstdio>

class liquid {
	// setCursor(row, col);
public:
	char visual[2][17];

	int cursor_riga;
	int cursor_colonna;

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

	void clear(){
		for (int i=0; i<2; i++){
			for (int j=0; j<17; j++){
				visual[i][j] = ' ';
				if (j==16)
					visual[i][j] = 0;
			}
		}
	}

	void setCursor (int riga, int colonna){
		cursor_riga = riga;
		cursor_colonna = colonna;
	}

	void print(char* s){
		for (int i=0; *s!=0 && cursor_colonna<16; i++, s++){
			visual[cursor_riga][cursor_colonna] = *s;
			cursor_colonna++;
		}
	}

	void print (char c){
		visual[cursor_riga][cursor_colonna] = c;
	}

	void show (){
		for (int i=0; i<2; i++){
			for (int j=0; j<17; j++){
				printf("%c", visual[i][j]);
			}
			printf("\n");
		}
	}
};

void showTime(){
	
}

int main (){
	liquid one;	
	one.print((char*)"hello");
	one.show();
	return 0;
}




//data ora
//cosa sta facendo (?)
//se spingo un pulsante cambio l'orario e la data

