# <a href="https://arxiv.org/pdf/2109.13194.pdf" target=newwindow >Z'-explorer 2.0: reconnoitering the dark matter landscape</a>

## A QUICK START USER GUIDE


### Víctor Martín Lozano, Rosa María Sandá Seoane, José Zurita 


#### SET UP



Download main directory `/Z'-explorer-2.0/` into your system. To start, set on `/lib/` folder and run `make`. No additional steps are required. 

The script runs in *C++*.

If changes in source code are done, set on `/lib/` folder again and repeat the above before running.





#### SET MODEL:


Information about the *Z'* model must be provided through an incard text file, that must be stored as `/incard/card_1.dat`. For each benchmark point in the New Physics parameter space, the following information must be provided in columns (separated by spaces, no tabs):

~~~
MZ'  guL guR  gdL  gdR  gcL  gcR  gsL  gsR  gbL  gbR  gtL  gtR  geL  geR  gμL  gμR  gτL  gτR  Γνν  Γww  ΓZh mχ gχL gχR Γxx
~~~

where `MZ'` is the *Z'* mass (in TeV), `gfL/R` is the *Z'* coupling to the corresponding Left/Right visible fermion, and `Γνν`, `Γww`, `ΓZh` are the partial widths to neutrinos, *WW* and *Zh*, and `mχ` is the fermionic DM mass (and `gχL/R` its Left/Right coupling to *Z'*). The total width to other non-SM particles can be added as `Γxx`.  If not, leave `Γxx` as 0.

Every benchmark point in parameter space should be set in a different row. There is no limit in the number of signal points (i.e. rows) that can be explored.


In `/incard/example/ATLAS-DM-Simplified-VEC-gq=0.25-gx=1` can be found an incard example for the vector mediator case presented in ATLAS results <a href="https://arxiv.org/pdf/2102.10874.pdf" target=newwindow >(arXiv:2102.10874)</a> to perform a test run and check the output card which will be placed at `/output/1.dat` .







#### RUN



After providing an incard, set on the main directory and enter `./program.out` .






#### EXPLORATION RESULTS:



The generated output file is saved in `/output/1.dat` . The output contains the following information for each benchmark point set in incard:
 
~~~
MZ'  guL guR  gdL  gdR  gcL  gcR  gsL  gsR  gbL  gbR  gtL  gtR  geL  geR  gμL  gμR  gτL  gτR  Γνν  Γww  ΓZh mχ gχL gχR Γxx  Sjj  Sbb  Stt  See  Sμμ  Sττ  Sνν  SWW  SZh  Sχχ Sxx   ΓZ'   WARNING:ΓZ'>5%
~~~

where `S` (defined as σ<sub>pred</sub>/σ<sub>lim</sub>) is the strength of the signal in each possible *Z'* decay channel, `ΓZ'` is the *Z'* total width and the warning displays 1 when `ΓZ'`>5% and 0 otherwise. 


More information about calculation can be found in `/extra/` folder:

- `2.dat` contains the estimated decay widths to all channels. 
- `3.dat` contains the estimated branching ratios to all channels.
- `4.dat` contains the estimated σ<sub>pred</sub> for visible channels.
- `5.dat` contains the extracted σ<sub>lim</sub> from experimental data for visible channels.





#### EXPERIMENTAL INFORMATION:



For visible channels:

Available experimental data from LHC to all possible *Z'* decay channels is stored in  `/cards/` folder as experimental cards. Data is specified in two columns, where the first one is the corresponding M<sub>Z'</sub> (in TeV) and the second one is the corresponding σ<sub>lim</sub> (in pb): 


- `exp_card_1.dat`-> *jj* <a href="https://arxiv.org/pdf/1910.08447.pdf" target=newwindow >(arXiv:1910.08447)</a>
- `exp_card_2.dat`-> *bb* <a href="https://arxiv.org/pdf/1910.08447.pdf" target=newwindow >(arXiv:1910.08447)</a> 
- `exp_card_3.dat`-> *tt* <a href="https://arxiv.org/pdf/1810.05905.pdf" target=newwindow >(arXiv:1810.05905)</a> 
- `exp_card_4.dat`-> *ee* <a href="https://arxiv.org/pdf/2103.02708.pdf" target=newwindow >(arXiv:2103.02708)</a>
- `exp_card_5.dat`-> *μμ* <a href="https://arxiv.org/pdf/2103.02708.pdf" target=newwindow >(arXiv:2103.02708)</a>
- `exp_card_6.dat`-> *ττ* <a href="https://arxiv.org/pdf/1709.07242.pdf" target=newwindow >(arXiv:1709.07242)</a>
- `exp_card_8.dat`-> *ww* <a href="https://arxiv.org/pdf/2109.06055" target=newwindow >(arXiv:2109.06055)</a>
- `exp_card_9.dat`-> *zh* <a href="https://arxiv.org/pdf/1906.00057.pdf" target=newwindow >(arXiv:1906.00057)</a>

User can update the experimental information just by replacing the corresponding experimental card. No other step is required. 




For invisible channels:

- `exp_card_7.dat`-> *νν* -
- `exp_card_10.dat`-> *xx* -

Note that `Sνν` and `Sxx` in `/output/1.dat` are left as dummy variables for future updates.

For the Dirac DM (*χχ*) channel, in  `/cards/` folder also can be found

- `DM/AXIAL/DM_1.dat` -> *χχ* <a href="https://arxiv.org/pdf/2102.10874.pdf" target=newwindow >(arXiv:2102.10874)</a> 

Data is specified in three columns in this case, where the first one is the corresponding M<sub>Z'</sub> (in TeV), the second one is the corresponding m<sub>χ</sub> (in TeV), and the third one is the σ<sub>lim</sub> (in pb). In this particular case, results are set for the leptophobic axial-vector mediator case with g<sub>q</sub>=0.25 and g<sub>χ</sub>=1 (as in ATLAS results in <a href="https://arxiv.org/pdf/2102.10874.pdf" target=newwindow >2102.10874</a>), so bounds are properly re-scale during program execution for arbitrary coupling structure.





#### RECORDED SIMULATIONS USED BY Z'-EXPLORER:



For visible channels:

For computing *Z'* production cross-section, previously generated and recorded production cross-section with *MadGraph5_aMC@NLO* <a href="https://arxiv.org/pdf/1405.0301.pdf" target=newwindow >(arXiv:1405.0301)</a> is stored in `/cards/` folder as simulation cards. These simulations were generated with a tailored *Z'* model which couples with unity to only one quark in the proton each time, at &radic; s = 13 TeV, and for M<sub>Z'</sub> between 0.4 and 8 TeV (the range of masses that can be scanned with *Z'-explorer*).

- `sim_card_1.dat`->  *uu* &rarr; *Z'*
- `sim_card_2.dat`->  *dd* &rarr; *Z'*
- `sim_card_3.dat`->  *cc* &rarr; *Z'*
- `sim_card_4.dat`->  *ss* &rarr; *Z'*
- `sim_card_5.dat`->  *bb* &rarr; *Z'*

These simulations are combined with the incard data to calculate σ<sub>pred</sub> for visible channels.



For invisible χχ channel:

In this case, since this channel is associated with the mono-jet search, for computing *Z'* production cross-section, previously generated and recorded production cross-section plus *ISR* with *MadGraph5_aMC@NLO* is stored in `/cards/` folder, also as simulation cards. These simulations were generated with a tailored *Z'* model which couples with unity to only one quark in the proton each time, at &radic; s = 13 TeV, and for M<sub>Z'</sub> between 0.001 and 2.5 TeV (the range of masses that are explored in the mono-jet results), for the vector and the axial-vector mediators cases.


- `AXIAL_Zpj_1.dat`->  *pp* &rarr; *Z'<sub>A</sub> j* 
- `AXIAL_Zpj_2.dat`->  *pp* &rarr; *Z'<sub>A</sub> j* 
- `AXIAL_Zpj_3.dat`->  *pp* &rarr; *Z'<sub>A</sub> j* 
- `AXIAL_Zpj_4.dat`->  *pp* &rarr; *Z'<sub>A</sub> j* 


- `VEC_Zpj_1.dat`->  *pp* &rarr; *Z'<sub>V</sub> j* 
- `VEC_Zpj_2.dat`->  *pp* &rarr; *Z'<sub>V</sub> j*  
- `VEC_Zpj_3.dat`->  *pp* &rarr; *Z'<sub>V</sub> j* 
- `VEC_Zpj_4.dat`->  *pp* &rarr; *Z'<sub>V</sub> j* 


These simulations are combined with the incard data and properly turn into right and left chiralities contributions to calculate σ<sub>pred</sub> for *χχ* channel.



For more information, please visit the associated publication <a href="https://arxiv.org/pdf/2109.13194.pdf" target=newwindow >*"Z'-explorer 2.0: reconnoitering the dark matter landscape"*</a>.
