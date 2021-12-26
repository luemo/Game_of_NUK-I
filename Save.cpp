#include <allegro.h>
#include <stdio.h>

void Save(int X, int Y, int last, int OUT, int Map, int College)
{
    FILE *SaveGAME;
	SaveGAME = fopen("Save.txt","w");
	fprintf (SaveGAME,"%d %d %d %d %d %d", X, Y, last, OUT, Map, College);
	fclose (SaveGAME);
}

void Load(int *X, int *Y, int *last, int *OUT, int *Map, int *College)
{
    FILE *LoadGAME;

	LoadGAME = fopen("Save.txt","r");
	fscanf (LoadGAME,"%d %d %d %d %d %d", X, Y, last, OUT, Map, College);
	fclose (LoadGAME);
}