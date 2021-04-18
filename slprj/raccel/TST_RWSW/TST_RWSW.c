#include "rt_logging_mmi.h"
#include "TST_RWSW_capi.h"
#include <math.h>
#include "TST_RWSW.h"
#include "TST_RWSW_private.h"
#include "TST_RWSW_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "10.1 (R2020a) 18-Nov-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\TST_RWSW\\TST_RWSW_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static void dbgipsmwwm ( const real_T Aq_B [ 4 ] , const real_T
Bq_C [ 4 ] , real_T Aq_C [ 4 ] ) ; static void fciduf4grh ( const real_T Aq_B
[ 4 ] , const real_T Bq_C [ 4 ] , real_T Aq_C [ 4 ] ) ; static void
aoeglvt35v ( const real_T Aq_B [ 4 ] , const real_T Bq_C [ 4 ] , real_T Aq_C
[ 4 ] ) ; real_T glob7s ( real_T * p , int_T doy , real_T lon , const real_T
f107a , real_T * sw , real_T * swc , real_T ctloc , real_T stloc , real_T
c2tloc , real_T s2tloc , real_T c3tloc , real_T s3tloc , real_T apdf , real_T
apt , real_T * plg ) { real_T pset = 2.0 ; real_T t [ 14 ] ; real_T tt ;
real_T cd32 , cd18 , cd14 , cd39 , dfa ; real_T p32 , p18 , p14 , p39 ; int_T
i , j ; if ( p [ 99 ] == 0 ) { p [ 99 ] = pset ; } if ( p [ 99 ] != pset ) {
return - 1 ; } for ( j = 0 ; j < 14 ; j ++ ) { t [ j ] = 0.0 ; } cd32 =
muDoubleScalarCos ( DR * ( doy - p [ 31 ] ) ) ; cd18 = muDoubleScalarCos (
2.0 * DR * ( doy - p [ 17 ] ) ) ; cd14 = muDoubleScalarCos ( DR * ( doy - p [
13 ] ) ) ; cd39 = muDoubleScalarCos ( 2.0 * DR * ( doy - p [ 38 ] ) ) ; p32 =
p [ 31 ] ; p18 = p [ 17 ] ; p14 = p [ 13 ] ; p39 = p [ 38 ] ; dfa = f107a -
150.0 ; t [ 0 ] = p [ 21 ] * dfa ; t [ 1 ] = p [ 1 ] * plg [ 2 ] + p [ 2 ] *
plg [ 4 ] + p [ 22 ] * plg [ 6 ] + p [ 26 ] * plg [ 1 ] + p [ 14 ] * plg [ 3
] + p [ 59 ] * plg [ 5 ] ; t [ 2 ] = ( p [ 18 ] + p [ 47 ] * plg [ 2 ] + p [
29 ] * plg [ 4 ] ) * cd32 ; t [ 3 ] = ( p [ 15 ] + p [ 16 ] * plg [ 2 ] + p [
30 ] * plg [ 4 ] ) * cd18 ; t [ 4 ] = ( p [ 9 ] * plg [ 1 ] + p [ 10 ] * plg
[ 3 ] + p [ 20 ] * plg [ 5 ] ) * cd14 ; t [ 5 ] = ( p [ 37 ] * plg [ 1 ] ) *
cd39 ; if ( sw [ 7 ] ) { real_T t71 , t72 ; t71 = p [ 11 ] * plg [ 11 ] *
cd14 * swc [ 5 ] ; t72 = p [ 12 ] * plg [ 11 ] * cd14 * swc [ 5 ] ; t [ 6 ] =
( ( p [ 3 ] * plg [ 10 ] + p [ 4 ] * plg [ 12 ] + t71 ) * ctloc + ( p [ 6 ] *
plg [ 10 ] + p [ 7 ] * plg [ 12 ] + t72 ) * stloc ) ; } if ( sw [ 8 ] ) {
real_T t81 , t82 ; t81 = ( p [ 23 ] * plg [ 21 ] + p [ 35 ] * plg [ 23 ] ) *
cd14 * swc [ 5 ] ; t82 = ( p [ 33 ] * plg [ 21 ] + p [ 36 ] * plg [ 23 ] ) *
cd14 * swc [ 5 ] ; t [ 7 ] = ( ( p [ 5 ] * plg [ 20 ] + p [ 41 ] * plg [ 22 ]
+ t81 ) * c2tloc + ( p [ 8 ] * plg [ 20 ] + p [ 42 ] * plg [ 22 ] + t82 ) *
s2tloc ) ; } if ( sw [ 14 ] ) { t [ 13 ] = p [ 39 ] * plg [ 30 ] * s3tloc + p
[ 40 ] * plg [ 30 ] * c3tloc ; } if ( sw [ 9 ] ) { if ( sw [ 9 ] == 1 ) { t [
8 ] = apdf * ( p [ 32 ] + p [ 45 ] * plg [ 2 ] * swc [ 2 ] ) ; } if ( sw [ 9
] == - 1 ) { t [ 8 ] = ( p [ 50 ] * apt + p [ 96 ] * plg [ 2 ] * apt * swc [
2 ] ) ; } } if ( ! ( ( sw [ 10 ] == 0 ) || ( sw [ 11 ] == 0 ) || ( lon <= -
1000.0 ) ) ) { t [ 10 ] = ( 1.0 + plg [ 1 ] * ( p [ 80 ] * swc [ 5 ] *
muDoubleScalarCos ( DR * ( doy - p [ 81 ] ) ) + p [ 85 ] * swc [ 6 ] *
muDoubleScalarCos ( 2.0 * DR * ( doy - p [ 86 ] ) ) ) + p [ 83 ] * swc [ 3 ]
* muDoubleScalarCos ( DR * ( doy - p [ 84 ] ) ) + p [ 87 ] * swc [ 4 ] *
muDoubleScalarCos ( 2.0 * DR * ( doy - p [ 88 ] ) ) ) * ( ( p [ 64 ] * plg [
11 ] + p [ 65 ] * plg [ 13 ] + p [ 66 ] * plg [ 15 ] + p [ 74 ] * plg [ 10 ]
+ p [ 75 ] * plg [ 12 ] + p [ 76 ] * plg [ 14 ] ) * muDoubleScalarCos ( DGTR
* lon ) + ( p [ 90 ] * plg [ 11 ] + p [ 91 ] * plg [ 13 ] + p [ 92 ] * plg [
15 ] + p [ 77 ] * plg [ 10 ] + p [ 78 ] * plg [ 12 ] + p [ 79 ] * plg [ 14 ]
) * muDoubleScalarSin ( DGTR * lon ) ) ; } tt = 0 ; for ( i = 0 ; i < 14 ; i
++ ) { tt += muDoubleScalarAbs ( ( real_T ) sw [ i + 1 ] ) * t [ i ] ; }
return tt ; } void gtd7 ( const int_T * doy , const real_T * sec , const
real_T * alt , real_T * lat , real_T * lon , const real_T * tloc , const
real_T * f107a , const real_T * f107 , real_T * ap , const real_T * aph ,
int_T numPoints , int_T * switches , real_T * sw , real_T * swc , real_T *
dens , real_T * T ) { real_T plg [ 36 ] ; real_T xmm ; int_T mn3 = 5 ; real_T
zn3 [ 5 ] = { 32.5 , 20.0 , 15.0 , 10.0 , 0.0 } ; int_T mn2 = 4 ; real_T zn2
[ 4 ] = { 72.5 , 55.0 , 45.0 , 32.5 } ; real_T zmix = 62.5 ; real_T dm28m ;
real_T tz ; real_T dmc ; real_T dmr ; real_T dz28 ; real_T dd ; real_T dm28 =
0 ; real_T meso_tn2 [ 4 ] ; real_T meso_tn3 [ 5 ] ; real_T meso_tgn2 [ 2 ] ;
real_T meso_tgn3 [ 2 ] ; real_T gsurf ; real_T re ; real_T ctloc , stloc ;
real_T c2tloc , s2tloc ; real_T s3tloc , c3tloc ; real_T apdf ; real_T apt [
4 ] ; real_T meso_tn1 [ 5 ] ; real_T meso_tgn1 [ 2 ] ; int_T i ; tselec (
switches , sw , swc ) ; xmm = pdm [ 2 ] [ 4 ] ; for ( i = 0 ; i < numPoints ;
i ++ ) { glatf ( lat [ i ] , & gsurf , & re , sw [ 2 ] ) ; gts7 ( doy [ i ] ,
sec [ i ] , alt [ i ] , lat [ i ] , lon [ i ] , tloc [ i ] , f107a [ i ] ,
f107 [ i ] , ap [ i ] , aph , numPoints , i , sw , swc , zn2 [ 0 ] , dens , T
, & dm28 , gsurf , re , & ctloc , & stloc , & c2tloc , & s2tloc , & c3tloc ,
& s3tloc , & apdf , & apt [ 0 ] , & meso_tn1 [ 0 ] , & meso_tgn1 [ 0 ] , &
plg [ 0 ] ) ; dm28m = dm28 * 1.0E6 ; if ( alt [ i ] < zn2 [ 0 ] ) { meso_tgn2
[ 0 ] = meso_tgn1 [ 1 ] ; meso_tn2 [ 0 ] = meso_tn1 [ 4 ] ; meso_tn2 [ 1 ] =
pma [ 0 ] [ 0 ] * pavgm [ 0 ] / ( 1.0 - sw [ 20 ] * glob7s ( pma [ 0 ] , doy
[ i ] , lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc
, c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tn2 [ 2 ] = pma
[ 1 ] [ 0 ] * pavgm [ 1 ] / ( 1.0 - sw [ 20 ] * glob7s ( pma [ 1 ] , doy [ i
] , lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc ,
c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tn2 [ 3 ] = pma [
2 ] [ 0 ] * pavgm [ 2 ] / ( 1.0 - sw [ 20 ] * sw [ 22 ] * glob7s ( pma [ 2 ]
, doy [ i ] , lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc ,
s2tloc , c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tgn2 [ 1
] = pavgm [ 8 ] * pma [ 9 ] [ 0 ] * ( 1.0 + sw [ 20 ] * sw [ 22 ] * glob7s (
pma [ 9 ] , doy [ i ] , lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc ,
c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) *
meso_tn2 [ 3 ] * meso_tn2 [ 3 ] / ( ( pma [ 2 ] [ 0 ] * pavgm [ 2 ] ) * ( pma
[ 2 ] [ 0 ] * pavgm [ 2 ] ) ) ; meso_tn3 [ 0 ] = meso_tn2 [ 3 ] ; if ( alt [
i ] < zn3 [ 0 ] ) { meso_tgn3 [ 0 ] = meso_tgn2 [ 1 ] ; meso_tn3 [ 1 ] = pma
[ 3 ] [ 0 ] * pavgm [ 3 ] / ( 1.0 - sw [ 22 ] * glob7s ( pma [ 3 ] , doy [ i
] , lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc ,
c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tn3 [ 2 ] = pma [
4 ] [ 0 ] * pavgm [ 4 ] / ( 1.0 - sw [ 22 ] * glob7s ( pma [ 4 ] , doy [ i ]
, lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc ,
c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tn3 [ 3 ] = pma [
5 ] [ 0 ] * pavgm [ 5 ] / ( 1.0 - sw [ 22 ] * glob7s ( pma [ 5 ] , doy [ i ]
, lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc ,
c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tn3 [ 4 ] = pma [
6 ] [ 0 ] * pavgm [ 6 ] / ( 1.0 - sw [ 22 ] * glob7s ( pma [ 6 ] , doy [ i ]
, lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc ,
c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tgn3 [ 1 ] = pma
[ 7 ] [ 0 ] * pavgm [ 7 ] * ( 1.0 + sw [ 22 ] * glob7s ( pma [ 7 ] , doy [ i
] , lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc ,
c3tloc , s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) * meso_tn3 [ 4 ] *
meso_tn3 [ 4 ] / ( ( pma [ 6 ] [ 0 ] * pavgm [ 6 ] ) * ( pma [ 6 ] [ 0 ] *
pavgm [ 6 ] ) ) ; } dmc = 0 ; if ( alt [ i ] > zmix ) { dmc = 1.0 - ( zn2 [ 0
] - alt [ i ] ) / ( zn2 [ 0 ] - zmix ) ; } dz28 = dens [ i + numPoints * 2 ]
; dmr = dens [ i + numPoints * 2 ] / dm28m - 1.0 ; dens [ i + numPoints * 2 ]
= densm ( alt [ i ] , dm28m , xmm , & tz , mn3 , zn3 , meso_tn3 , meso_tgn3 ,
mn2 , zn2 , meso_tn2 , meso_tgn2 , gsurf , re ) ; dens [ i + numPoints * 2 ]
= dens [ i + numPoints * 2 ] * ( 1.0 + dmr * dmc ) ; dmr = dens [ i ] / (
dz28 * pdm [ 0 ] [ 1 ] ) - 1.0 ; dens [ i ] = dens [ i + numPoints * 2 ] *
pdm [ 0 ] [ 1 ] * ( 1.0 + dmr * dmc ) ; dens [ i + numPoints ] = 0 ; dens [ i
+ numPoints * 8 ] = 0 ; dmr = dens [ i + numPoints * 3 ] / ( dz28 * pdm [ 3 ]
[ 1 ] ) - 1.0 ; dens [ i + numPoints * 3 ] = dens [ i + numPoints * 2 ] * pdm
[ 3 ] [ 1 ] * ( 1.0 + dmr * dmc ) ; dmr = dens [ i + numPoints * 4 ] / ( dz28
* pdm [ 4 ] [ 1 ] ) - 1.0 ; dens [ i + numPoints * 4 ] = dens [ i + numPoints
* 2 ] * pdm [ 4 ] [ 1 ] * ( 1.0 + dmr * dmc ) ; dens [ i + numPoints * 6 ] =
0 ; dens [ i + numPoints * 7 ] = 0 ; dens [ i + numPoints * 5 ] = 1.66E-24 *
( 4.0 * dens [ i ] + 16.0 * dens [ i + numPoints ] + 28.0 * dens [ i +
numPoints * 2 ] + 32.0 * dens [ i + numPoints * 3 ] + 40.0 * dens [ i +
numPoints * 4 ] + dens [ i + numPoints * 6 ] + 14.0 * dens [ i + numPoints *
7 ] ) ; dens [ i + numPoints * 5 ] = dens [ i + numPoints * 5 ] * 0.001 ; dd
= densm ( alt [ i ] , 1.0 , 0 , & tz , mn3 , zn3 , meso_tn3 , meso_tgn3 , mn2
, zn2 , meso_tn2 , meso_tgn2 , gsurf , re ) ; T [ i + numPoints ] = tz ; } }
} real_T zeta ( real_T zz , real_T zl , real_T re ) { return ( ( zz - zl ) *
( re + zl ) / ( re + zz ) ) ; } void spline ( real_T * x , real_T * y , int_T
n , real_T yp1 , real_T ypn , real_T * y2 ) { real_T u [ 10 ] ; real_T sig ,
p , qn , un ; int_T i , k ; if ( yp1 > 0.99E30 ) { y2 [ 0 ] = 0 ; u [ 0 ] = 0
; } else { y2 [ 0 ] = - 0.5 ; u [ 0 ] = ( 3.0 / ( x [ 1 ] - x [ 0 ] ) ) * ( (
y [ 1 ] - y [ 0 ] ) / ( x [ 1 ] - x [ 0 ] ) - yp1 ) ; } for ( i = 1 ; i < ( n
- 1 ) ; i ++ ) { sig = ( x [ i ] - x [ i - 1 ] ) / ( x [ i + 1 ] - x [ i - 1
] ) ; p = sig * y2 [ i - 1 ] + 2.0 ; y2 [ i ] = ( sig - 1.0 ) / p ; u [ i ] =
( 6.0 * ( ( y [ i + 1 ] - y [ i ] ) / ( x [ i + 1 ] - x [ i ] ) - ( y [ i ] -
y [ i - 1 ] ) / ( x [ i ] - x [ i - 1 ] ) ) / ( x [ i + 1 ] - x [ i - 1 ] ) -
sig * u [ i - 1 ] ) / p ; } if ( ypn > 0.99E30 ) { qn = 0 ; un = 0 ; } else {
qn = 0.5 ; un = ( 3.0 / ( x [ n - 1 ] - x [ n - 2 ] ) ) * ( ypn - ( y [ n - 1
] - y [ n - 2 ] ) / ( x [ n - 1 ] - x [ n - 2 ] ) ) ; } y2 [ n - 1 ] = ( un -
qn * u [ n - 2 ] ) / ( qn * y2 [ n - 2 ] + 1.0 ) ; for ( k = n - 2 ; k >= 0 ;
k -- ) y2 [ k ] = y2 [ k ] * y2 [ k + 1 ] + u [ k ] ; } void splint ( real_T
* xa , real_T * ya , real_T * y2a , int_T n , real_T x , real_T * y ) { int_T
klo = 0 ; int_T khi = n - 1 ; int_T k ; real_T h ; real_T a , b , yi ; while
( ( khi - klo ) > 1 ) { k = ( khi + klo ) * 0.5 ; if ( xa [ k ] > x ) khi = k
; else klo = k ; } h = xa [ khi ] - xa [ klo ] ; a = ( xa [ khi ] - x ) / h ;
b = ( x - xa [ klo ] ) / h ; yi = a * ya [ klo ] + b * ya [ khi ] + ( ( a * a
* a - a ) * y2a [ klo ] + ( b * b * b - b ) * y2a [ khi ] ) * h * h / 6.0 ; *
y = yi ; } void splini ( real_T * xa , real_T * ya , real_T * y2a , int_T n ,
real_T x , real_T * y ) { real_T yi = 0 ; int_T klo = 0 ; int_T khi = 1 ;
real_T xx , h , a , b , a2 , b2 ; while ( ( x > xa [ klo ] ) && ( khi < n ) )
{ xx = x ; if ( khi < ( n - 1 ) ) { if ( x < xa [ khi ] ) xx = x ; else xx =
xa [ khi ] ; } h = xa [ khi ] - xa [ klo ] ; a = ( xa [ khi ] - xx ) / h ; b
= ( xx - xa [ klo ] ) / h ; a2 = a * a ; b2 = b * b ; yi += ( ( 1.0 - a2 ) *
ya [ klo ] * 0.5 + b2 * ya [ khi ] * 0.5 + ( ( - ( 1.0 + a2 * a2 ) * 0.25 +
a2 * 0.5 ) * y2a [ klo ] + ( b2 * b2 * 0.25 - b2 * 0.5 ) * y2a [ khi ] ) * h
* h / 6.0 ) * h ; klo ++ ; khi ++ ; } * y = yi ; } real_T densm ( real_T alt
, real_T d0 , real_T xm , real_T * tz , int_T mn3 , real_T * zn3 , real_T *
tn3 , real_T * tgn3 , int_T mn2 , real_T * zn2 , real_T * tn2 , real_T * tgn2
, real_T gsurf , real_T re ) { real_T xs [ 10 ] , ys [ 10 ] , y2out [ 10 ] ;
real_T z , z1 , z2 , t1 , t2 , zg , zgdif ; real_T yd1 , yd2 ; real_T x , y ,
yi ; real_T expll , gamm , glb , sqterm ; real_T densm_tmp ; int_T mn ; int_T
k ; densm_tmp = d0 ; if ( alt > zn2 [ 0 ] ) { if ( xm == 0.0 ) return * tz ;
else return d0 ; } if ( alt > zn2 [ mn2 - 1 ] ) z = alt ; else z = zn2 [ mn2
- 1 ] ; mn = mn2 ; z1 = zn2 [ 0 ] ; z2 = zn2 [ mn - 1 ] ; t1 = tn2 [ 0 ] ; t2
= tn2 [ mn - 1 ] ; zg = zeta ( z , z1 , re ) ; zgdif = zeta ( z2 , z1 , re )
; for ( k = 0 ; k < mn ; k ++ ) { xs [ k ] = zeta ( zn2 [ k ] , z1 , re ) /
zgdif ; ys [ k ] = 1.0 / tn2 [ k ] ; } yd1 = - tgn2 [ 0 ] / ( t1 * t1 ) *
zgdif ; sqterm = ( re + z2 ) / ( re + z1 ) ; yd2 = - tgn2 [ 1 ] / ( t2 * t2 )
* zgdif * ( sqterm * sqterm ) ; spline ( xs , ys , mn , yd1 , yd2 , y2out ) ;
x = zg / zgdif ; splint ( xs , ys , y2out , mn , x , & y ) ; * tz = 1.0 / y ;
if ( xm != 0.0 ) { sqterm = 1.0 + z1 / re ; glb = gsurf / ( sqterm * sqterm )
; gamm = xm * glb * zgdif / RGAS ; splini ( xs , ys , y2out , mn , x , & yi )
; expll = gamm * yi ; if ( expll > 50.0 ) expll = 50.0 ; densm_tmp =
densm_tmp * ( t1 / * tz ) * muDoubleScalarExp ( - expll ) ; } if ( alt > zn3
[ 0 ] ) { if ( xm == 0.0 ) return * tz ; else return densm_tmp ; } z = alt ;
mn = mn3 ; z1 = zn3 [ 0 ] ; z2 = zn3 [ mn - 1 ] ; t1 = tn3 [ 0 ] ; t2 = tn3 [
mn - 1 ] ; zg = zeta ( z , z1 , re ) ; zgdif = zeta ( z2 , z1 , re ) ; for (
k = 0 ; k < mn ; k ++ ) { xs [ k ] = zeta ( zn3 [ k ] , z1 , re ) / zgdif ;
ys [ k ] = 1.0 / tn3 [ k ] ; } yd1 = - tgn3 [ 0 ] / ( t1 * t1 ) * zgdif ;
sqterm = ( re + z2 ) / ( re + z1 ) ; yd2 = - tgn3 [ 1 ] / ( t2 * t2 ) * zgdif
* ( sqterm * sqterm ) ; spline ( xs , ys , mn , yd1 , yd2 , y2out ) ; x = zg
/ zgdif ; splint ( xs , ys , y2out , mn , x , & y ) ; * tz = 1.0 / y ; if (
xm != 0.0 ) { sqterm = 1.0 + z1 / re ; glb = gsurf / ( sqterm * sqterm ) ;
gamm = xm * glb * zgdif / RGAS ; splini ( xs , ys , y2out , mn , x , & yi ) ;
expll = gamm * yi ; if ( expll > 50.0 ) expll = 50.0 ; densm_tmp = densm_tmp
* ( t1 / * tz ) * muDoubleScalarExp ( - expll ) ; } if ( xm == 0.0 ) return *
tz ; else return densm_tmp ; } void glatf ( const real_T lat , real_T * gv ,
real_T * reff , real_T flag ) { real_T c2 ; real_T xlat ; xlat = lat ; if (
flag == 0.0 ) { xlat = 45.0 ; } c2 = muDoubleScalarCos ( 2.0 * DGTR * xlat )
; * gv = 980.616 * ( 1.0 - 0.0026373 * c2 ) ; * reff = 2.0 * ( * gv ) / (
3.085462E-6 + 2.27E-9 * c2 ) * 1.0E-5 ; } void tselec ( int_T * switches ,
real_T * sw , real_T * swc ) { int_T i ; for ( i = 0 ; i < 24 ; i ++ ) { if (
i != 9 ) { if ( switches [ i ] == 1 ) sw [ i ] = 1 ; else sw [ i ] = 0 ; if (
switches [ i ] > 0 ) swc [ i ] = 1 ; else swc [ i ] = 0 ; } else { sw [ i ] =
switches [ i ] ; swc [ i ] = switches [ i ] ; } } } real_T densu ( real_T alt
, real_T dlb , real_T tinf , real_T tlb , real_T xm , real_T alpha , real_T *
tz , real_T zlb , real_T s2 , int_T mn1 , real_T * zn1 , real_T * tn1 ,
real_T * tgn1 , real_T gsurf , real_T re ) { real_T yd2 , yd1 , y ; real_T
densu_temp = 1.0 ; real_T za , z , zg2 , tt , ta ; real_T dta , z2 , t2 , zg
; real_T x = 0.0 ; real_T z1 = 0.0 ; real_T t1 = 0.0 ; real_T zgdif = 0.0 ;
int_T mn = 0 ; int_T k ; real_T glb ; real_T expll ; real_T yi ; real_T densa
, sqterm ; real_T gammad , gamm ; real_T xs [ 5 ] , ys [ 5 ] , y2out [ 5 ] ;
za = zn1 [ 0 ] ; if ( alt > za ) z = alt ; else z = za ; zg2 = zeta ( z , zlb
, re ) ; tt = tinf - ( tinf - tlb ) * muDoubleScalarExp ( - s2 * zg2 ) ; ta =
tt ; * tz = tt ; densu_temp = * tz ; if ( alt < za ) { sqterm = ( re + zlb )
/ ( re + za ) ; dta = ( tinf - ta ) * s2 * ( sqterm * sqterm ) ; tgn1 [ 0 ] =
dta ; tn1 [ 0 ] = ta ; if ( alt > zn1 [ mn1 - 1 ] ) z = alt ; else z = zn1 [
mn1 - 1 ] ; mn = mn1 ; z1 = zn1 [ 0 ] ; z2 = zn1 [ mn - 1 ] ; t1 = tn1 [ 0 ]
; t2 = tn1 [ mn - 1 ] ; zg = zeta ( z , z1 , re ) ; zgdif = zeta ( z2 , z1 ,
re ) ; for ( k = 0 ; k < mn ; k ++ ) { xs [ k ] = zeta ( zn1 [ k ] , z1 , re
) / zgdif ; ys [ k ] = 1.0 / tn1 [ k ] ; } yd1 = - tgn1 [ 0 ] / ( t1 * t1 ) *
zgdif ; sqterm = ( re + z2 ) / ( re + z1 ) ; yd2 = - tgn1 [ 1 ] / ( t2 * t2 )
* zgdif * ( sqterm * sqterm ) ; spline ( xs , ys , mn , yd1 , yd2 , y2out ) ;
x = zg / zgdif ; splint ( xs , ys , y2out , mn , x , & y ) ; * tz = 1.0 / y ;
densu_temp = * tz ; } if ( xm == 0.0 ) return densu_temp ; sqterm = 1.0 + zlb
/ re ; glb = gsurf / ( sqterm * sqterm ) ; gammad = xm * glb / ( s2 * RGAS *
tinf ) ; expll = muDoubleScalarExp ( - s2 * gammad * zg2 ) ; if ( expll >
50.0 ) { expll = 50.0 ; } if ( tt <= 0.0 ) { expll = 50.0 ; } densa = dlb *
muDoubleScalarPower ( tlb / tt , 1.0 + alpha + gammad ) * expll ; densu_temp
= densa ; if ( alt >= za ) return densu_temp ; sqterm = 1.0 + z1 / re ; glb =
gsurf / ( sqterm * sqterm ) ; gamm = xm * glb * zgdif / RGAS ; splini ( xs ,
ys , y2out , mn , x , & yi ) ; expll = gamm * yi ; if ( expll > 50.0 ) {
expll = 50.0 ; } if ( * tz <= 0.0 ) { expll = 50.0 ; } densu_temp =
densu_temp * muDoubleScalarPower ( t1 / * tz , 1.0 + alpha ) *
muDoubleScalarExp ( - expll ) ; return densu_temp ; } real_T sg0 ( real_T ex
, real_T * p , const real_T * ap ) { return ( ( ap [ 1 ] - 4.0 + ( p [ 25 ] -
1.0 ) * ( ap [ 1 ] - 4.0 + ( muDoubleScalarExp ( - muDoubleScalarAbs ( p [ 24
] ) * ( ap [ 1 ] - 4.0 ) ) - 1.0 ) / muDoubleScalarAbs ( p [ 24 ] ) ) ) + ex
* ( ( ap [ 2 ] - 4.0 + ( p [ 25 ] - 1.0 ) * ( ap [ 2 ] - 4.0 + (
muDoubleScalarExp ( - muDoubleScalarAbs ( p [ 24 ] ) * ( ap [ 2 ] - 4.0 ) ) -
1.0 ) / muDoubleScalarAbs ( p [ 24 ] ) ) ) + ex * ( ( ap [ 3 ] - 4.0 + ( p [
25 ] - 1.0 ) * ( ap [ 3 ] - 4.0 + ( muDoubleScalarExp ( - muDoubleScalarAbs (
p [ 24 ] ) * ( ap [ 3 ] - 4.0 ) ) - 1.0 ) / muDoubleScalarAbs ( p [ 24 ] ) )
) + ex * ( ( ap [ 4 ] - 4.0 + ( p [ 25 ] - 1.0 ) * ( ap [ 4 ] - 4.0 + (
muDoubleScalarExp ( - muDoubleScalarAbs ( p [ 24 ] ) * ( ap [ 4 ] - 4.0 ) ) -
1.0 ) / muDoubleScalarAbs ( p [ 24 ] ) ) ) + ex * ( ( ap [ 5 ] - 4.0 + ( p [
25 ] - 1.0 ) * ( ap [ 5 ] - 4.0 + ( muDoubleScalarExp ( - muDoubleScalarAbs (
p [ 24 ] ) * ( ap [ 5 ] - 4.0 ) ) - 1.0 ) / muDoubleScalarAbs ( p [ 24 ] ) )
) + ( ap [ 6 ] - 4.0 + ( p [ 25 ] - 1.0 ) * ( ap [ 6 ] - 4.0 + (
muDoubleScalarExp ( - muDoubleScalarAbs ( p [ 24 ] ) * ( ap [ 6 ] - 4.0 ) ) -
1.0 ) / muDoubleScalarAbs ( p [ 24 ] ) ) ) * muDoubleScalarPower ( ex , 8.0 )
) * ( 1.0 - muDoubleScalarPower ( ex , 8.0 ) ) / ( 1.0 - ex ) ) ) ) ) / ( 1.0
+ ( 1.0 - muDoubleScalarPower ( ex , 19.0 ) ) / ( 1.0 - ex ) *
muDoubleScalarSqrt ( ex ) ) ; } real_T globe7 ( real_T * p , const int_T doy
, const real_T sec , real_T lat , real_T lon , const real_T tloc , const
real_T f107a , const real_T f107 , real_T ap_in , const real_T * ap_a ,
real_T * sw , real_T * swc , real_T * ctloc , real_T * stloc , real_T *
c2tloc , real_T * s2tloc , real_T * c3tloc , real_T * s3tloc , real_T * apdf
, real_T * apt , real_T * plg ) { real_T t [ 15 ] ; int_T i , j ; int_T sw9 =
1 ; real_T apd ; real_T c , s , c2 , c4 , s2 ; real_T cd32 , cd18 , cd14 ,
cd39 ; real_T p32 , p18 , p14 , p39 ; real_T df , dfa ; real_T f1 , f2 ;
real_T tinf ; const real_T * ap ; for ( j = 0 ; j < 14 ; j ++ ) { t [ j ] = 0
; } if ( sw [ 9 ] > 0.0 ) { sw9 = 1 ; } else if ( sw [ 9 ] < 0.0 ) { sw9 = -
1 ; } c = muDoubleScalarSin ( lat * DGTR ) ; s = muDoubleScalarCos ( lat *
DGTR ) ; c2 = c * c ; c4 = c2 * c2 ; s2 = s * s ; plg [ 1 ] = c ; plg [ 2 ] =
0.5 * ( 3.0 * c2 - 1.0 ) ; plg [ 3 ] = 0.5 * ( 5.0 * c * c2 - 3.0 * c ) ; plg
[ 4 ] = ( 35.0 * c4 - 30.0 * c2 + 3.0 ) / 8.0 ; plg [ 5 ] = ( 63.0 * c2 * c2
* c - 70.0 * c2 * c + 15.0 * c ) * 0.125 ; plg [ 6 ] = ( 11.0 * c * plg [ 5 ]
- 5.0 * plg [ 4 ] ) / 6.0 ; plg [ 10 ] = s ; plg [ 11 ] = 3.0 * c * s ; plg [
12 ] = 1.5 * ( 5.0 * c2 - 1.0 ) * s ; plg [ 13 ] = 2.5 * ( 7.0 * c2 * c - 3.0
* c ) * s ; plg [ 14 ] = 1.875 * ( 21.0 * c4 - 14.0 * c2 + 1.0 ) * s ; plg [
15 ] = ( 11.0 * c * plg [ 14 ] - 6.0 * plg [ 13 ] ) * 0.2 ; plg [ 20 ] = 3.0
* s2 ; plg [ 21 ] = 15.0 * s2 * c ; plg [ 22 ] = 7.5 * ( 7.0 * c2 - 1.0 ) *
s2 ; plg [ 23 ] = 3.0 * c * plg [ 22 ] - 2.0 * plg [ 21 ] ; plg [ 24 ] = (
11.0 * c * plg [ 23 ] - 7.0 * plg [ 22 ] ) * 0.25 ; plg [ 25 ] = ( 13.0 * c *
plg [ 24 ] - 8.0 * plg [ 23 ] ) * 0.2 ; plg [ 30 ] = 15.0 * s2 * s ; plg [ 31
] = 105.0 * s2 * s * c ; plg [ 32 ] = ( 9.0 * c * plg [ 31 ] - 7. * plg [ 30
] ) * 0.5 ; plg [ 33 ] = ( 11.0 * c * plg [ 32 ] - 8. * plg [ 31 ] ) / 3.0 ;
if ( ! ( ( ( sw [ 7 ] == 0.0 ) && ( sw [ 8 ] == 0.0 ) ) && ( sw [ 14 ] == 0.0
) ) ) { * stloc = muDoubleScalarSin ( HR * tloc ) ; * ctloc =
muDoubleScalarCos ( HR * tloc ) ; * s2tloc = muDoubleScalarSin ( 2.0 * HR *
tloc ) ; * c2tloc = muDoubleScalarCos ( 2.0 * HR * tloc ) ; * s3tloc =
muDoubleScalarSin ( 3.0 * HR * tloc ) ; * c3tloc = muDoubleScalarCos ( 3.0 *
HR * tloc ) ; } cd32 = muDoubleScalarCos ( DR * ( doy - p [ 31 ] ) ) ; cd18 =
muDoubleScalarCos ( 2.0 * DR * ( doy - p [ 17 ] ) ) ; cd14 =
muDoubleScalarCos ( DR * ( doy - p [ 13 ] ) ) ; cd39 = muDoubleScalarCos (
2.0 * DR * ( doy - p [ 38 ] ) ) ; p32 = p [ 31 ] ; p18 = p [ 17 ] ; p14 = p [
13 ] ; p39 = p [ 38 ] ; df = f107 - f107a ; dfa = f107a - 150.0 ; t [ 0 ] = p
[ 19 ] * df * ( 1.0 + p [ 59 ] * ( dfa ) ) + p [ 20 ] * df * df + p [ 21 ] *
( dfa ) + p [ 29 ] * ( dfa ) * ( dfa ) ; f1 = 1.0 + ( p [ 47 ] * ( dfa ) + p
[ 19 ] * df + p [ 20 ] * df * df ) * swc [ 1 ] ; f2 = 1.0 + ( p [ 49 ] * (
dfa ) + p [ 19 ] * df + p [ 20 ] * df * df ) * swc [ 1 ] ; t [ 1 ] = ( p [ 1
] * plg [ 2 ] + p [ 2 ] * plg [ 4 ] + p [ 22 ] * plg [ 6 ] ) + ( p [ 14 ] *
plg [ 2 ] ) * ( dfa ) * swc [ 1 ] + p [ 26 ] * plg [ 1 ] ; t [ 2 ] = p [ 18 ]
* cd32 ; t [ 3 ] = ( p [ 15 ] + p [ 16 ] * plg [ 2 ] ) * cd18 ; t [ 4 ] = f1
* ( p [ 9 ] * plg [ 1 ] + p [ 10 ] * plg [ 3 ] ) * cd14 ; t [ 5 ] = p [ 37 ]
* plg [ 1 ] * cd39 ; if ( sw [ 7 ] ) { real_T t71 , t72 ; t71 = ( p [ 11 ] *
plg [ 11 ] ) * cd14 * swc [ 5 ] ; t72 = ( p [ 12 ] * plg [ 11 ] ) * cd14 *
swc [ 5 ] ; t [ 6 ] = f2 * ( ( p [ 3 ] * plg [ 10 ] + p [ 4 ] * plg [ 12 ] +
p [ 27 ] * plg [ 14 ] + t71 ) * ( * ctloc ) + ( p [ 6 ] * plg [ 10 ] + p [ 7
] * plg [ 12 ] + p [ 28 ] * plg [ 14 ] + t72 ) * ( * stloc ) ) ; } if ( sw [
8 ] ) { real_T t81 , t82 ; t81 = ( p [ 23 ] * plg [ 21 ] + p [ 35 ] * plg [
23 ] ) * cd14 * swc [ 5 ] ; t82 = ( p [ 33 ] * plg [ 21 ] + p [ 36 ] * plg [
23 ] ) * cd14 * swc [ 5 ] ; t [ 7 ] = f2 * ( ( p [ 5 ] * plg [ 20 ] + p [ 41
] * plg [ 22 ] + t81 ) * ( * c2tloc ) + ( p [ 8 ] * plg [ 20 ] + p [ 42 ] *
plg [ 22 ] + t82 ) * ( * s2tloc ) ) ; } if ( sw [ 14 ] ) { t [ 13 ] = f2 * (
( p [ 39 ] * plg [ 30 ] + ( p [ 93 ] * plg [ 31 ] + p [ 46 ] * plg [ 33 ] ) *
cd14 * swc [ 5 ] ) * ( * s3tloc ) + ( p [ 40 ] * plg [ 30 ] + ( p [ 94 ] *
plg [ 31 ] + p [ 48 ] * plg [ 33 ] ) * cd14 * swc [ 5 ] ) * ( * c3tloc ) ) ;
} if ( sw [ 9 ] == - 1.0 ) { ap = ap_a ; if ( p [ 51 ] != 0.0 ) { real_T exp1
; exp1 = muDoubleScalarExp ( - 10800.0 * muDoubleScalarAbs ( p [ 51 ] ) / (
1.0 + p [ 138 ] * ( 45.0 - muDoubleScalarAbs ( lat ) ) ) ) ; if ( exp1 >
0.99999 ) { exp1 = 0.99999 ; } if ( p [ 24 ] < 1.0E-4 ) { p [ 24 ] = 1.0E-4 ;
} apt [ 0 ] = sg0 ( exp1 , p , ap ) ; if ( sw [ 9 ] ) { t [ 8 ] = apt [ 0 ] *
( p [ 50 ] + p [ 96 ] * plg [ 2 ] + p [ 54 ] * plg [ 4 ] + ( p [ 125 ] * plg
[ 1 ] + p [ 126 ] * plg [ 3 ] + p [ 127 ] * plg [ 5 ] ) * cd14 * swc [ 5 ] +
( p [ 128 ] * plg [ 10 ] + p [ 129 ] * plg [ 12 ] + p [ 130 ] * plg [ 14 ] )
* swc [ 7 ] * muDoubleScalarCos ( HR * ( tloc - p [ 131 ] ) ) ) ; } } } else
{ real_T p44 , p45 ; apd = ap_in - 4.0 ; p44 = p [ 43 ] ; p45 = p [ 44 ] ; if
( p44 < 0 ) { p44 = 1.0E-5 ; } * apdf = apd + ( p45 - 1.0 ) * ( apd + (
muDoubleScalarExp ( - p44 * apd ) - 1.0 ) / p44 ) ; if ( sw [ 9 ] ) { t [ 8 ]
= ( * apdf ) * ( p [ 32 ] + p [ 45 ] * plg [ 2 ] + p [ 34 ] * plg [ 4 ] + ( p
[ 100 ] * plg [ 1 ] + p [ 101 ] * plg [ 3 ] + p [ 102 ] * plg [ 5 ] ) * cd14
* swc [ 5 ] + ( p [ 121 ] * plg [ 10 ] + p [ 122 ] * plg [ 12 ] + p [ 123 ] *
plg [ 14 ] ) * swc [ 7 ] * muDoubleScalarCos ( HR * ( tloc - p [ 124 ] ) ) )
; } } if ( ( sw [ 10 ] ) && ( lon > - 1000.0 ) ) { if ( sw [ 11 ] ) { t [ 10
] = ( 1.0 + p [ 80 ] * ( dfa ) * swc [ 1 ] ) * ( ( p [ 64 ] * plg [ 11 ] + p
[ 65 ] * plg [ 13 ] + p [ 66 ] * plg [ 15 ] + p [ 103 ] * plg [ 10 ] + p [
104 ] * plg [ 12 ] + p [ 105 ] * plg [ 14 ] + swc [ 5 ] * ( p [ 109 ] * plg [
10 ] + p [ 110 ] * plg [ 12 ] + p [ 111 ] * plg [ 14 ] ) * cd14 ) *
muDoubleScalarCos ( DGTR * lon ) + ( p [ 90 ] * plg [ 11 ] + p [ 91 ] * plg [
13 ] + p [ 92 ] * plg [ 15 ] + p [ 106 ] * plg [ 10 ] + p [ 107 ] * plg [ 12
] + p [ 108 ] * plg [ 14 ] + swc [ 5 ] * ( p [ 112 ] * plg [ 10 ] + p [ 113 ]
* plg [ 12 ] + p [ 114 ] * plg [ 14 ] ) * cd14 ) * muDoubleScalarSin ( DGTR *
lon ) ) ; } if ( sw [ 12 ] ) { t [ 11 ] = ( 1.0 + p [ 95 ] * plg [ 1 ] ) * (
1.0 + p [ 81 ] * ( dfa ) * swc [ 1 ] ) * ( 1.0 + p [ 119 ] * plg [ 1 ] * swc
[ 5 ] * cd14 ) * ( ( p [ 68 ] * plg [ 1 ] + p [ 69 ] * plg [ 3 ] + p [ 70 ] *
plg [ 5 ] ) * muDoubleScalarCos ( SR * ( sec - p [ 71 ] ) ) ) ; t [ 11 ] +=
swc [ 11 ] * ( p [ 76 ] * plg [ 21 ] + p [ 77 ] * plg [ 23 ] + p [ 78 ] * plg
[ 25 ] ) * muDoubleScalarCos ( SR * ( sec - p [ 79 ] ) + 2.0 * DGTR * lon ) *
( 1.0 + p [ 137 ] * ( dfa ) * swc [ 1 ] ) ; } if ( sw [ 13 ] ) { if ( sw [ 9
] == - 1 ) { if ( p [ 51 ] ) { t [ 12 ] = apt [ 0 ] * swc [ 11 ] * ( 1. + p [
132 ] * plg [ 1 ] ) * ( ( p [ 52 ] * plg [ 11 ] + p [ 98 ] * plg [ 13 ] + p [
67 ] * plg [ 15 ] ) * muDoubleScalarCos ( DGTR * ( lon - p [ 97 ] ) ) ) + apt
[ 0 ] * swc [ 11 ] * swc [ 5 ] * ( p [ 133 ] * plg [ 10 ] + p [ 134 ] * plg [
12 ] + p [ 135 ] * plg [ 14 ] ) * cd14 * muDoubleScalarCos ( DGTR * ( lon - p
[ 136 ] ) ) + apt [ 0 ] * swc [ 12 ] * ( p [ 55 ] * plg [ 1 ] + p [ 56 ] *
plg [ 3 ] + p [ 57 ] * plg [ 5 ] ) * muDoubleScalarCos ( SR * ( sec - p [ 58
] ) ) ; } } else { t [ 12 ] = ( * apdf ) * swc [ 11 ] * ( 1.0 + p [ 120 ] *
plg [ 1 ] ) * ( ( p [ 60 ] * plg [ 11 ] + p [ 61 ] * plg [ 13 ] + p [ 62 ] *
plg [ 15 ] ) * muDoubleScalarCos ( DGTR * ( lon - p [ 63 ] ) ) ) + ( * apdf )
* swc [ 11 ] * swc [ 5 ] * ( p [ 115 ] * plg [ 10 ] + p [ 116 ] * plg [ 12 ]
+ p [ 117 ] * plg [ 14 ] ) * cd14 * muDoubleScalarCos ( DGTR * ( lon - p [
118 ] ) ) + ( * apdf ) * swc [ 12 ] * ( p [ 83 ] * plg [ 1 ] + p [ 84 ] * plg
[ 3 ] + p [ 85 ] * plg [ 5 ] ) * muDoubleScalarCos ( SR * ( sec - p [ 75 ] )
) ; } } } tinf = p [ 30 ] ; for ( i = 0 ; i < 14 ; i ++ ) { tinf = tinf +
muDoubleScalarAbs ( sw [ i + 1 ] ) * t [ i ] ; } return tinf ; } real_T dnet
( real_T dd , real_T dm , real_T zhm , real_T xmm , real_T xm ) { real_T a ;
real_T ylog ; a = zhm / ( xmm - xm ) ; if ( ! ( ( dm > 0 ) && ( dd > 0 ) ) )
{ if ( ( dd == 0 ) && ( dm == 0 ) ) { dd = 1 ; } if ( dm == 0.0 ) { return dd
; } if ( dd == 0.0 ) { return dm ; } } ylog = a * muDoubleScalarLog ( dm / dd
) ; if ( ylog < - 10.0 ) { return dd ; } if ( ylog > 10.0 ) { return dm ; } a
= dd * muDoubleScalarPower ( ( 1.0 + muDoubleScalarExp ( ylog ) ) , ( 1.0 / a
) ) ; return a ; } real_T scalh ( real_T alt , real_T xm , real_T temp ,
real_T gsurf , real_T re ) { real_T g , denom ; denom = 1.0 + alt / re ; g =
gsurf / ( denom * denom ) ; g = RGAS * temp / ( g * xm ) ; return g ; }
real_T ccor2 ( real_T alt , real_T r , real_T h1 , real_T zh , real_T h2 ) {
real_T e1 , e2 , ex1 , ex2 , ccor2v ; e1 = ( alt - zh ) / h1 ; e2 = ( alt -
zh ) / h2 ; if ( ( e1 > 70.0 ) || ( e2 > 70.0 ) ) { ccor2v = 0.0 ; } else {
if ( ( e1 < - 70.0 ) && ( e2 < - 70.0 ) ) { ccor2v = r ; } else { ex1 =
muDoubleScalarExp ( e1 ) ; ex2 = muDoubleScalarExp ( e2 ) ; ccor2v = r / (
1.0 + 0.5 * ( ex1 + ex2 ) ) ; } } return muDoubleScalarExp ( ccor2v ) ; }
real_T ccor ( real_T alt , real_T r , real_T h1 , real_T zh ) { real_T e , ex
; e = ( alt - zh ) / h1 ; if ( e > 70.0 ) { e = 0.0 ; } else { if ( e < -
70.0 ) { e = r ; } else { ex = muDoubleScalarExp ( e ) ; e = r / ( 1.0 + ex )
; } } return muDoubleScalarExp ( e ) ; } void gts7 ( const int_T doy , const
real_T sec , const real_T alt , real_T lat , real_T lon , const real_T tloc ,
const real_T f107a , const real_T f107 , real_T ap , const real_T * aph ,
int_T numPoints , int_T i , real_T * sw , real_T * swc , real_T zn20 , real_T
* dens , real_T * T , real_T * dm28 , real_T gsurf , real_T re , real_T *
ctloc , real_T * stloc , real_T * c2tloc , real_T * s2tloc , real_T * c3tloc
, real_T * s3tloc , real_T * apdf , real_T * apt , real_T * meso_tn1 , real_T
* meso_tgn1 , real_T * plg ) { real_T za ; int_T j , k ; real_T ddum , z ;
real_T zn1 [ 5 ] = { 120.0 , 110.0 , 100.0 , 90.0 , 72.5 } ; real_T tinf ;
int_T mn1 = 5 ; real_T g0var ; real_T tlb ; real_T s , z0 , t0 , tr12 ;
real_T db01 , db04 , db14 , db16 , db28 , db32 , db40 , db48 ; real_T zh28 ,
zh04 , zh16 , zh32 , zh40 , zh01 , zh14 ; real_T zhm28 , zhm04 , zhm16 ,
zhm32 , zhm40 , zhm01 , zhm14 ; real_T xmd ; real_T b28 , b04 , b16 , b32 ,
b40 , b01 , b14 ; real_T dm04 , dm16 , dm32 , dm40 , dm01 , dm14 ; real_T tz
; real_T g28 , g4 , g16 , g32 , g40 , g1 , g14 ; real_T zhf , xmm ; real_T
zc04 , zc16 , zc32 , zc40 , zc01 , zc14 ; real_T hc04 , hc16 , hc32 , hc40 ,
hc01 , hc14 ; real_T hcc16 , hcc32 , hcc01 , hcc14 ; real_T zcc16 , zcc32 ,
zcc01 , zcc14 ; real_T rc16 , rc32 , rc01 , rc14 ; real_T rl ; real_T g16h ,
db16h , tho , zsht , zmho , zsho ; real_T alpha [ 9 ] = { - 0.38 , 0.0 , 0.0
, 0.0 , 0.17 , 0.0 , - 0.38 , 0.0 , 0.0 } ; real_T altl [ 8 ] = { 200.0 ,
300.0 , 160.0 , 250.0 , 240.0 , 450.0 , 320.0 , 450.0 } ; real_T dd ; real_T
hc216 , hcc232 ; real_T altt ; za = pdl [ 1 ] [ 15 ] ; zn1 [ 0 ] = za ; if (
alt > zn20 ) { altt = alt ; } else { altt = zn20 ; } for ( j = 0 ; j < 9 ; j
++ ) { dens [ i + numPoints * j ] = 0 ; } tinf = ptm [ 0 ] * pt [ 0 ] ; if (
altt > zn1 [ 0 ] ) { tinf = tinf * ( 1.0 + sw [ 16 ] * globe7 ( pt , doy ,
sec , lat , lon , tloc , f107a , f107 , ap , aph , sw , swc , ctloc , stloc ,
c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt , plg ) ) ; } T [ i ] = tinf ;
g0var = ptm [ 3 ] * ps [ 0 ] ; if ( altt > zn1 [ 4 ] ) { g0var = g0var * (
1.0 + sw [ 19 ] * globe7 ( ps , doy , sec , lat , lon , tloc , f107a , f107 ,
ap , aph , sw , swc , ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc ,
apdf , apt , plg ) ) ; } tlb = ptm [ 1 ] * ( 1.0 + sw [ 17 ] * globe7 ( pd [
3 ] , doy , sec , lat , lon , tloc , f107a , f107 , ap , aph , sw , swc ,
ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt , plg ) ) * pd
[ 3 ] [ 0 ] ; s = g0var / ( tinf - tlb ) ; meso_tn1 [ 1 ] = ptm [ 6 ] * ptl [
0 ] [ 0 ] ; meso_tn1 [ 2 ] = ptm [ 2 ] * ptl [ 1 ] [ 0 ] ; meso_tn1 [ 3 ] =
ptm [ 7 ] * ptl [ 2 ] [ 0 ] ; meso_tn1 [ 4 ] = ptm [ 4 ] * ptl [ 3 ] [ 0 ] ;
meso_tgn1 [ 1 ] = ptm [ 8 ] * pma [ 8 ] [ 0 ] * meso_tn1 [ 4 ] * meso_tn1 [ 4
] / ( ( ptm [ 4 ] * ptl [ 3 ] [ 0 ] ) * ( ptm [ 4 ] * ptl [ 3 ] [ 0 ] ) ) ;
if ( altt < 300.0 ) { meso_tn1 [ 1 ] = meso_tn1 [ 1 ] / ( 1.0 - sw [ 18 ] *
glob7s ( ptl [ 0 ] , doy , lon , f107a , sw , swc , * ctloc , * stloc , *
c2tloc , * s2tloc , * c3tloc , * s3tloc , * apdf , apt [ 0 ] , plg ) ) ;
meso_tn1 [ 2 ] = meso_tn1 [ 2 ] / ( 1.0 - sw [ 18 ] * glob7s ( ptl [ 1 ] ,
doy , lon , f107a , sw , swc , * ctloc , * stloc , * c2tloc , * s2tloc , *
c3tloc , * s3tloc , * apdf , apt [ 0 ] , plg ) ) ; meso_tn1 [ 3 ] = meso_tn1
[ 3 ] / ( 1.0 - sw [ 18 ] * glob7s ( ptl [ 2 ] , doy , lon , f107a , sw , swc
, * ctloc , * stloc , * c2tloc , * s2tloc , * c3tloc , * s3tloc , * apdf ,
apt [ 0 ] , plg ) ) ; meso_tn1 [ 4 ] = meso_tn1 [ 4 ] / ( 1.0 - sw [ 18 ] *
sw [ 20 ] * glob7s ( ptl [ 3 ] , doy , lon , f107a , sw , swc , * ctloc , *
stloc , * c2tloc , * s2tloc , * c3tloc , * s3tloc , * apdf , apt [ 0 ] , plg
) ) ; meso_tgn1 [ 1 ] = ptm [ 8 ] * pma [ 8 ] [ 0 ] * meso_tn1 [ 4 ] *
meso_tn1 [ 4 ] / ( ( ptm [ 4 ] * ptl [ 3 ] [ 0 ] ) * ( ptm [ 4 ] * ptl [ 3 ]
[ 0 ] ) ) ; meso_tgn1 [ 1 ] = meso_tgn1 [ 1 ] * ( 1.0 + sw [ 18 ] * sw [ 20 ]
* glob7s ( pma [ 8 ] , doy , lon , f107a , sw , swc , * ctloc , * stloc , *
c2tloc , * s2tloc , * c3tloc , * s3tloc , * apdf , apt [ 0 ] , plg ) ) ; } z0
= zn1 [ 3 ] ; t0 = meso_tn1 [ 3 ] ; tr12 = 1.0 ; g28 = sw [ 21 ] * globe7 (
pd [ 2 ] , doy , sec , lat , lon , tloc , f107a , f107 , ap , aph , sw , swc
, ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt , plg ) ;
zhf = pdl [ 1 ] [ 24 ] * ( 1.0 + sw [ 5 ] * pdl [ 0 ] [ 24 ] *
muDoubleScalarSin ( DGTR * lat ) * muDoubleScalarCos ( DR * ( doy - pt [ 13 ]
) ) ) ; T [ i ] = tinf ; xmm = pdm [ 2 ] [ 4 ] ; z = altt ; db28 = pdm [ 2 ]
[ 0 ] * muDoubleScalarExp ( g28 ) * pd [ 2 ] [ 0 ] ; dens [ i + numPoints * 2
] = densu ( z , db28 , tinf , tlb , 28.0 , alpha [ 2 ] , & T [ i + numPoints
] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf , re ) ; dd =
dens [ i + numPoints * 2 ] ; zh28 = pdm [ 2 ] [ 2 ] * zhf ; zhm28 = pdm [ 2 ]
[ 3 ] * pdl [ 1 ] [ 5 ] ; xmd = 28.0 - xmm ; b28 = densu ( zh28 , db28 , tinf
, tlb , xmd , ( alpha [ 2 ] - 1.0 ) , & tz , ptm [ 5 ] , s , mn1 , zn1 ,
meso_tn1 , meso_tgn1 , gsurf , re ) ; if ( sw [ 15 ] && ( z <= altl [ 2 ] ) )
{ * dm28 = densu ( z , b28 , tinf , tlb , xmm , alpha [ 2 ] , & tz , ptm [ 5
] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf , re ) ; dens [ i +
numPoints * 2 ] = dnet ( dens [ i + numPoints * 2 ] , * dm28 , zhm28 , xmm ,
28.0 ) ; } g4 = sw [ 21 ] * globe7 ( pd [ 0 ] , doy , sec , lat , lon , tloc
, f107a , f107 , ap , aph , sw , swc , ctloc , stloc , c2tloc , s2tloc ,
c3tloc , s3tloc , apdf , apt , plg ) ; db04 = pdm [ 0 ] [ 0 ] *
muDoubleScalarExp ( g4 ) * pd [ 0 ] [ 0 ] ; dens [ i ] = densu ( z , db04 ,
tinf , tlb , 4. , alpha [ 0 ] , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 ,
zn1 , meso_tn1 , meso_tgn1 , gsurf , re ) ; dd = dens [ i ] ; if ( sw [ 15 ]
&& ( z < altl [ 0 ] ) ) { zh04 = pdm [ 0 ] [ 2 ] ; b04 = densu ( zh04 , db04
, tinf , tlb , 4. - xmm , alpha [ 0 ] - 1. , & T [ i + numPoints ] , ptm [ 5
] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf , re ) ; dm04 = densu ( z ,
b04 , tinf , tlb , xmm , 0. , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 ,
zn1 , meso_tn1 , meso_tgn1 , gsurf , re ) ; zhm04 = zhm28 ; dens [ i ] = dnet
( dens [ i ] , dm04 , zhm04 , xmm , 4. ) ; rl = muDoubleScalarLog ( b28 * pdm
[ 0 ] [ 1 ] / b04 ) ; zc04 = pdm [ 0 ] [ 4 ] * pdl [ 1 ] [ 0 ] ; hc04 = pdm [
0 ] [ 5 ] * pdl [ 1 ] [ 1 ] ; dens [ i ] = dens [ i ] * ccor ( z , rl , hc04
, zc04 ) ; } g16 = sw [ 21 ] * globe7 ( pd [ 1 ] , doy , sec , lat , lon ,
tloc , f107a , f107 , ap , aph , sw , swc , ctloc , stloc , c2tloc , s2tloc ,
c3tloc , s3tloc , apdf , apt , plg ) ; db16 = pdm [ 1 ] [ 0 ] *
muDoubleScalarExp ( g16 ) * pd [ 1 ] [ 0 ] ; dens [ i + numPoints ] = densu (
z , db16 , tinf , tlb , 16. , alpha [ 1 ] , & T [ i + numPoints ] , ptm [ 5 ]
, s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf , re ) ; dd = dens [ i +
numPoints ] ; if ( sw [ 15 ] && ( z <= altl [ 1 ] ) ) { zh16 = pdm [ 1 ] [ 2
] ; b16 = densu ( zh16 , db16 , tinf , tlb , 16.0 - xmm , ( alpha [ 1 ] - 1.0
) , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1
, gsurf , re ) ; dm16 = densu ( z , b16 , tinf , tlb , xmm , 0. , & T [ i +
numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf , re )
; zhm16 = zhm28 ; dens [ i + numPoints ] = dnet ( dens [ i + numPoints ] ,
dm16 , zhm16 , xmm , 16. ) ; rl = pdm [ 1 ] [ 1 ] * pdl [ 1 ] [ 16 ] * ( 1.0
+ sw [ 1 ] * pdl [ 0 ] [ 23 ] * ( f107a - 150.0 ) ) ; hc16 = pdm [ 1 ] [ 5 ]
* pdl [ 1 ] [ 3 ] ; zc16 = pdm [ 1 ] [ 4 ] * pdl [ 1 ] [ 2 ] ; hc216 = pdm [
1 ] [ 5 ] * pdl [ 1 ] [ 4 ] ; dens [ i + numPoints ] = dens [ i + numPoints ]
* ccor2 ( z , rl , hc16 , zc16 , hc216 ) ; hcc16 = pdm [ 1 ] [ 7 ] * pdl [ 1
] [ 13 ] ; zcc16 = pdm [ 1 ] [ 6 ] * pdl [ 1 ] [ 12 ] ; rc16 = pdm [ 1 ] [ 3
] * pdl [ 1 ] [ 14 ] ; dens [ i + numPoints ] = dens [ i + numPoints ] * ccor
( z , rc16 , hcc16 , zcc16 ) ; } g32 = sw [ 21 ] * globe7 ( pd [ 4 ] , doy ,
sec , lat , lon , tloc , f107a , f107 , ap , aph , sw , swc , ctloc , stloc ,
c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt , plg ) ; db32 = pdm [ 3 ] [ 0
] * muDoubleScalarExp ( g32 ) * pd [ 4 ] [ 0 ] ; dens [ i + numPoints * 3 ] =
densu ( z , db32 , tinf , tlb , 32. , alpha [ 3 ] , & T [ i + numPoints ] ,
ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf , re ) ; dd = dens [
i + numPoints * 3 ] ; if ( sw [ 15 ] ) { if ( z <= altl [ 3 ] ) { zh32 = pdm
[ 3 ] [ 2 ] ; b32 = densu ( zh32 , db32 , tinf , tlb , 32. - xmm , alpha [ 3
] - 1. , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 ,
meso_tgn1 , gsurf , re ) ; dm32 = densu ( z , b32 , tinf , tlb , xmm , 0. , &
T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 ,
gsurf , re ) ; zhm32 = zhm28 ; dens [ i + numPoints * 3 ] = dnet ( dens [ i +
numPoints * 3 ] , dm32 , zhm32 , xmm , 32. ) ; rl = muDoubleScalarLog ( b28 *
pdm [ 3 ] [ 1 ] / b32 ) ; hc32 = pdm [ 3 ] [ 5 ] * pdl [ 1 ] [ 7 ] ; zc32 =
pdm [ 3 ] [ 4 ] * pdl [ 1 ] [ 6 ] ; dens [ i + numPoints * 3 ] = dens [ i +
numPoints * 3 ] * ccor ( z , rl , hc32 , zc32 ) ; } hcc32 = pdm [ 3 ] [ 7 ] *
pdl [ 1 ] [ 22 ] ; hcc232 = pdm [ 3 ] [ 7 ] * pdl [ 0 ] [ 22 ] ; zcc32 = pdm
[ 3 ] [ 6 ] * pdl [ 1 ] [ 21 ] ; rc32 = pdm [ 3 ] [ 3 ] * pdl [ 1 ] [ 23 ] *
( 1. + sw [ 1 ] * pdl [ 0 ] [ 23 ] * ( f107a - 150. ) ) ; dens [ i +
numPoints * 3 ] = dens [ i + numPoints * 3 ] * ccor2 ( z , rc32 , hcc32 ,
zcc32 , hcc232 ) ; } g40 = sw [ 20 ] * globe7 ( pd [ 5 ] , doy , sec , lat ,
lon , tloc , f107a , f107 , ap , aph , sw , swc , ctloc , stloc , c2tloc ,
s2tloc , c3tloc , s3tloc , apdf , apt , plg ) ; db40 = pdm [ 4 ] [ 0 ] *
muDoubleScalarExp ( g40 ) * pd [ 5 ] [ 0 ] ; dens [ i + numPoints * 4 ] =
densu ( z , db40 , tinf , tlb , 40. , alpha [ 4 ] , & T [ i + numPoints ] ,
ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf , re ) ; dd = dens [
i + numPoints * 4 ] ; if ( sw [ 15 ] && ( z <= altl [ 4 ] ) ) { zh40 = pdm [
4 ] [ 2 ] ; b40 = densu ( zh40 , db40 , tinf , tlb , 40. - xmm , alpha [ 4 ]
- 1. , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 ,
meso_tgn1 , gsurf , re ) ; dm40 = densu ( z , b40 , tinf , tlb , xmm , 0. , &
T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 ,
gsurf , re ) ; zhm40 = zhm28 ; dens [ i + numPoints * 4 ] = dnet ( dens [ i +
numPoints * 4 ] , dm40 , zhm40 , xmm , 40. ) ; rl = muDoubleScalarLog ( b28 *
pdm [ 4 ] [ 1 ] / b40 ) ; hc40 = pdm [ 4 ] [ 5 ] * pdl [ 1 ] [ 9 ] ; zc40 =
pdm [ 4 ] [ 4 ] * pdl [ 1 ] [ 8 ] ; dens [ i + numPoints * 4 ] = dens [ i +
numPoints * 4 ] * ccor ( z , rl , hc40 , zc40 ) ; } g1 = sw [ 21 ] * globe7 (
pd [ 6 ] , doy , sec , lat , lon , tloc , f107a , f107 , ap , aph , sw , swc
, ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt , plg ) ;
db01 = pdm [ 5 ] [ 0 ] * muDoubleScalarExp ( g1 ) * pd [ 6 ] [ 0 ] ; dens [ i
+ numPoints * 6 ] = densu ( z , db01 , tinf , tlb , 1. , alpha [ 6 ] , & T [
i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf ,
re ) ; dd = dens [ i + numPoints * 6 ] ; if ( sw [ 15 ] && ( z <= altl [ 6 ]
) ) { zh01 = pdm [ 5 ] [ 2 ] ; b01 = densu ( zh01 , db01 , tinf , tlb , 1. -
xmm , alpha [ 6 ] - 1. , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 ,
meso_tn1 , meso_tgn1 , gsurf , re ) ; dm01 = densu ( z , b01 , tinf , tlb ,
xmm , 0. , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 ,
meso_tgn1 , gsurf , re ) ; zhm01 = zhm28 ; dens [ i + numPoints * 6 ] = dnet
( dens [ i + numPoints * 6 ] , dm01 , zhm01 , xmm , 1. ) ; rl =
muDoubleScalarLog ( b28 * pdm [ 5 ] [ 1 ] * muDoubleScalarAbs ( pdl [ 1 ] [
17 ] ) / b01 ) ; hc01 = pdm [ 5 ] [ 5 ] * pdl [ 1 ] [ 11 ] ; zc01 = pdm [ 5 ]
[ 4 ] * pdl [ 1 ] [ 10 ] ; dens [ i + numPoints * 6 ] = dens [ i + numPoints
* 6 ] * ccor ( z , rl , hc01 , zc01 ) ; hcc01 = pdm [ 5 ] [ 7 ] * pdl [ 1 ] [
19 ] ; zcc01 = pdm [ 5 ] [ 6 ] * pdl [ 1 ] [ 18 ] ; rc01 = pdm [ 5 ] [ 3 ] *
pdl [ 1 ] [ 20 ] ; dens [ i + numPoints * 6 ] = dens [ i + numPoints * 6 ] *
ccor ( z , rc01 , hcc01 , zcc01 ) ; } g14 = sw [ 21 ] * globe7 ( pd [ 7 ] ,
doy , sec , lat , lon , tloc , f107a , f107 , ap , aph , sw , swc , ctloc ,
stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt , plg ) ; db14 = pdm [
6 ] [ 0 ] * muDoubleScalarExp ( g14 ) * pd [ 7 ] [ 0 ] ; dens [ i + numPoints
* 7 ] = densu ( z , db14 , tinf , tlb , 14. , alpha [ 7 ] , & T [ i +
numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 , gsurf , re )
; dd = dens [ i + numPoints * 7 ] ; if ( sw [ 15 ] && ( z <= altl [ 7 ] ) ) {
zh14 = pdm [ 6 ] [ 2 ] ; b14 = densu ( zh14 , db14 , tinf , tlb , 14. - xmm ,
alpha [ 7 ] - 1. , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 ,
meso_tn1 , meso_tgn1 , gsurf , re ) ; dm14 = densu ( z , b14 , tinf , tlb ,
xmm , 0. , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 ,
meso_tgn1 , gsurf , re ) ; zhm14 = zhm28 ; dens [ i + numPoints * 7 ] = dnet
( dens [ i + numPoints * 7 ] , dm14 , zhm14 , xmm , 14. ) ; rl =
muDoubleScalarLog ( b28 * pdm [ 6 ] [ 1 ] * muDoubleScalarAbs ( pdl [ 0 ] [ 2
] ) / b14 ) ; hc14 = pdm [ 6 ] [ 5 ] * pdl [ 0 ] [ 1 ] ; zc14 = pdm [ 6 ] [ 4
] * pdl [ 0 ] [ 0 ] ; dens [ i + numPoints * 7 ] = dens [ i + numPoints * 7 ]
* ccor ( z , rl , hc14 , zc14 ) ; hcc14 = pdm [ 6 ] [ 7 ] * pdl [ 0 ] [ 4 ] ;
zcc14 = pdm [ 6 ] [ 6 ] * pdl [ 0 ] [ 3 ] ; rc14 = pdm [ 6 ] [ 3 ] * pdl [ 0
] [ 5 ] ; dens [ i + numPoints * 7 ] = dens [ i + numPoints * 7 ] * ccor ( z
, rc14 , hcc14 , zcc14 ) ; } g16h = sw [ 21 ] * globe7 ( pd [ 8 ] , doy , sec
, lat , lon , tloc , f107a , f107 , ap , aph , sw , swc , ctloc , stloc ,
c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt , plg ) ; db16h = pdm [ 7 ] [
0 ] * muDoubleScalarExp ( g16h ) * pd [ 8 ] [ 0 ] ; tho = pdm [ 7 ] [ 9 ] *
pdl [ 0 ] [ 6 ] ; dd = densu ( z , db16h , tho , tho , 16. , alpha [ 8 ] , &
T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 , meso_tn1 , meso_tgn1 ,
gsurf , re ) ; zsht = pdm [ 7 ] [ 5 ] ; zmho = pdm [ 7 ] [ 4 ] ; zsho = scalh
( zmho , 16.0 , tho , gsurf , re ) ; dens [ i + numPoints * 8 ] = dd *
muDoubleScalarExp ( - zsht / zsho * ( muDoubleScalarExp ( - ( z - zmho ) /
zsht ) - 1. ) ) ; dens [ i + numPoints * 5 ] = 1.66E-24 * ( 4.0 * dens [ i ]
+ 16.0 * dens [ i + numPoints ] + 28.0 * dens [ i + numPoints * 2 ] + 32.0 *
dens [ i + numPoints * 3 ] + 40.0 * dens [ i + numPoints * 4 ] + dens [ i +
numPoints * 6 ] + 14.0 * dens [ i + numPoints * 7 ] ) ; db48 = 1.66E-24 * (
4.0 * db04 + 16.0 * db16 + 28.0 * db28 + 32.0 * db32 + 40.0 * db40 + db01 +
14.0 * db14 ) ; z = muDoubleScalarAbs ( altt ) ; ddum = densu ( z , 1.0 ,
tinf , tlb , 0.0 , 0.0 , & T [ i + numPoints ] , ptm [ 5 ] , s , mn1 , zn1 ,
meso_tn1 , meso_tgn1 , gsurf , re ) ; for ( k = 0 ; k < 9 ; k ++ ) { dens [ i
+ numPoints * k ] = dens [ i + numPoints * k ] * 1.0E6 ; } dens [ i +
numPoints * 5 ] = dens [ i + numPoints * 5 ] * 0.001 ; } void do1ujkzw1j (
SimStruct * rtS_e ) { if ( ssGetTaskTime ( rtS_e , 1 ) != ssGetTStart ( rtS_e
) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_e ) ; } } void
kzauxcucvk ( SimStruct * rtS_p ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS_p ) ; } void oasjptnaiz ( real_T hdfwqrpykb , real_T nfvnlke0tk ,
real_T * nhpkpr1dty , real_T * cmve3jr4ue , bbhpdcgcgo * localP ) { *
nhpkpr1dty = hdfwqrpykb + localP -> Bias1_Bias ; * cmve3jr4ue = nfvnlke0tk +
localP -> Bias_Bias ; } void mk1vmb1o52 ( SimStruct * rtS_i ) { if (
ssGetTaskTime ( rtS_i , 1 ) != ssGetTStart ( rtS_i ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS_i ) ; } } void eqoa5urut4 (
SimStruct * rtS_m ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS_m ) ;
} void ebq2is5hcr ( real_T luwgnakfqn , real_T ccrot5rx0q , real_T *
h1g5nvit5v , real_T * nwgfbgxfjb ) { * h1g5nvit5v = luwgnakfqn ; * nwgfbgxfjb
= ccrot5rx0q ; } void f1lioccfqk ( k503avwxjn * localB , kwb1dp5oh3 * localDW
, n3egxfz4sp * localP ) { localDW -> lodlplndji = localP ->
Memory_InitialCondition ; localB -> pmiuvoq3bk = localP -> phi_Y0 ; } void
mlcpngipio ( real_T cz3z5zongt , real_T nfujqytcft , real_T j1x4kvzqcf ,
real_T myxwxnngug , real_T n3or2rertx , real_T mhg5x2pwwu , k503avwxjn *
localB , kwb1dp5oh3 * localDW , n3egxfz4sp * localP ) { int8_T s61_iter ;
real_T ddg0f3meib ; real_T i4l2z5ph0f ; real_T hyamzwudr2 ; s61_iter = 1 ; do
{ if ( s61_iter > localP -> Switch_Threshold ) { hyamzwudr2 = localDW ->
lodlplndji ; } else { hyamzwudr2 = muDoubleScalarAtan2 ( nfujqytcft ,
myxwxnngug * cz3z5zongt ) ; } muDoubleScalarSinCos ( hyamzwudr2 , &
ddg0f3meib , & i4l2z5ph0f ) ; localB -> pmiuvoq3bk = muDoubleScalarAtan2 (
mhg5x2pwwu * j1x4kvzqcf * ddg0f3meib * ddg0f3meib * ddg0f3meib + nfujqytcft ,
cz3z5zongt - i4l2z5ph0f * i4l2z5ph0f * i4l2z5ph0f * n3or2rertx * localP ->
Constant1_Value ) ; muDoubleScalarSinCos ( localB -> pmiuvoq3bk , &
ddg0f3meib , & i4l2z5ph0f ) ; ddg0f3meib = muDoubleScalarAtan2 ( myxwxnngug *
ddg0f3meib , i4l2z5ph0f ) ; localDW -> lodlplndji = ddg0f3meib ; s61_iter ++
; } while ( ( hyamzwudr2 != ddg0f3meib ) && ( s61_iter <= 5 ) ) ; } void
bq4wkncpnc ( const real_T gklo22scg2 [ 4 ] , e42udnywi5 * localB ) { localB
-> nm24payncx [ 0 ] = gklo22scg2 [ 0 ] ; localB -> nm24payncx [ 1 ] = -
gklo22scg2 [ 1 ] ; localB -> nm24payncx [ 2 ] = - gklo22scg2 [ 2 ] ; localB
-> nm24payncx [ 3 ] = - gklo22scg2 [ 3 ] ; } static void dbgipsmwwm ( const
real_T Aq_B [ 4 ] , const real_T Bq_C [ 4 ] , real_T Aq_C [ 4 ] ) { real_T r
[ 4 ] ; real_T Aq_B_p [ 16 ] ; int32_T i ; real_T r_p ; Aq_B_p [ 0 ] = Aq_B [
0 ] ; Aq_B_p [ 4 ] = - Aq_B [ 1 ] ; Aq_B_p [ 8 ] = - Aq_B [ 2 ] ; Aq_B_p [ 12
] = - Aq_B [ 3 ] ; Aq_B_p [ 1 ] = Aq_B [ 1 ] ; Aq_B_p [ 5 ] = Aq_B [ 0 ] ;
Aq_B_p [ 9 ] = Aq_B [ 3 ] ; Aq_B_p [ 13 ] = - Aq_B [ 2 ] ; Aq_B_p [ 2 ] =
Aq_B [ 2 ] ; Aq_B_p [ 6 ] = - Aq_B [ 3 ] ; Aq_B_p [ 10 ] = Aq_B [ 0 ] ;
Aq_B_p [ 14 ] = Aq_B [ 1 ] ; Aq_B_p [ 3 ] = Aq_B [ 3 ] ; Aq_B_p [ 7 ] = Aq_B
[ 2 ] ; Aq_B_p [ 11 ] = - Aq_B [ 1 ] ; Aq_B_p [ 15 ] = Aq_B [ 0 ] ; for ( i =
0 ; i < 4 ; i ++ ) { r_p = Aq_B_p [ i + 12 ] * Bq_C [ 3 ] + ( Aq_B_p [ i + 8
] * Bq_C [ 2 ] + ( Aq_B_p [ i + 4 ] * Bq_C [ 1 ] + Aq_B_p [ i ] * Bq_C [ 0 ]
) ) ; r [ i ] = r_p ; } Aq_C [ 0 ] = r [ 0 ] ; Aq_C [ 1 ] = r [ 1 ] ; Aq_C [
2 ] = r [ 2 ] ; Aq_C [ 3 ] = r [ 3 ] ; } void elrubs4mtp ( const real_T
mi1tnp1wue [ 4 ] , const real_T pswom11qvb [ 3 ] , pwekmvsjkf * localB ) {
real_T q [ 4 ] ; real_T Bq_A [ 4 ] ; real_T tmp [ 4 ] ; real_T tmp_p [ 4 ] ;
q [ 0 ] = mi1tnp1wue [ 0 ] ; q [ 1 ] = mi1tnp1wue [ 1 ] ; q [ 2 ] =
mi1tnp1wue [ 2 ] ; q [ 3 ] = mi1tnp1wue [ 3 ] ; Bq_A [ 0 ] = mi1tnp1wue [ 0 ]
; Bq_A [ 1 ] = - mi1tnp1wue [ 1 ] ; Bq_A [ 2 ] = - mi1tnp1wue [ 2 ] ; Bq_A [
3 ] = - mi1tnp1wue [ 3 ] ; tmp [ 0 ] = 0.0 ; tmp [ 1 ] = pswom11qvb [ 0 ] ;
tmp [ 2 ] = pswom11qvb [ 1 ] ; tmp [ 3 ] = pswom11qvb [ 2 ] ; dbgipsmwwm ( q
, tmp , tmp_p ) ; dbgipsmwwm ( tmp_p , Bq_A , q ) ; localB -> ehs4r2hz2y [ 0
] = q [ 1 ] ; localB -> ehs4r2hz2y [ 1 ] = q [ 2 ] ; localB -> ehs4r2hz2y [ 2
] = q [ 3 ] ; } void od5ryzaqzv ( const real_T mth2ecsuxh [ 4 ] , f5p4lyabrn
* localB , real_T rtp_zero_tol ) { real_T n ; n = muDoubleScalarSqrt ( ( (
mth2ecsuxh [ 0 ] * mth2ecsuxh [ 0 ] + mth2ecsuxh [ 1 ] * mth2ecsuxh [ 1 ] ) +
mth2ecsuxh [ 2 ] * mth2ecsuxh [ 2 ] ) + mth2ecsuxh [ 3 ] * mth2ecsuxh [ 3 ] )
; if ( n < rtp_zero_tol ) { localB -> cmzu1jjbu1 [ 0 ] = 1.0 ; localB ->
cmzu1jjbu1 [ 1 ] = 0.0 ; localB -> cmzu1jjbu1 [ 2 ] = 0.0 ; localB ->
cmzu1jjbu1 [ 3 ] = 0.0 ; } else { localB -> cmzu1jjbu1 [ 0 ] = mth2ecsuxh [ 0
] / n ; localB -> cmzu1jjbu1 [ 1 ] = mth2ecsuxh [ 1 ] / n ; localB ->
cmzu1jjbu1 [ 2 ] = mth2ecsuxh [ 2 ] / n ; localB -> cmzu1jjbu1 [ 3 ] =
mth2ecsuxh [ 3 ] / n ; } } void nlh1krt5jh ( const real_T ljx4z0tmby [ 4 ] ,
ih3fopwm3i * localB ) { if ( ljx4z0tmby [ 0 ] < 0.0 ) { localB -> do5ugpkgof
[ 0 ] = - ljx4z0tmby [ 0 ] ; localB -> do5ugpkgof [ 1 ] = - ljx4z0tmby [ 1 ]
; localB -> do5ugpkgof [ 2 ] = - ljx4z0tmby [ 2 ] ; localB -> do5ugpkgof [ 3
] = - ljx4z0tmby [ 3 ] ; } else { localB -> do5ugpkgof [ 0 ] = ljx4z0tmby [ 0
] ; localB -> do5ugpkgof [ 1 ] = ljx4z0tmby [ 1 ] ; localB -> do5ugpkgof [ 2
] = ljx4z0tmby [ 2 ] ; localB -> do5ugpkgof [ 3 ] = ljx4z0tmby [ 3 ] ; } }
void j5jrka03le ( const real_T a3iagknmqq [ 3 ] , const real_T lswjxdjqsm [ 3
] , o41qhtemcd * localB ) { real_T tmp [ 9 ] ; int32_T i ; tmp [ 0 ] = 0.0 ;
tmp [ 3 ] = - a3iagknmqq [ 2 ] ; tmp [ 6 ] = a3iagknmqq [ 1 ] ; tmp [ 1 ] =
a3iagknmqq [ 2 ] ; tmp [ 4 ] = 0.0 ; tmp [ 7 ] = - a3iagknmqq [ 0 ] ; tmp [ 2
] = - a3iagknmqq [ 1 ] ; tmp [ 5 ] = a3iagknmqq [ 0 ] ; tmp [ 8 ] = 0.0 ; for
( i = 0 ; i < 3 ; i ++ ) { localB -> nkm03paxwo [ i ] = 0.0 ; localB ->
nkm03paxwo [ i ] += tmp [ i ] * lswjxdjqsm [ 0 ] ; localB -> nkm03paxwo [ i ]
+= tmp [ i + 3 ] * lswjxdjqsm [ 1 ] ; localB -> nkm03paxwo [ i ] += tmp [ i +
6 ] * lswjxdjqsm [ 2 ] ; } } void cddxeghm3a ( const real_T cl1mtxc13t [ 9 ]
, oj1osi3mrn * localB , real_T rtp_tol ) { boolean_T isodd ; real_T A [ 9 ] ;
int8_T ipiv [ 3 ] ; int32_T p1 ; int32_T p2 ; real_T absx21 ; real_T absx31 ;
int32_T ix ; real_T smax ; int32_T iy ; int32_T jA ; int32_T c_ix ; int32_T d
; int32_T ijA ; memcpy ( & A [ 0 ] , & cl1mtxc13t [ 0 ] , 9U * sizeof (
real_T ) ) ; ipiv [ 0 ] = 1 ; ipiv [ 1 ] = 2 ; for ( p1 = 0 ; p1 < 2 ; p1 ++
) { p2 = p1 << 2 ; jA = 0 ; ix = p2 ; smax = muDoubleScalarAbs ( A [ p2 ] ) ;
for ( iy = 2 ; iy <= 3 - p1 ; iy ++ ) { ix ++ ; absx21 = muDoubleScalarAbs (
A [ ix ] ) ; if ( absx21 > smax ) { jA = iy - 1 ; smax = absx21 ; } } if ( A
[ p2 + jA ] != 0.0 ) { if ( jA != 0 ) { ipiv [ p1 ] = ( int8_T ) ( ( p1 + jA
) + 1 ) ; iy = p1 + jA ; smax = A [ p1 ] ; A [ p1 ] = A [ iy ] ; A [ iy ] =
smax ; ix = p1 + 3 ; iy += 3 ; smax = A [ ix ] ; A [ ix ] = A [ iy ] ; A [ iy
] = smax ; ix += 3 ; iy += 3 ; smax = A [ ix ] ; A [ ix ] = A [ iy ] ; A [ iy
] = smax ; } jA = ( p2 - p1 ) + 3 ; for ( ix = p2 + 1 ; ix < jA ; ix ++ ) { A
[ ix ] /= A [ p2 ] ; } } jA = p2 ; ix = p2 + 3 ; for ( iy = 0 ; iy <= 1 - p1
; iy ++ ) { if ( A [ ix ] != 0.0 ) { smax = - A [ ix ] ; c_ix = p2 + 1 ; d =
( jA - p1 ) + 6 ; for ( ijA = jA + 4 ; ijA < d ; ijA ++ ) { A [ ijA ] += A [
c_ix ] * smax ; c_ix ++ ; } } ix += 3 ; jA += 3 ; } } isodd = ( ipiv [ 0 ] >
1 ) ; smax = A [ 0 ] * A [ 4 ] * A [ 8 ] ; if ( ipiv [ 1 ] > 2 ) { isodd = !
isodd ; } if ( isodd ) { smax = - smax ; } if ( muDoubleScalarAbs ( smax ) <=
rtp_tol ) { memset ( & localB -> nxsqtyhezz [ 0 ] , 0 , 9U * sizeof ( real_T
) ) ; } else { memcpy ( & A [ 0 ] , & cl1mtxc13t [ 0 ] , 9U * sizeof ( real_T
) ) ; p1 = 0 ; p2 = 3 ; jA = 6 ; smax = muDoubleScalarAbs ( cl1mtxc13t [ 0 ]
) ; absx21 = muDoubleScalarAbs ( cl1mtxc13t [ 1 ] ) ; absx31 =
muDoubleScalarAbs ( cl1mtxc13t [ 2 ] ) ; if ( ( absx21 > smax ) && ( absx21 >
absx31 ) ) { p1 = 3 ; p2 = 0 ; A [ 0 ] = cl1mtxc13t [ 1 ] ; A [ 1 ] =
cl1mtxc13t [ 0 ] ; A [ 3 ] = cl1mtxc13t [ 4 ] ; A [ 4 ] = cl1mtxc13t [ 3 ] ;
A [ 6 ] = cl1mtxc13t [ 7 ] ; A [ 7 ] = cl1mtxc13t [ 6 ] ; } else { if (
absx31 > smax ) { p1 = 6 ; jA = 0 ; A [ 0 ] = cl1mtxc13t [ 2 ] ; A [ 2 ] =
cl1mtxc13t [ 0 ] ; A [ 3 ] = cl1mtxc13t [ 5 ] ; A [ 5 ] = cl1mtxc13t [ 3 ] ;
A [ 6 ] = cl1mtxc13t [ 8 ] ; A [ 8 ] = cl1mtxc13t [ 6 ] ; } } smax = A [ 1 ]
/ A [ 0 ] ; A [ 1 ] /= A [ 0 ] ; absx21 = A [ 2 ] / A [ 0 ] ; A [ 2 ] /= A [
0 ] ; A [ 4 ] -= smax * A [ 3 ] ; A [ 5 ] -= absx21 * A [ 3 ] ; A [ 7 ] -=
smax * A [ 6 ] ; A [ 8 ] -= absx21 * A [ 6 ] ; if ( muDoubleScalarAbs ( A [ 5
] ) > muDoubleScalarAbs ( A [ 4 ] ) ) { ix = p2 ; p2 = jA ; jA = ix ; A [ 1 ]
= absx21 ; A [ 2 ] = smax ; smax = A [ 4 ] ; A [ 4 ] = A [ 5 ] ; A [ 5 ] =
smax ; smax = A [ 7 ] ; A [ 7 ] = A [ 8 ] ; A [ 8 ] = smax ; } smax = A [ 5 ]
/ A [ 4 ] ; A [ 5 ] /= A [ 4 ] ; A [ 8 ] -= smax * A [ 7 ] ; smax = ( A [ 5 ]
* A [ 1 ] - A [ 2 ] ) / A [ 8 ] ; absx21 = - ( A [ 7 ] * smax + A [ 1 ] ) / A
[ 4 ] ; localB -> nxsqtyhezz [ p1 ] = ( ( 1.0 - A [ 3 ] * absx21 ) - A [ 6 ]
* smax ) / A [ 0 ] ; localB -> nxsqtyhezz [ p1 + 1 ] = absx21 ; localB ->
nxsqtyhezz [ p1 + 2 ] = smax ; smax = - A [ 5 ] / A [ 8 ] ; absx21 = ( 1.0 -
A [ 7 ] * smax ) / A [ 4 ] ; localB -> nxsqtyhezz [ p2 ] = - ( A [ 3 ] *
absx21 + A [ 6 ] * smax ) / A [ 0 ] ; localB -> nxsqtyhezz [ p2 + 1 ] =
absx21 ; localB -> nxsqtyhezz [ p2 + 2 ] = smax ; smax = 1.0 / A [ 8 ] ;
absx21 = - A [ 7 ] * smax / A [ 4 ] ; localB -> nxsqtyhezz [ jA ] = - ( A [ 3
] * absx21 + A [ 6 ] * smax ) / A [ 0 ] ; localB -> nxsqtyhezz [ jA + 1 ] =
absx21 ; localB -> nxsqtyhezz [ jA + 2 ] = smax ; } } void eehz0nr2kb ( const
real_T ivsiqbfipy [ 9 ] , cvp4al0icj * localB , real_T rtp_tol ) { cddxeghm3a
( ivsiqbfipy , & localB -> ivoxddha1s , rtp_tol ) ; } void pqreim41fn ( const
real_T jeqpu1po2k [ 9 ] , jf3t2hxsbw * localB ) { real_T qw_sq ; real_T qx_sq
; real_T qy_sq ; real_T qz_sq ; int32_T k ; real_T varargin_1 [ 4 ] ; real_T
ex ; int32_T b_k ; boolean_T exitg1 ; qw_sq = ( ( ( jeqpu1po2k [ 0 ] +
jeqpu1po2k [ 4 ] ) + jeqpu1po2k [ 8 ] ) + 1.0 ) * 0.25 ; qx_sq = ( ( (
jeqpu1po2k [ 0 ] + 1.0 ) - jeqpu1po2k [ 4 ] ) - jeqpu1po2k [ 8 ] ) * 0.25 ;
qy_sq = ( ( ( jeqpu1po2k [ 4 ] + 1.0 ) - jeqpu1po2k [ 0 ] ) - jeqpu1po2k [ 8
] ) * 0.25 ; qz_sq = ( ( ( jeqpu1po2k [ 8 ] + 1.0 ) - jeqpu1po2k [ 0 ] ) -
jeqpu1po2k [ 4 ] ) * 0.25 ; varargin_1 [ 0 ] = qw_sq ; varargin_1 [ 1 ] =
qx_sq ; varargin_1 [ 2 ] = qy_sq ; varargin_1 [ 3 ] = qz_sq ; if ( !
muDoubleScalarIsNaN ( qw_sq ) ) { k = 1 ; } else { k = 0 ; b_k = 2 ; exitg1 =
false ; while ( ( ! exitg1 ) && ( b_k < 5 ) ) { if ( ! muDoubleScalarIsNaN (
varargin_1 [ b_k - 1 ] ) ) { k = b_k ; exitg1 = true ; } else { b_k ++ ; } }
} if ( k == 0 ) { k = 1 ; } else { ex = varargin_1 [ k - 1 ] ; for ( b_k = k
; b_k < 4 ; b_k ++ ) { if ( ex < varargin_1 [ b_k ] ) { ex = varargin_1 [ b_k
] ; k = b_k + 1 ; } } } if ( k == 1 ) { qx_sq = muDoubleScalarSqrt ( qw_sq )
; localB -> ekmxe1wuqt [ 1 ] = ( jeqpu1po2k [ 7 ] - jeqpu1po2k [ 5 ] ) * 0.25
/ qx_sq ; localB -> ekmxe1wuqt [ 2 ] = ( jeqpu1po2k [ 2 ] - jeqpu1po2k [ 6 ]
) * 0.25 / qx_sq ; localB -> ekmxe1wuqt [ 3 ] = ( jeqpu1po2k [ 3 ] -
jeqpu1po2k [ 1 ] ) * 0.25 / qx_sq ; } else if ( k == 2 ) { qy_sq =
muDoubleScalarSqrt ( qx_sq ) ; localB -> ekmxe1wuqt [ 1 ] =
muDoubleScalarSqrt ( qx_sq ) ; qx_sq = ( jeqpu1po2k [ 7 ] - jeqpu1po2k [ 5 ]
) * 0.25 / qy_sq ; localB -> ekmxe1wuqt [ 2 ] = ( jeqpu1po2k [ 3 ] +
jeqpu1po2k [ 1 ] ) * 0.25 / qy_sq ; localB -> ekmxe1wuqt [ 3 ] = ( jeqpu1po2k
[ 2 ] + jeqpu1po2k [ 6 ] ) * 0.25 / qy_sq ; } else if ( k == 3 ) { qz_sq =
muDoubleScalarSqrt ( qy_sq ) ; localB -> ekmxe1wuqt [ 2 ] =
muDoubleScalarSqrt ( qy_sq ) ; qx_sq = ( jeqpu1po2k [ 2 ] - jeqpu1po2k [ 6 ]
) * 0.25 / qz_sq ; localB -> ekmxe1wuqt [ 1 ] = ( jeqpu1po2k [ 3 ] +
jeqpu1po2k [ 1 ] ) * 0.25 / qz_sq ; localB -> ekmxe1wuqt [ 3 ] = ( jeqpu1po2k
[ 7 ] + jeqpu1po2k [ 5 ] ) * 0.25 / qz_sq ; } else { qy_sq =
muDoubleScalarSqrt ( qz_sq ) ; localB -> ekmxe1wuqt [ 3 ] =
muDoubleScalarSqrt ( qz_sq ) ; qx_sq = ( jeqpu1po2k [ 3 ] - jeqpu1po2k [ 1 ]
) * 0.25 / qy_sq ; localB -> ekmxe1wuqt [ 1 ] = ( jeqpu1po2k [ 2 ] +
jeqpu1po2k [ 6 ] ) * 0.25 / qy_sq ; localB -> ekmxe1wuqt [ 2 ] = ( jeqpu1po2k
[ 7 ] + jeqpu1po2k [ 5 ] ) * 0.25 / qy_sq ; } localB -> ekmxe1wuqt [ 0 ] =
qx_sq ; } void oa2h4lycyt ( const real_T ct0vuwuv1m [ 4 ] , d3abumwlqi *
localB ) { localB -> jtgcw4sbk0 [ 0 ] = ct0vuwuv1m [ 0 ] ; localB ->
jtgcw4sbk0 [ 1 ] = - ct0vuwuv1m [ 1 ] ; localB -> jtgcw4sbk0 [ 2 ] = -
ct0vuwuv1m [ 2 ] ; localB -> jtgcw4sbk0 [ 3 ] = - ct0vuwuv1m [ 3 ] ; } void
jywb5kciye ( const real_T ptt4wh4j53 [ 3 ] , aa02bbdgo4 * localB , real_T
rtp_mu_cst ) { real_T rnorm ; real_T scale ; real_T absxk ; real_T t ; scale
= 3.3121686421112381E-170 ; absxk = muDoubleScalarAbs ( ptt4wh4j53 [ 0 ] ) ;
if ( absxk > 3.3121686421112381E-170 ) { rnorm = 1.0 ; scale = absxk ; } else
{ t = absxk / 3.3121686421112381E-170 ; rnorm = t * t ; } absxk =
muDoubleScalarAbs ( ptt4wh4j53 [ 1 ] ) ; if ( absxk > scale ) { t = scale /
absxk ; rnorm = rnorm * t * t + 1.0 ; scale = absxk ; } else { t = absxk /
scale ; rnorm += t * t ; } absxk = muDoubleScalarAbs ( ptt4wh4j53 [ 2 ] ) ;
if ( absxk > scale ) { t = scale / absxk ; rnorm = rnorm * t * t + 1.0 ;
scale = absxk ; } else { t = absxk / scale ; rnorm += t * t ; } rnorm = scale
* muDoubleScalarSqrt ( rnorm ) ; rnorm = - rtp_mu_cst / ( rnorm * rnorm *
rnorm ) ; localB -> gafarm32k2 [ 0 ] = rnorm * ptt4wh4j53 [ 0 ] ; localB ->
gafarm32k2 [ 1 ] = rnorm * ptt4wh4j53 [ 1 ] ; localB -> gafarm32k2 [ 2 ] =
rnorm * ptt4wh4j53 [ 2 ] ; } static void fciduf4grh ( const real_T Aq_B [ 4 ]
, const real_T Bq_C [ 4 ] , real_T Aq_C [ 4 ] ) { real_T r [ 4 ] ; real_T
Aq_B_p [ 16 ] ; int32_T i ; real_T r_p ; Aq_B_p [ 0 ] = Aq_B [ 0 ] ; Aq_B_p [
4 ] = - Aq_B [ 1 ] ; Aq_B_p [ 8 ] = - Aq_B [ 2 ] ; Aq_B_p [ 12 ] = - Aq_B [ 3
] ; Aq_B_p [ 1 ] = Aq_B [ 1 ] ; Aq_B_p [ 5 ] = Aq_B [ 0 ] ; Aq_B_p [ 9 ] =
Aq_B [ 3 ] ; Aq_B_p [ 13 ] = - Aq_B [ 2 ] ; Aq_B_p [ 2 ] = Aq_B [ 2 ] ;
Aq_B_p [ 6 ] = - Aq_B [ 3 ] ; Aq_B_p [ 10 ] = Aq_B [ 0 ] ; Aq_B_p [ 14 ] =
Aq_B [ 1 ] ; Aq_B_p [ 3 ] = Aq_B [ 3 ] ; Aq_B_p [ 7 ] = Aq_B [ 2 ] ; Aq_B_p [
11 ] = - Aq_B [ 1 ] ; Aq_B_p [ 15 ] = Aq_B [ 0 ] ; for ( i = 0 ; i < 4 ; i ++
) { r_p = Aq_B_p [ i + 12 ] * Bq_C [ 3 ] + ( Aq_B_p [ i + 8 ] * Bq_C [ 2 ] +
( Aq_B_p [ i + 4 ] * Bq_C [ 1 ] + Aq_B_p [ i ] * Bq_C [ 0 ] ) ) ; r [ i ] =
r_p ; } Aq_C [ 0 ] = r [ 0 ] ; Aq_C [ 1 ] = r [ 1 ] ; Aq_C [ 2 ] = r [ 2 ] ;
Aq_C [ 3 ] = r [ 3 ] ; } void hh4puuamkn ( const real_T lcngjswajo [ 4 ] ,
const real_T l5epnqtdyl [ 3 ] , nla0xfnlgl * localB ) { real_T q [ 4 ] ;
real_T Bq_A [ 4 ] ; real_T tmp [ 4 ] ; real_T tmp_p [ 4 ] ; q [ 0 ] =
lcngjswajo [ 0 ] ; q [ 1 ] = lcngjswajo [ 1 ] ; q [ 2 ] = lcngjswajo [ 2 ] ;
q [ 3 ] = lcngjswajo [ 3 ] ; Bq_A [ 0 ] = lcngjswajo [ 0 ] ; Bq_A [ 1 ] = -
lcngjswajo [ 1 ] ; Bq_A [ 2 ] = - lcngjswajo [ 2 ] ; Bq_A [ 3 ] = -
lcngjswajo [ 3 ] ; tmp [ 0 ] = 0.0 ; tmp [ 1 ] = l5epnqtdyl [ 0 ] ; tmp [ 2 ]
= l5epnqtdyl [ 1 ] ; tmp [ 3 ] = l5epnqtdyl [ 2 ] ; fciduf4grh ( q , tmp ,
tmp_p ) ; fciduf4grh ( tmp_p , Bq_A , q ) ; localB -> bogcyvs5ln [ 0 ] = q [
1 ] ; localB -> bogcyvs5ln [ 1 ] = q [ 2 ] ; localB -> bogcyvs5ln [ 2 ] = q [
3 ] ; } static void aoeglvt35v ( const real_T Aq_B [ 4 ] , const real_T Bq_C
[ 4 ] , real_T Aq_C [ 4 ] ) { real_T r [ 4 ] ; real_T Aq_B_p [ 16 ] ; int32_T
i ; real_T r_p ; Aq_B_p [ 0 ] = Aq_B [ 0 ] ; Aq_B_p [ 4 ] = - Aq_B [ 1 ] ;
Aq_B_p [ 8 ] = - Aq_B [ 2 ] ; Aq_B_p [ 12 ] = - Aq_B [ 3 ] ; Aq_B_p [ 1 ] =
Aq_B [ 1 ] ; Aq_B_p [ 5 ] = Aq_B [ 0 ] ; Aq_B_p [ 9 ] = Aq_B [ 3 ] ; Aq_B_p [
13 ] = - Aq_B [ 2 ] ; Aq_B_p [ 2 ] = Aq_B [ 2 ] ; Aq_B_p [ 6 ] = - Aq_B [ 3 ]
; Aq_B_p [ 10 ] = Aq_B [ 0 ] ; Aq_B_p [ 14 ] = Aq_B [ 1 ] ; Aq_B_p [ 3 ] =
Aq_B [ 3 ] ; Aq_B_p [ 7 ] = Aq_B [ 2 ] ; Aq_B_p [ 11 ] = - Aq_B [ 1 ] ;
Aq_B_p [ 15 ] = Aq_B [ 0 ] ; for ( i = 0 ; i < 4 ; i ++ ) { r_p = Aq_B_p [ i
+ 12 ] * Bq_C [ 3 ] + ( Aq_B_p [ i + 8 ] * Bq_C [ 2 ] + ( Aq_B_p [ i + 4 ] *
Bq_C [ 1 ] + Aq_B_p [ i ] * Bq_C [ 0 ] ) ) ; r [ i ] = r_p ; } Aq_C [ 0 ] = r
[ 0 ] ; Aq_C [ 1 ] = r [ 1 ] ; Aq_C [ 2 ] = r [ 2 ] ; Aq_C [ 3 ] = r [ 3 ] ;
} void czqbc2hafp ( const real_T baipg25gok [ 4 ] , const real_T p1zt5xcqr1 [
3 ] , cqptmcnrgi * localB ) { real_T q [ 4 ] ; real_T Bq_A [ 4 ] ; real_T tmp
[ 4 ] ; real_T tmp_p [ 4 ] ; q [ 0 ] = baipg25gok [ 0 ] ; q [ 1 ] =
baipg25gok [ 1 ] ; q [ 2 ] = baipg25gok [ 2 ] ; q [ 3 ] = baipg25gok [ 3 ] ;
Bq_A [ 0 ] = baipg25gok [ 0 ] ; Bq_A [ 1 ] = - baipg25gok [ 1 ] ; Bq_A [ 2 ]
= - baipg25gok [ 2 ] ; Bq_A [ 3 ] = - baipg25gok [ 3 ] ; tmp [ 0 ] = 0.0 ;
tmp [ 1 ] = p1zt5xcqr1 [ 0 ] ; tmp [ 2 ] = p1zt5xcqr1 [ 1 ] ; tmp [ 3 ] =
p1zt5xcqr1 [ 2 ] ; aoeglvt35v ( q , tmp , tmp_p ) ; aoeglvt35v ( tmp_p , Bq_A
, q ) ; localB -> gzi3omxt3y [ 0 ] = q [ 1 ] ; localB -> gzi3omxt3y [ 1 ] = q
[ 2 ] ; localB -> gzi3omxt3y [ 2 ] = q [ 3 ] ; } void MdlInitialize ( void )
{ rtX . hmz1jwrnco [ 0 ] = rtP . DYN_ATT_par . BOFq_ECI_ini [ 0 ] ; rtX .
hmz1jwrnco [ 1 ] = rtP . DYN_ATT_par . BOFq_ECI_ini [ 1 ] ; rtX . hmz1jwrnco
[ 2 ] = rtP . DYN_ATT_par . BOFq_ECI_ini [ 2 ] ; rtX . hmz1jwrnco [ 3 ] = rtP
. DYN_ATT_par . BOFq_ECI_ini [ 3 ] ; rtX . oxda0i4vgt [ 0 ] = rtP .
DYN_TRA_par . pos_ECI_ini [ 0 ] ; rtX . mxzg4wj1qp [ 0 ] = rtP . DYN_TRA_par
. vel_ECI_ini [ 0 ] ; rtX . pz5d015liz [ 0 ] = rtP . DYN_ATT_par . h_BOF_ini
[ 0 ] ; rtX . oxda0i4vgt [ 1 ] = rtP . DYN_TRA_par . pos_ECI_ini [ 1 ] ; rtX
. mxzg4wj1qp [ 1 ] = rtP . DYN_TRA_par . vel_ECI_ini [ 1 ] ; rtX . pz5d015liz
[ 1 ] = rtP . DYN_ATT_par . h_BOF_ini [ 1 ] ; rtX . oxda0i4vgt [ 2 ] = rtP .
DYN_TRA_par . pos_ECI_ini [ 2 ] ; rtX . mxzg4wj1qp [ 2 ] = rtP . DYN_TRA_par
. vel_ECI_ini [ 2 ] ; rtX . pz5d015liz [ 2 ] = rtP . DYN_ATT_par . h_BOF_ini
[ 2 ] ; rtDW . j14ebrdltq = rtP . otime_InitialCondition ; rtDW . mpzjv2x2qj
= rtP . olon_InitialCondition ; rtDW . p13ptnzy3r = rtP .
olat_InitialCondition ; rtDW . olub4b3luy = rtP . oalt_InitialCondition ;
f1lioccfqk ( & rtB . mlcpngipio4 , & rtDW . mlcpngipio4 , & rtP . mlcpngipio4
) ; f1lioccfqk ( & rtB . hdy13qwuxo , & rtDW . hdy13qwuxo , & rtP .
hdy13qwuxo ) ; rtDW . obcjv3kxjy [ 0 ] = rtP .
UnitDelay1_InitialCondition_g1fqgjuntl ; rtDW . obcjv3kxjy [ 1 ] = rtP .
UnitDelay1_InitialCondition_g1fqgjuntl ; memcpy ( & rtB . dp5osgsbrh [ 0 ] ,
& rtP . sp13_Y0 [ 0 ] , 13U * sizeof ( real_T ) ) ; memcpy ( & rtB .
pggd3p1kfa [ 0 ] , & rtP . cp13_Y0 [ 0 ] , 13U * sizeof ( real_T ) ) ; rtB .
bzfp2p0tab = rtP . r_Y0 ; rtB . e4i5mtlz0g = rtP . ct_Y0 ; rtB . gsshebwjge =
rtP . st_Y0 ; rtB . a2zv22y3vl = rtP . sa_Y0 ; rtB . ff5eism403 = rtP . ca_Y0
; rtDW . pkxcgdmvhn = rtP . UnitDelay_InitialCondition_mllgrjaacn ; rtDW .
kjg3l4zk5v [ 0 ] = rtP . UnitDelay2_InitialCondition_iiychjgimi [ 0 ] ; rtDW
. kjg3l4zk5v [ 1 ] = rtP . UnitDelay2_InitialCondition_iiychjgimi [ 1 ] ;
rtDW . kjg3l4zk5v [ 2 ] = rtP . UnitDelay2_InitialCondition_iiychjgimi [ 2 ]
; rtDW . kjg3l4zk5v [ 3 ] = rtP . UnitDelay2_InitialCondition_iiychjgimi [ 3
] ; rtDW . oor1kyyfva = rtP . UnitDelay1_InitialCondition_e0xnht2pv2 ; rtDW .
jscepyc3up = rtP . UnitDelay3_InitialCondition ; rtDW . heflbpch1o = rtP .
UnitDelay2_InitialCondition ; rtDW . ksxubnoebg = rtP .
UnitDelay4_InitialCondition ; rtB . e1s2agf3sl = rtP .
Merge_InitialOutput_myeiq12cia ; rtB . osvuulzthg = rtP .
Merge1_InitialOutput ; rtB . dumv41hbdf = rtP . Merge_InitialOutput ; memcpy
( & rtDW . jbpr4falgz [ 0 ] , & rtP . UnitDelay_InitialCondition_pndmycisf3 [
0 ] , 169U * sizeof ( real_T ) ) ; memcpy ( & rtDW . h5cjobt13t [ 0 ] , & rtP
. UnitDelay_InitialCondition_czov4a5uix [ 0 ] , 169U * sizeof ( real_T ) ) ;
memcpy ( & rtB . jzrcpmvzbm [ 0 ] , & rtP . tc1313_Y0 [ 0 ] , 169U * sizeof (
real_T ) ) ; memcpy ( & rtDW . e4yokmhfao [ 0 ] , & rtP .
UnitDelay_InitialCondition [ 0 ] , 169U * sizeof ( real_T ) ) ; memcpy ( &
rtDW . kcfi4cmlhd [ 0 ] , & rtP . UnitDelay1_InitialCondition_pstroo2j12 [ 0
] , 169U * sizeof ( real_T ) ) ; memcpy ( & rtB . ozswcsd4u3 [ 0 ] , & rtP .
dp1313_Y0 [ 0 ] , 169U * sizeof ( real_T ) ) ; memcpy ( & rtB . dihmarvgf1 [
0 ] , & rtP . snorm169_Y0 [ 0 ] , 169U * sizeof ( real_T ) ) ; rtB .
k1dyohghpp = rtP . Merge1_InitialOutput_mn1mvqmvlz ; memcpy ( & rtDW .
at05wcm525 [ 0 ] , & rtP . UnitDelay1_InitialCondition [ 0 ] , 13U * sizeof (
real_T ) ) ; memcpy ( & rtB . e14uz2pq5j [ 0 ] , & rtP . pp13_Y0 [ 0 ] , 13U
* sizeof ( real_T ) ) ; memcpy ( & rtB . cvl0iqdxpn [ 0 ] , & rtP .
pp13_Y0_kswnfuenys [ 0 ] , 13U * sizeof ( real_T ) ) ; rtB . cafvg0zdey = rtP
. bpp_Y0 ; rtB . ctx2gmm5rx = rtP . bt_Y0 ; rtB . bjwvgrv5ph = rtP . bp_Y0 ;
rtB . cep0acxp4f = rtP . br_Y0 ; rtB . nc2canpxds = rtP . bpp_Y0_pfjanwvnvp ;
rtB . awbmrd3k3c [ 0 ] = rtP . btbpbrbpp_Y0 [ 0 ] ; rtB . awbmrd3k3c [ 1 ] =
rtP . btbpbrbpp_Y0 [ 1 ] ; rtB . awbmrd3k3c [ 2 ] = rtP . btbpbrbpp_Y0 [ 2 ]
; rtB . awbmrd3k3c [ 3 ] = rtP . btbpbrbpp_Y0 [ 3 ] ; } void MdlStart ( void
) { void * catalog ; void * catalog_p ; void * catalog_e ; void * catalog_i ;
void * catalog_m ; void * catalog_g ; void * catalog_j ; void * catalog_f ; {
void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL )
; void * * pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize =
16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } rtDW . ieumzhiu2f = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . nhcu04wvy3 = - 1
; rtDW . mf0i505azj = false ; ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; rtDW . lkylelnm2t = - 1 ; rtDW . cxt5grgy1s = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . a1ezypvm4e = - 1
; rtDW . gofjuybrne = - 1 ; rtDW . iubpiqse3a = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . klnvxdk0zo = 0 ;
rtDW . gqm3ezc0kt = 0 ; rtDW . brol3yumog = 0 ; rtDW . nde44yxft0 = 0 ; rtDW
. pbwiaz4fg0 = 0 ; rtDW . far5xhf1km = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . ou4mxpicy1 = - 1
; rtDW . arhjxoel23 = - 1 ; rtDW . lnkokfcmam = 0 ; rtDW . nbibucftep = 0 ;
rtDW . o4nqlaod2d = 0 ; rtDW . dbsyarjlzj = - 1 ; rtDW . pdbx5fzllt = - 1 ;
rtDW . dwpkqcic1h = 0 ; rtDW . a4hao0xdt0 = - 1 ; rtDW . hvtie0034r = - 1 ;
rtDW . asg4lqag0n = 0 ; rtDW . gubyv1x2xq = 0 ; rtDW . fojyv4gldg = 0 ; rtDW
. kuwonxbzmn = 0 ; rtDW . a1xwiuwg2w = 0 ; catalog =
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW . k1im3nzvaa =
rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog , rtDW . k1im3nzvaa ,
"Assertion" ,
"TST_RWSW/DYN/DYN_AERO/ECI Position to LLA/Check deltaT/Assertion" ) ;
catalog_p = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
kdyvdf55ga = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_p , rtDW
. kdyvdf55ga , "Assertion" ,
 "TST_RWSW/DYN/DYN_AERO/ECI Position to LLA/Direction Cosine Matrix ECI to ECEF/Check deltaT/Assertion"
) ; catalog_e = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
iiujy2f33w = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_e , rtDW
. iiujy2f33w , "Assertion" ,
"TST_RWSW/DYN/DYN_MAG/ECI Position to LLA/Check deltaT/Assertion" ) ;
catalog_i = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
fodvlcmywy = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_i , rtDW
. fodvlcmywy , "Assertion" ,
 "TST_RWSW/DYN/DYN_MAG/ECI Position to LLA/Direction Cosine Matrix ECI to ECEF/Check deltaT/Assertion"
) ; catalog_m = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
jm0wxqrcug = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_m , rtDW
. jm0wxqrcug , "Check Altitude" ,
"TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/Check Altitude/Assertion" ) ;
catalog_g = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
gq0nld4wdg = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_g , rtDW
. gq0nld4wdg , "Check Latitude" ,
"TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/Check Latitude/Assertion" ) ;
catalog_j = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
b010mugrdz = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_j , rtDW
. b010mugrdz , "Check Longitude" ,
"TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/Check Longitude/Assertion" )
; catalog_f = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
epf4xhkmwj = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_f , rtDW
. epf4xhkmwj , "Is time within model limits" ,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/Is time within model limits/Assertion"
) ; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T makjgtdumf ;
real_T ekxkr2veu1 ; real_T m0ixzcbh2s ; real_T dcum1m1fvs ; real_T j0houlamnx
; real_T ezrnwi3ppv ; real_T cdtst4eq4s ; real_T lzg3jkvf1b ; real_T
ch3ah2ivhg ; real_T mgba0laxgv ; real_T dmu0wnvjef ; real_T p1mmpiyz5w ;
real_T iex4qysaug ; real_T days ; real_T time_REF_minofhr ; real_T lmonth [
12 ] ; real_T inttemp ; real_T temp ; real_T nxh00ek3k5 [ 14 ] ; int32_T
assessmentVar = - 1 ; int32_T assessmentVar_p = - 1 ; int32_T assessmentVar_e
= - 1 ; int32_T assessmentVar_i = - 1 ; int32_T assessmentVar_m = - 1 ;
int32_T assessmentVar_g = - 1 ; int32_T assessmentVar_j = - 1 ; int32_T
assessmentVar_f = - 1 ; real_T nhr4ttucgq ; int8_T rtPrevAction ; int8_T
rtAction ; real_T fuciomtlqo ; boolean_T jawowd4hmr ; real_T bcfumrjja4 ;
void * assessmentPtrVar ; int32_T s207_iter ; real_T p5ik2nyru2 [ 11 ] ;
real_T h2uwkjx5ez [ 11 ] ; int32_T s256_iter ; real_T d31dx4tj1g ; int32_T
s215_iter ; int32_T ppjbaqmd1e ; int32_T dkseqjxisg ; real_T a1ufdryz5x [ 169
] ; int32_T bey410cc2p ; real_T ekvqrpgybx [ 13 ] ; real_T bptigujyyv [ 3 ] ;
real_T jtzddfrunm [ 169 ] ; char_T TRANS ; ptrdiff_t M ; ptrdiff_t N ;
ptrdiff_t LDA ; ptrdiff_t INCX ; ptrdiff_t INCY ; int32_T i ; real_T
eldb3aqjyd [ 9 ] ; real_T eldb3aqjyd_p [ 9 ] ; real_T tmp [ 16 ] ; real_T
p0axoxooci_idx_1 ; real_T p0axoxooci_idx_0 ; real_T mds4tgyfhx_idx_1 ;
int64_T tmp_p ; int32_T qY ; int32_T qY_p ; SimStruct * S ; void * diag ;
int32_T qY_e ; int32_T qY_i ; static const int8_T tmp_e [ 8 ] = { 0 , 1 , 2 ,
3 , 4 , 5 , 7 , 8 } ; srClearBC ( rtDW . oasjptnaiz4 . j4omgsrsfr ) ;
srClearBC ( rtDW . ebq2is5hcrm . k2tbsd51jk ) ; srClearBC ( rtDW . p5zu1sk310
) ; srClearBC ( rtDW . mgjysjngq1 ) ; srClearBC ( rtDW . eznk3o5xwu ) ;
srClearBC ( rtDW . lgblsj3t4q ) ; srClearBC ( rtDW . cfsnxzglwr ) ; srClearBC
( rtDW . lwuzl0ygua ) ; srClearBC ( rtDW . jxlgxqsvbl ) ; srClearBC ( rtDW .
hxe31sma1e ) ; srClearBC ( rtDW . nyw4c2tuhv ) ; srClearBC ( rtDW .
pfulaza2sz ) ; srClearBC ( rtDW . juk5yec0yu ) ; srClearBC ( rtDW .
anrree0xau ) ; srClearBC ( rtDW . b4mdlatzxs ) ; srClearBC ( rtDW .
m5sp20k3wx ) ; srClearBC ( rtDW . d4p0jrfexh ) ; nhr4ttucgq = ssGetT ( rtS )
; rtB . mbuf3ttyoj = rtP . Gain_Gain_b3taeuvvdg * nhr4ttucgq ; rtB .
hxtmxsk1r0 = rtB . mbuf3ttyoj + rtP . JDepoch_days_Value ; rtB . f4wdtbi41r =
nhr4ttucgq + rtB . as41rna3ij ; nhr4ttucgq = ( rtB . hxtmxsk1r0 -
2.4150195E+6 ) / 365.25 ; fuciomtlqo = muDoubleScalarFloor ( nhr4ttucgq ) ;
nhr4ttucgq = muDoubleScalarFloor ( nhr4ttucgq ) + 1900.0 ; days = ( rtB .
hxtmxsk1r0 - 2.4150195E+6 ) - ( ( ( fuciomtlqo + 1900.0 ) - 1900.0 ) * 365.0
+ muDoubleScalarFloor ( ( ( fuciomtlqo + 1900.0 ) - 1901.0 ) * 0.25 ) ) ; if
( days < 1.0 ) { nhr4ttucgq = ( fuciomtlqo + 1900.0 ) - 1.0 ; days = ( rtB .
hxtmxsk1r0 - 2.4150195E+6 ) - ( ( ( ( fuciomtlqo + 1900.0 ) - 1.0 ) - 1900.0
) * 365.0 + muDoubleScalarFloor ( ( ( ( fuciomtlqo + 1900.0 ) - 1.0 ) -
1901.0 ) * 0.25 ) ) ; } for ( s207_iter = 0 ; s207_iter < 12 ; s207_iter ++ )
{ lmonth [ s207_iter ] = 31.0 ; if ( s207_iter + 1 == 2 ) { lmonth [
s207_iter ] = 28.0 ; } if ( ( s207_iter + 1 == 4 ) || ( s207_iter + 1 == 6 )
|| ( s207_iter + 1 == 9 ) || ( s207_iter + 1 == 11 ) ) { lmonth [ s207_iter ]
= 30.0 ; } } fuciomtlqo = muDoubleScalarFloor ( days ) ; if (
muDoubleScalarRem ( nhr4ttucgq - 1900.0 , 4.0 ) == 0.0 ) { lmonth [ 1 ] =
29.0 ; } s207_iter = 1 ; inttemp = 0.0 ; while ( ( fuciomtlqo > lmonth [
s207_iter - 1 ] + inttemp ) && ( s207_iter < 12 ) ) { inttemp += lmonth [
s207_iter - 1 ] ; s207_iter ++ ; } temp = ( days - fuciomtlqo ) * 24.0 ; if (
temp < 0.0 ) { days = muDoubleScalarCeil ( temp ) ; } else { days =
muDoubleScalarFloor ( temp ) ; } temp = ( temp - days ) * 60.0 ; if ( temp <
0.0 ) { time_REF_minofhr = muDoubleScalarCeil ( temp ) ; } else {
time_REF_minofhr = muDoubleScalarFloor ( temp ) ; } temp = ( temp -
time_REF_minofhr ) * 60.0 ; rtB . j3bgt3ayxw = nhr4ttucgq ; rtB . dk4mi1twyg
= s207_iter ; rtB . gpytux1hqf = fuciomtlqo - inttemp ; rtB . msop4tmgui =
days ; rtB . kc4lodg3w4 = time_REF_minofhr ; rtB . k14q0a10oi = temp ; rtB .
mrdffjtdaz = fuciomtlqo ; rtB . f103l2lac4 = ( days * 3600.0 +
time_REF_minofhr * 60.0 ) + temp ; rtB . pwktwrqihs [ 0 ] = rtX . hmz1jwrnco
[ 0 ] ; rtB . pwktwrqihs [ 1 ] = rtX . hmz1jwrnco [ 1 ] ; rtB . pwktwrqihs [
2 ] = rtX . hmz1jwrnco [ 2 ] ; rtB . pwktwrqihs [ 3 ] = rtX . hmz1jwrnco [ 3
] ; od5ryzaqzv ( rtB . pwktwrqihs , & rtB . od5ryzaqzvr , rtP .
LIB_ROT_QNORM_zero_tol ) ; nlh1krt5jh ( rtB . od5ryzaqzvr . cmzu1jjbu1 , &
rtB . nlh1krt5jh2 ) ; bq4wkncpnc ( rtB . nlh1krt5jh2 . do5ugpkgof , & rtB .
bq4wkncpnch ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtPrevAction = rtDW .
ou4mxpicy1 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtP
. JulianDateConversion_month <= 2.0 ) ; rtDW . ou4mxpicy1 = rtAction ; } else
{ rtAction = rtDW . ou4mxpicy1 ; } if ( rtPrevAction != rtAction ) { switch (
rtPrevAction ) { case 0 : kzauxcucvk ( rtS ) ; break ; case 1 : eqoa5urut4 (
rtS ) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction !=
rtPrevAction ) { do1ujkzw1j ( rtS ) ; } oasjptnaiz ( rtP .
ECIPositiontoLLA_year , rtP . JulianDateConversion_month , & makjgtdumf , &
ekxkr2veu1 , & rtP . oasjptnaiz4 ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . oasjptnaiz4 . j4omgsrsfr ) ; } break ; case 1 : if (
rtAction != rtPrevAction ) { mk1vmb1o52 ( rtS ) ; } ebq2is5hcr ( rtP .
ECIPositiontoLLA_year , rtP . JulianDateConversion_month , & makjgtdumf , &
ekxkr2veu1 ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ebq2is5hcrm . k2tbsd51jk ) ; } break ; } nhr4ttucgq = muDoubleScalarFloor (
rtP . Gain2_Gain_oajgjiov5c * makjgtdumf ) ; rtB . eylpy53wuw = ( ( (
muDoubleScalarFloor ( ( makjgtdumf + rtP . BiasYear_Bias ) * rtP .
Gain_Gain_abz5gz4hcy ) + muDoubleScalarFloor ( ( ekxkr2veu1 + rtP .
Bias1_Bias ) * rtP . Gain1_Gain_jz0t0f0y5u ) ) + rtP . Bias2_Bias ) -
nhr4ttucgq ) + muDoubleScalarFloor ( rtP . Gain3_Gain * nhr4ttucgq ) ; } rtB
. bk4wge0g1b = ssGetT ( rtS ) ; rtB . mhu3lkxx2s [ 0 ] = rtP . sec2_Value [ 0
] ; rtB . jvjueq3cte [ 0 ] = rtB . mhu3lkxx2s [ 0 ] ; rtB . mhu3lkxx2s [ 1 ]
= rtP . sec2_Value [ 1 ] ; rtB . jvjueq3cte [ 1 ] = rtB . mhu3lkxx2s [ 1 ] ;
rtB . mhu3lkxx2s [ 2 ] = rtP . sec2_Value [ 2 ] ; rtB . jvjueq3cte [ 2 ] =
rtB . mhu3lkxx2s [ 2 ] ; rtB . mhu3lkxx2s [ 3 ] = rtP . sec2_Value [ 3 ] ;
rtB . jvjueq3cte [ 3 ] = rtB . mhu3lkxx2s [ 3 ] ; rtB . jvjueq3cte [ (
int32_T ) rtP . Index_Value - 1 ] = rtB . bk4wge0g1b ; rtB . pmf1oqvthd [ 0 ]
= rtP . JulianDateConversion_day + rtB . jvjueq3cte [ 0 ] ; rtB . pmf1oqvthd
[ 1 ] = rtP . ECIPositiontoLLA_hour + rtB . jvjueq3cte [ 1 ] ; rtB .
pmf1oqvthd [ 2 ] = rtP . ECIPositiontoLLA_min + rtB . jvjueq3cte [ 2 ] ; rtB
. pmf1oqvthd [ 3 ] = rtP . JulianDateConversion_sec + rtB . jvjueq3cte [ 3 ]
; rtB . khkmvj0ylx = rtB . eylpy53wuw + rtB . pmf1oqvthd [ 0 ] ; rtB .
lfsxpbmqdv = rtB . khkmvj0ylx + rtP . BiasDay_Bias ; rtB . huld2q2tsx = rtP .
Gain5_Gain * rtB . pmf1oqvthd [ 2 ] ; rtB . g2sezxeq2k = rtP . Gain6_Gain *
rtB . pmf1oqvthd [ 3 ] ; rtB . gniutc4hwr = ( rtB . pmf1oqvthd [ 1 ] + rtB .
huld2q2tsx ) + rtB . g2sezxeq2k ; rtB . mfnhetnqeo = rtP . Gain4_Gain * rtB .
gniutc4hwr ; rtB . at0dtswx00 = rtB . lfsxpbmqdv + rtB . mfnhetnqeo ; rtB .
dlirszzxgg = rtB . at0dtswx00 + rtB . oodz4urbyp ; rtB . cz2v4vvp2n = rtB .
dlirszzxgg + rtP . Bias1_Bias_afrqardpnr ; rtB . hdu0h34vcb = rtP .
Gain_Gain_bimerhfkin * rtB . cz2v4vvp2n ; rtB . mhpfazun14 = rtP .
Gain_Gain_aimd1pmlgi * rtB . hdu0h34vcb ; rtB . cb3r40lwqu [ 0 ] =
0.017453292519943295 * rtB . mhpfazun14 ; rtB . cb3r40lwqu [ 1 ] = rtB .
edzfllldyc [ 0 ] ; rtB . cb3r40lwqu [ 2 ] = rtB . edzfllldyc [ 1 ] ;
muDoubleScalarSinCos ( rtB . cb3r40lwqu [ 0 ] , & bptigujyyv [ 0 ] , &
nhr4ttucgq ) ; muDoubleScalarSinCos ( rtB . cb3r40lwqu [ 1 ] , & bptigujyyv [
1 ] , & fuciomtlqo ) ; muDoubleScalarSinCos ( rtB . cb3r40lwqu [ 2 ] , &
bptigujyyv [ 2 ] , & inttemp ) ; rtB . dftfd1z0ex [ 0 ] = fuciomtlqo *
nhr4ttucgq ; rtB . dftfd1z0ex [ 1 ] = bptigujyyv [ 2 ] * bptigujyyv [ 1 ] *
nhr4ttucgq - inttemp * bptigujyyv [ 0 ] ; rtB . dftfd1z0ex [ 2 ] = inttemp *
bptigujyyv [ 1 ] * nhr4ttucgq + bptigujyyv [ 2 ] * bptigujyyv [ 0 ] ; rtB .
dftfd1z0ex [ 3 ] = fuciomtlqo * bptigujyyv [ 0 ] ; rtB . dftfd1z0ex [ 4 ] =
bptigujyyv [ 2 ] * bptigujyyv [ 1 ] * bptigujyyv [ 0 ] + inttemp * nhr4ttucgq
; rtB . dftfd1z0ex [ 5 ] = inttemp * bptigujyyv [ 1 ] * bptigujyyv [ 0 ] -
bptigujyyv [ 2 ] * nhr4ttucgq ; rtB . dftfd1z0ex [ 6 ] = - bptigujyyv [ 1 ] ;
rtB . dftfd1z0ex [ 7 ] = bptigujyyv [ 2 ] * fuciomtlqo ; rtB . dftfd1z0ex [ 8
] = inttemp * fuciomtlqo ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtPrevAction = rtDW . arhjxoel23 ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtP . JulianDateConversion_month_hlb3dhxm04 <= 2.0
) ; rtDW . arhjxoel23 = rtAction ; } else { rtAction = rtDW . arhjxoel23 ; }
if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
kzauxcucvk ( rtS ) ; break ; case 1 : eqoa5urut4 ( rtS ) ; break ; } } switch
( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { do1ujkzw1j ( rtS )
; } oasjptnaiz ( rtP . ECIPositiontoLLA_year , rtP .
JulianDateConversion_month_hlb3dhxm04 , & m0ixzcbh2s , & dcum1m1fvs , & rtP .
j2qjlobs3y ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
j2qjlobs3y . j4omgsrsfr ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { mk1vmb1o52 ( rtS ) ; } ebq2is5hcr ( rtP . ECIPositiontoLLA_year , rtP .
JulianDateConversion_month_hlb3dhxm04 , & m0ixzcbh2s , & dcum1m1fvs ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . p4zw5pk3wy . k2tbsd51jk ) ;
} break ; } nhr4ttucgq = muDoubleScalarFloor ( rtP . Gain2_Gain_ego3bowjsc *
m0ixzcbh2s ) ; rtB . fulaf1ayid = ( ( ( muDoubleScalarFloor ( ( m0ixzcbh2s +
rtP . BiasYear_Bias_flvwpd23tq ) * rtP . Gain_Gain_af2qteq0md ) +
muDoubleScalarFloor ( ( dcum1m1fvs + rtP . Bias1_Bias_bqcafx2zzl ) * rtP .
Gain1_Gain_cxzipu4bih ) ) + rtP . Bias2_Bias_hygu35zh3z ) - nhr4ttucgq ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_fa5ervkb4p * nhr4ttucgq ) ; } rtB .
kjvdimqymn [ 0 ] = rtP . sec2_Value_chxskdyj2l [ 0 ] ; rtB . cig0rl2lyw [ 0 ]
= rtB . kjvdimqymn [ 0 ] ; rtB . kjvdimqymn [ 1 ] = rtP .
sec2_Value_chxskdyj2l [ 1 ] ; rtB . cig0rl2lyw [ 1 ] = rtB . kjvdimqymn [ 1 ]
; rtB . kjvdimqymn [ 2 ] = rtP . sec2_Value_chxskdyj2l [ 2 ] ; rtB .
cig0rl2lyw [ 2 ] = rtB . kjvdimqymn [ 2 ] ; rtB . kjvdimqymn [ 3 ] = rtP .
sec2_Value_chxskdyj2l [ 3 ] ; rtB . cig0rl2lyw [ 3 ] = rtB . kjvdimqymn [ 3 ]
; rtB . cig0rl2lyw [ ( int32_T ) rtP . Index_Value_d3cukp2ka0 - 1 ] = rtB .
bk4wge0g1b ; rtB . ddzjlmailu [ 0 ] = rtP .
JulianDateConversion_day_m0mo1gjmhe + rtB . cig0rl2lyw [ 0 ] ; rtB .
ddzjlmailu [ 1 ] = rtP . ECIPositiontoLLA_hour + rtB . cig0rl2lyw [ 1 ] ; rtB
. ddzjlmailu [ 2 ] = rtP . ECIPositiontoLLA_min + rtB . cig0rl2lyw [ 2 ] ;
rtB . ddzjlmailu [ 3 ] = rtP . JulianDateConversion_sec_jtb5mx1osm + rtB .
cig0rl2lyw [ 3 ] ; rtB . pfz3ztc0aa = rtB . fulaf1ayid + rtB . ddzjlmailu [ 0
] ; rtB . cptpe15cmc = rtB . pfz3ztc0aa + rtP . BiasDay_Bias_ka2dudb0f5 ; rtB
. anscqj5wy0 = rtP . Gain5_Gain_po5tiefu4u * rtB . ddzjlmailu [ 2 ] ; rtB .
b3yl3z2rka = rtP . Gain6_Gain_bquoj5efzi * rtB . ddzjlmailu [ 3 ] ; rtB .
oyzvd1f5ao = ( rtB . ddzjlmailu [ 1 ] + rtB . anscqj5wy0 ) + rtB . b3yl3z2rka
; rtB . h0tiwbztwo = rtP . Gain4_Gain_c1bog0ixkx * rtB . oyzvd1f5ao ; rtB .
chb3eqlmms = rtB . cptpe15cmc + rtB . h0tiwbztwo ; rtB . eyb331g3p5 = rtB .
chb3eqlmms + rtB . kvg2t5qrcf ; rtB . pam2p3b0ad = rtB . eyb331g3p5 + rtP .
Bias_Bias ; rtB . bfxopgu15t = muDoubleScalarMod ( rtB . pam2p3b0ad , rtP .
Constant_Value_hp2sqou0mh ) + rtP . Bias1_Bias_hsuhmxu2kn ; rtB . fic4arbej2
= rtP . Gain_Gain_eslt4lguf0 * rtB . pam2p3b0ad ; rtB . d0cdubtpzj = rtB .
bfxopgu15t + rtB . fic4arbej2 ; rtB . gg1oewnt1e = rtP .
Gain1_Gain_lrbrtfzz2g * rtB . d0cdubtpzj ; rtB . m2aqnjsjrj [ 0 ] =
muDoubleScalarMod ( rtB . gg1oewnt1e , rtP . Constant_Value_gal33glcsm ) ;
rtB . m2aqnjsjrj [ 1 ] = rtP . Constant1_Value_gl5rj15yqg [ 0 ] ; rtB .
m2aqnjsjrj [ 2 ] = rtP . Constant1_Value_gl5rj15yqg [ 1 ] ;
muDoubleScalarSinCos ( rtB . m2aqnjsjrj [ 0 ] , & nhr4ttucgq , & bptigujyyv [
0 ] ) ; muDoubleScalarSinCos ( rtB . m2aqnjsjrj [ 1 ] , & fuciomtlqo , &
bptigujyyv [ 1 ] ) ; muDoubleScalarSinCos ( rtB . m2aqnjsjrj [ 2 ] , &
inttemp , & bptigujyyv [ 2 ] ) ; rtB . g1k5nkpeqc [ 0 ] = bptigujyyv [ 1 ] *
bptigujyyv [ 0 ] ; rtB . g1k5nkpeqc [ 1 ] = inttemp * fuciomtlqo * bptigujyyv
[ 0 ] - bptigujyyv [ 2 ] * nhr4ttucgq ; rtB . g1k5nkpeqc [ 2 ] = bptigujyyv [
2 ] * fuciomtlqo * bptigujyyv [ 0 ] + inttemp * nhr4ttucgq ; rtB . g1k5nkpeqc
[ 3 ] = bptigujyyv [ 1 ] * nhr4ttucgq ; rtB . g1k5nkpeqc [ 4 ] = inttemp *
fuciomtlqo * nhr4ttucgq + bptigujyyv [ 2 ] * bptigujyyv [ 0 ] ; rtB .
g1k5nkpeqc [ 5 ] = bptigujyyv [ 2 ] * fuciomtlqo * nhr4ttucgq - inttemp *
bptigujyyv [ 0 ] ; rtB . g1k5nkpeqc [ 6 ] = - fuciomtlqo ; rtB . g1k5nkpeqc [
7 ] = inttemp * bptigujyyv [ 1 ] ; rtB . g1k5nkpeqc [ 8 ] = bptigujyyv [ 2 ]
* bptigujyyv [ 1 ] ; rtB . ggb00pezms = rtP . Y0_Coefs [ 0 ] ; for (
s207_iter = 0 ; s207_iter < 5 ; s207_iter ++ ) { rtB . ggb00pezms = rtB .
ggb00pezms * rtB . hdu0h34vcb + rtP . Y0_Coefs [ s207_iter + 1 ] ; } for ( i
= 0 ; i < 277 ; i ++ ) { rtB . j3qs3rtxbi [ i ] = rtP .
Constant2_Value_gsi2svh5ar [ i ] ; rtB . pw4jsriyp1 [ i ] = rtB . hdu0h34vcb
; } rtB . dnk13ajoih = rtB . hdu0h34vcb * rtB . hdu0h34vcb ; for ( i = 0 ; i
< 30 ; i ++ ) { rtB . kfexapzgyq [ i ] = rtP . Constant3_Value_adwr3klyjx [ i
] ; rtB . juyq5mtkcv [ i ] = rtB . dnk13ajoih ; } rtB . c0u5fnz03z = rtB .
dnk13ajoih * rtB . hdu0h34vcb ; rtB . k25mqcg024 = rtB . c0u5fnz03z * rtB .
hdu0h34vcb ; rtB . mijk0jy3sa = rtP . mMoon_Coefs [ 0 ] ; rtB . hfdypcubls =
rtP . mSun_Coefs [ 0 ] ; rtB . esfcef3azq = rtP . umMoon_Coefs [ 0 ] ; rtB .
mn3s24s3fm = rtP . dSun_Coefs [ 0 ] ; rtB . pshojpczoz = rtP .
omegaMoon_Coefs [ 0 ] ; rtB . mijk0jy3sa = rtB . mijk0jy3sa * rtB .
hdu0h34vcb + rtP . mMoon_Coefs [ 1 ] ; rtB . hfdypcubls = rtB . hfdypcubls *
rtB . hdu0h34vcb + rtP . mSun_Coefs [ 1 ] ; rtB . esfcef3azq = rtB .
esfcef3azq * rtB . hdu0h34vcb + rtP . umMoon_Coefs [ 1 ] ; rtB . mn3s24s3fm =
rtB . mn3s24s3fm * rtB . hdu0h34vcb + rtP . dSun_Coefs [ 1 ] ; rtB .
pshojpczoz = rtB . pshojpczoz * rtB . hdu0h34vcb + rtP . omegaMoon_Coefs [ 1
] ; rtB . mijk0jy3sa = rtB . mijk0jy3sa * rtB . hdu0h34vcb + rtP .
mMoon_Coefs [ 2 ] ; rtB . hfdypcubls = rtB . hfdypcubls * rtB . hdu0h34vcb +
rtP . mSun_Coefs [ 2 ] ; rtB . esfcef3azq = rtB . esfcef3azq * rtB .
hdu0h34vcb + rtP . umMoon_Coefs [ 2 ] ; rtB . mn3s24s3fm = rtB . mn3s24s3fm *
rtB . hdu0h34vcb + rtP . dSun_Coefs [ 2 ] ; rtB . pshojpczoz = rtB .
pshojpczoz * rtB . hdu0h34vcb + rtP . omegaMoon_Coefs [ 2 ] ; rtB .
mijk0jy3sa = rtB . mijk0jy3sa * rtB . hdu0h34vcb + rtP . mMoon_Coefs [ 3 ] ;
rtB . hfdypcubls = rtB . hfdypcubls * rtB . hdu0h34vcb + rtP . mSun_Coefs [ 3
] ; rtB . esfcef3azq = rtB . esfcef3azq * rtB . hdu0h34vcb + rtP .
umMoon_Coefs [ 3 ] ; rtB . mn3s24s3fm = rtB . mn3s24s3fm * rtB . hdu0h34vcb +
rtP . dSun_Coefs [ 3 ] ; rtB . pshojpczoz = rtB . pshojpczoz * rtB .
hdu0h34vcb + rtP . omegaMoon_Coefs [ 3 ] ; rtB . mijk0jy3sa = rtB .
mijk0jy3sa * rtB . hdu0h34vcb + rtP . mMoon_Coefs [ 4 ] ; rtB . hfdypcubls =
rtB . hfdypcubls * rtB . hdu0h34vcb + rtP . mSun_Coefs [ 4 ] ; rtB .
esfcef3azq = rtB . esfcef3azq * rtB . hdu0h34vcb + rtP . umMoon_Coefs [ 4 ] ;
rtB . mn3s24s3fm = rtB . mn3s24s3fm * rtB . hdu0h34vcb + rtP . dSun_Coefs [ 4
] ; rtB . pshojpczoz = rtB . pshojpczoz * rtB . hdu0h34vcb + rtP .
omegaMoon_Coefs [ 4 ] ; rtB . bylf4abebi [ 0 ] = rtP . Gain_Gain_mtidtwrn1n *
rtB . mijk0jy3sa ; rtB . bylf4abebi [ 1 ] = rtP . Gain_Gain_mtidtwrn1n * rtB
. hfdypcubls ; rtB . bylf4abebi [ 2 ] = rtP . Gain_Gain_mtidtwrn1n * rtB .
esfcef3azq ; rtB . bylf4abebi [ 3 ] = rtP . Gain_Gain_mtidtwrn1n * rtB .
mn3s24s3fm ; rtB . bylf4abebi [ 4 ] = rtP . Gain_Gain_mtidtwrn1n * rtB .
pshojpczoz ; rtB . jxbg2l2dpg = rtP . lMercury_Coefs [ 0 ] ; rtB . jxbg2l2dpg
= rtB . jxbg2l2dpg * rtB . hdu0h34vcb + rtP . lMercury_Coefs [ 1 ] ; rtB .
a5zapblmlm = rtP . lVenus_Coefs [ 0 ] ; rtB . a5zapblmlm = rtB . a5zapblmlm *
rtB . hdu0h34vcb + rtP . lVenus_Coefs [ 1 ] ; rtB . ksuihwdjar = rtP .
lEarth_Coefs [ 0 ] ; rtB . ksuihwdjar = rtB . ksuihwdjar * rtB . hdu0h34vcb +
rtP . lEarth_Coefs [ 1 ] ; rtB . chrfbb5slz = rtP . lMars_Coefs [ 0 ] ; rtB .
chrfbb5slz = rtB . chrfbb5slz * rtB . hdu0h34vcb + rtP . lMars_Coefs [ 1 ] ;
rtB . dy53a5i4is = rtP . lJupiter_Coefs [ 0 ] ; rtB . dy53a5i4is = rtB .
dy53a5i4is * rtB . hdu0h34vcb + rtP . lJupiter_Coefs [ 1 ] ; rtB . hgtydaf3wb
= rtP . lSaturn_Coefs [ 0 ] ; rtB . hgtydaf3wb = rtB . hgtydaf3wb * rtB .
hdu0h34vcb + rtP . lSaturn_Coefs [ 1 ] ; rtB . b0ye04xznx = rtP .
lUranus_Coefs [ 0 ] ; rtB . b0ye04xznx = rtB . b0ye04xznx * rtB . hdu0h34vcb
+ rtP . lUranus_Coefs [ 1 ] ; rtB . e1a0f24tac = rtP . lNeptune_Coefs [ 0 ] ;
rtB . e1a0f24tac = rtB . e1a0f24tac * rtB . hdu0h34vcb + rtP . lNeptune_Coefs
[ 1 ] ; rtB . mi0kf0nlq1 = rtP . pa_Coefs [ 0 ] ; rtB . mi0kf0nlq1 = rtB .
mi0kf0nlq1 * rtB . hdu0h34vcb + rtP . pa_Coefs [ 1 ] ; rtB . mi0kf0nlq1 = rtB
. mi0kf0nlq1 * rtB . hdu0h34vcb + rtP . pa_Coefs [ 2 ] ; for ( i = 0 ; i < 5
; i ++ ) { rtB . ojkqeip3ax [ i ] = rtP . Constant4_Value_mfq4qaouzv [ i ] ;
rtB . loucsklpgo [ i ] = rtB . c0u5fnz03z ; rtB . iy3g4iiyx4 [ i ] =
0.017453292519943295 * rtB . bylf4abebi [ i ] ; } rtB . iy3g4iiyx4 [ 5 ] =
rtB . jxbg2l2dpg ; rtB . iy3g4iiyx4 [ 6 ] = rtB . a5zapblmlm ; rtB .
iy3g4iiyx4 [ 7 ] = rtB . ksuihwdjar ; rtB . iy3g4iiyx4 [ 8 ] = rtB .
chrfbb5slz ; rtB . iy3g4iiyx4 [ 9 ] = rtB . dy53a5i4is ; rtB . iy3g4iiyx4 [
10 ] = rtB . hgtydaf3wb ; rtB . iy3g4iiyx4 [ 11 ] = rtB . b0ye04xznx ; rtB .
iy3g4iiyx4 [ 12 ] = rtB . e1a0f24tac ; rtB . iy3g4iiyx4 [ 13 ] = rtB .
mi0kf0nlq1 ; for ( i = 0 ; i < 14 ; i ++ ) { nxh00ek3k5 [ i ] =
muDoubleScalarMod ( rtB . iy3g4iiyx4 [ i ] , rtP . Constant_Value_ffojnsp0xh
) ; } TRANS = 'N' ; M = 1275LL ; N = 14LL ; nhr4ttucgq = 1.0 ; LDA = 1275LL ;
INCX = 1LL ; fuciomtlqo = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , &
nhr4ttucgq , & rtB . bthtxqpdik [ 0 ] , & LDA , & nxh00ek3k5 [ 0 ] , & INCX ,
& fuciomtlqo , & rtB . ocpmool2nu [ 0 ] , & INCY ) ; for ( i = 0 ; i < 962 ;
i ++ ) { rtB . pye21wjxiw [ i ] = rtP . Constant1_Value_b052naa0vc [ i ] *
rtB . ptev4zopsv [ i ] * muDoubleScalarSin ( rtB . ocpmool2nu [ i ] ) ; } for
( i = 0 ; i < 277 ; i ++ ) { rtB . pye21wjxiw [ i + 962 ] = rtB . ptev4zopsv
[ i + 962 ] * rtB . pw4jsriyp1 [ i ] * muDoubleScalarSin ( rtB . ocpmool2nu [
i + 962 ] ) ; } for ( i = 0 ; i < 30 ; i ++ ) { rtB . pye21wjxiw [ i + 1239 ]
= rtB . ptev4zopsv [ i + 1239 ] * rtB . juyq5mtkcv [ i ] * muDoubleScalarSin
( rtB . ocpmool2nu [ i + 1239 ] ) ; } for ( i = 0 ; i < 5 ; i ++ ) { rtB .
pye21wjxiw [ i + 1269 ] = rtB . ptev4zopsv [ i + 1269 ] * rtB . loucsklpgo [
i ] * muDoubleScalarSin ( rtB . ocpmool2nu [ i + 1269 ] ) ; } rtB .
pye21wjxiw [ 1274 ] = rtB . k25mqcg024 * rtB . ptev4zopsv [ 1274 ] *
muDoubleScalarSin ( rtB . ocpmool2nu [ 1274 ] ) ; for ( i = 0 ; i < 962 ; i
++ ) { rtB . mtxqqdefaw [ i ] = muDoubleScalarCos ( rtB . ocpmool2nu [ i ] )
* rtB . cpq0p1komv [ i ] * rtP . Constant1_Value_b052naa0vc [ i ] ; } for ( i
= 0 ; i < 277 ; i ++ ) { rtB . mtxqqdefaw [ i + 962 ] = muDoubleScalarCos (
rtB . ocpmool2nu [ i + 962 ] ) * rtB . cpq0p1komv [ i + 962 ] * rtB .
pw4jsriyp1 [ i ] ; } for ( i = 0 ; i < 30 ; i ++ ) { rtB . mtxqqdefaw [ i +
1239 ] = muDoubleScalarCos ( rtB . ocpmool2nu [ i + 1239 ] ) * rtB .
cpq0p1komv [ i + 1239 ] * rtB . juyq5mtkcv [ i ] ; } for ( i = 0 ; i < 5 ; i
++ ) { rtB . mtxqqdefaw [ i + 1269 ] = muDoubleScalarCos ( rtB . ocpmool2nu [
i + 1269 ] ) * rtB . cpq0p1komv [ i + 1269 ] * rtB . loucsklpgo [ i ] ; } rtB
. mtxqqdefaw [ 1274 ] = muDoubleScalarCos ( rtB . ocpmool2nu [ 1274 ] ) * rtB
. cpq0p1komv [ 1274 ] * rtB . k25mqcg024 ; nhr4ttucgq = - 0.0 ; for ( i = 0 ;
i < 1275 ; i ++ ) { rtB . j3jqtykmpk [ i ] = rtB . pye21wjxiw [ i ] + rtB .
mtxqqdefaw [ i ] ; nhr4ttucgq += rtB . j3jqtykmpk [ i ] ; } rtB . ek4mj4efp0
= nhr4ttucgq ; rtB . dwwgcalsvu = rtB . ggb00pezms + rtB . ek4mj4efp0 ; rtB .
gx5j4ct1re = rtP . Gain4_Gain_jn1efyybdb * rtB . dwwgcalsvu ; rtB .
ci2by4lmgt = 0.017453292519943295 * rtB . gx5j4ct1re ; rtB . cunu5mdzng = rtP
. X0_Coefs [ 0 ] ; for ( s207_iter = 0 ; s207_iter < 5 ; s207_iter ++ ) { rtB
. cunu5mdzng = rtB . cunu5mdzng * rtB . hdu0h34vcb + rtP . X0_Coefs [
s207_iter + 1 ] ; } for ( i = 0 ; i < 253 ; i ++ ) { rtB . dt2yrgmbaw [ i ] =
rtP . Constant2_Value_n3pjai40y1 [ i ] ; rtB . h3ldrmwz0b [ i ] = rtB .
hdu0h34vcb ; } rtB . ojluphtxxy = rtB . hdu0h34vcb * rtB . hdu0h34vcb ; for (
i = 0 ; i < 36 ; i ++ ) { rtB . cddpx32jsg [ i ] = rtP .
Constant3_Value_okgyhbkfgz [ i ] ; rtB . gqd3rauuos [ i ] = rtB . ojluphtxxy
; } rtB . gtyhy2ohqs = rtB . ojluphtxxy * rtB . hdu0h34vcb ; rtB . b0kerzcyjt
[ 0 ] = rtP . Constant4_Value_emg2dxpi3k [ 0 ] ; rtB . j1aaxufdsc [ 0 ] = rtB
. gtyhy2ohqs ; rtB . b0kerzcyjt [ 1 ] = rtP . Constant4_Value_emg2dxpi3k [ 1
] ; rtB . j1aaxufdsc [ 1 ] = rtB . gtyhy2ohqs ; rtB . b0kerzcyjt [ 2 ] = rtP
. Constant4_Value_emg2dxpi3k [ 2 ] ; rtB . j1aaxufdsc [ 2 ] = rtB .
gtyhy2ohqs ; rtB . b0kerzcyjt [ 3 ] = rtP . Constant4_Value_emg2dxpi3k [ 3 ]
; rtB . j1aaxufdsc [ 3 ] = rtB . gtyhy2ohqs ; rtB . anf1qrweu5 = rtB .
gtyhy2ohqs * rtB . hdu0h34vcb ; TRANS = 'N' ; M = 1600LL ; N = 14LL ;
nhr4ttucgq = 1.0 ; LDA = 1600LL ; INCX = 1LL ; fuciomtlqo = 0.0 ; INCY = 1LL
; dgemv ( & TRANS , & M , & N , & nhr4ttucgq , & rtB . nvlun450q4 [ 0 ] , &
LDA , & nxh00ek3k5 [ 0 ] , & INCX , & fuciomtlqo , & rtB . k0nwwxnjlb [ 0 ] ,
& INCY ) ; for ( i = 0 ; i < 1306 ; i ++ ) { rtB . gqcueq3quv [ i ] = rtP .
Constant1_Value_cz2wizjcpi [ i ] * rtB . mbqkewozo3 [ i ] * muDoubleScalarSin
( rtB . k0nwwxnjlb [ i ] ) ; } for ( i = 0 ; i < 253 ; i ++ ) { rtB .
gqcueq3quv [ i + 1306 ] = rtB . mbqkewozo3 [ i + 1306 ] * rtB . h3ldrmwz0b [
i ] * muDoubleScalarSin ( rtB . k0nwwxnjlb [ i + 1306 ] ) ; } for ( i = 0 ; i
< 36 ; i ++ ) { rtB . gqcueq3quv [ i + 1559 ] = rtB . mbqkewozo3 [ i + 1559 ]
* rtB . gqd3rauuos [ i ] * muDoubleScalarSin ( rtB . k0nwwxnjlb [ i + 1559 ]
) ; } rtB . gqcueq3quv [ 1595 ] = rtB . j1aaxufdsc [ 0 ] * rtB . mbqkewozo3 [
1595 ] * muDoubleScalarSin ( rtB . k0nwwxnjlb [ 1595 ] ) ; rtB . gqcueq3quv [
1596 ] = rtB . j1aaxufdsc [ 1 ] * rtB . mbqkewozo3 [ 1596 ] *
muDoubleScalarSin ( rtB . k0nwwxnjlb [ 1596 ] ) ; rtB . gqcueq3quv [ 1597 ] =
rtB . j1aaxufdsc [ 2 ] * rtB . mbqkewozo3 [ 1597 ] * muDoubleScalarSin ( rtB
. k0nwwxnjlb [ 1597 ] ) ; rtB . gqcueq3quv [ 1598 ] = rtB . j1aaxufdsc [ 3 ]
* rtB . mbqkewozo3 [ 1598 ] * muDoubleScalarSin ( rtB . k0nwwxnjlb [ 1598 ] )
; rtB . gqcueq3quv [ 1599 ] = rtB . anf1qrweu5 * rtB . mbqkewozo3 [ 1599 ] *
muDoubleScalarSin ( rtB . k0nwwxnjlb [ 1599 ] ) ; for ( i = 0 ; i < 1306 ; i
++ ) { rtB . kmawkdgie3 [ i ] = muDoubleScalarCos ( rtB . k0nwwxnjlb [ i ] )
* rtB . ily4igf2cj [ i ] * rtP . Constant1_Value_cz2wizjcpi [ i ] ; } for ( i
= 0 ; i < 253 ; i ++ ) { rtB . kmawkdgie3 [ i + 1306 ] = muDoubleScalarCos (
rtB . k0nwwxnjlb [ i + 1306 ] ) * rtB . ily4igf2cj [ i + 1306 ] * rtB .
h3ldrmwz0b [ i ] ; } for ( i = 0 ; i < 36 ; i ++ ) { rtB . kmawkdgie3 [ i +
1559 ] = muDoubleScalarCos ( rtB . k0nwwxnjlb [ i + 1559 ] ) * rtB .
ily4igf2cj [ i + 1559 ] * rtB . gqd3rauuos [ i ] ; } rtB . kmawkdgie3 [ 1595
] = muDoubleScalarCos ( rtB . k0nwwxnjlb [ 1595 ] ) * rtB . ily4igf2cj [ 1595
] * rtB . j1aaxufdsc [ 0 ] ; rtB . kmawkdgie3 [ 1596 ] = muDoubleScalarCos (
rtB . k0nwwxnjlb [ 1596 ] ) * rtB . ily4igf2cj [ 1596 ] * rtB . j1aaxufdsc [
1 ] ; rtB . kmawkdgie3 [ 1597 ] = muDoubleScalarCos ( rtB . k0nwwxnjlb [ 1597
] ) * rtB . ily4igf2cj [ 1597 ] * rtB . j1aaxufdsc [ 2 ] ; rtB . kmawkdgie3 [
1598 ] = muDoubleScalarCos ( rtB . k0nwwxnjlb [ 1598 ] ) * rtB . ily4igf2cj [
1598 ] * rtB . j1aaxufdsc [ 3 ] ; rtB . kmawkdgie3 [ 1599 ] =
muDoubleScalarCos ( rtB . k0nwwxnjlb [ 1599 ] ) * rtB . ily4igf2cj [ 1599 ] *
rtB . anf1qrweu5 ; nhr4ttucgq = - 0.0 ; for ( i = 0 ; i < 1600 ; i ++ ) { rtB
. mjdl5wxrno [ i ] = rtB . gqcueq3quv [ i ] + rtB . kmawkdgie3 [ i ] ;
nhr4ttucgq += rtB . mjdl5wxrno [ i ] ; } rtB . ejeeb2lpaq = nhr4ttucgq ; rtB
. hcyqujov3f = rtB . cunu5mdzng + rtB . ejeeb2lpaq ; rtB . lm1hmpqqev = rtP .
Gain3_Gain_owqano1n1j * rtB . hcyqujov3f ; rtB . ejp4cdox4v =
0.017453292519943295 * rtB . lm1hmpqqev ; inttemp = muDoubleScalarAtan2 ( rtB
. ci2by4lmgt , rtB . ejp4cdox4v ) ; rtB . jcawbpdl3k = rtB . ejp4cdox4v * rtB
. ejp4cdox4v + rtB . ci2by4lmgt * rtB . ci2by4lmgt ; rtB . o2cqohhb5c = rtP .
Constant_Value_bpqcpfxkh2 - rtB . jcawbpdl3k ; rtB . aev5oguouy = rtB .
jcawbpdl3k / rtB . o2cqohhb5c ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW
. lnkokfcmam != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
rtDW . lnkokfcmam = 0 ; } days = muDoubleScalarSqrt ( rtB . aev5oguouy ) ; }
else { if ( rtB . aev5oguouy < 0.0 ) { days = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtB . aev5oguouy ) ) ; } else { days = muDoubleScalarSqrt
( rtB . aev5oguouy ) ; } if ( rtB . aev5oguouy < 0.0 ) { rtDW . lnkokfcmam =
1 ; } } rtB . fmxwlh45zk = rtP . S0_Coefs [ 0 ] ; for ( s207_iter = 0 ;
s207_iter < 5 ; s207_iter ++ ) { rtB . fmxwlh45zk = rtB . fmxwlh45zk * rtB .
hdu0h34vcb + rtP . S0_Coefs [ s207_iter + 1 ] ; } rtB . a3fxqbdoc2 [ 0 ] =
rtP . Constant2_Value [ 0 ] ; rtB . p0yx405sxq [ 0 ] = rtB . hdu0h34vcb ; rtB
. a3fxqbdoc2 [ 1 ] = rtP . Constant2_Value [ 1 ] ; rtB . p0yx405sxq [ 1 ] =
rtB . hdu0h34vcb ; rtB . a3fxqbdoc2 [ 2 ] = rtP . Constant2_Value [ 2 ] ; rtB
. p0yx405sxq [ 2 ] = rtB . hdu0h34vcb ; rtB . ivwsn315e4 = rtB . hdu0h34vcb *
rtB . hdu0h34vcb ; for ( i = 0 ; i < 25 ; i ++ ) { rtB . d1fpbrwfhb [ i ] =
rtP . Constant3_Value [ i ] ; rtB . nieusgoeqj [ i ] = rtB . ivwsn315e4 ; }
rtB . k124dm0xlv = rtB . ivwsn315e4 * rtB . hdu0h34vcb ; rtB . kz2hijpe2h [ 0
] = rtP . Constant4_Value [ 0 ] ; rtB . cktaicpds5 [ 0 ] = rtB . k124dm0xlv ;
rtB . kz2hijpe2h [ 1 ] = rtP . Constant4_Value [ 1 ] ; rtB . cktaicpds5 [ 1 ]
= rtB . k124dm0xlv ; rtB . kz2hijpe2h [ 2 ] = rtP . Constant4_Value [ 2 ] ;
rtB . cktaicpds5 [ 2 ] = rtB . k124dm0xlv ; rtB . kz2hijpe2h [ 3 ] = rtP .
Constant4_Value [ 3 ] ; rtB . cktaicpds5 [ 3 ] = rtB . k124dm0xlv ; rtB .
bj3em3wxmz = rtB . k124dm0xlv * rtB . hdu0h34vcb ; for ( i = 0 ; i < 5 ; i ++
) { rtB . b3nffv5x1e [ i ] = nxh00ek3k5 [ i ] ; } rtB . b3nffv5x1e [ 5 ] =
nxh00ek3k5 [ 6 ] ; rtB . b3nffv5x1e [ 6 ] = nxh00ek3k5 [ 7 ] ; rtB .
b3nffv5x1e [ 7 ] = nxh00ek3k5 [ 13 ] ; TRANS = 'N' ; M = 66LL ; N = 8LL ;
nhr4ttucgq = 1.0 ; LDA = 66LL ; INCX = 1LL ; fuciomtlqo = 0.0 ; INCY = 1LL ;
dgemv ( & TRANS , & M , & N , & nhr4ttucgq , & rtB . g3a150ehbv [ 0 ] , & LDA
, & rtB . b3nffv5x1e [ 0 ] , & INCX , & fuciomtlqo , & rtB . ft0uwvnwf5 [ 0 ]
, & INCY ) ; for ( i = 0 ; i < 33 ; i ++ ) { rtB . jfqolzrdei [ i ] = rtP .
Constant1_Value_hgicfsjrdx [ i ] * rtB . fzxfo4voq2 [ i ] * muDoubleScalarSin
( rtB . ft0uwvnwf5 [ i ] ) ; } rtB . jfqolzrdei [ 33 ] = rtB . p0yx405sxq [ 0
] * rtB . fzxfo4voq2 [ 33 ] * muDoubleScalarSin ( rtB . ft0uwvnwf5 [ 33 ] ) ;
rtB . jfqolzrdei [ 34 ] = rtB . p0yx405sxq [ 1 ] * rtB . fzxfo4voq2 [ 34 ] *
muDoubleScalarSin ( rtB . ft0uwvnwf5 [ 34 ] ) ; rtB . jfqolzrdei [ 35 ] = rtB
. p0yx405sxq [ 2 ] * rtB . fzxfo4voq2 [ 35 ] * muDoubleScalarSin ( rtB .
ft0uwvnwf5 [ 35 ] ) ; for ( i = 0 ; i < 25 ; i ++ ) { rtB . jfqolzrdei [ i +
36 ] = rtB . fzxfo4voq2 [ i + 36 ] * rtB . nieusgoeqj [ i ] *
muDoubleScalarSin ( rtB . ft0uwvnwf5 [ i + 36 ] ) ; } rtB . jfqolzrdei [ 61 ]
= rtB . cktaicpds5 [ 0 ] * rtB . fzxfo4voq2 [ 61 ] * muDoubleScalarSin ( rtB
. ft0uwvnwf5 [ 61 ] ) ; rtB . jfqolzrdei [ 62 ] = rtB . cktaicpds5 [ 1 ] *
rtB . fzxfo4voq2 [ 62 ] * muDoubleScalarSin ( rtB . ft0uwvnwf5 [ 62 ] ) ; rtB
. jfqolzrdei [ 63 ] = rtB . cktaicpds5 [ 2 ] * rtB . fzxfo4voq2 [ 63 ] *
muDoubleScalarSin ( rtB . ft0uwvnwf5 [ 63 ] ) ; rtB . jfqolzrdei [ 64 ] = rtB
. cktaicpds5 [ 3 ] * rtB . fzxfo4voq2 [ 64 ] * muDoubleScalarSin ( rtB .
ft0uwvnwf5 [ 64 ] ) ; rtB . jfqolzrdei [ 65 ] = rtB . bj3em3wxmz * rtB .
fzxfo4voq2 [ 65 ] * muDoubleScalarSin ( rtB . ft0uwvnwf5 [ 65 ] ) ; for ( i =
0 ; i < 33 ; i ++ ) { rtB . ohi0wofqpa [ i ] = muDoubleScalarCos ( rtB .
ft0uwvnwf5 [ i ] ) * rtB . gh1fvty1e2 [ i ] * rtP .
Constant1_Value_hgicfsjrdx [ i ] ; } rtB . ohi0wofqpa [ 33 ] =
muDoubleScalarCos ( rtB . ft0uwvnwf5 [ 33 ] ) * rtB . gh1fvty1e2 [ 33 ] * rtB
. p0yx405sxq [ 0 ] ; rtB . ohi0wofqpa [ 34 ] = muDoubleScalarCos ( rtB .
ft0uwvnwf5 [ 34 ] ) * rtB . gh1fvty1e2 [ 34 ] * rtB . p0yx405sxq [ 1 ] ; rtB
. ohi0wofqpa [ 35 ] = muDoubleScalarCos ( rtB . ft0uwvnwf5 [ 35 ] ) * rtB .
gh1fvty1e2 [ 35 ] * rtB . p0yx405sxq [ 2 ] ; for ( i = 0 ; i < 25 ; i ++ ) {
rtB . ohi0wofqpa [ i + 36 ] = muDoubleScalarCos ( rtB . ft0uwvnwf5 [ i + 36 ]
) * rtB . gh1fvty1e2 [ i + 36 ] * rtB . nieusgoeqj [ i ] ; } rtB . ohi0wofqpa
[ 61 ] = muDoubleScalarCos ( rtB . ft0uwvnwf5 [ 61 ] ) * rtB . gh1fvty1e2 [
61 ] * rtB . cktaicpds5 [ 0 ] ; rtB . ohi0wofqpa [ 62 ] = muDoubleScalarCos (
rtB . ft0uwvnwf5 [ 62 ] ) * rtB . gh1fvty1e2 [ 62 ] * rtB . cktaicpds5 [ 1 ]
; rtB . ohi0wofqpa [ 63 ] = muDoubleScalarCos ( rtB . ft0uwvnwf5 [ 63 ] ) *
rtB . gh1fvty1e2 [ 63 ] * rtB . cktaicpds5 [ 2 ] ; rtB . ohi0wofqpa [ 64 ] =
muDoubleScalarCos ( rtB . ft0uwvnwf5 [ 64 ] ) * rtB . gh1fvty1e2 [ 64 ] * rtB
. cktaicpds5 [ 3 ] ; rtB . ohi0wofqpa [ 65 ] = muDoubleScalarCos ( rtB .
ft0uwvnwf5 [ 65 ] ) * rtB . gh1fvty1e2 [ 65 ] * rtB . bj3em3wxmz ; nhr4ttucgq
= - 0.0 ; for ( i = 0 ; i < 66 ; i ++ ) { rtB . idkgjvvbkw [ i ] = rtB .
jfqolzrdei [ i ] + rtB . ohi0wofqpa [ i ] ; nhr4ttucgq += rtB . idkgjvvbkw [
i ] ; } rtB . dnqnvk3id0 = nhr4ttucgq ; rtB . kku0y3djhe = rtB . fmxwlh45zk +
rtB . dnqnvk3id0 ; rtB . b4xys0hny1 = rtP . Gain2_Gain_hfcaz1phbz * rtB .
kku0y3djhe ; rtB . pnplagmggb = rtB . ci2by4lmgt * rtB . ejp4cdox4v ; rtB .
blpvfajcob = rtP . Gain5_Gain_fsuar2mnaj * rtB . pnplagmggb ; rtB .
jmeheyx5wd = 0.017453292519943295 * rtB . b4xys0hny1 - rtB . blpvfajcob ; rtB
. dk4w0dsybe = rtB . jmeheyx5wd + inttemp ; rtB . lmx1lmqzrw = rtP .
Gain1_Gain_k5feilsibt * rtB . dk4w0dsybe ; rtB . cprds4vjro [ 0 ] = inttemp ;
rtB . cprds4vjro [ 1 ] = muDoubleScalarAtan ( days ) ; rtB . cprds4vjro [ 2 ]
= rtB . lmx1lmqzrw ; muDoubleScalarSinCos ( rtB . cprds4vjro [ 0 ] , &
nhr4ttucgq , & bptigujyyv [ 0 ] ) ; muDoubleScalarSinCos ( rtB . cprds4vjro [
1 ] , & fuciomtlqo , & bptigujyyv [ 1 ] ) ; muDoubleScalarSinCos ( rtB .
cprds4vjro [ 2 ] , & inttemp , & bptigujyyv [ 2 ] ) ; rtB . jcwg21yjxx [ 0 ]
= bptigujyyv [ 0 ] * bptigujyyv [ 2 ] * bptigujyyv [ 1 ] - nhr4ttucgq *
inttemp ; rtB . jcwg21yjxx [ 1 ] = - bptigujyyv [ 0 ] * bptigujyyv [ 1 ] *
inttemp - nhr4ttucgq * bptigujyyv [ 2 ] ; rtB . jcwg21yjxx [ 2 ] = bptigujyyv
[ 0 ] * fuciomtlqo ; rtB . jcwg21yjxx [ 3 ] = nhr4ttucgq * bptigujyyv [ 2 ] *
bptigujyyv [ 1 ] + bptigujyyv [ 0 ] * inttemp ; rtB . jcwg21yjxx [ 4 ] = -
nhr4ttucgq * bptigujyyv [ 1 ] * inttemp + bptigujyyv [ 0 ] * bptigujyyv [ 2 ]
; rtB . jcwg21yjxx [ 5 ] = nhr4ttucgq * fuciomtlqo ; rtB . jcwg21yjxx [ 6 ] =
- fuciomtlqo * bptigujyyv [ 2 ] ; rtB . jcwg21yjxx [ 7 ] = fuciomtlqo *
inttemp ; rtB . jcwg21yjxx [ 8 ] = bptigujyyv [ 1 ] ; for ( s207_iter = 0 ;
s207_iter < 3 ; s207_iter ++ ) { for ( s256_iter = 0 ; s256_iter < 3 ;
s256_iter ++ ) { eldb3aqjyd [ s256_iter + 3 * s207_iter ] = 0.0 ; eldb3aqjyd
[ s256_iter + 3 * s207_iter ] += rtB . jcwg21yjxx [ 3 * s207_iter ] * rtB .
g1k5nkpeqc [ s256_iter ] ; eldb3aqjyd [ s256_iter + 3 * s207_iter ] += rtB .
jcwg21yjxx [ 3 * s207_iter + 1 ] * rtB . g1k5nkpeqc [ s256_iter + 3 ] ;
eldb3aqjyd [ s256_iter + 3 * s207_iter ] += rtB . jcwg21yjxx [ 3 * s207_iter
+ 2 ] * rtB . g1k5nkpeqc [ s256_iter + 6 ] ; } } for ( i = 0 ; i < 3 ; i ++ )
{ for ( s207_iter = 0 ; s207_iter < 3 ; s207_iter ++ ) { rtB . l1qtdzo5qs [ i
+ 3 * s207_iter ] = 0.0 ; rtB . l1qtdzo5qs [ i + 3 * s207_iter ] +=
eldb3aqjyd [ 3 * s207_iter ] * rtB . dftfd1z0ex [ i ] ; rtB . l1qtdzo5qs [ i
+ 3 * s207_iter ] += eldb3aqjyd [ 3 * s207_iter + 1 ] * rtB . dftfd1z0ex [ i
+ 3 ] ; rtB . l1qtdzo5qs [ i + 3 * s207_iter ] += eldb3aqjyd [ 3 * s207_iter
+ 2 ] * rtB . dftfd1z0ex [ i + 6 ] ; } rtB . hzfvnqhqh4 [ i ] = rtX .
oxda0i4vgt [ i ] ; } for ( s207_iter = 0 ; s207_iter < 3 ; s207_iter ++ ) {
rtB . kahiazkhjq [ s207_iter ] = 0.0 ; rtB . kahiazkhjq [ s207_iter ] += rtB
. l1qtdzo5qs [ s207_iter ] * rtB . hzfvnqhqh4 [ 0 ] ; rtB . kahiazkhjq [
s207_iter ] += rtB . l1qtdzo5qs [ s207_iter + 3 ] * rtB . hzfvnqhqh4 [ 1 ] ;
rtB . kahiazkhjq [ s207_iter ] += rtB . l1qtdzo5qs [ s207_iter + 6 ] * rtB .
hzfvnqhqh4 [ 2 ] ; } rtB . alojqq4waj = rtB . kahiazkhjq [ 0 ] * rtB .
kahiazkhjq [ 0 ] ; rtB . dq4ghxvamu = rtB . kahiazkhjq [ 1 ] * rtB .
kahiazkhjq [ 1 ] ; rtB . iv1obja41p = rtB . alojqq4waj + rtB . dq4ghxvamu ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . nbibucftep != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . nbibucftep = 0 ;
} rtB . bgphx4r2ap = muDoubleScalarSqrt ( rtB . iv1obja41p ) ; } else { if (
rtB . iv1obja41p < 0.0 ) { rtB . bgphx4r2ap = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtB . iv1obja41p ) ) ; } else { rtB . bgphx4r2ap =
muDoubleScalarSqrt ( rtB . iv1obja41p ) ; } if ( rtB . iv1obja41p < 0.0 ) {
rtDW . nbibucftep = 1 ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { mlcpngipio
( rtB . bgphx4r2ap , rtB . kahiazkhjq [ 2 ] , rtB . hakectrr15 , rtB .
nifycbgi5p , rtB . loketsez3q , rtB . mmsgyz3vfm , & rtB . mlcpngipio4 , &
rtDW . mlcpngipio4 , & rtP . mlcpngipio4 ) ; } days = 57.295779513082323 *
rtB . mlcpngipio4 . pmiuvoq3bk ; temp = 57.295779513082323 *
muDoubleScalarAtan2 ( rtB . kahiazkhjq [ 1 ] , rtB . kahiazkhjq [ 0 ] ) ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { muDoubleScalarSinCos ( rtB . mlcpngipio4
. pmiuvoq3bk , & rtB . mkutzgjcja , & rtB . kj4a4skaqt ) ; nhr4ttucgq = rtB .
mkutzgjcja * rtB . loketsez3q ; fuciomtlqo = rtP . f_Value - nhr4ttucgq * rtB
. mkutzgjcja ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . o4nqlaod2d != 0
) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . o4nqlaod2d =
0 ; } inttemp = muDoubleScalarSqrt ( fuciomtlqo ) ; } else if ( fuciomtlqo <
0.0 ) { inttemp = - muDoubleScalarSqrt ( muDoubleScalarAbs ( fuciomtlqo ) ) ;
rtDW . o4nqlaod2d = 1 ; } else { inttemp = muDoubleScalarSqrt ( fuciomtlqo )
; } rtB . bgmsguohbo = rtP . Constant1_Value_omeg2wr434 / inttemp ; rtB .
ogdbiskhax = nhr4ttucgq * rtB . bgmsguohbo ; } rtB . lplpcks1xr = rtB .
kahiazkhjq [ 2 ] + rtB . ogdbiskhax ; rtB . hlblpeadwl = rtB . mkutzgjcja *
rtB . lplpcks1xr ; rtB . haub2ujqzk = rtB . kj4a4skaqt * rtB . bgphx4r2ap ;
rtB . a34kq0qnht = ( rtB . hlblpeadwl - rtB . bgmsguohbo ) + rtB . haub2ujqzk
; rtB . na202onqkw [ 0 ] = days ; rtB . na202onqkw [ 1 ] = temp ; rtB .
na202onqkw [ 2 ] = rtB . a34kq0qnht ; rtB . fvzcriyu2k = rtB . na202onqkw [ 0
] ; rtB . azz1yrsj30 = rtB . na202onqkw [ 1 ] ; rtB . b55xgieqba = rtB .
na202onqkw [ 2 ] ; j0houlamnx = 0.001 * rtB . b55xgieqba ; { struct
nrlmsise_flags flags ; int_T i ; real_T absPhi , absLambda , lst ; boolean_T
phi_wrapped = false ; real_T * phi = ( real_T * ) & rtDW . aic2hlfea0 ;
real_T * h = ( real_T * ) & rtDW . g55xueop5g ; real_T * lambda = ( real_T *
) & rtDW . esy5tsm3ee ; real_T * ap = ( real_T * ) & rtDW . myivyj5gij ;
int_T * doy_int = ( int_T * ) & rtDW . puckbncoc1 ; real_T * T = ( real_T * )
& rtB . dqm0kbpewz [ 0 ] ; real_T * rho = ( real_T * ) & rtB . otj1lt2fyb [ 0
] ; real_T * heightInput = ( real_T * ) & j0houlamnx ; real_T * phiInput = (
real_T * ) & rtB . fvzcriyu2k ; real_T * lambdaInput = ( real_T * ) & rtB .
azz1yrsj30 ; real_T * flagsInput = ( real_T * ) & rtP .
NRLMSISE00AtmosphereModel_flags [ 0 ] ; int_T lstFlag = ( int_T ) 0.0 ; const
real_T * doy = ( const real_T * ) & rtB . mrdffjtdaz ; const real_T * sec = (
const real_T * ) & rtB . f4wdtbi41r ; const real_T * lstPort = ( const real_T
* ) & rtP . lst_Value ; const real_T * f107 = ( const real_T * ) & rtP .
f107a_Value ; const real_T * f107a = ( const real_T * ) & rtP . f107_Value ;
const real_T * aph = ( const real_T * ) & rtP . aph_Value [ 0 ] ; phi [ 0 ] =
phiInput [ 0 ] ; lambda [ 0 ] = lambdaInput [ 0 ] ; h [ 0 ] = heightInput [ 0
] ; doy_int [ 0 ] = ( int_T ) doy [ 0 ] ; ap [ 0 ] = aph [ 0 ] ; if ( phi [ 0
] > 180 || phi [ 0 ] < - 180 ) { phi [ 0 ] = muDoubleScalarRem ( phi [ 0 ] +
180 , 360 ) - 180 ; } absPhi = muDoubleScalarAbs ( phi [ 0 ] ) ; if ( absPhi
> 90.0 ) { real_T sign = phi [ 0 ] / absPhi ; phi_wrapped = true ; phi [ 0 ]
= sign * ( 90 - ( absPhi - 90 ) ) ; } absLambda = muDoubleScalarAbs ( lambda
[ 0 ] ) ; if ( phi_wrapped ) { lambda [ 0 ] = lambda [ 0 ] + 180 ; } if (
absLambda > 180.0 ) { real_T sign = lambda [ 0 ] / absLambda ; lambda [ 0 ] =
( ( absLambda - 180 ) - 180 ) * sign ; } if ( lstFlag == 1 ) { lst = lstPort
[ 0 ] ; } else { lst = sec [ 0 ] / 3600.0 + lambda [ 0 ] / 15.0 ; } flags .
switches [ 0 ] = 1 ; for ( i = 1 ; i < 24 ; i ++ ) { flags . switches [ i ] =
( int ) flagsInput [ i - 1 ] ; } gtd7 ( ( const int_T * ) doy_int , sec , h ,
phi , lambda , ( const real_T * ) & lst , f107a , f107 , ap , aph , 1 , & (
flags . switches [ 0 ] ) , & ( flags . sw [ 0 ] ) , & ( flags . swc [ 0 ] ) ,
rho , T ) ; if ( rtP . NRLMSISE00AtmosphereModel_oxygen_in ) { rho [ 5 ] =
1.66E-27 * ( 16.0 * rho [ 8 ] ) + rho [ 5 ] ; } } for ( i = 0 ; i < 8 ; i ++
) { rtB . kmoplxzlxz [ i ] = rtB . otj1lt2fyb [ tmp_e [ i ] ] ; } for ( i = 0
; i < 6 ; i ++ ) { rtB . mfk4darvmz [ i ] = rtB . kmoplxzlxz [ i ] ; } rtB .
mfk4darvmz [ 6 ] = rtB . otj1lt2fyb [ 6 ] ; rtB . mfk4darvmz [ 7 ] = rtB .
kmoplxzlxz [ 6 ] ; rtB . mfk4darvmz [ 8 ] = rtB . kmoplxzlxz [ 7 ] ; rtB .
g1i4pov3fb [ 0 ] = rtX . mxzg4wj1qp [ 0 ] ; rtB . g1i4pov3fb [ 1 ] = rtX .
mxzg4wj1qp [ 1 ] ; rtB . g1i4pov3fb [ 2 ] = rtX . mxzg4wj1qp [ 2 ] ;
nhr4ttucgq = muDoubleScalarSqrt ( ( rtB . g1i4pov3fb [ 0 ] * rtB . g1i4pov3fb
[ 0 ] + rtB . g1i4pov3fb [ 1 ] * rtB . g1i4pov3fb [ 1 ] ) + rtB . g1i4pov3fb
[ 2 ] * rtB . g1i4pov3fb [ 2 ] ) ; rtB . oohaox0ofe = nhr4ttucgq * nhr4ttucgq
* rtB . mfk4darvmz [ 5 ] ; rtB . pyqk4ufp53 = rtP . Gain_Gain_hdhhylvzeo *
rtB . oohaox0ofe ; rtB . ggvanenkks = rtP . AerodynamicForcesandMoments_S *
rtB . pyqk4ufp53 ; rtB . esq14j0ci4 [ 0 ] = rtB . ggvanenkks * rtB .
itxjzsphm3 [ 0 ] ; rtB . esq14j0ci4 [ 1 ] = rtB . ggvanenkks * rtB .
itxjzsphm3 [ 1 ] ; rtB . esq14j0ci4 [ 2 ] = rtB . ggvanenkks * rtB .
itxjzsphm3 [ 2 ] ; elrubs4mtp ( rtB . bq4wkncpnch . nm24payncx , rtB .
esq14j0ci4 , & rtB . meldjycwis ) ; rtB . dlf3gf11iq [ 0 ] = 1.0 / rtP .
DYN_SC_par . mass * rtB . meldjycwis . ehs4r2hz2y [ 0 ] ; rtB . dlf3gf11iq [
1 ] = 1.0 / rtP . DYN_SC_par . mass * rtB . meldjycwis . ehs4r2hz2y [ 1 ] ;
rtB . dlf3gf11iq [ 2 ] = 1.0 / rtP . DYN_SC_par . mass * rtB . meldjycwis .
ehs4r2hz2y [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtPrevAction = rtDW
. dbsyarjlzj ; if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! (
rtP . JulianDateConversion_month_cojprbcmrr <= 2.0 ) ; rtDW . dbsyarjlzj =
rtAction ; } else { rtAction = rtDW . dbsyarjlzj ; } if ( rtPrevAction !=
rtAction ) { switch ( rtPrevAction ) { case 0 : kzauxcucvk ( rtS ) ; break ;
case 1 : eqoa5urut4 ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if (
rtAction != rtPrevAction ) { do1ujkzw1j ( rtS ) ; } oasjptnaiz ( rtP .
DirectionCosineMatrixECItoECEF_year , rtP .
JulianDateConversion_month_cojprbcmrr , & ezrnwi3ppv , & cdtst4eq4s , & rtP .
kfz4qm0ehh ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
kfz4qm0ehh . j4omgsrsfr ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { mk1vmb1o52 ( rtS ) ; } ebq2is5hcr ( rtP .
DirectionCosineMatrixECItoECEF_year , rtP .
JulianDateConversion_month_cojprbcmrr , & ezrnwi3ppv , & cdtst4eq4s ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . hvkk5ldfab . k2tbsd51jk ) ;
} break ; } nhr4ttucgq = muDoubleScalarFloor ( rtP . Gain2_Gain_bz2f2drozo *
ezrnwi3ppv ) ; rtB . h20r5jewxu = ( ( ( muDoubleScalarFloor ( ( ezrnwi3ppv +
rtP . BiasYear_Bias_n4w3ry1u0i ) * rtP . Gain_Gain_hiumlrr1tu ) +
muDoubleScalarFloor ( ( cdtst4eq4s + rtP . Bias1_Bias_k25uehi4dt ) * rtP .
Gain1_Gain_hi1zqgx4wm ) ) + rtP . Bias2_Bias_fh1a5p4eyh ) - nhr4ttucgq ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_ocwqkavwvj * nhr4ttucgq ) ; } rtB .
fib5r0ervc [ 0 ] = rtP . sec2_Value_itv23ykpn0 [ 0 ] ; rtB . eu1nemp2kx [ 0 ]
= rtB . fib5r0ervc [ 0 ] ; rtB . fib5r0ervc [ 1 ] = rtP .
sec2_Value_itv23ykpn0 [ 1 ] ; rtB . eu1nemp2kx [ 1 ] = rtB . fib5r0ervc [ 1 ]
; rtB . fib5r0ervc [ 2 ] = rtP . sec2_Value_itv23ykpn0 [ 2 ] ; rtB .
eu1nemp2kx [ 2 ] = rtB . fib5r0ervc [ 2 ] ; rtB . fib5r0ervc [ 3 ] = rtP .
sec2_Value_itv23ykpn0 [ 3 ] ; rtB . eu1nemp2kx [ 3 ] = rtB . fib5r0ervc [ 3 ]
; rtB . eu1nemp2kx [ ( int32_T ) rtP . Index_Value_mnrgh2annx - 1 ] = rtB .
f4wdtbi41r ; rtB . il51pe3lbo [ 0 ] = rtP .
JulianDateConversion_day_e45v40wquc + rtB . eu1nemp2kx [ 0 ] ; rtB .
il51pe3lbo [ 1 ] = rtP . DirectionCosineMatrixECItoECEF_hour + rtB .
eu1nemp2kx [ 1 ] ; rtB . il51pe3lbo [ 2 ] = rtP .
DirectionCosineMatrixECItoECEF_min + rtB . eu1nemp2kx [ 2 ] ; rtB .
il51pe3lbo [ 3 ] = rtP . JulianDateConversion_sec_ognsdwmsdd + rtB .
eu1nemp2kx [ 3 ] ; rtB . psddpbcsbo = rtB . h20r5jewxu + rtB . il51pe3lbo [ 0
] ; rtB . c3fw2cjyqe = rtB . psddpbcsbo + rtP . BiasDay_Bias_h4d4xzeixu ; rtB
. dfsexdekjn = rtP . Gain5_Gain_cw0at02a10 * rtB . il51pe3lbo [ 2 ] ; rtB .
edm2r4bopy = rtP . Gain6_Gain_asg4eux1fd * rtB . il51pe3lbo [ 3 ] ; rtB .
ihmxg05jq2 = ( rtB . il51pe3lbo [ 1 ] + rtB . dfsexdekjn ) + rtB . edm2r4bopy
; rtB . d14sd1spcd = rtP . Gain4_Gain_cgs3mxx1hh * rtB . ihmxg05jq2 ; rtB .
pj1tyqws1q = rtB . c3fw2cjyqe + rtB . d14sd1spcd ; rtB . jo1znsl5t1 = rtB .
pj1tyqws1q + rtB . lchtvpgg01 ; rtB . bhrxinv1w4 = rtB . jo1znsl5t1 + rtP .
Bias1_Bias_nrxfej55lg ; rtB . dm2o2p1lc4 = rtP . Gain_Gain_ftqmvwc1lk * rtB .
bhrxinv1w4 ; rtB . lemqdujdtt = rtP . Gain_Gain_ek2ohtwn1h * rtB . dm2o2p1lc4
; rtB . dghprq20g3 [ 0 ] = 0.017453292519943295 * rtB . lemqdujdtt ; rtB .
dghprq20g3 [ 1 ] = rtB . dal2neiedt [ 0 ] ; rtB . dghprq20g3 [ 2 ] = rtB .
dal2neiedt [ 1 ] ; muDoubleScalarSinCos ( rtB . dghprq20g3 [ 0 ] , &
nhr4ttucgq , & bptigujyyv [ 0 ] ) ; muDoubleScalarSinCos ( rtB . dghprq20g3 [
1 ] , & fuciomtlqo , & bptigujyyv [ 1 ] ) ; muDoubleScalarSinCos ( rtB .
dghprq20g3 [ 2 ] , & inttemp , & bptigujyyv [ 2 ] ) ; rtB . fjiyyvaugo [ 0 ]
= bptigujyyv [ 1 ] * bptigujyyv [ 0 ] ; rtB . fjiyyvaugo [ 1 ] = inttemp *
fuciomtlqo * bptigujyyv [ 0 ] - bptigujyyv [ 2 ] * nhr4ttucgq ; rtB .
fjiyyvaugo [ 2 ] = bptigujyyv [ 2 ] * fuciomtlqo * bptigujyyv [ 0 ] + inttemp
* nhr4ttucgq ; rtB . fjiyyvaugo [ 3 ] = bptigujyyv [ 1 ] * nhr4ttucgq ; rtB .
fjiyyvaugo [ 4 ] = inttemp * fuciomtlqo * nhr4ttucgq + bptigujyyv [ 2 ] *
bptigujyyv [ 0 ] ; rtB . fjiyyvaugo [ 5 ] = bptigujyyv [ 2 ] * fuciomtlqo *
nhr4ttucgq - inttemp * bptigujyyv [ 0 ] ; rtB . fjiyyvaugo [ 6 ] = -
fuciomtlqo ; rtB . fjiyyvaugo [ 7 ] = inttemp * bptigujyyv [ 1 ] ; rtB .
fjiyyvaugo [ 8 ] = bptigujyyv [ 2 ] * bptigujyyv [ 1 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtPrevAction = rtDW . pdbx5fzllt ; if ( ssIsMajorTimeStep (
rtS ) ) { rtAction = ( int8_T ) ! ( rtP .
JulianDateConversion_month_ddckzl0a5p <= 2.0 ) ; rtDW . pdbx5fzllt = rtAction
; } else { rtAction = rtDW . pdbx5fzllt ; } if ( rtPrevAction != rtAction ) {
switch ( rtPrevAction ) { case 0 : kzauxcucvk ( rtS ) ; break ; case 1 :
eqoa5urut4 ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction
!= rtPrevAction ) { do1ujkzw1j ( rtS ) ; } oasjptnaiz ( rtP .
DirectionCosineMatrixECItoECEF_year , rtP .
JulianDateConversion_month_ddckzl0a5p , & lzg3jkvf1b , & ch3ah2ivhg , & rtP .
njjq1lvqsq ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
njjq1lvqsq . j4omgsrsfr ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { mk1vmb1o52 ( rtS ) ; } ebq2is5hcr ( rtP .
DirectionCosineMatrixECItoECEF_year , rtP .
JulianDateConversion_month_ddckzl0a5p , & lzg3jkvf1b , & ch3ah2ivhg ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . bxw5fabqqg . k2tbsd51jk ) ;
} break ; } nhr4ttucgq = muDoubleScalarFloor ( rtP . Gain2_Gain_cfgj3jd2t1 *
lzg3jkvf1b ) ; rtB . ifwzxts3py = ( ( ( muDoubleScalarFloor ( ( lzg3jkvf1b +
rtP . BiasYear_Bias_dq4wgw0ext ) * rtP . Gain_Gain_pz3cjiymq0 ) +
muDoubleScalarFloor ( ( ch3ah2ivhg + rtP . Bias1_Bias_asv15o3c1b ) * rtP .
Gain1_Gain_nlkud5skgo ) ) + rtP . Bias2_Bias_govedqbcfa ) - nhr4ttucgq ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_c4zdbsr3gi * nhr4ttucgq ) ; } rtB .
izmkrq2px5 [ 0 ] = rtP . sec2_Value_euqqqma0wu [ 0 ] ; rtB . meg2w5bizp [ 0 ]
= rtB . izmkrq2px5 [ 0 ] ; rtB . izmkrq2px5 [ 1 ] = rtP .
sec2_Value_euqqqma0wu [ 1 ] ; rtB . meg2w5bizp [ 1 ] = rtB . izmkrq2px5 [ 1 ]
; rtB . izmkrq2px5 [ 2 ] = rtP . sec2_Value_euqqqma0wu [ 2 ] ; rtB .
meg2w5bizp [ 2 ] = rtB . izmkrq2px5 [ 2 ] ; rtB . izmkrq2px5 [ 3 ] = rtP .
sec2_Value_euqqqma0wu [ 3 ] ; rtB . meg2w5bizp [ 3 ] = rtB . izmkrq2px5 [ 3 ]
; rtB . meg2w5bizp [ ( int32_T ) rtP . Index_Value_hht33xgv1j - 1 ] = rtB .
f4wdtbi41r ; rtB . oju5efmo34 [ 0 ] = rtP .
JulianDateConversion_day_oxofdgm3xl + rtB . meg2w5bizp [ 0 ] ; rtB .
oju5efmo34 [ 1 ] = rtP . DirectionCosineMatrixECItoECEF_hour + rtB .
meg2w5bizp [ 1 ] ; rtB . oju5efmo34 [ 2 ] = rtP .
DirectionCosineMatrixECItoECEF_min + rtB . meg2w5bizp [ 2 ] ; rtB .
oju5efmo34 [ 3 ] = rtP . JulianDateConversion_sec_l3vfkmpzlh + rtB .
meg2w5bizp [ 3 ] ; rtB . btpnvv5r13 = rtB . ifwzxts3py + rtB . oju5efmo34 [ 0
] ; rtB . kvotuhl1zl = rtB . btpnvv5r13 + rtP . BiasDay_Bias_ea0r5csp12 ; rtB
. nzbd5ihkko = rtP . Gain5_Gain_obezikmpam * rtB . oju5efmo34 [ 2 ] ; rtB .
m4jvoihqrw = rtP . Gain6_Gain_jbudznuq5c * rtB . oju5efmo34 [ 3 ] ; rtB .
is4mkewv1b = ( rtB . oju5efmo34 [ 1 ] + rtB . nzbd5ihkko ) + rtB . m4jvoihqrw
; rtB . hxqcavcwua = rtP . Gain4_Gain_c4zgm5t2w1 * rtB . is4mkewv1b ; rtB .
fuwwapn1xa = rtB . kvotuhl1zl + rtB . hxqcavcwua ; rtB . kgo0mhc5nv = rtB .
fuwwapn1xa + rtB . aizqp2ntxc ; rtB . b3iuwc5zih = rtB . kgo0mhc5nv + rtP .
Bias_Bias_l532sun3ix ; rtB . kvzow0nzav = muDoubleScalarMod ( rtB .
b3iuwc5zih , rtP . Constant_Value_j2nbb2jcp2 ) + rtP . Bias1_Bias_o2qxjaezc1
; rtB . ax1elxl2af = rtP . Gain_Gain_ak5fpqqeh4 * rtB . b3iuwc5zih ; rtB .
hbcseuiqv1 = rtB . kvzow0nzav + rtB . ax1elxl2af ; rtB . nlvrugau3g = rtP .
Gain1_Gain_detstoozi4 * rtB . hbcseuiqv1 ; rtB . oxspixiypd [ 0 ] =
muDoubleScalarMod ( rtB . nlvrugau3g , rtP . Constant_Value_m2yb3ytgqq ) ;
rtB . oxspixiypd [ 1 ] = rtP . Constant1_Value_naue5nbsm0 [ 0 ] ; rtB .
oxspixiypd [ 2 ] = rtP . Constant1_Value_naue5nbsm0 [ 1 ] ;
muDoubleScalarSinCos ( rtB . oxspixiypd [ 0 ] , & nhr4ttucgq , & bptigujyyv [
0 ] ) ; muDoubleScalarSinCos ( rtB . oxspixiypd [ 1 ] , & fuciomtlqo , &
bptigujyyv [ 1 ] ) ; muDoubleScalarSinCos ( rtB . oxspixiypd [ 2 ] , &
inttemp , & bptigujyyv [ 2 ] ) ; rtB . obxsdxvebf [ 0 ] = bptigujyyv [ 1 ] *
bptigujyyv [ 0 ] ; rtB . obxsdxvebf [ 1 ] = inttemp * fuciomtlqo * bptigujyyv
[ 0 ] - bptigujyyv [ 2 ] * nhr4ttucgq ; rtB . obxsdxvebf [ 2 ] = bptigujyyv [
2 ] * fuciomtlqo * bptigujyyv [ 0 ] + inttemp * nhr4ttucgq ; rtB . obxsdxvebf
[ 3 ] = bptigujyyv [ 1 ] * nhr4ttucgq ; rtB . obxsdxvebf [ 4 ] = inttemp *
fuciomtlqo * nhr4ttucgq + bptigujyyv [ 2 ] * bptigujyyv [ 0 ] ; rtB .
obxsdxvebf [ 5 ] = bptigujyyv [ 2 ] * fuciomtlqo * nhr4ttucgq - inttemp *
bptigujyyv [ 0 ] ; rtB . obxsdxvebf [ 6 ] = - fuciomtlqo ; rtB . obxsdxvebf [
7 ] = inttemp * bptigujyyv [ 1 ] ; rtB . obxsdxvebf [ 8 ] = bptigujyyv [ 2 ]
* bptigujyyv [ 1 ] ; rtB . h14powxwoq = rtP . Y0_Coefs_cma4ntrpt3 [ 0 ] ; for
( s207_iter = 0 ; s207_iter < 5 ; s207_iter ++ ) { rtB . h14powxwoq = rtB .
h14powxwoq * rtB . dm2o2p1lc4 + rtP . Y0_Coefs_cma4ntrpt3 [ s207_iter + 1 ] ;
} for ( i = 0 ; i < 277 ; i ++ ) { rtB . adnsiqq2dm [ i ] = rtP .
Constant2_Value_a4evmfwszo [ i ] ; rtB . f35oij5vwg [ i ] = rtB . dm2o2p1lc4
; } rtB . lrbpscjc5u = rtB . dm2o2p1lc4 * rtB . dm2o2p1lc4 ; for ( i = 0 ; i
< 30 ; i ++ ) { rtB . ndlhvo3dyr [ i ] = rtP . Constant3_Value_jz2c5abeqb [ i
] ; rtB . pxi1bjg1g4 [ i ] = rtB . lrbpscjc5u ; } rtB . eb5rjonudc = rtB .
lrbpscjc5u * rtB . dm2o2p1lc4 ; rtB . iu5lzrgxsp = rtB . eb5rjonudc * rtB .
dm2o2p1lc4 ; rtB . k4vkef0d22 = rtP . mMoon_Coefs_jtz0tcft3i [ 0 ] ; rtB .
kzkglygxvh = rtP . mSun_Coefs_diyd15g1wp [ 0 ] ; rtB . j1bfbdcgsv = rtP .
umMoon_Coefs_plrarhxgq3 [ 0 ] ; rtB . l3wuaxnxut = rtP .
dSun_Coefs_dmufayevgi [ 0 ] ; rtB . n1sqhnkie1 = rtP .
omegaMoon_Coefs_isubkliji5 [ 0 ] ; rtB . k4vkef0d22 = rtB . k4vkef0d22 * rtB
. dm2o2p1lc4 + rtP . mMoon_Coefs_jtz0tcft3i [ 1 ] ; rtB . kzkglygxvh = rtB .
kzkglygxvh * rtB . dm2o2p1lc4 + rtP . mSun_Coefs_diyd15g1wp [ 1 ] ; rtB .
j1bfbdcgsv = rtB . j1bfbdcgsv * rtB . dm2o2p1lc4 + rtP .
umMoon_Coefs_plrarhxgq3 [ 1 ] ; rtB . l3wuaxnxut = rtB . l3wuaxnxut * rtB .
dm2o2p1lc4 + rtP . dSun_Coefs_dmufayevgi [ 1 ] ; rtB . n1sqhnkie1 = rtB .
n1sqhnkie1 * rtB . dm2o2p1lc4 + rtP . omegaMoon_Coefs_isubkliji5 [ 1 ] ; rtB
. k4vkef0d22 = rtB . k4vkef0d22 * rtB . dm2o2p1lc4 + rtP .
mMoon_Coefs_jtz0tcft3i [ 2 ] ; rtB . kzkglygxvh = rtB . kzkglygxvh * rtB .
dm2o2p1lc4 + rtP . mSun_Coefs_diyd15g1wp [ 2 ] ; rtB . j1bfbdcgsv = rtB .
j1bfbdcgsv * rtB . dm2o2p1lc4 + rtP . umMoon_Coefs_plrarhxgq3 [ 2 ] ; rtB .
l3wuaxnxut = rtB . l3wuaxnxut * rtB . dm2o2p1lc4 + rtP .
dSun_Coefs_dmufayevgi [ 2 ] ; rtB . n1sqhnkie1 = rtB . n1sqhnkie1 * rtB .
dm2o2p1lc4 + rtP . omegaMoon_Coefs_isubkliji5 [ 2 ] ; rtB . k4vkef0d22 = rtB
. k4vkef0d22 * rtB . dm2o2p1lc4 + rtP . mMoon_Coefs_jtz0tcft3i [ 3 ] ; rtB .
kzkglygxvh = rtB . kzkglygxvh * rtB . dm2o2p1lc4 + rtP .
mSun_Coefs_diyd15g1wp [ 3 ] ; rtB . j1bfbdcgsv = rtB . j1bfbdcgsv * rtB .
dm2o2p1lc4 + rtP . umMoon_Coefs_plrarhxgq3 [ 3 ] ; rtB . l3wuaxnxut = rtB .
l3wuaxnxut * rtB . dm2o2p1lc4 + rtP . dSun_Coefs_dmufayevgi [ 3 ] ; rtB .
n1sqhnkie1 = rtB . n1sqhnkie1 * rtB . dm2o2p1lc4 + rtP .
omegaMoon_Coefs_isubkliji5 [ 3 ] ; rtB . k4vkef0d22 = rtB . k4vkef0d22 * rtB
. dm2o2p1lc4 + rtP . mMoon_Coefs_jtz0tcft3i [ 4 ] ; rtB . kzkglygxvh = rtB .
kzkglygxvh * rtB . dm2o2p1lc4 + rtP . mSun_Coefs_diyd15g1wp [ 4 ] ; rtB .
j1bfbdcgsv = rtB . j1bfbdcgsv * rtB . dm2o2p1lc4 + rtP .
umMoon_Coefs_plrarhxgq3 [ 4 ] ; rtB . l3wuaxnxut = rtB . l3wuaxnxut * rtB .
dm2o2p1lc4 + rtP . dSun_Coefs_dmufayevgi [ 4 ] ; rtB . n1sqhnkie1 = rtB .
n1sqhnkie1 * rtB . dm2o2p1lc4 + rtP . omegaMoon_Coefs_isubkliji5 [ 4 ] ; rtB
. bxueqfeu55 [ 0 ] = rtP . Gain_Gain_onjpfk2fzl * rtB . k4vkef0d22 ; rtB .
bxueqfeu55 [ 1 ] = rtP . Gain_Gain_onjpfk2fzl * rtB . kzkglygxvh ; rtB .
bxueqfeu55 [ 2 ] = rtP . Gain_Gain_onjpfk2fzl * rtB . j1bfbdcgsv ; rtB .
bxueqfeu55 [ 3 ] = rtP . Gain_Gain_onjpfk2fzl * rtB . l3wuaxnxut ; rtB .
bxueqfeu55 [ 4 ] = rtP . Gain_Gain_onjpfk2fzl * rtB . n1sqhnkie1 ; rtB .
cgpbdfxjn1 = rtP . lMercury_Coefs_lxucr4qhwu [ 0 ] ; rtB . cgpbdfxjn1 = rtB .
cgpbdfxjn1 * rtB . dm2o2p1lc4 + rtP . lMercury_Coefs_lxucr4qhwu [ 1 ] ; rtB .
epfzdghm10 = rtP . lVenus_Coefs_fxotok2s3d [ 0 ] ; rtB . epfzdghm10 = rtB .
epfzdghm10 * rtB . dm2o2p1lc4 + rtP . lVenus_Coefs_fxotok2s3d [ 1 ] ; rtB .
ft0z0s4aqu = rtP . lEarth_Coefs_bya2kolugl [ 0 ] ; rtB . ft0z0s4aqu = rtB .
ft0z0s4aqu * rtB . dm2o2p1lc4 + rtP . lEarth_Coefs_bya2kolugl [ 1 ] ; rtB .
fpjnzmjefc = rtP . lMars_Coefs_kkf443jqvl [ 0 ] ; rtB . fpjnzmjefc = rtB .
fpjnzmjefc * rtB . dm2o2p1lc4 + rtP . lMars_Coefs_kkf443jqvl [ 1 ] ; rtB .
g5vytyje2h = rtP . lJupiter_Coefs_aa0qdlhuxf [ 0 ] ; rtB . g5vytyje2h = rtB .
g5vytyje2h * rtB . dm2o2p1lc4 + rtP . lJupiter_Coefs_aa0qdlhuxf [ 1 ] ; rtB .
cvfz50cwau = rtP . lSaturn_Coefs_nm4emcptmd [ 0 ] ; rtB . cvfz50cwau = rtB .
cvfz50cwau * rtB . dm2o2p1lc4 + rtP . lSaturn_Coefs_nm4emcptmd [ 1 ] ; rtB .
ewxwkkl5da = rtP . lUranus_Coefs_esv1bkthff [ 0 ] ; rtB . ewxwkkl5da = rtB .
ewxwkkl5da * rtB . dm2o2p1lc4 + rtP . lUranus_Coefs_esv1bkthff [ 1 ] ; rtB .
ao0glnhvoj = rtP . lNeptune_Coefs_krgackraim [ 0 ] ; rtB . ao0glnhvoj = rtB .
ao0glnhvoj * rtB . dm2o2p1lc4 + rtP . lNeptune_Coefs_krgackraim [ 1 ] ; rtB .
ackvpr0z3u = rtP . pa_Coefs_lemnaykgb3 [ 0 ] ; rtB . ackvpr0z3u = rtB .
ackvpr0z3u * rtB . dm2o2p1lc4 + rtP . pa_Coefs_lemnaykgb3 [ 1 ] ; rtB .
ackvpr0z3u = rtB . ackvpr0z3u * rtB . dm2o2p1lc4 + rtP . pa_Coefs_lemnaykgb3
[ 2 ] ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . jmdg0cvfrp [ i ] = rtP .
Constant4_Value_o1opkhecub [ i ] ; rtB . dpyla2yxww [ i ] = rtB . eb5rjonudc
; rtB . czcmpilucx [ i ] = 0.017453292519943295 * rtB . bxueqfeu55 [ i ] ; }
rtB . czcmpilucx [ 5 ] = rtB . cgpbdfxjn1 ; rtB . czcmpilucx [ 6 ] = rtB .
epfzdghm10 ; rtB . czcmpilucx [ 7 ] = rtB . ft0z0s4aqu ; rtB . czcmpilucx [ 8
] = rtB . fpjnzmjefc ; rtB . czcmpilucx [ 9 ] = rtB . g5vytyje2h ; rtB .
czcmpilucx [ 10 ] = rtB . cvfz50cwau ; rtB . czcmpilucx [ 11 ] = rtB .
ewxwkkl5da ; rtB . czcmpilucx [ 12 ] = rtB . ao0glnhvoj ; rtB . czcmpilucx [
13 ] = rtB . ackvpr0z3u ; for ( i = 0 ; i < 14 ; i ++ ) { nxh00ek3k5 [ i ] =
muDoubleScalarMod ( rtB . czcmpilucx [ i ] , rtP . Constant_Value_psn3rbk20o
) ; } TRANS = 'N' ; M = 1275LL ; N = 14LL ; nhr4ttucgq = 1.0 ; LDA = 1275LL ;
INCX = 1LL ; fuciomtlqo = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , &
nhr4ttucgq , & rtB . btwrco0qwd [ 0 ] , & LDA , & nxh00ek3k5 [ 0 ] , & INCX ,
& fuciomtlqo , & rtB . icgnte4qpu [ 0 ] , & INCY ) ; for ( i = 0 ; i < 962 ;
i ++ ) { rtB . fbvatilagf [ i ] = rtP . Constant1_Value_axzvxccr3e [ i ] *
rtB . kd1rv3iov0 [ i ] * muDoubleScalarSin ( rtB . icgnte4qpu [ i ] ) ; } for
( i = 0 ; i < 277 ; i ++ ) { rtB . fbvatilagf [ i + 962 ] = rtB . kd1rv3iov0
[ i + 962 ] * rtB . f35oij5vwg [ i ] * muDoubleScalarSin ( rtB . icgnte4qpu [
i + 962 ] ) ; } for ( i = 0 ; i < 30 ; i ++ ) { rtB . fbvatilagf [ i + 1239 ]
= rtB . kd1rv3iov0 [ i + 1239 ] * rtB . pxi1bjg1g4 [ i ] * muDoubleScalarSin
( rtB . icgnte4qpu [ i + 1239 ] ) ; } for ( i = 0 ; i < 5 ; i ++ ) { rtB .
fbvatilagf [ i + 1269 ] = rtB . kd1rv3iov0 [ i + 1269 ] * rtB . dpyla2yxww [
i ] * muDoubleScalarSin ( rtB . icgnte4qpu [ i + 1269 ] ) ; } rtB .
fbvatilagf [ 1274 ] = rtB . iu5lzrgxsp * rtB . kd1rv3iov0 [ 1274 ] *
muDoubleScalarSin ( rtB . icgnte4qpu [ 1274 ] ) ; for ( i = 0 ; i < 962 ; i
++ ) { rtB . jkznnytsnd [ i ] = muDoubleScalarCos ( rtB . icgnte4qpu [ i ] )
* rtB . j2dweaustf [ i ] * rtP . Constant1_Value_axzvxccr3e [ i ] ; } for ( i
= 0 ; i < 277 ; i ++ ) { rtB . jkznnytsnd [ i + 962 ] = muDoubleScalarCos (
rtB . icgnte4qpu [ i + 962 ] ) * rtB . j2dweaustf [ i + 962 ] * rtB .
f35oij5vwg [ i ] ; } for ( i = 0 ; i < 30 ; i ++ ) { rtB . jkznnytsnd [ i +
1239 ] = muDoubleScalarCos ( rtB . icgnte4qpu [ i + 1239 ] ) * rtB .
j2dweaustf [ i + 1239 ] * rtB . pxi1bjg1g4 [ i ] ; } for ( i = 0 ; i < 5 ; i
++ ) { rtB . jkznnytsnd [ i + 1269 ] = muDoubleScalarCos ( rtB . icgnte4qpu [
i + 1269 ] ) * rtB . j2dweaustf [ i + 1269 ] * rtB . dpyla2yxww [ i ] ; } rtB
. jkznnytsnd [ 1274 ] = muDoubleScalarCos ( rtB . icgnte4qpu [ 1274 ] ) * rtB
. j2dweaustf [ 1274 ] * rtB . iu5lzrgxsp ; nhr4ttucgq = - 0.0 ; for ( i = 0 ;
i < 1275 ; i ++ ) { rtB . dl4v0kmdgn [ i ] = rtB . fbvatilagf [ i ] + rtB .
jkznnytsnd [ i ] ; nhr4ttucgq += rtB . dl4v0kmdgn [ i ] ; } rtB . pqctaujvgo
= nhr4ttucgq ; rtB . l5lcc4xttr = rtB . h14powxwoq + rtB . pqctaujvgo ; rtB .
ewumm1020z = rtP . Gain4_Gain_hg3t1ixrrd * rtB . l5lcc4xttr ; rtB .
fu0xgsqmwl = 0.017453292519943295 * rtB . ewumm1020z + rtP . AddParam_Value [
1 ] ; rtB . maoihm1jvn = rtP . X0_Coefs_kgh01blu1x [ 0 ] ; for ( s207_iter =
0 ; s207_iter < 5 ; s207_iter ++ ) { rtB . maoihm1jvn = rtB . maoihm1jvn *
rtB . dm2o2p1lc4 + rtP . X0_Coefs_kgh01blu1x [ s207_iter + 1 ] ; } for ( i =
0 ; i < 253 ; i ++ ) { rtB . aoao3w0eik [ i ] = rtP .
Constant2_Value_jrq2zowv3b [ i ] ; rtB . alyqymjndu [ i ] = rtB . dm2o2p1lc4
; } rtB . ggzu4svw5t = rtB . dm2o2p1lc4 * rtB . dm2o2p1lc4 ; for ( i = 0 ; i
< 36 ; i ++ ) { rtB . kw5rtltfk0 [ i ] = rtP . Constant3_Value_a315iwbeaf [ i
] ; rtB . p2ozldg0jj [ i ] = rtB . ggzu4svw5t ; } rtB . mhxp0yhl3s = rtB .
ggzu4svw5t * rtB . dm2o2p1lc4 ; rtB . dzmi0pkdb0 [ 0 ] = rtP .
Constant4_Value_hyps5wis0w [ 0 ] ; rtB . jqcdjat5ix [ 0 ] = rtB . mhxp0yhl3s
; rtB . dzmi0pkdb0 [ 1 ] = rtP . Constant4_Value_hyps5wis0w [ 1 ] ; rtB .
jqcdjat5ix [ 1 ] = rtB . mhxp0yhl3s ; rtB . dzmi0pkdb0 [ 2 ] = rtP .
Constant4_Value_hyps5wis0w [ 2 ] ; rtB . jqcdjat5ix [ 2 ] = rtB . mhxp0yhl3s
; rtB . dzmi0pkdb0 [ 3 ] = rtP . Constant4_Value_hyps5wis0w [ 3 ] ; rtB .
jqcdjat5ix [ 3 ] = rtB . mhxp0yhl3s ; rtB . fgvxet2oux = rtB . mhxp0yhl3s *
rtB . dm2o2p1lc4 ; TRANS = 'N' ; M = 1600LL ; N = 14LL ; nhr4ttucgq = 1.0 ;
LDA = 1600LL ; INCX = 1LL ; fuciomtlqo = 0.0 ; INCY = 1LL ; dgemv ( & TRANS ,
& M , & N , & nhr4ttucgq , & rtB . ek1ampu0qf [ 0 ] , & LDA , & nxh00ek3k5 [
0 ] , & INCX , & fuciomtlqo , & rtB . ptm33kspwu [ 0 ] , & INCY ) ; for ( i =
0 ; i < 1306 ; i ++ ) { rtB . pyvkiskhah [ i ] = rtP .
Constant1_Value_inkvfz0zew [ i ] * rtB . omstdtrdeg [ i ] * muDoubleScalarSin
( rtB . ptm33kspwu [ i ] ) ; } for ( i = 0 ; i < 253 ; i ++ ) { rtB .
pyvkiskhah [ i + 1306 ] = rtB . omstdtrdeg [ i + 1306 ] * rtB . alyqymjndu [
i ] * muDoubleScalarSin ( rtB . ptm33kspwu [ i + 1306 ] ) ; } for ( i = 0 ; i
< 36 ; i ++ ) { rtB . pyvkiskhah [ i + 1559 ] = rtB . omstdtrdeg [ i + 1559 ]
* rtB . p2ozldg0jj [ i ] * muDoubleScalarSin ( rtB . ptm33kspwu [ i + 1559 ]
) ; } rtB . pyvkiskhah [ 1595 ] = rtB . jqcdjat5ix [ 0 ] * rtB . omstdtrdeg [
1595 ] * muDoubleScalarSin ( rtB . ptm33kspwu [ 1595 ] ) ; rtB . pyvkiskhah [
1596 ] = rtB . jqcdjat5ix [ 1 ] * rtB . omstdtrdeg [ 1596 ] *
muDoubleScalarSin ( rtB . ptm33kspwu [ 1596 ] ) ; rtB . pyvkiskhah [ 1597 ] =
rtB . jqcdjat5ix [ 2 ] * rtB . omstdtrdeg [ 1597 ] * muDoubleScalarSin ( rtB
. ptm33kspwu [ 1597 ] ) ; rtB . pyvkiskhah [ 1598 ] = rtB . jqcdjat5ix [ 3 ]
* rtB . omstdtrdeg [ 1598 ] * muDoubleScalarSin ( rtB . ptm33kspwu [ 1598 ] )
; rtB . pyvkiskhah [ 1599 ] = rtB . fgvxet2oux * rtB . omstdtrdeg [ 1599 ] *
muDoubleScalarSin ( rtB . ptm33kspwu [ 1599 ] ) ; for ( i = 0 ; i < 1306 ; i
++ ) { rtB . m0vxd3rvog [ i ] = muDoubleScalarCos ( rtB . ptm33kspwu [ i ] )
* rtB . omav200po3 [ i ] * rtP . Constant1_Value_inkvfz0zew [ i ] ; } for ( i
= 0 ; i < 253 ; i ++ ) { rtB . m0vxd3rvog [ i + 1306 ] = muDoubleScalarCos (
rtB . ptm33kspwu [ i + 1306 ] ) * rtB . omav200po3 [ i + 1306 ] * rtB .
alyqymjndu [ i ] ; } for ( i = 0 ; i < 36 ; i ++ ) { rtB . m0vxd3rvog [ i +
1559 ] = muDoubleScalarCos ( rtB . ptm33kspwu [ i + 1559 ] ) * rtB .
omav200po3 [ i + 1559 ] * rtB . p2ozldg0jj [ i ] ; } rtB . m0vxd3rvog [ 1595
] = muDoubleScalarCos ( rtB . ptm33kspwu [ 1595 ] ) * rtB . omav200po3 [ 1595
] * rtB . jqcdjat5ix [ 0 ] ; rtB . m0vxd3rvog [ 1596 ] = muDoubleScalarCos (
rtB . ptm33kspwu [ 1596 ] ) * rtB . omav200po3 [ 1596 ] * rtB . jqcdjat5ix [
1 ] ; rtB . m0vxd3rvog [ 1597 ] = muDoubleScalarCos ( rtB . ptm33kspwu [ 1597
] ) * rtB . omav200po3 [ 1597 ] * rtB . jqcdjat5ix [ 2 ] ; rtB . m0vxd3rvog [
1598 ] = muDoubleScalarCos ( rtB . ptm33kspwu [ 1598 ] ) * rtB . omav200po3 [
1598 ] * rtB . jqcdjat5ix [ 3 ] ; rtB . m0vxd3rvog [ 1599 ] =
muDoubleScalarCos ( rtB . ptm33kspwu [ 1599 ] ) * rtB . omav200po3 [ 1599 ] *
rtB . fgvxet2oux ; nhr4ttucgq = - 0.0 ; for ( i = 0 ; i < 1600 ; i ++ ) { rtB
. l2s0i5fm5h [ i ] = rtB . pyvkiskhah [ i ] + rtB . m0vxd3rvog [ i ] ;
nhr4ttucgq += rtB . l2s0i5fm5h [ i ] ; } rtB . mcp1wxjj5w = nhr4ttucgq ; rtB
. nlfpuwtzr5 = rtB . maoihm1jvn + rtB . mcp1wxjj5w ; rtB . kqsiph1ehy = rtP .
Gain3_Gain_j3zv55r1ur * rtB . nlfpuwtzr5 ; rtB . jfgmo4o2up =
0.017453292519943295 * rtB . kqsiph1ehy + rtP . AddParam_Value [ 0 ] ;
inttemp = muDoubleScalarAtan2 ( rtB . fu0xgsqmwl , rtB . jfgmo4o2up ) ; rtB .
bjevpalkzl = rtB . jfgmo4o2up * rtB . jfgmo4o2up + rtB . fu0xgsqmwl * rtB .
fu0xgsqmwl ; rtB . nxb04j0yva = rtP . Constant_Value_gktmyn3mcb - rtB .
bjevpalkzl ; rtB . a2b3wwkimh = rtB . bjevpalkzl / rtB . nxb04j0yva ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . dwpkqcic1h != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . dwpkqcic1h = 0 ;
} days = muDoubleScalarSqrt ( rtB . a2b3wwkimh ) ; } else { if ( rtB .
a2b3wwkimh < 0.0 ) { days = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtB .
a2b3wwkimh ) ) ; } else { days = muDoubleScalarSqrt ( rtB . a2b3wwkimh ) ; }
if ( rtB . a2b3wwkimh < 0.0 ) { rtDW . dwpkqcic1h = 1 ; } } rtB . os1rarrsrr
= rtP . S0_Coefs_no3ka1dr5l [ 0 ] ; for ( s207_iter = 0 ; s207_iter < 5 ;
s207_iter ++ ) { rtB . os1rarrsrr = rtB . os1rarrsrr * rtB . dm2o2p1lc4 + rtP
. S0_Coefs_no3ka1dr5l [ s207_iter + 1 ] ; } rtB . jsrj0v34ul [ 0 ] = rtP .
Constant2_Value_by5smj3iox [ 0 ] ; rtB . arfcpmaykn [ 0 ] = rtB . dm2o2p1lc4
; rtB . jsrj0v34ul [ 1 ] = rtP . Constant2_Value_by5smj3iox [ 1 ] ; rtB .
arfcpmaykn [ 1 ] = rtB . dm2o2p1lc4 ; rtB . jsrj0v34ul [ 2 ] = rtP .
Constant2_Value_by5smj3iox [ 2 ] ; rtB . arfcpmaykn [ 2 ] = rtB . dm2o2p1lc4
; rtB . k104yccunc = rtB . dm2o2p1lc4 * rtB . dm2o2p1lc4 ; for ( i = 0 ; i <
25 ; i ++ ) { rtB . hgcuynlons [ i ] = rtP . Constant3_Value_hgeiisjifi [ i ]
; rtB . ijx5xzvxig [ i ] = rtB . k104yccunc ; } rtB . fzmd1gnkjj = rtB .
k104yccunc * rtB . dm2o2p1lc4 ; rtB . dyfmpxj3ck [ 0 ] = rtP .
Constant4_Value_i4zhyp3snv [ 0 ] ; rtB . hbjigi0xxg [ 0 ] = rtB . fzmd1gnkjj
; rtB . dyfmpxj3ck [ 1 ] = rtP . Constant4_Value_i4zhyp3snv [ 1 ] ; rtB .
hbjigi0xxg [ 1 ] = rtB . fzmd1gnkjj ; rtB . dyfmpxj3ck [ 2 ] = rtP .
Constant4_Value_i4zhyp3snv [ 2 ] ; rtB . hbjigi0xxg [ 2 ] = rtB . fzmd1gnkjj
; rtB . dyfmpxj3ck [ 3 ] = rtP . Constant4_Value_i4zhyp3snv [ 3 ] ; rtB .
hbjigi0xxg [ 3 ] = rtB . fzmd1gnkjj ; rtB . ezjkzzqpsv = rtB . fzmd1gnkjj *
rtB . dm2o2p1lc4 ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . fmdigjnac2 [ i ] =
nxh00ek3k5 [ i ] ; } rtB . fmdigjnac2 [ 5 ] = nxh00ek3k5 [ 6 ] ; rtB .
fmdigjnac2 [ 6 ] = nxh00ek3k5 [ 7 ] ; rtB . fmdigjnac2 [ 7 ] = nxh00ek3k5 [
13 ] ; TRANS = 'N' ; M = 66LL ; N = 8LL ; nhr4ttucgq = 1.0 ; LDA = 66LL ;
INCX = 1LL ; fuciomtlqo = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , &
nhr4ttucgq , & rtB . nfidzfrt02 [ 0 ] , & LDA , & rtB . fmdigjnac2 [ 0 ] , &
INCX , & fuciomtlqo , & rtB . miunog0axq [ 0 ] , & INCY ) ; for ( i = 0 ; i <
33 ; i ++ ) { rtB . du2d0zc4qu [ i ] = rtP . Constant1_Value_ddiex05etl [ i ]
* rtB . chnbedf2rz [ i ] * muDoubleScalarSin ( rtB . miunog0axq [ i ] ) ; }
rtB . du2d0zc4qu [ 33 ] = rtB . arfcpmaykn [ 0 ] * rtB . chnbedf2rz [ 33 ] *
muDoubleScalarSin ( rtB . miunog0axq [ 33 ] ) ; rtB . du2d0zc4qu [ 34 ] = rtB
. arfcpmaykn [ 1 ] * rtB . chnbedf2rz [ 34 ] * muDoubleScalarSin ( rtB .
miunog0axq [ 34 ] ) ; rtB . du2d0zc4qu [ 35 ] = rtB . arfcpmaykn [ 2 ] * rtB
. chnbedf2rz [ 35 ] * muDoubleScalarSin ( rtB . miunog0axq [ 35 ] ) ; for ( i
= 0 ; i < 25 ; i ++ ) { rtB . du2d0zc4qu [ i + 36 ] = rtB . chnbedf2rz [ i +
36 ] * rtB . ijx5xzvxig [ i ] * muDoubleScalarSin ( rtB . miunog0axq [ i + 36
] ) ; } rtB . du2d0zc4qu [ 61 ] = rtB . hbjigi0xxg [ 0 ] * rtB . chnbedf2rz [
61 ] * muDoubleScalarSin ( rtB . miunog0axq [ 61 ] ) ; rtB . du2d0zc4qu [ 62
] = rtB . hbjigi0xxg [ 1 ] * rtB . chnbedf2rz [ 62 ] * muDoubleScalarSin (
rtB . miunog0axq [ 62 ] ) ; rtB . du2d0zc4qu [ 63 ] = rtB . hbjigi0xxg [ 2 ]
* rtB . chnbedf2rz [ 63 ] * muDoubleScalarSin ( rtB . miunog0axq [ 63 ] ) ;
rtB . du2d0zc4qu [ 64 ] = rtB . hbjigi0xxg [ 3 ] * rtB . chnbedf2rz [ 64 ] *
muDoubleScalarSin ( rtB . miunog0axq [ 64 ] ) ; rtB . du2d0zc4qu [ 65 ] = rtB
. ezjkzzqpsv * rtB . chnbedf2rz [ 65 ] * muDoubleScalarSin ( rtB . miunog0axq
[ 65 ] ) ; for ( i = 0 ; i < 33 ; i ++ ) { rtB . gkyovuu3aw [ i ] =
muDoubleScalarCos ( rtB . miunog0axq [ i ] ) * rtB . kufhg2pmkw [ i ] * rtP .
Constant1_Value_ddiex05etl [ i ] ; } rtB . gkyovuu3aw [ 33 ] =
muDoubleScalarCos ( rtB . miunog0axq [ 33 ] ) * rtB . kufhg2pmkw [ 33 ] * rtB
. arfcpmaykn [ 0 ] ; rtB . gkyovuu3aw [ 34 ] = muDoubleScalarCos ( rtB .
miunog0axq [ 34 ] ) * rtB . kufhg2pmkw [ 34 ] * rtB . arfcpmaykn [ 1 ] ; rtB
. gkyovuu3aw [ 35 ] = muDoubleScalarCos ( rtB . miunog0axq [ 35 ] ) * rtB .
kufhg2pmkw [ 35 ] * rtB . arfcpmaykn [ 2 ] ; for ( i = 0 ; i < 25 ; i ++ ) {
rtB . gkyovuu3aw [ i + 36 ] = muDoubleScalarCos ( rtB . miunog0axq [ i + 36 ]
) * rtB . kufhg2pmkw [ i + 36 ] * rtB . ijx5xzvxig [ i ] ; } rtB . gkyovuu3aw
[ 61 ] = muDoubleScalarCos ( rtB . miunog0axq [ 61 ] ) * rtB . kufhg2pmkw [
61 ] * rtB . hbjigi0xxg [ 0 ] ; rtB . gkyovuu3aw [ 62 ] = muDoubleScalarCos (
rtB . miunog0axq [ 62 ] ) * rtB . kufhg2pmkw [ 62 ] * rtB . hbjigi0xxg [ 1 ]
; rtB . gkyovuu3aw [ 63 ] = muDoubleScalarCos ( rtB . miunog0axq [ 63 ] ) *
rtB . kufhg2pmkw [ 63 ] * rtB . hbjigi0xxg [ 2 ] ; rtB . gkyovuu3aw [ 64 ] =
muDoubleScalarCos ( rtB . miunog0axq [ 64 ] ) * rtB . kufhg2pmkw [ 64 ] * rtB
. hbjigi0xxg [ 3 ] ; rtB . gkyovuu3aw [ 65 ] = muDoubleScalarCos ( rtB .
miunog0axq [ 65 ] ) * rtB . kufhg2pmkw [ 65 ] * rtB . ezjkzzqpsv ; nhr4ttucgq
= - 0.0 ; for ( i = 0 ; i < 66 ; i ++ ) { rtB . nlpb2qzl3l [ i ] = rtB .
du2d0zc4qu [ i ] + rtB . gkyovuu3aw [ i ] ; nhr4ttucgq += rtB . nlpb2qzl3l [
i ] ; } rtB . gop12iuzpq = nhr4ttucgq ; rtB . fsryokpcdy = rtB . os1rarrsrr +
rtB . gop12iuzpq ; rtB . pslqjgdapi = rtP . Gain2_Gain_jdtrerikvn * rtB .
fsryokpcdy ; rtB . jsqufalwzt = rtB . fu0xgsqmwl * rtB . jfgmo4o2up ; rtB .
d10chwuyqe = rtP . Gain5_Gain_bm1bslfrzz * rtB . jsqufalwzt ; rtB .
kfllrbq4fx = 0.017453292519943295 * rtB . pslqjgdapi - rtB . d10chwuyqe ; rtB
. nawdlquz5z = rtB . kfllrbq4fx + inttemp ; rtB . i0ney05wxx = rtP .
Gain1_Gain_o1mxdlp2ab * rtB . nawdlquz5z ; rtB . jz2wzvcqsl [ 0 ] = inttemp ;
rtB . jz2wzvcqsl [ 1 ] = muDoubleScalarAtan ( days ) ; rtB . jz2wzvcqsl [ 2 ]
= rtB . i0ney05wxx ; muDoubleScalarSinCos ( rtB . jz2wzvcqsl [ 0 ] , &
nhr4ttucgq , & bptigujyyv [ 0 ] ) ; muDoubleScalarSinCos ( rtB . jz2wzvcqsl [
1 ] , & fuciomtlqo , & bptigujyyv [ 1 ] ) ; muDoubleScalarSinCos ( rtB .
jz2wzvcqsl [ 2 ] , & inttemp , & bptigujyyv [ 2 ] ) ; rtB . fkhy5353dd [ 0 ]
= bptigujyyv [ 0 ] * bptigujyyv [ 2 ] * bptigujyyv [ 1 ] - nhr4ttucgq *
inttemp ; rtB . fkhy5353dd [ 1 ] = - bptigujyyv [ 0 ] * bptigujyyv [ 1 ] *
inttemp - nhr4ttucgq * bptigujyyv [ 2 ] ; rtB . fkhy5353dd [ 2 ] = bptigujyyv
[ 0 ] * fuciomtlqo ; rtB . fkhy5353dd [ 3 ] = nhr4ttucgq * bptigujyyv [ 2 ] *
bptigujyyv [ 1 ] + bptigujyyv [ 0 ] * inttemp ; rtB . fkhy5353dd [ 4 ] = -
nhr4ttucgq * bptigujyyv [ 1 ] * inttemp + bptigujyyv [ 0 ] * bptigujyyv [ 2 ]
; rtB . fkhy5353dd [ 5 ] = nhr4ttucgq * fuciomtlqo ; rtB . fkhy5353dd [ 6 ] =
- fuciomtlqo * bptigujyyv [ 2 ] ; rtB . fkhy5353dd [ 7 ] = fuciomtlqo *
inttemp ; rtB . fkhy5353dd [ 8 ] = bptigujyyv [ 1 ] ; for ( s207_iter = 0 ;
s207_iter < 3 ; s207_iter ++ ) { for ( s256_iter = 0 ; s256_iter < 3 ;
s256_iter ++ ) { eldb3aqjyd [ s256_iter + 3 * s207_iter ] = 0.0 ; eldb3aqjyd
[ s256_iter + 3 * s207_iter ] += rtB . fkhy5353dd [ 3 * s207_iter ] * rtB .
obxsdxvebf [ s256_iter ] ; eldb3aqjyd [ s256_iter + 3 * s207_iter ] += rtB .
fkhy5353dd [ 3 * s207_iter + 1 ] * rtB . obxsdxvebf [ s256_iter + 3 ] ;
eldb3aqjyd [ s256_iter + 3 * s207_iter ] += rtB . fkhy5353dd [ 3 * s207_iter
+ 2 ] * rtB . obxsdxvebf [ s256_iter + 6 ] ; } } for ( s207_iter = 0 ;
s207_iter < 3 ; s207_iter ++ ) { for ( s256_iter = 0 ; s256_iter < 3 ;
s256_iter ++ ) { rtB . emfuz3ubwz [ s256_iter + 3 * s207_iter ] = 0.0 ; rtB .
emfuz3ubwz [ s256_iter + 3 * s207_iter ] += eldb3aqjyd [ 3 * s207_iter ] *
rtB . fjiyyvaugo [ s256_iter ] ; rtB . emfuz3ubwz [ s256_iter + 3 * s207_iter
] += eldb3aqjyd [ 3 * s207_iter + 1 ] * rtB . fjiyyvaugo [ s256_iter + 3 ] ;
rtB . emfuz3ubwz [ s256_iter + 3 * s207_iter ] += eldb3aqjyd [ 3 * s207_iter
+ 2 ] * rtB . fjiyyvaugo [ s256_iter + 6 ] ; } } pqreim41fn ( rtB .
emfuz3ubwz , & rtB . pqreim41fnf ) ; oa2h4lycyt ( rtB . pqreim41fnf .
ekmxe1wuqt , & rtB . oa2h4lycyto ) ; bq4wkncpnc ( rtB . oa2h4lycyto .
jtgcw4sbk0 , & rtB . ncfvgzcbsa ) ; hh4puuamkn ( rtB . oa2h4lycyto .
jtgcw4sbk0 , rtB . hzfvnqhqh4 , & rtB . onhb0tophc ) ; jywb5kciye ( rtB .
onhb0tophc . bogcyvs5ln , & rtB . kfmgjpcbo0 , rtP . CONSTANTS_par . mu_earth
) ; elrubs4mtp ( rtB . ncfvgzcbsa . nm24payncx , rtB . kfmgjpcbo0 .
gafarm32k2 , & rtB . iuykey3bat ) ; rtB . kqaoyphs3d [ 0 ] = rtB . dlf3gf11iq
[ 0 ] + rtB . iuykey3bat . ehs4r2hz2y [ 0 ] ; rtB . kqaoyphs3d [ 1 ] = rtB .
dlf3gf11iq [ 1 ] + rtB . iuykey3bat . ehs4r2hz2y [ 1 ] ; rtB . kqaoyphs3d [ 2
] = rtB . dlf3gf11iq [ 2 ] + rtB . iuykey3bat . ehs4r2hz2y [ 2 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { eehz0nr2kb ( rtP . DYN_SC_par . inertia , &
rtB . eehz0nr2kbd , rtP . LIB_ROT_MATINV_tol ) ; } rtB . cufcoe2lw0 [ 0 ] =
rtX . pz5d015liz [ 0 ] ; rtB . cufcoe2lw0 [ 1 ] = rtX . pz5d015liz [ 1 ] ;
rtB . cufcoe2lw0 [ 2 ] = rtX . pz5d015liz [ 2 ] ; for ( s207_iter = 0 ;
s207_iter < 3 ; s207_iter ++ ) { rtB . f3zlxaswiq [ s207_iter ] = 0.0 ; rtB .
f3zlxaswiq [ s207_iter ] += rtB . eehz0nr2kbd . ivoxddha1s . nxsqtyhezz [
s207_iter ] * rtB . cufcoe2lw0 [ 0 ] ; rtB . f3zlxaswiq [ s207_iter ] += rtB
. eehz0nr2kbd . ivoxddha1s . nxsqtyhezz [ s207_iter + 3 ] * rtB . cufcoe2lw0
[ 1 ] ; rtB . f3zlxaswiq [ s207_iter ] += rtB . eehz0nr2kbd . ivoxddha1s .
nxsqtyhezz [ s207_iter + 6 ] * rtB . cufcoe2lw0 [ 2 ] ; } rtB . k13h5jbvy1 =
rtB . esq14j0ci4 [ 1 ] * rtB . nhbdb1hyqs [ 2 ] ; rtB . n3k1ob3xmx = rtB .
esq14j0ci4 [ 2 ] * rtB . nhbdb1hyqs [ 0 ] ; rtB . m5hmz43bo1 = rtB .
esq14j0ci4 [ 0 ] * rtB . nhbdb1hyqs [ 1 ] ; rtB . n5mij1y5vn = rtB .
esq14j0ci4 [ 2 ] * rtB . nhbdb1hyqs [ 1 ] ; rtB . pg1djboonx = rtB .
esq14j0ci4 [ 0 ] * rtB . nhbdb1hyqs [ 2 ] ; rtB . ch1525kggw = rtB .
esq14j0ci4 [ 1 ] * rtB . nhbdb1hyqs [ 0 ] ; rtB . nmtuh2ebbi [ 0 ] = rtB .
k13h5jbvy1 - rtB . n5mij1y5vn ; rtB . nmtuh2ebbi [ 1 ] = rtB . n3k1ob3xmx -
rtB . pg1djboonx ; rtB . nmtuh2ebbi [ 2 ] = rtB . m5hmz43bo1 - rtB .
ch1525kggw ; rtB . opfb3c3zmg [ 0 ] = rtP . AerodynamicForcesandMoments_b *
rtB . ggvanenkks ; rtB . opfb3c3zmg [ 1 ] = rtP .
AerodynamicForcesandMoments_cbar * rtB . ggvanenkks ; rtB . opfb3c3zmg [ 2 ]
= rtP . AerodynamicForcesandMoments_b * rtB . ggvanenkks ; rtB . h0udz1lb32 [
0 ] = rtP . DYN_AERO_par . Drag_Coefficient [ 3 ] * rtB . opfb3c3zmg [ 0 ] ;
rtB . lmiox3ymu0 [ 0 ] = rtB . nmtuh2ebbi [ 0 ] + rtB . h0udz1lb32 [ 0 ] ;
rtB . h0udz1lb32 [ 1 ] = rtP . DYN_AERO_par . Drag_Coefficient [ 4 ] * rtB .
opfb3c3zmg [ 1 ] ; rtB . lmiox3ymu0 [ 1 ] = rtB . nmtuh2ebbi [ 1 ] + rtB .
h0udz1lb32 [ 1 ] ; rtB . h0udz1lb32 [ 2 ] = rtP . DYN_AERO_par .
Drag_Coefficient [ 5 ] * rtB . opfb3c3zmg [ 2 ] ; rtB . lmiox3ymu0 [ 2 ] =
rtB . nmtuh2ebbi [ 2 ] + rtB . h0udz1lb32 [ 2 ] ; bq4wkncpnc ( rtB .
nlh1krt5jh2 . do5ugpkgof , & rtB . glvqkwfsgg ) ; rtB . k5tl50qmt2 = rtP .
Gain_Gain_muxufnpnzm * rtB . mrdffjtdaz + rtB . j3bgt3ayxw ; rtB . kelhke2kzj
= rtB . k5tl50qmt2 - rtP . epoch_Value ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ rtB . ik0l3bbokb = rtDW . j14ebrdltq ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . onsfiqzaxb = ( rtB . k5tl50qmt2 != rtB . ik0l3bbokb ) ; } rtB .
l0jloknu45 = rtDW . onsfiqzaxb ; rtPrevAction = rtDW . a4hao0xdt0 ; if (
ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtP .
JulianDateConversion_month_dygyg541u0 <= 2.0 ) ; rtDW . a4hao0xdt0 = rtAction
; } else { rtAction = rtDW . a4hao0xdt0 ; } if ( rtPrevAction != rtAction ) {
switch ( rtPrevAction ) { case 0 : kzauxcucvk ( rtS ) ; break ; case 1 :
eqoa5urut4 ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction
!= rtPrevAction ) { do1ujkzw1j ( rtS ) ; } oasjptnaiz ( rtP .
ECIPositiontoLLA_year_puex1wafy5 , rtP .
JulianDateConversion_month_dygyg541u0 , & mgba0laxgv , & dmu0wnvjef , & rtP .
cbthz0gwcs ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
cbthz0gwcs . j4omgsrsfr ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { mk1vmb1o52 ( rtS ) ; } ebq2is5hcr ( rtP .
ECIPositiontoLLA_year_puex1wafy5 , rtP .
JulianDateConversion_month_dygyg541u0 , & mgba0laxgv , & dmu0wnvjef ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . ku4t4kttcb . k2tbsd51jk ) ;
} break ; } nhr4ttucgq = muDoubleScalarFloor ( rtP . Gain2_Gain_inyn5mztkh *
mgba0laxgv ) ; rtB . ihrru2lok0 = ( ( ( muDoubleScalarFloor ( ( mgba0laxgv +
rtP . BiasYear_Bias_aliio05ag5 ) * rtP . Gain_Gain_at2pdfq0hn ) +
muDoubleScalarFloor ( ( dmu0wnvjef + rtP . Bias1_Bias_lbt1eqslp3 ) * rtP .
Gain1_Gain_ioogsj5ido ) ) + rtP . Bias2_Bias_loapkssk0r ) - nhr4ttucgq ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_n3ofo4trun * nhr4ttucgq ) ; } rtB .
gomgada3tp = ssGetT ( rtS ) ; rtB . jt3qqeoksu [ 0 ] = rtP .
sec2_Value_fqezgz3otg [ 0 ] ; rtB . bchm14jynu [ 0 ] = rtB . jt3qqeoksu [ 0 ]
; rtB . jt3qqeoksu [ 1 ] = rtP . sec2_Value_fqezgz3otg [ 1 ] ; rtB .
bchm14jynu [ 1 ] = rtB . jt3qqeoksu [ 1 ] ; rtB . jt3qqeoksu [ 2 ] = rtP .
sec2_Value_fqezgz3otg [ 2 ] ; rtB . bchm14jynu [ 2 ] = rtB . jt3qqeoksu [ 2 ]
; rtB . jt3qqeoksu [ 3 ] = rtP . sec2_Value_fqezgz3otg [ 3 ] ; rtB .
bchm14jynu [ 3 ] = rtB . jt3qqeoksu [ 3 ] ; rtB . bchm14jynu [ ( int32_T )
rtP . Index_Value_n204t4hl2h - 1 ] = rtB . gomgada3tp ; rtB . oeonbo5wiu [ 0
] = rtP . JulianDateConversion_day_as4zhjks20 + rtB . bchm14jynu [ 0 ] ; rtB
. oeonbo5wiu [ 1 ] = rtP . ECIPositiontoLLA_hour_hxz4j5ftiz + rtB .
bchm14jynu [ 1 ] ; rtB . oeonbo5wiu [ 2 ] = rtP .
ECIPositiontoLLA_min_b32vidcx4h + rtB . bchm14jynu [ 2 ] ; rtB . oeonbo5wiu [
3 ] = rtP . JulianDateConversion_sec_gdeswoz3p0 + rtB . bchm14jynu [ 3 ] ;
rtB . jcwv54bt5g = rtB . ihrru2lok0 + rtB . oeonbo5wiu [ 0 ] ; rtB .
givjyfbihc = rtB . jcwv54bt5g + rtP . BiasDay_Bias_kx23oa5fos ; rtB .
mzs0l31kl4 = rtP . Gain5_Gain_ilan1xzgqo * rtB . oeonbo5wiu [ 2 ] ; rtB .
fh4044woqy = rtP . Gain6_Gain_ak51j1uaxi * rtB . oeonbo5wiu [ 3 ] ; rtB .
fvqajiieaf = ( rtB . oeonbo5wiu [ 1 ] + rtB . mzs0l31kl4 ) + rtB . fh4044woqy
; rtB . ojgkh1ufyo = rtP . Gain4_Gain_mg3e432ign * rtB . fvqajiieaf ; rtB .
bpi5ji4ru4 = rtB . givjyfbihc + rtB . ojgkh1ufyo ; rtB . dijekv3sgz = rtB .
bpi5ji4ru4 + rtB . je3saqysdi ; rtB . db2rrc0lim = rtB . dijekv3sgz + rtP .
Bias1_Bias_mxqwso2h41 ; rtB . bjskyfp2d2 = rtP . Gain_Gain_dt3fpswwfk * rtB .
db2rrc0lim ; rtB . iyjspgwu2k = rtP . Gain_Gain_m1qcgs5t0k * rtB . bjskyfp2d2
; rtB . llimplwwny [ 0 ] = 0.017453292519943295 * rtB . iyjspgwu2k ; rtB .
llimplwwny [ 1 ] = rtB . ftmbjsdwjt [ 0 ] ; rtB . llimplwwny [ 2 ] = rtB .
ftmbjsdwjt [ 1 ] ; muDoubleScalarSinCos ( rtB . llimplwwny [ 0 ] , &
nhr4ttucgq , & bptigujyyv [ 0 ] ) ; muDoubleScalarSinCos ( rtB . llimplwwny [
1 ] , & fuciomtlqo , & bptigujyyv [ 1 ] ) ; muDoubleScalarSinCos ( rtB .
llimplwwny [ 2 ] , & inttemp , & bptigujyyv [ 2 ] ) ; rtB . ibcdw3x2ct [ 0 ]
= bptigujyyv [ 1 ] * bptigujyyv [ 0 ] ; rtB . ibcdw3x2ct [ 1 ] = inttemp *
fuciomtlqo * bptigujyyv [ 0 ] - bptigujyyv [ 2 ] * nhr4ttucgq ; rtB .
ibcdw3x2ct [ 2 ] = bptigujyyv [ 2 ] * fuciomtlqo * bptigujyyv [ 0 ] + inttemp
* nhr4ttucgq ; rtB . ibcdw3x2ct [ 3 ] = bptigujyyv [ 1 ] * nhr4ttucgq ; rtB .
ibcdw3x2ct [ 4 ] = inttemp * fuciomtlqo * nhr4ttucgq + bptigujyyv [ 2 ] *
bptigujyyv [ 0 ] ; rtB . ibcdw3x2ct [ 5 ] = bptigujyyv [ 2 ] * fuciomtlqo *
nhr4ttucgq - inttemp * bptigujyyv [ 0 ] ; rtB . ibcdw3x2ct [ 6 ] = -
fuciomtlqo ; rtB . ibcdw3x2ct [ 7 ] = inttemp * bptigujyyv [ 1 ] ; rtB .
ibcdw3x2ct [ 8 ] = bptigujyyv [ 2 ] * bptigujyyv [ 1 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { rtPrevAction = rtDW . hvtie0034r ; if ( ssIsMajorTimeStep (
rtS ) ) { rtAction = ( int8_T ) ! ( rtP .
JulianDateConversion_month_jjko0tg2mn <= 2.0 ) ; rtDW . hvtie0034r = rtAction
; } else { rtAction = rtDW . hvtie0034r ; } if ( rtPrevAction != rtAction ) {
switch ( rtPrevAction ) { case 0 : kzauxcucvk ( rtS ) ; break ; case 1 :
eqoa5urut4 ( rtS ) ; break ; } } switch ( rtAction ) { case 0 : if ( rtAction
!= rtPrevAction ) { do1ujkzw1j ( rtS ) ; } oasjptnaiz ( rtP .
ECIPositiontoLLA_year_puex1wafy5 , rtP .
JulianDateConversion_month_jjko0tg2mn , & p1mmpiyz5w , & iex4qysaug , & rtP .
lwyp5so3rz ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
lwyp5so3rz . j4omgsrsfr ) ; } break ; case 1 : if ( rtAction != rtPrevAction
) { mk1vmb1o52 ( rtS ) ; } ebq2is5hcr ( rtP .
ECIPositiontoLLA_year_puex1wafy5 , rtP .
JulianDateConversion_month_jjko0tg2mn , & p1mmpiyz5w , & iex4qysaug ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . nw3ycnua5h . k2tbsd51jk ) ;
} break ; } nhr4ttucgq = muDoubleScalarFloor ( rtP . Gain2_Gain_ncg4ehfczr *
p1mmpiyz5w ) ; rtB . b5owf0343w = ( ( ( muDoubleScalarFloor ( ( p1mmpiyz5w +
rtP . BiasYear_Bias_brnbdy2n1d ) * rtP . Gain_Gain_dkcretjodz ) +
muDoubleScalarFloor ( ( iex4qysaug + rtP . Bias1_Bias_mil2ojwnu2 ) * rtP .
Gain1_Gain_o50kjiguet ) ) + rtP . Bias2_Bias_ecpwnq22vr ) - nhr4ttucgq ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_i00ghwtvfa * nhr4ttucgq ) ; } rtB .
lwpxz30c2m [ 0 ] = rtP . sec2_Value_b0uh2kaims [ 0 ] ; rtB . plrbsgnpf3 [ 0 ]
= rtB . lwpxz30c2m [ 0 ] ; rtB . lwpxz30c2m [ 1 ] = rtP .
sec2_Value_b0uh2kaims [ 1 ] ; rtB . plrbsgnpf3 [ 1 ] = rtB . lwpxz30c2m [ 1 ]
; rtB . lwpxz30c2m [ 2 ] = rtP . sec2_Value_b0uh2kaims [ 2 ] ; rtB .
plrbsgnpf3 [ 2 ] = rtB . lwpxz30c2m [ 2 ] ; rtB . lwpxz30c2m [ 3 ] = rtP .
sec2_Value_b0uh2kaims [ 3 ] ; rtB . plrbsgnpf3 [ 3 ] = rtB . lwpxz30c2m [ 3 ]
; rtB . plrbsgnpf3 [ ( int32_T ) rtP . Index_Value_h3h5j0d243 - 1 ] = rtB .
gomgada3tp ; rtB . a5fkzjoruy [ 0 ] = rtP .
JulianDateConversion_day_b3uyqw452t + rtB . plrbsgnpf3 [ 0 ] ; rtB .
a5fkzjoruy [ 1 ] = rtP . ECIPositiontoLLA_hour_hxz4j5ftiz + rtB . plrbsgnpf3
[ 1 ] ; rtB . a5fkzjoruy [ 2 ] = rtP . ECIPositiontoLLA_min_b32vidcx4h + rtB
. plrbsgnpf3 [ 2 ] ; rtB . a5fkzjoruy [ 3 ] = rtP .
JulianDateConversion_sec_ipkurkj5eg + rtB . plrbsgnpf3 [ 3 ] ; rtB .
adk4hpyanr = rtB . b5owf0343w + rtB . a5fkzjoruy [ 0 ] ; rtB . n52wovcqpw =
rtB . adk4hpyanr + rtP . BiasDay_Bias_l15sc5nzd1 ; rtB . oz3sdgz4se = rtP .
Gain5_Gain_nf1m5uawcw * rtB . a5fkzjoruy [ 2 ] ; rtB . jkjdxfb5pu = rtP .
Gain6_Gain_ktkaikrz20 * rtB . a5fkzjoruy [ 3 ] ; rtB . gkxtpmrveh = ( rtB .
a5fkzjoruy [ 1 ] + rtB . oz3sdgz4se ) + rtB . jkjdxfb5pu ; rtB . mh5r3c5rbk =
rtP . Gain4_Gain_bvjyiveudp * rtB . gkxtpmrveh ; rtB . cpzufd55v4 = rtB .
n52wovcqpw + rtB . mh5r3c5rbk ; rtB . kjh05ehjak = rtB . cpzufd55v4 + rtB .
bkdmnk0pty ; rtB . kgspknbz4q = rtB . kjh05ehjak + rtP . Bias_Bias_czbwtteptn
; rtB . l0spyqlnju = muDoubleScalarMod ( rtB . kgspknbz4q , rtP .
Constant_Value_ozxjypgv2m ) + rtP . Bias1_Bias_dtaubxtyxe ; rtB . f4xismy11n
= rtP . Gain_Gain_eoz4cwquy4 * rtB . kgspknbz4q ; rtB . cvgtcoepc0 = rtB .
l0spyqlnju + rtB . f4xismy11n ; rtB . or0rtimhyl = rtP .
Gain1_Gain_kz5th20k0g * rtB . cvgtcoepc0 ; rtB . d2rz3rfikp [ 0 ] =
muDoubleScalarMod ( rtB . or0rtimhyl , rtP . Constant_Value_bdzjiale0j ) ;
rtB . d2rz3rfikp [ 1 ] = rtP . Constant1_Value_d3hr30tnd3 [ 0 ] ; rtB .
d2rz3rfikp [ 2 ] = rtP . Constant1_Value_d3hr30tnd3 [ 1 ] ;
muDoubleScalarSinCos ( rtB . d2rz3rfikp [ 0 ] , & nhr4ttucgq , & bptigujyyv [
0 ] ) ; muDoubleScalarSinCos ( rtB . d2rz3rfikp [ 1 ] , & fuciomtlqo , &
bptigujyyv [ 1 ] ) ; muDoubleScalarSinCos ( rtB . d2rz3rfikp [ 2 ] , &
inttemp , & bptigujyyv [ 2 ] ) ; rtB . ghml2vzc1i [ 0 ] = bptigujyyv [ 1 ] *
bptigujyyv [ 0 ] ; rtB . ghml2vzc1i [ 1 ] = inttemp * fuciomtlqo * bptigujyyv
[ 0 ] - bptigujyyv [ 2 ] * nhr4ttucgq ; rtB . ghml2vzc1i [ 2 ] = bptigujyyv [
2 ] * fuciomtlqo * bptigujyyv [ 0 ] + inttemp * nhr4ttucgq ; rtB . ghml2vzc1i
[ 3 ] = bptigujyyv [ 1 ] * nhr4ttucgq ; rtB . ghml2vzc1i [ 4 ] = inttemp *
fuciomtlqo * nhr4ttucgq + bptigujyyv [ 2 ] * bptigujyyv [ 0 ] ; rtB .
ghml2vzc1i [ 5 ] = bptigujyyv [ 2 ] * fuciomtlqo * nhr4ttucgq - inttemp *
bptigujyyv [ 0 ] ; rtB . ghml2vzc1i [ 6 ] = - fuciomtlqo ; rtB . ghml2vzc1i [
7 ] = inttemp * bptigujyyv [ 1 ] ; rtB . ghml2vzc1i [ 8 ] = bptigujyyv [ 2 ]
* bptigujyyv [ 1 ] ; rtB . ptvwzl42uo = rtP . Y0_Coefs_j4edtdbmce [ 0 ] ; for
( s207_iter = 0 ; s207_iter < 5 ; s207_iter ++ ) { rtB . ptvwzl42uo = rtB .
ptvwzl42uo * rtB . bjskyfp2d2 + rtP . Y0_Coefs_j4edtdbmce [ s207_iter + 1 ] ;
} for ( i = 0 ; i < 277 ; i ++ ) { rtB . exvdt03ija [ i ] = rtP .
Constant2_Value_fzij21kslz [ i ] ; rtB . dlix0rrcbv [ i ] = rtB . bjskyfp2d2
; } rtB . e04iqkf4nx = rtB . bjskyfp2d2 * rtB . bjskyfp2d2 ; for ( i = 0 ; i
< 30 ; i ++ ) { rtB . gpwnegfrzn [ i ] = rtP . Constant3_Value_i3i3sbnskz [ i
] ; rtB . ooe1dsmblv [ i ] = rtB . e04iqkf4nx ; } rtB . kpn540m4nj = rtB .
e04iqkf4nx * rtB . bjskyfp2d2 ; rtB . nxwznbqhbl = rtB . kpn540m4nj * rtB .
bjskyfp2d2 ; rtB . hi1gg5qnn1 = rtP . mMoon_Coefs_fhtgxhqslm [ 0 ] ; rtB .
jffr4vztjz = rtP . mSun_Coefs_k5qfpcaq4v [ 0 ] ; rtB . cmkynrmz0q = rtP .
umMoon_Coefs_k1lhkptrx0 [ 0 ] ; rtB . lkciksoosk = rtP .
dSun_Coefs_mr3dhrfpf4 [ 0 ] ; rtB . od3egvwk5i = rtP .
omegaMoon_Coefs_phytzpyn2y [ 0 ] ; rtB . hi1gg5qnn1 = rtB . hi1gg5qnn1 * rtB
. bjskyfp2d2 + rtP . mMoon_Coefs_fhtgxhqslm [ 1 ] ; rtB . jffr4vztjz = rtB .
jffr4vztjz * rtB . bjskyfp2d2 + rtP . mSun_Coefs_k5qfpcaq4v [ 1 ] ; rtB .
cmkynrmz0q = rtB . cmkynrmz0q * rtB . bjskyfp2d2 + rtP .
umMoon_Coefs_k1lhkptrx0 [ 1 ] ; rtB . lkciksoosk = rtB . lkciksoosk * rtB .
bjskyfp2d2 + rtP . dSun_Coefs_mr3dhrfpf4 [ 1 ] ; rtB . od3egvwk5i = rtB .
od3egvwk5i * rtB . bjskyfp2d2 + rtP . omegaMoon_Coefs_phytzpyn2y [ 1 ] ; rtB
. hi1gg5qnn1 = rtB . hi1gg5qnn1 * rtB . bjskyfp2d2 + rtP .
mMoon_Coefs_fhtgxhqslm [ 2 ] ; rtB . jffr4vztjz = rtB . jffr4vztjz * rtB .
bjskyfp2d2 + rtP . mSun_Coefs_k5qfpcaq4v [ 2 ] ; rtB . cmkynrmz0q = rtB .
cmkynrmz0q * rtB . bjskyfp2d2 + rtP . umMoon_Coefs_k1lhkptrx0 [ 2 ] ; rtB .
lkciksoosk = rtB . lkciksoosk * rtB . bjskyfp2d2 + rtP .
dSun_Coefs_mr3dhrfpf4 [ 2 ] ; rtB . od3egvwk5i = rtB . od3egvwk5i * rtB .
bjskyfp2d2 + rtP . omegaMoon_Coefs_phytzpyn2y [ 2 ] ; rtB . hi1gg5qnn1 = rtB
. hi1gg5qnn1 * rtB . bjskyfp2d2 + rtP . mMoon_Coefs_fhtgxhqslm [ 3 ] ; rtB .
jffr4vztjz = rtB . jffr4vztjz * rtB . bjskyfp2d2 + rtP .
mSun_Coefs_k5qfpcaq4v [ 3 ] ; rtB . cmkynrmz0q = rtB . cmkynrmz0q * rtB .
bjskyfp2d2 + rtP . umMoon_Coefs_k1lhkptrx0 [ 3 ] ; rtB . lkciksoosk = rtB .
lkciksoosk * rtB . bjskyfp2d2 + rtP . dSun_Coefs_mr3dhrfpf4 [ 3 ] ; rtB .
od3egvwk5i = rtB . od3egvwk5i * rtB . bjskyfp2d2 + rtP .
omegaMoon_Coefs_phytzpyn2y [ 3 ] ; rtB . hi1gg5qnn1 = rtB . hi1gg5qnn1 * rtB
. bjskyfp2d2 + rtP . mMoon_Coefs_fhtgxhqslm [ 4 ] ; rtB . jffr4vztjz = rtB .
jffr4vztjz * rtB . bjskyfp2d2 + rtP . mSun_Coefs_k5qfpcaq4v [ 4 ] ; rtB .
cmkynrmz0q = rtB . cmkynrmz0q * rtB . bjskyfp2d2 + rtP .
umMoon_Coefs_k1lhkptrx0 [ 4 ] ; rtB . lkciksoosk = rtB . lkciksoosk * rtB .
bjskyfp2d2 + rtP . dSun_Coefs_mr3dhrfpf4 [ 4 ] ; rtB . od3egvwk5i = rtB .
od3egvwk5i * rtB . bjskyfp2d2 + rtP . omegaMoon_Coefs_phytzpyn2y [ 4 ] ; rtB
. hcdnpgpsx3 [ 0 ] = rtP . Gain_Gain_iqbwobzmbk * rtB . hi1gg5qnn1 ; rtB .
hcdnpgpsx3 [ 1 ] = rtP . Gain_Gain_iqbwobzmbk * rtB . jffr4vztjz ; rtB .
hcdnpgpsx3 [ 2 ] = rtP . Gain_Gain_iqbwobzmbk * rtB . cmkynrmz0q ; rtB .
hcdnpgpsx3 [ 3 ] = rtP . Gain_Gain_iqbwobzmbk * rtB . lkciksoosk ; rtB .
hcdnpgpsx3 [ 4 ] = rtP . Gain_Gain_iqbwobzmbk * rtB . od3egvwk5i ; rtB .
hlxfhbo13t = rtP . lMercury_Coefs_m5snryadyd [ 0 ] ; rtB . hlxfhbo13t = rtB .
hlxfhbo13t * rtB . bjskyfp2d2 + rtP . lMercury_Coefs_m5snryadyd [ 1 ] ; rtB .
hcgycykbvb = rtP . lVenus_Coefs_odwx0v3t1k [ 0 ] ; rtB . hcgycykbvb = rtB .
hcgycykbvb * rtB . bjskyfp2d2 + rtP . lVenus_Coefs_odwx0v3t1k [ 1 ] ; rtB .
p4zzzpfwuc = rtP . lEarth_Coefs_e2uao4qeak [ 0 ] ; rtB . p4zzzpfwuc = rtB .
p4zzzpfwuc * rtB . bjskyfp2d2 + rtP . lEarth_Coefs_e2uao4qeak [ 1 ] ; rtB .
nsr33ghlnl = rtP . lMars_Coefs_fxog3atqyg [ 0 ] ; rtB . nsr33ghlnl = rtB .
nsr33ghlnl * rtB . bjskyfp2d2 + rtP . lMars_Coefs_fxog3atqyg [ 1 ] ; rtB .
jslmljr52n = rtP . lJupiter_Coefs_kshyeufjur [ 0 ] ; rtB . jslmljr52n = rtB .
jslmljr52n * rtB . bjskyfp2d2 + rtP . lJupiter_Coefs_kshyeufjur [ 1 ] ; rtB .
cfuz5azyhs = rtP . lSaturn_Coefs_fnnhe3ezq1 [ 0 ] ; rtB . cfuz5azyhs = rtB .
cfuz5azyhs * rtB . bjskyfp2d2 + rtP . lSaturn_Coefs_fnnhe3ezq1 [ 1 ] ; rtB .
bp5zla3buu = rtP . lUranus_Coefs_lk0nrkh0ol [ 0 ] ; rtB . bp5zla3buu = rtB .
bp5zla3buu * rtB . bjskyfp2d2 + rtP . lUranus_Coefs_lk0nrkh0ol [ 1 ] ; rtB .
dx4y0dpyzb = rtP . lNeptune_Coefs_owth3gnsft [ 0 ] ; rtB . dx4y0dpyzb = rtB .
dx4y0dpyzb * rtB . bjskyfp2d2 + rtP . lNeptune_Coefs_owth3gnsft [ 1 ] ; rtB .
ggnfhqi10o = rtP . pa_Coefs_db5dntr30p [ 0 ] ; rtB . ggnfhqi10o = rtB .
ggnfhqi10o * rtB . bjskyfp2d2 + rtP . pa_Coefs_db5dntr30p [ 1 ] ; rtB .
ggnfhqi10o = rtB . ggnfhqi10o * rtB . bjskyfp2d2 + rtP . pa_Coefs_db5dntr30p
[ 2 ] ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . f1bb1owktv [ i ] = rtP .
Constant4_Value_l3velnslc1 [ i ] ; rtB . fko3lxf0hl [ i ] = rtB . kpn540m4nj
; rtB . o02puwzmeq [ i ] = 0.017453292519943295 * rtB . hcdnpgpsx3 [ i ] ; }
rtB . o02puwzmeq [ 5 ] = rtB . hlxfhbo13t ; rtB . o02puwzmeq [ 6 ] = rtB .
hcgycykbvb ; rtB . o02puwzmeq [ 7 ] = rtB . p4zzzpfwuc ; rtB . o02puwzmeq [ 8
] = rtB . nsr33ghlnl ; rtB . o02puwzmeq [ 9 ] = rtB . jslmljr52n ; rtB .
o02puwzmeq [ 10 ] = rtB . cfuz5azyhs ; rtB . o02puwzmeq [ 11 ] = rtB .
bp5zla3buu ; rtB . o02puwzmeq [ 12 ] = rtB . dx4y0dpyzb ; rtB . o02puwzmeq [
13 ] = rtB . ggnfhqi10o ; for ( i = 0 ; i < 14 ; i ++ ) { nxh00ek3k5 [ i ] =
muDoubleScalarMod ( rtB . o02puwzmeq [ i ] , rtP . Constant_Value_mrgcwyt01m
) ; } TRANS = 'N' ; M = 1275LL ; N = 14LL ; nhr4ttucgq = 1.0 ; LDA = 1275LL ;
INCX = 1LL ; fuciomtlqo = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , &
nhr4ttucgq , & rtB . a0dijuavlp [ 0 ] , & LDA , & nxh00ek3k5 [ 0 ] , & INCX ,
& fuciomtlqo , & rtB . b4mcjoq3pm [ 0 ] , & INCY ) ; for ( i = 0 ; i < 962 ;
i ++ ) { rtB . dxqhfqss0v [ i ] = rtP . Constant1_Value_k4qbtajenz [ i ] *
rtB . j4ooexe14u [ i ] * muDoubleScalarSin ( rtB . b4mcjoq3pm [ i ] ) ; } for
( i = 0 ; i < 277 ; i ++ ) { rtB . dxqhfqss0v [ i + 962 ] = rtB . j4ooexe14u
[ i + 962 ] * rtB . dlix0rrcbv [ i ] * muDoubleScalarSin ( rtB . b4mcjoq3pm [
i + 962 ] ) ; } for ( i = 0 ; i < 30 ; i ++ ) { rtB . dxqhfqss0v [ i + 1239 ]
= rtB . j4ooexe14u [ i + 1239 ] * rtB . ooe1dsmblv [ i ] * muDoubleScalarSin
( rtB . b4mcjoq3pm [ i + 1239 ] ) ; } for ( i = 0 ; i < 5 ; i ++ ) { rtB .
dxqhfqss0v [ i + 1269 ] = rtB . j4ooexe14u [ i + 1269 ] * rtB . fko3lxf0hl [
i ] * muDoubleScalarSin ( rtB . b4mcjoq3pm [ i + 1269 ] ) ; } rtB .
dxqhfqss0v [ 1274 ] = rtB . nxwznbqhbl * rtB . j4ooexe14u [ 1274 ] *
muDoubleScalarSin ( rtB . b4mcjoq3pm [ 1274 ] ) ; for ( i = 0 ; i < 962 ; i
++ ) { rtB . a00jzbvsry [ i ] = muDoubleScalarCos ( rtB . b4mcjoq3pm [ i ] )
* rtB . juhn3ctbqj [ i ] * rtP . Constant1_Value_k4qbtajenz [ i ] ; } for ( i
= 0 ; i < 277 ; i ++ ) { rtB . a00jzbvsry [ i + 962 ] = muDoubleScalarCos (
rtB . b4mcjoq3pm [ i + 962 ] ) * rtB . juhn3ctbqj [ i + 962 ] * rtB .
dlix0rrcbv [ i ] ; } for ( i = 0 ; i < 30 ; i ++ ) { rtB . a00jzbvsry [ i +
1239 ] = muDoubleScalarCos ( rtB . b4mcjoq3pm [ i + 1239 ] ) * rtB .
juhn3ctbqj [ i + 1239 ] * rtB . ooe1dsmblv [ i ] ; } for ( i = 0 ; i < 5 ; i
++ ) { rtB . a00jzbvsry [ i + 1269 ] = muDoubleScalarCos ( rtB . b4mcjoq3pm [
i + 1269 ] ) * rtB . juhn3ctbqj [ i + 1269 ] * rtB . fko3lxf0hl [ i ] ; } rtB
. a00jzbvsry [ 1274 ] = muDoubleScalarCos ( rtB . b4mcjoq3pm [ 1274 ] ) * rtB
. juhn3ctbqj [ 1274 ] * rtB . nxwznbqhbl ; nhr4ttucgq = - 0.0 ; for ( i = 0 ;
i < 1275 ; i ++ ) { rtB . eba3zreb1v [ i ] = rtB . dxqhfqss0v [ i ] + rtB .
a00jzbvsry [ i ] ; nhr4ttucgq += rtB . eba3zreb1v [ i ] ; } rtB . cvgoybhrct
= nhr4ttucgq ; rtB . jussrigxo5 = rtB . ptvwzl42uo + rtB . cvgoybhrct ; rtB .
objuddsoqo = rtP . Gain4_Gain_oppsulm5sy * rtB . jussrigxo5 ; rtB .
n00asbe0cr = 0.017453292519943295 * rtB . objuddsoqo ; rtB . ggzhenojhj = rtP
. X0_Coefs_e20wt0lj1b [ 0 ] ; for ( s207_iter = 0 ; s207_iter < 5 ; s207_iter
++ ) { rtB . ggzhenojhj = rtB . ggzhenojhj * rtB . bjskyfp2d2 + rtP .
X0_Coefs_e20wt0lj1b [ s207_iter + 1 ] ; } for ( i = 0 ; i < 253 ; i ++ ) {
rtB . ksl4bwwthm [ i ] = rtP . Constant2_Value_nyqacrfyzs [ i ] ; rtB .
j4sa44oemc [ i ] = rtB . bjskyfp2d2 ; } rtB . j1ddyrfz02 = rtB . bjskyfp2d2 *
rtB . bjskyfp2d2 ; for ( i = 0 ; i < 36 ; i ++ ) { rtB . puj5ufcgar [ i ] =
rtP . Constant3_Value_idwt3uxkw3 [ i ] ; rtB . h14ca55sib [ i ] = rtB .
j1ddyrfz02 ; } rtB . o5ociv4loy = rtB . j1ddyrfz02 * rtB . bjskyfp2d2 ; rtB .
jw50knhr32 [ 0 ] = rtP . Constant4_Value_eeff0ovks2 [ 0 ] ; rtB . h4qpwqrsbp
[ 0 ] = rtB . o5ociv4loy ; rtB . jw50knhr32 [ 1 ] = rtP .
Constant4_Value_eeff0ovks2 [ 1 ] ; rtB . h4qpwqrsbp [ 1 ] = rtB . o5ociv4loy
; rtB . jw50knhr32 [ 2 ] = rtP . Constant4_Value_eeff0ovks2 [ 2 ] ; rtB .
h4qpwqrsbp [ 2 ] = rtB . o5ociv4loy ; rtB . jw50knhr32 [ 3 ] = rtP .
Constant4_Value_eeff0ovks2 [ 3 ] ; rtB . h4qpwqrsbp [ 3 ] = rtB . o5ociv4loy
; rtB . hk5ddbrna2 = rtB . o5ociv4loy * rtB . bjskyfp2d2 ; TRANS = 'N' ; M =
1600LL ; N = 14LL ; nhr4ttucgq = 1.0 ; LDA = 1600LL ; INCX = 1LL ; fuciomtlqo
= 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , & nhr4ttucgq , & rtB .
eygirkdnjo [ 0 ] , & LDA , & nxh00ek3k5 [ 0 ] , & INCX , & fuciomtlqo , & rtB
. l20wnp13pi [ 0 ] , & INCY ) ; for ( i = 0 ; i < 1306 ; i ++ ) { rtB .
gilhtaxxr4 [ i ] = rtP . Constant1_Value_a0dc2utvkp [ i ] * rtB . l5e405bn0t
[ i ] * muDoubleScalarSin ( rtB . l20wnp13pi [ i ] ) ; } for ( i = 0 ; i <
253 ; i ++ ) { rtB . gilhtaxxr4 [ i + 1306 ] = rtB . l5e405bn0t [ i + 1306 ]
* rtB . j4sa44oemc [ i ] * muDoubleScalarSin ( rtB . l20wnp13pi [ i + 1306 ]
) ; } for ( i = 0 ; i < 36 ; i ++ ) { rtB . gilhtaxxr4 [ i + 1559 ] = rtB .
l5e405bn0t [ i + 1559 ] * rtB . h14ca55sib [ i ] * muDoubleScalarSin ( rtB .
l20wnp13pi [ i + 1559 ] ) ; } rtB . gilhtaxxr4 [ 1595 ] = rtB . h4qpwqrsbp [
0 ] * rtB . l5e405bn0t [ 1595 ] * muDoubleScalarSin ( rtB . l20wnp13pi [ 1595
] ) ; rtB . gilhtaxxr4 [ 1596 ] = rtB . h4qpwqrsbp [ 1 ] * rtB . l5e405bn0t [
1596 ] * muDoubleScalarSin ( rtB . l20wnp13pi [ 1596 ] ) ; rtB . gilhtaxxr4 [
1597 ] = rtB . h4qpwqrsbp [ 2 ] * rtB . l5e405bn0t [ 1597 ] *
muDoubleScalarSin ( rtB . l20wnp13pi [ 1597 ] ) ; rtB . gilhtaxxr4 [ 1598 ] =
rtB . h4qpwqrsbp [ 3 ] * rtB . l5e405bn0t [ 1598 ] * muDoubleScalarSin ( rtB
. l20wnp13pi [ 1598 ] ) ; rtB . gilhtaxxr4 [ 1599 ] = rtB . hk5ddbrna2 * rtB
. l5e405bn0t [ 1599 ] * muDoubleScalarSin ( rtB . l20wnp13pi [ 1599 ] ) ; for
( i = 0 ; i < 1306 ; i ++ ) { rtB . mptzwf152z [ i ] = muDoubleScalarCos (
rtB . l20wnp13pi [ i ] ) * rtB . pfdallhby2 [ i ] * rtP .
Constant1_Value_a0dc2utvkp [ i ] ; } for ( i = 0 ; i < 253 ; i ++ ) { rtB .
mptzwf152z [ i + 1306 ] = muDoubleScalarCos ( rtB . l20wnp13pi [ i + 1306 ] )
* rtB . pfdallhby2 [ i + 1306 ] * rtB . j4sa44oemc [ i ] ; } for ( i = 0 ; i
< 36 ; i ++ ) { rtB . mptzwf152z [ i + 1559 ] = muDoubleScalarCos ( rtB .
l20wnp13pi [ i + 1559 ] ) * rtB . pfdallhby2 [ i + 1559 ] * rtB . h14ca55sib
[ i ] ; } rtB . mptzwf152z [ 1595 ] = muDoubleScalarCos ( rtB . l20wnp13pi [
1595 ] ) * rtB . pfdallhby2 [ 1595 ] * rtB . h4qpwqrsbp [ 0 ] ; rtB .
mptzwf152z [ 1596 ] = muDoubleScalarCos ( rtB . l20wnp13pi [ 1596 ] ) * rtB .
pfdallhby2 [ 1596 ] * rtB . h4qpwqrsbp [ 1 ] ; rtB . mptzwf152z [ 1597 ] =
muDoubleScalarCos ( rtB . l20wnp13pi [ 1597 ] ) * rtB . pfdallhby2 [ 1597 ] *
rtB . h4qpwqrsbp [ 2 ] ; rtB . mptzwf152z [ 1598 ] = muDoubleScalarCos ( rtB
. l20wnp13pi [ 1598 ] ) * rtB . pfdallhby2 [ 1598 ] * rtB . h4qpwqrsbp [ 3 ]
; rtB . mptzwf152z [ 1599 ] = muDoubleScalarCos ( rtB . l20wnp13pi [ 1599 ] )
* rtB . pfdallhby2 [ 1599 ] * rtB . hk5ddbrna2 ; nhr4ttucgq = - 0.0 ; for ( i
= 0 ; i < 1600 ; i ++ ) { rtB . krwr1yxnkb [ i ] = rtB . gilhtaxxr4 [ i ] +
rtB . mptzwf152z [ i ] ; nhr4ttucgq += rtB . krwr1yxnkb [ i ] ; } rtB .
dy4bikxriy = nhr4ttucgq ; rtB . mo4slycvom = rtB . ggzhenojhj + rtB .
dy4bikxriy ; rtB . m3xwdo0hga = rtP . Gain3_Gain_j2smucdy5e * rtB .
mo4slycvom ; rtB . owxe21jvfm = 0.017453292519943295 * rtB . m3xwdo0hga ;
inttemp = muDoubleScalarAtan2 ( rtB . n00asbe0cr , rtB . owxe21jvfm ) ; rtB .
kcof4nf0ik = rtB . owxe21jvfm * rtB . owxe21jvfm + rtB . n00asbe0cr * rtB .
n00asbe0cr ; rtB . hpubuefce4 = rtP . Constant_Value_oxv42c3du0 - rtB .
kcof4nf0ik ; rtB . e2t2weucbk = rtB . kcof4nf0ik / rtB . hpubuefce4 ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . asg4lqag0n != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . asg4lqag0n = 0 ;
} days = muDoubleScalarSqrt ( rtB . e2t2weucbk ) ; } else { if ( rtB .
e2t2weucbk < 0.0 ) { days = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtB .
e2t2weucbk ) ) ; } else { days = muDoubleScalarSqrt ( rtB . e2t2weucbk ) ; }
if ( rtB . e2t2weucbk < 0.0 ) { rtDW . asg4lqag0n = 1 ; } } rtB . h1b3wfya1d
= rtP . S0_Coefs_fabprfntsi [ 0 ] ; for ( s207_iter = 0 ; s207_iter < 5 ;
s207_iter ++ ) { rtB . h1b3wfya1d = rtB . h1b3wfya1d * rtB . bjskyfp2d2 + rtP
. S0_Coefs_fabprfntsi [ s207_iter + 1 ] ; } rtB . d2lucuzp5c [ 0 ] = rtP .
Constant2_Value_l2txdzslhh [ 0 ] ; rtB . ocfwq55xsq [ 0 ] = rtB . bjskyfp2d2
; rtB . d2lucuzp5c [ 1 ] = rtP . Constant2_Value_l2txdzslhh [ 1 ] ; rtB .
ocfwq55xsq [ 1 ] = rtB . bjskyfp2d2 ; rtB . d2lucuzp5c [ 2 ] = rtP .
Constant2_Value_l2txdzslhh [ 2 ] ; rtB . ocfwq55xsq [ 2 ] = rtB . bjskyfp2d2
; rtB . d0bf53zj5j = rtB . bjskyfp2d2 * rtB . bjskyfp2d2 ; for ( i = 0 ; i <
25 ; i ++ ) { rtB . e0whfm2h5c [ i ] = rtP . Constant3_Value_hcq30unaft [ i ]
; rtB . gw0k5m2uam [ i ] = rtB . d0bf53zj5j ; } rtB . ekkw4jo0wu = rtB .
d0bf53zj5j * rtB . bjskyfp2d2 ; rtB . k3hijpifwv [ 0 ] = rtP .
Constant4_Value_lpkraygrx1 [ 0 ] ; rtB . fva02g052r [ 0 ] = rtB . ekkw4jo0wu
; rtB . k3hijpifwv [ 1 ] = rtP . Constant4_Value_lpkraygrx1 [ 1 ] ; rtB .
fva02g052r [ 1 ] = rtB . ekkw4jo0wu ; rtB . k3hijpifwv [ 2 ] = rtP .
Constant4_Value_lpkraygrx1 [ 2 ] ; rtB . fva02g052r [ 2 ] = rtB . ekkw4jo0wu
; rtB . k3hijpifwv [ 3 ] = rtP . Constant4_Value_lpkraygrx1 [ 3 ] ; rtB .
fva02g052r [ 3 ] = rtB . ekkw4jo0wu ; rtB . icglrbob3m = rtB . ekkw4jo0wu *
rtB . bjskyfp2d2 ; for ( i = 0 ; i < 5 ; i ++ ) { rtB . fdi0wyedh2 [ i ] =
nxh00ek3k5 [ i ] ; } rtB . fdi0wyedh2 [ 5 ] = nxh00ek3k5 [ 6 ] ; rtB .
fdi0wyedh2 [ 6 ] = nxh00ek3k5 [ 7 ] ; rtB . fdi0wyedh2 [ 7 ] = nxh00ek3k5 [
13 ] ; TRANS = 'N' ; M = 66LL ; N = 8LL ; nhr4ttucgq = 1.0 ; LDA = 66LL ;
INCX = 1LL ; fuciomtlqo = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , &
nhr4ttucgq , & rtB . a4g2vzyhvm [ 0 ] , & LDA , & rtB . fdi0wyedh2 [ 0 ] , &
INCX , & fuciomtlqo , & rtB . c1at2baqh4 [ 0 ] , & INCY ) ; for ( i = 0 ; i <
33 ; i ++ ) { rtB . lq1pcb3a12 [ i ] = rtP . Constant1_Value_pcoochrvub [ i ]
* rtB . n5ozyxl2ea [ i ] * muDoubleScalarSin ( rtB . c1at2baqh4 [ i ] ) ; }
rtB . lq1pcb3a12 [ 33 ] = rtB . ocfwq55xsq [ 0 ] * rtB . n5ozyxl2ea [ 33 ] *
muDoubleScalarSin ( rtB . c1at2baqh4 [ 33 ] ) ; rtB . lq1pcb3a12 [ 34 ] = rtB
. ocfwq55xsq [ 1 ] * rtB . n5ozyxl2ea [ 34 ] * muDoubleScalarSin ( rtB .
c1at2baqh4 [ 34 ] ) ; rtB . lq1pcb3a12 [ 35 ] = rtB . ocfwq55xsq [ 2 ] * rtB
. n5ozyxl2ea [ 35 ] * muDoubleScalarSin ( rtB . c1at2baqh4 [ 35 ] ) ; for ( i
= 0 ; i < 25 ; i ++ ) { rtB . lq1pcb3a12 [ i + 36 ] = rtB . n5ozyxl2ea [ i +
36 ] * rtB . gw0k5m2uam [ i ] * muDoubleScalarSin ( rtB . c1at2baqh4 [ i + 36
] ) ; } rtB . lq1pcb3a12 [ 61 ] = rtB . fva02g052r [ 0 ] * rtB . n5ozyxl2ea [
61 ] * muDoubleScalarSin ( rtB . c1at2baqh4 [ 61 ] ) ; rtB . lq1pcb3a12 [ 62
] = rtB . fva02g052r [ 1 ] * rtB . n5ozyxl2ea [ 62 ] * muDoubleScalarSin (
rtB . c1at2baqh4 [ 62 ] ) ; rtB . lq1pcb3a12 [ 63 ] = rtB . fva02g052r [ 2 ]
* rtB . n5ozyxl2ea [ 63 ] * muDoubleScalarSin ( rtB . c1at2baqh4 [ 63 ] ) ;
rtB . lq1pcb3a12 [ 64 ] = rtB . fva02g052r [ 3 ] * rtB . n5ozyxl2ea [ 64 ] *
muDoubleScalarSin ( rtB . c1at2baqh4 [ 64 ] ) ; rtB . lq1pcb3a12 [ 65 ] = rtB
. icglrbob3m * rtB . n5ozyxl2ea [ 65 ] * muDoubleScalarSin ( rtB . c1at2baqh4
[ 65 ] ) ; for ( i = 0 ; i < 33 ; i ++ ) { rtB . p5pw32yemt [ i ] =
muDoubleScalarCos ( rtB . c1at2baqh4 [ i ] ) * rtB . hqiyhoklio [ i ] * rtP .
Constant1_Value_pcoochrvub [ i ] ; } rtB . p5pw32yemt [ 33 ] =
muDoubleScalarCos ( rtB . c1at2baqh4 [ 33 ] ) * rtB . hqiyhoklio [ 33 ] * rtB
. ocfwq55xsq [ 0 ] ; rtB . p5pw32yemt [ 34 ] = muDoubleScalarCos ( rtB .
c1at2baqh4 [ 34 ] ) * rtB . hqiyhoklio [ 34 ] * rtB . ocfwq55xsq [ 1 ] ; rtB
. p5pw32yemt [ 35 ] = muDoubleScalarCos ( rtB . c1at2baqh4 [ 35 ] ) * rtB .
hqiyhoklio [ 35 ] * rtB . ocfwq55xsq [ 2 ] ; for ( i = 0 ; i < 25 ; i ++ ) {
rtB . p5pw32yemt [ i + 36 ] = muDoubleScalarCos ( rtB . c1at2baqh4 [ i + 36 ]
) * rtB . hqiyhoklio [ i + 36 ] * rtB . gw0k5m2uam [ i ] ; } rtB . p5pw32yemt
[ 61 ] = muDoubleScalarCos ( rtB . c1at2baqh4 [ 61 ] ) * rtB . hqiyhoklio [
61 ] * rtB . fva02g052r [ 0 ] ; rtB . p5pw32yemt [ 62 ] = muDoubleScalarCos (
rtB . c1at2baqh4 [ 62 ] ) * rtB . hqiyhoklio [ 62 ] * rtB . fva02g052r [ 1 ]
; rtB . p5pw32yemt [ 63 ] = muDoubleScalarCos ( rtB . c1at2baqh4 [ 63 ] ) *
rtB . hqiyhoklio [ 63 ] * rtB . fva02g052r [ 2 ] ; rtB . p5pw32yemt [ 64 ] =
muDoubleScalarCos ( rtB . c1at2baqh4 [ 64 ] ) * rtB . hqiyhoklio [ 64 ] * rtB
. fva02g052r [ 3 ] ; rtB . p5pw32yemt [ 65 ] = muDoubleScalarCos ( rtB .
c1at2baqh4 [ 65 ] ) * rtB . hqiyhoklio [ 65 ] * rtB . icglrbob3m ; nhr4ttucgq
= - 0.0 ; for ( i = 0 ; i < 66 ; i ++ ) { rtB . dtxacc1epz [ i ] = rtB .
lq1pcb3a12 [ i ] + rtB . p5pw32yemt [ i ] ; nhr4ttucgq += rtB . dtxacc1epz [
i ] ; } rtB . kupdujq45v = nhr4ttucgq ; rtB . pc4w1nqdrk = rtB . h1b3wfya1d +
rtB . kupdujq45v ; rtB . a3loymxutw = rtP . Gain2_Gain_pjm2hegrql * rtB .
pc4w1nqdrk ; rtB . glxtjxd4tz = rtB . n00asbe0cr * rtB . owxe21jvfm ; rtB .
e2ossr2k3s = rtP . Gain5_Gain_j0ximqlaqo * rtB . glxtjxd4tz ; rtB .
n5b55f5xhn = 0.017453292519943295 * rtB . a3loymxutw - rtB . e2ossr2k3s ; rtB
. dqtv3p4m0t = rtB . n5b55f5xhn + inttemp ; rtB . eemwer0jti = rtP .
Gain1_Gain_iweoiyfcch * rtB . dqtv3p4m0t ; rtB . ntsaohnf5w [ 0 ] = inttemp ;
rtB . ntsaohnf5w [ 1 ] = muDoubleScalarAtan ( days ) ; rtB . ntsaohnf5w [ 2 ]
= rtB . eemwer0jti ; muDoubleScalarSinCos ( rtB . ntsaohnf5w [ 0 ] , &
nhr4ttucgq , & bptigujyyv [ 0 ] ) ; muDoubleScalarSinCos ( rtB . ntsaohnf5w [
1 ] , & fuciomtlqo , & bptigujyyv [ 1 ] ) ; muDoubleScalarSinCos ( rtB .
ntsaohnf5w [ 2 ] , & inttemp , & bptigujyyv [ 2 ] ) ; rtB . nhjqtovl12 [ 0 ]
= bptigujyyv [ 0 ] * bptigujyyv [ 2 ] * bptigujyyv [ 1 ] - nhr4ttucgq *
inttemp ; rtB . nhjqtovl12 [ 1 ] = - bptigujyyv [ 0 ] * bptigujyyv [ 1 ] *
inttemp - nhr4ttucgq * bptigujyyv [ 2 ] ; rtB . nhjqtovl12 [ 2 ] = bptigujyyv
[ 0 ] * fuciomtlqo ; rtB . nhjqtovl12 [ 3 ] = nhr4ttucgq * bptigujyyv [ 2 ] *
bptigujyyv [ 1 ] + bptigujyyv [ 0 ] * inttemp ; rtB . nhjqtovl12 [ 4 ] = -
nhr4ttucgq * bptigujyyv [ 1 ] * inttemp + bptigujyyv [ 0 ] * bptigujyyv [ 2 ]
; rtB . nhjqtovl12 [ 5 ] = nhr4ttucgq * fuciomtlqo ; rtB . nhjqtovl12 [ 6 ] =
- fuciomtlqo * bptigujyyv [ 2 ] ; rtB . nhjqtovl12 [ 7 ] = fuciomtlqo *
inttemp ; rtB . nhjqtovl12 [ 8 ] = bptigujyyv [ 1 ] ; for ( s207_iter = 0 ;
s207_iter < 3 ; s207_iter ++ ) { for ( s256_iter = 0 ; s256_iter < 3 ;
s256_iter ++ ) { eldb3aqjyd [ s256_iter + 3 * s207_iter ] = 0.0 ; eldb3aqjyd
[ s256_iter + 3 * s207_iter ] += rtB . nhjqtovl12 [ 3 * s207_iter ] * rtB .
ghml2vzc1i [ s256_iter ] ; eldb3aqjyd [ s256_iter + 3 * s207_iter ] += rtB .
nhjqtovl12 [ 3 * s207_iter + 1 ] * rtB . ghml2vzc1i [ s256_iter + 3 ] ;
eldb3aqjyd [ s256_iter + 3 * s207_iter ] += rtB . nhjqtovl12 [ 3 * s207_iter
+ 2 ] * rtB . ghml2vzc1i [ s256_iter + 6 ] ; } } for ( s207_iter = 0 ;
s207_iter < 3 ; s207_iter ++ ) { rtB . dzwrbcq5j0 [ s207_iter ] = 0.0 ; for (
s256_iter = 0 ; s256_iter < 3 ; s256_iter ++ ) { rtB . hb0ecjv4tk [ s207_iter
+ 3 * s256_iter ] = 0.0 ; rtB . hb0ecjv4tk [ s207_iter + 3 * s256_iter ] +=
eldb3aqjyd [ 3 * s256_iter ] * rtB . ibcdw3x2ct [ s207_iter ] ; rtB .
hb0ecjv4tk [ s207_iter + 3 * s256_iter ] += eldb3aqjyd [ 3 * s256_iter + 1 ]
* rtB . ibcdw3x2ct [ s207_iter + 3 ] ; rtB . hb0ecjv4tk [ s207_iter + 3 *
s256_iter ] += eldb3aqjyd [ 3 * s256_iter + 2 ] * rtB . ibcdw3x2ct [
s207_iter + 6 ] ; rtB . dzwrbcq5j0 [ s207_iter ] += rtB . hb0ecjv4tk [ 3 *
s256_iter + s207_iter ] * rtB . hzfvnqhqh4 [ s256_iter ] ; } } rtB .
digpgjvs5w = rtB . dzwrbcq5j0 [ 0 ] * rtB . dzwrbcq5j0 [ 0 ] ; rtB .
blg5blm30r = rtB . dzwrbcq5j0 [ 1 ] * rtB . dzwrbcq5j0 [ 1 ] ; rtB .
as5apg3ex2 = rtB . digpgjvs5w + rtB . blg5blm30r ; if ( ssIsMajorTimeStep (
rtS ) ) { if ( rtDW . gubyv1x2xq != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . gubyv1x2xq = 0 ;
} rtB . dtewnjw5oh = muDoubleScalarSqrt ( rtB . as5apg3ex2 ) ; } else { if (
rtB . as5apg3ex2 < 0.0 ) { rtB . dtewnjw5oh = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtB . as5apg3ex2 ) ) ; } else { rtB . dtewnjw5oh =
muDoubleScalarSqrt ( rtB . as5apg3ex2 ) ; } if ( rtB . as5apg3ex2 < 0.0 ) {
rtDW . gubyv1x2xq = 1 ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { mlcpngipio
( rtB . dtewnjw5oh , rtB . dzwrbcq5j0 [ 2 ] , rtB . hxuxvq3zag , rtB .
avmjjgc2jq , rtB . imfg2yay3n , rtB . b3q33e3m3g , & rtB . hdy13qwuxo , &
rtDW . hdy13qwuxo , & rtP . hdy13qwuxo ) ; } days = 57.295779513082323 * rtB
. hdy13qwuxo . pmiuvoq3bk ; temp = 57.295779513082323 * muDoubleScalarAtan2 (
rtB . dzwrbcq5j0 [ 1 ] , rtB . dzwrbcq5j0 [ 0 ] ) ; if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { muDoubleScalarSinCos ( rtB . hdy13qwuxo . pmiuvoq3bk , & rtB .
jy2zhwllxu , & rtB . fmtrkmmqhe ) ; nhr4ttucgq = rtB . jy2zhwllxu * rtB .
imfg2yay3n ; fuciomtlqo = rtP . f_Value_a0qm3q0swb - nhr4ttucgq * rtB .
jy2zhwllxu ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . fojyv4gldg != 0 )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . fojyv4gldg = 0
; } inttemp = muDoubleScalarSqrt ( fuciomtlqo ) ; } else if ( fuciomtlqo <
0.0 ) { inttemp = - muDoubleScalarSqrt ( muDoubleScalarAbs ( fuciomtlqo ) ) ;
rtDW . fojyv4gldg = 1 ; } else { inttemp = muDoubleScalarSqrt ( fuciomtlqo )
; } rtB . cs2usie1fh = rtP . Constant1_Value_o24g21izud / inttemp ; rtB .
pjgxtmydfn = nhr4ttucgq * rtB . cs2usie1fh ; } rtB . n3vsd5osmw = rtB .
dzwrbcq5j0 [ 2 ] + rtB . pjgxtmydfn ; rtB . fwnvn1evsn = rtB . jy2zhwllxu *
rtB . n3vsd5osmw ; rtB . mfp1uwxokr = rtB . fmtrkmmqhe * rtB . dtewnjw5oh ;
rtB . cz3y22ipue = ( rtB . fwnvn1evsn - rtB . cs2usie1fh ) + rtB . mfp1uwxokr
; rtB . pnkvvhogf2 [ 0 ] = days ; rtB . pnkvvhogf2 [ 1 ] = temp ; rtB .
pnkvvhogf2 [ 2 ] = rtB . cz3y22ipue ; rtB . nmpjtwlnon = rtB . pnkvvhogf2 [ 2
] ; rtB . hkurduz0au = rtB . pnkvvhogf2 [ 0 ] ; rtB . k2e4po1rpr = rtB .
pnkvvhogf2 [ 1 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . fmtbmkiyrg = rtB
. k2e4po1rpr >= rtP . u80deg_UpperSat ? 1 : rtB . k2e4po1rpr > rtP .
u80deg_LowerSat ? 0 : - 1 ; rtDW . pqbzdxzmmn = rtB . hkurduz0au >= rtP .
u0deg_UpperSat ? 1 : rtB . hkurduz0au > rtP . u0deg_LowerSat ? 0 : - 1 ; }
rtB . b32j4milfx = rtDW . fmtbmkiyrg == 1 ? rtP . u80deg_UpperSat : rtDW .
fmtbmkiyrg == - 1 ? rtP . u80deg_LowerSat : rtB . k2e4po1rpr ; rtB .
ekrc3dfwk4 = rtDW . pqbzdxzmmn == 1 ? rtP . u0deg_UpperSat : rtDW .
pqbzdxzmmn == - 1 ? rtP . u0deg_LowerSat : rtB . hkurduz0au ;
muDoubleScalarSinCos ( 0.017453292519943295 * rtB . b32j4milfx , & rtB .
elheedzzl0 [ 0 ] , & rtB . nxn4eoqw55 [ 0 ] ) ; muDoubleScalarSinCos (
0.017453292519943295 * rtB . ekrc3dfwk4 , & rtB . elheedzzl0 [ 1 ] , & rtB .
nxn4eoqw55 [ 1 ] ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . f3foywtd4b
= rtDW . mpzjv2x2qj ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . m30jrqnd0d =
( rtB . b32j4milfx != rtB . f3foywtd4b ) ; } rtB . gmdzlbahaz = rtDW .
m30jrqnd0d ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB . gmdzlbahaz ) { if
( ! rtDW . far5xhf1km ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS
) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW .
far5xhf1km = true ; } } else { if ( rtDW . far5xhf1km ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . far5xhf1km =
false ; } } } } if ( rtDW . far5xhf1km ) { rtB . jutgmhmp2z = rtB .
elheedzzl0 [ 0 ] ; rtB . jcs20b5wfh = rtB . nxn4eoqw55 [ 0 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( s256_iter = 1 ; s256_iter <= rtP .
ForIterator_IterationLimit ; s256_iter ++ ) { if ( s256_iter > rtP .
cpm1spm1_Threshold ) { days = rtDW . obcjv3kxjy [ 0 ] ; temp = rtDW .
obcjv3kxjy [ 1 ] ; } else { days = rtB . jcs20b5wfh ; temp = rtB . jutgmhmp2z
; } nhr4ttucgq = days * rtB . jutgmhmp2z + temp * rtB . jcs20b5wfh ;
fuciomtlqo = days * rtB . jcs20b5wfh - temp * rtB . jutgmhmp2z ; if (
s256_iter == 1 ) { memcpy ( & h2uwkjx5ez [ 0 ] , & rtP .
Constant_Value_hwgeqimqs5 [ 0 ] , 11U * sizeof ( real_T ) ) ; memcpy ( &
p5ik2nyru2 [ 0 ] , & rtP . Constant1_Value_h1wxj304y3 [ 0 ] , 11U * sizeof (
real_T ) ) ; } h2uwkjx5ez [ s256_iter - 1 ] = nhr4ttucgq ; p5ik2nyru2 [
s256_iter - 1 ] = fuciomtlqo ; rtDW . obcjv3kxjy [ 0 ] = fuciomtlqo ; rtDW .
obcjv3kxjy [ 1 ] = nhr4ttucgq ; } for ( i = 0 ; i < 11 ; i ++ ) { rtB .
acuo1yvmj5 [ i ] = rtP . Gain_Gain_lhdtz4jp1s * p5ik2nyru2 [ i ] ; rtB .
flj1dzerqr [ i ] = rtP . Gain1_Gain_gog3k4xq4w * h2uwkjx5ez [ i ] ; } } rtB .
pggd3p1kfa [ 0 ] = rtP . cp1_Value ; rtB . pggd3p1kfa [ 1 ] = rtB .
jcs20b5wfh ; rtB . dp5osgsbrh [ 0 ] = rtP . sp1_Value ; rtB . dp5osgsbrh [ 1
] = rtB . jutgmhmp2z ; memcpy ( & rtB . pggd3p1kfa [ 2 ] , & rtB . acuo1yvmj5
[ 0 ] , 11U * sizeof ( real_T ) ) ; memcpy ( & rtB . dp5osgsbrh [ 2 ] , & rtB
. flj1dzerqr [ 0 ] , 11U * sizeof ( real_T ) ) ; if ( ssIsMajorTimeStep ( rtS
) ) { srUpdateBC ( rtDW . d4p0jrfexh ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0
) ) { rtB . dv0v3nmzor = rtDW . p13ptnzy3r ; if ( ssIsMajorTimeStep ( rtS ) )
{ rtDW . jzhzjymezd = ( rtB . ekrc3dfwk4 != rtB . dv0v3nmzor ) ; } jawowd4hmr
= rtDW . jzhzjymezd ; } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . a5xxu4ouzd
= rtB . nmpjtwlnon >= rtP . uto1000000m_UpperSat ? 1 : rtB . nmpjtwlnon > rtP
. uto1000000m_LowerSat ? 0 : - 1 ; } rtB . birqe40e5n = rtDW . a5xxu4ouzd ==
1 ? rtP . uto1000000m_UpperSat : rtDW . a5xxu4ouzd == - 1 ? rtP .
uto1000000m_LowerSat : rtB . nmpjtwlnon ; rtB . mpmwb1rvos = rtP .
Gain_Gain_c532tabdaz * rtB . birqe40e5n ; rtB . eaidw1cpku = rtB . elheedzzl0
[ 1 ] * rtB . elheedzzl0 [ 1 ] ; rtB . ht0irk4tfp = rtB . nxn4eoqw55 [ 1 ] *
rtB . nxn4eoqw55 [ 1 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
alwtmvsmpo = rtDW . olub4b3luy ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
dcldc3j5cw = ( rtB . mpmwb1rvos != rtB . alwtmvsmpo ) ; } rtB . n0c1cwwurd =
( jawowd4hmr || rtDW . dcldc3j5cw ) ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtB . n0c1cwwurd ) { if ( ! rtDW . iubpiqse3a ) { if ( ssGetTaskTime ( rtS ,
1 ) != ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; } rtDW . iubpiqse3a = true ; } } else { if ( rtDW . iubpiqse3a ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . iubpiqse3a =
false ; } } } } if ( rtDW . iubpiqse3a ) { rtB . arzgsm2ap5 = rtB .
eaidw1cpku * rtB . eepk5vi4ia ; rtB . d2kgi00523 = rtB . c0lgenxrhk - rtB .
arzgsm2ap5 ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . klnvxdk0zo != 0 )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . klnvxdk0zo = 0
; } d31dx4tj1g = muDoubleScalarSqrt ( rtB . d2kgi00523 ) ; } else { if ( rtB
. d2kgi00523 < 0.0 ) { d31dx4tj1g = - muDoubleScalarSqrt ( muDoubleScalarAbs
( rtB . d2kgi00523 ) ) ; } else { d31dx4tj1g = muDoubleScalarSqrt ( rtB .
d2kgi00523 ) ; } if ( rtB . d2kgi00523 < 0.0 ) { rtDW . klnvxdk0zo = 1 ; } }
rtB . gshcaiqn50 = d31dx4tj1g * rtB . mpmwb1rvos ; rtB . mpmnl0a2zz = rtB .
ht0irk4tfp * rtB . c0lgenxrhk ; rtB . ln2ggwhvzq = rtB . lholmb3e4u * rtB .
eaidw1cpku ; rtB . jg34eicxwk = rtB . mpmnl0a2zz + rtB . ln2ggwhvzq ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . gqm3ezc0kt != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . gqm3ezc0kt = 0 ;
} nhr4ttucgq = muDoubleScalarSqrt ( rtB . jg34eicxwk ) ; } else { if ( rtB .
jg34eicxwk < 0.0 ) { nhr4ttucgq = - muDoubleScalarSqrt ( muDoubleScalarAbs (
rtB . jg34eicxwk ) ) ; } else { nhr4ttucgq = muDoubleScalarSqrt ( rtB .
jg34eicxwk ) ; } if ( rtB . jg34eicxwk < 0.0 ) { rtDW . gqm3ezc0kt = 1 ; } }
rtB . ha53xgy2uq = rtB . mpmwb1rvos + nhr4ttucgq ; rtB . n15a0llump = rtP .
Gain_Gain_md0oerbgpc * rtB . gshcaiqn50 ; rtB . pipw2nejuz = rtB . mpmwb1rvos
* rtB . mpmwb1rvos ; rtB . a5ywvserm5 = rtB . arvpirinaz * rtB . eaidw1cpku ;
rtB . hms0mdlueo = rtB . obqhwmks5n - rtB . a5ywvserm5 ; rtB . o0kix50z3l =
d31dx4tj1g * d31dx4tj1g ; rtB . gs1k0f4cz1 = rtB . hms0mdlueo / rtB .
o0kix50z3l ; rtB . bdk3pcqskh = ( rtB . n15a0llump + rtB . pipw2nejuz ) + rtB
. gs1k0f4cz1 ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . brol3yumog != 0
) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . brol3yumog =
0 ; } rtB . bzfp2p0tab = muDoubleScalarSqrt ( rtB . bdk3pcqskh ) ; } else {
if ( rtB . bdk3pcqskh < 0.0 ) { rtB . bzfp2p0tab = - muDoubleScalarSqrt (
muDoubleScalarAbs ( rtB . bdk3pcqskh ) ) ; } else { rtB . bzfp2p0tab =
muDoubleScalarSqrt ( rtB . bdk3pcqskh ) ; } if ( rtB . bdk3pcqskh < 0.0 ) {
rtDW . brol3yumog = 1 ; } } rtB . ff5eism403 = rtB . ha53xgy2uq / rtB .
bzfp2p0tab ; rtB . g1dfem4a45 = rtB . c0lgenxrhk + rtB . gshcaiqn50 ; rtB .
h4j3u4lsho = rtB . gshcaiqn50 + rtB . lholmb3e4u ; rtB . ouk0sd2oau = rtB .
h4j3u4lsho * rtB . h4j3u4lsho ; rtB . e2zmxl5mfm = rtB . g1dfem4a45 * rtB .
g1dfem4a45 / rtB . ouk0sd2oau ; rtB . lqv2v5iao3 = rtB . ht0irk4tfp * rtB .
e2zmxl5mfm ; rtB . c1rynmct4z = rtB . eaidw1cpku + rtB . lqv2v5iao3 ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . nde44yxft0 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . nde44yxft0 = 0 ;
} d31dx4tj1g = muDoubleScalarSqrt ( rtB . c1rynmct4z ) ; } else { if ( rtB .
c1rynmct4z < 0.0 ) { d31dx4tj1g = - muDoubleScalarSqrt ( muDoubleScalarAbs (
rtB . c1rynmct4z ) ) ; } else { d31dx4tj1g = muDoubleScalarSqrt ( rtB .
c1rynmct4z ) ; } if ( rtB . c1rynmct4z < 0.0 ) { rtDW . nde44yxft0 = 1 ; } }
rtB . e4i5mtlz0g = rtB . elheedzzl0 [ 1 ] / d31dx4tj1g ; rtB . n4mqntadxa =
rtB . bzfp2p0tab * nhr4ttucgq ; rtB . a2zv22y3vl = rtB . jgul4ugkjp / rtB .
n4mqntadxa * rtB . nxn4eoqw55 [ 1 ] * rtB . elheedzzl0 [ 1 ] ; rtB .
oipikmy4vw = rtB . e4i5mtlz0g * rtB . e4i5mtlz0g ; rtB . fhwx15i2ya = rtP .
Constant_Value_a3at3ko0th - rtB . oipikmy4vw ; if ( ssIsMajorTimeStep ( rtS )
) { if ( rtDW . pbwiaz4fg0 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . pbwiaz4fg0 = 0 ;
} rtB . gsshebwjge = muDoubleScalarSqrt ( rtB . fhwx15i2ya ) ; srUpdateBC (
rtDW . m5sp20k3wx ) ; } else { if ( rtB . fhwx15i2ya < 0.0 ) { rtB .
gsshebwjge = - muDoubleScalarSqrt ( muDoubleScalarAbs ( rtB . fhwx15i2ya ) )
; } else { rtB . gsshebwjge = muDoubleScalarSqrt ( rtB . fhwx15i2ya ) ; } if
( rtB . fhwx15i2ya < 0.0 ) { rtDW . pbwiaz4fg0 = 1 ; } } } rtB . p22qd4031z =
rtP . re_Value / rtB . bzfp2p0tab ; rtB . dd2mp1s2kq = rtB . p22qd4031z * rtB
. p22qd4031z ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . pkxcgdmvhn = rtP
. UnitDelay_InitialCondition_mllgrjaacn ; rtDW . kjg3l4zk5v [ 0 ] = rtP .
UnitDelay2_InitialCondition_iiychjgimi [ 0 ] ; rtDW . kjg3l4zk5v [ 1 ] = rtP
. UnitDelay2_InitialCondition_iiychjgimi [ 1 ] ; rtDW . kjg3l4zk5v [ 2 ] =
rtP . UnitDelay2_InitialCondition_iiychjgimi [ 2 ] ; rtDW . kjg3l4zk5v [ 3 ]
= rtP . UnitDelay2_InitialCondition_iiychjgimi [ 3 ] ; for ( s207_iter = 1 ;
s207_iter <= rtP . ForIterator_IterationLimit_axxrp1ixpm ; s207_iter ++ ) {
if ( s207_iter > rtP . arn_Threshold ) { d31dx4tj1g = rtDW . pkxcgdmvhn ; }
else { d31dx4tj1g = rtB . dd2mp1s2kq ; } nhr4ttucgq = d31dx4tj1g * rtB .
p22qd4031z ; if ( ( s207_iter < 0 ) && ( rtP . Constant_Value_ozyzchp131 <
MIN_int32_T - s207_iter ) ) { s256_iter = MIN_int32_T ; } else if ( (
s207_iter > 0 ) && ( rtP . Constant_Value_ozyzchp131 > MAX_int32_T -
s207_iter ) ) { s256_iter = MAX_int32_T ; } else { s256_iter = s207_iter +
rtP . Constant_Value_ozyzchp131 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . oor1kyyfva = rtP
. UnitDelay1_InitialCondition_e0xnht2pv2 ; rtDW . jscepyc3up = rtP .
UnitDelay3_InitialCondition ; rtDW . heflbpch1o = rtP .
UnitDelay2_InitialCondition ; rtDW . ksxubnoebg = rtP .
UnitDelay4_InitialCondition ; for ( i = 0 ; i < 6 ; i ++ ) { rtDW .
gmx32akt1l [ i ] = 1U ; } if ( s256_iter > 2147483646 ) { s256_iter =
2147483646 ; } else { if ( s256_iter < 0 ) { s256_iter = 0 ; } } for (
s215_iter = 1 ; s215_iter <= s256_iter ; s215_iter ++ ) { if ( rtP .
Constant_Value_c31cs1qspe < s215_iter - MAX_int32_T ) { qY_p = MAX_int32_T ;
} else { qY_p = s215_iter - rtP . Constant_Value_c31cs1qspe ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB . l0jloknu45 ) { if ( ! rtDW .
cxt5grgy1s ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . cxt5grgy1s =
true ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ( qY_p < 0 ) && ( rtP .
Constant1_Value_m2x0xcbmle < MIN_int32_T - qY_p ) ) { qY_e = MIN_int32_T ; }
else if ( ( qY_p > 0 ) && ( rtP . Constant1_Value_m2x0xcbmle > MAX_int32_T -
qY_p ) ) { qY_e = MAX_int32_T ; } else { qY_e = qY_p + rtP .
Constant1_Value_m2x0xcbmle ; } ppjbaqmd1e = qY_e - 1 ; if ( ( s207_iter < 0 )
&& ( rtP . Constant_Value_mxbsfvifbk < MIN_int32_T - s207_iter ) ) { i =
MIN_int32_T ; } else if ( ( s207_iter > 0 ) && ( rtP .
Constant_Value_mxbsfvifbk > MAX_int32_T - s207_iter ) ) { i = MAX_int32_T ; }
else { i = s207_iter + rtP . Constant_Value_mxbsfvifbk ; } dkseqjxisg = i - 1
; bcfumrjja4 = rtP . cdmaxdefmaxdef_Value [ 13 * dkseqjxisg + ppjbaqmd1e ] *
rtB . kelhke2kzj + rtP . cmaxdefmaxdef_Value [ 13 * dkseqjxisg + ppjbaqmd1e ]
; } if ( rtDW . gmx32akt1l [ 4 ] < 2 ) { rtDW . gmx32akt1l [ 4 ] = 2U ;
memcpy ( & rtB . j0eelvbmwd [ 0 ] , & rtDW . jbpr4falgz [ 0 ] , 169U * sizeof
( real_T ) ) ; } rtB . j0eelvbmwd [ ppjbaqmd1e + 13 * dkseqjxisg ] =
bcfumrjja4 ; if ( s207_iter > rtP . tc_old_Threshold ) { memcpy ( &
jtzddfrunm [ 0 ] , & rtDW . h5cjobt13t [ 0 ] , 169U * sizeof ( real_T ) ) ; }
else { memcpy ( & jtzddfrunm [ 0 ] , & rtP . zerosmaxdef1maxdef1_Value [ 0 ]
, 169U * sizeof ( real_T ) ) ; } rtPrevAction = rtDW . a1ezypvm4e ; rtAction
= ( int8_T ) ( qY_p == 0 ) ; rtDW . a1ezypvm4e = rtAction ; if ( rtPrevAction
!= rtAction ) { switch ( rtPrevAction ) { case 0 :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; case 1 :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; } } if (
rtAction == 0 ) { if ( 0 != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 )
!= ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } } if ( ( s207_iter < 0 ) && ( rtP . Constant_Value_okfmr3g0bv <
MIN_int32_T - s207_iter ) ) { i = MIN_int32_T ; } else if ( ( s207_iter > 0 )
&& ( rtP . Constant_Value_okfmr3g0bv > MAX_int32_T - s207_iter ) ) { i =
MAX_int32_T ; } else { i = s207_iter + rtP . Constant_Value_okfmr3g0bv ; }
bey410cc2p = i - 1 ; if ( rtDW . gmx32akt1l [ 5 ] < 2 ) { rtDW . gmx32akt1l [
5 ] = 2U ; memcpy ( & rtB . g1vw4aqlya [ 0 ] , & jtzddfrunm [ 0 ] , 169U *
sizeof ( real_T ) ) ; } rtB . g1vw4aqlya [ bey410cc2p + 13 * ( qY_p - 1 ) ] =
rtP . cdmaxdefmaxdef_Value [ ( qY_p - 1 ) * 13 + bey410cc2p ] * rtB .
kelhke2kzj + rtP . cmaxdefmaxdef_Value [ ( qY_p - 1 ) * 13 + bey410cc2p ] ;
for ( i = 0 ; i < 169 ; i ++ ) { rtB . hezmbi5h34 [ i ] = rtP . Gain_Gain *
rtB . g1vw4aqlya [ i ] ; } rtDW . pfulaza2sz = 4 ; } else { if ( 1 !=
rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } memcpy ( & rtB .
hezmbi5h34 [ 0 ] , & jtzddfrunm [ 0 ] , 169U * sizeof ( real_T ) ) ; rtDW .
juk5yec0yu = 4 ; } for ( i = 0 ; i < 169 ; i ++ ) { rtB . jzrcpmvzbm [ i ] =
rtB . j0eelvbmwd [ i ] + rtB . hezmbi5h34 [ i ] ; } rtDW . anrree0xau = 4 ; }
else { if ( rtDW . cxt5grgy1s ) { ssSetBlockStateForSolverChangedAtMajorStep
( rtS ) ; switch ( rtDW . a1ezypvm4e ) { case 0 :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; case 1 :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; } rtDW .
a1ezypvm4e = - 1 ; rtDW . cxt5grgy1s = false ; } } } p0axoxooci_idx_0 = (
real_T ) qY_p + rtP . Constant1_Value_hhsbgiwfw4 ; d31dx4tj1g = rtB .
pggd3p1kfa [ ( int32_T ) p0axoxooci_idx_0 - 1 ] ; p0axoxooci_idx_0 = rtB .
dp5osgsbrh [ ( int32_T ) p0axoxooci_idx_0 - 1 ] ; rtPrevAction = rtDW .
gofjuybrne ; rtAction = ( int8_T ) ( qY_p != 0 ) ; rtDW . gofjuybrne =
rtAction ; if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0
: ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; case 1 :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; } } if (
rtAction == 0 ) { if ( 0 != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 )
!= ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } } days = ( real_T ) s207_iter + rtP . Constant_Value_ojjvjervs2 ; temp =
( real_T ) qY_p + rtP . Constant_Value_ojjvjervs2 ; rtB . e1s2agf3sl = rtB .
jzrcpmvzbm [ ( ( ( int32_T ) days - 1 ) * 13 + ( int32_T ) temp ) - 1 ] *
d31dx4tj1g * rtP . Gain1_Gain ; rtB . k1dyohghpp = rtB . jzrcpmvzbm [ ( ( (
int32_T ) days - 1 ) * 13 + ( int32_T ) temp ) - 1 ] * p0axoxooci_idx_0 * rtP
. Gain2_Gain ; rtDW . lgblsj3t4q = 4 ; } else { if ( 1 != rtPrevAction ) { if
( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } fuciomtlqo = (
real_T ) s207_iter + rtP . Constant_Value_gsdkcwgkjf ; inttemp = ( real_T )
qY_p + rtP . Constant_Value_gsdkcwgkjf ; days = ( real_T ) s207_iter + rtP .
Constant_Value_ci50fad5pe ; rtB . e1s2agf3sl = rtB . jzrcpmvzbm [ ( ( (
int32_T ) fuciomtlqo - 1 ) * 13 + ( int32_T ) inttemp ) - 1 ] * d31dx4tj1g +
rtB . jzrcpmvzbm [ ( ( qY_p - 1 ) * 13 + ( int32_T ) days ) - 1 ] *
p0axoxooci_idx_0 ; rtB . k1dyohghpp = rtB . jzrcpmvzbm [ ( ( ( int32_T )
fuciomtlqo - 1 ) * 13 + ( int32_T ) inttemp ) - 1 ] * p0axoxooci_idx_0 - rtB
. jzrcpmvzbm [ ( ( qY_p - 1 ) * 13 + ( int32_T ) days ) - 1 ] * d31dx4tj1g ;
rtDW . cfsnxzglwr = 4 ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( rtB .
n0c1cwwurd ) { if ( ! rtDW . mf0i505azj ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} rtDW . mf0i505azj = true ; } memcpy ( & jtzddfrunm [ 0 ] , & rtDW .
e4yokmhfao [ 0 ] , 169U * sizeof ( real_T ) ) ; memcpy ( & a1ufdryz5x [ 0 ] ,
& rtDW . kcfi4cmlhd [ 0 ] , 169U * sizeof ( real_T ) ) ; rtPrevAction = rtDW
. lkylelnm2t ; rtAction = - 1 ; if ( s207_iter == qY_p ) { rtAction = 0 ; }
else if ( ( s207_iter == 1 ) && ( qY_p == 0 ) ) { rtAction = 1 ; } else { if
( ( s207_iter > 1 ) && ( s207_iter != qY_p ) ) { rtAction = 2 ; } } rtDW .
lkylelnm2t = rtAction ; if ( rtPrevAction != rtAction ) { switch (
rtPrevAction ) { case 0 : ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; break ; case 1 : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break
; case 2 : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; } }
switch ( rtAction ) { case 0 : if ( rtAction != rtPrevAction ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } if ( ( qY_p >= 0 )
&& ( rtP . Constant_Value_f2xoku0mnk < qY_p - MAX_int32_T ) ) { qY_e =
MAX_int32_T ; } else if ( ( qY_p < 0 ) && ( rtP . Constant_Value_f2xoku0mnk >
qY_p - MIN_int32_T ) ) { qY_e = MIN_int32_T ; } else { qY_e = qY_p - rtP .
Constant_Value_f2xoku0mnk ; } tmp_p = ( int64_T ) rtP . Gain_Gain_anntbiv2hw
* qY_e ; if ( tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if (
tmp_p < - 2147483648LL ) { tmp_p = - 2147483648LL ; } } i = ( int32_T ) tmp_p
; if ( ( s207_iter < 0 ) && ( i < MIN_int32_T - s207_iter ) ) { i =
MIN_int32_T ; } else if ( ( s207_iter > 0 ) && ( i > MAX_int32_T - s207_iter
) ) { i = MAX_int32_T ; } else { i += s207_iter ; } rtB . dumv41hbdf =
a1ufdryz5x [ i - 1 ] * rtB . gsshebwjge ; if ( ( qY_p >= 0 ) && ( rtP .
Constant_Value_f2xoku0mnk < qY_p - MAX_int32_T ) ) { qY_e = MAX_int32_T ; }
else if ( ( qY_p < 0 ) && ( rtP . Constant_Value_f2xoku0mnk > qY_p -
MIN_int32_T ) ) { qY_e = MIN_int32_T ; } else { qY_e = qY_p - rtP .
Constant_Value_f2xoku0mnk ; } tmp_p = ( int64_T ) rtP . Gain_Gain_anntbiv2hw
* qY_e ; if ( tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if (
tmp_p < - 2147483648LL ) { tmp_p = - 2147483648LL ; } } i = ( int32_T ) tmp_p
; if ( ( s207_iter < 0 ) && ( i < MIN_int32_T - s207_iter ) ) { i =
MIN_int32_T ; } else if ( ( s207_iter > 0 ) && ( i > MAX_int32_T - s207_iter
) ) { i = MAX_int32_T ; } else { i += s207_iter ; } rtB . osvuulzthg =
jtzddfrunm [ ( ( s207_iter - 1 ) * 13 + qY_p ) - 1 ] * rtB . gsshebwjge +
a1ufdryz5x [ i - 1 ] * rtB . e4i5mtlz0g ; rtDW . lwuzl0ygua = 4 ; break ;
case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} } tmp_p = ( int64_T ) rtP . Gain_Gain_h5zkzhoa3l * qY_p ; if ( tmp_p >
2147483647LL ) { tmp_p = 2147483647LL ; } else { if ( tmp_p < - 2147483648LL
) { tmp_p = - 2147483648LL ; } } i = ( int32_T ) tmp_p ; if ( ( s207_iter < 0
) && ( i < MIN_int32_T - s207_iter ) ) { i = MIN_int32_T ; } else if ( (
s207_iter > 0 ) && ( i > MAX_int32_T - s207_iter ) ) { i = MAX_int32_T ; }
else { i += s207_iter ; } rtB . dumv41hbdf = a1ufdryz5x [ i - 1 ] * rtB .
e4i5mtlz0g ; tmp_p = ( int64_T ) rtP . Gain_Gain_h5zkzhoa3l * qY_p ; if (
tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if ( tmp_p < -
2147483648LL ) { tmp_p = - 2147483648LL ; } } i = ( int32_T ) tmp_p ; if ( (
qY_p < 0 ) && ( rtP . Constant_Value_jhaknhjhno < MIN_int32_T - qY_p ) ) {
qY_e = MIN_int32_T ; } else if ( ( qY_p > 0 ) && ( rtP .
Constant_Value_jhaknhjhno > MAX_int32_T - qY_p ) ) { qY_e = MAX_int32_T ; }
else { qY_e = qY_p + rtP . Constant_Value_jhaknhjhno ; } if ( ( s207_iter < 0
) && ( i < MIN_int32_T - s207_iter ) ) { i = MIN_int32_T ; } else if ( (
s207_iter > 0 ) && ( i > MAX_int32_T - s207_iter ) ) { i = MAX_int32_T ; }
else { i += s207_iter ; } rtB . osvuulzthg = jtzddfrunm [ ( ( s207_iter - 1 )
* 13 + qY_e ) - 1 ] * rtB . e4i5mtlz0g - a1ufdryz5x [ i - 1 ] * rtB .
gsshebwjge ; rtDW . jxlgxqsvbl = 4 ; break ; case 2 : if ( rtAction !=
rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } if ( ( s207_iter < 0
) && ( rtP . Constant_Value_bwlzvps1l5 < MIN_int32_T - s207_iter ) ) { qY_e =
MIN_int32_T ; } else if ( ( s207_iter > 0 ) && ( rtP .
Constant_Value_bwlzvps1l5 > MAX_int32_T - s207_iter ) ) { qY_e = MAX_int32_T
; } else { qY_e = s207_iter + rtP . Constant_Value_bwlzvps1l5 ; } if ( ( qY_p
< 0 ) && ( rtP . Constant_Value_bwlzvps1l5 < MIN_int32_T - qY_p ) ) { qY =
MIN_int32_T ; } else if ( ( qY_p > 0 ) && ( rtP . Constant_Value_bwlzvps1l5 >
MAX_int32_T - qY_p ) ) { qY = MAX_int32_T ; } else { qY = qY_p + rtP .
Constant_Value_bwlzvps1l5 ; } tmp_p = ( int64_T ) rtP . Gain_Gain_f4ahrvji4n
* qY_p ; if ( tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if (
tmp_p < - 2147483648LL ) { tmp_p = - 2147483648LL ; } } bey410cc2p = (
int32_T ) tmp_p ; if ( ( s207_iter >= 0 ) && ( rtP .
Constant1_Value_bvd3altyqr < s207_iter - MAX_int32_T ) ) { i = MAX_int32_T ;
} else if ( ( s207_iter < 0 ) && ( rtP . Constant1_Value_bvd3altyqr >
s207_iter - MIN_int32_T ) ) { i = MIN_int32_T ; } else { i = s207_iter - rtP
. Constant1_Value_bvd3altyqr ; } if ( ( i >= qY_p ) > rtP . Switch_Threshold
) { if ( ( qY_p < 0 ) && ( rtP . Constant_Value_bwahynpith < MIN_int32_T -
qY_p ) ) { qY_i = MIN_int32_T ; } else if ( ( qY_p > 0 ) && ( rtP .
Constant_Value_bwahynpith > MAX_int32_T - qY_p ) ) { qY_i = MAX_int32_T ; }
else { qY_i = qY_p + rtP . Constant_Value_bwahynpith ; } if ( ( s207_iter >=
0 ) && ( rtP . Constant1_Value_kfgfurqslu < s207_iter - MAX_int32_T ) ) { i =
MAX_int32_T ; } else if ( ( s207_iter < 0 ) && ( rtP .
Constant1_Value_kfgfurqslu > s207_iter - MIN_int32_T ) ) { i = MIN_int32_T ;
} else { i = s207_iter - rtP . Constant1_Value_kfgfurqslu ; } d31dx4tj1g =
jtzddfrunm [ ( ( i - 1 ) * 13 + qY_i ) - 1 ] ; } else { d31dx4tj1g = rtP .
Constant_Value_kxvhj2k0q1 ; } if ( ( qY_p < 0 ) && ( rtP .
Constant_Value_bwahynpith < MIN_int32_T - qY_p ) ) { qY_i = MIN_int32_T ; }
else if ( ( qY_p > 0 ) && ( rtP . Constant_Value_bwahynpith > MAX_int32_T -
qY_p ) ) { qY_i = MAX_int32_T ; } else { qY_i = qY_p + rtP .
Constant_Value_bwahynpith ; } if ( ( s207_iter < 0 ) && ( bey410cc2p <
MIN_int32_T - s207_iter ) ) { i = MIN_int32_T ; } else if ( ( s207_iter > 0 )
&& ( bey410cc2p > MAX_int32_T - s207_iter ) ) { i = MAX_int32_T ; } else { i
= s207_iter + bey410cc2p ; } rtB . osvuulzthg = ( jtzddfrunm [ ( ( s207_iter
- 1 ) * 13 + qY_i ) - 1 ] * rtB . e4i5mtlz0g - a1ufdryz5x [ i - 1 ] * rtB .
gsshebwjge ) - rtP . k1313_Value_lpuwbdf0we [ ( ( qY_e - 1 ) * 13 + qY ) - 1
] * d31dx4tj1g ; if ( ( s207_iter >= 0 ) && ( rtP .
Constant1_Value_otjdz3c2iu < s207_iter - MAX_int32_T ) ) { i = MAX_int32_T ;
} else if ( ( s207_iter < 0 ) && ( rtP . Constant1_Value_otjdz3c2iu >
s207_iter - MIN_int32_T ) ) { i = MIN_int32_T ; } else { i = s207_iter - rtP
. Constant1_Value_otjdz3c2iu ; } if ( ( i >= qY_p ) > rtP . Switch1_Threshold
) { if ( ( s207_iter >= 0 ) && ( rtP . Constant1_Value_afnplzfoow < s207_iter
- MAX_int32_T ) ) { qY_i = MAX_int32_T ; } else if ( ( s207_iter < 0 ) && (
rtP . Constant1_Value_afnplzfoow > s207_iter - MIN_int32_T ) ) { qY_i =
MIN_int32_T ; } else { qY_i = s207_iter - rtP . Constant1_Value_afnplzfoow ;
} if ( ( qY_i < 0 ) && ( bey410cc2p < MIN_int32_T - qY_i ) ) { qY_i =
MIN_int32_T ; } else if ( ( qY_i > 0 ) && ( bey410cc2p > MAX_int32_T - qY_i )
) { qY_i = MAX_int32_T ; } else { qY_i += bey410cc2p ; } d31dx4tj1g =
a1ufdryz5x [ qY_i - 1 ] ; } else { d31dx4tj1g = rtP .
Constant1_Value_oob1ufgc1x ; } if ( ( s207_iter < 0 ) && ( bey410cc2p <
MIN_int32_T - s207_iter ) ) { i = MIN_int32_T ; } else if ( ( s207_iter > 0 )
&& ( bey410cc2p > MAX_int32_T - s207_iter ) ) { i = MAX_int32_T ; } else { i
= s207_iter + bey410cc2p ; } rtB . dumv41hbdf = a1ufdryz5x [ i - 1 ] * rtB .
e4i5mtlz0g - rtP . k1313_Value_lpuwbdf0we [ ( ( qY_e - 1 ) * 13 + qY ) - 1 ]
* d31dx4tj1g ; rtDW . hxe31sma1e = 4 ; break ; } if ( ( s207_iter < 0 ) && (
rtP . Constant_Value_bsq4tggw3b < MIN_int32_T - s207_iter ) ) { qY_e =
MIN_int32_T ; } else if ( ( s207_iter > 0 ) && ( rtP .
Constant_Value_bsq4tggw3b > MAX_int32_T - s207_iter ) ) { qY_e = MAX_int32_T
; } else { qY_e = s207_iter + rtP . Constant_Value_bsq4tggw3b ; } if ( ( qY_p
< 0 ) && ( rtP . Constant_Value_bsq4tggw3b < MIN_int32_T - qY_p ) ) { qY =
MIN_int32_T ; } else if ( ( qY_p > 0 ) && ( rtP . Constant_Value_bsq4tggw3b >
MAX_int32_T - qY_p ) ) { qY = MAX_int32_T ; } else { qY = qY_p + rtP .
Constant_Value_bsq4tggw3b ; } if ( rtDW . gmx32akt1l [ 2 ] < 2 ) { rtDW .
gmx32akt1l [ 2 ] = 2U ; memcpy ( & rtB . ozswcsd4u3 [ 0 ] , & jtzddfrunm [ 0
] , 169U * sizeof ( real_T ) ) ; } rtB . ozswcsd4u3 [ ( qY + 13 * ( qY_e - 1
) ) - 1 ] = rtB . osvuulzthg ; if ( rtDW . gmx32akt1l [ 3 ] < 2 ) { rtDW .
gmx32akt1l [ 3 ] = 2U ; memcpy ( & rtB . dihmarvgf1 [ 0 ] , & a1ufdryz5x [ 0
] , 169U * sizeof ( real_T ) ) ; } if ( ( qY >= 0 ) && ( rtP .
Constant_Value_jjv34c5bzq < qY - MAX_int32_T ) ) { qY = MAX_int32_T ; } else
if ( ( qY < 0 ) && ( rtP . Constant_Value_jjv34c5bzq > qY - MIN_int32_T ) ) {
qY = MIN_int32_T ; } else { qY -= rtP . Constant_Value_jjv34c5bzq ; } tmp_p =
( int64_T ) rtP . Gain_Gain_jpwaeoydvw * qY ; if ( tmp_p > 2147483647LL ) {
tmp_p = 2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } rtB . dihmarvgf1 [ ( qY_e + ( int32_T ) tmp_p ) - 1 ] =
rtB . dumv41hbdf ; rtDW . nyw4c2tuhv = 4 ; } else { if ( rtDW . mf0i505azj )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; switch ( rtDW .
lkylelnm2t ) { case 0 : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
break ; case 1 : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ;
case 2 : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; } rtDW
. lkylelnm2t = - 1 ; rtDW . mf0i505azj = false ; } } } if ( ( qY_p < 0 ) && (
rtP . Constant_Value_nqlsv55lik < MIN_int32_T - qY_p ) ) { qY_e = MIN_int32_T
; } else if ( ( qY_p > 0 ) && ( rtP . Constant_Value_nqlsv55lik > MAX_int32_T
- qY_p ) ) { qY_e = MAX_int32_T ; } else { qY_e = qY_p + rtP .
Constant_Value_nqlsv55lik ; } if ( ( s207_iter < 0 ) && ( rtP .
Constant_Value_nqlsv55lik < MIN_int32_T - s207_iter ) ) { i = MIN_int32_T ; }
else if ( ( s207_iter > 0 ) && ( rtP . Constant_Value_nqlsv55lik >
MAX_int32_T - s207_iter ) ) { i = MAX_int32_T ; } else { i = s207_iter + rtP
. Constant_Value_nqlsv55lik ; } d31dx4tj1g = rtB . ozswcsd4u3 [ ( ( i - 1 ) *
13 + qY_e ) - 1 ] * rtB . e1s2agf3sl * nhr4ttucgq ; if ( ( rtP .
Constant_Value_oq3ogp0hba < 0 ) && ( s207_iter < MIN_int32_T - rtP .
Constant_Value_oq3ogp0hba ) ) { qY_e = MIN_int32_T ; } else if ( ( rtP .
Constant_Value_oq3ogp0hba > 0 ) && ( s207_iter > MAX_int32_T - rtP .
Constant_Value_oq3ogp0hba ) ) { qY_e = MAX_int32_T ; } else { qY_e = rtP .
Constant_Value_oq3ogp0hba + s207_iter ; } tmp_p = ( int64_T ) rtP .
Gain_Gain_o2vpnzrawe * qY_p ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } i = ( int32_T ) tmp_p ; if ( ( qY_e < 0 ) && ( i <
MIN_int32_T - qY_e ) ) { qY_e = MIN_int32_T ; } else if ( ( qY_e > 0 ) && ( i
> MAX_int32_T - qY_e ) ) { qY_e = MAX_int32_T ; } else { qY_e += i ; } days =
rtB . dihmarvgf1 [ qY_e - 1 ] * nhr4ttucgq ; if ( ( qY_p < 0 ) && ( rtP .
Constant1_Value_i5o3wxnos4 < MIN_int32_T - qY_p ) ) { qY_e = MIN_int32_T ; }
else if ( ( qY_p > 0 ) && ( rtP . Constant1_Value_i5o3wxnos4 > MAX_int32_T -
qY_p ) ) { qY_e = MAX_int32_T ; } else { qY_e = qY_p + rtP .
Constant1_Value_i5o3wxnos4 ; } p0axoxooci_idx_0 = rtP . fm_Value [ qY_e - 1 ]
* days * rtB . k1dyohghpp ; if ( ( s207_iter < 0 ) && ( rtP .
Constant1_Value_i5o3wxnos4 < MIN_int32_T - s207_iter ) ) { i = MIN_int32_T ;
} else if ( ( s207_iter > 0 ) && ( rtP . Constant1_Value_i5o3wxnos4 >
MAX_int32_T - s207_iter ) ) { i = MAX_int32_T ; } else { i = s207_iter + rtP
. Constant1_Value_i5o3wxnos4 ; } days = rtP . fn_Value [ i - 1 ] * days * rtB
. e1s2agf3sl ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ( rtB . gsshebwjge
== rtP . Constant1_Value_c3qzhrjczc ) && ( rtP . Constant_Value_egtb2jjfml ==
qY_p ) ) { if ( ! rtDW . ieumzhiu2f ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} rtDW . ieumzhiu2f = true ; } memcpy ( & ekvqrpgybx [ 0 ] , & rtDW .
at05wcm525 [ 0 ] , 13U * sizeof ( real_T ) ) ; rtPrevAction = rtDW .
nhcu04wvy3 ; rtAction = ( int8_T ) ( s207_iter != 1 ) ; rtDW . nhcu04wvy3 =
rtAction ; if ( rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0
: ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; case 1 :
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ; } } if (
rtAction == 0 ) { if ( 0 != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 )
!= ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; } } if ( rtDW . gmx32akt1l [ 0 ] < 2 ) { rtDW . gmx32akt1l [ 0 ] = 2U ;
memcpy ( & rtB . e14uz2pq5j [ 0 ] , & ekvqrpgybx [ 0 ] , 13U * sizeof (
real_T ) ) ; } rtB . e14uz2pq5j [ ( int32_T ) ( ( real_T ) s207_iter + rtP .
Constant_Value ) - 1 ] = ekvqrpgybx [ s207_iter - 1 ] ; rtDW . p5zu1sk310 = 4
; } else { if ( 1 != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 1 ) !=
ssGetTStart ( rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
} } if ( rtDW . gmx32akt1l [ 1 ] < 2 ) { rtDW . gmx32akt1l [ 1 ] = 2U ;
memcpy ( & rtB . cvl0iqdxpn [ 0 ] , & ekvqrpgybx [ 0 ] , 13U * sizeof (
real_T ) ) ; } if ( ( s207_iter < 0 ) && ( rtP . Constant_Value_pkbx0wcdbg <
MIN_int32_T - s207_iter ) ) { i = MIN_int32_T ; } else if ( ( s207_iter > 0 )
&& ( rtP . Constant_Value_pkbx0wcdbg > MAX_int32_T - s207_iter ) ) { i =
MAX_int32_T ; } else { i = s207_iter + rtP . Constant_Value_pkbx0wcdbg ; } if
( ( qY_p < 0 ) && ( rtP . Constant_Value_n0idaqzggt < MIN_int32_T - qY_p ) )
{ qY_p = MIN_int32_T ; } else if ( ( qY_p > 0 ) && ( rtP .
Constant_Value_n0idaqzggt > MAX_int32_T - qY_p ) ) { qY_p = MAX_int32_T ; }
else { qY_p += rtP . Constant_Value_n0idaqzggt ; } if ( ( s207_iter < 0 ) &&
( rtP . Constant_Value_n0idaqzggt < MIN_int32_T - s207_iter ) ) { qY_e =
MIN_int32_T ; } else if ( ( s207_iter > 0 ) && ( rtP .
Constant_Value_n0idaqzggt > MAX_int32_T - s207_iter ) ) { qY_e = MAX_int32_T
; } else { qY_e = s207_iter + rtP . Constant_Value_n0idaqzggt ; } if ( (
s207_iter >= 0 ) && ( rtP . Constant1_Value_jfvsd5kyuk < s207_iter -
MAX_int32_T ) ) { bey410cc2p = MAX_int32_T ; } else if ( ( s207_iter < 0 ) &&
( rtP . Constant1_Value_jfvsd5kyuk > s207_iter - MIN_int32_T ) ) { bey410cc2p
= MIN_int32_T ; } else { bey410cc2p = s207_iter - rtP .
Constant1_Value_jfvsd5kyuk ; } rtB . cvl0iqdxpn [ i - 1 ] = ekvqrpgybx [
s207_iter - 1 ] * rtB . e4i5mtlz0g - rtP . k1313_Value [ ( ( qY_e - 1 ) * 13
+ qY_p ) - 1 ] * ekvqrpgybx [ bey410cc2p - 1 ] ; rtDW . mgjysjngq1 = 4 ; }
rtB . pfif2ru53r [ 0 ] = ekvqrpgybx [ 0 ] ; rtB . pfif2ru53r [ 1 ] = rtB .
e14uz2pq5j [ 1 ] ; memcpy ( & rtB . pfif2ru53r [ 2 ] , & rtB . cvl0iqdxpn [ 2
] , 11U * sizeof ( real_T ) ) ; rtB . cafvg0zdey = rtB . pfif2ru53r [ (
int32_T ) ( ( real_T ) s207_iter + rtP . Constant1_Value ) - 1 ] * nhr4ttucgq
* rtP . Constant_Value_iuv5na0ase * rtB . k1dyohghpp ; rtDW . eznk3o5xwu = 4
; } else { if ( rtDW . ieumzhiu2f ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; switch ( rtDW .
nhcu04wvy3 ) { case 0 : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
break ; case 1 : ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; break ;
} rtDW . nhcu04wvy3 = - 1 ; rtB . cafvg0zdey = rtP . bpp_Y0 ; rtDW .
ieumzhiu2f = false ; } } if ( rtDW . cxt5grgy1s ) { memcpy ( & rtDW .
jbpr4falgz [ 0 ] , & rtB . j0eelvbmwd [ 0 ] , 169U * sizeof ( real_T ) ) ;
memcpy ( & rtDW . h5cjobt13t [ 0 ] , & rtB . hezmbi5h34 [ 0 ] , 169U * sizeof
( real_T ) ) ; } if ( rtDW . mf0i505azj ) { memcpy ( & rtDW . e4yokmhfao [ 0
] , & rtB . ozswcsd4u3 [ 0 ] , 169U * sizeof ( real_T ) ) ; memcpy ( & rtDW .
kcfi4cmlhd [ 0 ] , & rtB . dihmarvgf1 [ 0 ] , 169U * sizeof ( real_T ) ) ; }
if ( rtDW . ieumzhiu2f ) { memcpy ( & rtDW . at05wcm525 [ 0 ] , & rtB .
pfif2ru53r [ 0 ] , 13U * sizeof ( real_T ) ) ; } } rtB . ctx2gmm5rx = rtDW .
oor1kyyfva - d31dx4tj1g ; rtB . bjwvgrv5ph = rtDW . jscepyc3up +
p0axoxooci_idx_0 ; rtB . cep0acxp4f = rtDW . heflbpch1o + days ; rtB .
nc2canpxds = rtDW . ksxubnoebg + rtB . cafvg0zdey ; rtDW . oor1kyyfva = rtB .
ctx2gmm5rx ; rtDW . jscepyc3up = rtB . bjwvgrv5ph ; rtDW . heflbpch1o = rtB .
cep0acxp4f ; rtDW . ksxubnoebg = rtB . nc2canpxds ; rtDW . b4mdlatzxs = 4 ; }
} rtB . awbmrd3k3c [ 0 ] = rtDW . kjg3l4zk5v [ 0 ] + rtB . ctx2gmm5rx ; rtB .
awbmrd3k3c [ 1 ] = rtDW . kjg3l4zk5v [ 1 ] + rtB . bjwvgrv5ph ; rtB .
awbmrd3k3c [ 2 ] = rtDW . kjg3l4zk5v [ 2 ] + rtB . cep0acxp4f ; rtB .
awbmrd3k3c [ 3 ] = rtDW . kjg3l4zk5v [ 3 ] + rtB . nc2canpxds ; rtDW .
pkxcgdmvhn = nhr4ttucgq ; rtDW . kjg3l4zk5v [ 0 ] = rtB . awbmrd3k3c [ 0 ] ;
rtDW . kjg3l4zk5v [ 1 ] = rtB . awbmrd3k3c [ 1 ] ; rtDW . kjg3l4zk5v [ 2 ] =
rtB . awbmrd3k3c [ 2 ] ; rtDW . kjg3l4zk5v [ 3 ] = rtB . awbmrd3k3c [ 3 ] ; }
} if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . p1fsih3dwg = ( rtB . gsshebwjge
!= 0.0 ) ; } if ( rtDW . p1fsih3dwg ) { rtB . gs0fs41pgc = rtB . awbmrd3k3c [
1 ] / rtB . gsshebwjge ; rtB . fowi1an3oi = rtB . gs0fs41pgc ; } else { rtB .
fowi1an3oi = rtB . awbmrd3k3c [ 3 ] ; } rtB . fx3ccbyxgc = rtB . ff5eism403 *
rtB . awbmrd3k3c [ 0 ] ; rtB . mcwsqdc35c = rtB . awbmrd3k3c [ 2 ] * rtB .
a2zv22y3vl ; rtB . k0yud3ty5b = ( 0.0 - rtB . fx3ccbyxgc ) - rtB . mcwsqdc35c
; bcfumrjja4 = muDoubleScalarAtan2 ( rtB . fowi1an3oi , rtB . k0yud3ty5b ) ;
rtB . b405iv50yi = rtB . a2zv22y3vl * rtB . awbmrd3k3c [ 0 ] ; rtB .
i0h1yamdil = rtB . awbmrd3k3c [ 2 ] * rtB . ff5eism403 ; rtB . ejj102e0vx =
rtB . b405iv50yi - rtB . i0h1yamdil ; rtB . olaxcbkzda = rtB . fowi1an3oi *
rtB . fowi1an3oi ; rtB . lmokjh52p3 = rtB . k0yud3ty5b * rtB . k0yud3ty5b ;
rtB . giciwpdamg = rtB . olaxcbkzda + rtB . lmokjh52p3 ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . kuwonxbzmn != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . kuwonxbzmn = 0 ;
} nhr4ttucgq = muDoubleScalarSqrt ( rtB . giciwpdamg ) ; } else { if ( rtB .
giciwpdamg < 0.0 ) { nhr4ttucgq = - muDoubleScalarSqrt ( muDoubleScalarAbs (
rtB . giciwpdamg ) ) ; } else { nhr4ttucgq = muDoubleScalarSqrt ( rtB .
giciwpdamg ) ; } if ( rtB . giciwpdamg < 0.0 ) { rtDW . kuwonxbzmn = 1 ; } }
muDoubleScalarSinCos ( 0.017453292519943295 * ( 57.295779513082323 *
bcfumrjja4 ) , & d31dx4tj1g , & p0axoxooci_idx_0 ) ; muDoubleScalarSinCos (
0.017453292519943295 * ( 57.295779513082323 * muDoubleScalarAtan2 ( rtB .
ejj102e0vx , nhr4ttucgq ) ) , & mds4tgyfhx_idx_1 , & p0axoxooci_idx_1 ) ; rtB
. gci5dtecc3 = rtB . ejj102e0vx * rtB . ejj102e0vx ; rtB . d3g3axp2rz = rtB .
gci5dtecc3 + rtB . giciwpdamg ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW
. a1xwiuwg2w != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
rtDW . a1xwiuwg2w = 0 ; } bcfumrjja4 = muDoubleScalarSqrt ( rtB . d3g3axp2rz
) ; } else { if ( rtB . d3g3axp2rz < 0.0 ) { bcfumrjja4 = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( rtB . d3g3axp2rz ) ) ; } else {
bcfumrjja4 = muDoubleScalarSqrt ( rtB . d3g3axp2rz ) ; } if ( rtB .
d3g3axp2rz < 0.0 ) { rtDW . a1xwiuwg2w = 1 ; } } rtB . m4psq12wv1 =
p0axoxooci_idx_1 * bcfumrjja4 ; rtB . bvqq5sazyw = p0axoxooci_idx_0 * rtB .
m4psq12wv1 ; rtB . d35rtk4pom = d31dx4tj1g * rtB . m4psq12wv1 ; rtB .
pdwghfu5fu = mds4tgyfhx_idx_1 * bcfumrjja4 ; rtB . lzu3uo0n3g [ 0 ] = rtP .
nTtoT_Gain * rtB . bvqq5sazyw ; rtB . lzu3uo0n3g [ 1 ] = rtP . nTtoT_Gain *
rtB . d35rtk4pom ; rtB . lzu3uo0n3g [ 2 ] = rtP . nTtoT_Gain * rtB .
pdwghfu5fu ; elrubs4mtp ( rtB . glvqkwfsgg . nm24payncx , rtB . lzu3uo0n3g ,
& rtB . f2f5asy2qj ) ; rtB . iupw2x5jk0 = rtP . nTtoT1_Gain * bcfumrjja4 ;
bq4wkncpnc ( rtB . oa2h4lycyto . jtgcw4sbk0 , & rtB . jse42y33cf ) ;
czqbc2hafp ( rtB . jse42y33cf . nm24payncx , rtP . Constant_Value_j0j5kt5zqt
, & rtB . czqbc2hafpz ) ; rtB . ibjjmy50pj [ 0 ] = rtB . czqbc2hafpz .
gzi3omxt3y [ 1 ] * rtB . f2f5asy2qj . ehs4r2hz2y [ 2 ] ; rtB . ibjjmy50pj [ 1
] = rtB . czqbc2hafpz . gzi3omxt3y [ 2 ] * rtB . f2f5asy2qj . ehs4r2hz2y [ 0
] ; rtB . ibjjmy50pj [ 2 ] = rtB . czqbc2hafpz . gzi3omxt3y [ 0 ] * rtB .
f2f5asy2qj . ehs4r2hz2y [ 1 ] ; rtB . ibjjmy50pj [ 3 ] = rtB . czqbc2hafpz .
gzi3omxt3y [ 2 ] * rtB . f2f5asy2qj . ehs4r2hz2y [ 1 ] ; rtB . ibjjmy50pj [ 4
] = rtB . czqbc2hafpz . gzi3omxt3y [ 0 ] * rtB . f2f5asy2qj . ehs4r2hz2y [ 2
] ; rtB . ibjjmy50pj [ 5 ] = rtB . czqbc2hafpz . gzi3omxt3y [ 1 ] * rtB .
f2f5asy2qj . ehs4r2hz2y [ 0 ] ; rtB . ccswgitxvj [ 0 ] = rtB . ibjjmy50pj [ 0
] - rtB . ibjjmy50pj [ 3 ] ; rtB . ccswgitxvj [ 1 ] = rtB . ibjjmy50pj [ 1 ]
- rtB . ibjjmy50pj [ 4 ] ; rtB . ccswgitxvj [ 2 ] = rtB . ibjjmy50pj [ 2 ] -
rtB . ibjjmy50pj [ 5 ] ; elrubs4mtp ( rtB . oa2h4lycyto . jtgcw4sbk0 , rtB .
ccswgitxvj , & rtB . cwkeianlye ) ; hh4puuamkn ( rtB . nlh1krt5jh2 .
do5ugpkgof , rtB . hzfvnqhqh4 , & rtB . hh4puuamknj ) ; bcfumrjja4 =
muDoubleScalarSqrt ( ( rtB . hh4puuamknj . bogcyvs5ln [ 0 ] * rtB .
hh4puuamknj . bogcyvs5ln [ 0 ] + rtB . hh4puuamknj . bogcyvs5ln [ 1 ] * rtB .
hh4puuamknj . bogcyvs5ln [ 1 ] ) + rtB . hh4puuamknj . bogcyvs5ln [ 2 ] * rtB
. hh4puuamknj . bogcyvs5ln [ 2 ] ) ; bptigujyyv [ 0 ] = rtB . hh4puuamknj .
bogcyvs5ln [ 0 ] / bcfumrjja4 ; bptigujyyv [ 1 ] = rtB . hh4puuamknj .
bogcyvs5ln [ 1 ] / bcfumrjja4 ; bptigujyyv [ 2 ] = rtB . hh4puuamknj .
bogcyvs5ln [ 2 ] / bcfumrjja4 ; bcfumrjja4 = rtP . CONSTANTS_par . mu_earth /
muDoubleScalarPower ( bcfumrjja4 , 3.0 ) * 3.0 ; eldb3aqjyd [ 0 ] =
bcfumrjja4 * 0.0 ; eldb3aqjyd [ 3 ] = bcfumrjja4 * - bptigujyyv [ 2 ] ;
eldb3aqjyd [ 6 ] = bcfumrjja4 * bptigujyyv [ 1 ] ; eldb3aqjyd [ 1 ] =
bcfumrjja4 * bptigujyyv [ 2 ] ; eldb3aqjyd [ 4 ] = bcfumrjja4 * 0.0 ;
eldb3aqjyd [ 7 ] = bcfumrjja4 * - bptigujyyv [ 0 ] ; eldb3aqjyd [ 2 ] =
bcfumrjja4 * - bptigujyyv [ 1 ] ; eldb3aqjyd [ 5 ] = bcfumrjja4 * bptigujyyv
[ 0 ] ; eldb3aqjyd [ 8 ] = bcfumrjja4 * 0.0 ; for ( s207_iter = 0 ; s207_iter
< 3 ; s207_iter ++ ) { rtB . edtfmju3qt [ s207_iter ] = 0.0 ; for ( s256_iter
= 0 ; s256_iter < 3 ; s256_iter ++ ) { eldb3aqjyd_p [ s207_iter + 3 *
s256_iter ] = 0.0 ; eldb3aqjyd_p [ s207_iter + 3 * s256_iter ] += rtP .
DYN_SC_par . inertia [ 3 * s256_iter ] * eldb3aqjyd [ s207_iter ] ;
eldb3aqjyd_p [ s207_iter + 3 * s256_iter ] += rtP . DYN_SC_par . inertia [ 3
* s256_iter + 1 ] * eldb3aqjyd [ s207_iter + 3 ] ; eldb3aqjyd_p [ s207_iter +
3 * s256_iter ] += rtP . DYN_SC_par . inertia [ 3 * s256_iter + 2 ] *
eldb3aqjyd [ s207_iter + 6 ] ; rtB . edtfmju3qt [ s207_iter ] += eldb3aqjyd_p
[ 3 * s256_iter + s207_iter ] * bptigujyyv [ s256_iter ] ; } } hh4puuamkn (
rtB . nlh1krt5jh2 . do5ugpkgof , rtB . iuykey3bat . ehs4r2hz2y , & rtB .
ep1nysc0kg ) ; rtB . pai3e3zarf [ 0 ] = rtB . ep1nysc0kg . bogcyvs5ln [ 0 ] *
rtP . DYN_SC_par . mass ; rtB . pai3e3zarf [ 1 ] = rtB . ep1nysc0kg .
bogcyvs5ln [ 1 ] * rtP . DYN_SC_par . mass ; rtB . pai3e3zarf [ 2 ] = rtB .
ep1nysc0kg . bogcyvs5ln [ 2 ] * rtP . DYN_SC_par . mass ; bq4wkncpnc ( rtB .
nlh1krt5jh2 . do5ugpkgof , & rtB . px30n50fob ) ; elrubs4mtp ( rtB .
px30n50fob . nm24payncx , rtB . pai3e3zarf , & rtB . gzjgdvz5xb ) ; rtB .
kdc5rm1ohd [ 0 ] = ( rtB . lmiox3ymu0 [ 0 ] + rtB . cwkeianlye . ehs4r2hz2y [
0 ] ) + rtB . edtfmju3qt [ 0 ] ; rtB . kdc5rm1ohd [ 1 ] = ( rtB . lmiox3ymu0
[ 1 ] + rtB . cwkeianlye . ehs4r2hz2y [ 1 ] ) + rtB . edtfmju3qt [ 1 ] ; rtB
. kdc5rm1ohd [ 2 ] = ( rtB . lmiox3ymu0 [ 2 ] + rtB . cwkeianlye . ehs4r2hz2y
[ 2 ] ) + rtB . edtfmju3qt [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if
( ssIsMajorTimeStep ( rtS ) ) { rtDW . a1m5kq3kzu = ( rtB . bk4wge0g1b < rtP
. CheckdeltaT_minmax [ 0 ] ) ; rtDW . i4ltbzqbwy = ( rtB . bk4wge0g1b > rtP .
CheckdeltaT_minmax [ 1 ] ) ; } assessmentPtrVar = ( void * ) & assessmentVar
; if ( ( ! rtDW . a1m5kq3kzu ) && ( ! rtDW . i4ltbzqbwy ) ) { assessmentVar =
0 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . k1im3nzvaa , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSW/DYN/DYN_AERO/ECI Position to LLA/Check deltaT/Assertion" , 2 ,
ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested ( rtS
, ( int ) ssGetT ( rtS ) ) ; assessmentVar = 1 ; rt_SlioAccessorUpdate ( 1 ,
3 , rtDW . k1im3nzvaa , ssGetT ( rtS ) , assessmentPtrVar ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . dv2dewa5ej = ( rtB . bk4wge0g1b < rtP .
CheckdeltaT_minmax_l5hvbzxump [ 0 ] ) ; rtDW . dhy1luj35e = ( rtB .
bk4wge0g1b > rtP . CheckdeltaT_minmax_l5hvbzxump [ 1 ] ) ; } assessmentPtrVar
= ( void * ) & assessmentVar_p ; if ( ( ! rtDW . dv2dewa5ej ) && ( ! rtDW .
dhy1luj35e ) ) { assessmentVar_p = 0 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW .
kdyvdf55ga , ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5 ,
 "TST_RWSW/DYN/DYN_AERO/ECI Position to LLA/Direction Cosine Matrix ECI to ECEF/Check deltaT/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested
( rtS , ( int ) ssGetT ( rtS ) ) ; assessmentVar_p = 1 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . kdyvdf55ga , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . cjf2rcprnb =
( rtB . bk4wge0g1b < rtP . CheckdeltaT_minmax_igedlwrre3 [ 0 ] ) ; rtDW .
g0lbtdq2uw = ( rtB . bk4wge0g1b > rtP . CheckdeltaT_minmax_igedlwrre3 [ 1 ] )
; rtDW . lmcvixutc1 = ( rtB . bk4wge0g1b < rtP .
CheckdeltaT_minmax_ccepsw5qgq [ 0 ] ) ; rtDW . knywovw04o = ( rtB .
bk4wge0g1b > rtP . CheckdeltaT_minmax_ccepsw5qgq [ 1 ] ) ; } } tmp [ 0 ] = -
0.0 ; tmp [ 4 ] = rtB . f3zlxaswiq [ 2 ] ; tmp [ 8 ] = - rtB . f3zlxaswiq [ 1
] ; tmp [ 1 ] = - rtB . f3zlxaswiq [ 2 ] ; tmp [ 5 ] = - 0.0 ; tmp [ 9 ] =
rtB . f3zlxaswiq [ 0 ] ; tmp [ 2 ] = rtB . f3zlxaswiq [ 1 ] ; tmp [ 6 ] = -
rtB . f3zlxaswiq [ 0 ] ; tmp [ 10 ] = - 0.0 ; tmp [ 12 ] = rtB . f3zlxaswiq [
0 ] ; tmp [ 3 ] = - rtB . f3zlxaswiq [ 0 ] ; tmp [ 13 ] = rtB . f3zlxaswiq [
1 ] ; tmp [ 7 ] = - rtB . f3zlxaswiq [ 1 ] ; tmp [ 14 ] = rtB . f3zlxaswiq [
2 ] ; tmp [ 11 ] = - rtB . f3zlxaswiq [ 2 ] ; tmp [ 15 ] = 0.0 ; for ( i = 0
; i < 4 ; i ++ ) { rtB . era5e4fmzn [ i ] = 0.0 ; rtB . era5e4fmzn [ i ] +=
tmp [ i ] * rtB . pwktwrqihs [ 0 ] ; rtB . era5e4fmzn [ i ] += tmp [ i + 4 ]
* rtB . pwktwrqihs [ 1 ] ; rtB . era5e4fmzn [ i ] += tmp [ i + 8 ] * rtB .
pwktwrqihs [ 2 ] ; rtB . era5e4fmzn [ i ] += tmp [ i + 12 ] * rtB .
pwktwrqihs [ 3 ] ; rtB . bnkjf4wemf [ i ] = rtP . Gain_Gain_d4wyhwnizf * rtB
. era5e4fmzn [ i ] ; } j5jrka03le ( rtB . cufcoe2lw0 , rtB . f3zlxaswiq , &
rtB . j5jrka03lep ) ; rtB . d52cu0jrec [ 0 ] = rtB . kdc5rm1ohd [ 0 ] + rtB .
j5jrka03lep . nkm03paxwo [ 0 ] ; rtB . d52cu0jrec [ 1 ] = rtB . kdc5rm1ohd [
1 ] + rtB . j5jrka03lep . nkm03paxwo [ 1 ] ; rtB . d52cu0jrec [ 2 ] = rtB .
kdc5rm1ohd [ 2 ] + rtB . j5jrka03lep . nkm03paxwo [ 2 ] ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . htejeb43jp = (
rtB . f4wdtbi41r < rtP . CheckdeltaT_minmax_nxemqbvh1w [ 0 ] ) ; rtDW .
muhrn4an4s = ( rtB . f4wdtbi41r > rtP . CheckdeltaT_minmax_nxemqbvh1w [ 1 ] )
; rtDW . avbyw4pngn = ( rtB . f4wdtbi41r < rtP .
CheckdeltaT_minmax_a2tgpuyjmr [ 0 ] ) ; rtDW . ht5wxzfvhb = ( rtB .
f4wdtbi41r > rtP . CheckdeltaT_minmax_a2tgpuyjmr [ 1 ] ) ; rtDW . njspbenauj
= ( rtB . f4wdtbi41r < rtP . CheckdeltaT_minmax_cnwv0n4cpc [ 0 ] ) ; rtDW .
hlczhahkiw = ( rtB . f4wdtbi41r > rtP . CheckdeltaT_minmax_cnwv0n4cpc [ 1 ] )
; rtDW . bdynxuedph = ( rtB . gomgada3tp < rtP .
CheckdeltaT_minmax_axwixcj3v5 [ 0 ] ) ; rtDW . jz5y5fp0m1 = ( rtB .
gomgada3tp > rtP . CheckdeltaT_minmax_axwixcj3v5 [ 1 ] ) ; } assessmentPtrVar
= ( void * ) & assessmentVar_e ; if ( ( ! rtDW . bdynxuedph ) && ( ! rtDW .
jz5y5fp0m1 ) ) { assessmentVar_e = 0 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW .
iiujy2f33w , ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSW/DYN/DYN_MAG/ECI Position to LLA/Check deltaT/Assertion" , 2 ,
ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested ( rtS
, ( int ) ssGetT ( rtS ) ) ; assessmentVar_e = 1 ; rt_SlioAccessorUpdate ( 1
, 3 , rtDW . iiujy2f33w , ssGetT ( rtS ) , assessmentPtrVar ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . e4gacfnnoi = ( rtB . gomgada3tp < rtP .
CheckdeltaT_minmax_iczlyigkah [ 0 ] ) ; rtDW . hzkby4wwto = ( rtB .
gomgada3tp > rtP . CheckdeltaT_minmax_iczlyigkah [ 1 ] ) ; } assessmentPtrVar
= ( void * ) & assessmentVar_i ; if ( ( ! rtDW . e4gacfnnoi ) && ( ! rtDW .
hzkby4wwto ) ) { assessmentVar_i = 0 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW .
fodvlcmywy , ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5 ,
 "TST_RWSW/DYN/DYN_MAG/ECI Position to LLA/Direction Cosine Matrix ECI to ECEF/Check deltaT/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested
( rtS , ( int ) ssGetT ( rtS ) ) ; assessmentVar_i = 1 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . fodvlcmywy , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . nzerztgxqu =
( rtB . gomgada3tp < rtP . CheckdeltaT_minmax_o0fimawo5l [ 0 ] ) ; rtDW .
lpbtnh0h20 = ( rtB . gomgada3tp > rtP . CheckdeltaT_minmax_o0fimawo5l [ 1 ] )
; rtDW . ktyptafnjn = ( rtB . gomgada3tp < rtP .
CheckdeltaT_minmax_cn2hd0jnck [ 0 ] ) ; rtDW . d1x4fhglbc = ( rtB .
gomgada3tp > rtP . CheckdeltaT_minmax_cn2hd0jnck [ 1 ] ) ; rtDW . a5xidqthyv
= ( rtP . CheckAltitude_min <= rtB . nmpjtwlnon ) ; rtDW . kycuklig1k = ( rtB
. nmpjtwlnon <= rtP . CheckAltitude_max ) ; } assessmentPtrVar = ( void * ) &
assessmentVar_m ; if ( rtDW . a5xidqthyv && rtDW . kycuklig1k ) {
assessmentVar_m = 0 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . jm0wxqrcug ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/Check Altitude/Assertion" , 2
, ssGetT ( rtS ) ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ;
assessmentVar_m = 1 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . jm0wxqrcug ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . danlzm034o = ( rtP . CheckLatitude_min <= rtB . hkurduz0au ) ; rtDW .
hfy3m5qgqx = ( rtB . hkurduz0au <= rtP . CheckLatitude_max ) ; }
assessmentPtrVar = ( void * ) & assessmentVar_g ; if ( rtDW . danlzm034o &&
rtDW . hfy3m5qgqx ) { assessmentVar_g = 0 ; rt_SlioAccessorUpdate ( 1 , 3 ,
rtDW . gq0nld4wdg , ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ;
diag = CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5
, "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/Check Latitude/Assertion" ,
2 , ssGetT ( rtS ) ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ;
assessmentVar_g = 1 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . gq0nld4wdg ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . mcctp5x10a = ( rtP . CheckLongitude_min <= rtB . k2e4po1rpr ) ; rtDW .
kch0bl4hze = ( rtB . k2e4po1rpr <= rtP . CheckLongitude_max ) ; }
assessmentPtrVar = ( void * ) & assessmentVar_j ; if ( rtDW . mcctp5x10a &&
rtDW . kch0bl4hze ) { assessmentVar_j = 0 ; rt_SlioAccessorUpdate ( 1 , 3 ,
rtDW . b010mugrdz , ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ;
diag = CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5
, "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/Check Longitude/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ;
assessmentVar_j = 1 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . b010mugrdz ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . jms1o03b1m = ( rtP . Istimewithinmodellimits_min <= rtB . kelhke2kzj )
; rtDW . j2aja4lihr = ( rtB . kelhke2kzj <= rtP . Istimewithinmodellimits_max
) ; } assessmentPtrVar = ( void * ) & assessmentVar_f ; if ( rtDW .
jms1o03b1m && rtDW . j2aja4lihr ) { assessmentVar_f = 0 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . epf4xhkmwj , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/Is time within model limits/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ;
assessmentVar_f = 1 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . epf4xhkmwj ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { int32_T i ; rtB . nhbdb1hyqs [ 0 ] = rtP .
DYN_AERO_par . CP_BOF [ 0 ] - rtP . DYN_AERO_par . CG_BOF [ 0 ] ; rtB .
itxjzsphm3 [ 0 ] = rtP . coefAdjust_Gain [ 0 ] * rtP . DYN_AERO_par .
Drag_Coefficient [ 0 ] ; rtB . nhbdb1hyqs [ 1 ] = rtP . DYN_AERO_par . CP_BOF
[ 1 ] - rtP . DYN_AERO_par . CG_BOF [ 1 ] ; rtB . itxjzsphm3 [ 1 ] = rtP .
coefAdjust_Gain [ 1 ] * rtP . DYN_AERO_par . Drag_Coefficient [ 1 ] ; rtB .
nhbdb1hyqs [ 2 ] = rtP . DYN_AERO_par . CP_BOF [ 2 ] - rtP . DYN_AERO_par .
CG_BOF [ 2 ] ; rtB . itxjzsphm3 [ 2 ] = rtP . coefAdjust_Gain [ 2 ] * rtP .
DYN_AERO_par . Drag_Coefficient [ 2 ] ; rtB . oodz4urbyp = ( rtP .
ECIPositiontoLLA_sec + rtP . Bias_Bias_muto2udg1i ) * rtP . secGain_Gain ;
rtB . kvg2t5qrcf = rtP . gainVal_Gain * rtP . ECIPositiontoLLA_sec ; for ( i
= 0 ; i < 8 ; i ++ ) { memcpy ( & rtB . g3a150ehbv [ i * 66 ] , & rtP .
Constant_Value_mv2kh0yrpo [ i * 66 + 198 ] , 66U * sizeof ( real_T ) ) ; }
memcpy ( & rtB . fzxfo4voq2 [ 0 ] , & rtP . Constant_Value_mv2kh0yrpo [ 66 ]
, 66U * sizeof ( real_T ) ) ; memcpy ( & rtB . gh1fvty1e2 [ 0 ] , & rtP .
Constant_Value_mv2kh0yrpo [ 132 ] , 66U * sizeof ( real_T ) ) ; for ( i = 0 ;
i < 14 ; i ++ ) { memcpy ( & rtB . nvlun450q4 [ i * 1600 ] , & rtP .
Constant_Value_bln5ascixh [ i * 1600 + 4800 ] , 1600U * sizeof ( real_T ) ) ;
} memcpy ( & rtB . mbqkewozo3 [ 0 ] , & rtP . Constant_Value_bln5ascixh [
1600 ] , 1600U * sizeof ( real_T ) ) ; memcpy ( & rtB . ily4igf2cj [ 0 ] , &
rtP . Constant_Value_bln5ascixh [ 3200 ] , 1600U * sizeof ( real_T ) ) ; for
( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB . bthtxqpdik [ i * 1275 ] , & rtP
. Constant_Value_o4yfykzqvt [ i * 1275 + 3825 ] , 1275U * sizeof ( real_T ) )
; } memcpy ( & rtB . ptev4zopsv [ 0 ] , & rtP . Constant_Value_o4yfykzqvt [
1275 ] , 1275U * sizeof ( real_T ) ) ; memcpy ( & rtB . cpq0p1komv [ 0 ] , &
rtP . Constant_Value_o4yfykzqvt [ 2550 ] , 1275U * sizeof ( real_T ) ) ; rtB
. edzfllldyc [ 0 ] = rtP . Gain1_Gain_ehl1l35w02 * 0.0 ; rtB . edzfllldyc [ 1
] = rtP . Gain1_Gain_ehl1l35w02 * 0.0 ; rtB . nifycbgi5p = rtP .
Constant_Value_eqdvpf4fte - rtP . Constant1_Value_mtln531pzy ; rtB .
hakectrr15 = rtP . Constant_Value_fe02n3dwap * rtB . nifycbgi5p ; rtB .
loketsez3q = rtP . Constant_Value_khf3n3ma2u - rtB . nifycbgi5p * rtB .
nifycbgi5p ; rtB . mmsgyz3vfm = rtB . loketsez3q / ( rtP .
Constant_Value_gl3cqlwg4c - rtB . loketsez3q ) ; rtB . lchtvpgg01 = ( ( rtP .
deltaAT_Value + rtP . DirectionCosineMatrixECItoECEF_sec ) + rtP .
Bias_Bias_gbleru4jry ) * rtP . secGain_Gain_biw3ghlj4z ; rtB . aizqp2ntxc = (
rtP . DirectionCosineMatrixECItoECEF_sec + rtP . deltaUT1_Value ) * rtP .
gainVal_Gain_loj5c3zibi ; for ( i = 0 ; i < 8 ; i ++ ) { memcpy ( & rtB .
nfidzfrt02 [ i * 66 ] , & rtP . Constant_Value_i1xx5cbvq3 [ i * 66 + 198 ] ,
66U * sizeof ( real_T ) ) ; } memcpy ( & rtB . chnbedf2rz [ 0 ] , & rtP .
Constant_Value_i1xx5cbvq3 [ 66 ] , 66U * sizeof ( real_T ) ) ; memcpy ( & rtB
. kufhg2pmkw [ 0 ] , & rtP . Constant_Value_i1xx5cbvq3 [ 132 ] , 66U * sizeof
( real_T ) ) ; for ( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB . ek1ampu0qf [
i * 1600 ] , & rtP . Constant_Value_mip0qup14w [ i * 1600 + 4800 ] , 1600U *
sizeof ( real_T ) ) ; } memcpy ( & rtB . omstdtrdeg [ 0 ] , & rtP .
Constant_Value_mip0qup14w [ 1600 ] , 1600U * sizeof ( real_T ) ) ; memcpy ( &
rtB . omav200po3 [ 0 ] , & rtP . Constant_Value_mip0qup14w [ 3200 ] , 1600U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB .
btwrco0qwd [ i * 1275 ] , & rtP . Constant_Value_ivophock2i [ i * 1275 + 3825
] , 1275U * sizeof ( real_T ) ) ; } memcpy ( & rtB . kd1rv3iov0 [ 0 ] , & rtP
. Constant_Value_ivophock2i [ 1275 ] , 1275U * sizeof ( real_T ) ) ; memcpy (
& rtB . j2dweaustf [ 0 ] , & rtP . Constant_Value_ivophock2i [ 2550 ] , 1275U
* sizeof ( real_T ) ) ; rtB . dal2neiedt [ 0 ] = rtP . Gain1_Gain_jzrkdwkcmc
* rtP . PolarMotion_Value [ 0 ] ; rtB . dal2neiedt [ 1 ] = rtP .
Gain1_Gain_jzrkdwkcmc * rtP . PolarMotion_Value [ 1 ] ; rtB . je3saqysdi = (
rtP . ECIPositiontoLLA_sec_hg1n4hn3po + rtP . Bias_Bias_fimxdpcz0r ) * rtP .
secGain_Gain_hlnp40tcco ; rtB . bkdmnk0pty = rtP . gainVal_Gain_jepzmrn5us *
rtP . ECIPositiontoLLA_sec_hg1n4hn3po ; for ( i = 0 ; i < 8 ; i ++ ) { memcpy
( & rtB . a4g2vzyhvm [ i * 66 ] , & rtP . Constant_Value_arzpnbb4jz [ i * 66
+ 198 ] , 66U * sizeof ( real_T ) ) ; } memcpy ( & rtB . n5ozyxl2ea [ 0 ] , &
rtP . Constant_Value_arzpnbb4jz [ 66 ] , 66U * sizeof ( real_T ) ) ; memcpy (
& rtB . hqiyhoklio [ 0 ] , & rtP . Constant_Value_arzpnbb4jz [ 132 ] , 66U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB .
eygirkdnjo [ i * 1600 ] , & rtP . Constant_Value_ghtelgcmbm [ i * 1600 + 4800
] , 1600U * sizeof ( real_T ) ) ; } memcpy ( & rtB . l5e405bn0t [ 0 ] , & rtP
. Constant_Value_ghtelgcmbm [ 1600 ] , 1600U * sizeof ( real_T ) ) ; memcpy (
& rtB . pfdallhby2 [ 0 ] , & rtP . Constant_Value_ghtelgcmbm [ 3200 ] , 1600U
* sizeof ( real_T ) ) ; for ( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB .
a0dijuavlp [ i * 1275 ] , & rtP . Constant_Value_j10ooefofa [ i * 1275 + 3825
] , 1275U * sizeof ( real_T ) ) ; } memcpy ( & rtB . j4ooexe14u [ 0 ] , & rtP
. Constant_Value_j10ooefofa [ 1275 ] , 1275U * sizeof ( real_T ) ) ; memcpy (
& rtB . juhn3ctbqj [ 0 ] , & rtP . Constant_Value_j10ooefofa [ 2550 ] , 1275U
* sizeof ( real_T ) ) ; rtB . ftmbjsdwjt [ 0 ] = rtP . Gain1_Gain_ptxpgc3l5h
* 0.0 ; rtB . ftmbjsdwjt [ 1 ] = rtP . Gain1_Gain_ptxpgc3l5h * 0.0 ; rtB .
avmjjgc2jq = rtP . Constant_Value_cg2soit4am - rtP .
Constant1_Value_o0v0cp40lz ; rtB . hxuxvq3zag = rtP .
Constant_Value_pppnc2td4g * rtB . avmjjgc2jq ; rtB . imfg2yay3n = rtP .
Constant_Value_nqner0e4l0 - rtB . avmjjgc2jq * rtB . avmjjgc2jq ; rtB .
b3q33e3m3g = rtB . imfg2yay3n / ( rtP . Constant_Value_lprh1udy0r - rtB .
imfg2yay3n ) ; rtB . c0lgenxrhk = rtP . a_Value * rtP . a_Value ; rtB .
lholmb3e4u = rtP . b_Value * rtP . b_Value ; rtB . eepk5vi4ia = rtB .
c0lgenxrhk - rtB . lholmb3e4u ; rtB . obqhwmks5n = rtB . c0lgenxrhk * rtB .
c0lgenxrhk ; rtB . arvpirinaz = rtB . obqhwmks5n - rtB . lholmb3e4u * rtB .
lholmb3e4u ; rtB . jgul4ugkjp = rtB . c0lgenxrhk - rtB . lholmb3e4u ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . m5sp20k3wx ) ; srUpdateBC (
rtDW . d4p0jrfexh ) ; } rtB . as41rna3ij = rtP . Gain1_Gain_jiyxhgzckp * rtP
. JDepoch_days_Value ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T
tid ) { if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . j14ebrdltq = rtB .
k5tl50qmt2 ; rtDW . mpzjv2x2qj = rtB . b32j4milfx ; rtDW . p13ptnzy3r = rtB .
ekrc3dfwk4 ; rtDW . olub4b3luy = rtB . mpmwb1rvos ; } UNUSED_PARAMETER ( tid
) ; } void MdlUpdateTID2 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; _rtXdot -> hmz1jwrnco [ 0 ] = rtB . bnkjf4wemf [ 0 ] ; _rtXdot ->
hmz1jwrnco [ 1 ] = rtB . bnkjf4wemf [ 1 ] ; _rtXdot -> hmz1jwrnco [ 2 ] = rtB
. bnkjf4wemf [ 2 ] ; _rtXdot -> hmz1jwrnco [ 3 ] = rtB . bnkjf4wemf [ 3 ] ;
_rtXdot -> oxda0i4vgt [ 0 ] = rtB . g1i4pov3fb [ 0 ] ; _rtXdot -> mxzg4wj1qp
[ 0 ] = rtB . kqaoyphs3d [ 0 ] ; _rtXdot -> pz5d015liz [ 0 ] = rtB .
d52cu0jrec [ 0 ] ; _rtXdot -> oxda0i4vgt [ 1 ] = rtB . g1i4pov3fb [ 1 ] ;
_rtXdot -> mxzg4wj1qp [ 1 ] = rtB . kqaoyphs3d [ 1 ] ; _rtXdot -> pz5d015liz
[ 1 ] = rtB . d52cu0jrec [ 1 ] ; _rtXdot -> oxda0i4vgt [ 2 ] = rtB .
g1i4pov3fb [ 2 ] ; _rtXdot -> mxzg4wj1qp [ 2 ] = rtB . kqaoyphs3d [ 2 ] ;
_rtXdot -> pz5d015liz [ 2 ] = rtB . d52cu0jrec [ 2 ] ; } void MdlProjection (
void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV
* ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> on04gpzde4 = rtB .
k5tl50qmt2 - rtB . ik0l3bbokb ; _rtZCSV -> gixsda4bxe = rtB . k2e4po1rpr -
rtP . u80deg_UpperSat ; _rtZCSV -> pstgm24b14 = rtB . k2e4po1rpr - rtP .
u80deg_LowerSat ; _rtZCSV -> bfa53nlxor = rtB . hkurduz0au - rtP .
u0deg_UpperSat ; _rtZCSV -> ggpzo3g3ic = rtB . hkurduz0au - rtP .
u0deg_LowerSat ; _rtZCSV -> mljdm35a2w = rtB . b32j4milfx - rtB . f3foywtd4b
; _rtZCSV -> hvejtfx4tk = rtB . ekrc3dfwk4 - rtB . dv0v3nmzor ; _rtZCSV ->
ccjttm4k14 = rtB . nmpjtwlnon - rtP . uto1000000m_UpperSat ; _rtZCSV ->
mpoeljukju = rtB . nmpjtwlnon - rtP . uto1000000m_LowerSat ; _rtZCSV ->
blcdcm45ox = rtB . mpmwb1rvos - rtB . alwtmvsmpo ; _rtZCSV -> jv04uxmnal =
rtB . gsshebwjge ; _rtZCSV -> mzzwkdtdk4 = rtB . bk4wge0g1b - rtP .
CheckdeltaT_minmax [ 0 ] ; _rtZCSV -> ltam3jfqj2 = rtB . bk4wge0g1b - rtP .
CheckdeltaT_minmax [ 1 ] ; _rtZCSV -> o4qsalpqnc = rtB . bk4wge0g1b - rtP .
CheckdeltaT_minmax_l5hvbzxump [ 0 ] ; _rtZCSV -> nb3e0bn3ca = rtB .
bk4wge0g1b - rtP . CheckdeltaT_minmax_l5hvbzxump [ 1 ] ; _rtZCSV ->
crvlqxhw14 = rtB . bk4wge0g1b - rtP . CheckdeltaT_minmax_igedlwrre3 [ 0 ] ;
_rtZCSV -> j3mgw4p0ga = rtB . bk4wge0g1b - rtP .
CheckdeltaT_minmax_igedlwrre3 [ 1 ] ; _rtZCSV -> ilr1vcrggp = rtB .
bk4wge0g1b - rtP . CheckdeltaT_minmax_ccepsw5qgq [ 0 ] ; _rtZCSV ->
esafw32dui = rtB . bk4wge0g1b - rtP . CheckdeltaT_minmax_ccepsw5qgq [ 1 ] ;
_rtZCSV -> hc5z5aewkq = rtB . f4wdtbi41r - rtP .
CheckdeltaT_minmax_nxemqbvh1w [ 0 ] ; _rtZCSV -> coa53myf45 = rtB .
f4wdtbi41r - rtP . CheckdeltaT_minmax_nxemqbvh1w [ 1 ] ; _rtZCSV ->
i0cqq3wjwo = rtB . f4wdtbi41r - rtP . CheckdeltaT_minmax_a2tgpuyjmr [ 0 ] ;
_rtZCSV -> htdzalrmgh = rtB . f4wdtbi41r - rtP .
CheckdeltaT_minmax_a2tgpuyjmr [ 1 ] ; _rtZCSV -> ot00lnpbu1 = rtB .
f4wdtbi41r - rtP . CheckdeltaT_minmax_cnwv0n4cpc [ 0 ] ; _rtZCSV ->
gko1wm0t2f = rtB . f4wdtbi41r - rtP . CheckdeltaT_minmax_cnwv0n4cpc [ 1 ] ;
_rtZCSV -> p4bmzbeppo = rtB . gomgada3tp - rtP .
CheckdeltaT_minmax_axwixcj3v5 [ 0 ] ; _rtZCSV -> j1dtem3dil = rtB .
gomgada3tp - rtP . CheckdeltaT_minmax_axwixcj3v5 [ 1 ] ; _rtZCSV ->
bio0cc2b5u = rtB . gomgada3tp - rtP . CheckdeltaT_minmax_iczlyigkah [ 0 ] ;
_rtZCSV -> et2pdibc2o = rtB . gomgada3tp - rtP .
CheckdeltaT_minmax_iczlyigkah [ 1 ] ; _rtZCSV -> e20bracmkl = rtB .
gomgada3tp - rtP . CheckdeltaT_minmax_o0fimawo5l [ 0 ] ; _rtZCSV ->
o3or5rxznj = rtB . gomgada3tp - rtP . CheckdeltaT_minmax_o0fimawo5l [ 1 ] ;
_rtZCSV -> pg1djeo2ng = rtB . gomgada3tp - rtP .
CheckdeltaT_minmax_cn2hd0jnck [ 0 ] ; _rtZCSV -> mvyygymfw5 = rtB .
gomgada3tp - rtP . CheckdeltaT_minmax_cn2hd0jnck [ 1 ] ; _rtZCSV ->
komr1smdon = rtP . CheckAltitude_min - rtB . nmpjtwlnon ; _rtZCSV ->
bohzvnaelj = rtB . nmpjtwlnon - rtP . CheckAltitude_max ; _rtZCSV ->
eouq0giui5 = rtP . CheckLatitude_min - rtB . hkurduz0au ; _rtZCSV ->
nzjskho3pt = rtB . hkurduz0au - rtP . CheckLatitude_max ; _rtZCSV ->
h45rrcffpf = rtP . CheckLongitude_min - rtB . k2e4po1rpr ; _rtZCSV ->
c13ojsfep0 = rtB . k2e4po1rpr - rtP . CheckLongitude_max ; _rtZCSV ->
csknh51wia = rtP . Istimewithinmodellimits_min - rtB . kelhke2kzj ; _rtZCSV
-> jdnz4mw0kx = rtB . kelhke2kzj - rtP . Istimewithinmodellimits_max ; } void
MdlTerminate ( void ) { rtDW . k1im3nzvaa = rt_SlioAccessorRelease ( 1 , 1 ,
rtDW . k1im3nzvaa ) ; rtDW . kdyvdf55ga = rt_SlioAccessorRelease ( 1 , 1 ,
rtDW . kdyvdf55ga ) ; rtDW . iiujy2f33w = rt_SlioAccessorRelease ( 1 , 1 ,
rtDW . iiujy2f33w ) ; rtDW . fodvlcmywy = rt_SlioAccessorRelease ( 1 , 1 ,
rtDW . fodvlcmywy ) ; rtDW . jm0wxqrcug = rt_SlioAccessorRelease ( 1 , 1 ,
rtDW . jm0wxqrcug ) ; rtDW . gq0nld4wdg = rt_SlioAccessorRelease ( 1 , 1 ,
rtDW . gq0nld4wdg ) ; rtDW . b010mugrdz = rt_SlioAccessorRelease ( 1 , 1 ,
rtDW . b010mugrdz ) ; rtDW . epf4xhkmwj = rt_SlioAccessorRelease ( 1 , 1 ,
rtDW . epf4xhkmwj ) ; if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * *
slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 13 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 1369 ) ; ssSetNumBlockIO ( rtS , 602 ) ;
ssSetNumBlockParams ( rtS , 160386 ) ; } void MdlInitializeSampleTimes ( void
) { ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2373376969U ) ;
ssSetChecksumVal ( rtS , 1 , 1712769446U ) ; ssSetChecksumVal ( rtS , 2 ,
1339463086U ) ; ssSetChecksumVal ( rtS , 3 , 840225815U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 22 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
TST_RWSW_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "TST_RWSW" ) ; ssSetPath
( rtS , "TST_RWSW" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS ,
200000.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
{ static int_T rt_LoggedStateWidths [ ] = { 4 , 3 , 3 , 3 , 2 , 1 , 4 , 1 , 1
, 1 , 1 , 169 , 169 , 169 , 169 , 13 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 4 , 3 ,
3 , 3 , 2 , 1 , 4 , 1 , 1 , 1 , 1 , 169 , 169 , 169 , 169 , 13 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds
[ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE
, SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"TST_RWSW/DYN/DYN_ATT/DYN_ATT_KIN/Integrator" ,
"TST_RWSW/DYN/DYN_TRA/Integrator1" , "TST_RWSW/DYN/DYN_TRA/Integrator" ,
"TST_RWSW/DYN/DYN_ATT/Integrator" ,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Convert from geodetic to\n spherical coordinates\n/For Iterator\nSubsystem/Unit Delay1"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/Unit Delay"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/Unit Delay2"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Unit Delay1"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Unit Delay3"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Unit Delay2"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Unit Delay4"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Time adjust the gauss coefficients/Unit Delay"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Time adjust the gauss coefficients/if (m~=0)/Unit Delay"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Compute unnormalized associated \nlegendre polynomials and \nderivatives via recursion relations/Unit Delay"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Compute unnormalized associated \nlegendre polynomials and \nderivatives via recursion relations/Unit Delay1"
,
 "TST_RWSW/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Special case - North//South Geographic Pole/Unit Delay1"
} ; static const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" ,
"DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" , "DSTATE" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [
] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 16 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 16 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . hmz1jwrnco [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . oxda0i4vgt [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . mxzg4wj1qp [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . pz5d015liz [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) rtDW . obcjv3kxjy ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtDW . pkxcgdmvhn ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) rtDW . kjg3l4zk5v ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtDW . oor1kyyfva ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtDW . jscepyc3up ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtDW . heflbpch1o ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtDW . ksxubnoebg ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) rtDW . jbpr4falgz ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) rtDW . h5cjobt13t ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) rtDW . e4yokmhfao ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) rtDW . kcfi4cmlhd ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) rtDW . at05wcm525 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 13 ] ;
static real_T absTol [ 13 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 } ;
static uint8_T absTolControl [ 13 ] = { 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U , 0U } ; static real_T contStateJacPerturbBoundMinVec [
13 ] ; static real_T contStateJacPerturbBoundMaxVec [ 13 ] ; static uint8_T
zcAttributes [ 41 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL
) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 18 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
pjgxtmydfn ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
cs2usie1fh ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
fmtrkmmqhe ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
jy2zhwllxu ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
b5owf0343w ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
ihrru2lok0 ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
ifwzxts3py ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
h20r5jewxu ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
ogdbiskhax ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
bgmsguohbo ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
kj4a4skaqt ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
mkutzgjcja ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
fulaf1ayid ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
eylpy53wuw ) , ( NULL ) } , { 4 * sizeof ( real_T ) , ( char * ) ( & rtB .
awbmrd3k3c [ 0 ] ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( &
rtB . hdy13qwuxo . pmiuvoq3bk ) , ( NULL ) } , { 9 * sizeof ( real_T ) , (
char * ) ( & rtB . eehz0nr2kbd . ivoxddha1s . nxsqtyhezz [ 0 ] ) , ( NULL ) }
, { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . mlcpngipio4 . pmiuvoq3bk ) ,
( NULL ) } } ; { int i ; for ( i = 0 ; i < 13 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 4000.0
) ; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 18 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS
, 1 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetAbsTolVector ( rtS , absTol ) ; ssSetAbsTolControlVector (
rtS , absTolControl ) ; ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 41 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 41 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 2373376969U ) ; ssSetChecksumVal ( rtS , 1 ,
1712769446U ) ; ssSetChecksumVal ( rtS , 2 , 1339463086U ) ; ssSetChecksumVal
( rtS , 3 , 840225815U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 86 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . oasjptnaiz4 . j4omgsrsfr ; systemRan [ 2 ] = ( sysRanDType * ) & rtDW
. ebq2is5hcrm . k2tbsd51jk ; systemRan [ 3 ] = ( sysRanDType * ) & rtDW .
j2qjlobs3y . j4omgsrsfr ; systemRan [ 4 ] = ( sysRanDType * ) & rtDW .
p4zw5pk3wy . k2tbsd51jk ; systemRan [ 5 ] = & rtAlwaysEnabled ; systemRan [ 6
] = & rtAlwaysEnabled ; systemRan [ 7 ] = & rtAlwaysEnabled ; systemRan [ 8 ]
= & rtAlwaysEnabled ; systemRan [ 9 ] = & rtAlwaysEnabled ; systemRan [ 10 ]
= & rtAlwaysEnabled ; systemRan [ 11 ] = & rtAlwaysEnabled ; systemRan [ 12 ]
= & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ; systemRan [ 14 ]
= & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ; systemRan [ 16 ]
= & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ; systemRan [ 18 ]
= & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ; systemRan [ 20 ]
= & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ; systemRan [ 22 ]
= & rtAlwaysEnabled ; systemRan [ 23 ] = ( sysRanDType * ) & rtDW .
kfz4qm0ehh . j4omgsrsfr ; systemRan [ 24 ] = ( sysRanDType * ) & rtDW .
hvkk5ldfab . k2tbsd51jk ; systemRan [ 25 ] = ( sysRanDType * ) & rtDW .
njjq1lvqsq . j4omgsrsfr ; systemRan [ 26 ] = ( sysRanDType * ) & rtDW .
bxw5fabqqg . k2tbsd51jk ; systemRan [ 27 ] = & rtAlwaysEnabled ; systemRan [
28 ] = & rtAlwaysEnabled ; systemRan [ 29 ] = & rtAlwaysEnabled ; systemRan [
30 ] = & rtAlwaysEnabled ; systemRan [ 31 ] = & rtAlwaysEnabled ; systemRan [
32 ] = & rtAlwaysEnabled ; systemRan [ 33 ] = & rtAlwaysEnabled ; systemRan [
34 ] = & rtAlwaysEnabled ; systemRan [ 35 ] = & rtAlwaysEnabled ; systemRan [
36 ] = & rtAlwaysEnabled ; systemRan [ 37 ] = & rtAlwaysEnabled ; systemRan [
38 ] = & rtAlwaysEnabled ; systemRan [ 39 ] = & rtAlwaysEnabled ; systemRan [
40 ] = & rtAlwaysEnabled ; systemRan [ 41 ] = & rtAlwaysEnabled ; systemRan [
42 ] = & rtAlwaysEnabled ; systemRan [ 43 ] = & rtAlwaysEnabled ; systemRan [
44 ] = & rtAlwaysEnabled ; systemRan [ 45 ] = & rtAlwaysEnabled ; systemRan [
46 ] = & rtAlwaysEnabled ; systemRan [ 47 ] = & rtAlwaysEnabled ; systemRan [
48 ] = ( sysRanDType * ) & rtDW . cbthz0gwcs . j4omgsrsfr ; systemRan [ 49 ]
= ( sysRanDType * ) & rtDW . ku4t4kttcb . k2tbsd51jk ; systemRan [ 50 ] = (
sysRanDType * ) & rtDW . lwyp5so3rz . j4omgsrsfr ; systemRan [ 51 ] = (
sysRanDType * ) & rtDW . nw3ycnua5h . k2tbsd51jk ; systemRan [ 52 ] = &
rtAlwaysEnabled ; systemRan [ 53 ] = & rtAlwaysEnabled ; systemRan [ 54 ] = &
rtAlwaysEnabled ; systemRan [ 55 ] = & rtAlwaysEnabled ; systemRan [ 56 ] = &
rtAlwaysEnabled ; systemRan [ 57 ] = & rtAlwaysEnabled ; systemRan [ 58 ] = &
rtAlwaysEnabled ; systemRan [ 59 ] = & rtAlwaysEnabled ; systemRan [ 60 ] = &
rtAlwaysEnabled ; systemRan [ 61 ] = & rtAlwaysEnabled ; systemRan [ 62 ] = &
rtAlwaysEnabled ; systemRan [ 63 ] = & rtAlwaysEnabled ; systemRan [ 64 ] = (
sysRanDType * ) & rtDW . p5zu1sk310 ; systemRan [ 65 ] = ( sysRanDType * ) &
rtDW . mgjysjngq1 ; systemRan [ 66 ] = ( sysRanDType * ) & rtDW . eznk3o5xwu
; systemRan [ 67 ] = ( sysRanDType * ) & rtDW . lgblsj3t4q ; systemRan [ 68 ]
= ( sysRanDType * ) & rtDW . cfsnxzglwr ; systemRan [ 69 ] = ( sysRanDType *
) & rtDW . lwuzl0ygua ; systemRan [ 70 ] = ( sysRanDType * ) & rtDW .
jxlgxqsvbl ; systemRan [ 71 ] = ( sysRanDType * ) & rtDW . hxe31sma1e ;
systemRan [ 72 ] = ( sysRanDType * ) & rtDW . nyw4c2tuhv ; systemRan [ 73 ] =
( sysRanDType * ) & rtDW . anrree0xau ; systemRan [ 74 ] = ( sysRanDType * )
& rtDW . pfulaza2sz ; systemRan [ 75 ] = ( sysRanDType * ) & rtDW .
juk5yec0yu ; systemRan [ 76 ] = ( sysRanDType * ) & rtDW . anrree0xau ;
systemRan [ 77 ] = ( sysRanDType * ) & rtDW . b4mdlatzxs ; systemRan [ 78 ] =
& rtAlwaysEnabled ; systemRan [ 79 ] = ( sysRanDType * ) & rtDW . m5sp20k3wx
; systemRan [ 80 ] = ( sysRanDType * ) & rtDW . d4p0jrfexh ; systemRan [ 81 ]
= ( sysRanDType * ) & rtDW . d4p0jrfexh ; systemRan [ 82 ] = &
rtAlwaysEnabled ; systemRan [ 83 ] = & rtAlwaysEnabled ; systemRan [ 84 ] = &
rtAlwaysEnabled ; systemRan [ 85 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } rtP . CheckdeltaT_minmax [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_l5hvbzxump [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_igedlwrre3 [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_ccepsw5qgq [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_nxemqbvh1w [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_a2tgpuyjmr [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_cnwv0n4cpc [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_axwixcj3v5 [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_iczlyigkah [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_o0fimawo5l [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_cn2hd0jnck [ 1 ] = rtInf ; return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
