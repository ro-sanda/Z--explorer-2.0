#!/bin/bash


rm rows_card_1.dat

name="rows_card_1"

s1=$(grep -c '^' sim_card_1.dat)
s2=$(grep -c '^' sim_card_2.dat)
s3=$(grep -c '^' sim_card_3.dat)
s4=$(grep -c '^' sim_card_4.dat)
s5=$(grep -c '^' sim_card_5.dat)
s6=$(grep -c '^' VEC_Zpj_1.dat)
s7=$(grep -c '^' VEC_Zpj_2.dat)
s8=$(grep -c '^' VEC_Zpj_3.dat)
s9=$(grep -c '^' VEC_Zpj_4.dat)
s10=$(grep -c '^' AXIAL_Zpj_1.dat)
s11=$(grep -c '^' AXIAL_Zpj_2.dat)
s12=$(grep -c '^' AXIAL_Zpj_3.dat)
s13=$(grep -c '^' AXIAL_Zpj_4.dat)



e1=$(grep -c '^' exp_card_1.dat)
e2=$(grep -c '^' exp_card_2.dat)
e3=$(grep -c '^' exp_card_3.dat)
e4=$(grep -c '^' exp_card_4.dat)
e5=$(grep -c '^' exp_card_5.dat)
e6=$(grep -c '^' exp_card_6.dat)
e7=$(grep -c '^' exp_card_7.dat)
e8=$(grep -c '^' exp_card_8.dat)
e9=$(grep -c '^' exp_card_9.dat)
e10=$(grep -c '^' exp_card_10.dat)

dm1=$(grep -c '^' DM/VEC/DM_1.dat )
dm2=$(grep -c '^' DM/AXIAL/DM_2.dat )

ir=$(grep -c '^' ../incard/card_1.dat)
ic=$(awk '{print NF; exit}' ../incard/card_1.dat)

# -e allows the use of \n
echo  -e "$s1 $e1 \n$s2 $e2 \n$s3 $e3 \n$s4 $e4 \n$s5 $e5 \n$s6 $e6 \n$s7 $e7 \n$s8 $e8 \n$s9 $e9 \n$s10 $e10 \n$s11 $dm1 \n$s12 $dm2 \n$s13 0 \n$ir $ic" >> "$name".dat



