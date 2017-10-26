#pragma once
#include<cstdlib>
#include<iostream>
#include"linked_list_of_curves.h"

//#include<string>
using namespace std;
class hash_table {
	friend class linked_list_of_curves;
	private:
		int  Table_size  ;
		Linked_List_C** Hash_table ;
	public :

		hash_table(void);
		hash_table(int );  //Constructor of hash structure
		int hash_function( int ) ;//Hash function-->gives the position on table of an account by its key
/////////////////////////REQUIRED FUNCTIONS//////////////////////////////
	//	void createnodes ( int ) ; //create accounts
	//	void delnodes	(int) ;   //delete account
		void add_curve(string onoma , vector<vector <double> > ,vector<vector <double> >,int ); // add connections
          //      void deltran(int ,int ); // delete connections
          //      void lookup(string , int); //look up an account
		void destroy_hash_table () ;             //destroy all the structures
		void print  () ;          //Print the structure 
		void print_a_bucket(int);
		void Search_vector_in_bucket(vector <vector <double> >,vector<vector <double> >,long int);
		double Search_vector_in_table(vector <vector <double> >);
};
