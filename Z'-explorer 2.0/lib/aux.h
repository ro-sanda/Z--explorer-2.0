#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "program.h"

void read(double *matriz,int numero,int filas,int columnas,int opcion);

void save(double *matriz,int num,int opcion,int filas,int columnas);
void savew(double *matriz, char headers[15][22], int num,int opcion,int filas,int columnas);
void savebr(double *matriz, char headers[12][22], int num,int opcion,int filas,int columnas);
void savex(double *matriz, char headers[11][22], int num,int opcion,int filas,int columnas);
//HASTA ACÁ CAMBIE
void saveo(double *matriz, char headers[39][22], int num,int opcion,int filas,int columnas);


double gamma_jj(double *matrix,int row,int option,int tam_cols);
double gamma_tt(double *matrix,int row,int tam_cols);
double gamma_ll(double *matrix,int row,int option,int tam_cols);
double gamma_DM(double *matrix,int row,int option,int tam_cols);

double BR_jj(double *matrix,int row,int tam_cols);
double BR_bb(double *matrix,int row,int tam_cols);
double BR_tt(double *matrix,int row,int tam_cols);
double BR_ee(double *matrix,int row,int tam_cols);
double BR_mumu(double *matrix,int row,int tam_cols);
double BR_tautau(double *matrix,int row,int tam_cols);
double BR_inv(double *matrix,int row,int tam_cols);
double BR_ww(double *matrix,int row,int tam_cols);
double BR_zh(double *matrix,int row,int tam_cols);
double BR_xx(double *matrix,int row,int tam_cols);
double BR_DMv(double *matrix,int row,int tam_cols);
double BR_DMa(double *matrix,int row,int tam_cols);
double BR_DM(double *matrix,int row,int tam_cols);

//HASTA ACÁ CAMBIE
int indexofSmallestElement(double array[], int size);
int indexofLargestElement(double array[], int size);



double sigmatot(double *matrix1,int row1,int tam_cols1,double *matrix2,int row2,int tam_cols2,double *matrix3,int row3,int tam_cols3,double *matrix4,int row4,int tam_cols4,double *matrix5,int row5,int tam_cols5,double *matrix6,int row6,int tam_cols6);

double sigmatotZpjV(double *matrix1,int row1,int tam_cols1,double *matrix2,int row2,int tam_cols2,double *matrix3,int row3,int tam_cols3,double *matrix4,int row4,int tam_cols4,double *matrix5,int row5,int tam_cols5);

double sigmatotZpjA(double *matrix1,int row1,int tam_cols1,double *matrix2,int row2,int tam_cols2,double *matrix3,int row3,int tam_cols3,double *matrix4,int row4,int tam_cols4,double *matrix5,int row5,int tam_cols5);

#endif
