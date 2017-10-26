#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Curve {

	friend class Linked_List_C		;//class Linked_List_C has access here
//	friend class hash;
	private:
		Curve* 	        Next_Curve	;//Pointer to the next curve

		vector< vector <double> > coordinates ;
		vector<vector <double> > coordinates_in_grid ; 
		string		onoma_kampulhs	;

	public :
		Curve( string ,vector< vector <double> >,vector<vector <double> > );//constructor with values
		Curve(void)		;	//default constructor
					;
		void Print_Curve()	;	//function to print the curves
	//	int Get_Coordinates()		;//accesor function
};
