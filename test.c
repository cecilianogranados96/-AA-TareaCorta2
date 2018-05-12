#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>
#include <string.h>

int col[20];
double promesing_n;
double soluciones;
double backtraking;

int promesing(int i){
    backtraking++;
    int k,segura;
    k = segura = 1;
    while( segura && (k<i) ){
        if(col[i] == col[k] || i-k == abs(col[i] - col[k]) ){
            segura = 0;
        }else{
            k++;
            
        }
    }
    return segura;
}

void queens(int i,int n){
    int j;
    if (promesing(i)){
        promesing_n++;
        if (i == n){
            soluciones++;
        }else{
            for(j=1;j<=n;j++){
                col[i+1] = j;
                queens(i+1,n);
            }
        }    
    }
}

double exaustivo(int n){
    return (pow(n,n+1) - 1) / (n-1);;
}

double factorial(int i){
    double fact = 1;
    for (int b = i; b > 1; b--){
        fact = fact * b;
    }
    return fact;
}

char* format(double a){
    char str[4050];
    if (a < 960000){
        sprintf(str, "%f", a);
    }else{
        sprintf(str, "%e", a);
    }
    return str;
}

double MC_queens(int n) { 
    int i, j; int m; 
    double mprod, numnodes; 
    int valid_child[255]= { 0 }; 
    int v_idx = 0; 
    i = 0; 
    numnodes = 1; 
    m = 1; 
    mprod = 1; 
    while (m != 0 && i != n) { 
        mprod *= m; 
        numnodes += mprod * m; 
        i++; 
        m = 0; 
        for (j = 1; j <= n; ++j) { 
            col[i] = j; 
            if (promesing(i)) { 
                valid_child[m++] = j; 
            } 
        } 
        if (m != 0) { 
            j = valid_child[rand() % m]; 
            col[i] = j; 
        } 
    } 
    return numnodes; 
}


double promedio_mc(int n){
    
    int cantidad_pruebas = 100;
    double avg = 0.0;
    double nodes = 0.0;
    for (int i = 0; i <= cantidad_pruebas; ++i) { 
        nodes += MC_queens(n);
        srand(time(NULL)); 
    } 
    avg = nodes / cantidad_pruebas; 
    return avg;
}

int main()
{ 
    int i = 20;
    int limite = 13;
    
    printf("|       N \t|       Exaustivo\t|        Factorial\t|        Backtraking\t|      Promesing\t|        Soluciones\t|       MC\t\n\n");

    for (int x = 4;x<=i;x++){
        printf("|       %02d\t",       x                                ); //N
        printf("|       %s\t",         format(exaustivo(x))             ); //Exaustivo
        printf("|       %s\t",         format(factorial(x))             ); //Factorial
        
        if (limite > x ){
            queens(0,x);
            printf("|       %s\t",       format(backtraking)              ); //Backtraking
            printf("|       %s\t",       format(promesing_n)              ); //Promesing
            printf("|       %s\t",       format(soluciones)               ); //Soluciones
        }else{
            printf("|       ????????????\t"); //Backtraking
            printf("|       ????????????\t"); //Promesing
            printf("|       ????????????\t"); //Soluciones
        }

        printf("|       %s\t\n",     format(promedio_mc(x))              ); //MC
        promesing_n = 0.0;
        soluciones = 0.0;
        backtraking = 0.0;
    }
}