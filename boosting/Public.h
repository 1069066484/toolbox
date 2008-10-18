#ifndef PUBLIC_H
#define PUBLIC_H

// standard include
#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;

// typedefs
typedef unsigned char		uchar;
typedef unsigned short		ushort;
typedef vector<int>			vectori;
typedef vector<float>		vectorf;
typedef vector<double>		vectord;
typedef vector<uchar>		vectoru;
typedef vector<ushort>		vectorus;
typedef vector<string>		vectorString;
static const double PI		= 3.1415926535897931;

// basic utility functions
template<class T> int	sign( T s ) { return (s > 0 ) ? 1 : ((s<0) ? -1 : 0); }
template<class T> T		squeeze( T v, T vMin, T vMax ) { return max((vMin),min((v),(vMax))); }
inline double			degToRad(double dDeg) { return dDeg * PI / 180; }
inline double			radToDeg(double dRad) { return dRad * 180 / PI; }
inline double			factorial(const int i) { double d=1.0; for(int k=2; k<=i; k++) d*=k; return d; }
inline int				roundInt(double v) {return (int)(v+0.5);}
inline void				abortError( const char *msg, const int line, const char *file) 
{
	if( msg==NULL )
		fprintf(stderr, "%s %d: ERROR\n", file, line );
	else
		fprintf(stderr, "%s %d: ERROR: %s\n", file, line, msg );
	abort();
}

inline void				abortError( const char *msg1, const char *msg2, const int line, const char *file) 
{
	fprintf(stderr, "%s %d: ERROR: %s %s\n", file, line, msg1, msg2 );
	abort();
}

// vector ops
template<class T> T         vecSum( const vector<T> &v )
{
	T sum = (T) 0.0; for( size_t i=0; i<v.size(); i++ ) sum+=v[i]; return sum;
}

template<class T> vector<T> vecAdd( const vector<T> &v1, const vector<T> &v2 )
{
	vector<T> r(v1); for( size_t i=0; i<v1.size(); i++ ) r[i]+=v2[i]; return r;
}

template<class T> vector<T> vecSub( const vector<T> &v1, const vector<T> &v2 )
{
	vector<T> r(v1); for( size_t i=0; i<v1.size(); i++ ) r[i]-=v2[i]; return r;
}

template<class T> vector<T> vecMul( const vector<T> &v1, const vector<T> &v2 )
{
	vector<T> r(v1); for( size_t i=0; i<v1.size(); i++ ) r[i]*=v2[i]; return r;
}

template<class T> vector<T> vecDiv( const vector<T> &v1, const vector<T> &v2 )
{
	vector<T> r(v1); for( size_t i=0; i<v1.size(); i++ ) r[i]/=v2[i]; return r;
}

template<class T> vector<T> vecAdd( const vector<T> &v, T val )
{
	vector<T> r(v); for( size_t i=0; i<v.size(); i++ )  r[i]+=val; return r;
}

template<class T> vector<T> vecSub( const vector<T> &v, T val )
{
	vector<T> r(v); for( size_t i=0; i<v.size(); i++ )  r[i]-=val; return r;
}

template<class T> vector<T> vecMul( const vector<T> &v, T val )
{
	vector<T> r(v); for( size_t i=0; i<v.size(); i++ ) r[i]*=val; return r;
}

template<class T> vector<T> vecDiv( const vector<T> &v, T val )
{
	vector<T> r(v); for( size_t i=0; i<v.size(); i++ ) r[i]/=val; return r;
}

template<class T> vector<T> vecSub( T val, const vector<T> &v )
{
	vector<T> r(v.size(),val); for( size_t i=0; i<v.size(); i++ ) r[i]-=v[i]; return r;
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << "[ " ; for (size_t i=0; i<v.size(); i++) os << v[i] << " "; os << "]"; return os;
}


#endif