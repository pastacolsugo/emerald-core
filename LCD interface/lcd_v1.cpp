#include <cstdio>

class liquid {
	// setCursor(row, col);
public:
	char visual[2][17];

	liquid(){
		for (int i=0; i<2; i++){
			for (int j=0; j<17; j++){
				visual[i][j] = ' ';
				if (j==16)
					visual[i][j] = 0;
			}
		}
	}

	int cursor_riga;
	int cursor_colonna;

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

	void print(int x){
		for (int j=0, i=cursor_colonna; voci[x][j] != 0 && i < 16; i++, j++){
			visual[cursor_riga][i] = voci[x][j];
		}
	}

	void print (char c){
		visual[cursor_riga][cursor_colonna] = c;
	}
};

void showTime(){
	
}

int main (){

}




//data ora
//cosa sta facendo (?)
//se spingo un pulsante cambio l'orario e la data

