
"IRI EDP" is the script file for gnuplot for ploting "IRI EDP.dat"


"IRI EDP.dat" is the dat file created by using 
Time_type = Universal, Year= 2021., Month= 03, Day= 03, Hour=11.
Coordinate_type = Geographic, Latitude= 37.8, Longitude= 284.6, Height= 100.
Prof. parameters: Start= 100. Stop= 2000. Step= 50.

"IRI EDP.png" is the plot made by gnuplot for "IRI EDP.dat"


"IRI EDP2" is the script file for gnuplot for ploting "IRI EDP2.dat"

"IRI EDP2.dat" is the dat file created by using 
Time_type = Universal, Year= 2021., Month= 03, Day= 04, Hour=23.
Coordinate_type = Geographic, Latitude= 37.8, Longitude= 284.6, Height= 100.
Prof. parameters: Start= 100. Stop= 2000. Step= 50.

"IRI EDP2.png" is the plot made by gnuplot for "IRI EDP.dat"

Errors given trying to run.txt is a txt file which has the erros given when trying to run iri2016
More specifically the command "g77 -o iri iritest.for irisub.for irifun.for iritec.for iridreg.for igrf.for  cira.for iriflip.for"
Which is meant to test iri2016. 

The dat files "IRI EDP.dat" and "IRI EDP2.dat" are created with https://ccmc.gsfc.nasa.gov/modelweb/models/iri2016_vitmo.php
Because iri2016 does not work.
