#include "stdafx.h"
#include "math.h"
#include "stdio.h"
#include <conio.h>

void aufgabeSchleife() {
	int z = 0;
	for (int i = 1; i < 31; i++) {
		z += i*i;
		printf_s("%i\n", z);
	}
}

void aufgabeWarenbestand() {
	int bestand = 0, artikel = 0, i = 0;
	double preis = 0, summe = 0;

	printf_s("Bitte Anzahl und Preis des Artikels eingeben, 0 0 zum Beenden:\n\n");
	do {
		printf_s("Bitte Artikel %d eingeben:\n", i);
		scanf_s("%d %lf", &bestand, &preis);
		if (bestand != 0 && preis != 0) {
			summe += bestand*preis;
			artikel += bestand;
			i++;
		}
	} while (bestand != 0 && preis != 0);

	printf_s("Sie haben %d Artikel im Gesamtwert von %.1f Euro.", artikel, summe);
	getchar();
}

void aufgabeRechnungen() {
	int i, j;
	i = 275 % 10 + 27 / 10;
	printf_s("Ergebnis 1: %i\n", i);

	i = 12345;
	i = i / 100 * 10;
	printf_s("Ergebnis 2: %i\n", i);

	i = 3;
	i = (int)(1.1);
	printf_s("Ergebnis 3: %i\n", i);


	i = 3, j = 4;
	j = ++i*j;
	printf_s("Ergebnis 4: %i - %i\n", i, j);

	i = 3, j = 4;
	j = i++*j;
	printf_s("Ergebnis 5: %i - %i\n", i, j);

	i = 4, j = 3;
	j *= i + 3;
	printf_s("Ergebnis 6: %i - %i\n", i, j);

	i = 20;
	while (i > 10) {
		i -= 3;
	}
	printf_s("Ergebnis 7: %i\n", i);

	/*
		Ergebnis 1: 7
		Ergebnis 2: 1230
		Ergebnis 3: 1
		Ergebnis 4: 4 - 16
		Ergebnis 5: 4 - 12
		Ergebnis 6: 4 - 21
		Ergebnis 7: 8
	*/
}

void testTastatureingabe() {
	unsigned char c;
	do {
		c = _getch();
		printf("%2.2x %d %c\n", c, c, c);

	} while (c != 'x');
}

int check_J_kleiner_I(int i, int j) {
	i = j < i; // Vergleich auf TRUE/FALSE mit Zuweisung 1 bzw. 0
	printf_s("i:%d - j:%d", i, j);
	return i; //i=1=true wenn j kleiner i, sonst i=0=false
}
//Fibonacci Rekursiv
int fibonacci(int zahl) {
	if (zahl == 0) { // Die Fibonacci-Zahl von null ist null
		return 0;
	}
	if (zahl == 1) { // Die Fibonacci-Zahl von eins ist eins
		return 1;
	}
	// Ansonsten wird die Summe der zwei vorherigen Fibonacci-Zahlen zurückgegeben 
	return fibonacci(zahl - 1) + fibonacci(zahl - 2);
}

int fibonacciIterativ(int zahl) {
	if (zahl == 0) { // Die Fibonacci-Zahl von null ist null
		return 0;
	}
	if (zahl == 1) { // Die Fibonacci-Zahl von eins ist eins
		return 1;
	}
	int ret;
	int h1 = 0;
	int h2 = 1;

	for (int i = 1; i < zahl; ++i) {
		ret = h1 + h2; // Ergebnis ist die Summe der zwei vorhergehenden Fibonacci-Zahlen
		h1 = h2;       // und den beiden Hilfsvariablen die
		h2 = ret;      // neuen vorhergehenden Fibonacci-Zahlen

	}
	return ret;
}

char* kundenBezeichnung(int anzahlKaeufe) {
	char* bez;
	if (anzahlKaeufe < 5) {
		bez = "Neuling";
	}
	else if (anzahlKaeufe < 50) {
		bez = "Kunde";
	}
	else if (anzahlKaeufe < 500) {
		bez = "Stammkunde";
	}
	else {
		bez = "Gold Kunde";
	}
	return bez;
}

void showASCIIzeichen() {
	char z; int i;
	int showUeberschrift1 = 1;
	int showUeberschrift2 = 1;
	int showUeberschrift3 = 1;
	int showUeberschrift4 = 1;

	for (i = 0; i < 80; i++) {
		z = 48 + i;
		if (iswdigit(z) && showUeberschrift1) {
			printf_s("Zahlen in ASCII:\n");
			showUeberschrift1 = 0;
		}if (iswlower(z) && showUeberschrift2) {
			printf_s("\nKleinbuchstaben in ASCII:\n");
			showUeberschrift2 = 0;
		}if (iswupper(z) && showUeberschrift3) {
			printf_s("\nGrossbuchstaben in ASCII:\n");
			showUeberschrift3 = 0;
		}
		if (iswalpha(z) && showUeberschrift4) {
			printf_s("\nSonderzeichen in ASCII:\n");
			showUeberschrift4 = 0;
		}
		if (iswdigit(z))
			printf_s("ASCII-Zeichen %d ist %c\n", i, z);
		if (iswlower(z))
			printf_s("ASCII-Zeichen %d ist %c\n", i, z);
		if (iswupper(z))
			printf_s("ASCII-Zeichen %d ist %c\n", i, z);
		if (iswalpha(z))
			printf_s("ASCII-Zeichen %d ist %c\n", i, z);
	}
}
/*
Berechnet Wurfweite aus Geschwindigkeit (m/s) und Winkel alpha.
*/
double schieferWurf(double v, double alpha) {
	double w;
	w = ((pow(v, 2) * sin(alpha * 2)) / 9.81);

	printf_s("Schiefer Wurf bei einer Geschwindigkeit von %.1f m/s und einem Winkel von %.1f Grad ergibt die Wurfweite von %0.1f Metern.", v, alpha, w);
	return w;
}

int ggt(int a, int b) {
	if (a == b) return(a);
	else {
		if (a > b) return(ggt(a - b, b));
		else return(ggt(b - a, a));
	}
}
int ggtIterativ(int a, int b) {
	while (b > 0) {
		int rest = a % b; // Rest bestimmen
		a = b; // Werte tauschen
		b = rest;
	}
	return a;
}

static long kgv(long a, long b)
{
	return a * (b / ggt(a, b));
}

int quersummeRekursiv(int a) {
	if (a < 10) return a;
	return quersummeRekursiv(a % 10) + quersummeRekursiv(a / 10);
}

int quersummeIterativ(int a) {
	int qs = 0, b = 0;
	if (a < 10) { return a; }
	else {
		while (a >= 1) {
			qs += (a % 10);
			a /= 10;
		}
		return qs;
	}
}



int main()
{
	//aufgabeSchleife();
	aufgabeWarenbestand();
	//aufgabeRechnungen();
	//testTastatureingabe();
	//checkcheck_J_kleiner_I(1,0);
	/*for (int i = 0; i < 30; i++)
		printf_s("Fibonacci-Zahl von %d ist %d\n", i, fibonacciIterativ(i));
		*/

		//printf_s("Sie sind %s", kundenBezeichnung(80));

	//showASCIIzeichen();
	//schieferWurf(80, 35);
	/*printf_s("GGT von %d und %d ist %d.\n", 50, 4, ggt(50, 4));
	printf_s("KGV von %d und %d ist %d.", 10, 4, kgv(10, 4));*/

	//printf_s("Quersumme rekursiv: %d\n", quersummeRekursiv(123));
	//printf_s("Quersumme iterativ: %d\n", quersummeIterativ(123));

	getchar();
	return 0;
}

