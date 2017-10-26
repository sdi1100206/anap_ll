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

string ReadLine(){

	string line, a;
	do {
		getline(cin,line);	
    		a += line + '\n';	//apothikeush string apo ton xrhsth se mia metavlhth

  	} while (!line.empty());
		
	//line.clear();
	return 	a;			//epistrofh metavlhths
}

//27
//H sunarthsh ayth gridarei mia kampulh K fores kai epistrefei to athroisma tou grammikou sundiasmou tou concatanated dianismatos kampulhs
struct Concatenated Grid_a_curve_K_times_and_return_riConnation(vector <double> Curve_go_grid,Grid gridaki[],int K){
	vector < vector<double> > conc_of_K;
        
	for(int i = 0 ; i < K ; i ++ ){//Gridare K fores
                vector < vector<double> > g_c;
        
	        //TO gridaki dexete ena mono vector kai epistrefei ena diplo
                g_c =  gridaki[i].grid_a_curve(Curve_go_grid);//Gridare thn kampulh
	
		//kane concatenation tis diaforetikes kampules plegmatos sto conc_of_K
		conc_of_K.insert(conc_of_K.end(), g_c.begin(), g_c.end());

		//kwdhkas gia emfanish ths Kosths kampulhs kampulhs
//		for(int  i =0 ; i < g_c.size(); i++){
  //              	for(int j = 0; j< 2; j++ ){
    //            		cout <<endl<< g_c[i][j] ;
      //          		if(j % 2 == 0 ){cout << ",";}
        //        		if(j % 2 == 1 ){cout << "\n";}
          //      	}
            //    }

	}
//	cout << "Concatanated ddianusma:\n";
//	for(int  i =0 ; i < conc_of_K.size(); i++){
  //                     for(int j = 0; j< 2; j++ ){
    //                            cout <<endl<< conc_of_K[i][j] ;
      //                                 if(j % 2 == 0 ){cout << ",";}
        //                               if(j % 2 == 1 ){cout << "\n";}
          //              }
        //}




        float r[K];
        int dev = 0 ;
        //cout<< "Randomed";
	//genitria tuxaiwn arithmwn se kanonikh katanomh me apoklish ena kai range 0-8 
         random_device rd;
    	 mt19937 gen(rd());
 
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
//    	normal_distribution<> d(60,2);
 
/*
	int random_ints[conc_of_K.size() / 3 +1];
	for (int i = 0 ; i <conc_of_K.size()/3 ; i++  ){
		int number = round(d(gen));
		random_ints[i] = number ;
//		cout << "TYXEIO"<< random_ints[i];
	}
*/
	
	default_random_engine generator; 
        normal_distribution<double> distribution(4.0,1.0);

	
	//parakse K tuxaious aritmous gia na upologistei o grammikos sundiasmos tou concatenated dianismatos
	for(int i = 0 ; i < K ; i++){
                double number = distribution(generator)  ; 
                r[i] = number*0.3 ;
//              cout << r[i]<<endl;
        }

	int plus=1;
	long double  Hadd=0;//athroisma tou grammikou sundiasmou 
       	for(int l = 0 ; l < K ; l++ ){//gia tis K kampules
             	for( int dev = 0   ; dev < conc_of_K.size()/3; dev++){ //gia kathe mia apo afth sto concatanated dianima
        		plus++;
			//cout << R.return_random[dev] << endl;
	        	for(int j = 0; j< 2; j++ ){//gia tis duo siastaseis
	//			cout <<endl<< conc_of_K[l*conc_of_K.size()/3 + dev][j] * r[l] << "ri = "<<r[l] <<" ";
				//Grammikos sundiasmos-polaplasiase ta shmeia twn diaforetika k gridarismenwn kampulwn me ri(random se kanonikh katanomh-diaforetiko gia kathe K )
				Hadd += conc_of_K[l*conc_of_K.size()/3 + dev][j] * r[l] ;
                                //if(j % 2 == 0 ){cout << ",";}
                                //if(j % 2 == 1 ){cout << "\n";}
                         }
                }
	}
	struct Concatenated K_grided ={conc_of_K , Hadd}; 
	return (K_grided);
	//return Hadd;//epestrece to athroisma tou grammikou sundiasmou


}

double discrete_frechet_distance(vector < vector<double> > c1,vector < vector<double> > c2){
	int n =c1.size(); 
        int m =c2.size();
        double L[n][m] ;

	for(int i = 0 ; i <n ; i ++ ){
                for(int j=0; j <m ; j++){
                        if(i == 0 && j == 0 ){
                                double distancex = (c1[0][0] - c2[0][0]) * (c1[0][0] - c2[0][0]);
                                double distancey = (c1[0][1] - c2[0][1]) * (c1[0][1] - c2[0][1]);
                                double distancex_y = sqrt(distancex + distancey);
                                L[0][0] = distancex_y;
//                              cout << L[0][0];
                        }
                        else if(i==0 && j!=0 ){
                                double distancex = (c1[0][0] - c2[j][0]) * (c1[0][0] - c2[j][0]);
                                double distancey = (c1[0][1] - c2[j][1]) * (c1[0][1] - c2[j][1]);
                                double distancex_y = sqrt(distancex + distancey);
                                double L_element = max(distancex_y , L[0][j]);
                                L[i][j] = L_element;
                        }
			else if(j == 0 && i!= 0 ){
                                double distancex = (c1[i][0] - c2[0][0]) * (c1[i][0] - c2[0][0]);
                                double distancey = (c1[i][1] - c2[0][1]) * (c1[i][1] - c2[0][1]);
                                double distancex_y = sqrt(distancex + distancey);
                                double L_element = max(distancex_y , L[0][j]);
                                L[i][j] = L_element;


                        }
                        else{
//L[i, j] := max(d(pi, qj), min(L[i - 1, j], L[i, j - 1], L[i - 1, j - 1]))
                                double distancex = (c1[i][0] - c2[j][0]) * (c1[i][0] - c2[j][0]);
                                double distancey = (c1[i][1] - c2[j][1]) * (c1[i][1] - c2[j][1]);
                                double distancex_y = sqrt(distancex + distancey);
                                double min_in_hood = min(min(L[i-1][j],L[i][j-1]),(L[i-1][j-1]));
                                double L_element = max(distancex_y,min_in_hood);
                                L[i][j] = L_element ; 
			}

                }



        }
        return L[n-1][m-1];

				
}
