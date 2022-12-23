#include<iostream>
#include<stdio.h>
#include<sstream>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include "sleep.h"
using namespace std;

int funtion_help(){
	cout<<"help"<<endl;
	cout<<"./a.out <interfaz> <direccionmac>"<<endl;
	return 0;
}


int main(int argc, char *argv[]){
    char stringer[] = "--help";
    char script[]="--script";
    char helper[]="help";
    if(strcmp(argv[1], stringer)==0){
    	funtion_help();
    }else{
    	if(argv[1] && argv[2]){
    		cout<<"[-] Desactivando interfaz..."<<endl;
    		sleep(3);
    		stringstream var;
    		var<<"ifconfig "<<argv[1]<<" down";
    		system(var.str().c_str());
    		cout<<"[+] Cambiando direccion mac..."<<endl;
    		sleep(3);
    		stringstream mac;
    		mac<<"ifconfig "<<argv[1]<<" hw ether "<<argv[2];
    		system(mac.str().c_str());
    		stringstream up;
    		cout<<"[+] Encendiendo interfaz..."<<endl;
    		sleep(3);
    		up<<"ifconfig "<<argv[1]<<" up";
    		system(up.str().c_str());
    		cout<<"Proceso finalizado..."<<endl;
    	}else{
    		funtion_help();
    	}
    }
	return 0;
}
