#include<iostream>
#include<cstdlib>
#include<sstream>

using namespace std;


int sleep(int numero){
	stringstream var;
	string num = to_string(numero);
	var<<"sleep "<<num;
	system(var.str().c_str());
	return 0;
}