#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "Functions.h"
#include "linked_list_of_curves.h"
#include "hash_table.h"
#include "read_file.h"
#define D 25
//#include"Grid.h"
#include <random>
#include<iomanip>
//#include"random_array.h"
using namespace std;
int main(int argc, const char *argv[]) {
//	random_array R_for_hash;
//	R_for_hash.print();
	int K = 3, L = 2, index;			   		// arxikopoihsh tou K kai tou L
	string d, q, o;							// strings gia apothikeush paths
	string str ;							// string gia apothikeush twn suntetagmenwn	
  	for (index = 1; index < argc; index++) {              		// tsekarei na dei poia parametro dinei o xrhsths mesw terminal kai thn
                                                              		// apothikeuei sthn katallhlh metavlhth	
		if (strcmp(argv[index], "-d") == 0) {
			d = string(argv[index+1]);
        	}
        	else if (strcmp(argv[index], "-q") == 0) {
            		q = string(argv[index+1]);
        	}
        	else if (strcmp(argv[index], "-k") == 0) {
            		K = atoi(argv[index+1]);
        	}
        	else if (strcmp(argv[index], "-L") == 0) {
            		L = atoi(argv[index+1]);
        	}
        	else if (strcmp(argv[index], "-o") == 0) {
            		o = string(argv[index+1]);
        	}
    	}

	if (d.empty()){							// tsekarei ama o xrhsths exei dwsei to path gia to dataset mesw 										// terminal
		cout << "give the path for your dataset file" << endl;	// an den thn dwsei thn zhtaei apo to xrhsth
		d = ReadLine();
	}

	if (q.empty()){							// tsekarei ama o xrhsths exei dwsei to path gia ta queries mesw 										// terminal
		cout << "give the path for your queries file" << endl;
		q = ReadLine();
	}
	if (o.empty()){							// tsekarei ama o xrhsths exei dwsei to path gia to output mesw
		cout << "give the path for your output 2 file" << endl; //terminal
		o = ReadLine();
	}
//	ifstream set(d.c_str(),ios::in);
	Grid gridaki[K];
	vector < vector<double> > conc_of_K;
	double ts[K];
	default_random_engine generator;
        normal_distribution<double> distribution(4.0,1.0);

	for(int i = 0 ; i < L*K ; i++){
		double number = distribution(generator)  ; 
		ts[i] = number ;
	}
	for(int i = 0 ; i <L*K ; i++){
		cout << ts[i] <<endl;
		gridaki[i].pick_delta() ;
                gridaki[i].pick_t(ts[i]);
       //         gridaki[i].print_grid();
	}

	//vector<hash_table>  hash_tables(L, hash_table(15));
	//for (int l =0 ; l <L ; l++){
	//	load_hash_table_with_curves("",hash_tables[0],gridaki,K);
	//	hash_tables[0].print();
		//load_hash_table_with_curves("",hash_tables[1],gridaki,K);
	//	cout << "\n\n";
          //      hash_tables[1].print();

		//}

 
	ofstream out("output");

	hash_table **hash_tables;
	hash_tables = new hash_table *[L];
	for(int i = 0;i < L;i++){
		for(int i = 0 ; i < K ; i++){
        	        double number = distribution(generator)  ; 
                	ts[i] = number ;
	        }
        	for(int i = 0 ; i <K ; i++){
                	cout << ts[i] <<endl;
                	gridaki[i].pick_delta() ;
                	gridaki[i].pick_t(ts[i]);
                	gridaki[i].print_grid();
        	}
   		hash_tables[i] = new hash_table(15);
		load_hash_table_with_curves("",(hash_tables[i]),gridaki,K);
		if(i==0){open_querry_file_and_find_nearest_n("",hash_tables[0],gridaki,K);}
		open_querry_file("",(hash_tables[i]),gridaki,K);
		hash_tables[i]->print();



	}


//	load_hash_table_with_curves("",(hash_tables[0]),gridaki,K);
//                open_querry_file("",(hash_tables[0]),gridaki,K);
//                hash_tables[0]->print();
	//open_querry_file_and_find_nearest_n("",hash_tables[0],gridaki,K);
	return 0 ;
}



