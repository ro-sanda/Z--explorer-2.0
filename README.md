# <a href="https://arxiv.org/pdf/2109.13194.pdf" target=newwindow >Z'-explorer 2.0: reconnoitering the dark matter landscape</a>

## A QUICK START USER GUIDE


### Víctor Martín Lozano, Rosa María Sandá Seoane, José Zurita 


#### SET UP



Download main directory `/Z'-explorer-2.0/` into your system. To start, set on `/lib/` folder and run `make`. No additional steps are required. 

The script runs in C++.

If changes in source code are done, set on `/lib/` folder again and repeat the above before running.





#### SET MODEL:


Information about the Z' model must be provided through an incard text file, that must be stored as `/incard/card_1.dat`. For each benchmark point in the NP parameter space, the following information must be provided in columns (separated by spaces, no tabs):

~~~
MZ'  guL guR  gdL  gdR  gcL  gcR  gsL  gsR  gbL  gbR  gtL  gtR  geL  geR  gμL  gμR  gτL  gτR  Γνν  Γww  ΓZh mχ gχL gχR Γxx
~~~

where `MZ'` is the Z' mass (in TeV), `gfL/R` is the Z' coupling to the corresponding Left/Right visible fermion, and `Γνν`, `Γww`, `ΓZh` are the partial widths to neutrinos, WW and Zh, and `mχ` is the fermionic DM mass (and `gχL/R` its Left/Right coupling to Z'). The total width to other non-SM particles can be added as `Γxx`.  If not, leave `Γxx` as 0.

Every benchmark point in parameter space should be set in a different row. There is no limit in the number of signal points (i.e. rows) that can be explored.


In `/incard/example/ATLAS-DM-Simplified-VEC-gq=0.25-gx=1` can be found an incard example for the vector mediator case presented in ATLAS results (Phys. Rev.D 103 (2021) 11, 112006) to perform a test run and check the output card which will be placed at `/output/1.dat` .







#### RUN



After providing an incard, set on the main directory and enter `./program.out` .






#### EXPLORATION RESULTS:



The generated output file is saved in `/output/1.dat` . The output contains the following information for each benchmark point set in incard:
 
~~~
M  guL guR  gdL  gdR  gcL  gcR  gsL  gsR  gbL  gbR  gtL  gtR  geL  geR  gμL  gμR  gτL  gτR  Γνν  Γww  ΓZh mχ gχL gχR Γxx  Sjj  Sbb  Stt  See  Sμμ  Sττ  Sνν  SWW  SZh  Sχχ Sxx   ΓZ'   WARNING:ΓZ'>5%
~~~

where `S` (defined as σpred/σlim) is the strength of the signal in each possible Z' decay channel, `ΓZ'` is the Z' total width and the warning displays 1 when `ΓZ'`>5% and 0 otherwise. 


More information about calculation can be found in `/extra/` folder:

`2.dat` contains the estimated decay widths to all channels. 
`3.dat` contains the estimated branching ratios to all channels.
`4.dat` contains the estimated σpred for visible channels.
`5.dat` contains the extracted σlim from experimental data for visible channels.





#### EXPERIMENTAL INFORMATION:



For visible channels:

Available experimental data from LHC to all possible Z' decay channels is stored in  `/cards/` folder as experimental cards. Data is specified in two columns, where the first one is the corresponding MZ' (in TeV) and the second one is the corresponding σlim (in pb): 


`exp_card_1.dat`-> jj (arXiv:1910.08447) 

`exp_card_2.dat`-> bb (arXiv:1910.08447)
`exp_card_3.dat`-> tt (arXiv:1810.05955)
`exp_card_4.dat`-> ee (arXiv:2103.02708)
`exp_card_5.dat`-> μμ (arXiv:2103.02708)
`exp_card_6.dat`-> ττ (arXiv:1709.07242)
`exp_card_8.dat`-> ww (arXiv:1710.07235)
`exp_card_9.dat`-> zh (arXiv:1906.00057)

User can update the experimental information just by replacing the corresponding experimental card. No other step is required. 




For invisible channels:

`exp_card_7.dat`-> νν -
`exp_card_10.dat`-> xx -

Note that Sνν and Sxx in `/output/1.dat` are left as dummy variables for future updates.

For the Dirac DM (χχ) channel, in  `/cards/` folder also can be found

`DM/AXIAL/DM_1.dat` -> χχ (arXiv:2102.10874)

Data is specified in three columns in this case, where the first one is the corresponding MZ' (in TeV), the second one is the corresponding mχ (in TeV), and the third one is the σlim (in pb). In this particular case, results are set for the leptophobic axial-vector mediator case with gq=0.25 and gχ=1 (as in ATLAS results), so bounds are properly re-scale during program execution for arbitrary coupling structure.





#### RECORDED SIMULATIONS USED BY Z'-EXPLORER:



For visible channels:

For computing Z' production cross-section, previously generated and recorded production cross-section with MadGraph5_aMC@NLO (arXiv:1405.0301) is stored in `/cards/` folder as simulation cards. These simulations were generated with a tailored Z' model which couples with unity to only one quark in the proton each time, at sqrt(s) = 13 TeV, and for M between 0.4 and 8 TeV (the range of masses that can be explored with Z'-explorer).

`sim_card_1.dat`->  uu-->Z'
`sim_card_2.dat`->  dd-->Z'
`sim_card_3.dat`->  cc-->Z'
`sim_card_4.dat`->  ss-->Z'
`sim_card_5.dat`->  bb-->Z'

These simulations are combined with the incard data to calculate σpred for visible channels.



For invisible χχ channel:

In this case, since this channel is associated with the mono-jet search, for computing Z' production cross-section, previously generated and recorded production cross-section plus ISR with MadGraph5_aMC@NLO is stored in `/cards/` folder, also as simulation cards. These simulations were generated with a tailored Z' model which couples with unity to only one quark in the proton each time, at sqrt(s) = 13 TeV, and for M between 0.001 and 2.5 TeV (the range of masses that are explored in the mono-jet results), for the vector and the axial-vector mediators cases.


`AXIAL_Zpj_1.dat`->  pp-->Z'_{A} j
`AXIAL_Zpj_2.dat`->  pp-->Z'_{A} j
`AXIAL_Zpj_3.dat`->  pp-->Z'_{A} j
`AXIAL_Zpj_4.dat`->  pp-->Z'_{A} j

`VEC_Zpj_1.dat`->  pp-->Z'_{V} j
`VEC_Zpj_2.dat`->  pp-->Z'_{V} j
`VEC_Zpj_3.dat`->  pp-->Z'_{V} j
`VEC_Zpj_4.dat`->  pp-->Z'_{V} j


These simulations are combined with the incard data and properly turn into right and left chiralities contributions to calculate σpred for χχ channel.



For more information, please visit the associated publication *"Z'-explorer 2.0: reconnoitering the dark matter landscape".* (https://arxiv.org/pdf/2109.13194.pdf)
