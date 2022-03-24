/*
Assessment Temporal relationship: In C, without using any third-party library except standard C library,
write a function that can sort the following entries by date and time,
from the oldest to the newest then write a median filter function that calculates foF2 and hmF2.

This requires AU930_ROAM.TXT to be in the source folder
The sorted verion will be created in the source folder called AU930_ROAM2.TXT
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// These are the funtion that reads and writes the file.	
void Readfile(int yyyy[], int MM[], int dd[], int DDD[], int HH[], int mm[], int ss[], int Cscore[], double foF2[], double hmF2[], int* Length, double foF1[], double foE[], double foEs[], double hEs[], double hmF1[], double hmE[], double B0[], double B1[]/*, double D1[]*/);
void Writefile(int yyyy[], int MM[], int dd[], int DDD[], int HH[], int mm[], int ss[], int Cscore[], double foF2[], double hmF2[], int Length, double foF1[], double foE[], double foEs[], double hEs[], double hmF1[], double hmE[], double B0[], double B1[]/*, double D1[]*/);

// These are the funtion that sorts the Values, it uses a merge sort to do so.
void sortVals(int yyyy[], int MM[], int dd[], int DDD[], int HH[], int mm[], int ss[], int Cscore[], double foF2[], double hmF2[], int Length, double foF1[], double foE[], double foEs[], double hEs[], double hmF1[], double hmE[], double B0[], double B1[]);
void Merge(int yyyy[], int MM[], int dd[], int DDD[], int HH[], int mm[], int ss[], int Cscore[], double foF2[], double hmF2[], double foF1[], double foE[], double foEs[], double hEs[], double hmF1[], double hmE[], double B0[], double B1[], int iLeft, int iRight, int iEnd, int Tyyyy[], int TMM[], int Tdd[], int TDDD[], int THH[], int Tmm[], int Tss[], int TCscore[], double TfoF2[], double ThmF2[], double TfoF1[], double TfoE[], double TfoEs[], double ThEs[], double ThmF1[], double ThmE[], double TB0[], double TB1[]);
void ICopyArray(int B[], int A[], int Length);
void DCopyArray(double B[], double A[], int Length);

// These are the funtions that finds the median
double  Medianfinder(double A[], int Length);
void SMerge(double A[], int iLeft, int iRight, int iEnd, double B[]);

int main()
{
	// Variables for the year, month, day, and Dday
	int yyyy[500], MM[500], dd[500], DDD[500];
	// Variables for the Hour, minute, second, and Cscore
	int HH[500], mm[500], ss[500], Cscore[500];
	// Variables for the other doubles in the file
	double foF2[500], hmF2[500], foF1[500], foE[500], foEs[500], hEs[500], hmF1[500], hmE[500], B0[500], B1[500]/*, D1[500]*/;
	// Variable for Length
	int Length = 0;
	//Read the file
	Readfile(yyyy, MM, dd, DDD, HH, mm, ss, Cscore, foF2, hmF2, &Length, foF1, foE, foEs, hEs, hmF1, hmE, B0, B1/*, D1*/);
	//Sort the values from file
	sortVals(yyyy, MM, dd, DDD, HH, mm, ss, Cscore, foF2, hmF2, Length, foF1, foE, foEs, hEs, hmF1, hmE, B0, B1);
	//Write the file
	Writefile(yyyy, MM, dd, DDD, HH, mm, ss, Cscore, foF2, hmF2, Length, foF1, foE, foEs, hEs, hmF1, hmE, B0, B1/*, D1*/);
	// Find and print the median of foF2 and hmF2.
	printf("The Median of foF2 is %.3f\n", Medianfinder(foF2, Length));
	printf("The Median of hmF2 is %.3f\n\n", Medianfinder(hmF2, Length));

}

void Readfile(int yyyy[], int MM[], int dd[], int DDD[], int HH[], int mm[], int ss[], int Cscore[], double foF2[], double hmF2[], int* Length, double foF1[], double foE[], double foEs[], double hEs[], double hmF1[], double hmE[], double B0[], double B1[]/*, double D1[]*/)
{
	// Open the file, set to read
	FILE* froam = fopen("AU930_ROAM.TXT", "r");
	char Fchar = getc(froam);
	// Temporary variables that hold the string form of the double variables
	char c1[10], c2[10], c3[10], c4[10], c5[10], c6[10], c7[10], c8[10], c9[10], c10[10];
	//Ignore the first 2 lines
	while (Fchar != '\n')
	{
		Fchar = getc(froam);
	}
	Fchar = getc(froam);
	//Read the data and assign it to the arrays
	while (1)
	{

		fscanf(froam, "%d.%d.%d (%d) %d:%d:%d %d %s %s %s %s %s %s %s %s %s %s", &yyyy[*Length], &MM[*Length], &dd[*Length], &DDD[*Length], &HH[*Length], &mm[*Length], &ss[*Length], &Cscore[*Length], c1, c2, c3, c4, c5, c6, c7, c8, c9, c10);
		if (feof(froam)) {
			break;
		}
		if (*c1 != '-')
		{
			foF2[*Length] = strtod(c1, NULL);
		}
		else
		{
			foF2[*Length] = 0;
		}
		if (*c2 != '-')
		{
			foF1[*Length] = strtod(c2, NULL);
		}
		else
		{
			foF1[*Length] = 0;
		}
		if (*c3 != '-')
		{
			foE[*Length] = strtod(c3, NULL);
		}
		else
		{
			foE[*Length] = 0;
		}
		if (*c4 != '-')
		{
			foEs[*Length] = strtod(c4, NULL);
		}
		else
		{
			foEs[*Length] = 0;
		}
		if (*c5 != '-')
		{
			hEs[*Length] = strtod(c5, NULL);
		}
		else
		{
			hEs[*Length] = 0;
		}
		if (*c6 != '-')
		{
			hmF2[*Length] = strtod(c6, NULL);
		}
		else
		{
			hmF2[*Length] = 0;
		}
		if (*c7 != '-')
		{
			hmF1[*Length] = strtod(c7, NULL);
		}
		else
		{
			hmF1[*Length] = 0;
		}
		if (*c8 != '-')
		{
			hmE[*Length] = strtod(c8, NULL);
		}
		else
		{
			hmE[*Length] = 0;
		}
		if (*c9 != '-')
		{
			B0[*Length] = strtod(c9, NULL);
		}
		else
		{
			B0[*Length] = 0;
		}
		if (*c10 != '-')
		{
			B1[*Length] = strtod(c10, NULL);
		}
		else
		{
			B1[*Length] = 0;
		}
		Fchar = getc(froam);
		*Length = *Length + 1;
	}
	// Close file
	fclose(froam);
}

void Writefile(int yyyy[], int MM[], int dd[], int DDD[], int HH[], int mm[], int ss[], int Cscore[], double foF2[], double hmF2[], int Length, double foF1[], double foE[], double foEs[], double hEs[], double hmF1[], double hmE[], double B0[], double B1[]/*, double D1[]*/)
{
	// Open the file, set to write
	FILE* froam = fopen("AU930_ROAM2.TXT", "w");
	// Write the two lines of the file at the begining
	fprintf(froam, "yyyy.MM.dd (DDD) HH:mm:ss C-score   foF2  foF1   foE  foEs   h`Es   hmF2   hmF1    hmE    B0   B1   D1\n\n");
	// Write from the variables to the file.
	for (int i = 0; i < Length; i++)
	{
		char c[100];
		sprintf(c, "%d", yyyy[i]);
		if (MM[i] < 10)
			sprintf(c, "%s.0%d", c, MM[i]);
		else
			sprintf(c, "%s.%d", c, MM[i]);
		if (dd[i] < 10)
			sprintf(c, "%s.0%d", c, dd[i]);
		else
			sprintf(c, "%s.%d", c, dd[i]);
		if (DDD[i] < 100)
			sprintf(c, "%s (0%d)", c, DDD[i]);
		else if (DDD[i] < 10)
			sprintf(c, "%s (00%d)", c, DDD[i]);
		else
			sprintf(c, "%s (%d)", c, DDD[i]);
		if (HH[i] < 10)
			sprintf(c, "%s 0%d", c, HH[i]);
		else
			sprintf(c, "%s %d", c, HH[i]);
		if (mm[i] < 10)
			sprintf(c, "%s:0%d", c, mm[i]);
		else
			sprintf(c, "%s:%d", c, mm[i]);
		if (ss[i] < 10)
			sprintf(c, "%s:0%d", c, ss[i]);
		else
			sprintf(c, "%s:%d", c, ss[i]);
		sprintf(c, "%s\t%d", c, Cscore[i]);
		if (foF2[i] != 0)
			sprintf(c, "%s %.3f", c, foF2[i]);
		else
			sprintf(c, "%s    ---", c);
		if (foF1[i] != 0)
			sprintf(c, "%s %.3f", c, foF1[i]);
		else
			sprintf(c, "%s    ---", c);
		if (foE[i] != 0)
			sprintf(c, "%s %.3f", c, foE[i]);
		else
			sprintf(c, "%s    ---", c);
		if (foEs[i] != 0)
			sprintf(c, "%s %.3f", c, foEs[i]);
		else
			sprintf(c, "%s    ---", c);
		if (hEs[i] != 0)
			sprintf(c, "%s %.3f", c, hEs[i]);
		else
			sprintf(c, "%s    ---", c);
		if (hmF2[i] != 0)
			sprintf(c, "%s %.3f", c, hmF2[i]);
		else
			sprintf(c, "%s    ---", c);
		if (hmF1[i] != 0)
			sprintf(c, "%s %.3f", c, hmF1[i]);
		else
			sprintf(c, "%s    ---", c);
		if (hmE[i] != 0)
			sprintf(c, "%s %.3f", c, hmE[i]);
		else
			sprintf(c, "%s    ---", c);
		if (B0[i] != 0)
			sprintf(c, "%s %.3f", c, B0[i]);
		else
			sprintf(c, "%s    ---", c);
		if (B1[i] != 0)
			sprintf(c, "%s %.3f", c, B1[i]);
		else
			sprintf(c, "%s    ---", c);
		fprintf(froam, "%s\n", c);
	}
	// Close file
	fclose(froam);
}

//Merge Sort
void sortVals(int yyyy[], int MM[], int dd[], int DDD[], int HH[], int mm[], int ss[], int Cscore[], double foF2[], double hmF2[], int Length, double foF1[], double foE[], double foEs[], double hEs[], double hmF1[], double hmE[], double B0[], double B1[])
{
	int Tyyyy[500], TMM[500], Tdd[500], TDDD[500];
	int THH[500], Tmm[500], Tss[500], TCscore[500];
	double TfoF2[500], ThmF2[500], TfoF1[500], TfoE[500], TfoEs[500], ThEs[500], ThmF1[500], ThmE[500], TB0[500], TB1[500]/*, D1[500]*/;
	int width;
	// Start Split to avoid recursion
	for (width = 1; width < Length; width = 2 * width)
	{
		// Do the merging of the pairs of split arrays
		int i;
		for (i = 0; i < Length; i = i + 2 * width)
		{
			Merge(yyyy, MM, dd, DDD, HH, mm, ss, Cscore, foF2, hmF2, foF1, foE, foEs, hEs, hmF1, hmE, B0, B1, i, (int)fmin(i + width, Length), (int)fmin(i + 2 * width, Length), Tyyyy, TMM, Tdd, TDDD, THH, Tmm, Tss, TCscore, TfoF2, ThmF2, TfoF1, TfoE, TfoEs, ThEs, ThmF1, ThmE, TB0, TB1);
		}
		ICopyArray(Tyyyy, yyyy, Length);
		ICopyArray(TMM, MM, Length);
		ICopyArray(Tdd, dd, Length);
		ICopyArray(TDDD, DDD, Length);
		ICopyArray(THH, HH, Length);
		ICopyArray(Tmm, mm, Length);
		ICopyArray(Tss, ss, Length);
		ICopyArray(TCscore, Cscore, Length);
		DCopyArray(TfoF2, foF2, Length);
		DCopyArray(ThmF2, hmF2, Length);
		DCopyArray(TfoF1, foF1, Length);
		DCopyArray(TfoE, foE, Length);
		DCopyArray(TfoEs, foEs, Length);
		DCopyArray(ThEs, hEs, Length);
		DCopyArray(ThmF1, hmF1, Length);
		DCopyArray(ThmE, hmE, Length);
		DCopyArray(TB0, B0, Length);
		DCopyArray(TB1, B1, Length);
	}
}

void Merge(int yyyy[], int MM[], int dd[], int DDD[], int HH[], int mm[], int ss[], int Cscore[], double foF2[], double hmF2[], double foF1[], double foE[], double foEs[], double hEs[], double hmF1[], double hmE[], double B0[], double B1[], int iLeft, int iRight, int iEnd, int Tyyyy[], int TMM[], int Tdd[], int TDDD[], int THH[], int Tmm[], int Tss[], int TCscore[], double TfoF2[], double ThmF2[], double TfoF1[], double TfoE[], double TfoEs[], double ThEs[], double ThmF1[], double ThmE[], double TB0[], double TB1[])
{
	int i = iLeft, j = iRight;
	for (int k = iLeft; k < iEnd; k++) {

		if (i < iRight && (j >= iEnd || DDD[i] < DDD[j] || (DDD[i] == DDD[j] && HH[i] < HH[j]) || (DDD[i] == DDD[j] && HH[i] == HH[j] && mm[i] < mm[j]) || (DDD[i] == DDD[j] && HH[i] == HH[j] && mm[i] == mm[j] && ss[i] <= ss[j])))
		{
			Tyyyy[k] = yyyy[i]; TMM[k] = MM[i]; Tdd[k] = dd[i]; TDDD[k] = DDD[i]; THH[k] = HH[i]; Tmm[k] = mm[i]; Tss[k] = ss[i]; TCscore[k] = Cscore[i];
			TfoF2[k] = foF2[i]; ThmF2[k] = hmF2[i]; TfoF1[k] = foF1[i]; TfoE[k] = foE[i]; TfoEs[k] = foEs[i]; ThEs[k] = hEs[i]; ThmF1[k] = hmF1[i]; ThmE[k] = hmE[i]; TB0[k] = B0[i]; TB1[k] = B1[i];
			i = i + 1;

		}
		else {
			Tyyyy[k] = yyyy[j]; TMM[k] = MM[j]; Tdd[k] = dd[j]; TDDD[k] = DDD[j]; THH[k] = HH[j]; Tmm[k] = mm[j]; Tss[k] = ss[j]; TCscore[k] = Cscore[j];
			TfoF2[k] = foF2[j]; ThmF2[k] = hmF2[j]; TfoF1[k] = foF1[j]; TfoE[k] = foE[j]; TfoEs[k] = foEs[j]; ThEs[k] = hEs[j]; ThmF1[k] = hmF1[j]; ThmE[k] = hmE[j]; TB0[k] = B0[j]; TB1[k] = B1[j];
			j = j + 1;
		}
	}
}

// This is integer array Copy
void ICopyArray(int B[], int A[], int Length)
{
	for (int i = 0; i < Length; i++)
		A[i] = B[i];
}

// This is Double array Copy
void DCopyArray(double B[], double A[], int Length)
{
	for (int i = 0; i < Length; i++)
		A[i] = B[i];
}

double  Medianfinder(double A[], int Length)
{
	double B[500];
	double C[500];
	// Copy the array first to not change it.
	DCopyArray(A, C, Length);
	// Do a merge sort of the the Copy

	for (int width = 1; width < Length; width = 2 * width)
	{
		for (int i = 0; i < Length; i = i + 2 * width)
		{
			SMerge(C, i, (int)fmin(i + width, Length), (int)fmin(i + 2 * width, Length), B);
		}
		DCopyArray(B, C, Length);
	}
	//Return the Median
	if (Length % 2 == 1)
	{
		return C[(Length - 1) / 2];
	}
	else
	{
		return (C[(Length / 2) - 1] + C[(Length / 2)]) / 2;
	}
}
// Medianfinders merge sort merger
void SMerge(double A[], int iLeft, int iRight, int iEnd, double B[])
{
	int i = iLeft, j = iRight;
	for (int k = iLeft; k < iEnd; k++) {
		if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
			B[k] = A[i];
			i = i + 1;
		}
		else {
			B[k] = A[j];
			j = j + 1;
		}
	}
}
