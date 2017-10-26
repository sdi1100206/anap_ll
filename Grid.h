#pragma once
#include<cstdlib>
#include<iostream>
#include<vector>
//#include"linked_list_of_curves.h"

//#include<string>
using namespace std;
class Grid {
        //friend class linked_list_of_curves;
        private:
                float    delta     ;
		float    t	   ; 
		float    dimensions;//float for the rand function 
		float grid_measurement;
        public :
		Grid();
		Grid(float );  //Constructor of hash structure
                //int hash_function( int ) ;
                ~Grid();
		//void destroy_grid () ;             //destroy all the structures
                void print_grid  () ;          //Print the structure 
		void pick_delta();
		void pick_t(double );
		vector <vector <double> > grid_a_curve(vector <double> );
		
};


