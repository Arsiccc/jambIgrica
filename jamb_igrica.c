
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void glavnaIgra (void);
void baciKockicu (int vrednostiKockice[5], int brojPredmeta);
void printKockice (int kockica[5], int velicina, int kategorije[13]);
void baciOpet (int kockica[5], int velicina, int kategorija[12], int igrac, int runda);
void izaberiKategoriju (int kockica[5], int velicina, int kategorija[12], int rezultat[13], int igrac, int runda);

void printRezultat (int rezultat[13], int igrac);
void printKategorije (int kategorije[13]);

int jedinice (int kockica[5], int kategorija[12], int poeni[12]);
int dvojke (int kockica[5], int kategorija[12], int poeni[12]);
int trojke (int kockica[5], int kategorija[12], int poeni[12]);
int cetvorke (int kockica[5], int kategorija[12], int poeni[12]);
int petice (int kockica[5], int kategorija[12], int poeni[12]);
int sestice (int kockica[5], int kategorija[12], int poeni[12]);

int triling (int kockica[5], int kategorija[12], int poeni[12]);
int poker (int kockica[5], int kategorija[12], int poeni[12]);
int full (int kockica[5], int kategorija[12], int poeni[12]);
int kenta(int kockica[5], int kategorija[12], int poeni[12]);
int jamb(int kockica[5], int kategorija[12], int poeni[12]);

void krajIgre (int p1_poeni[12], int p2_poeni[12]);




void glavnaIgra(void) {
    int kockica[5] = {0}, igrac1Rezultat[13] = {0}, igrac1Kombinacije[13] = {0}, igrac2Rezultat[13] = {0}, igrac2Kombinacije[13] = {0}, igrac = 1, krug = 0;

    srand((unsigned int)time(NULL));

    while (1) {
        while (krug < 14) {
            system("cls");
            printf("************************************************** IGRAC %d ********************************************************\n", igrac);
            printf("************************************************** RUNDA %d ********************************************************\n\n", krug);
            baciKockicu(kockica, 5);
            printKockice(kockica, 5, (igrac == 1) ? igrac1Kombinacije : igrac2Kombinacije);
            baciOpet(kockica, 5, (igrac == 1) ? igrac1Kombinacije : igrac2Kombinacije, igrac, krug);
            izaberiKategoriju(kockica, 5, (igrac == 1) ? igrac1Kombinacije : igrac2Kombinacije, (igrac == 1) ? igrac1Rezultat : igrac2Rezultat, igrac, krug);

            system("cls");
            printf("************************************************** IGRAC %d ********************************************************\n", igrac);
            printf("************************************************** RUNDA %d ********************************************************\n\n", krug);
            printRezultat((igrac == 1) ? igrac1Rezultat : igrac2Rezultat, igrac);

            printf("\n\nPritisni bilo koje dugme da promenis na igraca %d.", (igrac == 1) ? 2 : 1);
            system("pause > nul");
            system("cls");

            igrac = (igrac == 1) ? 2 : 1;
            krug++;
        }

        krajIgre(igrac1Rezultat, igrac2Rezultat);
        krug = 0;
        igrac = 1;
    }

    printf("Cao!\n\n");
}


void baciKockicu (int kockica[5], int velicina)
{
	char cont = 0;
	int index = 0;

	printf("Pritisni bilo koje dugme da bacis kockicu.\n\n");
	system("pause > nul");
	

	for (index = 0; index < velicina; ++index)
	{			
		kockica[index] = rand() % 6 + 1;
	}

}


void printKockice(int kockica[], int velicina, int kategorije[13]) {
    for (int index = 0; index < velicina; index++) {
        printf("%d\t", kockica[index]);
    }

    printf("\n\n");
    printKategorije(kategorije);
}


void baciOpet (int kockica[5], int velicina, int kategorija[12], int igrac, int runda)
{
	int broj = 0;
	int index = 0;
	int baciOpet_index = 0;
	int kockica_baciOpet = 0;
	
	
	for (index = 0; index<2; index++)
	{
		do
		{
			printf("Koliko kockica zelis da bacis opet? Ili stisni 0 da koristis ovu ruku. ");
			scanf("%d", &broj);
	
		} while ((broj!=1) && (broj!=2) && (broj!=3) && (broj!=4) && (broj!=5) && (broj!=0));

		

		if (broj != 0)
		{
			for (baciOpet_index = 0; baciOpet_index < broj; baciOpet_index++)
			{
			
					do
					{
						printf("Unesi samo jednu od kockica koju zelis da bacis ponovo: ");
						scanf("%d", &kockica_baciOpet);
						kockica[kockica_baciOpet-1] = rand() % 6 + 1;
					}
					while((kockica_baciOpet != 5) && (kockica_baciOpet != 1) && (kockica_baciOpet != 2) && (kockica_baciOpet != 3) && (kockica_baciOpet != 4));
			
			}
		}
		else
		{break;}
	system("cls");
	printf("************************************************** IGRAC %d ********************************************************\n", igrac);
	printf("************************************************** RUNDA %d ********************************************************\n\n", runda);
		
	printKockice(kockica, 5,kategorija);
	}
}


void izaberiKategoriju (int kockica[5], int velicina, int kategorija[12], int rezultat[13], int igrac, int runda)
{
	int selection = 0, index = 0, is_combo_valid = 0;


	system("cls");
	printf("************************************************** IGRAC %d ********************************************************\n", igrac);
	printf("************************************************** RUNDA %d ********************************************************\n\n", runda);
	printKockice(kockica, 5, kategorija);
	
	
	do
	{
		printf("Unesi u koju kategoriju zelis da upises: ");
		scanf("%d", &selection);

		switch(selection)
		{
		case 1:
			is_combo_valid = jedinice(kockica,kategorija,rezultat);
			break;
		case 2:
			is_combo_valid = dvojke(kockica,kategorija,rezultat);
			break;
		case 3:
			is_combo_valid = trojke(kockica,kategorija,rezultat);
			break;
		case 4:
			is_combo_valid = cetvorke(kockica,kategorija,rezultat);
			break;
		case 5:
			is_combo_valid = petice(kockica,kategorija,rezultat);
			break;
		case 6:
			is_combo_valid = sestice(kockica,kategorija,rezultat);
			break;
		case 7:
			is_combo_valid = triling(kockica,kategorija,rezultat);
			break;
		case 8:
			is_combo_valid = poker(kockica,kategorija, rezultat);
			break;
		case 9:
			is_combo_valid = full(kockica,kategorija, rezultat);
			break;
		case 10:
			is_combo_valid = kenta(kockica, kategorija, rezultat);
			break;
		case 11:
			is_combo_valid = jamb(kockica, kategorija, rezultat);
			break;
		default:
			printf("Unesite validnu kategoriju.\n\n");
			break;
		}

	}
	while(!is_combo_valid);

		

}






void printKategorije (int kategorija[12])
{
	
	if (kategorija[0] == 0)
	{printf ("1. Suma jedinica\n");}
	else {printf ("X. Suma jedinica\n");}

	if (kategorija[1] == 0)
	{printf ("2. Suma dvojki\n");}
	else {printf ("X. Suma dvojki\n");}

	if (kategorija[2] == 0)
	{printf ("3. Suma trojki\n");}
	else {printf ("X. Suma trojki\n");}

	if (kategorija[3] == 0)
	{printf ("4. Suma cetvorki\n");}
	else {printf ("X. Suma cetvorki\n");}

	if (kategorija[4] == 0)
	{printf ("5. Suma petica\n");}
	else {printf ("X. Suma petica\n");}

	if (kategorija[5] == 0)
	{printf ("6. Suma sestica\n");}
	else {printf ("X. Suma sestica\n");}

	if (kategorija[6] == 0)
	{printf ("7. Triling\n");}
	else {printf ("X. Triling\n");}

	if (kategorija[7] == 0)
	{printf ("8. Poker\n");}
	else {printf ("X. Poker\n");}

	if (kategorija[8] == 0)
	{printf ("9. Full House\n");}
	else {printf ("X. Full House\n");}

	if (kategorija[9] == 0)
	{printf ("11. Kenta\n");}
	else {printf ("X. Kenta\n");}

	printf ("12. Jamb\n");

}






void printRezultat (int rezultat[13], int igrac)
{
	int sum = 0, index = 0;
	for (index= 0; index<13; index++)
	{
		sum = rezultat[index] + sum;
	}
	printf("igrac %d's score is now %d.\n", igrac, sum);
}





int jedinice (int kockica[5], int kategorija[12], int poeni[12])
{
	int index = 0, sum = 0, value = 0;

	if (kategorija[0] == 0)
	{
		kategorija[0] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(kockica[index] == 1)
			{sum = sum + 1;}
		}
		poeni[0] = sum;
	}
	return value;
}





int dvojke (int kockica[5], int kategorija[12], int poeni[12])
{
	int index = 0, sum = 0, value = 0;

	if (kategorija[1] == 0)
	{
		kategorija[1] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(kockica[index] == 2)
			{sum = sum + 1;}
		}
		poeni[1] = sum*2;
	}
	return value;
}






int trojke (int kockica[5], int kategorija[12], int poeni[12])
{
	int index = 0, sum = 0, value = 0;

	if (kategorija[2] == 0)
	{
		kategorija[2] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(kockica[index] == 3)
			{sum = sum + 1;}
		}
		poeni[2] = sum*3;
	}
	return value;
}







int cetvorke (int kockica[5], int kategorija[12], int poeni[12])
{
	int index = 0, sum = 0, value = 0;

	if (kategorija[3] == 0)
	{
		kategorija[3] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(kockica[index] == 4)
			{sum = sum + 1;}
		}
		poeni[3] = sum*4;
	}
	return value;
}









int petice (int kockica[5], int kategorija[12], int poeni[12])
{
	int index = 0, sum = 0, value = 0;

	if (kategorija[4] == 0)
	{
		kategorija[4] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(kockica[index] == 5)
			{sum = sum + 1;}
		}
		poeni[4] = sum*5;
	}
	return value;
}








int sestice (int kockica[5], int kategorija[12], int poeni[12])
{
	int index = 0, sum = 0, value = 0;

	if (kategorija[5] == 0)
	{
		kategorija[5] = 1;
		value = 1;
		for (index= 0; index<5; index++)
		{
			if(kockica[index] == 6)
			{sum = sum + 1;}
		}
		poeni[5] = sum*6;
	}
	return value;
}







int triling (int kockica[5], int kategorija[12], int poeni[12])
{
	int broj = 0, rezultat = 0, sum = 0;

	
	if (kategorija[6] == 0)
	{
		rezultat = 1;
		kategorija[6] = 1; 
		for (broj = 1; broj<7; broj++)
		{
			sum = 0;

			if (kockica[0] == broj)
			{sum = sum +1;}
			if (kockica[1] == broj)
			{sum = sum +1;}
			if (kockica[2] == broj)
			{sum = sum +1;}
			if (kockica[3] == broj)
			{sum = sum +1;}
			if (kockica[4] == broj)
			{sum = sum +1;}
			
			if (sum>= 3)
			{
				poeni[6] = kockica [0] + kockica[1] + kockica[2] + kockica[3] + kockica[4];
				break;
			}		
		}
		
	}
	return rezultat;
}








int poker (int kockica[5], int kategorija[12], int poeni[12])
{
	int broj = 0, rezultat = 0, sum = 0;

	
	if (kategorija[7] == 0)
	{
		kategorija[7] = 1; 
		
		for (broj = 1; broj>5; broj++)
		{
			sum = 0;

			if (kockica[0] == broj)
			{sum = sum +1;}
			if (kockica[1] == broj)
			{sum = sum +1;}
			if (kockica[2] == broj)
			{sum = sum +1;}
			if (kockica[3] == broj)
			{sum = sum +1;}
			if (kockica[4] == broj)
			{sum = sum +1;}

			if (sum>= 4)
			{
				poeni[7] = kockica [0] + kockica[1] + kockica[2] + kockica[3] + kockica[4];
				break;
			}
		}
		rezultat = 1;
	}

	return rezultat;
}







int full (int kockica[5], int kategorija[12], int poeni[12])
{
	int broj = 0, rezultat = 0, sum1 = 0, sum2 = 0, tri=0, dva=0, broj2 = 0;

	
	if (kategorija[8] == 0)
	{
		kategorija[8] = 1; 

		
		rezultat = 1;

		
		for (broj = 1; broj<7; broj++)
		{
			sum1 = 0;

			if (kockica[0] == broj)
			{sum1 = sum1 +1;}
			if (kockica[1] == broj)
			{sum1 = sum1 +1;}
			if (kockica[2] == broj)
			{sum1 = sum1 +1;}
			if (kockica[3] == broj)
			{sum1 = sum1 +1;}
			if (kockica[4] == broj)
			{sum1 = sum1 +1;}
			
			if (sum1 == 3)
			{
				break;
			}	
		}

		
		for (broj2 = 1; broj2<7; broj2++)
		{
			sum2 = 0;

			if (kockica[0] == broj2)
			{sum2 = sum2 +1;}
			if (kockica[1] == broj2)
			{sum2 = sum2 +1;}
			if (kockica[2] == broj2)
			{sum2 = sum2 +1;}
			if (kockica[3] == broj2)
			{sum2 = sum2 +1;}
			if (kockica[4] == broj2)
			{sum2 = sum2 +1;}

			
			if (broj2 == broj)
			{sum2 = 0;}
			
			if (sum2== 2)
			{
				if (sum2 + sum1 == 5)
				{poeni[8] = 25;} 
				break;
			}	
		}
	}
	return rezultat;
	
}




int kenta(int kockica[5], int kategorija[12], int poeni [13])
{
	int index = 0, temp = 0, passes = 0, sum=0, rezultat=0;
	
	
	if (kategorija[9] == 0)
	{
		rezultat = 1;
		kategorija[9]=1;
		
		for (passes = 1; passes < 5; passes++)
		{
			for (index = 0; index < 5 - passes; index++)
			{
				if (kockica[index] > kockica[index + 1])
					{
					temp = kockica[index];
					kockica[index] = kockica[index+1];
					kockica[index+1] = temp;
				}
			}
		}
 
	
	for (index = 4; index>0; index--)
		{
			if (kockica[index] == kockica[index -1] + 1)
			{sum++;}

		}

	
	if (sum>=4)
	{poeni[10] = 30;}
	}

	return rezultat;
}








int jamb (int kockica[5], int kategorija[12], int poeni[12])
{
	int broj = 0, rezultat = 0, sum = 0;

	
	if (kategorija[10] == 0)
	{
		kategorija[10] = 1; 
			
		for (broj=0;broj<5;broj++)
		{	
			sum =0;
			
			if (kockica[0] == broj)
			{sum = sum +1;}
			if (kockica[1] == broj)
			{sum = sum +1;}
			if (kockica[2] == broj)
			{sum = sum +1;}
			if (kockica[3] == broj)
			{sum = sum +1;}
			if (kockica[4] == broj)
			{sum = sum +1;}

			if (sum== 5)
			{
				poeni[11] = 50;
			}
		}
		rezultat = 1;
	}

	return rezultat;
}















void krajIgre (int p1_poeni[12], int p2_poeni[12])
{
	int sum1 = 0, sum2 = 0, winner = 0, index=0;

	printf("************************************************ GAME OVER ******************************************************\n");
	
	for (index = 0; index<5; index++)
	{
		sum1 = p1_poeni[index] + sum1;
	}
	for (index = 0; index<5; index++)
	{
		sum2 = p2_poeni[index] + sum2;
	}


	if ((p1_poeni[0]+p1_poeni[1]+p1_poeni[2]+p1_poeni[3]+p1_poeni[4]+p1_poeni[5])>63)
	{sum1 = sum1+35;}
	if ((p2_poeni[0]+p2_poeni[1]+p2_poeni[2]+p2_poeni[3]+p2_poeni[4]+p1_poeni[5])>63)
	{sum2 = sum2+35;}

	if (sum2>sum1)
	{
		winner=2;
	}

	if (sum1>sum2)
	{
		winner =1;
	}
	
	if (sum1 == sum2)
	{
		winner = -1;
	}

	switch (winner)
	{
	case 1:
		printf("\n\nigrac 1 wins with %d poeni!\nigrac 2 has %d poeni.\n\n", sum1, sum2);
		break;
	case 2:
		printf("\n\nigrac 2 wins with %d poeni!\nigrac 1 has %d poeni.\n\n", sum2, sum1);
		break;
	case -1:
		printf("It's a tie! Both igracs have %d poeni.\n\n", sum1);
		break;
	default:
		printf("Error");
	}

	system("pause");
	system("cls");

}

int main (void)
{
	glavnaIgra ();
}