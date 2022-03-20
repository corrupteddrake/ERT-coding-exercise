/*
Assessment Coordinate Transformation: Implement coordinate conversion utilities that
can convert radar coordinates (bearing, range) to GIS coordinates (lat, lon) and vice versa in C.
The header declaration could be the following or your own design.
*/

#include <math.h>
#include <stdio.h>

//This will be the function which converts GIS coordinates to radar coordinates
int GIS2Radar(double* range,
	double* bearing,
	double glonInit,
	double glatInit,
	double glonFinal,
	double glatFinal);

//This will be the function which converts radar coordinates to GIS coordinates
int RtoG(double range,
	double bearing,
	double  glonInit,
	double glatInit,
	double* glonFinal,
	double* glatFinal);


int main()
{
	// Radar coordinates
	double range = 0; double bearing=0;
	// GIS coordinates, WI = Wallops Islands, PR = Puerto Rico
	double WIlat = 37; double WIlong = -75; double PRlat = 18; double PRlong = -66;
	// Call GIS2Radar to take our initial GIS coordinates and convert to radar coordinates
	GIS2Radar(&range, &bearing, WIlong, WIlat, PRlong, PRlat);
	// Print radar coordinates
	printf("The range is %f meters and the bearing is %f degrees\n",range,bearing);
	// Call RtoG to take our radar coordinates and convert to back to GIS coordinates
	RtoG(range, bearing, WIlong, WIlat, &PRlong, &PRlat);
	// Print GIS coordinates
	printf("The Final Longitude is %f and the Final Latitude is %f\nNegative indicates west/south\n\n\n", PRlong, PRlat);
	return 0;
}

int GIS2Radar(double* range,
	double* bearing,
	double glonInit,
	double glatInit,
	double glonFinal,
	double glatFinal)
{
	/*
	Range Formula
	a = sin²(Δφ/2) + cos φ1 ⋅ cos φ2 ⋅ sin²(Δλ/2)
	c = 2 ⋅ atan2( √a, √(1−a) )
	d = R ⋅ c

	Bearing Formula
	θ = atan2( sin Δλ ⋅ cos φ2 , cos φ1 ⋅ sin φ2 − sin φ1 ⋅ cos φ2 ⋅ cos Δλ )
	*/

	// Constants
	double Pi = 3.142857l;
	double EarthR = 6371000;
	// Latitude initial, final, and difference in degrees
	double lati = glatInit * Pi / 180;
	double latf = glatFinal * Pi / 180;
	double latdif = latf- lati;
	// Longitude initial, final, and difference in degrees
	double longi = glonInit * Pi / 180;
	double longf = glonFinal * Pi / 180;
	double longdif = longf - longi;
	// a is a temporary variable
	double a = sin(latdif / 2)* sin(latdif / 2) + cos(lati) * cos(latf) * sin(longdif / 2) * sin(longdif / 2);

	*range = EarthR * 2 * atan2(sqrt(a), sqrt(1 - a));
	*bearing =  fmod((atan2((sin(longdif) * cos(latf)), (cos(lati) * sin(latf) - sin(lati) * cos(latf) * cos(longdif))) * 180 / Pi + 360) , 360);

	return 0;
}

int RtoG(double range,
	double bearing,
	double  glonInit,
	double glatInit,
	double* glonFinal,
	double* glatFinal)
{
	/*
	Latitude Formula
	φ2 = asin( sin φ1 ⋅ cos δ + cos φ1 ⋅ sin δ ⋅ cos θ )

	Longitude Formula
	λ2 = λ1 + atan2( sin θ ⋅ sin δ ⋅ cos φ1, cos δ − sin φ1 ⋅ sin φ2 )
	*/

	// Constants
	double Pi = 3.142857l;
	double EarthR = 6371000;
	// Latitude, longitude and bearing initial in degrees
	double lati = glatInit * Pi / 180;
	double longi = glonInit * Pi / 180;
	double b = bearing * Pi / 180;

	*glatFinal = asin(sin(lati) * cos(range / EarthR) + cos(lati) * sin(range / EarthR) * cos(b))*180/Pi;
	*glonFinal = (longi + atan2(sin(b) * sin(range / EarthR) * cos(lati), cos(range / EarthR) - sin(lati) * sin(*glatFinal*Pi/180))) * 180 / Pi;

	return 0;
}