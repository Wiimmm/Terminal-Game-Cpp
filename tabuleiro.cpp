#include <iostream>
#include <conio.h>

using namespace std;

char tabuleiro[9][9];
//Marcar spawn do player 1 [7][4] | player 2 [1][4]

char wherewalk;

int posP1x;
int posP1y;

int posP2x;
int posP2y;

void spawnp2(){
	posP2x = 4;
	posP2y = 1;
	
	tabuleiro[1][4] = '2';
	
	return;
}

void spawnp1(){
	posP1x = 4;
	posP1y = 7;
	
	tabuleiro[7][4] = '1';
	
	return;
}

int turno = 1;

char criartabuleiro() {
	for (int l = 0; l < 9; l++) {
		for (int c = 0; c < 9; c++) {
			tabuleiro[l][c] = '*';
		}
	}

	return 0;
}

char setFlagPlayer() {
	tabuleiro[8][4] = 'B';
	tabuleiro[0][4] = 'b';	//Bandeiras

	tabuleiro[7][4] = '1';
	tabuleiro[1][4] = '2';  //Spawn players

	return 0;
}

void checkp1() {
	for (int l = 0; l < 9; l++) {
		for (int c = 0; c < 9; c++) {
			if (tabuleiro[l][c] == '1') {
				posP1y = l;
				posP1x = c;
				return;
			}
		}
	}

	return;
}

void checkp2() {
	for (int l = 0; l < 9; l++) {
		for (int c = 0; c < 9; c++) {
			if (tabuleiro[l][c] == '2') {
				posP2y = l;
				posP2x = c;
				return;
			}
		}
	}

	return;
}

int andar(char x) { //Tenho que fazer uma temp pq isto n ta a funfar, melhor, estar a funfar esta só volta é para o spawn.
	if (turno == 1) {
		switch (x) {
			case 'w':
				if (posP1y > 0) {
					tabuleiro[posP1y][posP1x] = '*';
					posP1y--;
					tabuleiro[posP1y][posP1x] = '1';
					
					if(posP1x == posP2x && posP1y == posP2y){
						spawnp2();
					}
				}
				break;
			case 'a':
				if (posP1x > 0) {
					
					tabuleiro[posP1y][posP1x] = '*';
					posP1x--;
					
					if(posP1y == 8 && posP1x == 4){ //Propria bandeira -- ERRO
						spawnp1();
						return 0;
					}
					
					tabuleiro[posP1y][posP1x] = '1';
					
					if(posP1x == posP2x && posP1y == posP2y){
						spawnp2();
					}
				}
			break;;
			case 's':
				if (posP1y < 8) {
					
					tabuleiro[posP1y][posP1x] = '*';
					posP1y++;
					
					if(posP1y == 8 && posP1x == 4){ //Propria bandeira -- ERRO
						spawnp1();
						return 0;
					}
					
					tabuleiro[posP1y][posP1x] = '1';
					
					if(posP1x == posP2x && posP1y == posP2y){
						spawnp2();
					}
				}
				break;
			case 'd':
				if (posP1x < 8) {
					
					tabuleiro[posP1y][posP1x] = '*';
					posP1x++;
					
					if(posP1y == 8 && posP1x == 4){ //Propria bandeira -- ERRO
						spawnp1();
						return 0;
					}
					
					tabuleiro[posP1y][posP1x] = '1';
					
					if(posP1x == posP2x && posP1y == posP2y){
						spawnp2();
					}
				}
			break;
			default:
				//TODO
				break;
		}
		
		turno = 2;
	}

	else {
		switch (x) {
			case 'w':
				if (posP2y > 0) {
					tabuleiro[posP2y][posP2x] = '*';
					posP2y--;
					tabuleiro[posP2y][posP2x] = '2';
					
					if(posP1x == posP2x && posP1y == posP2y){
						spawnp1();
					}
				}
				break;
			case 'a':
				if (posP2x > 0) {
					tabuleiro[posP2y][posP2x] = '*';
					posP2x--;
					tabuleiro[posP2y][posP2x] = '2';
					
					if(posP1x == posP2x && posP1y == posP2y){
						spawnp1();
					}
				}
				break;
			case 's':
				if (posP2y < 8) {
					tabuleiro[posP2y][posP2x] = '*';
					posP2y++;
					tabuleiro[posP2y][posP2x] = '2';
					
					if(posP1x == posP2x && posP1y == posP2y){
						spawnp1();
					}
				}
				break;
			case 'd':
				if (posP2x < 8) {
					tabuleiro[posP2y][posP2x] = '*';
					posP2x++;
					tabuleiro[posP2y][posP2x] = '2';
					
					if(posP1x == posP2x && posP1y == posP2y){
						spawnp1();
					}
				}
				break;
			default:
				//TODO
				break;
		}
		
		turno = 1;
	}
	return 0;
}

char spawnpoint() {
	return 0;
}

char mostrartabuleiro() {
	for (int l = 0; l < 9; l++) {
		for (int c = 0; c < 9; c++) {
			cout << tabuleiro[l][c] << " ";
		}
		cout << endl;
	}

	return 0;
}

int main() {
	criartabuleiro();
	setFlagPlayer();

	checkp1();
	checkp2();

	while (true) {
		system("cls");
		mostrartabuleiro();

		if (turno == 1) { //Colocar um switch para depois mais opções
			cout << endl
				 << "X1: " << posP1x << endl
				 << "Y1: " << posP1y << endl << endl
					
			     << "Andar frente - W" << endl
			     << "Andar direita - D" << endl
			     << "Andar esquerda - A" << endl
			     << "Andar baixo - S" << endl
			     << endl
			     << "-> ";
			wherewalk = _getch(); // Use _getch() para ler a tecla pressionada -- conio.h

			andar(wherewalk);
		} else {
			cout << endl
				 << "X2: " << posP2x << endl
				 << "Y2: " << posP2y << endl << endl
					
			     << "Andar frente - W" << endl
			     << "Andar direita - D" << endl
			     << "Andar esquerda - A" << endl
			     << "Andar baixo - S" << endl
			     << endl
			     << "-> ";
			wherewalk = _getch(); // Use _getch() para ler a tecla pressionada -- conio.h

			andar(wherewalk);
		}
	}
}

