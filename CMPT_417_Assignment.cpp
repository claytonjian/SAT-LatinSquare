#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]){
	if (argc != 3){
		cout << "Not enough arguments";
	}
	else{
		string line = "";		
	    int rowcount = 0;		
	    int order = 0;
	    int order_digits = 0;
	    long upperbound = 0;
	    long ibound = 0;
	    long jbound = 0;
	    int coded_number = 0;
	    bool error = false;	
	    ifstream read_file(argv[1]);
		ofstream write_file(argv[2]);
	    if (!read_file.is_open()){
	    	cout << "Can't open file";
	    }
	    else{
	    	getline(read_file, line);	
			line = line.substr(6);
			stringstream(line) >> order;
 			string numbers[order][order];
 			int tmp = order;
 			while (tmp) {
        		tmp /= 10;
       			order_digits++;
    		}
			upperbound = pow(10, (order_digits* 3));
			ibound = pow(10, (order_digits*2));
			jbound = pow(10, order_digits);

			if(write_file.is_open()){
				write_file << "p cnf " << (upperbound * 2) << " " << upperbound;
			}
			while(getline(read_file, line)){
				rowcount++;
				stringstream split_line(line);
			    int i = 0;
			    int entry = 0;
			    stringstream ssline(line);
			    while (ssline.good() && i < order){
			        ssline >> numbers[rowcount - 1][i];
			        stringstream(numbers[rowcount - 1][i]) >> entry;
			        if (numbers[rowcount - 1][i] != "."){
			        	coded_number = upperbound + ((rowcount) * ibound) + ((i + 1) * jbound) + entry;
			        	write_file << "\n" << coded_number << " 0";
			        }
			        i++;
			    }
			}
			// property a
			for (int i = 1; i <= order; i++){
				for (int j = 1; j <= order; j++){
					write_file << "\n";
					for (int k = 1; k <= order; k++){
						coded_number = upperbound + (i * ibound) + (j * jbound) + k;
						write_file << coded_number << " ";
					}
					write_file << "0";
				}
			}
			/*
			// property b
			for (int i = 1; i <= order; i++){
				for (int j = 1; j <= order; j++){
					for (int k = 1; k <= order; k++){
						for (int l = 1; l <= order; l++){
							if (k != l){
								write_file << "\n";
								coded_number = upperbound + (i * ibound) + (j * jbound) + k;
								write_file << "-" << coded_number << " ";
								coded_number = upperbound + (i * ibound) + (j * jbound) + l;
								write_file << "-" << coded_number << " ";
								write_file << "0";
							}
						}
					}
				}
			}
			*/
			// property c
			for (int i = 1; i <= order; i++){
				for (int j = 1; j <= order; j++){
					for (int k = 1; k <= order; k++){
						for (int l = 1; l <= order; l++){
							if (k != j){
								write_file << "\n";
								coded_number = upperbound + (i * ibound) + (k * jbound) + l;
								write_file << "-" << coded_number << " ";
								coded_number = upperbound + (i * ibound) + (j * jbound) + l;
								write_file << "-" << coded_number << " ";
								write_file << "0";
							}
						}
					}
				}
			}
			// property d
			for (int i = 1; i <= order; i++){
				for (int j = 1; j <= order; j++){
					for (int k = 1; k <= order; k++){
						for (int l = 1; l <= order; l++){
							if (i != j){
								write_file << "\n";
								coded_number = upperbound + (i * ibound) + (k * jbound) + l;
								write_file << "-" << coded_number << " ";
								coded_number = upperbound + (j * ibound) + (k * jbound) + l;
								write_file << "-" << coded_number << " ";
								write_file << "0";
							}
						}
					}
				}
			}
			/*
			// property e
			for (int i = 1; i <= order; i++){
				for (int k = 1; k <= order; k++){
					write_file << "\n";
					for (int j = 1; j <= order; j++){
						coded_number = upperbound + (i * ibound) + (j * jbound) + k;
						write_file << coded_number << " ";
					}
					write_file << "0";
				}
			}

			// property f
			for (int k = 1; k <= order; k++){
				for (int j = 1; j <= order; j++){
					write_file << "\n";
					for (int i = 1; i <= order; i++){
						coded_number = upperbound + (i * ibound) + (j * jbound) + k;
						write_file << coded_number << " ";
					}
					write_file << "0";
				}
			}
			*/
			
	    }
		
	}
    
    return 0;
}