"makefile.win" is the makefile that will compile and run the fortran code assuming that it is in the same folder.
"nmake -f Makefile.win" in command prompt will run it.
It was originally designed for windows computers.

The dat files "IRI EDP.dat" and "IRI EDP2.dat" are currently created with https://ccmc.gsfc.nasa.gov/modelweb/models/iri2016_vitmo.php
Because I had a hard time getting iri2016 to work.  They will be changed in the future now that iri2016 can be compiled.

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
