The Folder "00_iri" has all the fortran code needed to run 
as well as "makefile.win" which compiles and runs the fortran code 
and "iri.exe" which is the compiled fortran code that can be run.

"makefile.win" is the makefile that will compile and run the fortran code assuming that it is in the same folder.
"nmake -f Makefile.win" in command prompt in the same directory will run it.
It was originally designed for windows computers.

"full IRI EDP.dat" is the full data given by "iri.exe" it includes both plots.

"IRI EDP" is the script file for gnuplot for ploting "IRI EDP.dat"

"IRI EDP.dat" is the dat file created by using the first data in "full IRI EDP.dat"
yyyy/mmdd(or -ddd)/hh.h):2021/ 303/11.0UT  geog Lat/Long/Alt= 37.8/ 284.6/ 100.0
Prof. parameters: Start= 100. Stop= 2000. Step= 50.

"IRI EDP.png" is the plot made by gnuplot for "IRI EDP.dat"
The Y-axis is Height in km and the X-axis is Electron_density in Ne/cm-3


"IRI EDP2" is the script file for gnuplot for ploting "IRI EDP2.dat"

"IRI EDP2.dat" is the dat file created by using the second data in "full IRI EDP.dat" 
yyyy/mmdd(or -ddd)/hh.h):2021/ 304/23.0UT  geog Lat/Long/Alt= 37.8/ 284.6/ 100.0
Prof. parameters: Start= 100. Stop= 2000. Step= 50.

"IRI EDP2.png" is the plot made by gnuplot for "IRI EDP.dat"
The Y-axis is Height in km and the X-axis is Electron_density in Ne/cm-3
