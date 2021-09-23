///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

#include "program.h"  //includes libraries
#include "aux.h"      //includes auxiliary functions
#include <string>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  


int main(){
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

//Creation of the "output" and "extra" directories. About their rights: user (file owner) and group have read, write and execute permission, and others have read and execute permission.

  mkdir("./output", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  mkdir("./extra", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  
 



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Create ./cards/rows_card_1.dat file

system("cd cards/ ;bash rows_card_maker.bash; cd ..");

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
  

//Set rows as an array (vector) with the data from ./cards/rows_card_1.dat. (rows_card_1.dat has 14 rows and 2 columns. For first 13 rows -> 1st column: #rows for each simulation card -> 2nd column: #rows for each experimental card; 14th row: -> 1st column: #rows incard-> 2nd column: #columns incard )

printf("\n\nExtracting number of rows in cards...\n");
  double *rows;
  rows=(double *) malloc(sizeof(double)*14*2);
  read(rows,1,14,2,3);



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//All the simulation and experimental cards for visible channels have 2 columns

  int col=2;

//Allocation of memory blocks for all simulation cards according their numbers of rows and columns

//For visible channels: qq->Z'   
  int row_s_1=rows[2*0 + 0];
  double *sim_1;
  sim_1=(double *) malloc(sizeof(double)*row_s_1*col);
  
  int row_s_2=rows[2*1 + 0];
  double *sim_2;
  sim_2=(double *) malloc(sizeof(double)*row_s_2*col);
  
  int row_s_3=rows[2*2 + 0];
  double *sim_3;
  sim_3=(double *) malloc(sizeof(double)*row_s_3*col);
  
  int row_s_4=rows[2*3 + 0];
  double *sim_4;
  sim_4=(double *) malloc(sizeof(double)*row_s_4*col);
  
  int row_s_5=rows[2*4 + 0];
  double *sim_5;
  sim_5=(double *) malloc(sizeof(double)*row_s_5*col);

//For invisible channels: pp->Z'_{V} j
  int row_s_6=rows[2*5 + 0];
  double *sim_6;
  sim_6=(double *) malloc(sizeof(double)*row_s_6*col);

  int row_s_7=rows[2*6 + 0];
  double *sim_7;
  sim_7=(double *) malloc(sizeof(double)*row_s_7*col);

  int row_s_8=rows[2*7 + 0];
  double *sim_8;
  sim_8=(double *) malloc(sizeof(double)*row_s_8*col);

  int row_s_9=rows[2*8 + 0];
  double *sim_9;
  sim_9=(double *) malloc(sizeof(double)*row_s_9*col);

//For invisible channels: pp->Z'_{A} j
  int row_s_10=rows[2*9 + 0];
  double *sim_10;
  sim_10=(double *) malloc(sizeof(double)*row_s_10*col);

  int row_s_11=rows[2*10 + 0];
  double *sim_11;
  sim_11=(double *) malloc(sizeof(double)*row_s_11*col);

  int row_s_12=rows[2*11 + 0];
  double *sim_12;
  sim_12=(double *) malloc(sizeof(double)*row_s_12*col);

  int row_s_13=rows[2*12 + 0];
  double *sim_13;
  sim_13=(double *) malloc(sizeof(double)*row_s_13*col);



//Allocation of memory blocks for experimental cards for visible channels according their numbers of rows and columns
  
  int row_e_1=rows[2*0 + 1];
  double *exp_1;
  exp_1=(double *) malloc(sizeof(double)*row_e_1*col);
  
  int row_e_2=rows[2*1 + 1];
  double *exp_2;
  exp_2=(double *) malloc(sizeof(double)*row_e_2*col);
  
  int row_e_3=rows[2*2 + 1];
  double *exp_3;
  exp_3=(double *) malloc(sizeof(double)*row_e_3*col);
  
  int row_e_4=rows[2*3 + 1];
  double *exp_4;
  exp_4=(double *) malloc(sizeof(double)*row_e_4*col);
  
  int row_e_5=rows[2*4 + 1];
  double *exp_5;
  exp_5=(double *) malloc(sizeof(double)*row_e_5*col);

  int row_e_6=rows[2*5 + 1];
  double *exp_6;
  exp_6=(double *) malloc(sizeof(double)*row_e_6*col);
  
  int row_e_7=rows[2*6 + 1];
  double *exp_7;
  exp_7=(double *) malloc(sizeof(double)*row_e_7*col);

  int row_e_8=rows[2*7 + 1];
  double *exp_8;
  exp_8=(double *) malloc(sizeof(double)*row_e_8*col);

  int row_e_9=rows[2*8 + 1];
  double *exp_9;
  exp_9=(double *) malloc(sizeof(double)*row_e_9*col);

  int row_e_10=rows[2*9 + 1];
  double *exp_10;
  exp_10=(double *) malloc(sizeof(double)*row_e_10*col);

//For invisible channels

  int colDM=3;

  int row_dm_1=rows[2*10 + 1];
  double *dm_1;
  dm_1=(double *) malloc(sizeof(double)*row_dm_1*colDM);

  int row_dm_2=rows[2*11 + 1];
  double *dm_2;
  dm_2=(double *) malloc(sizeof(double)*row_dm_2*colDM);



//Extract number of rows and columns in incard

  int in_row = rows[2*13 + 0];
  int in_col = rows[2*13 + 1];


//The #columns of incard must be 26. 

   if (in_col != 26) {
    printf("\nError: the number of columns of the input card must be 26\n\n");
    return 1;
  }


printf("\nThe incard has %d rows and %d columns\n\n", in_row, in_col);

//Allocation of memory blocks for in_card according their numbers of rows and columns
  
  double *in_card;
  in_card=(double *) malloc(sizeof(double)*in_row*in_col);
  
  double *widths;
  widths=(double *) malloc(sizeof(double)*in_row*15);

  double *totalwidth;
  totalwidth=(double *) malloc(sizeof(double)*in_row*1); 

  double *mass;
  mass=(double *) malloc(sizeof(double)*in_row*1); //There are in_row masses in total

  double *massDM;
  massDM=(double *) malloc(sizeof(double)*in_row*1); //There are in_row DM masses in total

  double *BR;
  BR=(double *) malloc(sizeof(double)*in_row*12);

  double *xsBRsim;
  xsBRsim=(double *) malloc(sizeof(double)*in_row*11);

  double *xsBRexp;
  xsBRexp=(double *) malloc(sizeof(double)*in_row*11);


  double *strength;
  strength=(double *) malloc(sizeof(double)*in_row*39);





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

//SIGO CAMBIANDO ACÁ
 
//Take data from the simulation cards and put it in the corresponding variable

printf("\n\nReading simulation cards...\n");

  read(sim_1,1,row_s_1,2,1);
  read(sim_2,2,row_s_2,2,1);
  read(sim_3,3,row_s_3,2,1);
  read(sim_4,4,row_s_4,2,1);
  read(sim_5,5,row_s_5,2,1);
  read(sim_6,1,row_s_6,2,5);
  read(sim_7,2,row_s_7,2,5);
  read(sim_8,3,row_s_8,2,5);
  read(sim_9,4,row_s_9,2,5);
  read(sim_10,1,row_s_10,2,6);
  read(sim_11,2,row_s_11,2,6);
  read(sim_12,3,row_s_12,2,6);
  read(sim_13,4,row_s_13,2,6);

//printf("\nComplete!\n");

//Take data from the visible experimental cards and put it in the corresponding variable

printf("\n\nReading experimental cards for visible final states...\n");

  read(exp_1,1,row_e_1,2,2);
  read(exp_2,2,row_e_2,2,2);
  read(exp_3,3,row_e_3,2,2);
  read(exp_4,4,row_e_4,2,2);
  read(exp_5,5,row_e_5,2,2);
  read(exp_6,6,row_e_6,2,2);
  read(exp_7,7,row_e_7,2,2);
  read(exp_8,8,row_e_8,2,2);
  read(exp_9,9,row_e_9,2,2);
  read(exp_10,10,row_e_10,2,2);

//printf("\nComplete!\n");

printf("\n\nReading recast of experimental data for DM final state...\n");

  read(dm_1,1,row_dm_1,3,7);
  read(dm_2,2,row_dm_2,3,8);

//printf("\nComplete!\n");



//Take data from incard and put it in the corresponding variable

  printf("\nReading incard...\n");
  read(in_card,1,in_row,in_col,4);



  
  int t=0;
  printf("\n\nCalculating decay widths to fermions and extracting decay widths to bosons...");
  for(t=0 ; t<in_row ; t++){

//Take mass of Z' (1st column of 26) and of χ (23th column of 26) for each row in incard 
      mass[t]=in_card[26*t+0];
      massDM[t]=in_card[26*t+22];



//Calculate widths for each final state


      widths[15*t + 0]=gamma_jj(in_card,t,1,in_col);//uu
      widths[15*t + 1]=gamma_jj(in_card,t,2,in_col);//dd
      widths[15*t + 2]=gamma_jj(in_card,t,3,in_col);//cc
      widths[15*t + 3]=gamma_jj(in_card,t,4,in_col);//ss
      widths[15*t + 4]=gamma_jj(in_card,t,5,in_col);//bb

      widths[15*t + 5]=gamma_tt(in_card,t,in_col);//tt

      widths[15*t + 6]=gamma_ll(in_card,t,1,in_col);//ee
      widths[15*t + 7]=gamma_ll(in_card,t,2,in_col);//μμ
      widths[15*t + 8]=gamma_ll(in_card,t,3,in_col);//ττ


//Take widths from in_card for the case of neutrinos (νν), WW, ZH and XX


      widths[15*t + 9]=in_card[26*t+19];//νν
      widths[15*t + 10]=in_card[26*t+20];//WW
      widths[15*t + 11]=in_card[26*t+21];//ZH
      widths[15*t + 12]=in_card[26*t+25];//XX

//Calculate partial widths to DM with vector/axial mediator

      widths[15*t + 13]=gamma_DM(in_card,t,1,in_col);//χχ-VEC
      widths[15*t + 14]=gamma_DM(in_card,t,2,in_col);//χχ-AXIAL




//Calculate total width


     totalwidth[t]=widths[15*t + 0]+widths[15*t + 1]+widths[15*t + 2]+widths[15*t + 3]+widths[15*t + 4]+widths[15*t + 5]+widths[15*t + 6]+widths[15*t + 7]+widths[15*t + 8]+widths[15*t + 9]+widths[15*t + 10]+widths[15*t + 11]+widths[15*t + 12]+widths[15*t + 13]+widths[15*t + 14];


  }

//Total: 15 decay widths. Save them in ./extra/2.dat


char  headersw[15][22] = { "    Γuu     ", "   Γdd   ", "    Γcc     ", "   Γss   ", "   Γbb   ", "   Γtt   ", "   Γee   ", "   Γμμ   ", "   Γττ   ", "   Γνν   ", "   ΓWW   ", "   ΓZH   ", "   ΓXX   ",  "   ΓχχV   ", "   ΓχχA   "
                    };

  
savew(widths,headersw,2,2,in_row,15);



//Calculation of 12 BR.

int t2=0;
  printf("\nCalculating branching ratios...");
  for(t2=0 ; t2<in_row ; t2++){
      BR[12*t2 + 0]=BR_jj(widths,t2,15);//uu+dd+cc+ss (jj)
      BR[12*t2 + 1]=BR_bb(widths,t2,15);//bb 	
      BR[12*t2 + 2]=BR_tt(widths,t2,15);//tt
      BR[12*t2 + 3]=BR_ee(widths,t2,15);//ee 
      BR[12*t2 + 4]=BR_mumu(widths,t2,15);//μμ
      BR[12*t2 + 5]=BR_tautau(widths,t2,15);//ττ 
      BR[12*t2 + 6]=BR_inv(widths,t2,15);//νν
      BR[12*t2 + 7]=BR_ww(widths,t2,15);//WW
      BR[12*t2 + 8]=BR_zh(widths,t2,15);//ZH
      BR[12*t2 + 9]=BR_xx(widths,t2,15);//XX
      BR[12*t2 + 10]=BR_DMv(widths,t2,15);//χχV
      BR[12*t2 + 11]=BR_DMa(widths,t2,15);//χχA
  }


//Total: 12 branching ratios. Save them in ./extra/3.dat  
  
char  headersbr[12][22] = {  "   BRjj   ", "   BRbb   ", "   BRtt   ", "   BRee   ", "   BRμμ   ", "   BRττ   ", "   BRνν   ", "   BRWW   ", "   BRZH   ", "   BRXX   ", "   BRχχV   ", "   BRχχA   "
                    };



savebr(BR,headersbr,3,2,in_row,12);
  


//For each mass in the in_card (in_row in total), find the index of the closest mass within the simulation cards for visible channels(rows_s_1 in total, that is the number of rows in sim_card_1.dat, but they have all the same number of lines)


double resta[row_s_1], k[in_row];

int q=0;
int p=0;

for(q=0 ; q<in_row ; q++){
  for(p=0 ; p<row_s_1 ; p++){
	resta[p]= fabs( mass[q] - sim_1[2*p] );
	}
	k[q]=indexofSmallestElement(resta,row_s_1);
}




//Save the index for each más in ./extra/6.dat
//save(k,6,2,in_row,1);




//save(resta,7,2,row_s_1,1); // Save in ./extra/7.dat


//Calculation of the total cross section at fixed mass as sum of all simulated cross sections (at closest mass) for each parton in the proton that couples to Z' (u, d, c, s, b) adjusted by the sum of the squared couplings in the incard



double sigmasim[in_row];

int t3=0;
  for(t3=0 ; t3<in_row ; t3++){
      sigmasim[t3]=sigmatot(in_card,t3,in_col,sim_1,k[t3],2,sim_2,k[t3],2,sim_3,k[t3],2,sim_4,k[t3],2,sim_5,k[t3],2);
     
 
  }

//save(sigmasim,8,2,in_row,1); //Save in ./extra/8.dat


//Product between total simulated cross-section and branching ratios for visible channels

int r=0;
  printf("\nCalculating cross-section to SM final states...");
  for(r=0 ; r<in_row ; r++){
      xsBRsim[11*r + 0]=mass[r];
      xsBRsim[11*r + 1]=sigmasim[r]*BR[12*r+0];//uu+dd+cc+ss (jj)
      xsBRsim[11*r + 2]=sigmasim[r]*BR[12*r+1];//bb
      xsBRsim[11*r + 3]=sigmasim[r]*BR[12*r+2];//tt
      xsBRsim[11*r + 4]=sigmasim[r]*BR[12*r+3];//ee
      xsBRsim[11*r + 5]=sigmasim[r]*BR[12*r+4];//μμ
      xsBRsim[11*r + 6]=sigmasim[r]*BR[12*r+5];//ττ
      xsBRsim[11*r + 7]=sigmasim[r]*BR[12*r+6];//νν
      xsBRsim[11*r + 8]=sigmasim[r]*BR[12*r+7];//WW
      xsBRsim[11*r + 9]=sigmasim[r]*BR[12*r+8];//ZH
      xsBRsim[11*r + 10]=sigmasim[r]*BR[12*r+9];//XX
    
 
  }
  

char  headerssigpred[11][22] = { "     M     ", "   σpred_jj   ", "   σpred_bb   ", "   σpred_tt   ", "   σpred_ee   ", "   σpred_μμ   ", "   σpred_ττ   ", "   σpred_νν  ", "   σpred_WW   ", "   σpred_ZH   ", "   σpred_XX   "
                    };


savex(xsBRsim,headerssigpred,4,2,in_row,11); // Save in ./extra/4.dat


double restae1[row_e_1], ke1[in_row], restae2[row_e_2], ke2[in_row], restae3[row_e_3], ke3[in_row], restae4[row_e_4], ke4[in_row], restae5[row_e_5], ke5[in_row], restae6[row_e_6], ke6[in_row], restae7[row_e_7], ke7[in_row], restae8[row_e_8], ke8[in_row], restae9[row_e_9], ke9[in_row], restae10[row_e_10], ke10[in_row];
int q1=0;
int p1=0;
int p2=0;
int p3=0;
int p4=0;
int p5=0;
int p6=0;
int p7=0;
int p8=0;
int p9=0;
int p10=0;

//For each mass in the in_card (in_row in total), find the index of the closest mass within each on of the experimental cards. 


for(q1=0 ; q1<in_row ; q1++){

  for(p1=0 ; p1<row_e_1 ; p1++){
	restae1[p1]= fabs( mass[q1] - exp_1[2*p1+0]); //uu+dd+cc+ss (jj)
	}
	ke1[q1]=indexofSmallestElement(restae1,row_e_1);

  for(p2=0 ; p2<row_e_2 ; p2++){
	restae2[p2]= fabs( mass[q1] - exp_2[2*p2+0] ); //bb
	}
	ke2[q1]=indexofSmallestElement(restae2,row_e_2);

  for(p3=0 ; p3<row_e_3 ; p3++){
	restae3[p3]= fabs( mass[q1] - exp_3[2*p3+0] ); //tt
	}
	ke3[q1]=indexofSmallestElement(restae3,row_e_3);

  for(p4=0 ; p4<row_e_4 ; p4++){
	restae4[p4]= fabs( mass[q1] - exp_4[2*p4+0] ); //ee
	}
	ke4[q1]=indexofSmallestElement(restae4,row_e_4);


  for(p5=0 ; p5<row_e_5 ; p5++){
	restae5[p5]= fabs( mass[q1] - exp_5[2*p5+0] ); //μμ
	}
	ke5[q1]=indexofSmallestElement(restae5,row_e_5);

  for(p6=0 ; p6<row_e_6 ; p6++){
	restae6[p6]= fabs( mass[q1] - exp_6[2*p6+0] ); //ττ
	}
	ke6[q1]=indexofSmallestElement(restae6,row_e_6);

  for(p7=0 ; p7<row_e_7 ; p7++){
	restae7[p7]= fabs( mass[q1] - exp_7[2*p7+0] ); //νν
	}
	ke7[q1]=indexofSmallestElement(restae7,row_e_7);

  for(p8=0 ; p8<row_e_8 ; p8++){
	restae8[p8]= fabs( mass[q1] - exp_8[2*p8+0] ); //WW
	}
	ke8[q1]=indexofSmallestElement(restae8,row_e_8);

  for(p9=0 ; p9<row_e_9 ; p9++){
	restae9[p9]= fabs( mass[q1] - exp_9[2*p9+0] ); //ZH
	}
	ke9[q1]=indexofSmallestElement(restae9,row_e_9);

  for(p10=0 ; p10<row_e_10 ; p10++){
	restae10[p10]= fabs( mass[q1] - exp_10[2*p10+0] ); //XX
	}
	ke10[q1]=indexofSmallestElement(restae10,row_e_10);



}


//save(ke1,6,2,in_row,1);




//Take for each mass in the incard the experimental limits in the cross-section for visible each channel (at closest mass).

double outlier=1e9;

int s=0;
  printf("\nExtracting cross-section limits from experimental cards for visible channels...");
  for(s=0 ; s<in_row ; s++){
      xsBRexp[11*s + 0]=mass[s];

      if(int(ke1[s])==(row_e_1-1) || int(ke1[s])==0){
      xsBRexp[11*s + 1]=outlier;//uu+dd+cc+ss (jj)
      }else{
      xsBRexp[11*s + 1]=exp_1[2*(int) ke1[s]+1];//uu+dd+cc+ss (jj)
      }

      if(int(ke2[s])==(row_e_2-1) || int(ke2[s])==0){
      xsBRexp[11*s + 2]=outlier;//bb
      }else{
      xsBRexp[11*s + 2]=exp_2[2*(int) ke2[s]+1];//bb
      }

      if(int(ke3[s])==(row_e_3-1) || int(ke3[s])==0){
      xsBRexp[11*s + 3]=outlier;//tt
      }else{
      xsBRexp[11*s + 3]=exp_3[2*(int) ke3[s]+1];//tt
      }   

      if(int(ke4[s])==(row_e_4-1) || int(ke4[s])==0){
      xsBRexp[11*s + 4]=outlier;//ee
      }else{
      xsBRexp[11*s + 4]=exp_4[2*(int) ke4[s]+1];//ee
      }   


      if(int(ke5[s])==(row_e_5-1) || int(ke5[s])==0){
      xsBRexp[11*s + 5]=outlier;//μμ
      }else{
      xsBRexp[11*s + 5]=exp_5[2*(int) ke5[s]+1];//μμ
      }
      
      if(int(ke6[s])==(row_e_6-1) || int(ke6[s])==0){
      xsBRexp[11*s + 6]=outlier;//ττ 
      }else{
      xsBRexp[11*s + 6]=exp_6[2*(int) ke6[s]+1];//ττ 
      }

      if(int(ke7[s])==(row_e_7-1) || int(ke7[s])==0){
      xsBRexp[11*s + 7]=outlier;//νν
      }else{
      xsBRexp[11*s + 7]=exp_7[2*(int) ke7[s]+1];//νν
      }

      if(int(ke8[s])==(row_e_8-1) || int(ke8[s])==0){
      xsBRexp[11*s + 8]=outlier;//WW
      }else{
      xsBRexp[11*s + 8]=exp_8[2*(int) ke8[s]+1];//WW
      }

      if(int(ke9[s])==(row_e_9-1) || int(ke9[s])==0){
      xsBRexp[11*s + 9]=outlier;//ZH
      }else{
      xsBRexp[11*s + 9]=exp_9[2*(int) ke9[s]+1];//ZH
      }

      if(int(ke10[s])==(row_e_10-1) || int(ke10[s])==0){
      xsBRexp[11*s + 10]=outlier;//XX
      }else{
      xsBRexp[11*s + 10]=exp_10[2*(int) ke10[s]+1];//XX
      }      
     
  }




char  headerssiglim[11][22] = { "     M     ", "   σlim_jj   ", "   σlim_bb   ", "   σlim_tt   ", "   σlim_ee   ", "   σlim_μμ   ", "   σlim_ττ   ", "   σlim_νν   ", "   σlim_WW   ", "   σlim_ZH   ", "   σlim_XX   "
                    };

  
savex(xsBRexp,headerssiglim,5,2,in_row,11); //Save in ./extra/5.dat



//Limits for the DM channel
printf("\nExtracting bounds from monojet recast DM final state...\n");

//For each pair of Z' and χ masses in the in_card (in_row in total), find the index of the closest pair of masses within the recast cards for DM channel(rows_dm_2 in total, that is the number of rows in incard_VEC_DM_1.dat/incard_AXIAL_DM_2.dat -the number of rows is the same in both cards)


double norma2D[row_dm_2], k2D[in_row];

int q2D=0;
int p2D=0;

for(q2D=0 ; q2D<in_row ; q2D++){
  for(p2D=0 ; p2D<row_dm_2 ; p2D++){
	norma2D[p2D]= fabs(sqrt((mass[q2D] - dm_2[3*p2D])*(mass[q2D] - dm_2[3*p2D])+(massDM[q2D]-dm_2[3*p2D+1])*(massDM[q2D]-dm_2[3*p2D+1])));
	}
	k2D[q2D]=indexofSmallestElement(norma2D,row_dm_2);
}


//save(k2D,69,2,in_row,1);

//For each mass in the in_card (in_row in total), find the index of the closest mass within the simulation cards for invisible channels(rows_s_6 in total, that is the number of rows in sim_card_6.dat, but they have all the same number of lines)

double resta1D[row_s_6], k1D[in_row];

int q1D=0;
int p1D=0;

for(q1D=0 ; q1D<in_row ; q1D++){
  for(p1D=0 ; p1D<row_s_6 ; p1D++){
	resta1D[p1D]= fabs( mass[q1D] - sim_6[2*p1D] );
	}
	k1D[q1D]=indexofSmallestElement(resta1D,row_s_6);
}


//save(k1D,69,2,in_row,1);




//Define constants for the significance in Z'->χχ channel
int t4;
double lumi=139;
double kfac=0.82;
double tot=1000000;
double xsecpbtofb=1000;


//Import background for exclusive regions in Z'->χχ channel
double *bckg;
bckg = (double *) malloc(sizeof(double)*13*1);
read(bckg, 1, 13, 1, 10);


//Allocation of memory block for significance in Z'->χχ channel

double *significance;
significance=(double *) malloc(sizeof(double)*in_row*1);



//Define ATLAS incard in Z'_{A} monojet results for the corresponding Z' and χ masses

double *in_cardATLAS2D;
  in_cardATLAS2D=(double *) malloc(sizeof(double)*in_row*in_col);
  
  int t7;
  for(t7=0 ; t7<in_row ; t7++){
  in_cardATLAS2D[26*t7+0]=in_card[26*t7+0];//MZ'
  //Couplings to all SM quarks
  in_cardATLAS2D[26*t7+1]=-0.25; 
  in_cardATLAS2D[26*t7+2]=0.25; 
  in_cardATLAS2D[26*t7+3]=-0.25; 
  in_cardATLAS2D[26*t7+4]=0.25; 
  in_cardATLAS2D[26*t7+5]=-0.25; 
  in_cardATLAS2D[26*t7+6]=0.25; 
  in_cardATLAS2D[26*t7+7]=-0.25; 
  in_cardATLAS2D[26*t7+8]=0.25; 
  in_cardATLAS2D[26*t7+9]=-0.25; 
  in_cardATLAS2D[26*t7+10]=0.25; 
  in_cardATLAS2D[26*t7+11]=-0.25; 
  in_cardATLAS2D[26*t7+12]=0.25; 
  int t8;
  for(t8=13 ; t8<22; t8++){//Coupling to all leptons and partial widths to νν, WW and ZH
  	in_cardATLAS2D[26*t7+t8]=0;
}
  in_cardATLAS2D[26*t7+22]=in_card[26*t7+22]; //mχ 
  in_cardATLAS2D[26*t7+23]=-1;//gχL
  in_cardATLAS2D[26*t7+24]=1;//gχR
  in_cardATLAS2D[26*t7+25]=0;//partial width to XX      
}


//Allocation of memory block for widths in Z'_{A} monojet ATLAS results
double *widthsATLAS;
widthsATLAS=(double *) malloc(sizeof(double)*in_row*15);

double scaleBR[in_row];
double scaleBRATLAS[in_row];

double scalePROD[in_row];
double sigmasimZpj[in_row];
double sigmasimZpjATLAS[in_row];

//Estimation of the stregth in the Z'->χχ channel
double *events;

double *significance_aux;

for (t4=0; t4<in_row; t4++){

  //Import events for monojet

  events = (double *) malloc(sizeof(double)*13*1);
  read(events, k2D[t4]+1, 13, 1 ,9);
  

  significance_aux = (double *) malloc(sizeof(double)*13*1);

  //Estimate widths in monojet ATLAS results
  widthsATLAS[15*t4 + 0]=gamma_jj(in_cardATLAS2D,t4,1,in_col);//uu
  widthsATLAS[15*t4 + 1]=gamma_jj(in_cardATLAS2D,t4,2,in_col);//dd
  widthsATLAS[15*t4 + 2]=gamma_jj(in_cardATLAS2D,t4,3,in_col);//cc
  widthsATLAS[15*t4 + 3]=gamma_jj(in_cardATLAS2D,t4,4,in_col);//ss
  widthsATLAS[15*t4 + 4]=gamma_jj(in_cardATLAS2D,t4,5,in_col);//bb
  widthsATLAS[15*t4 + 5]=gamma_tt(in_cardATLAS2D,t4,in_col);//tt
  widthsATLAS[15*t4 + 6]=gamma_ll(in_cardATLAS2D,t4,1,in_col);//ee
  widthsATLAS[15*t4 + 7]=gamma_ll(in_cardATLAS2D,t4,2,in_col);//μμ
  widthsATLAS[15*t4 + 8]=gamma_ll(in_cardATLAS2D,t4,3,in_col);//ττ
  widthsATLAS[15*t4 + 9]=in_cardATLAS2D[26*t4+19];//νν
  widthsATLAS[15*t4 + 10]=in_cardATLAS2D[26*t4+20];//WW
  widthsATLAS[15*t4 + 11]=in_cardATLAS2D[26*t4+21];//ZH
  widthsATLAS[15*t4 + 12]=in_cardATLAS2D[26*t4+25];//XX
  widthsATLAS[15*t4 + 13]=gamma_DM(in_cardATLAS2D,t4,1,in_col);//χχ-VEC
  widthsATLAS[15*t4 + 14]=gamma_DM(in_cardATLAS2D,t4,2,in_col);//χχ-AXIAL




  //Calculation of the total cross section of pp->Z' j at fixed mass as sum of all simulated cross sections (at closest mass) for each parton in the proton that couples to Z' with non-negligible contribution (u, d, c, s) adjusted by the sum of the squared couplings in the incard (for BP and for ATLAS)

  sigmasimZpj[t4]=sigmatotZpjV(in_card,t4,in_col,sim_6,k1D[t4],2,sim_7,k1D[t4],2,sim_8,k1D[t4],2,sim_9,k1D[t4],2)+sigmatotZpjA(in_card,t4,in_col,sim_10,k1D[t4],2,sim_11,k1D[t4],2,sim_12,k1D[t4],2,sim_13,k1D[t4],2);

  sigmasimZpjATLAS[t4]=sigmatotZpjV(in_cardATLAS2D,t4,in_col,sim_6,k1D[t4],2,sim_7,k1D[t4],2,sim_8,k1D[t4],2,sim_9,k1D[t4],2)+sigmatotZpjA(in_cardATLAS2D,t4,in_col,sim_10,k1D[t4],2,sim_11,k1D[t4],2,sim_12,k1D[t4],2,sim_13,k1D[t4],2);  


  //Rescaling data from ATLAS


  scaleBR[t4]=BR_DM(widths,t4,15);
  scaleBRATLAS[t4]=BR_DM(widthsATLAS,t4,15);
 
   
  scalePROD[t4]=sigmasimZpj[t4] /sigmasimZpjATLAS[t4];

  //Estimation of the significance  

  //Set significance to 0 when masses are out of range and out of on-shell regime
  if(massDM[t4]<0.001 || massDM[t4]>1 || mass[t4]<0.001 || mass[t4]>2.5 || mass[t4]<=(2.0 * massDM[t4])){
      significance[t4]=0;
      }else{
	int t5;
	int t6;
	for (t5=0; t5<13; t5++){
        int index = k2D[t4];
        significance_aux[t5] = 0.51* events[t5] * lumi * kfac * dm_2[3*index+2] * xsecpbtofb * scaleBR[t4] * scalePROD[t4] / (scaleBRATLAS[t4] * tot * sqrt(bckg[t5]));
  }
  	t6=indexofLargestElement(significance_aux,13);
      	significance[t4]=significance_aux[t6];
      }
}







//Calculation of the strength of each channel and mass.




char  headers[39][22] = {"    M     ", "   guuL   ", "   guuR   ", "   gddL   ", "   gddR   ", "   gccL   ", "   gccR   ", "   gssL   ", "   gssR   ", "   gbbL   ", "   gbbR   ", "   gttL   ", "   gttR   ", "   geeL   ", "   geeR   ", "   gμμL   ", "   gμμR   ", "   gττL   ", "   gττR   ",  "    Γνν     ",  "    ΓWW     ", "    ΓZH     ","    mχ     ","    gχχL     ","    gχχR     ",  "    ΓXX     ", "   Sjj   ", "   Sbb   ", "   Stt   ", "   See   ", "   Sμμ   ", "   Sττ   ", "   Sνν   ", "   SWW   ", "   SZH   ", "   Sχχ   ", "   SXX   ", "   ΓZ'   ", "WARNING:ΓZ'>5%"
                    };



int u=0;
  printf("\nCalculating strength of each channel...\n\n");
  for(u=0 ; u<in_row ; u++){

      strength[39*u + 0]=mass[u];
      strength[39*u + 1]=in_card[26*u+1];
      strength[39*u + 2]=in_card[26*u+2];
      strength[39*u + 3]=in_card[26*u+3];
      strength[39*u + 4]=in_card[26*u+4];
      strength[39*u + 5]=in_card[26*u+5];
      strength[39*u + 6]=in_card[26*u+6];
      strength[39*u + 7]=in_card[26*u+7];
      strength[39*u + 8]=in_card[26*u+8];
      strength[39*u + 9]=in_card[26*u+9];
      strength[39*u + 10]=in_card[26*u+10];
      strength[39*u + 11]=in_card[26*u+11];
      strength[39*u + 12]=in_card[26*u+12];
      strength[39*u + 13]=in_card[26*u+13];
      strength[39*u + 14]=in_card[26*u+14];
      strength[39*u + 15]=in_card[26*u+15];
      strength[39*u + 16]=in_card[26*u+16];
      strength[39*u + 17]=in_card[26*u+17];
      strength[39*u + 18]=in_card[26*u+18];
      strength[39*u + 19]=in_card[26*u+19];
      strength[39*u + 20]=in_card[26*u+20];
      strength[39*u + 21]=in_card[26*u+21];
      strength[39*u + 22]=in_card[26*u+22];
      strength[39*u + 23]=in_card[26*u+23];
      strength[39*u + 24]=in_card[26*u+24];
      strength[39*u + 25]=in_card[26*u+25];

      strength[39*u + 26]=xsBRsim[11*u+1]/xsBRexp[11*u+1];//uu+dd+cc+ss (jj)
      strength[39*u + 27]=xsBRsim[11*u+2]/xsBRexp[11*u+2];//bb
      strength[39*u + 28]=xsBRsim[11*u+3]/xsBRexp[11*u+3];//tt
      strength[39*u + 29]=xsBRsim[11*u+4]/xsBRexp[11*u+4];//ee
      strength[39*u + 30]=xsBRsim[11*u+5]/xsBRexp[11*u+5];//μμ
      strength[39*u + 31]=xsBRsim[11*u+6]/xsBRexp[11*u+6];//ττ
      strength[39*u + 32]=xsBRsim[11*u+7]/xsBRexp[11*u+7];//νν
      strength[39*u + 33]=xsBRsim[11*u+8]/xsBRexp[11*u+8];//WW
      strength[39*u + 34]=xsBRsim[11*u+9]/xsBRexp[11*u+9];//ZH
      strength[39*u + 35]= significance[u]*1;//χχ
      strength[39*u + 36]=xsBRsim[11*u+10]/xsBRexp[11*u+10];//XX
      strength[39*u + 37]=totalwidth[u];//Total width
      

//Warning about narrow width approximation not satisfied

      if( (totalwidth[u]/mass[u])>0.05){
      strength[39*u + 38]=1;//Warning! Total width above 5%
printf("\nWarning, point with width above 5%, check corresponding column in /output/1.dat");
      }else{
      strength[39*u + 38]=0;//No warning. Total width bellow 5%
      }      
   

}

// Save all the masses (total:in_row) in the incard and the strength for each mass in each channel (total:10), with the total width and the narrow width approximation warning in ./output/1.dat
  printf("\n\nComplete!");


  saveo(strength,headers,1,1,in_row,39);




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

//free deallocates memory blocks previously allocated by the call to malloc, making them available again for further allocations.
  free(rows);
  free(sim_1);
  free(sim_2);     
  free(sim_3);     
  free(sim_4);     
  free(sim_5);
  free(sim_6);
  free(sim_7);     
  free(sim_8);     
  free(sim_9);     
  free(sim_10);
  free(sim_11);
  free(sim_12);     
  free(sim_13);     
  free(exp_1);
  free(exp_2);
  free(exp_3);     
  free(exp_4);     
  free(exp_5);
  free(exp_6);     
  free(exp_7);
  free(exp_8);
  free(exp_9);
  free(exp_10);
  free(dm_1);
  free(dm_2);
  free(in_card);
  free(widths);
  free(widthsATLAS);
  free(BR);

  printf("\nOutput has been written to: ./output/1.dat \n\n");
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
