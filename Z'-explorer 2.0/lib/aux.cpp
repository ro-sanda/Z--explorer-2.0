///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "aux.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void read(double *matrix,int number,int rows,int columns,int option){   
  
  
  
  
  int TAM_C=columns;
  int TAM_F=rows;
  
  
  FILE *archive;   // creation of the archive

  char name[22];
  char ext[12]=".dat";
  char path[40];



//The option determines the path inside de directory

  if(option==1){
  strncpy(path, "./cards/sim_card_", 22);
  }
  if(option==2){
  strncpy(path, "./cards/exp_card_", 22);    
  }
  if(option==3){
  strncpy(path, "./cards/rows_card_", 22);    
  }
  if(option==4){
  strncpy(path, "./incard/card_", 22);    
  }
  if(option==5){
  strncpy(path, "./cards/VEC_Zpj_", 22);    
  }
  if(option==6){
  strncpy(path, "./cards/AXIAL_Zpj_", 22);    
  }
  if(option==8){
  strncpy(path, "./cards/DM/AXIAL/DM_", 22);    
  }
  if(option==9){
  strncpy(path, "./cards/DM/AXIAL/bins-ZpAXIAL-",40);    
  }
  if(option==10){
  strncpy(path, "./cards/DM/bckg-",22);    
  }

//Print number inside name
  sprintf(name,"%d",number);



//Concatenate strings  
  strcat(name,ext); //Example: name=1.dat

  strcat(path,name); //Example: path=./cards/sim_card_1.dat

// At this stage we have defined the variable path as required by the the function call
  

  printf("%s\n",path); //It prints the path (optional)
  archive= fopen(path,"r"); // Open the required file in read access mode into the variable archive
  
  int f=0; 
  int c=0;
  int i=0;
  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix 
      i=fscanf(archive,"%lf",&matrix[TAM_C*f + c]); //Save a data from archive in the matrix       
     
    }
  }
  
  
  fclose(archive); //close archive
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void save(double *matrix,int num,int option,int rows,int columns){    


  int TAM_C=columns;
  int TAM_F=rows;
    
  FILE *archive;   // creation of the archive
  char name[12];
  char ext[12]=".dat";
  char path[22];

//The option determines the path inside de directory


  if(option==1){
  strncpy(path, "./output/", 22);
  }
  if(option==2){
  strncpy(path, "./extra/", 22);
  }
  if(option==3){
  strncpy(path, "./", 22);
  }


//Print number inside name  
  sprintf(name,"%d",num);

//Get name length
  int largo = strlen(name) ;


//Concatenate strings  
  strcat(name,ext);
  strcat(path,name);
  //printf("\n  el tam del string es =%i \n",largo);


//Create an empty file and open it for update 
  archive= fopen(path,"w+"); 
  int f=0; 
  int c=0;

  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix
      fprintf(archive,"%.15f	",matrix[TAM_C*f + c]); //Save a data from matrix to archive
    }
      fprintf(archive,"\n"); //space after each row
  }
  
  
  fclose(archive); //close archive
}
// The format to save data is [ row_i -empty space- row_i+1 -empty space- row_i+2 ..... ]   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void savew(double *matrix,char headers[15][22], int num,int option,int rows,int columns){    
     

  int TAM_C=columns;
  int TAM_F=rows;
    
  FILE *archive;   // creation of the archive
  char name[12];
  char ext[12]=".dat";
  char path[22];

//The option determines the path inside de directory


  if(option==1){
  strncpy(path, "./output/", 22);
  }
  if(option==2){
  strncpy(path, "./extra/", 22);
  }
  if(option==3){
  strncpy(path, "./", 22);
  }


//Print number inside name  
  sprintf(name,"%d",num);

//Get name length
  int largo = strlen(name) ;


//Concatenate strings  
  strcat(name,ext);
  strcat(path,name);
  //printf("\n  el tam del string es =%i \n",largo);


//Create an empty file and open it for update 
  archive= fopen(path,"w+"); 
  int f=0; 
  int c=0;


for(c=0 ; c<TAM_C ; c++){ //go through all the columns of headers
      fprintf(archive,"%.20s	",headers[c] ); //Save a data from headers to archive
    }
      fprintf(archive,"\n"); //space after headers



  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix
      fprintf(archive,"%.12f	",matrix[TAM_C*f + c]); //Save a data from matrix to archive
    }
      fprintf(archive,"\n"); //space after each row
  }
  
  
  fclose(archive); //close archive
}
// The format to save data is [ row_i -empty space- row_i+1 -empty space- row_i+2 ..... ]   


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void savebr(double *matrix,char headers[12][22], int num,int option,int rows,int columns){    
     

  int TAM_C=columns;
  int TAM_F=rows;
    
  FILE *archive;   // creation of the archive
  char name[12];
  char ext[12]=".dat";
  char path[22];

//The option determines the path inside de directory


  if(option==1){
  strncpy(path, "./output/", 22);
  }
  if(option==2){
  strncpy(path, "./extra/", 22);
  }
  if(option==3){
  strncpy(path, "./", 22);
  }


//Print number inside name  
  sprintf(name,"%d",num);

//Get name length
  int largo = strlen(name) ;


//Concatenate strings  
  strcat(name,ext);
  strcat(path,name);
  //printf("\n  el tam del string es =%i \n",largo);


//Create an empty file and open it for update 
  archive= fopen(path,"w+"); 
  int f=0; 
  int c=0;


for(c=0 ; c<TAM_C ; c++){ //go through all the columns of headers
      fprintf(archive,"%.20s	",headers[c] ); //Save a data from headers to archive
    }
      fprintf(archive,"\n"); //space after headers



  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix
      fprintf(archive,"%.12f	",matrix[TAM_C*f + c]); //Save a data from matrix to archive
    }
      fprintf(archive,"\n"); //space after each row
  }
  
  
  fclose(archive); //close archive
}
// The format to save data is [ row_i -empty space- row_i+1 -empty space- row_i+2 ..... ]   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void savex(double *matrix,char headers[11][22], int num,int option,int rows,int columns){    
     

  int TAM_C=columns;
  int TAM_F=rows;
    
  FILE *archive;   // creation of the archive
  char name[12];
  char ext[12]=".dat";
  char path[22];

//The option determines the path inside de directory


  if(option==1){
  strncpy(path, "./output/", 22);
  }
  if(option==2){
  strncpy(path, "./extra/", 22);
  }
  if(option==3){
  strncpy(path, "./", 22);
  }


//Print number inside name  
  sprintf(name,"%d",num);

//Get name length
  int largo = strlen(name) ;


//Concatenate strings  
  strcat(name,ext);
  strcat(path,name);
  //printf("\n  el tam del string es =%i \n",largo);


//Create an empty file and open it for update 
  archive= fopen(path,"w+"); 
  int f=0; 
  int c=0;


for(c=0 ; c<TAM_C ; c++){ //go through all the columns of headers
      fprintf(archive,"%.20s	",headers[c] ); //Save a data from headers to archive
    }
      fprintf(archive,"\n"); //space after headers



  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix
      fprintf(archive,"%.12f	",matrix[TAM_C*f + c]); //Save a data from matrix to archive
    }
      fprintf(archive,"\n"); //space after each row
  }
  
  
  fclose(archive); //close archive
}
// The format to save data is [ row_i -empty space- row_i+1 -empty space- row_i+2 ..... ]   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void saveo(double *matrix,char headers[39][22], int num,int option,int rows,int columns){    
     

  int TAM_C=columns;
  int TAM_F=rows;
    
  FILE *archive;   // creation of the archive
  char name[12];
  char ext[12]=".dat";
  char path[22];

//The option determines the path inside de directory


  if(option==1){
  strncpy(path, "./output/", 22);
  }
  if(option==2){
  strncpy(path, "./extra/", 22);
  }
  if(option==3){
  strncpy(path, "./", 22);
  }


//Print number inside name  
  sprintf(name,"%d",num);

//Get name length
  int largo = strlen(name) ;


//Concatenate strings  
  strcat(name,ext);
  strcat(path,name);
  //printf("\n  el tam del string es =%i \n",largo);


//Create an empty file and open it for update 
  archive= fopen(path,"w+"); 
  int f=0; 
  int c=0;


for(c=0 ; c<TAM_C ; c++){ //go through all the columns of headers
      fprintf(archive,"%.20s	",headers[c] ); //Save a data from headers to archive
    }
      fprintf(archive,"\n"); //space after headers



  
  for(f=0 ; f<TAM_F ; f++){ //go through all the rows of matrix
    for(c=0 ; c<TAM_C ; c++){ //go through all the columns of matrix
      fprintf(archive,"%.12f	",matrix[TAM_C*f + c]); //Save a data from matrix to archive
    }
      fprintf(archive,"\n"); //space after each row
  }
  
  
  fclose(archive); //close archive
}
// The format to save data is [ row_i -empty space- row_i+1 -empty space- row_i+2 ..... ]   


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double gamma_jj(double *matrix,int row,int option,int tam_cols){
    
    double m;
    double gr;
    double gl;
    double result=0.0;


//Take mass in matrix    
    m=matrix[tam_cols*row + 0];
 

//Take couplings in matrix    
    if(option==1){
        gl=matrix[tam_cols*row + 1];//guuL
        gr=matrix[tam_cols*row + 2];//guuR
    }
    if(option==2){
        gl=matrix[tam_cols*row + 3];//gddL
        gr=matrix[tam_cols*row + 4];//gddR
    }
    if(option==3){
        gl=matrix[tam_cols*row + 5];//gccL
        gr=matrix[tam_cols*row + 6];//gccR
    }
    if(option==4){
        gl=matrix[tam_cols*row + 7];//gssL
        gr=matrix[tam_cols*row + 8];//gssR
    }
    if(option==5){
        gl=matrix[tam_cols*row + 9];//gbbL
        gr=matrix[tam_cols*row + 10];//gbbR
    }

//Calculate decay width to each channel    
    result= 3*m*2/(48*M_PI)*(gl*gl + gr*gr);
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double gamma_ll(double *matrix,int row,int option,int tam_cols){




    double m;
    double gr;
    double gl;
    double result=0.0;


//Take mass and couplings in matrix     
    m=matrix[tam_cols*row + 0];
    
    if(option==1){
        gl=matrix[tam_cols*row + 13];//geeL
        gr=matrix[tam_cols*row + 14];//geeR
    }
  
   if(option==2){
        gl=matrix[tam_cols*row + 15];//gmumuL
        gr=matrix[tam_cols*row + 16];//gmumuR
    }

   if(option==3){
        gl=matrix[tam_cols*row + 17];//gtautauL
        gr=matrix[tam_cols*row + 18];//gtautauR
    }

//Calculate decay width to dielectron channel    
    result= 1*m*2/(48*M_PI)*(gl*gl + gr*gr);
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double gamma_tt(double *matrix,int row,int tam_cols){
    
    double m;
    double gr;
    double gl;
    double result=0.0;
    double m_t=0.174;

//Take mass and couplings in matrix     
    m=matrix[tam_cols*row + 0];
    gl=matrix[tam_cols*row + 11];//gttL
    gr=matrix[tam_cols*row + 12];//gttR

//Calculate decay width to tt  

  if(m>(2 * 0.174)){
      result= 1*m*3/(48*M_PI)*sqrt(1-4*((m_t/m)*(m_t/m)))*((gr-gl)*(gr-gl)*(1-4*((m_t/m)*(m_t/m)))+ (gr+gl)*(gr+gl)*(1+2*((m_t/m)*(m_t/m))) );
     return result;
      }else{
      result=0;
     return result;
      }

    
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double gamma_DM(double *matrix,int row,int option,int tam_cols){

    double m;
    double mdm;
    double gV;
    double gA;
    double result=0.0;


//Take masses and couplings in matrix and calculate partial width for each case    
    m=matrix[tam_cols*row + 0];
    mdm=matrix[tam_cols*row +22];
    
//Vector mediator case
    if(option==1){
      if(m>(2 * mdm)){
      gV=(matrix[tam_cols*row + 24]+matrix[tam_cols*row + 23])/2;//gchichiV
      result= m*(gV*gV)/(12*M_PI)*(1+(2*(mdm/m)*(mdm/m)))*sqrt(1-4*((mdm/m)*(mdm/m)));
      return result;
      }else{
      result=0;
     return result;
      }
    }

 

//Axial mediator case 

    if(option==2){
      if(m>(2 * mdm)){
      gA=(matrix[tam_cols*row + 24]-matrix[tam_cols*row + 23])/2;//gchichiA
      result= m*(gA*gA)/(12*M_PI)*sqrt(1-4*((mdm/m)*(mdm/m)))*sqrt(1-4*((mdm/m)*(mdm/m)))*sqrt(1-4*((mdm/m)*(mdm/m)));
      return result;
      }else{
      result=0;
     return result;
      }
    }

 


}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_jj(double *matrix,int row,int tam_cols){



    double result=0.0;
    
    result= (matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_bb(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 4])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_tt(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 5])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_ee(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 6])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_mumu(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 7])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double BR_tautau(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 8])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_inv(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 9])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_ww(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 10])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_zh(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 11])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_xx(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 12])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_DMv(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 13])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_DMa(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 14])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double BR_DM(double *matrix,int row,int tam_cols){

    double result=0.0;
    
    result= (matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14])/((matrix[tam_cols*row + 0]+matrix[tam_cols*row + 1]+matrix[tam_cols*row + 2]+matrix[tam_cols*row + 3])+matrix[tam_cols*row + 4]+matrix[tam_cols*row + 5]+matrix[tam_cols*row + 6]+matrix[tam_cols*row + 7]+matrix[tam_cols*row + 8]+matrix[tam_cols*row + 9]+matrix[tam_cols*row + 10]+matrix[tam_cols*row + 11]+matrix[tam_cols*row + 12]+matrix[tam_cols*row + 13]+matrix[tam_cols*row + 14]);
    
    return result;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int indexofSmallestElement(double array[], int size)
{
    int index = 0;

    for(int i = 1; i < size; i++)
    {
        if(array[i] < array[index])
            index = i;              
    }

    return index;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int indexofLargestElement(double array[], int size)
{
    int index = 0;

    for(int i = 1; i < size; i++)
    {
        if(array[i] > array[index])
            index = i;              
    }

    return index;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double sigmatot(double *matrix1,int row1,int tam_cols1,double *matrix2,int row2,int tam_cols2,double *matrix3,int row3,int tam_cols3,double *matrix4,int row4,int tam_cols4,double *matrix5,int row5,int tam_cols5,double *matrix6,int row6,int tam_cols6){

    double result=0.0;

    result= ( matrix1[tam_cols1*row1+1]*matrix1[tam_cols1*row1+1] + matrix1[tam_cols1*row1+2]*matrix1[tam_cols1*row1+2] ) * matrix2[tam_cols2*row2 + 1]
+( matrix1[tam_cols1*row1+3]*matrix1[tam_cols1*row1+3] + matrix1[tam_cols1*row1+4]*matrix1[tam_cols1*row1+4] ) * matrix3[tam_cols3*row3 + 1]
+( matrix1[tam_cols1*row1+5]*matrix1[tam_cols1*row1+5] + matrix1[tam_cols1*row1+6]*matrix1[tam_cols1*row1+6] ) * matrix4[tam_cols4*row4 + 1]
+( matrix1[tam_cols1*row1+7]*matrix1[tam_cols1*row1+7] + matrix1[tam_cols1*row1+8]*matrix1[tam_cols1*row1+8] ) * matrix5[tam_cols5*row5 + 1]
+( matrix1[tam_cols1*row1+9]*matrix1[tam_cols1*row1+9] + matrix1[tam_cols1*row1+10]*matrix1[tam_cols1*row1+10] ) * matrix6[tam_cols6*row6 + 1];
    
    return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double sigmatotZpjV(double *matrix1,int row1,int tam_cols1,double *matrix2,int row2,int tam_cols2,double *matrix3,int row3,int tam_cols3,double *matrix4,int row4,int tam_cols4,double *matrix5,int row5,int tam_cols5){

    double result=0.0;

    result= ( matrix1[tam_cols1*row1+1]*matrix1[tam_cols1*row1+1] + matrix1[tam_cols1*row1+2]*matrix1[tam_cols1*row1+2] + 2 * matrix1[tam_cols1*row1+1] * matrix1[tam_cols1*row1+2]) * 0.25 * matrix2[tam_cols2*row2 + 1]
+( matrix1[tam_cols1*row1+3]*matrix1[tam_cols1*row1+3] + matrix1[tam_cols1*row1+4]*matrix1[tam_cols1*row1+4] + 2 * matrix1[tam_cols1*row1+3] * matrix1[tam_cols1*row1+4]) * 0.25 * matrix3[tam_cols3*row3 + 1]
+( matrix1[tam_cols1*row1+5]*matrix1[tam_cols1*row1+5] + matrix1[tam_cols1*row1+6]*matrix1[tam_cols1*row1+6] + 2 * matrix1[tam_cols1*row1+5] * matrix1[tam_cols1*row1+6]) * 0.25 * matrix4[tam_cols4*row4 + 1]
+( matrix1[tam_cols1*row1+7]*matrix1[tam_cols1*row1+7] + matrix1[tam_cols1*row1+8]*matrix1[tam_cols1*row1+8] + 2 * matrix1[tam_cols1*row1+7] * matrix1[tam_cols1*row1+8]) * 0.25 * matrix5[tam_cols5*row5 + 1];
    
    return result;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double sigmatotZpjA(double *matrix1,int row1,int tam_cols1,double *matrix2,int row2,int tam_cols2,double *matrix3,int row3,int tam_cols3,double *matrix4,int row4,int tam_cols4,double *matrix5,int row5,int tam_cols5){

    double result=0.0;

    result= ( matrix1[tam_cols1*row1+1]*matrix1[tam_cols1*row1+1] + matrix1[tam_cols1*row1+2]*matrix1[tam_cols1*row1+2] - 2 * matrix1[tam_cols1*row1+1] * matrix1[tam_cols1*row1+2]) * 0.25 * matrix2[tam_cols2*row2 + 1]
+( matrix1[tam_cols1*row1+3]*matrix1[tam_cols1*row1+3] + matrix1[tam_cols1*row1+4]*matrix1[tam_cols1*row1+4] - 2 * matrix1[tam_cols1*row1+3] * matrix1[tam_cols1*row1+4]) * 0.25 * matrix3[tam_cols3*row3 + 1]
+( matrix1[tam_cols1*row1+5]*matrix1[tam_cols1*row1+5] + matrix1[tam_cols1*row1+6]*matrix1[tam_cols1*row1+6] - 2 * matrix1[tam_cols1*row1+5] * matrix1[tam_cols1*row1+6]) * 0.25 * matrix4[tam_cols4*row4 + 1]
+( matrix1[tam_cols1*row1+7]*matrix1[tam_cols1*row1+7] + matrix1[tam_cols1*row1+8]*matrix1[tam_cols1*row1+8] - 2 * matrix1[tam_cols1*row1+7] * matrix1[tam_cols1*row1+8]) * 0.25 * matrix5[tam_cols5*row5 + 1];
    
    return result;
}

