#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
using namespace std;

void fill_array(int*, int);   // заповнення масиву випадковими числами 0-19
void input_ard(int*, int*, int*, int);  // будування масиву D
void input_ard2(int*, int);  // перенесення мінімального елемента в кінець масиву
void output_array(int*, int);   // заповнення масиву випадковими числами 0-19
//void output_m(int*, int*, int*, int);	// виведення масиву

int main()
{
	const int SIZE = 10;
	int a[SIZE], c[SIZE], d[SIZE];
	srand(time(NULL));
	fill_array(a, SIZE);
	cout << "Array A: ";
	output_array(a, SIZE);
	fill_array(c, SIZE);
	cout << "Array C: ";
	output_array(c, SIZE);
	input_ard(a, c, d, SIZE);
	input_ard2(d, SIZE);
	cout << "Array D: ";
	output_array(d, SIZE);
}

void fill_array(int *m, const int SIZE)
{
		for (int i = 0; i < SIZE; i++)
			m[i] = rand()%20;			
	}

void input_ard(int *m1, int *m2, int *m3, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
		if (m1[i] > m2[i]) 
			m3[i] = m1[i];
		else if (m2[i] > m1[i]) 
			m3[i] = m2[i];
		else m3[i] = 0;
}


void input_ard2(int *m, const int SIZE)
{
	int min = 0, temp = m[0];
	for (int i = 1; i < SIZE; i++)
	{
		if (temp > m[i]) {
			temp = m[i];
			min = i;
					}
	}
	m[min] = m[SIZE-1];
	m[SIZE-1] = temp;	
}
  
void output_array(int *m, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout.width(3); cout << m[i] << "; ";
	}
	
	cout << endl;
} 