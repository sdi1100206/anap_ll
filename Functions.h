#ifndef Functions_H
#define Functions_H

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include"Grid.h"
#include<random>
#include<iomanip>
#include"Functions.h"
//#include"random_array.h"

using namespace std;

string ReadLine();
struct Concatenated Grid_a_curve_K_times_and_return_riConnation(vector <double>,Grid[],int);
double discrete_frechet_distance(vector < vector<double> > ,vector < vector<double> > );


struct Concatenated{
	vector< vector <double> > K_grided_curve ; 
	long double Hadd ; 
};
struct dis_name{
	double distance ; 
	string name ;
};

#endif
