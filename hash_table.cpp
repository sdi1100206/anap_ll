#include<cstdlib>
#include<iostream>
#include"hash_table.h"
#include"linked_list_of_curves.h"

using namespace std;



hash_table :: hash_table(void)
        :Table_size(15){//make each shell of the table a graph
                Hash_table = new Linked_List_C*[Table_size];
                for (int i = 0 ; i < Table_size ; i++){
                        Hash_table[i] = new Linked_List_C() ;   
                }
        //Table_size = b_first_n ;
}

///////////////////////////////FUNCTIONS/////////////////////////////////
hash_table :: hash_table(int Table_siz)
	:Table_size(Table_siz){//make each shell of the table a graph
		Hash_table = new Linked_List_C*[Table_size];
		for (int i = 0 ; i < Table_size ; i++){
			Hash_table[i] = new Linked_List_C() ;	
		}
	//Table_size = b_first_n ;
}
////////////////////////////////////////////////////////////////////////

int hash_table :: hash_function(int Hadd){
	int H ;
	H = ((int)Hadd % 7541)%15 ;//count its position on table
	return H ;           //return this position
}

void hash_table :: add_curve(string onoma , vector<vector <double> > New_Curve,vector<vector <double> > New_Curve_in_grid,int keli){
	Hash_table[keli]->Add_curve_on_tail_C(onoma,New_Curve,New_Curve_in_grid);

}



void hash_table :: print( ){
	cout << "HASH TABLE\n";
	for (int i=0 ;  i < Table_size; i++){//Print every list of the table
		cout << "ANOTHER BUCKET:";
		Hash_table[i]->Traverse_and_print_C();
		cout << endl;
	}
}

void hash_table :: destroy_hash_table(){

	cout << "\n\nI  destroyed all Of Your Data\n\n" ;
	for (int i=0 ;  i < Table_size; i++){//i am just deleting all the lists of the Hash table
		Hash_table[i]->Delete_all_the_curves();
	}
	
}

void hash_table :: print_a_bucket(int H){
	this->Hash_table[H]->Traverse_and_print_C();
}

void hash_table :: Search_vector_in_bucket(vector <vector <double> > K_grided_curve,vector <vector <double> > Curve,long int bucket){
	this->Hash_table[bucket]->Is_in_C(K_grided_curve,Curve);	

}

double hash_table :: Search_vector_in_table(vector <vector <double> > curve){
	struct dis_name min_in_hash ;
	min_in_hash.distance = 1000 ;
	min_in_hash.name = "";
	struct dis_name d_n ;
	for(int i = 0 ; i < this->Table_size ; i ++ ){
		d_n =  this->Hash_table[i]->Is_in_full_C(curve);
		if(d_n.distance < min_in_hash.distance){
			min_in_hash.distance = d_n.distance ; 
			min_in_hash.name = d_n.name;
		}
	}
	//cout << "\nQuery:" << curve->
//	return fixed << min_in_hash ; 
	cout << fixed <<"True nearest neigbor : " << min_in_hash.name << "\ndistance True : " << min_in_hash.distance <<endl; 
}
