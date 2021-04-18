#include "rt_logging_mmi.h"
#include "TST_RWSWV2_capi.h"
#include <math.h>
#include "TST_RWSWV2.h"
#include "TST_RWSWV2_private.h"
#include "TST_RWSWV2_dt.h"
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
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
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
"slprj\\raccel\\TST_RWSWV2\\TST_RWSWV2_Jpattern.mat" ; const int_T
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
& model_S ; static void pxb1ugk451 ( const real_T Aq_B [ 4 ] , const real_T
Bq_C [ 4 ] , real_T Aq_C [ 4 ] ) ; static void chjngh2jei ( const real_T Aq_B
[ 4 ] , const real_T Bq_C [ 4 ] , real_T Aq_C [ 4 ] ) ; static void
p2ulm3jjpb ( const real_T Aq_B [ 4 ] , const real_T Bq_C [ 4 ] , real_T Aq_C
[ 4 ] ) ; static void nsbxylmapa ( real_T * x ) ; static void be4dle1kpx (
real_T * x ) ; real_T glob7s ( real_T * p , int_T doy , real_T lon , const
real_T f107a , real_T * sw , real_T * swc , real_T ctloc , real_T stloc ,
real_T c2tloc , real_T s2tloc , real_T c3tloc , real_T s3tloc , real_T apdf ,
real_T apt , real_T * plg ) { real_T pset = 2.0 ; real_T t [ 14 ] ; real_T tt
; real_T cd32 , cd18 , cd14 , cd39 , dfa ; real_T p32 , p18 , p14 , p39 ;
int_T i , j ; if ( p [ 99 ] == 0 ) { p [ 99 ] = pset ; } if ( p [ 99 ] !=
pset ) { return - 1 ; } for ( j = 0 ; j < 14 ; j ++ ) { t [ j ] = 0.0 ; }
cd32 = muDoubleScalarCos ( DR * ( doy - p [ 31 ] ) ) ; cd18 =
muDoubleScalarCos ( 2.0 * DR * ( doy - p [ 17 ] ) ) ; cd14 =
muDoubleScalarCos ( DR * ( doy - p [ 13 ] ) ) ; cd39 = muDoubleScalarCos (
2.0 * DR * ( doy - p [ 38 ] ) ) ; p32 = p [ 31 ] ; p18 = p [ 17 ] ; p14 = p [
13 ] ; p39 = p [ 38 ] ; dfa = f107a - 150.0 ; t [ 0 ] = p [ 21 ] * dfa ; t [
1 ] = p [ 1 ] * plg [ 2 ] + p [ 2 ] * plg [ 4 ] + p [ 22 ] * plg [ 6 ] + p [
26 ] * plg [ 1 ] + p [ 14 ] * plg [ 3 ] + p [ 59 ] * plg [ 5 ] ; t [ 2 ] = (
p [ 18 ] + p [ 47 ] * plg [ 2 ] + p [ 29 ] * plg [ 4 ] ) * cd32 ; t [ 3 ] = (
p [ 15 ] + p [ 16 ] * plg [ 2 ] + p [ 30 ] * plg [ 4 ] ) * cd18 ; t [ 4 ] = (
p [ 9 ] * plg [ 1 ] + p [ 10 ] * plg [ 3 ] + p [ 20 ] * plg [ 5 ] ) * cd14 ;
t [ 5 ] = ( p [ 37 ] * plg [ 1 ] ) * cd39 ; if ( sw [ 7 ] ) { real_T t71 ,
t72 ; t71 = p [ 11 ] * plg [ 11 ] * cd14 * swc [ 5 ] ; t72 = p [ 12 ] * plg [
11 ] * cd14 * swc [ 5 ] ; t [ 6 ] = ( ( p [ 3 ] * plg [ 10 ] + p [ 4 ] * plg
[ 12 ] + t71 ) * ctloc + ( p [ 6 ] * plg [ 10 ] + p [ 7 ] * plg [ 12 ] + t72
) * stloc ) ; } if ( sw [ 8 ] ) { real_T t81 , t82 ; t81 = ( p [ 23 ] * plg [
21 ] + p [ 35 ] * plg [ 23 ] ) * cd14 * swc [ 5 ] ; t82 = ( p [ 33 ] * plg [
21 ] + p [ 36 ] * plg [ 23 ] ) * cd14 * swc [ 5 ] ; t [ 7 ] = ( ( p [ 5 ] *
plg [ 20 ] + p [ 41 ] * plg [ 22 ] + t81 ) * c2tloc + ( p [ 8 ] * plg [ 20 ]
+ p [ 42 ] * plg [ 22 ] + t82 ) * s2tloc ) ; } if ( sw [ 14 ] ) { t [ 13 ] =
p [ 39 ] * plg [ 30 ] * s3tloc + p [ 40 ] * plg [ 30 ] * c3tloc ; } if ( sw [
9 ] ) { if ( sw [ 9 ] == 1 ) { t [ 8 ] = apdf * ( p [ 32 ] + p [ 45 ] * plg [
2 ] * swc [ 2 ] ) ; } if ( sw [ 9 ] == - 1 ) { t [ 8 ] = ( p [ 50 ] * apt + p
[ 96 ] * plg [ 2 ] * apt * swc [ 2 ] ) ; } } if ( ! ( ( sw [ 10 ] == 0 ) || (
sw [ 11 ] == 0 ) || ( lon <= - 1000.0 ) ) ) { t [ 10 ] = ( 1.0 + plg [ 1 ] *
( p [ 80 ] * swc [ 5 ] * muDoubleScalarCos ( DR * ( doy - p [ 81 ] ) ) + p [
85 ] * swc [ 6 ] * muDoubleScalarCos ( 2.0 * DR * ( doy - p [ 86 ] ) ) ) + p
[ 83 ] * swc [ 3 ] * muDoubleScalarCos ( DR * ( doy - p [ 84 ] ) ) + p [ 87 ]
* swc [ 4 ] * muDoubleScalarCos ( 2.0 * DR * ( doy - p [ 88 ] ) ) ) * ( ( p [
64 ] * plg [ 11 ] + p [ 65 ] * plg [ 13 ] + p [ 66 ] * plg [ 15 ] + p [ 74 ]
* plg [ 10 ] + p [ 75 ] * plg [ 12 ] + p [ 76 ] * plg [ 14 ] ) *
muDoubleScalarCos ( DGTR * lon ) + ( p [ 90 ] * plg [ 11 ] + p [ 91 ] * plg [
13 ] + p [ 92 ] * plg [ 15 ] + p [ 77 ] * plg [ 10 ] + p [ 78 ] * plg [ 12 ]
+ p [ 79 ] * plg [ 14 ] ) * muDoubleScalarSin ( DGTR * lon ) ) ; } tt = 0 ;
for ( i = 0 ; i < 14 ; i ++ ) { tt += muDoubleScalarAbs ( ( real_T ) sw [ i +
1 ] ) * t [ i ] ; } return tt ; } void gtd7 ( const int_T * doy , const
real_T * sec , const real_T * alt , real_T * lat , real_T * lon , const
real_T * tloc , const real_T * f107a , const real_T * f107 , real_T * ap ,
const real_T * aph , int_T numPoints , int_T * switches , real_T * sw ,
real_T * swc , real_T * dens , real_T * T ) { real_T plg [ 36 ] ; real_T xmm
; int_T mn3 = 5 ; real_T zn3 [ 5 ] = { 32.5 , 20.0 , 15.0 , 10.0 , 0.0 } ;
int_T mn2 = 4 ; real_T zn2 [ 4 ] = { 72.5 , 55.0 , 45.0 , 32.5 } ; real_T
zmix = 62.5 ; real_T dm28m ; real_T tz ; real_T dmc ; real_T dmr ; real_T
dz28 ; real_T dd ; real_T dm28 = 0 ; real_T meso_tn2 [ 4 ] ; real_T meso_tn3
[ 5 ] ; real_T meso_tgn2 [ 2 ] ; real_T meso_tgn3 [ 2 ] ; real_T gsurf ;
real_T re ; real_T ctloc , stloc ; real_T c2tloc , s2tloc ; real_T s3tloc ,
c3tloc ; real_T apdf ; real_T apt [ 4 ] ; real_T meso_tn1 [ 5 ] ; real_T
meso_tgn1 [ 2 ] ; int_T i ; tselec ( switches , sw , swc ) ; xmm = pdm [ 2 ]
[ 4 ] ; for ( i = 0 ; i < numPoints ; i ++ ) { glatf ( lat [ i ] , & gsurf ,
& re , sw [ 2 ] ) ; gts7 ( doy [ i ] , sec [ i ] , alt [ i ] , lat [ i ] ,
lon [ i ] , tloc [ i ] , f107a [ i ] , f107 [ i ] , ap [ i ] , aph ,
numPoints , i , sw , swc , zn2 [ 0 ] , dens , T , & dm28 , gsurf , re , &
ctloc , & stloc , & c2tloc , & s2tloc , & c3tloc , & s3tloc , & apdf , & apt
[ 0 ] , & meso_tn1 [ 0 ] , & meso_tgn1 [ 0 ] , & plg [ 0 ] ) ; dm28m = dm28 *
1.0E6 ; if ( alt [ i ] < zn2 [ 0 ] ) { meso_tgn2 [ 0 ] = meso_tgn1 [ 1 ] ;
meso_tn2 [ 0 ] = meso_tn1 [ 4 ] ; meso_tn2 [ 1 ] = pma [ 0 ] [ 0 ] * pavgm [
0 ] / ( 1.0 - sw [ 20 ] * glob7s ( pma [ 0 ] , doy [ i ] , lon [ i ] , f107a
[ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf ,
apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tn2 [ 2 ] = pma [ 1 ] [ 0 ] * pavgm [ 1 ]
/ ( 1.0 - sw [ 20 ] * glob7s ( pma [ 1 ] , doy [ i ] , lon [ i ] , f107a [ i
] , sw , swc , ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt
[ 0 ] , & plg [ 0 ] ) ) ; meso_tn2 [ 3 ] = pma [ 2 ] [ 0 ] * pavgm [ 2 ] / (
1.0 - sw [ 20 ] * sw [ 22 ] * glob7s ( pma [ 2 ] , doy [ i ] , lon [ i ] ,
f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc ,
apdf , apt [ 0 ] , & plg [ 0 ] ) ) ; meso_tgn2 [ 1 ] = pavgm [ 8 ] * pma [ 9
] [ 0 ] * ( 1.0 + sw [ 20 ] * sw [ 22 ] * glob7s ( pma [ 9 ] , doy [ i ] ,
lon [ i ] , f107a [ i ] , sw , swc , ctloc , stloc , c2tloc , s2tloc , c3tloc
, s3tloc , apdf , apt [ 0 ] , & plg [ 0 ] ) ) * meso_tn2 [ 3 ] * meso_tn2 [ 3
] / ( ( pma [ 2 ] [ 0 ] * pavgm [ 2 ] ) * ( pma [ 2 ] [ 0 ] * pavgm [ 2 ] ) )
; meso_tn3 [ 0 ] = meso_tn2 [ 3 ] ; if ( alt [ i ] < zn3 [ 0 ] ) { meso_tgn3
[ 0 ] = meso_tgn2 [ 1 ] ; meso_tn3 [ 1 ] = pma [ 3 ] [ 0 ] * pavgm [ 3 ] / (
1.0 - sw [ 22 ] * glob7s ( pma [ 3 ] , doy [ i ] , lon [ i ] , f107a [ i ] ,
sw , swc , ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt [ 0
] , & plg [ 0 ] ) ) ; meso_tn3 [ 2 ] = pma [ 4 ] [ 0 ] * pavgm [ 4 ] / ( 1.0
- sw [ 22 ] * glob7s ( pma [ 4 ] , doy [ i ] , lon [ i ] , f107a [ i ] , sw ,
swc , ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt [ 0 ] ,
& plg [ 0 ] ) ) ; meso_tn3 [ 3 ] = pma [ 5 ] [ 0 ] * pavgm [ 5 ] / ( 1.0 - sw
[ 22 ] * glob7s ( pma [ 5 ] , doy [ i ] , lon [ i ] , f107a [ i ] , sw , swc
, ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt [ 0 ] , &
plg [ 0 ] ) ) ; meso_tn3 [ 4 ] = pma [ 6 ] [ 0 ] * pavgm [ 6 ] / ( 1.0 - sw [
22 ] * glob7s ( pma [ 6 ] , doy [ i ] , lon [ i ] , f107a [ i ] , sw , swc ,
ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt [ 0 ] , & plg
[ 0 ] ) ) ; meso_tgn3 [ 1 ] = pma [ 7 ] [ 0 ] * pavgm [ 7 ] * ( 1.0 + sw [ 22
] * glob7s ( pma [ 7 ] , doy [ i ] , lon [ i ] , f107a [ i ] , sw , swc ,
ctloc , stloc , c2tloc , s2tloc , c3tloc , s3tloc , apdf , apt [ 0 ] , & plg
[ 0 ] ) ) * meso_tn3 [ 4 ] * meso_tn3 [ 4 ] / ( ( pma [ 6 ] [ 0 ] * pavgm [ 6
] ) * ( pma [ 6 ] [ 0 ] * pavgm [ 6 ] ) ) ; } dmc = 0 ; if ( alt [ i ] > zmix
) { dmc = 1.0 - ( zn2 [ 0 ] - alt [ i ] ) / ( zn2 [ 0 ] - zmix ) ; } dz28 =
dens [ i + numPoints * 2 ] ; dmr = dens [ i + numPoints * 2 ] / dm28m - 1.0 ;
dens [ i + numPoints * 2 ] = densm ( alt [ i ] , dm28m , xmm , & tz , mn3 ,
zn3 , meso_tn3 , meso_tgn3 , mn2 , zn2 , meso_tn2 , meso_tgn2 , gsurf , re )
; dens [ i + numPoints * 2 ] = dens [ i + numPoints * 2 ] * ( 1.0 + dmr * dmc
) ; dmr = dens [ i ] / ( dz28 * pdm [ 0 ] [ 1 ] ) - 1.0 ; dens [ i ] = dens [
i + numPoints * 2 ] * pdm [ 0 ] [ 1 ] * ( 1.0 + dmr * dmc ) ; dens [ i +
numPoints ] = 0 ; dens [ i + numPoints * 8 ] = 0 ; dmr = dens [ i + numPoints
* 3 ] / ( dz28 * pdm [ 3 ] [ 1 ] ) - 1.0 ; dens [ i + numPoints * 3 ] = dens
[ i + numPoints * 2 ] * pdm [ 3 ] [ 1 ] * ( 1.0 + dmr * dmc ) ; dmr = dens [
i + numPoints * 4 ] / ( dz28 * pdm [ 4 ] [ 1 ] ) - 1.0 ; dens [ i + numPoints
* 4 ] = dens [ i + numPoints * 2 ] * pdm [ 4 ] [ 1 ] * ( 1.0 + dmr * dmc ) ;
dens [ i + numPoints * 6 ] = 0 ; dens [ i + numPoints * 7 ] = 0 ; dens [ i +
numPoints * 5 ] = 1.66E-24 * ( 4.0 * dens [ i ] + 16.0 * dens [ i + numPoints
] + 28.0 * dens [ i + numPoints * 2 ] + 32.0 * dens [ i + numPoints * 3 ] +
40.0 * dens [ i + numPoints * 4 ] + dens [ i + numPoints * 6 ] + 14.0 * dens
[ i + numPoints * 7 ] ) ; dens [ i + numPoints * 5 ] = dens [ i + numPoints *
5 ] * 0.001 ; dd = densm ( alt [ i ] , 1.0 , 0 , & tz , mn3 , zn3 , meso_tn3
, meso_tgn3 , mn2 , zn2 , meso_tn2 , meso_tgn2 , gsurf , re ) ; T [ i +
numPoints ] = tz ; } } } real_T zeta ( real_T zz , real_T zl , real_T re ) {
return ( ( zz - zl ) * ( re + zl ) / ( re + zz ) ) ; } void spline ( real_T *
x , real_T * y , int_T n , real_T yp1 , real_T ypn , real_T * y2 ) { real_T u
[ 10 ] ; real_T sig , p , qn , un ; int_T i , k ; if ( yp1 > 0.99E30 ) { y2 [
0 ] = 0 ; u [ 0 ] = 0 ; } else { y2 [ 0 ] = - 0.5 ; u [ 0 ] = ( 3.0 / ( x [ 1
] - x [ 0 ] ) ) * ( ( y [ 1 ] - y [ 0 ] ) / ( x [ 1 ] - x [ 0 ] ) - yp1 ) ; }
for ( i = 1 ; i < ( n - 1 ) ; i ++ ) { sig = ( x [ i ] - x [ i - 1 ] ) / ( x
[ i + 1 ] - x [ i - 1 ] ) ; p = sig * y2 [ i - 1 ] + 2.0 ; y2 [ i ] = ( sig -
1.0 ) / p ; u [ i ] = ( 6.0 * ( ( y [ i + 1 ] - y [ i ] ) / ( x [ i + 1 ] - x
[ i ] ) - ( y [ i ] - y [ i - 1 ] ) / ( x [ i ] - x [ i - 1 ] ) ) / ( x [ i +
1 ] - x [ i - 1 ] ) - sig * u [ i - 1 ] ) / p ; } if ( ypn > 0.99E30 ) { qn =
0 ; un = 0 ; } else { qn = 0.5 ; un = ( 3.0 / ( x [ n - 1 ] - x [ n - 2 ] ) )
* ( ypn - ( y [ n - 1 ] - y [ n - 2 ] ) / ( x [ n - 1 ] - x [ n - 2 ] ) ) ; }
y2 [ n - 1 ] = ( un - qn * u [ n - 2 ] ) / ( qn * y2 [ n - 2 ] + 1.0 ) ; for
( k = n - 2 ; k >= 0 ; k -- ) y2 [ k ] = y2 [ k ] * y2 [ k + 1 ] + u [ k ] ;
} void splint ( real_T * xa , real_T * ya , real_T * y2a , int_T n , real_T x
, real_T * y ) { int_T klo = 0 ; int_T khi = n - 1 ; int_T k ; real_T h ;
real_T a , b , yi ; while ( ( khi - klo ) > 1 ) { k = ( khi + klo ) * 0.5 ;
if ( xa [ k ] > x ) khi = k ; else klo = k ; } h = xa [ khi ] - xa [ klo ] ;
a = ( xa [ khi ] - x ) / h ; b = ( x - xa [ klo ] ) / h ; yi = a * ya [ klo ]
+ b * ya [ khi ] + ( ( a * a * a - a ) * y2a [ klo ] + ( b * b * b - b ) *
y2a [ khi ] ) * h * h / 6.0 ; * y = yi ; } void splini ( real_T * xa , real_T
* ya , real_T * y2a , int_T n , real_T x , real_T * y ) { real_T yi = 0 ;
int_T klo = 0 ; int_T khi = 1 ; real_T xx , h , a , b , a2 , b2 ; while ( ( x
> xa [ klo ] ) && ( khi < n ) ) { xx = x ; if ( khi < ( n - 1 ) ) { if ( x <
xa [ khi ] ) xx = x ; else xx = xa [ khi ] ; } h = xa [ khi ] - xa [ klo ] ;
a = ( xa [ khi ] - xx ) / h ; b = ( xx - xa [ klo ] ) / h ; a2 = a * a ; b2 =
b * b ; yi += ( ( 1.0 - a2 ) * ya [ klo ] * 0.5 + b2 * ya [ khi ] * 0.5 + ( (
- ( 1.0 + a2 * a2 ) * 0.25 + a2 * 0.5 ) * y2a [ klo ] + ( b2 * b2 * 0.25 - b2
* 0.5 ) * y2a [ khi ] ) * h * h / 6.0 ) * h ; klo ++ ; khi ++ ; } * y = yi ;
} real_T densm ( real_T alt , real_T d0 , real_T xm , real_T * tz , int_T mn3
, real_T * zn3 , real_T * tn3 , real_T * tgn3 , int_T mn2 , real_T * zn2 ,
real_T * tn2 , real_T * tgn2 , real_T gsurf , real_T re ) { real_T xs [ 10 ]
, ys [ 10 ] , y2out [ 10 ] ; real_T z , z1 , z2 , t1 , t2 , zg , zgdif ;
real_T yd1 , yd2 ; real_T x , y , yi ; real_T expll , gamm , glb , sqterm ;
real_T densm_tmp ; int_T mn ; int_T k ; densm_tmp = d0 ; if ( alt > zn2 [ 0 ]
) { if ( xm == 0.0 ) return * tz ; else return d0 ; } if ( alt > zn2 [ mn2 -
1 ] ) z = alt ; else z = zn2 [ mn2 - 1 ] ; mn = mn2 ; z1 = zn2 [ 0 ] ; z2 =
zn2 [ mn - 1 ] ; t1 = tn2 [ 0 ] ; t2 = tn2 [ mn - 1 ] ; zg = zeta ( z , z1 ,
re ) ; zgdif = zeta ( z2 , z1 , re ) ; for ( k = 0 ; k < mn ; k ++ ) { xs [ k
] = zeta ( zn2 [ k ] , z1 , re ) / zgdif ; ys [ k ] = 1.0 / tn2 [ k ] ; } yd1
= - tgn2 [ 0 ] / ( t1 * t1 ) * zgdif ; sqterm = ( re + z2 ) / ( re + z1 ) ;
yd2 = - tgn2 [ 1 ] / ( t2 * t2 ) * zgdif * ( sqterm * sqterm ) ; spline ( xs
, ys , mn , yd1 , yd2 , y2out ) ; x = zg / zgdif ; splint ( xs , ys , y2out ,
mn , x , & y ) ; * tz = 1.0 / y ; if ( xm != 0.0 ) { sqterm = 1.0 + z1 / re ;
glb = gsurf / ( sqterm * sqterm ) ; gamm = xm * glb * zgdif / RGAS ; splini (
xs , ys , y2out , mn , x , & yi ) ; expll = gamm * yi ; if ( expll > 50.0 )
expll = 50.0 ; densm_tmp = densm_tmp * ( t1 / * tz ) * muDoubleScalarExp ( -
expll ) ; } if ( alt > zn3 [ 0 ] ) { if ( xm == 0.0 ) return * tz ; else
return densm_tmp ; } z = alt ; mn = mn3 ; z1 = zn3 [ 0 ] ; z2 = zn3 [ mn - 1
] ; t1 = tn3 [ 0 ] ; t2 = tn3 [ mn - 1 ] ; zg = zeta ( z , z1 , re ) ; zgdif
= zeta ( z2 , z1 , re ) ; for ( k = 0 ; k < mn ; k ++ ) { xs [ k ] = zeta (
zn3 [ k ] , z1 , re ) / zgdif ; ys [ k ] = 1.0 / tn3 [ k ] ; } yd1 = - tgn3 [
0 ] / ( t1 * t1 ) * zgdif ; sqterm = ( re + z2 ) / ( re + z1 ) ; yd2 = - tgn3
[ 1 ] / ( t2 * t2 ) * zgdif * ( sqterm * sqterm ) ; spline ( xs , ys , mn ,
yd1 , yd2 , y2out ) ; x = zg / zgdif ; splint ( xs , ys , y2out , mn , x , &
y ) ; * tz = 1.0 / y ; if ( xm != 0.0 ) { sqterm = 1.0 + z1 / re ; glb =
gsurf / ( sqterm * sqterm ) ; gamm = xm * glb * zgdif / RGAS ; splini ( xs ,
ys , y2out , mn , x , & yi ) ; expll = gamm * yi ; if ( expll > 50.0 ) expll
= 50.0 ; densm_tmp = densm_tmp * ( t1 / * tz ) * muDoubleScalarExp ( - expll
) ; } if ( xm == 0.0 ) return * tz ; else return densm_tmp ; } void glatf (
const real_T lat , real_T * gv , real_T * reff , real_T flag ) { real_T c2 ;
real_T xlat ; xlat = lat ; if ( flag == 0.0 ) { xlat = 45.0 ; } c2 =
muDoubleScalarCos ( 2.0 * DGTR * xlat ) ; * gv = 980.616 * ( 1.0 - 0.0026373
* c2 ) ; * reff = 2.0 * ( * gv ) / ( 3.085462E-6 + 2.27E-9 * c2 ) * 1.0E-5 ;
} void tselec ( int_T * switches , real_T * sw , real_T * swc ) { int_T i ;
for ( i = 0 ; i < 24 ; i ++ ) { if ( i != 9 ) { if ( switches [ i ] == 1 ) sw
[ i ] = 1 ; else sw [ i ] = 0 ; if ( switches [ i ] > 0 ) swc [ i ] = 1 ;
else swc [ i ] = 0 ; } else { sw [ i ] = switches [ i ] ; swc [ i ] =
switches [ i ] ; } } } real_T densu ( real_T alt , real_T dlb , real_T tinf ,
real_T tlb , real_T xm , real_T alpha , real_T * tz , real_T zlb , real_T s2
, int_T mn1 , real_T * zn1 , real_T * tn1 , real_T * tgn1 , real_T gsurf ,
real_T re ) { real_T yd2 , yd1 , y ; real_T densu_temp = 1.0 ; real_T za , z
, zg2 , tt , ta ; real_T dta , z2 , t2 , zg ; real_T x = 0.0 ; real_T z1 =
0.0 ; real_T t1 = 0.0 ; real_T zgdif = 0.0 ; int_T mn = 0 ; int_T k ; real_T
glb ; real_T expll ; real_T yi ; real_T densa , sqterm ; real_T gammad , gamm
; real_T xs [ 5 ] , ys [ 5 ] , y2out [ 5 ] ; za = zn1 [ 0 ] ; if ( alt > za )
z = alt ; else z = za ; zg2 = zeta ( z , zlb , re ) ; tt = tinf - ( tinf -
tlb ) * muDoubleScalarExp ( - s2 * zg2 ) ; ta = tt ; * tz = tt ; densu_temp =
* tz ; if ( alt < za ) { sqterm = ( re + zlb ) / ( re + za ) ; dta = ( tinf -
ta ) * s2 * ( sqterm * sqterm ) ; tgn1 [ 0 ] = dta ; tn1 [ 0 ] = ta ; if (
alt > zn1 [ mn1 - 1 ] ) z = alt ; else z = zn1 [ mn1 - 1 ] ; mn = mn1 ; z1 =
zn1 [ 0 ] ; z2 = zn1 [ mn - 1 ] ; t1 = tn1 [ 0 ] ; t2 = tn1 [ mn - 1 ] ; zg =
zeta ( z , z1 , re ) ; zgdif = zeta ( z2 , z1 , re ) ; for ( k = 0 ; k < mn ;
k ++ ) { xs [ k ] = zeta ( zn1 [ k ] , z1 , re ) / zgdif ; ys [ k ] = 1.0 /
tn1 [ k ] ; } yd1 = - tgn1 [ 0 ] / ( t1 * t1 ) * zgdif ; sqterm = ( re + z2 )
/ ( re + z1 ) ; yd2 = - tgn1 [ 1 ] / ( t2 * t2 ) * zgdif * ( sqterm * sqterm
) ; spline ( xs , ys , mn , yd1 , yd2 , y2out ) ; x = zg / zgdif ; splint (
xs , ys , y2out , mn , x , & y ) ; * tz = 1.0 / y ; densu_temp = * tz ; } if
( xm == 0.0 ) return densu_temp ; sqterm = 1.0 + zlb / re ; glb = gsurf / (
sqterm * sqterm ) ; gammad = xm * glb / ( s2 * RGAS * tinf ) ; expll =
muDoubleScalarExp ( - s2 * gammad * zg2 ) ; if ( expll > 50.0 ) { expll =
50.0 ; } if ( tt <= 0.0 ) { expll = 50.0 ; } densa = dlb *
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
numPoints * 5 ] = dens [ i + numPoints * 5 ] * 0.001 ; } void i41uiun02b (
const real_T gkweaamiz5 [ 9 ] , guvq4wawov * localB ) { real_T qw_sq ; real_T
qx_sq ; real_T qy_sq ; real_T qz_sq ; int32_T k ; real_T varargin_1 [ 4 ] ;
real_T ex ; int32_T b_k ; boolean_T exitg1 ; qw_sq = ( ( ( gkweaamiz5 [ 0 ] +
gkweaamiz5 [ 4 ] ) + gkweaamiz5 [ 8 ] ) + 1.0 ) * 0.25 ; qx_sq = ( ( (
gkweaamiz5 [ 0 ] + 1.0 ) - gkweaamiz5 [ 4 ] ) - gkweaamiz5 [ 8 ] ) * 0.25 ;
qy_sq = ( ( ( gkweaamiz5 [ 4 ] + 1.0 ) - gkweaamiz5 [ 0 ] ) - gkweaamiz5 [ 8
] ) * 0.25 ; qz_sq = ( ( ( gkweaamiz5 [ 8 ] + 1.0 ) - gkweaamiz5 [ 0 ] ) -
gkweaamiz5 [ 4 ] ) * 0.25 ; varargin_1 [ 0 ] = qw_sq ; varargin_1 [ 1 ] =
qx_sq ; varargin_1 [ 2 ] = qy_sq ; varargin_1 [ 3 ] = qz_sq ; if ( !
muDoubleScalarIsNaN ( qw_sq ) ) { k = 1 ; } else { k = 0 ; b_k = 2 ; exitg1 =
false ; while ( ( ! exitg1 ) && ( b_k < 5 ) ) { if ( ! muDoubleScalarIsNaN (
varargin_1 [ b_k - 1 ] ) ) { k = b_k ; exitg1 = true ; } else { b_k ++ ; } }
} if ( k == 0 ) { k = 1 ; } else { ex = varargin_1 [ k - 1 ] ; for ( b_k = k
; b_k < 4 ; b_k ++ ) { if ( ex < varargin_1 [ b_k ] ) { ex = varargin_1 [ b_k
] ; k = b_k + 1 ; } } } if ( k == 1 ) { qx_sq = muDoubleScalarSqrt ( qw_sq )
; localB -> ny3pcenmal [ 1 ] = ( gkweaamiz5 [ 7 ] - gkweaamiz5 [ 5 ] ) * 0.25
/ qx_sq ; localB -> ny3pcenmal [ 2 ] = ( gkweaamiz5 [ 2 ] - gkweaamiz5 [ 6 ]
) * 0.25 / qx_sq ; localB -> ny3pcenmal [ 3 ] = ( gkweaamiz5 [ 3 ] -
gkweaamiz5 [ 1 ] ) * 0.25 / qx_sq ; } else if ( k == 2 ) { qy_sq =
muDoubleScalarSqrt ( qx_sq ) ; localB -> ny3pcenmal [ 1 ] =
muDoubleScalarSqrt ( qx_sq ) ; qx_sq = ( gkweaamiz5 [ 7 ] - gkweaamiz5 [ 5 ]
) * 0.25 / qy_sq ; localB -> ny3pcenmal [ 2 ] = ( gkweaamiz5 [ 3 ] +
gkweaamiz5 [ 1 ] ) * 0.25 / qy_sq ; localB -> ny3pcenmal [ 3 ] = ( gkweaamiz5
[ 2 ] + gkweaamiz5 [ 6 ] ) * 0.25 / qy_sq ; } else if ( k == 3 ) { qz_sq =
muDoubleScalarSqrt ( qy_sq ) ; localB -> ny3pcenmal [ 2 ] =
muDoubleScalarSqrt ( qy_sq ) ; qx_sq = ( gkweaamiz5 [ 2 ] - gkweaamiz5 [ 6 ]
) * 0.25 / qz_sq ; localB -> ny3pcenmal [ 1 ] = ( gkweaamiz5 [ 3 ] +
gkweaamiz5 [ 1 ] ) * 0.25 / qz_sq ; localB -> ny3pcenmal [ 3 ] = ( gkweaamiz5
[ 7 ] + gkweaamiz5 [ 5 ] ) * 0.25 / qz_sq ; } else { qy_sq =
muDoubleScalarSqrt ( qz_sq ) ; localB -> ny3pcenmal [ 3 ] =
muDoubleScalarSqrt ( qz_sq ) ; qx_sq = ( gkweaamiz5 [ 3 ] - gkweaamiz5 [ 1 ]
) * 0.25 / qy_sq ; localB -> ny3pcenmal [ 1 ] = ( gkweaamiz5 [ 2 ] +
gkweaamiz5 [ 6 ] ) * 0.25 / qy_sq ; localB -> ny3pcenmal [ 2 ] = ( gkweaamiz5
[ 7 ] + gkweaamiz5 [ 5 ] ) * 0.25 / qy_sq ; } localB -> ny3pcenmal [ 0 ] =
qx_sq ; } void cc3vamisq4 ( const real_T eseqmfakns [ 4 ] , pj0ihkypqf *
localB ) { localB -> gaty2jlz2p [ 0 ] = eseqmfakns [ 0 ] ; localB ->
gaty2jlz2p [ 1 ] = - eseqmfakns [ 1 ] ; localB -> gaty2jlz2p [ 2 ] = -
eseqmfakns [ 2 ] ; localB -> gaty2jlz2p [ 3 ] = - eseqmfakns [ 3 ] ; } void
k3sfyh0c3k ( real_T izlzshocw0 , real_T ajhyipdmio , real_T * o54a3ez2j0 ,
real_T * ixoi1llif0 , darponzt3g * localP ) { * o54a3ez2j0 = izlzshocw0 +
localP -> Bias1_Bias ; * ixoi1llif0 = ajhyipdmio + localP -> Bias_Bias ; }
void eu5kqssxx5 ( real_T irx2av1ofg , real_T ntacjmujus , real_T * gnizzvsuof
, real_T * kem0wzjelw ) { * gnizzvsuof = irx2av1ofg ; * kem0wzjelw =
ntacjmujus ; } void bgtcatk3m4 ( ksbim0l5cn * localB , a1psbvqfed * localDW ,
jz3icdjngh * localP ) { localDW -> kekyx2w2xd = localP ->
Memory_InitialCondition ; localB -> injnyz4auw = localP -> phi_Y0 ; } void
fbciyjdijr ( real_T l2adjlobrb , real_T k4fba5wlhb , real_T emhbmza453 ,
real_T ba0y1gt5aq , real_T ccdqnvofws , real_T cm0wwo2ob2 , ksbim0l5cn *
localB , a1psbvqfed * localDW , jz3icdjngh * localP ) { int8_T s62_iter ;
real_T ooo4w03yom ; real_T ogoojgfkhs ; real_T bxvj34srxj ; s62_iter = 1 ; do
{ if ( s62_iter > localP -> Switch_Threshold ) { bxvj34srxj = localDW ->
kekyx2w2xd ; } else { bxvj34srxj = muDoubleScalarAtan2 ( k4fba5wlhb ,
ba0y1gt5aq * l2adjlobrb ) ; } muDoubleScalarSinCos ( bxvj34srxj , &
ooo4w03yom , & ogoojgfkhs ) ; localB -> injnyz4auw = muDoubleScalarAtan2 (
cm0wwo2ob2 * emhbmza453 * ooo4w03yom * ooo4w03yom * ooo4w03yom + k4fba5wlhb ,
l2adjlobrb - ogoojgfkhs * ogoojgfkhs * ogoojgfkhs * ccdqnvofws * localP ->
Constant1_Value ) ; muDoubleScalarSinCos ( localB -> injnyz4auw , &
ooo4w03yom , & ogoojgfkhs ) ; ooo4w03yom = muDoubleScalarAtan2 ( ba0y1gt5aq *
ooo4w03yom , ogoojgfkhs ) ; localDW -> kekyx2w2xd = ooo4w03yom ; s62_iter ++
; } while ( ( bxvj34srxj != ooo4w03yom ) && ( s62_iter <= 5 ) ) ; } void
bq3pldfcaq ( const real_T igeihs2dha [ 4 ] , m22jb12str * localB , real_T
rtp_zero_tol ) { real_T n ; n = muDoubleScalarSqrt ( ( ( igeihs2dha [ 0 ] *
igeihs2dha [ 0 ] + igeihs2dha [ 1 ] * igeihs2dha [ 1 ] ) + igeihs2dha [ 2 ] *
igeihs2dha [ 2 ] ) + igeihs2dha [ 3 ] * igeihs2dha [ 3 ] ) ; if ( n <
rtp_zero_tol ) { localB -> nkouc1qloz [ 0 ] = 1.0 ; localB -> nkouc1qloz [ 1
] = 0.0 ; localB -> nkouc1qloz [ 2 ] = 0.0 ; localB -> nkouc1qloz [ 3 ] = 0.0
; } else { localB -> nkouc1qloz [ 0 ] = igeihs2dha [ 0 ] / n ; localB ->
nkouc1qloz [ 1 ] = igeihs2dha [ 1 ] / n ; localB -> nkouc1qloz [ 2 ] =
igeihs2dha [ 2 ] / n ; localB -> nkouc1qloz [ 3 ] = igeihs2dha [ 3 ] / n ; }
} void lj0sp02vlx ( const real_T dntfbtekfo [ 4 ] , hkf1pxdbyl * localB ) {
if ( dntfbtekfo [ 0 ] < 0.0 ) { localB -> fdh2hm3qwy [ 0 ] = - dntfbtekfo [ 0
] ; localB -> fdh2hm3qwy [ 1 ] = - dntfbtekfo [ 1 ] ; localB -> fdh2hm3qwy [
2 ] = - dntfbtekfo [ 2 ] ; localB -> fdh2hm3qwy [ 3 ] = - dntfbtekfo [ 3 ] ;
} else { localB -> fdh2hm3qwy [ 0 ] = dntfbtekfo [ 0 ] ; localB -> fdh2hm3qwy
[ 1 ] = dntfbtekfo [ 1 ] ; localB -> fdh2hm3qwy [ 2 ] = dntfbtekfo [ 2 ] ;
localB -> fdh2hm3qwy [ 3 ] = dntfbtekfo [ 3 ] ; } } void lawi0f5r5l ( const
real_T crhh2dktyy [ 3 ] , const real_T dq1ejiwfqi [ 3 ] , a4l2akdomh * localB
) { real_T tmp [ 9 ] ; int32_T i ; tmp [ 0 ] = 0.0 ; tmp [ 3 ] = - crhh2dktyy
[ 2 ] ; tmp [ 6 ] = crhh2dktyy [ 1 ] ; tmp [ 1 ] = crhh2dktyy [ 2 ] ; tmp [ 4
] = 0.0 ; tmp [ 7 ] = - crhh2dktyy [ 0 ] ; tmp [ 2 ] = - crhh2dktyy [ 1 ] ;
tmp [ 5 ] = crhh2dktyy [ 0 ] ; tmp [ 8 ] = 0.0 ; for ( i = 0 ; i < 3 ; i ++ )
{ localB -> jgjuew1xpe [ i ] = 0.0 ; localB -> jgjuew1xpe [ i ] += tmp [ i ]
* dq1ejiwfqi [ 0 ] ; localB -> jgjuew1xpe [ i ] += tmp [ i + 3 ] * dq1ejiwfqi
[ 1 ] ; localB -> jgjuew1xpe [ i ] += tmp [ i + 6 ] * dq1ejiwfqi [ 2 ] ; } }
void lq4jylha0o ( const real_T ggefvq31ri [ 9 ] , l5n2ev1vfg * localB ,
real_T rtp_tol ) { boolean_T isodd ; real_T A [ 9 ] ; int8_T ipiv [ 3 ] ;
int32_T p1 ; int32_T p2 ; real_T absx21 ; real_T absx31 ; int32_T ix ; real_T
smax ; int32_T iy ; int32_T jA ; int32_T c_ix ; int32_T d ; int32_T ijA ;
memcpy ( & A [ 0 ] , & ggefvq31ri [ 0 ] , 9U * sizeof ( real_T ) ) ; ipiv [ 0
] = 1 ; ipiv [ 1 ] = 2 ; for ( p1 = 0 ; p1 < 2 ; p1 ++ ) { p2 = p1 << 2 ; jA
= 0 ; ix = p2 ; smax = muDoubleScalarAbs ( A [ p2 ] ) ; for ( iy = 2 ; iy <=
3 - p1 ; iy ++ ) { ix ++ ; absx21 = muDoubleScalarAbs ( A [ ix ] ) ; if (
absx21 > smax ) { jA = iy - 1 ; smax = absx21 ; } } if ( A [ p2 + jA ] != 0.0
) { if ( jA != 0 ) { ipiv [ p1 ] = ( int8_T ) ( ( p1 + jA ) + 1 ) ; iy = p1 +
jA ; smax = A [ p1 ] ; A [ p1 ] = A [ iy ] ; A [ iy ] = smax ; ix = p1 + 3 ;
iy += 3 ; smax = A [ ix ] ; A [ ix ] = A [ iy ] ; A [ iy ] = smax ; ix += 3 ;
iy += 3 ; smax = A [ ix ] ; A [ ix ] = A [ iy ] ; A [ iy ] = smax ; } jA = (
p2 - p1 ) + 3 ; for ( ix = p2 + 1 ; ix < jA ; ix ++ ) { A [ ix ] /= A [ p2 ]
; } } jA = p2 ; ix = p2 + 3 ; for ( iy = 0 ; iy <= 1 - p1 ; iy ++ ) { if ( A
[ ix ] != 0.0 ) { smax = - A [ ix ] ; c_ix = p2 + 1 ; d = ( jA - p1 ) + 6 ;
for ( ijA = jA + 4 ; ijA < d ; ijA ++ ) { A [ ijA ] += A [ c_ix ] * smax ;
c_ix ++ ; } } ix += 3 ; jA += 3 ; } } isodd = ( ipiv [ 0 ] > 1 ) ; smax = A [
0 ] * A [ 4 ] * A [ 8 ] ; if ( ipiv [ 1 ] > 2 ) { isodd = ! isodd ; } if (
isodd ) { smax = - smax ; } if ( muDoubleScalarAbs ( smax ) <= rtp_tol ) {
memset ( & localB -> gyjfwigx2h [ 0 ] , 0 , 9U * sizeof ( real_T ) ) ; } else
{ memcpy ( & A [ 0 ] , & ggefvq31ri [ 0 ] , 9U * sizeof ( real_T ) ) ; p1 = 0
; p2 = 3 ; jA = 6 ; smax = muDoubleScalarAbs ( ggefvq31ri [ 0 ] ) ; absx21 =
muDoubleScalarAbs ( ggefvq31ri [ 1 ] ) ; absx31 = muDoubleScalarAbs (
ggefvq31ri [ 2 ] ) ; if ( ( absx21 > smax ) && ( absx21 > absx31 ) ) { p1 = 3
; p2 = 0 ; A [ 0 ] = ggefvq31ri [ 1 ] ; A [ 1 ] = ggefvq31ri [ 0 ] ; A [ 3 ]
= ggefvq31ri [ 4 ] ; A [ 4 ] = ggefvq31ri [ 3 ] ; A [ 6 ] = ggefvq31ri [ 7 ]
; A [ 7 ] = ggefvq31ri [ 6 ] ; } else { if ( absx31 > smax ) { p1 = 6 ; jA =
0 ; A [ 0 ] = ggefvq31ri [ 2 ] ; A [ 2 ] = ggefvq31ri [ 0 ] ; A [ 3 ] =
ggefvq31ri [ 5 ] ; A [ 5 ] = ggefvq31ri [ 3 ] ; A [ 6 ] = ggefvq31ri [ 8 ] ;
A [ 8 ] = ggefvq31ri [ 6 ] ; } } smax = A [ 1 ] / A [ 0 ] ; A [ 1 ] /= A [ 0
] ; absx21 = A [ 2 ] / A [ 0 ] ; A [ 2 ] /= A [ 0 ] ; A [ 4 ] -= smax * A [ 3
] ; A [ 5 ] -= absx21 * A [ 3 ] ; A [ 7 ] -= smax * A [ 6 ] ; A [ 8 ] -=
absx21 * A [ 6 ] ; if ( muDoubleScalarAbs ( A [ 5 ] ) > muDoubleScalarAbs ( A
[ 4 ] ) ) { ix = p2 ; p2 = jA ; jA = ix ; A [ 1 ] = absx21 ; A [ 2 ] = smax ;
smax = A [ 4 ] ; A [ 4 ] = A [ 5 ] ; A [ 5 ] = smax ; smax = A [ 7 ] ; A [ 7
] = A [ 8 ] ; A [ 8 ] = smax ; } smax = A [ 5 ] / A [ 4 ] ; A [ 5 ] /= A [ 4
] ; A [ 8 ] -= smax * A [ 7 ] ; smax = ( A [ 5 ] * A [ 1 ] - A [ 2 ] ) / A [
8 ] ; absx21 = - ( A [ 7 ] * smax + A [ 1 ] ) / A [ 4 ] ; localB ->
gyjfwigx2h [ p1 ] = ( ( 1.0 - A [ 3 ] * absx21 ) - A [ 6 ] * smax ) / A [ 0 ]
; localB -> gyjfwigx2h [ p1 + 1 ] = absx21 ; localB -> gyjfwigx2h [ p1 + 2 ]
= smax ; smax = - A [ 5 ] / A [ 8 ] ; absx21 = ( 1.0 - A [ 7 ] * smax ) / A [
4 ] ; localB -> gyjfwigx2h [ p2 ] = - ( A [ 3 ] * absx21 + A [ 6 ] * smax ) /
A [ 0 ] ; localB -> gyjfwigx2h [ p2 + 1 ] = absx21 ; localB -> gyjfwigx2h [
p2 + 2 ] = smax ; smax = 1.0 / A [ 8 ] ; absx21 = - A [ 7 ] * smax / A [ 4 ]
; localB -> gyjfwigx2h [ jA ] = - ( A [ 3 ] * absx21 + A [ 6 ] * smax ) / A [
0 ] ; localB -> gyjfwigx2h [ jA + 1 ] = absx21 ; localB -> gyjfwigx2h [ jA +
2 ] = smax ; } } void evxgoynfhh ( const real_T njpgwwuzhd [ 9 ] , fuvgor4n5v
* localB , real_T rtp_tol ) { lq4jylha0o ( njpgwwuzhd , & localB ->
mqozl5xj12 , rtp_tol ) ; } void kaa1h5fw2d ( const real_T lmcmusx0h4 [ 9 ] ,
etjlh4l4yf * localB ) { real_T qw_sq ; real_T qx_sq ; real_T qy_sq ; real_T
qz_sq ; int32_T k ; real_T varargin_1 [ 4 ] ; real_T ex ; int32_T b_k ;
boolean_T exitg1 ; qw_sq = ( ( ( lmcmusx0h4 [ 0 ] + lmcmusx0h4 [ 4 ] ) +
lmcmusx0h4 [ 8 ] ) + 1.0 ) * 0.25 ; qx_sq = ( ( ( lmcmusx0h4 [ 0 ] + 1.0 ) -
lmcmusx0h4 [ 4 ] ) - lmcmusx0h4 [ 8 ] ) * 0.25 ; qy_sq = ( ( ( lmcmusx0h4 [ 4
] + 1.0 ) - lmcmusx0h4 [ 0 ] ) - lmcmusx0h4 [ 8 ] ) * 0.25 ; qz_sq = ( ( (
lmcmusx0h4 [ 8 ] + 1.0 ) - lmcmusx0h4 [ 0 ] ) - lmcmusx0h4 [ 4 ] ) * 0.25 ;
varargin_1 [ 0 ] = qw_sq ; varargin_1 [ 1 ] = qx_sq ; varargin_1 [ 2 ] =
qy_sq ; varargin_1 [ 3 ] = qz_sq ; if ( ! muDoubleScalarIsNaN ( qw_sq ) ) { k
= 1 ; } else { k = 0 ; b_k = 2 ; exitg1 = false ; while ( ( ! exitg1 ) && (
b_k < 5 ) ) { if ( ! muDoubleScalarIsNaN ( varargin_1 [ b_k - 1 ] ) ) { k =
b_k ; exitg1 = true ; } else { b_k ++ ; } } } if ( k == 0 ) { k = 1 ; } else
{ ex = varargin_1 [ k - 1 ] ; for ( b_k = k ; b_k < 4 ; b_k ++ ) { if ( ex <
varargin_1 [ b_k ] ) { ex = varargin_1 [ b_k ] ; k = b_k + 1 ; } } } if ( k
== 1 ) { qx_sq = muDoubleScalarSqrt ( qw_sq ) ; localB -> apia2ki5qj [ 1 ] =
( lmcmusx0h4 [ 7 ] - lmcmusx0h4 [ 5 ] ) * 0.25 / qx_sq ; localB -> apia2ki5qj
[ 2 ] = ( lmcmusx0h4 [ 2 ] - lmcmusx0h4 [ 6 ] ) * 0.25 / qx_sq ; localB ->
apia2ki5qj [ 3 ] = ( lmcmusx0h4 [ 3 ] - lmcmusx0h4 [ 1 ] ) * 0.25 / qx_sq ; }
else if ( k == 2 ) { qy_sq = muDoubleScalarSqrt ( qx_sq ) ; localB ->
apia2ki5qj [ 1 ] = muDoubleScalarSqrt ( qx_sq ) ; qx_sq = ( lmcmusx0h4 [ 7 ]
- lmcmusx0h4 [ 5 ] ) * 0.25 / qy_sq ; localB -> apia2ki5qj [ 2 ] = (
lmcmusx0h4 [ 3 ] + lmcmusx0h4 [ 1 ] ) * 0.25 / qy_sq ; localB -> apia2ki5qj [
3 ] = ( lmcmusx0h4 [ 2 ] + lmcmusx0h4 [ 6 ] ) * 0.25 / qy_sq ; } else if ( k
== 3 ) { qz_sq = muDoubleScalarSqrt ( qy_sq ) ; localB -> apia2ki5qj [ 2 ] =
muDoubleScalarSqrt ( qy_sq ) ; qx_sq = ( lmcmusx0h4 [ 2 ] - lmcmusx0h4 [ 6 ]
) * 0.25 / qz_sq ; localB -> apia2ki5qj [ 1 ] = ( lmcmusx0h4 [ 3 ] +
lmcmusx0h4 [ 1 ] ) * 0.25 / qz_sq ; localB -> apia2ki5qj [ 3 ] = ( lmcmusx0h4
[ 7 ] + lmcmusx0h4 [ 5 ] ) * 0.25 / qz_sq ; } else { qy_sq =
muDoubleScalarSqrt ( qz_sq ) ; localB -> apia2ki5qj [ 3 ] =
muDoubleScalarSqrt ( qz_sq ) ; qx_sq = ( lmcmusx0h4 [ 3 ] - lmcmusx0h4 [ 1 ]
) * 0.25 / qy_sq ; localB -> apia2ki5qj [ 1 ] = ( lmcmusx0h4 [ 2 ] +
lmcmusx0h4 [ 6 ] ) * 0.25 / qy_sq ; localB -> apia2ki5qj [ 2 ] = ( lmcmusx0h4
[ 7 ] + lmcmusx0h4 [ 5 ] ) * 0.25 / qy_sq ; } localB -> apia2ki5qj [ 0 ] =
qx_sq ; } void ok5kaek4lx ( SimStruct * rtS_p , real_T ppwcvhq504 ,
cv3otbwh2x * localDW ) { int32_T tmp ; int32_T s152_iter ; if ( ppwcvhq504 <
2.147483648E+9 ) { if ( ppwcvhq504 >= - 2.147483648E+9 ) { tmp = ( int32_T )
ppwcvhq504 ; } else { tmp = MIN_int32_T ; } } else if ( ppwcvhq504 >=
2.147483648E+9 ) { tmp = MAX_int32_T ; } else { tmp = 0 ; } if ( tmp >
2147483646 ) { tmp = 2147483646 ; } else { if ( tmp < 0 ) { tmp = 0 ; } } for
( s152_iter = 1 ; s152_iter <= tmp ; s152_iter ++ ) { if ( ssIsMajorTimeStep
( rtS_p ) ) { srUpdateBC ( localDW -> p0optqqzsf ) ; } } } void fq0ya2wvxm (
real_T rtp_ncm ) { int32_T s153_iter ; for ( s153_iter = 1 ; s153_iter <=
rtp_ncm ; s153_iter ++ ) { } } void cuzz03aam2 ( SimStruct * rtS_g , real_T
c3saaxlv5m , g4j2xx02c4 * localDW ) { int32_T tmp ; int32_T s157_iter ; if (
c3saaxlv5m < 2.147483648E+9 ) { if ( c3saaxlv5m >= - 2.147483648E+9 ) { tmp =
( int32_T ) c3saaxlv5m ; } else { tmp = MIN_int32_T ; } } else if (
c3saaxlv5m >= 2.147483648E+9 ) { tmp = MAX_int32_T ; } else { tmp = 0 ; } if
( tmp > 2147483646 ) { tmp = 2147483646 ; } else { if ( tmp < 0 ) { tmp = 0 ;
} } for ( s157_iter = 1 ; s157_iter <= tmp ; s157_iter ++ ) { if (
ssIsMajorTimeStep ( rtS_g ) ) { srUpdateBC ( localDW -> d343bhqapn ) ; } } }
void ouhnihomld ( cvvampj2zd * localP ) { int32_T s158_iter ; for ( s158_iter
= 1 ; s158_iter <= localP -> ncm_IterationLimit ; s158_iter ++ ) { } } void
eeqgjz4lp4 ( const real_T dzmm1zlrir [ 3 ] , b2kmkl3wcw * localB , real_T
rtp_mu_cst ) { real_T rnorm ; real_T scale ; real_T absxk ; real_T t ; scale
= 3.3121686421112381E-170 ; absxk = muDoubleScalarAbs ( dzmm1zlrir [ 0 ] ) ;
if ( absxk > 3.3121686421112381E-170 ) { rnorm = 1.0 ; scale = absxk ; } else
{ t = absxk / 3.3121686421112381E-170 ; rnorm = t * t ; } absxk =
muDoubleScalarAbs ( dzmm1zlrir [ 1 ] ) ; if ( absxk > scale ) { t = scale /
absxk ; rnorm = rnorm * t * t + 1.0 ; scale = absxk ; } else { t = absxk /
scale ; rnorm += t * t ; } absxk = muDoubleScalarAbs ( dzmm1zlrir [ 2 ] ) ;
if ( absxk > scale ) { t = scale / absxk ; rnorm = rnorm * t * t + 1.0 ;
scale = absxk ; } else { t = absxk / scale ; rnorm += t * t ; } rnorm = scale
* muDoubleScalarSqrt ( rnorm ) ; rnorm = - rtp_mu_cst / ( rnorm * rnorm *
rnorm ) ; localB -> kfmst3u5d3 [ 0 ] = rnorm * dzmm1zlrir [ 0 ] ; localB ->
kfmst3u5d3 [ 1 ] = rnorm * dzmm1zlrir [ 1 ] ; localB -> kfmst3u5d3 [ 2 ] =
rnorm * dzmm1zlrir [ 2 ] ; } void fzzz0da3bp ( const real_T prnirli1yc [ 4 ]
, kzmuyenout * localB ) { localB -> otpij24kr0 [ 0 ] = prnirli1yc [ 0 ] ;
localB -> otpij24kr0 [ 1 ] = - prnirli1yc [ 1 ] ; localB -> otpij24kr0 [ 2 ]
= - prnirli1yc [ 2 ] ; localB -> otpij24kr0 [ 3 ] = - prnirli1yc [ 3 ] ; }
static void pxb1ugk451 ( const real_T Aq_B [ 4 ] , const real_T Bq_C [ 4 ] ,
real_T Aq_C [ 4 ] ) { real_T r [ 4 ] ; real_T Aq_B_p [ 16 ] ; int32_T i ;
real_T r_p ; Aq_B_p [ 0 ] = Aq_B [ 0 ] ; Aq_B_p [ 4 ] = - Aq_B [ 1 ] ; Aq_B_p
[ 8 ] = - Aq_B [ 2 ] ; Aq_B_p [ 12 ] = - Aq_B [ 3 ] ; Aq_B_p [ 1 ] = Aq_B [ 1
] ; Aq_B_p [ 5 ] = Aq_B [ 0 ] ; Aq_B_p [ 9 ] = Aq_B [ 3 ] ; Aq_B_p [ 13 ] = -
Aq_B [ 2 ] ; Aq_B_p [ 2 ] = Aq_B [ 2 ] ; Aq_B_p [ 6 ] = - Aq_B [ 3 ] ; Aq_B_p
[ 10 ] = Aq_B [ 0 ] ; Aq_B_p [ 14 ] = Aq_B [ 1 ] ; Aq_B_p [ 3 ] = Aq_B [ 3 ]
; Aq_B_p [ 7 ] = Aq_B [ 2 ] ; Aq_B_p [ 11 ] = - Aq_B [ 1 ] ; Aq_B_p [ 15 ] =
Aq_B [ 0 ] ; for ( i = 0 ; i < 4 ; i ++ ) { r_p = Aq_B_p [ i + 12 ] * Bq_C [
3 ] + ( Aq_B_p [ i + 8 ] * Bq_C [ 2 ] + ( Aq_B_p [ i + 4 ] * Bq_C [ 1 ] +
Aq_B_p [ i ] * Bq_C [ 0 ] ) ) ; r [ i ] = r_p ; } Aq_C [ 0 ] = r [ 0 ] ; Aq_C
[ 1 ] = r [ 1 ] ; Aq_C [ 2 ] = r [ 2 ] ; Aq_C [ 3 ] = r [ 3 ] ; } void
fl3fthyqxf ( const real_T mi30ylmvcj [ 4 ] , const real_T oizfekbc3t [ 3 ] ,
i2abnoyfrw * localB ) { real_T q [ 4 ] ; real_T Bq_A [ 4 ] ; real_T tmp [ 4 ]
; real_T tmp_p [ 4 ] ; q [ 0 ] = mi30ylmvcj [ 0 ] ; q [ 1 ] = mi30ylmvcj [ 1
] ; q [ 2 ] = mi30ylmvcj [ 2 ] ; q [ 3 ] = mi30ylmvcj [ 3 ] ; Bq_A [ 0 ] =
mi30ylmvcj [ 0 ] ; Bq_A [ 1 ] = - mi30ylmvcj [ 1 ] ; Bq_A [ 2 ] = -
mi30ylmvcj [ 2 ] ; Bq_A [ 3 ] = - mi30ylmvcj [ 3 ] ; tmp [ 0 ] = 0.0 ; tmp [
1 ] = oizfekbc3t [ 0 ] ; tmp [ 2 ] = oizfekbc3t [ 1 ] ; tmp [ 3 ] =
oizfekbc3t [ 2 ] ; pxb1ugk451 ( q , tmp , tmp_p ) ; pxb1ugk451 ( tmp_p , Bq_A
, q ) ; localB -> grgp0ja04k [ 0 ] = q [ 1 ] ; localB -> grgp0ja04k [ 1 ] = q
[ 2 ] ; localB -> grgp0ja04k [ 2 ] = q [ 3 ] ; } static void chjngh2jei (
const real_T Aq_B [ 4 ] , const real_T Bq_C [ 4 ] , real_T Aq_C [ 4 ] ) {
real_T r [ 4 ] ; real_T Aq_B_p [ 16 ] ; int32_T i ; real_T r_p ; Aq_B_p [ 0 ]
= Aq_B [ 0 ] ; Aq_B_p [ 4 ] = - Aq_B [ 1 ] ; Aq_B_p [ 8 ] = - Aq_B [ 2 ] ;
Aq_B_p [ 12 ] = - Aq_B [ 3 ] ; Aq_B_p [ 1 ] = Aq_B [ 1 ] ; Aq_B_p [ 5 ] =
Aq_B [ 0 ] ; Aq_B_p [ 9 ] = Aq_B [ 3 ] ; Aq_B_p [ 13 ] = - Aq_B [ 2 ] ;
Aq_B_p [ 2 ] = Aq_B [ 2 ] ; Aq_B_p [ 6 ] = - Aq_B [ 3 ] ; Aq_B_p [ 10 ] =
Aq_B [ 0 ] ; Aq_B_p [ 14 ] = Aq_B [ 1 ] ; Aq_B_p [ 3 ] = Aq_B [ 3 ] ; Aq_B_p
[ 7 ] = Aq_B [ 2 ] ; Aq_B_p [ 11 ] = - Aq_B [ 1 ] ; Aq_B_p [ 15 ] = Aq_B [ 0
] ; for ( i = 0 ; i < 4 ; i ++ ) { r_p = Aq_B_p [ i + 12 ] * Bq_C [ 3 ] + (
Aq_B_p [ i + 8 ] * Bq_C [ 2 ] + ( Aq_B_p [ i + 4 ] * Bq_C [ 1 ] + Aq_B_p [ i
] * Bq_C [ 0 ] ) ) ; r [ i ] = r_p ; } Aq_C [ 0 ] = r [ 0 ] ; Aq_C [ 1 ] = r
[ 1 ] ; Aq_C [ 2 ] = r [ 2 ] ; Aq_C [ 3 ] = r [ 3 ] ; } void esmxkiztnv (
const real_T jzjcyn04b1 [ 4 ] , const real_T mbfatxlkvy [ 3 ] , gi1ufbotw1 *
localB ) { real_T q [ 4 ] ; real_T Bq_A [ 4 ] ; real_T tmp [ 4 ] ; real_T
tmp_p [ 4 ] ; q [ 0 ] = jzjcyn04b1 [ 0 ] ; q [ 1 ] = jzjcyn04b1 [ 1 ] ; q [ 2
] = jzjcyn04b1 [ 2 ] ; q [ 3 ] = jzjcyn04b1 [ 3 ] ; Bq_A [ 0 ] = jzjcyn04b1 [
0 ] ; Bq_A [ 1 ] = - jzjcyn04b1 [ 1 ] ; Bq_A [ 2 ] = - jzjcyn04b1 [ 2 ] ;
Bq_A [ 3 ] = - jzjcyn04b1 [ 3 ] ; tmp [ 0 ] = 0.0 ; tmp [ 1 ] = mbfatxlkvy [
0 ] ; tmp [ 2 ] = mbfatxlkvy [ 1 ] ; tmp [ 3 ] = mbfatxlkvy [ 2 ] ;
chjngh2jei ( q , tmp , tmp_p ) ; chjngh2jei ( tmp_p , Bq_A , q ) ; localB ->
ihykyxkclc [ 0 ] = q [ 1 ] ; localB -> ihykyxkclc [ 1 ] = q [ 2 ] ; localB ->
ihykyxkclc [ 2 ] = q [ 3 ] ; } static void p2ulm3jjpb ( const real_T Aq_B [ 4
] , const real_T Bq_C [ 4 ] , real_T Aq_C [ 4 ] ) { real_T r [ 4 ] ; real_T
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
Aq_C [ 3 ] = r [ 3 ] ; } void noxmrm1w5f ( const real_T dvfj0lqlly [ 4 ] ,
const real_T aa0wr4mki1 [ 3 ] , pekwweku3r * localB ) { real_T q [ 4 ] ;
real_T Bq_A [ 4 ] ; real_T tmp [ 4 ] ; real_T tmp_p [ 4 ] ; q [ 0 ] =
dvfj0lqlly [ 0 ] ; q [ 1 ] = dvfj0lqlly [ 1 ] ; q [ 2 ] = dvfj0lqlly [ 2 ] ;
q [ 3 ] = dvfj0lqlly [ 3 ] ; Bq_A [ 0 ] = dvfj0lqlly [ 0 ] ; Bq_A [ 1 ] = -
dvfj0lqlly [ 1 ] ; Bq_A [ 2 ] = - dvfj0lqlly [ 2 ] ; Bq_A [ 3 ] = -
dvfj0lqlly [ 3 ] ; tmp [ 0 ] = 0.0 ; tmp [ 1 ] = aa0wr4mki1 [ 0 ] ; tmp [ 2 ]
= aa0wr4mki1 [ 1 ] ; tmp [ 3 ] = aa0wr4mki1 [ 2 ] ; p2ulm3jjpb ( q , tmp ,
tmp_p ) ; p2ulm3jjpb ( tmp_p , Bq_A , q ) ; localB -> elfsvtngpi [ 0 ] = q [
1 ] ; localB -> elfsvtngpi [ 1 ] = q [ 2 ] ; localB -> elfsvtngpi [ 2 ] = q [
3 ] ; } void evg4tqc010 ( const real_T j4krvvcvt3 [ 4 ] , edmvwng2i4 * localB
) { localB -> pl0ikyvvgy [ 0 ] = muDoubleScalarAtan2 ( ( j4krvvcvt3 [ 1 ] *
j4krvvcvt3 [ 0 ] + j4krvvcvt3 [ 3 ] * j4krvvcvt3 [ 2 ] ) * 2.0 , ( (
j4krvvcvt3 [ 0 ] * j4krvvcvt3 [ 0 ] - j4krvvcvt3 [ 1 ] * j4krvvcvt3 [ 1 ] ) -
j4krvvcvt3 [ 2 ] * j4krvvcvt3 [ 2 ] ) + j4krvvcvt3 [ 3 ] * j4krvvcvt3 [ 3 ] )
; localB -> pl0ikyvvgy [ 1 ] = muDoubleScalarAsin ( ( j4krvvcvt3 [ 2 ] *
j4krvvcvt3 [ 0 ] - j4krvvcvt3 [ 1 ] * j4krvvcvt3 [ 3 ] ) * 2.0 ) ; localB ->
pl0ikyvvgy [ 2 ] = muDoubleScalarAtan2 ( ( j4krvvcvt3 [ 1 ] * j4krvvcvt3 [ 2
] + j4krvvcvt3 [ 3 ] * j4krvvcvt3 [ 0 ] ) * 2.0 , ( ( j4krvvcvt3 [ 0 ] *
j4krvvcvt3 [ 0 ] + j4krvvcvt3 [ 1 ] * j4krvvcvt3 [ 1 ] ) - j4krvvcvt3 [ 2 ] *
j4krvvcvt3 [ 2 ] ) - j4krvvcvt3 [ 3 ] * j4krvvcvt3 [ 3 ] ) ; } static void
nsbxylmapa ( real_T * x ) { int8_T n ; real_T b_x ; real_T absx ; if (
muDoubleScalarIsInf ( * x ) || muDoubleScalarIsNaN ( * x ) ) { * x = ( rtNaN
) ; } else { b_x = muDoubleScalarRem ( * x , 360.0 ) ; absx =
muDoubleScalarAbs ( b_x ) ; if ( absx > 180.0 ) { if ( b_x > 0.0 ) { b_x -=
360.0 ; } else { b_x += 360.0 ; } absx = muDoubleScalarAbs ( b_x ) ; } if (
absx <= 45.0 ) { b_x *= 0.017453292519943295 ; * x = muDoubleScalarCos ( b_x
) ; } else { if ( absx <= 135.0 ) { if ( b_x > 0.0 ) { b_x = ( b_x - 90.0 ) *
0.017453292519943295 ; n = 1 ; } else { b_x = ( b_x + 90.0 ) *
0.017453292519943295 ; n = - 1 ; } } else if ( b_x > 0.0 ) { b_x = ( b_x -
180.0 ) * 0.017453292519943295 ; n = 2 ; } else { b_x = ( b_x + 180.0 ) *
0.017453292519943295 ; n = - 2 ; } if ( n == 1 ) { * x = - muDoubleScalarSin
( b_x ) ; } else if ( n == - 1 ) { * x = muDoubleScalarSin ( b_x ) ; } else {
* x = - muDoubleScalarCos ( b_x ) ; } } } } static void be4dle1kpx ( real_T *
x ) { int8_T n ; real_T c_x ; real_T absx ; if ( muDoubleScalarIsInf ( * x )
|| muDoubleScalarIsNaN ( * x ) ) { * x = ( rtNaN ) ; } else { c_x =
muDoubleScalarRem ( * x , 360.0 ) ; absx = muDoubleScalarAbs ( c_x ) ; if (
absx > 180.0 ) { if ( c_x > 0.0 ) { c_x -= 360.0 ; } else { c_x += 360.0 ; }
absx = muDoubleScalarAbs ( c_x ) ; } if ( absx <= 45.0 ) { c_x *=
0.017453292519943295 ; * x = muDoubleScalarSin ( c_x ) ; } else { if ( absx
<= 135.0 ) { if ( c_x > 0.0 ) { c_x = ( c_x - 90.0 ) * 0.017453292519943295 ;
n = 1 ; } else { c_x = ( c_x + 90.0 ) * 0.017453292519943295 ; n = - 1 ; } }
else if ( c_x > 0.0 ) { c_x = ( c_x - 180.0 ) * 0.017453292519943295 ; n = 2
; } else { c_x = ( c_x + 180.0 ) * 0.017453292519943295 ; n = - 2 ; } if ( n
== 1 ) { * x = muDoubleScalarCos ( c_x ) ; } else if ( n == - 1 ) { * x = -
muDoubleScalarCos ( c_x ) ; } else { * x = - muDoubleScalarSin ( c_x ) ; } }
} } void MdlInitialize ( void ) { rtX . e5l2wmdpfb [ 0 ] = rtP . DYN_ATT_par
. h_BOF_ini [ 0 ] ; rtX . mes33bxk5w [ 0 ] = rtP . DYN_TRA_par . pos_ECI_ini
[ 0 ] ; rtX . agflyx222j [ 0 ] = rtP . DYN_TRA_par . vel_ECI_ini [ 0 ] ; rtX
. e5l2wmdpfb [ 1 ] = rtP . DYN_ATT_par . h_BOF_ini [ 1 ] ; rtX . mes33bxk5w [
1 ] = rtP . DYN_TRA_par . pos_ECI_ini [ 1 ] ; rtX . agflyx222j [ 1 ] = rtP .
DYN_TRA_par . vel_ECI_ini [ 1 ] ; rtX . e5l2wmdpfb [ 2 ] = rtP . DYN_ATT_par
. h_BOF_ini [ 2 ] ; rtX . mes33bxk5w [ 2 ] = rtP . DYN_TRA_par . pos_ECI_ini
[ 2 ] ; rtX . agflyx222j [ 2 ] = rtP . DYN_TRA_par . vel_ECI_ini [ 2 ] ; rtX
. mqqxdp0em5 [ 0 ] = rtP . DYN_ATT_par . BOFq_ECI_ini [ 0 ] ; rtX .
mqqxdp0em5 [ 1 ] = rtP . DYN_ATT_par . BOFq_ECI_ini [ 1 ] ; rtX . mqqxdp0em5
[ 2 ] = rtP . DYN_ATT_par . BOFq_ECI_ini [ 2 ] ; rtX . mqqxdp0em5 [ 3 ] = rtP
. DYN_ATT_par . BOFq_ECI_ini [ 3 ] ; rtDW . pttppk3jcp = rtP .
otime_InitialCondition ; rtDW . ay1crq4gjz = rtP . olon_InitialCondition ;
rtDW . cws51k2ewn = rtP . olat_InitialCondition ; rtDW . d4vvv2k2v3 = rtP .
oalt_InitialCondition ; rtDW . d2miu0jpen = ( rtInf ) ; rtDW . pxvqpp25ev = (
rtInf ) ; rtDW . hhrhjkqm2k = ( rtInf ) ; rtDW . cqqd21gc1k = ( rtInf ) ;
bgtcatk3m4 ( & rtB . fbciyjdijrl , & rtDW . fbciyjdijrl , & rtP . fbciyjdijrl
) ; bgtcatk3m4 ( & rtB . kaatsalz40 , & rtDW . kaatsalz40 , & rtP .
kaatsalz40 ) ; rtDW . jbiuzi4aai [ 0 ] = rtP .
UnitDelay1_InitialCondition_bu0v3y4mz0 ; rtDW . jbiuzi4aai [ 1 ] = rtP .
UnitDelay1_InitialCondition_bu0v3y4mz0 ; memcpy ( & rtB . lqzgmigds5 [ 0 ] ,
& rtP . sp13_Y0 [ 0 ] , 13U * sizeof ( real_T ) ) ; memcpy ( & rtB .
p3gpuz1pzd [ 0 ] , & rtP . cp13_Y0 [ 0 ] , 13U * sizeof ( real_T ) ) ; rtB .
iqc2f25oqb = rtP . r_Y0 ; rtB . kwlbg5jb4t = rtP . ct_Y0 ; rtB . d2klb5ahil =
rtP . st_Y0 ; rtB . b0zlh5u3jc = rtP . sa_Y0 ; rtB . fqya1lnkpm = rtP . ca_Y0
; rtDW . ogsulvdfqo = rtP . UnitDelay_InitialCondition_dcdbfk2ii1 ; rtDW .
o1a1coezrh [ 0 ] = rtP . UnitDelay2_InitialCondition_boysunw0mm [ 0 ] ; rtDW
. o1a1coezrh [ 1 ] = rtP . UnitDelay2_InitialCondition_boysunw0mm [ 1 ] ;
rtDW . o1a1coezrh [ 2 ] = rtP . UnitDelay2_InitialCondition_boysunw0mm [ 2 ]
; rtDW . o1a1coezrh [ 3 ] = rtP . UnitDelay2_InitialCondition_boysunw0mm [ 3
] ; rtDW . oghbzylezs = rtP . UnitDelay1_InitialCondition_fhyfwa2bo2 ; rtDW .
l31233tzs5 = rtP . UnitDelay3_InitialCondition ; rtDW . oe4craxtsr = rtP .
UnitDelay2_InitialCondition ; rtDW . p3utuwbotk = rtP .
UnitDelay4_InitialCondition ; rtB . clqi5421sn = rtP . Merge1_InitialOutput ;
rtB . kvglegmnr2 = rtP . Merge_InitialOutput ; memcpy ( & rtDW . m35wdbwfjk [
0 ] , & rtP . UnitDelay_InitialCondition_gvr0gvtxcf [ 0 ] , 169U * sizeof (
real_T ) ) ; memcpy ( & rtDW . adfw0bsjev [ 0 ] , & rtP .
UnitDelay_InitialCondition_lns2pt5iyl [ 0 ] , 169U * sizeof ( real_T ) ) ;
memcpy ( & rtB . pr4mmdkig3 [ 0 ] , & rtP . tc1313_Y0 [ 0 ] , 169U * sizeof (
real_T ) ) ; memcpy ( & rtDW . bdtrovn01a [ 0 ] , & rtP .
UnitDelay_InitialCondition [ 0 ] , 169U * sizeof ( real_T ) ) ; memcpy ( &
rtDW . bwjkpamfxw [ 0 ] , & rtP . UnitDelay1_InitialCondition_p1upzq1u1r [ 0
] , 169U * sizeof ( real_T ) ) ; memcpy ( & rtB . orlxict5uw [ 0 ] , & rtP .
dp1313_Y0 [ 0 ] , 169U * sizeof ( real_T ) ) ; memcpy ( & rtB . n2aonouljp [
0 ] , & rtP . snorm169_Y0 [ 0 ] , 169U * sizeof ( real_T ) ) ; memcpy ( &
rtDW . gwnmkcjbc1 [ 0 ] , & rtP . UnitDelay1_InitialCondition [ 0 ] , 13U *
sizeof ( real_T ) ) ; memcpy ( & rtB . mqbqw1xcbl [ 0 ] , & rtP . pp13_Y0 [ 0
] , 13U * sizeof ( real_T ) ) ; memcpy ( & rtB . bxaxpwfsdh [ 0 ] , & rtP .
pp13_Y0_b320ukeyf3 [ 0 ] , 13U * sizeof ( real_T ) ) ; rtB . dhcl5bwk3d = rtP
. bpp_Y0 ; rtB . adgz4bd3kf = rtP . bt_Y0 ; rtB . cig0wmtt3m = rtP . bp_Y0 ;
rtB . o21kbr4mgl = rtP . br_Y0 ; rtB . bmbl2eeqey = rtP . bpp_Y0_fnr14vctj2 ;
rtB . kvihuxhnbc [ 0 ] = rtP . btbpbrbpp_Y0 [ 0 ] ; rtB . kvihuxhnbc [ 1 ] =
rtP . btbpbrbpp_Y0 [ 1 ] ; rtB . kvihuxhnbc [ 2 ] = rtP . btbpbrbpp_Y0 [ 2 ]
; rtB . kvihuxhnbc [ 3 ] = rtP . btbpbrbpp_Y0 [ 3 ] ; } void MdlStart ( void
) { void * catalog ; void * catalog_p ; void * catalog_e ; void * catalog_i ;
void * catalog_m ; void * catalog_g ; void * catalog_j ; void * catalog_f ;
void * catalog_c ; void * catalog_k ; { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
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
externalInputIsInDatasetFormat ) { } } { static int_T rt_ToWksWidths [ ] = {
4 } ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 4 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<BOFq_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/BOFq_ECI" ;
rtDW . gzbqcsyzkc . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "BOFq_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . gzbqcsyzkc .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "BOFrpy_ECI" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/BOFrpy_ECI"
; rtDW . gtgmcfoi3f . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "BOFrpy_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . gtgmcfoi3f .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<BOFw_relECI_BOF>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"TST_RWSWV2/DYN_SIGNAL_SAVE/BOFw_relECI_BOF" ; rtDW . dzb5en3ect . LoggedData
= rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"BOFw_relECI_BOF" , 1 , 0 , 1 , 1.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . dzb5en3ect . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 3 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 3
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "BOFw_relECI_BOF_degpersec" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"TST_RWSWV2/DYN_SIGNAL_SAVE/BOFw_relECI_BOF_degpersec" ; rtDW . id44yqi2er .
LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart (
rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"BOFw_relECI_BOF_degpersec" , 1 , 0 , 1 , 1.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . id44yqi2er . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 4 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 4
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "<ECEFq_ECI>" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"TST_RWSWV2/DYN_SIGNAL_SAVE/ECEFq_ECI" ; rtDW . a1dzmttfkg . LoggedData =
rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "ECEFq_ECI" , 1
, 0 , 1 , 1.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW .
a1dzmttfkg . LoggedData == ( NULL ) ) return ; } { static int_T
rt_ToWksWidths [ ] = { 4 } ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ;
static int_T rt_ToWksDimensions [ ] = { 4 } ; static boolean_T
rt_ToWksIsVarDims [ ] = { 0 } ; static void * rt_ToWksCurrSigDims [ ] = { (
NULL ) } ; static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static
BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_ToWksComplexSignals [ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0
} ; static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = {
( NULL ) } ; static const char_T * rt_ToWksLabels [ ] = { "<ECIq_ECEF>" } ;
static RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/ECIq_ECEF" ;
rtDW . jm4yyjoxrc . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ECIq_ECEF" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . jm4yyjoxrc .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<acc_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/acc_ECI" ;
rtDW . ghseczrajd . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "acc_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . ghseczrajd .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<aerofor_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/aerofor_ECI"
; rtDW . mqvqz0mc3o . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "aerofor_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . mqvqz0mc3o .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<aerotor_BOF>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/aerotor_ECI"
; rtDW . ffw1agfuzs . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "aerotor_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . ffw1agfuzs .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<extacc_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/extacc_ECI"
; rtDW . jxvmg11z51 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "extacc_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . jxvmg11z51 .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<extfor_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/extfor_ECI"
; rtDW . kuevle4fk1 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "extfor_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . kuevle4fk1 .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<exttor_BOF>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/exttor_BOF"
; rtDW . dj0y1a4rkp . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "exttor_BOF" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . dj0y1a4rkp .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<grvacc_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/grvacc_ECI"
; rtDW . anhptlbpor . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "grvacc_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . anhptlbpor .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<grvfor_BOF>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/grvfor_BOF"
; rtDW . nys0j5xotg . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "grvfor_BOF" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . nys0j5xotg .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<grvfor_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/grvfor_ECI"
; rtDW . ot4oqlzgej . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "grvfor_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . ot4oqlzgej .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<grvtor_BOF>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/grvtor_BOF"
; rtDW . ajfa0dqrat . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "grvtor_BOF" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . ajfa0dqrat .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<h_tot_BOF>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/h_tot_BOF" ;
rtDW . gl2kjcpx0w . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "h_tot_BOF" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . gl2kjcpx0w .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<magfld_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/magfld_ECI"
; rtDW . aexra1pda3 . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "magfld_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . aexra1pda3 .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 1 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 1 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<magfld_magnitude>" } ;
static RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] =
"TST_RWSWV2/DYN_SIGNAL_SAVE/magfld_magnitude" ; rtDW . hg1ul0ders .
LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart (
rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) ,
"magfld_magnitude" , 1 , 0 , 1 , 1.0 , & rt_ToWksSignalInfo ,
rt_ToWksBlockName ) ; if ( rtDW . hg1ul0ders . LoggedData == ( NULL ) )
return ; } { static int_T rt_ToWksWidths [ ] = { 3 } ; static int_T
rt_ToWksNumDimensions [ ] = { 1 } ; static int_T rt_ToWksDimensions [ ] = { 3
} ; static boolean_T rt_ToWksIsVarDims [ ] = { 0 } ; static void *
rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T rt_ToWksCurrSigDimsSize
[ ] = { 4 } ; static BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ;
static int_T rt_ToWksComplexSignals [ ] = { 0 } ; static int_T
rt_ToWksFrameData [ ] = { 0 } ; static RTWPreprocessingFcnPtr
rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) } ; static const char_T
* rt_ToWksLabels [ ] = { "<magtor_app_BOF>" } ; static RTWLogSignalInfo
rt_ToWksSignalInfo = { 1 , rt_ToWksWidths , rt_ToWksNumDimensions ,
rt_ToWksDimensions , rt_ToWksIsVarDims , rt_ToWksCurrSigDims ,
rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds , rt_ToWksComplexSignals ,
rt_ToWksFrameData , rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels }
, ( NULL ) , ( NULL ) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , (
NULL ) } ; static const char_T rt_ToWksBlockName [ ] =
"TST_RWSWV2/DYN_SIGNAL_SAVE/magtor_app_BOF" ; rtDW . kl2yhyienj . LoggedData
= rt_CreateStructLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) ,
ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "magtor_app_BOF"
, 1 , 0 , 1 , 1.0 , & rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW .
kl2yhyienj . LoggedData == ( NULL ) ) return ; } { static int_T
rt_ToWksWidths [ ] = { 3 } ; static int_T rt_ToWksNumDimensions [ ] = { 1 } ;
static int_T rt_ToWksDimensions [ ] = { 3 } ; static boolean_T
rt_ToWksIsVarDims [ ] = { 0 } ; static void * rt_ToWksCurrSigDims [ ] = { (
NULL ) } ; static int_T rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static
BuiltInDTypeId rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T
rt_ToWksComplexSignals [ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0
} ; static RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = {
( NULL ) } ; static const char_T * rt_ToWksLabels [ ] = { "<pos_ECI>" } ;
static RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/pos_ECI" ;
rtDW . bvz2m4kqbs . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "pos_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . bvz2m4kqbs .
LoggedData == ( NULL ) ) return ; } { static int_T rt_ToWksWidths [ ] = { 3 }
; static int_T rt_ToWksNumDimensions [ ] = { 1 } ; static int_T
rt_ToWksDimensions [ ] = { 3 } ; static boolean_T rt_ToWksIsVarDims [ ] = { 0
} ; static void * rt_ToWksCurrSigDims [ ] = { ( NULL ) } ; static int_T
rt_ToWksCurrSigDimsSize [ ] = { 4 } ; static BuiltInDTypeId
rt_ToWksDataTypeIds [ ] = { SS_DOUBLE } ; static int_T rt_ToWksComplexSignals
[ ] = { 0 } ; static int_T rt_ToWksFrameData [ ] = { 0 } ; static
RTWPreprocessingFcnPtr rt_ToWksLoggingPreprocessingFcnPtrs [ ] = { ( NULL ) }
; static const char_T * rt_ToWksLabels [ ] = { "<vel_ECI>" } ; static
RTWLogSignalInfo rt_ToWksSignalInfo = { 1 , rt_ToWksWidths ,
rt_ToWksNumDimensions , rt_ToWksDimensions , rt_ToWksIsVarDims ,
rt_ToWksCurrSigDims , rt_ToWksCurrSigDimsSize , rt_ToWksDataTypeIds ,
rt_ToWksComplexSignals , rt_ToWksFrameData ,
rt_ToWksLoggingPreprocessingFcnPtrs , { rt_ToWksLabels } , ( NULL ) , ( NULL
) , ( NULL ) , { ( NULL ) } , { ( NULL ) } , ( NULL ) , ( NULL ) } ; static
const char_T rt_ToWksBlockName [ ] = "TST_RWSWV2/DYN_SIGNAL_SAVE/vel_ECI" ;
rtDW . fmcrmebkkc . LoggedData = rt_CreateStructLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "vel_ECI" , 1 , 0 , 1 , 1.0 , &
rt_ToWksSignalInfo , rt_ToWksBlockName ) ; if ( rtDW . fmcrmebkkc .
LoggedData == ( NULL ) ) return ; } { void * slioCatalogue = rt_slioCatalogue
( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwIsLoggingToFile ( slioCatalogue ) ) { { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"pos_ECI" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "pos_ECI" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "TST_RWSWV2/DYN/DYN_TRA/Integrator1" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "pos_ECI" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 3 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. opv2domrvm . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"c49ba5ac-8aa2-40cf-91fd-1bf6c48a7ea4" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "m" ) ; if ( rtDW . opv2domrvm . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . opv2domrvm . AQHandles , "1" , 1.0 ,
ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . opv2domrvm . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
opv2domrvm . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
opv2domrvm . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } } rtDW .
opv2domrvm . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; void
* slioCatalogue = rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr (
rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue ( rt_dataMapInfo . mmi .
InstanceMap . fullPath ) ; if ( slioCatalogue && rtwIsLoggingToFile (
slioCatalogue ) ) { treeVector = rtwGetTreeVector ( ) ; { int_T sigDimsArray
[ 1 ] = { 3 } ; rtwAddLeafNode ( 0 , "pos_ECI" , "linear" , 0 , ( unsigned
int * ) sigDimsArray , 1 , "double" , "m" , "1" , 1.0 , ssGetTFinal ( rtS ) ,
treeVector ) ; } signalDescriptor = rtwGetSignalDescriptor ( treeVector , 1 ,
1 , 0 , 1 , "pos_ECI" , "" , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"TST_RWSWV2/DYN/DYN_TRA/Integrator1" , 1 , 0 , slioCatalogue , ( NULL ) , 0 ,
( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) { sdiSlioIsLoggingSignal (
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"TST_RWSWV2/DYN/DYN_TRA/Integrator1" , 1 , "pos_ECI" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . opv2domrvm . SlioLTF = accessor ;
} } } } rtDW . gzzht5dcba = false ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . hgodhfyuxy =
false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW .
mdd3waf5u2 = false ; ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
rtDW . abs4jjv355 = - 1 ; rtDW . hxosnzpni0 = - 1 ; rtDW . pods3ngpuh = - 1 ;
rtDW . dgi2ryavxf = - 1 ; rtDW . ghsbqj1gdd = - 1 ; rtDW . fdkfwem5wv = - 1 ;
catalog = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
l5porott1o = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog , rtDW .
l5porott1o , "Assertion" ,
"TST_RWSWV2/DYN/DYN_AERO/ECI Position to LLA/Check deltaT/Assertion" ) ;
catalog_p = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
emojxwu2oc = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_p , rtDW
. emojxwu2oc , "Assertion" ,
 "TST_RWSWV2/DYN/DYN_AERO/ECI Position to LLA/Direction Cosine Matrix ECI to ECEF/Check deltaT/Assertion"
) ; catalog_e = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
eph5mfdrkn = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_e , rtDW
. eph5mfdrkn , "Assertion" ,
"TST_RWSWV2/DYN/DYN_EPHEM/Planetary Ephemeris/Check Epoch/Assertion" ) ; rtDW
. ottqmwv4ab = - 1 ; catalog_i = rtwGetPointerFromUniquePtr (
rt_slioCatalogue ( ) ) ; rtDW . aubnmf0jim =
rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_i , rtDW . aubnmf0jim
, "Assertion" ,
"TST_RWSWV2/DYN/DYN_EPHEM/Planetary Ephemeris/Register/Check epoch/Assertion"
) ; rtDW . mjjt5milxa = - 1 ; catalog_m = rtwGetPointerFromUniquePtr (
rt_slioCatalogue ( ) ) ; rtDW . ceonvoxabs =
rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_m , rtDW . ceonvoxabs
, "Assertion" ,
"TST_RWSWV2/DYN/DYN_MAG/ECI Position to LLA/Check deltaT/Assertion" ) ;
catalog_g = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
oeklz3vrcs = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_g , rtDW
. oeklz3vrcs , "Assertion" ,
 "TST_RWSWV2/DYN/DYN_MAG/ECI Position to LLA/Direction Cosine Matrix ECI to ECEF/Check deltaT/Assertion"
) ; catalog_j = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
ewbbr1445y = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_j , rtDW
. ewbbr1445y , "Check Altitude" ,
"TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/Check Altitude/Assertion" )
; catalog_f = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
hvp123ipm0 = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_f , rtDW
. hvp123ipm0 , "Check Latitude" ,
"TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/Check Latitude/Assertion" )
; catalog_c = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
no4z2mnrxf = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_c , rtDW
. no4z2mnrxf , "Check Longitude" ,
"TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/Check Longitude/Assertion"
) ; catalog_k = rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ; rtDW .
c0fqulldoy = rt_SlioAccessorAddClientAssessmentSdi ( 1 , 4 , catalog_k , rtDW
. c0fqulldoy , "Is time within model limits" ,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/Is time within model limits/Assertion"
) ; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T pkystdek2a [
9 ] ; real_T ncuj3cy4hk ; real_T pelpp2ffsz ; real_T ggp2aawwhq ; real_T
lg0f3edifc ; real_T amhhnifger ; real_T gfdktyyhs5 ; real_T bzglndm1xq ;
real_T g1sn43mf0l ; real_T j3auneqaay ; real_T i5fgw4qg3a ; real_T bn01gmujrh
; real_T madogxzyal [ 9 ] ; real_T psqdofqdfc [ 4 ] ; real_T oqweut25mw ;
real_T og5mr3oopu ; real_T j52isufaqr ; real_T n0jkmuiqeb ; real_T jkspr0rgyw
[ 3 ] ; real_T p0wrq0nzpv [ 3 ] ; real_T oc0abfogmk [ 9 ] ; real_T ( * lastU
) [ 4 ] ; real_T lmonth [ 12 ] ; real_T chxdtzje0j ; real_T acweymdfsj ;
real_T g5pzqldhbn ; real_T fug530bbhx ; real_T n32jw4rqz5 [ 14 ] ; real_T
ijs1lor1qv [ 8 ] ; real_T f4ne12mlzi [ 66 ] ; real_T kiruj5xuq5 [ 66 ] ;
real_T i2lmhfpmzi ; real_T k4q33fn5wp ; real_T fqhdbem00h ; int32_T
assessmentVar = - 1 ; int32_T assessmentVar_p = - 1 ; real_T m2ldz44rx4 [ 4 ]
; int32_T assessmentVar_e = - 1 ; int32_T assessmentVar_i = - 1 ; int32_T
assessmentVar_m = - 1 ; int32_T assessmentVar_g = - 1 ; int32_T
assessmentVar_j = - 1 ; int32_T assessmentVar_f = - 1 ; int32_T
assessmentVar_c = - 1 ; int32_T assessmentVar_k = - 1 ; int8_T rtAction ;
real_T oltw25yayb ; real_T pz1213rdrt [ 3 ] ; real_T lah2koeql2 [ 9 ] ;
real_T f1iitcpwuk [ 9 ] ; real_T evfxmkblai ; real_T jxl2iyicpw [ 9 ] ;
real_T ftalipigpn [ 3 ] ; int32_T idx1 ; int32_T idx2 ; int32_T j ; void *
assessmentPtrVar ; int32_T s258_iter ; real_T egmjspetb3 ; real_T bpuwpgpm3m
; real_T ohohv0ef3n ; real_T fl4bb5kzfk [ 11 ] ; real_T e4gptqqsf3 [ 11 ] ;
int32_T s307_iter ; real_T ikmey0rqcr ; real_T px5y01giei [ 169 ] ; boolean_T
ejitfv2qt3 ; boolean_T jbpxsrqdbv ; char_T TRANS ; ptrdiff_t M ; ptrdiff_t N
; ptrdiff_t LDA ; ptrdiff_t INCX ; ptrdiff_t INCY ; int32_T i ; real_T tmp [
66 ] ; real_T j5wb5jlzhj [ 9 ] ; real_T ltksehy2vp [ 16 ] ; real_T
jpewagwvqf_idx_0 ; real_T jpewagwvqf_idx_2 ; int32_T eah1nufwt4_idx_1 ;
real_T ihoigetibq_idx_1 ; real_T ihoigetibq_idx_0 ; real_T fsyqxyxc3v_idx_0 ;
real_T fsyqxyxc3v_idx_1 ; real_T njxhrvfs1c_idx_0 ; real_T njxhrvfs1c_idx_1 ;
real_T njxhrvfs1c_idx_2 ; int64_T tmp_p ; int64_T tmp_e ; int64_T tmp_i ;
int64_T tmp_m ; SimStruct * S ; void * diag ; static const int8_T tmp_g [ 8 ]
= { 0 , 1 , 2 , 3 , 4 , 5 , 7 , 8 } ; static const int8_T b [ 9 ] = { 1 , 0 ,
0 , 0 , 1 , 0 , 0 , 0 , 1 } ; srClearBC ( rtDW . k3sfyh0c3kb . c5enzgh0ln ) ;
srClearBC ( rtDW . eu5kqssxx5u . gmbejf1syu ) ; srClearBC ( rtDW . o5lwvvqufc
) ; srClearBC ( rtDW . it5tygcmno ) ; srClearBC ( rtDW . oyffazvwpp ) ;
srClearBC ( rtDW . c3fesmoiak ) ; srClearBC ( rtDW . ok5kaek4lxs . p0optqqzsf
) ; srClearBC ( rtDW . cuzz03aam2l . d343bhqapn ) ; srClearBC ( rtDW .
kyqgjgbzfu ) ; srClearBC ( rtDW . khigjg54p1 ) ; srClearBC ( rtDW .
a3mffltq2c ) ; srClearBC ( rtDW . fob5v3qelm ) ; srClearBC ( rtDW .
bqkqmfirk2 ) ; srClearBC ( rtDW . onw1kj0tt3 ) ; srClearBC ( rtDW .
ouyhtippx4 ) ; srClearBC ( rtDW . jub4qa0tx5 ) ; srClearBC ( rtDW .
ehevun3t0d ) ; srClearBC ( rtDW . hafmo2yjxp ) ; srClearBC ( rtDW .
g1gz2kwalm ) ; srClearBC ( rtDW . l4idmhenv4 ) ; srClearBC ( rtDW .
dgmhfl0ejy ) ; srClearBC ( rtDW . bjrkfcnwqe ) ; srClearBC ( rtDW .
ozdacijjrc ) ; srClearBC ( rtDW . c4fmxjrfvq ) ; srClearBC ( rtDW .
dpoz2afmu5 ) ; egmjspetb3 = ssGetT ( rtS ) ; if ( egmjspetb3 > rtP .
Switch_Threshold_jy54w1qvbc ) { memcpy ( & pkystdek2a [ 0 ] , & rtP .
DYN_SC_par . inertia_deployed [ 0 ] , 9U * sizeof ( real_T ) ) ; } else {
memcpy ( & pkystdek2a [ 0 ] , & rtP . DYN_SC_par . inertia [ 0 ] , 9U *
sizeof ( real_T ) ) ; } evxgoynfhh ( pkystdek2a , & rtB . evxgoynfhh1 , rtP .
LIB_ROT_MATINV_tol ) ; rtB . p11ofm4mny [ 0 ] = rtX . e5l2wmdpfb [ 0 ] ; rtB
. p11ofm4mny [ 1 ] = rtX . e5l2wmdpfb [ 1 ] ; rtB . p11ofm4mny [ 2 ] = rtX .
e5l2wmdpfb [ 2 ] ; for ( s258_iter = 0 ; s258_iter < 3 ; s258_iter ++ ) { rtB
. lkurcisohk [ s258_iter ] = 0.0 ; rtB . lkurcisohk [ s258_iter ] += rtB .
evxgoynfhh1 . mqozl5xj12 . gyjfwigx2h [ s258_iter ] * rtB . p11ofm4mny [ 0 ]
; rtB . lkurcisohk [ s258_iter ] += rtB . evxgoynfhh1 . mqozl5xj12 .
gyjfwigx2h [ s258_iter + 3 ] * rtB . p11ofm4mny [ 1 ] ; rtB . lkurcisohk [
s258_iter ] += rtB . evxgoynfhh1 . mqozl5xj12 . gyjfwigx2h [ s258_iter + 6 ]
* rtB . p11ofm4mny [ 2 ] ; } njxhrvfs1c_idx_0 = rtP . Kd_Gain * rtB .
lkurcisohk [ 0 ] ; njxhrvfs1c_idx_1 = rtP . Kd_Gain * rtB . lkurcisohk [ 1 ]
; njxhrvfs1c_idx_2 = rtP . Kd_Gain * rtB . lkurcisohk [ 2 ] ; egmjspetb3 =
ssGetT ( rtS ) ; if ( egmjspetb3 > rtP . Switch_Threshold_diu3nnmqns ) {
k4q33fn5wp = rtP . DYN_AERO_par . Drag_Coefficient_Deployed ; } else {
k4q33fn5wp = rtP . DYN_AERO_par . Drag_Coefficient ; } if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) !
( rtP . JulianDateConversion_month <= 2.0 ) ; rtDW . abs4jjv355 = rtAction ;
} else { rtAction = rtDW . abs4jjv355 ; } switch ( rtAction ) { case 0 :
k3sfyh0c3k ( rtP . ECIPositiontoLLA_year , rtP . JulianDateConversion_month ,
& ncuj3cy4hk , & pelpp2ffsz , & rtP . k3sfyh0c3kb ) ; if ( ssIsMajorTimeStep
( rtS ) ) { srUpdateBC ( rtDW . k3sfyh0c3kb . c5enzgh0ln ) ; } break ; case 1
: eu5kqssxx5 ( rtP . ECIPositiontoLLA_year , rtP . JulianDateConversion_month
, & ncuj3cy4hk , & pelpp2ffsz ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . eu5kqssxx5u . gmbejf1syu ) ; } break ; } oltw25yayb =
muDoubleScalarFloor ( rtP . Gain2_Gain_ha2c5rnbap * ncuj3cy4hk ) ; rtB .
kp2e2xb4cc = ( ( ( muDoubleScalarFloor ( ( ncuj3cy4hk + rtP . BiasYear_Bias )
* rtP . Gain_Gain_nnyck3ujwy ) + muDoubleScalarFloor ( ( pelpp2ffsz + rtP .
Bias1_Bias_jb4qn5y1yi ) * rtP . Gain1_Gain_e0nbiop4h1 ) ) + rtP . Bias2_Bias
) - oltw25yayb ) + muDoubleScalarFloor ( rtP . Gain3_Gain * oltw25yayb ) ; }
m2ldz44rx4 [ 0 ] = rtP . sec2_Value [ 0 ] ; m2ldz44rx4 [ 1 ] = rtP .
sec2_Value [ 1 ] ; m2ldz44rx4 [ 2 ] = rtP . sec2_Value [ 2 ] ; m2ldz44rx4 [ 3
] = rtP . sec2_Value [ 3 ] ; m2ldz44rx4 [ ( int32_T ) rtP . Index_Value - 1 ]
= egmjspetb3 ; jpewagwvqf_idx_0 = m2ldz44rx4 [ 0 ] ; oltw25yayb = m2ldz44rx4
[ 1 ] ; bpuwpgpm3m = m2ldz44rx4 [ 2 ] ; ohohv0ef3n = m2ldz44rx4 [ 3 ] ;
chxdtzje0j = ( ( ( ( ( ( rtP . ECIPositiontoLLA_min + bpuwpgpm3m ) * rtP .
Gain5_Gain + ( rtP . ECIPositiontoLLA_hour + oltw25yayb ) ) + ( rtP .
JulianDateConversion_sec + ohohv0ef3n ) * rtP . Gain6_Gain ) * rtP .
Gain4_Gain + ( ( ( rtP . JulianDateConversion_day + jpewagwvqf_idx_0 ) + rtB
. kp2e2xb4cc ) + rtP . BiasDay_Bias ) ) + rtB . ol3bqwr21m ) + rtP .
Bias1_Bias_ji5kh02tmj ) * rtP . Gain_Gain_n4zfmhpjdz ; muDoubleScalarSinCos (
0.017453292519943295 * ( rtP . Gain_Gain_gwzumkg2ha * chxdtzje0j ) , &
pz1213rdrt [ 0 ] , & jpewagwvqf_idx_0 ) ; muDoubleScalarSinCos ( rtB .
afvb1ehg0t [ 0 ] , & pz1213rdrt [ 1 ] , & oltw25yayb ) ; muDoubleScalarSinCos
( rtB . afvb1ehg0t [ 1 ] , & g5pzqldhbn , & jpewagwvqf_idx_2 ) ; lah2koeql2 [
0 ] = oltw25yayb * jpewagwvqf_idx_0 ; lah2koeql2 [ 1 ] = g5pzqldhbn *
pz1213rdrt [ 1 ] * jpewagwvqf_idx_0 - jpewagwvqf_idx_2 * pz1213rdrt [ 0 ] ;
lah2koeql2 [ 2 ] = jpewagwvqf_idx_2 * pz1213rdrt [ 1 ] * jpewagwvqf_idx_0 +
g5pzqldhbn * pz1213rdrt [ 0 ] ; lah2koeql2 [ 3 ] = oltw25yayb * pz1213rdrt [
0 ] ; lah2koeql2 [ 4 ] = g5pzqldhbn * pz1213rdrt [ 1 ] * pz1213rdrt [ 0 ] +
jpewagwvqf_idx_2 * jpewagwvqf_idx_0 ; lah2koeql2 [ 5 ] = jpewagwvqf_idx_2 *
pz1213rdrt [ 1 ] * pz1213rdrt [ 0 ] - g5pzqldhbn * jpewagwvqf_idx_0 ;
lah2koeql2 [ 6 ] = - pz1213rdrt [ 1 ] ; lah2koeql2 [ 7 ] = g5pzqldhbn *
oltw25yayb ; lah2koeql2 [ 8 ] = jpewagwvqf_idx_2 * oltw25yayb ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtAction
= ( int8_T ) ! ( rtP . JulianDateConversion_month_iotvngoujn <= 2.0 ) ; rtDW
. hxosnzpni0 = rtAction ; } else { rtAction = rtDW . hxosnzpni0 ; } switch (
rtAction ) { case 0 : k3sfyh0c3k ( rtP . ECIPositiontoLLA_year , rtP .
JulianDateConversion_month_iotvngoujn , & ggp2aawwhq , & lg0f3edifc , & rtP .
ep1krdw3c3 ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ep1krdw3c3 . c5enzgh0ln ) ; } break ; case 1 : eu5kqssxx5 ( rtP .
ECIPositiontoLLA_year , rtP . JulianDateConversion_month_iotvngoujn , &
ggp2aawwhq , & lg0f3edifc ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC (
rtDW . ausjujlz1d . gmbejf1syu ) ; } break ; } oltw25yayb =
muDoubleScalarFloor ( rtP . Gain2_Gain_pffca4otqi * ggp2aawwhq ) ; rtB .
jfavnuvm3x = ( ( ( muDoubleScalarFloor ( ( ggp2aawwhq + rtP .
BiasYear_Bias_d1bz4cwjem ) * rtP . Gain_Gain_nbkyysfa1j ) +
muDoubleScalarFloor ( ( lg0f3edifc + rtP . Bias1_Bias_jq03q5eepb ) * rtP .
Gain1_Gain_khexcsxl3v ) ) + rtP . Bias2_Bias_fpu32hl3sv ) - oltw25yayb ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_jel0ucvuxl * oltw25yayb ) ; }
m2ldz44rx4 [ 0 ] = rtP . sec2_Value_cqhhxc22cp [ 0 ] ; m2ldz44rx4 [ 1 ] = rtP
. sec2_Value_cqhhxc22cp [ 1 ] ; m2ldz44rx4 [ 2 ] = rtP .
sec2_Value_cqhhxc22cp [ 2 ] ; m2ldz44rx4 [ 3 ] = rtP . sec2_Value_cqhhxc22cp
[ 3 ] ; m2ldz44rx4 [ ( int32_T ) rtP . Index_Value_ggtv1dsxam - 1 ] =
egmjspetb3 ; jpewagwvqf_idx_0 = m2ldz44rx4 [ 0 ] ; oltw25yayb = m2ldz44rx4 [
1 ] ; bpuwpgpm3m = m2ldz44rx4 [ 2 ] ; ohohv0ef3n = m2ldz44rx4 [ 3 ] ;
oltw25yayb = ( ( ( ( ( rtP . ECIPositiontoLLA_min + bpuwpgpm3m ) * rtP .
Gain5_Gain_d4jo3mva53 + ( rtP . ECIPositiontoLLA_hour + oltw25yayb ) ) + (
rtP . JulianDateConversion_sec_jnhedb5ppd + ohohv0ef3n ) * rtP .
Gain6_Gain_bnnxaastma ) * rtP . Gain4_Gain_i45flsg3or + ( ( ( rtP .
JulianDateConversion_day_evmxw404ks + jpewagwvqf_idx_0 ) + rtB . jfavnuvm3x )
+ rtP . BiasDay_Bias_pbwswhzoa4 ) ) + rtB . itueiehnrc ) + rtP . Bias_Bias ;
oltw25yayb = muDoubleScalarMod ( ( ( muDoubleScalarMod ( oltw25yayb , rtP .
Constant_Value_bu55wk5sux ) + rtP . Bias1_Bias_a5hamgvknt ) + rtP .
Gain_Gain_cy4gpaqjaz * oltw25yayb ) * rtP . Gain1_Gain_okow3nhbkn , rtP .
Constant_Value_hfl0axy5vc ) ; muDoubleScalarSinCos ( oltw25yayb , &
jpewagwvqf_idx_0 , & pz1213rdrt [ 0 ] ) ; muDoubleScalarSinCos ( rtP .
Constant1_Value_dacsesdqm3 [ 0 ] , & oltw25yayb , & pz1213rdrt [ 1 ] ) ;
muDoubleScalarSinCos ( rtP . Constant1_Value_dacsesdqm3 [ 1 ] , & acweymdfsj
, & pz1213rdrt [ 2 ] ) ; f1iitcpwuk [ 0 ] = pz1213rdrt [ 1 ] * pz1213rdrt [ 0
] ; f1iitcpwuk [ 1 ] = acweymdfsj * oltw25yayb * pz1213rdrt [ 0 ] -
pz1213rdrt [ 2 ] * jpewagwvqf_idx_0 ; f1iitcpwuk [ 2 ] = pz1213rdrt [ 2 ] *
oltw25yayb * pz1213rdrt [ 0 ] + acweymdfsj * jpewagwvqf_idx_0 ; f1iitcpwuk [
3 ] = pz1213rdrt [ 1 ] * jpewagwvqf_idx_0 ; f1iitcpwuk [ 4 ] = acweymdfsj *
oltw25yayb * jpewagwvqf_idx_0 + pz1213rdrt [ 2 ] * pz1213rdrt [ 0 ] ;
f1iitcpwuk [ 5 ] = pz1213rdrt [ 2 ] * oltw25yayb * jpewagwvqf_idx_0 -
acweymdfsj * pz1213rdrt [ 0 ] ; f1iitcpwuk [ 6 ] = - oltw25yayb ; f1iitcpwuk
[ 7 ] = acweymdfsj * pz1213rdrt [ 1 ] ; f1iitcpwuk [ 8 ] = pz1213rdrt [ 2 ] *
pz1213rdrt [ 1 ] ; evfxmkblai = rtP . Y0_Coefs [ 0 ] ; for ( s258_iter = 0 ;
s258_iter < 5 ; s258_iter ++ ) { evfxmkblai = evfxmkblai * chxdtzje0j + rtP .
Y0_Coefs [ s258_iter + 1 ] ; } acweymdfsj = chxdtzje0j * chxdtzje0j ;
g5pzqldhbn = acweymdfsj * chxdtzje0j ; fug530bbhx = g5pzqldhbn * chxdtzje0j ;
n32jw4rqz5 [ 0 ] = muDoubleScalarMod ( ( ( ( ( rtP . mMoon_Coefs [ 0 ] *
chxdtzje0j + rtP . mMoon_Coefs [ 1 ] ) * chxdtzje0j + rtP . mMoon_Coefs [ 2 ]
) * chxdtzje0j + rtP . mMoon_Coefs [ 3 ] ) * chxdtzje0j + rtP . mMoon_Coefs [
4 ] ) * rtP . Gain_Gain_anuil02gv5 * 0.017453292519943295 , rtP .
Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 1 ] = muDoubleScalarMod ( ( ( ( (
rtP . mSun_Coefs [ 0 ] * chxdtzje0j + rtP . mSun_Coefs [ 1 ] ) * chxdtzje0j +
rtP . mSun_Coefs [ 2 ] ) * chxdtzje0j + rtP . mSun_Coefs [ 3 ] ) * chxdtzje0j
+ rtP . mSun_Coefs [ 4 ] ) * rtP . Gain_Gain_anuil02gv5 *
0.017453292519943295 , rtP . Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 2 ] =
muDoubleScalarMod ( ( ( ( ( rtP . umMoon_Coefs [ 0 ] * chxdtzje0j + rtP .
umMoon_Coefs [ 1 ] ) * chxdtzje0j + rtP . umMoon_Coefs [ 2 ] ) * chxdtzje0j +
rtP . umMoon_Coefs [ 3 ] ) * chxdtzje0j + rtP . umMoon_Coefs [ 4 ] ) * rtP .
Gain_Gain_anuil02gv5 * 0.017453292519943295 , rtP . Constant_Value_b2ijke2zch
) ; n32jw4rqz5 [ 3 ] = muDoubleScalarMod ( ( ( ( ( rtP . dSun_Coefs [ 0 ] *
chxdtzje0j + rtP . dSun_Coefs [ 1 ] ) * chxdtzje0j + rtP . dSun_Coefs [ 2 ] )
* chxdtzje0j + rtP . dSun_Coefs [ 3 ] ) * chxdtzje0j + rtP . dSun_Coefs [ 4 ]
) * rtP . Gain_Gain_anuil02gv5 * 0.017453292519943295 , rtP .
Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 4 ] = muDoubleScalarMod ( ( ( ( (
rtP . omegaMoon_Coefs [ 0 ] * chxdtzje0j + rtP . omegaMoon_Coefs [ 1 ] ) *
chxdtzje0j + rtP . omegaMoon_Coefs [ 2 ] ) * chxdtzje0j + rtP .
omegaMoon_Coefs [ 3 ] ) * chxdtzje0j + rtP . omegaMoon_Coefs [ 4 ] ) * rtP .
Gain_Gain_anuil02gv5 * 0.017453292519943295 , rtP . Constant_Value_b2ijke2zch
) ; n32jw4rqz5 [ 5 ] = muDoubleScalarMod ( rtP . lMercury_Coefs [ 0 ] *
chxdtzje0j + rtP . lMercury_Coefs [ 1 ] , rtP . Constant_Value_b2ijke2zch ) ;
n32jw4rqz5 [ 6 ] = muDoubleScalarMod ( rtP . lVenus_Coefs [ 0 ] * chxdtzje0j
+ rtP . lVenus_Coefs [ 1 ] , rtP . Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [
7 ] = muDoubleScalarMod ( rtP . lEarth_Coefs [ 0 ] * chxdtzje0j + rtP .
lEarth_Coefs [ 1 ] , rtP . Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 8 ] =
muDoubleScalarMod ( rtP . lMars_Coefs [ 0 ] * chxdtzje0j + rtP . lMars_Coefs
[ 1 ] , rtP . Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 9 ] =
muDoubleScalarMod ( rtP . lJupiter_Coefs [ 0 ] * chxdtzje0j + rtP .
lJupiter_Coefs [ 1 ] , rtP . Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 10 ]
= muDoubleScalarMod ( rtP . lSaturn_Coefs [ 0 ] * chxdtzje0j + rtP .
lSaturn_Coefs [ 1 ] , rtP . Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 11 ] =
muDoubleScalarMod ( rtP . lUranus_Coefs [ 0 ] * chxdtzje0j + rtP .
lUranus_Coefs [ 1 ] , rtP . Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 12 ] =
muDoubleScalarMod ( rtP . lNeptune_Coefs [ 0 ] * chxdtzje0j + rtP .
lNeptune_Coefs [ 1 ] , rtP . Constant_Value_b2ijke2zch ) ; n32jw4rqz5 [ 13 ]
= muDoubleScalarMod ( ( rtP . pa_Coefs [ 0 ] * chxdtzje0j + rtP . pa_Coefs [
1 ] ) * chxdtzje0j + rtP . pa_Coefs [ 2 ] , rtP . Constant_Value_b2ijke2zch )
; TRANS = 'N' ; M = 1275LL ; N = 14LL ; oltw25yayb = 1.0 ; LDA = 1275LL ;
INCX = 1LL ; jpewagwvqf_idx_0 = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , &
N , & oltw25yayb , & rtB . d5i5n2ctvl [ 0 ] , & LDA , & n32jw4rqz5 [ 0 ] , &
INCX , & jpewagwvqf_idx_0 , & rtB . m04ridjbke_kkiq3xxxve [ 0 ] , & INCY ) ;
for ( i = 0 ; i < 962 ; i ++ ) { rtB . pgqpd5ik4w_cxarnvbvui [ i ] = rtP .
Constant1_Value_oxaayczkra [ i ] * rtB . eetng5atfq [ i ] * muDoubleScalarSin
( rtB . m04ridjbke_kkiq3xxxve [ i ] ) ; } for ( i = 0 ; i < 277 ; i ++ ) {
rtB . pgqpd5ik4w_cxarnvbvui [ i + 962 ] = rtB . eetng5atfq [ i + 962 ] *
chxdtzje0j * muDoubleScalarSin ( rtB . m04ridjbke_kkiq3xxxve [ i + 962 ] ) ;
} for ( i = 0 ; i < 30 ; i ++ ) { rtB . pgqpd5ik4w_cxarnvbvui [ i + 1239 ] =
rtB . eetng5atfq [ i + 1239 ] * acweymdfsj * muDoubleScalarSin ( rtB .
m04ridjbke_kkiq3xxxve [ i + 1239 ] ) ; } for ( i = 0 ; i < 5 ; i ++ ) { rtB .
pgqpd5ik4w_cxarnvbvui [ i + 1269 ] = rtB . eetng5atfq [ i + 1269 ] *
g5pzqldhbn * muDoubleScalarSin ( rtB . m04ridjbke_kkiq3xxxve [ i + 1269 ] ) ;
} rtB . pgqpd5ik4w_cxarnvbvui [ 1274 ] = fug530bbhx * rtB . eetng5atfq [ 1274
] * muDoubleScalarSin ( rtB . m04ridjbke_kkiq3xxxve [ 1274 ] ) ; for (
s258_iter = 0 ; s258_iter < 1275 ; s258_iter ++ ) { rtB .
m04ridjbke_kkiq3xxxve [ s258_iter ] = muDoubleScalarCos ( rtB .
m04ridjbke_kkiq3xxxve [ s258_iter ] ) ; } memcpy ( & rtB . dv1 [ 0 ] , & rtP
. Constant1_Value_oxaayczkra [ 0 ] , 962U * sizeof ( real_T ) ) ; for (
s258_iter = 0 ; s258_iter < 277 ; s258_iter ++ ) { rtB . dv1 [ s258_iter +
962 ] = chxdtzje0j ; } for ( s258_iter = 0 ; s258_iter < 30 ; s258_iter ++ )
{ rtB . dv1 [ s258_iter + 1239 ] = acweymdfsj ; } for ( s258_iter = 0 ;
s258_iter < 5 ; s258_iter ++ ) { rtB . dv1 [ s258_iter + 1269 ] = g5pzqldhbn
; } rtB . dv1 [ 1274 ] = fug530bbhx ; jpewagwvqf_idx_2 = - 0.0 ; for ( i = 0
; i < 1275 ; i ++ ) { jpewagwvqf_idx_0 = rtB . m04ridjbke_kkiq3xxxve [ i ] *
rtB . judoxslscy [ i ] * rtB . dv1 [ i ] ; oltw25yayb = rtB .
pgqpd5ik4w_cxarnvbvui [ i ] + jpewagwvqf_idx_0 ; jpewagwvqf_idx_2 +=
oltw25yayb ; rtB . m04ridjbke_kkiq3xxxve [ i ] = jpewagwvqf_idx_0 ; rtB .
pgqpd5ik4w_cxarnvbvui [ i ] = oltw25yayb ; } jpewagwvqf_idx_2 = ( evfxmkblai
+ jpewagwvqf_idx_2 ) * rtP . Gain4_Gain_gob23x2gl0 * 0.017453292519943295 ;
evfxmkblai = rtP . X0_Coefs [ 0 ] ; for ( s258_iter = 0 ; s258_iter < 5 ;
s258_iter ++ ) { evfxmkblai = evfxmkblai * chxdtzje0j + rtP . X0_Coefs [
s258_iter + 1 ] ; } acweymdfsj = chxdtzje0j * chxdtzje0j ; g5pzqldhbn =
acweymdfsj * chxdtzje0j ; fug530bbhx = g5pzqldhbn * chxdtzje0j ; TRANS = 'N'
; M = 1600LL ; N = 14LL ; oltw25yayb = 1.0 ; LDA = 1600LL ; INCX = 1LL ;
jpewagwvqf_idx_0 = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , &
oltw25yayb , & rtB . ogh5hr0p0j [ 0 ] , & LDA , & n32jw4rqz5 [ 0 ] , & INCX ,
& jpewagwvqf_idx_0 , & rtB . pcu42j55xs_mbvzarwird [ 0 ] , & INCY ) ; for ( i
= 0 ; i < 1306 ; i ++ ) { rtB . ooyuznughj_cl54gopm0x [ i ] = rtP .
Constant1_Value_pnm1ckjvfq [ i ] * rtB . nfpmyaudo5 [ i ] * muDoubleScalarSin
( rtB . pcu42j55xs_mbvzarwird [ i ] ) ; } for ( i = 0 ; i < 253 ; i ++ ) {
rtB . ooyuznughj_cl54gopm0x [ i + 1306 ] = rtB . nfpmyaudo5 [ i + 1306 ] *
chxdtzje0j * muDoubleScalarSin ( rtB . pcu42j55xs_mbvzarwird [ i + 1306 ] ) ;
} for ( i = 0 ; i < 36 ; i ++ ) { rtB . ooyuznughj_cl54gopm0x [ i + 1559 ] =
rtB . nfpmyaudo5 [ i + 1559 ] * acweymdfsj * muDoubleScalarSin ( rtB .
pcu42j55xs_mbvzarwird [ i + 1559 ] ) ; } rtB . ooyuznughj_cl54gopm0x [ 1595 ]
= g5pzqldhbn * rtB . nfpmyaudo5 [ 1595 ] * muDoubleScalarSin ( rtB .
pcu42j55xs_mbvzarwird [ 1595 ] ) ; rtB . ooyuznughj_cl54gopm0x [ 1596 ] =
g5pzqldhbn * rtB . nfpmyaudo5 [ 1596 ] * muDoubleScalarSin ( rtB .
pcu42j55xs_mbvzarwird [ 1596 ] ) ; rtB . ooyuznughj_cl54gopm0x [ 1597 ] =
g5pzqldhbn * rtB . nfpmyaudo5 [ 1597 ] * muDoubleScalarSin ( rtB .
pcu42j55xs_mbvzarwird [ 1597 ] ) ; rtB . ooyuznughj_cl54gopm0x [ 1598 ] =
g5pzqldhbn * rtB . nfpmyaudo5 [ 1598 ] * muDoubleScalarSin ( rtB .
pcu42j55xs_mbvzarwird [ 1598 ] ) ; rtB . ooyuznughj_cl54gopm0x [ 1599 ] =
fug530bbhx * rtB . nfpmyaudo5 [ 1599 ] * muDoubleScalarSin ( rtB .
pcu42j55xs_mbvzarwird [ 1599 ] ) ; for ( s258_iter = 0 ; s258_iter < 1600 ;
s258_iter ++ ) { rtB . pcu42j55xs_mbvzarwird [ s258_iter ] =
muDoubleScalarCos ( rtB . pcu42j55xs_mbvzarwird [ s258_iter ] ) ; } memcpy (
& rtB . dv [ 0 ] , & rtP . Constant1_Value_pnm1ckjvfq [ 0 ] , 1306U * sizeof
( real_T ) ) ; for ( s258_iter = 0 ; s258_iter < 253 ; s258_iter ++ ) { rtB .
dv [ s258_iter + 1306 ] = chxdtzje0j ; } for ( s258_iter = 0 ; s258_iter < 36
; s258_iter ++ ) { rtB . dv [ s258_iter + 1559 ] = acweymdfsj ; } rtB . dv [
1595 ] = g5pzqldhbn ; rtB . dv [ 1596 ] = g5pzqldhbn ; rtB . dv [ 1597 ] =
g5pzqldhbn ; rtB . dv [ 1598 ] = g5pzqldhbn ; rtB . dv [ 1599 ] = fug530bbhx
; i2lmhfpmzi = - 0.0 ; for ( i = 0 ; i < 1600 ; i ++ ) { jpewagwvqf_idx_0 =
rtB . pcu42j55xs_mbvzarwird [ i ] * rtB . lglaedtr5a [ i ] * rtB . dv [ i ] ;
oltw25yayb = rtB . ooyuznughj_cl54gopm0x [ i ] + jpewagwvqf_idx_0 ;
i2lmhfpmzi += oltw25yayb ; rtB . pcu42j55xs_mbvzarwird [ i ] =
jpewagwvqf_idx_0 ; rtB . ooyuznughj_cl54gopm0x [ i ] = oltw25yayb ; }
i2lmhfpmzi = ( evfxmkblai + i2lmhfpmzi ) * rtP . Gain3_Gain_nr4rdelyih *
0.017453292519943295 ; evfxmkblai = muDoubleScalarAtan2 ( jpewagwvqf_idx_2 ,
i2lmhfpmzi ) ; acweymdfsj = i2lmhfpmzi * i2lmhfpmzi + jpewagwvqf_idx_2 *
jpewagwvqf_idx_2 ; g5pzqldhbn = rtP . S0_Coefs [ 0 ] ; fug530bbhx =
chxdtzje0j * chxdtzje0j ; bpuwpgpm3m = fug530bbhx * chxdtzje0j ; ohohv0ef3n =
bpuwpgpm3m * chxdtzje0j ; TRANS = 'N' ; M = 66LL ; N = 8LL ; oltw25yayb = 1.0
; LDA = 66LL ; for ( s258_iter = 0 ; s258_iter < 5 ; s258_iter ++ ) {
g5pzqldhbn = g5pzqldhbn * chxdtzje0j + rtP . S0_Coefs [ s258_iter + 1 ] ;
ijs1lor1qv [ s258_iter ] = n32jw4rqz5 [ s258_iter ] ; } ijs1lor1qv [ 5 ] =
n32jw4rqz5 [ 6 ] ; ijs1lor1qv [ 6 ] = n32jw4rqz5 [ 7 ] ; ijs1lor1qv [ 7 ] =
n32jw4rqz5 [ 13 ] ; INCX = 1LL ; jpewagwvqf_idx_0 = 0.0 ; INCY = 1LL ; dgemv
( & TRANS , & M , & N , & oltw25yayb , & rtB . kvgnk3vwbl [ 0 ] , & LDA , &
ijs1lor1qv [ 0 ] , & INCX , & jpewagwvqf_idx_0 , & f4ne12mlzi [ 0 ] , & INCY
) ; for ( i = 0 ; i < 33 ; i ++ ) { kiruj5xuq5 [ i ] = rtP .
Constant1_Value_cnmjmk0drt [ i ] * rtB . jywa2bcbgw [ i ] * muDoubleScalarSin
( f4ne12mlzi [ i ] ) ; } kiruj5xuq5 [ 33 ] = chxdtzje0j * rtB . jywa2bcbgw [
33 ] * muDoubleScalarSin ( f4ne12mlzi [ 33 ] ) ; kiruj5xuq5 [ 34 ] =
chxdtzje0j * rtB . jywa2bcbgw [ 34 ] * muDoubleScalarSin ( f4ne12mlzi [ 34 ]
) ; kiruj5xuq5 [ 35 ] = chxdtzje0j * rtB . jywa2bcbgw [ 35 ] *
muDoubleScalarSin ( f4ne12mlzi [ 35 ] ) ; for ( i = 0 ; i < 25 ; i ++ ) {
kiruj5xuq5 [ i + 36 ] = rtB . jywa2bcbgw [ i + 36 ] * fug530bbhx *
muDoubleScalarSin ( f4ne12mlzi [ i + 36 ] ) ; } kiruj5xuq5 [ 61 ] =
bpuwpgpm3m * rtB . jywa2bcbgw [ 61 ] * muDoubleScalarSin ( f4ne12mlzi [ 61 ]
) ; kiruj5xuq5 [ 62 ] = bpuwpgpm3m * rtB . jywa2bcbgw [ 62 ] *
muDoubleScalarSin ( f4ne12mlzi [ 62 ] ) ; kiruj5xuq5 [ 63 ] = bpuwpgpm3m *
rtB . jywa2bcbgw [ 63 ] * muDoubleScalarSin ( f4ne12mlzi [ 63 ] ) ;
kiruj5xuq5 [ 64 ] = bpuwpgpm3m * rtB . jywa2bcbgw [ 64 ] * muDoubleScalarSin
( f4ne12mlzi [ 64 ] ) ; kiruj5xuq5 [ 65 ] = ohohv0ef3n * rtB . jywa2bcbgw [
65 ] * muDoubleScalarSin ( f4ne12mlzi [ 65 ] ) ; for ( s258_iter = 0 ;
s258_iter < 66 ; s258_iter ++ ) { f4ne12mlzi [ s258_iter ] =
muDoubleScalarCos ( f4ne12mlzi [ s258_iter ] ) ; } memcpy ( & tmp [ 0 ] , &
rtP . Constant1_Value_cnmjmk0drt [ 0 ] , 33U * sizeof ( real_T ) ) ; tmp [ 33
] = chxdtzje0j ; tmp [ 34 ] = chxdtzje0j ; tmp [ 35 ] = chxdtzje0j ; for (
s258_iter = 0 ; s258_iter < 25 ; s258_iter ++ ) { tmp [ s258_iter + 36 ] =
fug530bbhx ; } tmp [ 61 ] = bpuwpgpm3m ; tmp [ 62 ] = bpuwpgpm3m ; tmp [ 63 ]
= bpuwpgpm3m ; tmp [ 64 ] = bpuwpgpm3m ; tmp [ 65 ] = ohohv0ef3n ; fug530bbhx
= - 0.0 ; for ( i = 0 ; i < 66 ; i ++ ) { jpewagwvqf_idx_0 = f4ne12mlzi [ i ]
* rtB . gp0yss5tss [ i ] * tmp [ i ] ; oltw25yayb = kiruj5xuq5 [ i ] +
jpewagwvqf_idx_0 ; fug530bbhx += oltw25yayb ; f4ne12mlzi [ i ] =
jpewagwvqf_idx_0 ; kiruj5xuq5 [ i ] = oltw25yayb ; } muDoubleScalarSinCos (
evfxmkblai , & jpewagwvqf_idx_0 , & pz1213rdrt [ 0 ] ) ; muDoubleScalarSinCos
( muDoubleScalarAtan ( muDoubleScalarSqrt ( acweymdfsj / ( rtP .
Constant_Value_fijgkcnnhd - acweymdfsj ) ) ) , & oltw25yayb , & pz1213rdrt [
1 ] ) ; muDoubleScalarSinCos ( rtP . Gain1_Gain_dhurlgsnhr * ( (
0.017453292519943295 * ( rtP . Gain2_Gain_jynln5owt4 * ( g5pzqldhbn +
fug530bbhx ) ) - rtP . Gain5_Gain_c4ytvmivzm * ( jpewagwvqf_idx_2 *
i2lmhfpmzi ) ) + evfxmkblai ) , & acweymdfsj , & pz1213rdrt [ 2 ] ) ;
jxl2iyicpw [ 0 ] = pz1213rdrt [ 0 ] * pz1213rdrt [ 2 ] * pz1213rdrt [ 1 ] -
jpewagwvqf_idx_0 * acweymdfsj ; jxl2iyicpw [ 1 ] = - pz1213rdrt [ 0 ] *
pz1213rdrt [ 1 ] * acweymdfsj - jpewagwvqf_idx_0 * pz1213rdrt [ 2 ] ;
jxl2iyicpw [ 2 ] = pz1213rdrt [ 0 ] * oltw25yayb ; jxl2iyicpw [ 3 ] =
jpewagwvqf_idx_0 * pz1213rdrt [ 2 ] * pz1213rdrt [ 1 ] + pz1213rdrt [ 0 ] *
acweymdfsj ; jxl2iyicpw [ 4 ] = - jpewagwvqf_idx_0 * pz1213rdrt [ 1 ] *
acweymdfsj + pz1213rdrt [ 0 ] * pz1213rdrt [ 2 ] ; jxl2iyicpw [ 5 ] =
jpewagwvqf_idx_0 * oltw25yayb ; jxl2iyicpw [ 6 ] = - oltw25yayb * pz1213rdrt
[ 2 ] ; jxl2iyicpw [ 7 ] = oltw25yayb * acweymdfsj ; jxl2iyicpw [ 8 ] =
pz1213rdrt [ 1 ] ; for ( i = 0 ; i < 3 ; i ++ ) { rtB . lgajxwyfuf [ i ] =
rtX . mes33bxk5w [ i ] ; for ( s258_iter = 0 ; s258_iter < 3 ; s258_iter ++ )
{ j5wb5jlzhj [ i + 3 * s258_iter ] = 0.0 ; j5wb5jlzhj [ i + 3 * s258_iter ]
+= jxl2iyicpw [ 3 * s258_iter ] * f1iitcpwuk [ i ] ; j5wb5jlzhj [ i + 3 *
s258_iter ] += jxl2iyicpw [ 3 * s258_iter + 1 ] * f1iitcpwuk [ i + 3 ] ;
j5wb5jlzhj [ i + 3 * s258_iter ] += jxl2iyicpw [ 3 * s258_iter + 2 ] *
f1iitcpwuk [ i + 6 ] ; } } for ( s258_iter = 0 ; s258_iter < 3 ; s258_iter ++
) { rtB . bbupnojfch [ s258_iter ] = 0.0 ; for ( i = 0 ; i < 3 ; i ++ ) {
f1iitcpwuk [ s258_iter + 3 * i ] = 0.0 ; f1iitcpwuk [ s258_iter + 3 * i ] +=
j5wb5jlzhj [ 3 * i ] * lah2koeql2 [ s258_iter ] ; f1iitcpwuk [ s258_iter + 3
* i ] += j5wb5jlzhj [ 3 * i + 1 ] * lah2koeql2 [ s258_iter + 3 ] ; f1iitcpwuk
[ s258_iter + 3 * i ] += j5wb5jlzhj [ 3 * i + 2 ] * lah2koeql2 [ s258_iter +
6 ] ; rtB . bbupnojfch [ s258_iter ] += f1iitcpwuk [ 3 * i + s258_iter ] *
rtB . lgajxwyfuf [ i ] ; } } rtB . f4iofc4dn5 = muDoubleScalarSqrt ( rtB .
bbupnojfch [ 0 ] * rtB . bbupnojfch [ 0 ] + rtB . bbupnojfch [ 1 ] * rtB .
bbupnojfch [ 1 ] ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { fbciyjdijr ( rtB
. f4iofc4dn5 , rtB . bbupnojfch [ 2 ] , rtB . ialvqzftpg , rtB . hyyusjwwd0 ,
rtB . pf0kn2talc , rtB . cucbrhyluc , & rtB . fbciyjdijrl , & rtDW .
fbciyjdijrl , & rtP . fbciyjdijrl ) ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ muDoubleScalarSinCos ( rtB . fbciyjdijrl . injnyz4auw , & rtB . ewfw4ajeec
, & rtB . euvzemougu ) ; oltw25yayb = rtB . ewfw4ajeec * rtB . pf0kn2talc ;
rtB . jrebo5mrdq = rtP . Constant1_Value_kkksjwcunb / muDoubleScalarSqrt (
rtP . f_Value - oltw25yayb * rtB . ewfw4ajeec ) ; rtB . mli0y4udzs =
oltw25yayb * rtB . jrebo5mrdq ; } amhhnifger = 57.295779513082323 * rtB .
fbciyjdijrl . injnyz4auw ; gfdktyyhs5 = 57.295779513082323 *
muDoubleScalarAtan2 ( rtB . bbupnojfch [ 1 ] , rtB . bbupnojfch [ 0 ] ) ;
bzglndm1xq = ( ( ( rtB . bbupnojfch [ 2 ] + rtB . mli0y4udzs ) * rtB .
ewfw4ajeec - rtB . jrebo5mrdq ) + rtB . euvzemougu * rtB . f4iofc4dn5 ) *
0.001 ; oltw25yayb = ssGetT ( rtS ) ; rtB . odftn2hv1u = rtP .
Gain_Gain_o4i5m3le5k * oltw25yayb + rtP . JDepoch_days_Value ;
jpewagwvqf_idx_0 = ( rtB . odftn2hv1u - 2.4150195E+6 ) / 365.25 ; fug530bbhx
= muDoubleScalarFloor ( jpewagwvqf_idx_0 ) ; jpewagwvqf_idx_0 =
muDoubleScalarFloor ( jpewagwvqf_idx_0 ) + 1900.0 ; i2lmhfpmzi = ( rtB .
odftn2hv1u - 2.4150195E+6 ) - ( ( ( fug530bbhx + 1900.0 ) - 1900.0 ) * 365.0
+ muDoubleScalarFloor ( ( ( fug530bbhx + 1900.0 ) - 1901.0 ) * 0.25 ) ) ; if
( i2lmhfpmzi < 1.0 ) { jpewagwvqf_idx_0 = ( fug530bbhx + 1900.0 ) - 1.0 ;
i2lmhfpmzi = ( rtB . odftn2hv1u - 2.4150195E+6 ) - ( ( ( ( fug530bbhx +
1900.0 ) - 1.0 ) - 1900.0 ) * 365.0 + muDoubleScalarFloor ( ( ( ( fug530bbhx
+ 1900.0 ) - 1.0 ) - 1901.0 ) * 0.25 ) ) ; } for ( s258_iter = 0 ; s258_iter
< 12 ; s258_iter ++ ) { lmonth [ s258_iter ] = 31.0 ; if ( s258_iter + 1 == 2
) { lmonth [ s258_iter ] = 28.0 ; } if ( ( s258_iter + 1 == 4 ) || (
s258_iter + 1 == 6 ) || ( s258_iter + 1 == 9 ) || ( s258_iter + 1 == 11 ) ) {
lmonth [ s258_iter ] = 30.0 ; } } fug530bbhx = muDoubleScalarFloor (
i2lmhfpmzi ) ; if ( muDoubleScalarRem ( jpewagwvqf_idx_0 - 1900.0 , 4.0 ) ==
0.0 ) { lmonth [ 1 ] = 29.0 ; } s258_iter = 1 ; chxdtzje0j = 0.0 ; while ( (
fug530bbhx > lmonth [ s258_iter - 1 ] + chxdtzje0j ) && ( s258_iter < 12 ) )
{ chxdtzje0j += lmonth [ s258_iter - 1 ] ; s258_iter ++ ; } evfxmkblai = (
i2lmhfpmzi - fug530bbhx ) * 24.0 ; if ( evfxmkblai < 0.0 ) { i2lmhfpmzi =
muDoubleScalarCeil ( evfxmkblai ) ; } else { i2lmhfpmzi = muDoubleScalarFloor
( evfxmkblai ) ; } evfxmkblai = ( evfxmkblai - i2lmhfpmzi ) * 60.0 ; if (
evfxmkblai < 0.0 ) { jpewagwvqf_idx_2 = muDoubleScalarCeil ( evfxmkblai ) ; }
else { jpewagwvqf_idx_2 = muDoubleScalarFloor ( evfxmkblai ) ; } evfxmkblai =
( evfxmkblai - jpewagwvqf_idx_2 ) * 60.0 ; rtB . igqwt1yjrx =
jpewagwvqf_idx_0 ; rtB . mokdwqn5tv = s258_iter ; rtB . jl0xq30mcu =
fug530bbhx - chxdtzje0j ; rtB . f20ikslrr0 = i2lmhfpmzi ; rtB . kx5tkh0df0 =
jpewagwvqf_idx_2 ; rtB . irruavepb4 = evfxmkblai ; rtB . harzibozpz =
fug530bbhx ; rtB . eawptovapg = ( i2lmhfpmzi * 3600.0 + jpewagwvqf_idx_2 *
60.0 ) + evfxmkblai ; rtB . d2wjb40qki = oltw25yayb + rtB . fqejnq5fml ; {
struct nrlmsise_flags flags ; int_T i ; real_T absPhi , absLambda , lst ;
boolean_T phi_wrapped = false ; real_T * phi = ( real_T * ) & rtDW .
fa1es2nu0v ; real_T * h = ( real_T * ) & rtDW . krqhenkhky ; real_T * lambda
= ( real_T * ) & rtDW . ii40oryl4u ; real_T * ap = ( real_T * ) & rtDW .
fkzball0la ; int_T * doy_int = ( int_T * ) & rtDW . jmztpvsjv0 ; real_T * T =
( real_T * ) & rtB . bloxjw4yky [ 0 ] ; real_T * rho = ( real_T * ) & rtB .
ad2fwlvomc [ 0 ] ; real_T * heightInput = ( real_T * ) & bzglndm1xq ; real_T
* phiInput = ( real_T * ) & amhhnifger ; real_T * lambdaInput = ( real_T * )
& gfdktyyhs5 ; real_T * flagsInput = ( real_T * ) & rtP .
NRLMSISE00AtmosphereModel_flags [ 0 ] ; int_T lstFlag = ( int_T ) 0.0 ; const
real_T * doy = ( const real_T * ) & rtB . harzibozpz ; const real_T * sec = (
const real_T * ) & rtB . d2wjb40qki ; const real_T * lstPort = ( const real_T
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
) { ijs1lor1qv [ i ] = rtB . ad2fwlvomc [ tmp_g [ i ] ] ; } for ( i = 0 ; i <
6 ; i ++ ) { lah2koeql2 [ i ] = ijs1lor1qv [ i ] ; } rtB . dlialfoqve [ 0 ] =
rtX . agflyx222j [ 0 ] ; rtB . dlialfoqve [ 1 ] = rtX . agflyx222j [ 1 ] ;
rtB . dlialfoqve [ 2 ] = rtX . agflyx222j [ 2 ] ; oltw25yayb =
muDoubleScalarSqrt ( ( rtB . dlialfoqve [ 0 ] * rtB . dlialfoqve [ 0 ] + rtB
. dlialfoqve [ 1 ] * rtB . dlialfoqve [ 1 ] ) + rtB . dlialfoqve [ 2 ] * rtB
. dlialfoqve [ 2 ] ) ; jpewagwvqf_idx_0 = oltw25yayb * oltw25yayb *
lah2koeql2 [ 5 ] * rtP . Gain_Gain_ciwym1xe3o ; if ( egmjspetb3 > rtP .
Switch1_Threshold_dixrx2rqvf ) { fug530bbhx = rtP . DYN_AERO_par .
Area_Deployed ; } else { fug530bbhx = rtP . DYN_AERO_par . Area ; } rtB .
mt5ejwesnp [ 0 ] = k4q33fn5wp * jpewagwvqf_idx_0 * ( rtB . dlialfoqve [ 0 ] /
oltw25yayb ) * fug530bbhx ; rtB . mt5ejwesnp [ 1 ] = k4q33fn5wp *
jpewagwvqf_idx_0 * ( rtB . dlialfoqve [ 1 ] / oltw25yayb ) * fug530bbhx ; rtB
. mt5ejwesnp [ 2 ] = k4q33fn5wp * jpewagwvqf_idx_0 * ( rtB . dlialfoqve [ 2 ]
/ oltw25yayb ) * fug530bbhx ; rtB . ajt3i13qwt [ 0 ] = rtP . DYN_AERO_par .
CP_BOF [ 1 ] * rtB . mt5ejwesnp [ 2 ] - rtP . DYN_AERO_par . CP_BOF [ 2 ] *
rtB . mt5ejwesnp [ 1 ] ; rtB . ajt3i13qwt [ 1 ] = rtP . DYN_AERO_par . CP_BOF
[ 2 ] * rtB . mt5ejwesnp [ 0 ] - rtP . DYN_AERO_par . CP_BOF [ 0 ] * rtB .
mt5ejwesnp [ 2 ] ; rtB . ajt3i13qwt [ 2 ] = rtP . DYN_AERO_par . CP_BOF [ 0 ]
* rtB . mt5ejwesnp [ 1 ] - rtP . DYN_AERO_par . CP_BOF [ 1 ] * rtB .
mt5ejwesnp [ 0 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtP .
JulianDateConversion_month_lojm1u4apm <= 2.0 ) ; rtDW . pods3ngpuh = rtAction
; } else { rtAction = rtDW . pods3ngpuh ; } switch ( rtAction ) { case 0 :
k3sfyh0c3k ( rtP . DirectionCosineMatrixECItoECEF_year , rtP .
JulianDateConversion_month_lojm1u4apm , & g1sn43mf0l , & j3auneqaay , & rtP .
ccrvxjn2zx ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
ccrvxjn2zx . c5enzgh0ln ) ; } break ; case 1 : eu5kqssxx5 ( rtP .
DirectionCosineMatrixECItoECEF_year , rtP .
JulianDateConversion_month_lojm1u4apm , & g1sn43mf0l , & j3auneqaay ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . fse3bizgct . gmbejf1syu ) ;
} break ; } k4q33fn5wp = muDoubleScalarFloor ( rtP . Gain2_Gain_awbzl5swxl *
g1sn43mf0l ) ; rtB . k2m5cyjcxc = ( ( ( muDoubleScalarFloor ( ( g1sn43mf0l +
rtP . BiasYear_Bias_ekq2nttdv1 ) * rtP . Gain_Gain_hlk0dlsuje ) +
muDoubleScalarFloor ( ( j3auneqaay + rtP . Bias1_Bias_jyp11st4jd ) * rtP .
Gain1_Gain_ij5fxr5f4u ) ) + rtP . Bias2_Bias_ldahvgkl0h ) - k4q33fn5wp ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_gcrs4a5en3 * k4q33fn5wp ) ; }
m2ldz44rx4 [ 0 ] = rtP . sec2_Value_jhtvjuwtd3 [ 0 ] ; m2ldz44rx4 [ 1 ] = rtP
. sec2_Value_jhtvjuwtd3 [ 1 ] ; m2ldz44rx4 [ 2 ] = rtP .
sec2_Value_jhtvjuwtd3 [ 2 ] ; m2ldz44rx4 [ 3 ] = rtP . sec2_Value_jhtvjuwtd3
[ 3 ] ; m2ldz44rx4 [ ( int32_T ) rtP . Index_Value_glfdv0gwi4 - 1 ] = rtB .
d2wjb40qki ; jpewagwvqf_idx_0 = m2ldz44rx4 [ 0 ] ; oltw25yayb = m2ldz44rx4 [
1 ] ; bpuwpgpm3m = m2ldz44rx4 [ 2 ] ; ohohv0ef3n = m2ldz44rx4 [ 3 ] ;
k4q33fn5wp = ( ( ( ( ( ( rtP . DirectionCosineMatrixECItoECEF_min +
bpuwpgpm3m ) * rtP . Gain5_Gain_lrl4u1x0vd + ( rtP .
DirectionCosineMatrixECItoECEF_hour + oltw25yayb ) ) + ( rtP .
JulianDateConversion_sec_oypk4uawdh + ohohv0ef3n ) * rtP .
Gain6_Gain_mqy3djvdly ) * rtP . Gain4_Gain_amkvwtlsmf + ( ( ( rtP .
JulianDateConversion_day_kmvymyt2gr + jpewagwvqf_idx_0 ) + rtB . k2m5cyjcxc )
+ rtP . BiasDay_Bias_iyjzgz1krp ) ) + rtB . jv1d0qfy4m ) + rtP .
Bias1_Bias_onjh0xywa3 ) * rtP . Gain_Gain_oej452fzct ; muDoubleScalarSinCos (
0.017453292519943295 * ( rtP . Gain_Gain_ndkkslk451 * k4q33fn5wp ) , &
jpewagwvqf_idx_0 , & pz1213rdrt [ 0 ] ) ; muDoubleScalarSinCos ( rtB .
gm45wrvmmz [ 0 ] , & oltw25yayb , & pz1213rdrt [ 1 ] ) ; muDoubleScalarSinCos
( rtB . gm45wrvmmz [ 1 ] , & acweymdfsj , & pz1213rdrt [ 2 ] ) ; lah2koeql2 [
0 ] = pz1213rdrt [ 1 ] * pz1213rdrt [ 0 ] ; lah2koeql2 [ 1 ] = acweymdfsj *
oltw25yayb * pz1213rdrt [ 0 ] - pz1213rdrt [ 2 ] * jpewagwvqf_idx_0 ;
lah2koeql2 [ 2 ] = pz1213rdrt [ 2 ] * oltw25yayb * pz1213rdrt [ 0 ] +
acweymdfsj * jpewagwvqf_idx_0 ; lah2koeql2 [ 3 ] = pz1213rdrt [ 1 ] *
jpewagwvqf_idx_0 ; lah2koeql2 [ 4 ] = acweymdfsj * oltw25yayb *
jpewagwvqf_idx_0 + pz1213rdrt [ 2 ] * pz1213rdrt [ 0 ] ; lah2koeql2 [ 5 ] =
pz1213rdrt [ 2 ] * oltw25yayb * jpewagwvqf_idx_0 - acweymdfsj * pz1213rdrt [
0 ] ; lah2koeql2 [ 6 ] = - oltw25yayb ; lah2koeql2 [ 7 ] = acweymdfsj *
pz1213rdrt [ 1 ] ; lah2koeql2 [ 8 ] = pz1213rdrt [ 2 ] * pz1213rdrt [ 1 ] ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtP . JulianDateConversion_month_a2eshsju1n <= 2.0
) ; rtDW . dgi2ryavxf = rtAction ; } else { rtAction = rtDW . dgi2ryavxf ; }
switch ( rtAction ) { case 0 : k3sfyh0c3k ( rtP .
DirectionCosineMatrixECItoECEF_year , rtP .
JulianDateConversion_month_a2eshsju1n , & i5fgw4qg3a , & bn01gmujrh , & rtP .
f3bpn3lnkh ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
f3bpn3lnkh . c5enzgh0ln ) ; } break ; case 1 : eu5kqssxx5 ( rtP .
DirectionCosineMatrixECItoECEF_year , rtP .
JulianDateConversion_month_a2eshsju1n , & i5fgw4qg3a , & bn01gmujrh ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . cpe4p1nzlo . gmbejf1syu ) ;
} break ; } oltw25yayb = muDoubleScalarFloor ( rtP . Gain2_Gain_l4tmhxbslq *
i5fgw4qg3a ) ; rtB . j5jwy3odai = ( ( ( muDoubleScalarFloor ( ( i5fgw4qg3a +
rtP . BiasYear_Bias_imsh3ixp5m ) * rtP . Gain_Gain_dzc5eq4jde ) +
muDoubleScalarFloor ( ( bn01gmujrh + rtP . Bias1_Bias_bkfwxcvhlr ) * rtP .
Gain1_Gain_nqjbd4cvsr ) ) + rtP . Bias2_Bias_eu1ohcctud ) - oltw25yayb ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_c5kepxotnq * oltw25yayb ) ; }
m2ldz44rx4 [ 0 ] = rtP . sec2_Value_pis0t02q3n [ 0 ] ; m2ldz44rx4 [ 1 ] = rtP
. sec2_Value_pis0t02q3n [ 1 ] ; m2ldz44rx4 [ 2 ] = rtP .
sec2_Value_pis0t02q3n [ 2 ] ; m2ldz44rx4 [ 3 ] = rtP . sec2_Value_pis0t02q3n
[ 3 ] ; m2ldz44rx4 [ ( int32_T ) rtP . Index_Value_i2ivw01z5k - 1 ] = rtB .
d2wjb40qki ; jpewagwvqf_idx_0 = m2ldz44rx4 [ 0 ] ; oltw25yayb = m2ldz44rx4 [
1 ] ; bpuwpgpm3m = m2ldz44rx4 [ 2 ] ; ohohv0ef3n = m2ldz44rx4 [ 3 ] ;
oltw25yayb = ( ( ( ( ( rtP . DirectionCosineMatrixECItoECEF_min + bpuwpgpm3m
) * rtP . Gain5_Gain_i2whnjgqrb + ( rtP . DirectionCosineMatrixECItoECEF_hour
+ oltw25yayb ) ) + ( rtP . JulianDateConversion_sec_oc0zkhngk4 + ohohv0ef3n )
* rtP . Gain6_Gain_iu4xfjvn3q ) * rtP . Gain4_Gain_gionsmqgjc + ( ( ( rtP .
JulianDateConversion_day_onhw3gbpmx + jpewagwvqf_idx_0 ) + rtB . j5jwy3odai )
+ rtP . BiasDay_Bias_lsy34iafjp ) ) + rtB . a0ua2epli1 ) + rtP .
Bias_Bias_n53vi0dm2i ; oltw25yayb = muDoubleScalarMod ( ( ( muDoubleScalarMod
( oltw25yayb , rtP . Constant_Value_ksu35oenhl ) + rtP .
Bias1_Bias_k3tkuodmxy ) + rtP . Gain_Gain_pfmppwunjf * oltw25yayb ) * rtP .
Gain1_Gain_bnnhkcipw4 , rtP . Constant_Value_dkayhkb1ee ) ;
muDoubleScalarSinCos ( oltw25yayb , & jpewagwvqf_idx_0 , & pz1213rdrt [ 0 ] )
; muDoubleScalarSinCos ( rtP . Constant1_Value_dvynw02bvl [ 0 ] , &
oltw25yayb , & pz1213rdrt [ 1 ] ) ; muDoubleScalarSinCos ( rtP .
Constant1_Value_dvynw02bvl [ 1 ] , & acweymdfsj , & pz1213rdrt [ 2 ] ) ;
f1iitcpwuk [ 0 ] = pz1213rdrt [ 1 ] * pz1213rdrt [ 0 ] ; f1iitcpwuk [ 1 ] =
acweymdfsj * oltw25yayb * pz1213rdrt [ 0 ] - pz1213rdrt [ 2 ] *
jpewagwvqf_idx_0 ; f1iitcpwuk [ 2 ] = pz1213rdrt [ 2 ] * oltw25yayb *
pz1213rdrt [ 0 ] + acweymdfsj * jpewagwvqf_idx_0 ; f1iitcpwuk [ 3 ] =
pz1213rdrt [ 1 ] * jpewagwvqf_idx_0 ; f1iitcpwuk [ 4 ] = acweymdfsj *
oltw25yayb * jpewagwvqf_idx_0 + pz1213rdrt [ 2 ] * pz1213rdrt [ 0 ] ;
f1iitcpwuk [ 5 ] = pz1213rdrt [ 2 ] * oltw25yayb * jpewagwvqf_idx_0 -
acweymdfsj * pz1213rdrt [ 0 ] ; f1iitcpwuk [ 6 ] = - oltw25yayb ; f1iitcpwuk
[ 7 ] = acweymdfsj * pz1213rdrt [ 1 ] ; f1iitcpwuk [ 8 ] = pz1213rdrt [ 2 ] *
pz1213rdrt [ 1 ] ; fug530bbhx = rtP . Y0_Coefs_bwrgfw3tef [ 0 ] ; for (
s258_iter = 0 ; s258_iter < 5 ; s258_iter ++ ) { fug530bbhx = fug530bbhx *
k4q33fn5wp + rtP . Y0_Coefs_bwrgfw3tef [ s258_iter + 1 ] ; } chxdtzje0j =
k4q33fn5wp * k4q33fn5wp ; i2lmhfpmzi = chxdtzje0j * k4q33fn5wp ;
jpewagwvqf_idx_2 = i2lmhfpmzi * k4q33fn5wp ; n32jw4rqz5 [ 0 ] =
muDoubleScalarMod ( ( ( ( ( rtP . mMoon_Coefs_cidt3skfqi [ 0 ] * k4q33fn5wp +
rtP . mMoon_Coefs_cidt3skfqi [ 1 ] ) * k4q33fn5wp + rtP .
mMoon_Coefs_cidt3skfqi [ 2 ] ) * k4q33fn5wp + rtP . mMoon_Coefs_cidt3skfqi [
3 ] ) * k4q33fn5wp + rtP . mMoon_Coefs_cidt3skfqi [ 4 ] ) * rtP .
Gain_Gain_m2mgem3n4b * 0.017453292519943295 , rtP . Constant_Value_ahtudx4mbv
) ; n32jw4rqz5 [ 1 ] = muDoubleScalarMod ( ( ( ( ( rtP .
mSun_Coefs_axhju4mj5r [ 0 ] * k4q33fn5wp + rtP . mSun_Coefs_axhju4mj5r [ 1 ]
) * k4q33fn5wp + rtP . mSun_Coefs_axhju4mj5r [ 2 ] ) * k4q33fn5wp + rtP .
mSun_Coefs_axhju4mj5r [ 3 ] ) * k4q33fn5wp + rtP . mSun_Coefs_axhju4mj5r [ 4
] ) * rtP . Gain_Gain_m2mgem3n4b * 0.017453292519943295 , rtP .
Constant_Value_ahtudx4mbv ) ; n32jw4rqz5 [ 2 ] = muDoubleScalarMod ( ( ( ( (
rtP . umMoon_Coefs_le3esxmyqt [ 0 ] * k4q33fn5wp + rtP .
umMoon_Coefs_le3esxmyqt [ 1 ] ) * k4q33fn5wp + rtP . umMoon_Coefs_le3esxmyqt
[ 2 ] ) * k4q33fn5wp + rtP . umMoon_Coefs_le3esxmyqt [ 3 ] ) * k4q33fn5wp +
rtP . umMoon_Coefs_le3esxmyqt [ 4 ] ) * rtP . Gain_Gain_m2mgem3n4b *
0.017453292519943295 , rtP . Constant_Value_ahtudx4mbv ) ; n32jw4rqz5 [ 3 ] =
muDoubleScalarMod ( ( ( ( ( rtP . dSun_Coefs_f3irhysq0t [ 0 ] * k4q33fn5wp +
rtP . dSun_Coefs_f3irhysq0t [ 1 ] ) * k4q33fn5wp + rtP .
dSun_Coefs_f3irhysq0t [ 2 ] ) * k4q33fn5wp + rtP . dSun_Coefs_f3irhysq0t [ 3
] ) * k4q33fn5wp + rtP . dSun_Coefs_f3irhysq0t [ 4 ] ) * rtP .
Gain_Gain_m2mgem3n4b * 0.017453292519943295 , rtP . Constant_Value_ahtudx4mbv
) ; n32jw4rqz5 [ 4 ] = muDoubleScalarMod ( ( ( ( ( rtP .
omegaMoon_Coefs_j5eu514zo1 [ 0 ] * k4q33fn5wp + rtP .
omegaMoon_Coefs_j5eu514zo1 [ 1 ] ) * k4q33fn5wp + rtP .
omegaMoon_Coefs_j5eu514zo1 [ 2 ] ) * k4q33fn5wp + rtP .
omegaMoon_Coefs_j5eu514zo1 [ 3 ] ) * k4q33fn5wp + rtP .
omegaMoon_Coefs_j5eu514zo1 [ 4 ] ) * rtP . Gain_Gain_m2mgem3n4b *
0.017453292519943295 , rtP . Constant_Value_ahtudx4mbv ) ; n32jw4rqz5 [ 5 ] =
muDoubleScalarMod ( rtP . lMercury_Coefs_obscuuka2n [ 0 ] * k4q33fn5wp + rtP
. lMercury_Coefs_obscuuka2n [ 1 ] , rtP . Constant_Value_ahtudx4mbv ) ;
n32jw4rqz5 [ 6 ] = muDoubleScalarMod ( rtP . lVenus_Coefs_cx2zgmgsf0 [ 0 ] *
k4q33fn5wp + rtP . lVenus_Coefs_cx2zgmgsf0 [ 1 ] , rtP .
Constant_Value_ahtudx4mbv ) ; n32jw4rqz5 [ 7 ] = muDoubleScalarMod ( rtP .
lEarth_Coefs_d42olao44d [ 0 ] * k4q33fn5wp + rtP . lEarth_Coefs_d42olao44d [
1 ] , rtP . Constant_Value_ahtudx4mbv ) ; n32jw4rqz5 [ 8 ] =
muDoubleScalarMod ( rtP . lMars_Coefs_pyrwksj5dw [ 0 ] * k4q33fn5wp + rtP .
lMars_Coefs_pyrwksj5dw [ 1 ] , rtP . Constant_Value_ahtudx4mbv ) ; n32jw4rqz5
[ 9 ] = muDoubleScalarMod ( rtP . lJupiter_Coefs_gygbwhbo5q [ 0 ] *
k4q33fn5wp + rtP . lJupiter_Coefs_gygbwhbo5q [ 1 ] , rtP .
Constant_Value_ahtudx4mbv ) ; n32jw4rqz5 [ 10 ] = muDoubleScalarMod ( rtP .
lSaturn_Coefs_mcg0rrj2nd [ 0 ] * k4q33fn5wp + rtP . lSaturn_Coefs_mcg0rrj2nd
[ 1 ] , rtP . Constant_Value_ahtudx4mbv ) ; n32jw4rqz5 [ 11 ] =
muDoubleScalarMod ( rtP . lUranus_Coefs_dx42eubvi2 [ 0 ] * k4q33fn5wp + rtP .
lUranus_Coefs_dx42eubvi2 [ 1 ] , rtP . Constant_Value_ahtudx4mbv ) ;
n32jw4rqz5 [ 12 ] = muDoubleScalarMod ( rtP . lNeptune_Coefs_l1hxb3q0ll [ 0 ]
* k4q33fn5wp + rtP . lNeptune_Coefs_l1hxb3q0ll [ 1 ] , rtP .
Constant_Value_ahtudx4mbv ) ; n32jw4rqz5 [ 13 ] = muDoubleScalarMod ( ( rtP .
pa_Coefs_le1r1fm4yh [ 0 ] * k4q33fn5wp + rtP . pa_Coefs_le1r1fm4yh [ 1 ] ) *
k4q33fn5wp + rtP . pa_Coefs_le1r1fm4yh [ 2 ] , rtP .
Constant_Value_ahtudx4mbv ) ; TRANS = 'N' ; M = 1275LL ; N = 14LL ;
oltw25yayb = 1.0 ; LDA = 1275LL ; INCX = 1LL ; jpewagwvqf_idx_0 = 0.0 ; INCY
= 1LL ; dgemv ( & TRANS , & M , & N , & oltw25yayb , & rtB . hs0i1v4xen [ 0 ]
, & LDA , & n32jw4rqz5 [ 0 ] , & INCX , & jpewagwvqf_idx_0 , & rtB .
pgqpd5ik4w_cxarnvbvui [ 0 ] , & INCY ) ; for ( i = 0 ; i < 962 ; i ++ ) { rtB
. m04ridjbke_kkiq3xxxve [ i ] = rtP . Constant1_Value_dwv0tsukpb [ i ] * rtB
. bpam2luzqr [ i ] * muDoubleScalarSin ( rtB . pgqpd5ik4w_cxarnvbvui [ i ] )
; } for ( i = 0 ; i < 277 ; i ++ ) { rtB . m04ridjbke_kkiq3xxxve [ i + 962 ]
= rtB . bpam2luzqr [ i + 962 ] * k4q33fn5wp * muDoubleScalarSin ( rtB .
pgqpd5ik4w_cxarnvbvui [ i + 962 ] ) ; } for ( i = 0 ; i < 30 ; i ++ ) { rtB .
m04ridjbke_kkiq3xxxve [ i + 1239 ] = rtB . bpam2luzqr [ i + 1239 ] *
chxdtzje0j * muDoubleScalarSin ( rtB . pgqpd5ik4w_cxarnvbvui [ i + 1239 ] ) ;
} for ( i = 0 ; i < 5 ; i ++ ) { rtB . m04ridjbke_kkiq3xxxve [ i + 1269 ] =
rtB . bpam2luzqr [ i + 1269 ] * i2lmhfpmzi * muDoubleScalarSin ( rtB .
pgqpd5ik4w_cxarnvbvui [ i + 1269 ] ) ; } rtB . m04ridjbke_kkiq3xxxve [ 1274 ]
= jpewagwvqf_idx_2 * rtB . bpam2luzqr [ 1274 ] * muDoubleScalarSin ( rtB .
pgqpd5ik4w_cxarnvbvui [ 1274 ] ) ; for ( s258_iter = 0 ; s258_iter < 1275 ;
s258_iter ++ ) { rtB . pgqpd5ik4w_cxarnvbvui [ s258_iter ] =
muDoubleScalarCos ( rtB . pgqpd5ik4w_cxarnvbvui [ s258_iter ] ) ; } memcpy (
& rtB . dv1 [ 0 ] , & rtP . Constant1_Value_dwv0tsukpb [ 0 ] , 962U * sizeof
( real_T ) ) ; for ( s258_iter = 0 ; s258_iter < 277 ; s258_iter ++ ) { rtB .
dv1 [ s258_iter + 962 ] = k4q33fn5wp ; } for ( s258_iter = 0 ; s258_iter < 30
; s258_iter ++ ) { rtB . dv1 [ s258_iter + 1239 ] = chxdtzje0j ; } for (
s258_iter = 0 ; s258_iter < 5 ; s258_iter ++ ) { rtB . dv1 [ s258_iter + 1269
] = i2lmhfpmzi ; } rtB . dv1 [ 1274 ] = jpewagwvqf_idx_2 ; fqhdbem00h = - 0.0
; for ( i = 0 ; i < 1275 ; i ++ ) { oltw25yayb = rtB . pgqpd5ik4w_cxarnvbvui
[ i ] * rtB . muwbjqqbz2 [ i ] * rtB . dv1 [ i ] ; jpewagwvqf_idx_0 = rtB .
m04ridjbke_kkiq3xxxve [ i ] + oltw25yayb ; fqhdbem00h += jpewagwvqf_idx_0 ;
rtB . pgqpd5ik4w_cxarnvbvui [ i ] = oltw25yayb ; rtB . m04ridjbke_kkiq3xxxve
[ i ] = jpewagwvqf_idx_0 ; } fqhdbem00h = ( fug530bbhx + fqhdbem00h ) * rtP .
Gain4_Gain_pmnkzgmte0 * 0.017453292519943295 + rtP . AddParam_Value [ 1 ] ;
fug530bbhx = rtP . X0_Coefs_n5lp2rc1aa [ 0 ] ; for ( s258_iter = 0 ;
s258_iter < 5 ; s258_iter ++ ) { fug530bbhx = fug530bbhx * k4q33fn5wp + rtP .
X0_Coefs_n5lp2rc1aa [ s258_iter + 1 ] ; } chxdtzje0j = k4q33fn5wp *
k4q33fn5wp ; i2lmhfpmzi = chxdtzje0j * k4q33fn5wp ; jpewagwvqf_idx_2 =
i2lmhfpmzi * k4q33fn5wp ; TRANS = 'N' ; M = 1600LL ; N = 14LL ; oltw25yayb =
1.0 ; LDA = 1600LL ; INCX = 1LL ; jpewagwvqf_idx_0 = 0.0 ; INCY = 1LL ; dgemv
( & TRANS , & M , & N , & oltw25yayb , & rtB . ag3iipcuzh [ 0 ] , & LDA , &
n32jw4rqz5 [ 0 ] , & INCX , & jpewagwvqf_idx_0 , & rtB .
ooyuznughj_cl54gopm0x [ 0 ] , & INCY ) ; for ( i = 0 ; i < 1306 ; i ++ ) {
rtB . pcu42j55xs_mbvzarwird [ i ] = rtP . Constant1_Value_fzzob5xizj [ i ] *
rtB . g22eqcolk1 [ i ] * muDoubleScalarSin ( rtB . ooyuznughj_cl54gopm0x [ i
] ) ; } for ( i = 0 ; i < 253 ; i ++ ) { rtB . pcu42j55xs_mbvzarwird [ i +
1306 ] = rtB . g22eqcolk1 [ i + 1306 ] * k4q33fn5wp * muDoubleScalarSin ( rtB
. ooyuznughj_cl54gopm0x [ i + 1306 ] ) ; } for ( i = 0 ; i < 36 ; i ++ ) {
rtB . pcu42j55xs_mbvzarwird [ i + 1559 ] = rtB . g22eqcolk1 [ i + 1559 ] *
chxdtzje0j * muDoubleScalarSin ( rtB . ooyuznughj_cl54gopm0x [ i + 1559 ] ) ;
} rtB . pcu42j55xs_mbvzarwird [ 1595 ] = i2lmhfpmzi * rtB . g22eqcolk1 [ 1595
] * muDoubleScalarSin ( rtB . ooyuznughj_cl54gopm0x [ 1595 ] ) ; rtB .
pcu42j55xs_mbvzarwird [ 1596 ] = i2lmhfpmzi * rtB . g22eqcolk1 [ 1596 ] *
muDoubleScalarSin ( rtB . ooyuznughj_cl54gopm0x [ 1596 ] ) ; rtB .
pcu42j55xs_mbvzarwird [ 1597 ] = i2lmhfpmzi * rtB . g22eqcolk1 [ 1597 ] *
muDoubleScalarSin ( rtB . ooyuznughj_cl54gopm0x [ 1597 ] ) ; rtB .
pcu42j55xs_mbvzarwird [ 1598 ] = i2lmhfpmzi * rtB . g22eqcolk1 [ 1598 ] *
muDoubleScalarSin ( rtB . ooyuznughj_cl54gopm0x [ 1598 ] ) ; rtB .
pcu42j55xs_mbvzarwird [ 1599 ] = jpewagwvqf_idx_2 * rtB . g22eqcolk1 [ 1599 ]
* muDoubleScalarSin ( rtB . ooyuznughj_cl54gopm0x [ 1599 ] ) ; for (
s258_iter = 0 ; s258_iter < 1600 ; s258_iter ++ ) { rtB .
ooyuznughj_cl54gopm0x [ s258_iter ] = muDoubleScalarCos ( rtB .
ooyuznughj_cl54gopm0x [ s258_iter ] ) ; } memcpy ( & rtB . dv [ 0 ] , & rtP .
Constant1_Value_fzzob5xizj [ 0 ] , 1306U * sizeof ( real_T ) ) ; for (
s258_iter = 0 ; s258_iter < 253 ; s258_iter ++ ) { rtB . dv [ s258_iter +
1306 ] = k4q33fn5wp ; } for ( s258_iter = 0 ; s258_iter < 36 ; s258_iter ++ )
{ rtB . dv [ s258_iter + 1559 ] = chxdtzje0j ; } rtB . dv [ 1595 ] =
i2lmhfpmzi ; rtB . dv [ 1596 ] = i2lmhfpmzi ; rtB . dv [ 1597 ] = i2lmhfpmzi
; rtB . dv [ 1598 ] = i2lmhfpmzi ; rtB . dv [ 1599 ] = jpewagwvqf_idx_2 ;
g5pzqldhbn = - 0.0 ; for ( i = 0 ; i < 1600 ; i ++ ) { oltw25yayb = rtB .
ooyuznughj_cl54gopm0x [ i ] * rtB . dw4fhg5i10 [ i ] * rtB . dv [ i ] ;
jpewagwvqf_idx_0 = rtB . pcu42j55xs_mbvzarwird [ i ] + oltw25yayb ;
g5pzqldhbn += jpewagwvqf_idx_0 ; rtB . ooyuznughj_cl54gopm0x [ i ] =
oltw25yayb ; rtB . pcu42j55xs_mbvzarwird [ i ] = jpewagwvqf_idx_0 ; }
g5pzqldhbn = ( fug530bbhx + g5pzqldhbn ) * rtP . Gain3_Gain_i1ru15t2mc *
0.017453292519943295 + rtP . AddParam_Value [ 0 ] ; fug530bbhx =
muDoubleScalarAtan2 ( fqhdbem00h , g5pzqldhbn ) ; chxdtzje0j = g5pzqldhbn *
g5pzqldhbn + fqhdbem00h * fqhdbem00h ; i2lmhfpmzi = rtP . S0_Coefs_inc4sr1jg5
[ 0 ] ; jpewagwvqf_idx_2 = k4q33fn5wp * k4q33fn5wp ; evfxmkblai =
jpewagwvqf_idx_2 * k4q33fn5wp ; acweymdfsj = evfxmkblai * k4q33fn5wp ; TRANS
= 'N' ; M = 66LL ; N = 8LL ; oltw25yayb = 1.0 ; LDA = 66LL ; for ( s258_iter
= 0 ; s258_iter < 5 ; s258_iter ++ ) { i2lmhfpmzi = i2lmhfpmzi * k4q33fn5wp +
rtP . S0_Coefs_inc4sr1jg5 [ s258_iter + 1 ] ; ijs1lor1qv [ s258_iter ] =
n32jw4rqz5 [ s258_iter ] ; } ijs1lor1qv [ 5 ] = n32jw4rqz5 [ 6 ] ; ijs1lor1qv
[ 6 ] = n32jw4rqz5 [ 7 ] ; ijs1lor1qv [ 7 ] = n32jw4rqz5 [ 13 ] ; INCX = 1LL
; jpewagwvqf_idx_0 = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , &
oltw25yayb , & rtB . j1syazdgd4 [ 0 ] , & LDA , & ijs1lor1qv [ 0 ] , & INCX ,
& jpewagwvqf_idx_0 , & kiruj5xuq5 [ 0 ] , & INCY ) ; for ( i = 0 ; i < 33 ; i
++ ) { f4ne12mlzi [ i ] = rtP . Constant1_Value_ouz0cwj015 [ i ] * rtB .
gsgwdmkgku [ i ] * muDoubleScalarSin ( kiruj5xuq5 [ i ] ) ; } f4ne12mlzi [ 33
] = k4q33fn5wp * rtB . gsgwdmkgku [ 33 ] * muDoubleScalarSin ( kiruj5xuq5 [
33 ] ) ; f4ne12mlzi [ 34 ] = k4q33fn5wp * rtB . gsgwdmkgku [ 34 ] *
muDoubleScalarSin ( kiruj5xuq5 [ 34 ] ) ; f4ne12mlzi [ 35 ] = k4q33fn5wp *
rtB . gsgwdmkgku [ 35 ] * muDoubleScalarSin ( kiruj5xuq5 [ 35 ] ) ; for ( i =
0 ; i < 25 ; i ++ ) { f4ne12mlzi [ i + 36 ] = rtB . gsgwdmkgku [ i + 36 ] *
jpewagwvqf_idx_2 * muDoubleScalarSin ( kiruj5xuq5 [ i + 36 ] ) ; } f4ne12mlzi
[ 61 ] = evfxmkblai * rtB . gsgwdmkgku [ 61 ] * muDoubleScalarSin (
kiruj5xuq5 [ 61 ] ) ; f4ne12mlzi [ 62 ] = evfxmkblai * rtB . gsgwdmkgku [ 62
] * muDoubleScalarSin ( kiruj5xuq5 [ 62 ] ) ; f4ne12mlzi [ 63 ] = evfxmkblai
* rtB . gsgwdmkgku [ 63 ] * muDoubleScalarSin ( kiruj5xuq5 [ 63 ] ) ;
f4ne12mlzi [ 64 ] = evfxmkblai * rtB . gsgwdmkgku [ 64 ] * muDoubleScalarSin
( kiruj5xuq5 [ 64 ] ) ; f4ne12mlzi [ 65 ] = acweymdfsj * rtB . gsgwdmkgku [
65 ] * muDoubleScalarSin ( kiruj5xuq5 [ 65 ] ) ; for ( s258_iter = 0 ;
s258_iter < 66 ; s258_iter ++ ) { kiruj5xuq5 [ s258_iter ] =
muDoubleScalarCos ( kiruj5xuq5 [ s258_iter ] ) ; } memcpy ( & tmp [ 0 ] , &
rtP . Constant1_Value_ouz0cwj015 [ 0 ] , 33U * sizeof ( real_T ) ) ; tmp [ 33
] = k4q33fn5wp ; tmp [ 34 ] = k4q33fn5wp ; tmp [ 35 ] = k4q33fn5wp ; for (
s258_iter = 0 ; s258_iter < 25 ; s258_iter ++ ) { tmp [ s258_iter + 36 ] =
jpewagwvqf_idx_2 ; } tmp [ 61 ] = evfxmkblai ; tmp [ 62 ] = evfxmkblai ; tmp
[ 63 ] = evfxmkblai ; tmp [ 64 ] = evfxmkblai ; tmp [ 65 ] = acweymdfsj ;
evfxmkblai = - 0.0 ; for ( i = 0 ; i < 66 ; i ++ ) { oltw25yayb = kiruj5xuq5
[ i ] * rtB . axbdr3x1fp [ i ] * tmp [ i ] ; jpewagwvqf_idx_0 = f4ne12mlzi [
i ] + oltw25yayb ; evfxmkblai += jpewagwvqf_idx_0 ; kiruj5xuq5 [ i ] =
oltw25yayb ; f4ne12mlzi [ i ] = jpewagwvqf_idx_0 ; } muDoubleScalarSinCos (
fug530bbhx , & jpewagwvqf_idx_0 , & pz1213rdrt [ 0 ] ) ; muDoubleScalarSinCos
( muDoubleScalarAtan ( muDoubleScalarSqrt ( chxdtzje0j / ( rtP .
Constant_Value_m3svuae4lu - chxdtzje0j ) ) ) , & oltw25yayb , & pz1213rdrt [
1 ] ) ; muDoubleScalarSinCos ( rtP . Gain1_Gain_nh5jhddhzf * ( (
0.017453292519943295 * ( rtP . Gain2_Gain_apmnxrfk2y * ( i2lmhfpmzi +
evfxmkblai ) ) - rtP . Gain5_Gain_aysc4s0m2h * ( fqhdbem00h * g5pzqldhbn ) )
+ fug530bbhx ) , & acweymdfsj , & pz1213rdrt [ 2 ] ) ; jxl2iyicpw [ 0 ] =
pz1213rdrt [ 0 ] * pz1213rdrt [ 2 ] * pz1213rdrt [ 1 ] - jpewagwvqf_idx_0 *
acweymdfsj ; jxl2iyicpw [ 1 ] = - pz1213rdrt [ 0 ] * pz1213rdrt [ 1 ] *
acweymdfsj - jpewagwvqf_idx_0 * pz1213rdrt [ 2 ] ; jxl2iyicpw [ 2 ] =
pz1213rdrt [ 0 ] * oltw25yayb ; jxl2iyicpw [ 3 ] = jpewagwvqf_idx_0 *
pz1213rdrt [ 2 ] * pz1213rdrt [ 1 ] + pz1213rdrt [ 0 ] * acweymdfsj ;
jxl2iyicpw [ 4 ] = - jpewagwvqf_idx_0 * pz1213rdrt [ 1 ] * acweymdfsj +
pz1213rdrt [ 0 ] * pz1213rdrt [ 2 ] ; jxl2iyicpw [ 5 ] = jpewagwvqf_idx_0 *
oltw25yayb ; jxl2iyicpw [ 6 ] = - oltw25yayb * pz1213rdrt [ 2 ] ; jxl2iyicpw
[ 7 ] = oltw25yayb * acweymdfsj ; jxl2iyicpw [ 8 ] = pz1213rdrt [ 1 ] ; for (
s258_iter = 0 ; s258_iter < 3 ; s258_iter ++ ) { for ( i = 0 ; i < 3 ; i ++ )
{ j5wb5jlzhj [ i + 3 * s258_iter ] = 0.0 ; j5wb5jlzhj [ i + 3 * s258_iter ]
+= jxl2iyicpw [ 3 * s258_iter ] * f1iitcpwuk [ i ] ; j5wb5jlzhj [ i + 3 *
s258_iter ] += jxl2iyicpw [ 3 * s258_iter + 1 ] * f1iitcpwuk [ i + 3 ] ;
j5wb5jlzhj [ i + 3 * s258_iter ] += jxl2iyicpw [ 3 * s258_iter + 2 ] *
f1iitcpwuk [ i + 6 ] ; } } for ( s258_iter = 0 ; s258_iter < 3 ; s258_iter ++
) { for ( i = 0 ; i < 3 ; i ++ ) { madogxzyal [ i + 3 * s258_iter ] = 0.0 ;
madogxzyal [ i + 3 * s258_iter ] += j5wb5jlzhj [ 3 * s258_iter ] * lah2koeql2
[ i ] ; madogxzyal [ i + 3 * s258_iter ] += j5wb5jlzhj [ 3 * s258_iter + 1 ]
* lah2koeql2 [ i + 3 ] ; madogxzyal [ i + 3 * s258_iter ] += j5wb5jlzhj [ 3 *
s258_iter + 2 ] * lah2koeql2 [ i + 6 ] ; } } kaa1h5fw2d ( madogxzyal , & rtB
. kaa1h5fw2dm ) ; cc3vamisq4 ( rtB . kaa1h5fw2dm . apia2ki5qj , & rtB .
fy4zj3hhge ) ; fzzz0da3bp ( rtB . fy4zj3hhge . gaty2jlz2p , & rtB .
pteoo54u1l ) ; noxmrm1w5f ( rtB . pteoo54u1l . otpij24kr0 , rtP . DYN_MAG_par
. m , & rtB . noxmrm1w5fh ) ; psqdofqdfc [ 0 ] = rtX . mqqxdp0em5 [ 0 ] ;
psqdofqdfc [ 1 ] = rtX . mqqxdp0em5 [ 1 ] ; psqdofqdfc [ 2 ] = rtX .
mqqxdp0em5 [ 2 ] ; psqdofqdfc [ 3 ] = rtX . mqqxdp0em5 [ 3 ] ; bq3pldfcaq (
psqdofqdfc , & rtB . bq3pldfcaqv , rtP . LIB_ROT_QNORM_zero_tol ) ;
lj0sp02vlx ( rtB . bq3pldfcaqv . nkouc1qloz , & rtB . lj0sp02vlxl ) ;
fzzz0da3bp ( rtB . lj0sp02vlxl . fdh2hm3qwy , & rtB . arkzj205og ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtAction
= ( int8_T ) ! ( rtP . JulianDateConversion_month_astih3gt22 <= 2.0 ) ; rtDW
. ghsbqj1gdd = rtAction ; } else { rtAction = rtDW . ghsbqj1gdd ; } switch (
rtAction ) { case 0 : k3sfyh0c3k ( rtP . ECIPositiontoLLA_year_hzfjhys0gc ,
rtP . JulianDateConversion_month_astih3gt22 , & oqweut25mw , & og5mr3oopu , &
rtP . kvhpjeahvc ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
kvhpjeahvc . c5enzgh0ln ) ; } break ; case 1 : eu5kqssxx5 ( rtP .
ECIPositiontoLLA_year_hzfjhys0gc , rtP .
JulianDateConversion_month_astih3gt22 , & oqweut25mw , & og5mr3oopu ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . cbgg0vjzsr . gmbejf1syu ) ;
} break ; } evfxmkblai = muDoubleScalarFloor ( rtP . Gain2_Gain_jnf0iavht0 *
oqweut25mw ) ; rtB . m1xertokvw = ( ( ( muDoubleScalarFloor ( ( oqweut25mw +
rtP . BiasYear_Bias_plir0mxcin ) * rtP . Gain_Gain_bjloitegmg ) +
muDoubleScalarFloor ( ( og5mr3oopu + rtP . Bias1_Bias_lvr30dnevt ) * rtP .
Gain1_Gain_p2ht4xvqkz ) ) + rtP . Bias2_Bias_fje2l0fkwy ) - evfxmkblai ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_f5ijzu0fzz * evfxmkblai ) ; }
m2ldz44rx4 [ 0 ] = rtP . sec2_Value_nqa3admmuu [ 0 ] ; m2ldz44rx4 [ 1 ] = rtP
. sec2_Value_nqa3admmuu [ 1 ] ; m2ldz44rx4 [ 2 ] = rtP .
sec2_Value_nqa3admmuu [ 2 ] ; m2ldz44rx4 [ 3 ] = rtP . sec2_Value_nqa3admmuu
[ 3 ] ; evfxmkblai = ssGetT ( rtS ) ; m2ldz44rx4 [ ( int32_T ) rtP .
Index_Value_fz3uncvddf - 1 ] = evfxmkblai ; jpewagwvqf_idx_0 = m2ldz44rx4 [ 0
] ; oltw25yayb = m2ldz44rx4 [ 1 ] ; bpuwpgpm3m = m2ldz44rx4 [ 2 ] ;
ohohv0ef3n = m2ldz44rx4 [ 3 ] ; g5pzqldhbn = ( ( ( ( ( ( rtP .
ECIPositiontoLLA_min_dkkjuh05iq + bpuwpgpm3m ) * rtP . Gain5_Gain_oi0yu20axd
+ ( rtP . ECIPositiontoLLA_hour_evxsy2hcpl + oltw25yayb ) ) + ( rtP .
JulianDateConversion_sec_dv4yi3hyps + ohohv0ef3n ) * rtP .
Gain6_Gain_czvyggzlcz ) * rtP . Gain4_Gain_ewzhaucagg + ( ( ( rtP .
JulianDateConversion_day_hqsimmntf5 + jpewagwvqf_idx_0 ) + rtB . m1xertokvw )
+ rtP . BiasDay_Bias_hraprfl4su ) ) + rtB . gli54111iq ) + rtP .
Bias1_Bias_nj42g2wgiy ) * rtP . Gain_Gain_kptdtjyalj ; muDoubleScalarSinCos (
0.017453292519943295 * ( rtP . Gain_Gain_bv02jx33w5 * g5pzqldhbn ) , &
jpewagwvqf_idx_0 , & pz1213rdrt [ 0 ] ) ; muDoubleScalarSinCos ( rtB .
lem3rvqyps [ 0 ] , & oltw25yayb , & pz1213rdrt [ 1 ] ) ; muDoubleScalarSinCos
( rtB . lem3rvqyps [ 1 ] , & acweymdfsj , & pz1213rdrt [ 2 ] ) ; lah2koeql2 [
0 ] = pz1213rdrt [ 1 ] * pz1213rdrt [ 0 ] ; lah2koeql2 [ 1 ] = acweymdfsj *
oltw25yayb * pz1213rdrt [ 0 ] - pz1213rdrt [ 2 ] * jpewagwvqf_idx_0 ;
lah2koeql2 [ 2 ] = pz1213rdrt [ 2 ] * oltw25yayb * pz1213rdrt [ 0 ] +
acweymdfsj * jpewagwvqf_idx_0 ; lah2koeql2 [ 3 ] = pz1213rdrt [ 1 ] *
jpewagwvqf_idx_0 ; lah2koeql2 [ 4 ] = acweymdfsj * oltw25yayb *
jpewagwvqf_idx_0 + pz1213rdrt [ 2 ] * pz1213rdrt [ 0 ] ; lah2koeql2 [ 5 ] =
pz1213rdrt [ 2 ] * oltw25yayb * jpewagwvqf_idx_0 - acweymdfsj * pz1213rdrt [
0 ] ; lah2koeql2 [ 6 ] = - oltw25yayb ; lah2koeql2 [ 7 ] = acweymdfsj *
pz1213rdrt [ 1 ] ; lah2koeql2 [ 8 ] = pz1213rdrt [ 2 ] * pz1213rdrt [ 1 ] ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) {
rtAction = ( int8_T ) ! ( rtP . JulianDateConversion_month_alwn00nkdo <= 2.0
) ; rtDW . fdkfwem5wv = rtAction ; } else { rtAction = rtDW . fdkfwem5wv ; }
switch ( rtAction ) { case 0 : k3sfyh0c3k ( rtP .
ECIPositiontoLLA_year_hzfjhys0gc , rtP .
JulianDateConversion_month_alwn00nkdo , & j52isufaqr , & n0jkmuiqeb , & rtP .
aoxobjloyv ) ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
aoxobjloyv . c5enzgh0ln ) ; } break ; case 1 : eu5kqssxx5 ( rtP .
ECIPositiontoLLA_year_hzfjhys0gc , rtP .
JulianDateConversion_month_alwn00nkdo , & j52isufaqr , & n0jkmuiqeb ) ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . etw3qygazq . gmbejf1syu ) ;
} break ; } fqhdbem00h = muDoubleScalarFloor ( rtP . Gain2_Gain_p0xkrfvhky *
j52isufaqr ) ; rtB . h5tqcjnxlo = ( ( ( muDoubleScalarFloor ( ( j52isufaqr +
rtP . BiasYear_Bias_bmaluhvoe0 ) * rtP . Gain_Gain_iv3vbucwzk ) +
muDoubleScalarFloor ( ( n0jkmuiqeb + rtP . Bias1_Bias_jonuus30ns ) * rtP .
Gain1_Gain_nvuiwxw25a ) ) + rtP . Bias2_Bias_otf22zkp2b ) - fqhdbem00h ) +
muDoubleScalarFloor ( rtP . Gain3_Gain_aoqhdoyxj4 * fqhdbem00h ) ; }
m2ldz44rx4 [ 0 ] = rtP . sec2_Value_nvuz4xt0x0 [ 0 ] ; m2ldz44rx4 [ 1 ] = rtP
. sec2_Value_nvuz4xt0x0 [ 1 ] ; m2ldz44rx4 [ 2 ] = rtP .
sec2_Value_nvuz4xt0x0 [ 2 ] ; m2ldz44rx4 [ 3 ] = rtP . sec2_Value_nvuz4xt0x0
[ 3 ] ; m2ldz44rx4 [ ( int32_T ) rtP . Index_Value_c2zywt0j1o - 1 ] =
evfxmkblai ; jpewagwvqf_idx_0 = m2ldz44rx4 [ 0 ] ; oltw25yayb = m2ldz44rx4 [
1 ] ; bpuwpgpm3m = m2ldz44rx4 [ 2 ] ; ohohv0ef3n = m2ldz44rx4 [ 3 ] ;
fqhdbem00h = ( ( ( ( ( rtP . ECIPositiontoLLA_min_dkkjuh05iq + bpuwpgpm3m ) *
rtP . Gain5_Gain_ah5345mcbz + ( rtP . ECIPositiontoLLA_hour_evxsy2hcpl +
oltw25yayb ) ) + ( rtP . JulianDateConversion_sec_ehpmmr44me + ohohv0ef3n ) *
rtP . Gain6_Gain_cyiidsiez4 ) * rtP . Gain4_Gain_dqsev3qffw + ( ( ( rtP .
JulianDateConversion_day_oibncvp13p + jpewagwvqf_idx_0 ) + rtB . h5tqcjnxlo )
+ rtP . BiasDay_Bias_grhohsed3v ) ) + rtB . ml34nkrhlq ) + rtP .
Bias_Bias_ixjbzntfcs ; fqhdbem00h = muDoubleScalarMod ( ( ( muDoubleScalarMod
( fqhdbem00h , rtP . Constant_Value_feix0nt3zl ) + rtP .
Bias1_Bias_dtr0arjo0k ) + rtP . Gain_Gain_jz5ez0s5hy * fqhdbem00h ) * rtP .
Gain1_Gain_dhqy2eebus , rtP . Constant_Value_b3n1xwnzjr ) ;
muDoubleScalarSinCos ( fqhdbem00h , & jpewagwvqf_idx_0 , & pz1213rdrt [ 0 ] )
; muDoubleScalarSinCos ( rtP . Constant1_Value_f43klkerwg [ 0 ] , &
oltw25yayb , & pz1213rdrt [ 1 ] ) ; muDoubleScalarSinCos ( rtP .
Constant1_Value_f43klkerwg [ 1 ] , & acweymdfsj , & pz1213rdrt [ 2 ] ) ;
f1iitcpwuk [ 0 ] = pz1213rdrt [ 1 ] * pz1213rdrt [ 0 ] ; f1iitcpwuk [ 1 ] =
acweymdfsj * oltw25yayb * pz1213rdrt [ 0 ] - pz1213rdrt [ 2 ] *
jpewagwvqf_idx_0 ; f1iitcpwuk [ 2 ] = pz1213rdrt [ 2 ] * oltw25yayb *
pz1213rdrt [ 0 ] + acweymdfsj * jpewagwvqf_idx_0 ; f1iitcpwuk [ 3 ] =
pz1213rdrt [ 1 ] * jpewagwvqf_idx_0 ; f1iitcpwuk [ 4 ] = acweymdfsj *
oltw25yayb * jpewagwvqf_idx_0 + pz1213rdrt [ 2 ] * pz1213rdrt [ 0 ] ;
f1iitcpwuk [ 5 ] = pz1213rdrt [ 2 ] * oltw25yayb * jpewagwvqf_idx_0 -
acweymdfsj * pz1213rdrt [ 0 ] ; f1iitcpwuk [ 6 ] = - oltw25yayb ; f1iitcpwuk
[ 7 ] = acweymdfsj * pz1213rdrt [ 1 ] ; f1iitcpwuk [ 8 ] = pz1213rdrt [ 2 ] *
pz1213rdrt [ 1 ] ; fqhdbem00h = rtP . Y0_Coefs_ix5v1tp13f [ 0 ] ; for (
s258_iter = 0 ; s258_iter < 5 ; s258_iter ++ ) { fqhdbem00h = fqhdbem00h *
g5pzqldhbn + rtP . Y0_Coefs_ix5v1tp13f [ s258_iter + 1 ] ; } k4q33fn5wp =
g5pzqldhbn * g5pzqldhbn ; fug530bbhx = k4q33fn5wp * g5pzqldhbn ; chxdtzje0j =
fug530bbhx * g5pzqldhbn ; n32jw4rqz5 [ 0 ] = muDoubleScalarMod ( ( ( ( ( rtP
. mMoon_Coefs_nxqjw1har2 [ 0 ] * g5pzqldhbn + rtP . mMoon_Coefs_nxqjw1har2 [
1 ] ) * g5pzqldhbn + rtP . mMoon_Coefs_nxqjw1har2 [ 2 ] ) * g5pzqldhbn + rtP
. mMoon_Coefs_nxqjw1har2 [ 3 ] ) * g5pzqldhbn + rtP . mMoon_Coefs_nxqjw1har2
[ 4 ] ) * rtP . Gain_Gain_jfjijmjqlv * 0.017453292519943295 , rtP .
Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 1 ] = muDoubleScalarMod ( ( ( ( (
rtP . mSun_Coefs_bmvjcmjux3 [ 0 ] * g5pzqldhbn + rtP . mSun_Coefs_bmvjcmjux3
[ 1 ] ) * g5pzqldhbn + rtP . mSun_Coefs_bmvjcmjux3 [ 2 ] ) * g5pzqldhbn + rtP
. mSun_Coefs_bmvjcmjux3 [ 3 ] ) * g5pzqldhbn + rtP . mSun_Coefs_bmvjcmjux3 [
4 ] ) * rtP . Gain_Gain_jfjijmjqlv * 0.017453292519943295 , rtP .
Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 2 ] = muDoubleScalarMod ( ( ( ( (
rtP . umMoon_Coefs_kgcdo5cdpi [ 0 ] * g5pzqldhbn + rtP .
umMoon_Coefs_kgcdo5cdpi [ 1 ] ) * g5pzqldhbn + rtP . umMoon_Coefs_kgcdo5cdpi
[ 2 ] ) * g5pzqldhbn + rtP . umMoon_Coefs_kgcdo5cdpi [ 3 ] ) * g5pzqldhbn +
rtP . umMoon_Coefs_kgcdo5cdpi [ 4 ] ) * rtP . Gain_Gain_jfjijmjqlv *
0.017453292519943295 , rtP . Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 3 ] =
muDoubleScalarMod ( ( ( ( ( rtP . dSun_Coefs_gdwpgdottt [ 0 ] * g5pzqldhbn +
rtP . dSun_Coefs_gdwpgdottt [ 1 ] ) * g5pzqldhbn + rtP .
dSun_Coefs_gdwpgdottt [ 2 ] ) * g5pzqldhbn + rtP . dSun_Coefs_gdwpgdottt [ 3
] ) * g5pzqldhbn + rtP . dSun_Coefs_gdwpgdottt [ 4 ] ) * rtP .
Gain_Gain_jfjijmjqlv * 0.017453292519943295 , rtP . Constant_Value_lct454zdoq
) ; n32jw4rqz5 [ 4 ] = muDoubleScalarMod ( ( ( ( ( rtP .
omegaMoon_Coefs_eawixivbxh [ 0 ] * g5pzqldhbn + rtP .
omegaMoon_Coefs_eawixivbxh [ 1 ] ) * g5pzqldhbn + rtP .
omegaMoon_Coefs_eawixivbxh [ 2 ] ) * g5pzqldhbn + rtP .
omegaMoon_Coefs_eawixivbxh [ 3 ] ) * g5pzqldhbn + rtP .
omegaMoon_Coefs_eawixivbxh [ 4 ] ) * rtP . Gain_Gain_jfjijmjqlv *
0.017453292519943295 , rtP . Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 5 ] =
muDoubleScalarMod ( rtP . lMercury_Coefs_pybetdv4eb [ 0 ] * g5pzqldhbn + rtP
. lMercury_Coefs_pybetdv4eb [ 1 ] , rtP . Constant_Value_lct454zdoq ) ;
n32jw4rqz5 [ 6 ] = muDoubleScalarMod ( rtP . lVenus_Coefs_hv3qo3uo3w [ 0 ] *
g5pzqldhbn + rtP . lVenus_Coefs_hv3qo3uo3w [ 1 ] , rtP .
Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 7 ] = muDoubleScalarMod ( rtP .
lEarth_Coefs_j0mivuewpj [ 0 ] * g5pzqldhbn + rtP . lEarth_Coefs_j0mivuewpj [
1 ] , rtP . Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 8 ] =
muDoubleScalarMod ( rtP . lMars_Coefs_min3puad3h [ 0 ] * g5pzqldhbn + rtP .
lMars_Coefs_min3puad3h [ 1 ] , rtP . Constant_Value_lct454zdoq ) ; n32jw4rqz5
[ 9 ] = muDoubleScalarMod ( rtP . lJupiter_Coefs_hq4twgfzoz [ 0 ] *
g5pzqldhbn + rtP . lJupiter_Coefs_hq4twgfzoz [ 1 ] , rtP .
Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 10 ] = muDoubleScalarMod ( rtP .
lSaturn_Coefs_nvzevagca4 [ 0 ] * g5pzqldhbn + rtP . lSaturn_Coefs_nvzevagca4
[ 1 ] , rtP . Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 11 ] =
muDoubleScalarMod ( rtP . lUranus_Coefs_fxaxpx10pt [ 0 ] * g5pzqldhbn + rtP .
lUranus_Coefs_fxaxpx10pt [ 1 ] , rtP . Constant_Value_lct454zdoq ) ;
n32jw4rqz5 [ 12 ] = muDoubleScalarMod ( rtP . lNeptune_Coefs_gkf5ct5aik [ 0 ]
* g5pzqldhbn + rtP . lNeptune_Coefs_gkf5ct5aik [ 1 ] , rtP .
Constant_Value_lct454zdoq ) ; n32jw4rqz5 [ 13 ] = muDoubleScalarMod ( ( rtP .
pa_Coefs_cmmkm3cgb1 [ 0 ] * g5pzqldhbn + rtP . pa_Coefs_cmmkm3cgb1 [ 1 ] ) *
g5pzqldhbn + rtP . pa_Coefs_cmmkm3cgb1 [ 2 ] , rtP .
Constant_Value_lct454zdoq ) ; TRANS = 'N' ; M = 1275LL ; N = 14LL ;
oltw25yayb = 1.0 ; LDA = 1275LL ; INCX = 1LL ; jpewagwvqf_idx_0 = 0.0 ; INCY
= 1LL ; dgemv ( & TRANS , & M , & N , & oltw25yayb , & rtB . mr1b0wzzg2 [ 0 ]
, & LDA , & n32jw4rqz5 [ 0 ] , & INCX , & jpewagwvqf_idx_0 , & rtB .
pgqpd5ik4w_cxarnvbvui [ 0 ] , & INCY ) ; for ( i = 0 ; i < 962 ; i ++ ) { rtB
. m04ridjbke_kkiq3xxxve [ i ] = rtP . Constant1_Value_gp2wuzxkly [ i ] * rtB
. obucup33bh [ i ] * muDoubleScalarSin ( rtB . pgqpd5ik4w_cxarnvbvui [ i ] )
; } for ( i = 0 ; i < 277 ; i ++ ) { rtB . m04ridjbke_kkiq3xxxve [ i + 962 ]
= rtB . obucup33bh [ i + 962 ] * g5pzqldhbn * muDoubleScalarSin ( rtB .
pgqpd5ik4w_cxarnvbvui [ i + 962 ] ) ; } for ( i = 0 ; i < 30 ; i ++ ) { rtB .
m04ridjbke_kkiq3xxxve [ i + 1239 ] = rtB . obucup33bh [ i + 1239 ] *
k4q33fn5wp * muDoubleScalarSin ( rtB . pgqpd5ik4w_cxarnvbvui [ i + 1239 ] ) ;
} for ( i = 0 ; i < 5 ; i ++ ) { rtB . m04ridjbke_kkiq3xxxve [ i + 1269 ] =
rtB . obucup33bh [ i + 1269 ] * fug530bbhx * muDoubleScalarSin ( rtB .
pgqpd5ik4w_cxarnvbvui [ i + 1269 ] ) ; } rtB . m04ridjbke_kkiq3xxxve [ 1274 ]
= chxdtzje0j * rtB . obucup33bh [ 1274 ] * muDoubleScalarSin ( rtB .
pgqpd5ik4w_cxarnvbvui [ 1274 ] ) ; for ( s258_iter = 0 ; s258_iter < 1275 ;
s258_iter ++ ) { rtB . pgqpd5ik4w_cxarnvbvui [ s258_iter ] =
muDoubleScalarCos ( rtB . pgqpd5ik4w_cxarnvbvui [ s258_iter ] ) ; } memcpy (
& rtB . dv1 [ 0 ] , & rtP . Constant1_Value_gp2wuzxkly [ 0 ] , 962U * sizeof
( real_T ) ) ; for ( s258_iter = 0 ; s258_iter < 277 ; s258_iter ++ ) { rtB .
dv1 [ s258_iter + 962 ] = g5pzqldhbn ; } for ( s258_iter = 0 ; s258_iter < 30
; s258_iter ++ ) { rtB . dv1 [ s258_iter + 1239 ] = k4q33fn5wp ; } for (
s258_iter = 0 ; s258_iter < 5 ; s258_iter ++ ) { rtB . dv1 [ s258_iter + 1269
] = fug530bbhx ; } rtB . dv1 [ 1274 ] = chxdtzje0j ; bpuwpgpm3m = - 0.0 ; for
( i = 0 ; i < 1275 ; i ++ ) { oltw25yayb = rtB . pgqpd5ik4w_cxarnvbvui [ i ]
* rtB . bixz4y4cs3 [ i ] * rtB . dv1 [ i ] ; jpewagwvqf_idx_0 = rtB .
m04ridjbke_kkiq3xxxve [ i ] + oltw25yayb ; bpuwpgpm3m += jpewagwvqf_idx_0 ;
rtB . pgqpd5ik4w_cxarnvbvui [ i ] = oltw25yayb ; rtB . m04ridjbke_kkiq3xxxve
[ i ] = jpewagwvqf_idx_0 ; } bpuwpgpm3m = ( fqhdbem00h + bpuwpgpm3m ) * rtP .
Gain4_Gain_kkmqinuqik * 0.017453292519943295 ; fqhdbem00h = rtP .
X0_Coefs_lglvj03zib [ 0 ] ; for ( s258_iter = 0 ; s258_iter < 5 ; s258_iter
++ ) { fqhdbem00h = fqhdbem00h * g5pzqldhbn + rtP . X0_Coefs_lglvj03zib [
s258_iter + 1 ] ; } k4q33fn5wp = g5pzqldhbn * g5pzqldhbn ; fug530bbhx =
k4q33fn5wp * g5pzqldhbn ; chxdtzje0j = fug530bbhx * g5pzqldhbn ; TRANS = 'N'
; M = 1600LL ; N = 14LL ; oltw25yayb = 1.0 ; LDA = 1600LL ; INCX = 1LL ;
jpewagwvqf_idx_0 = 0.0 ; INCY = 1LL ; dgemv ( & TRANS , & M , & N , &
oltw25yayb , & rtB . gbmpokz3zp [ 0 ] , & LDA , & n32jw4rqz5 [ 0 ] , & INCX ,
& jpewagwvqf_idx_0 , & rtB . ooyuznughj_cl54gopm0x [ 0 ] , & INCY ) ; for ( i
= 0 ; i < 1306 ; i ++ ) { rtB . pcu42j55xs_mbvzarwird [ i ] = rtP .
Constant1_Value_jvyjyvnzqm [ i ] * rtB . kyoy4xdfin [ i ] * muDoubleScalarSin
( rtB . ooyuznughj_cl54gopm0x [ i ] ) ; } for ( i = 0 ; i < 253 ; i ++ ) {
rtB . pcu42j55xs_mbvzarwird [ i + 1306 ] = rtB . kyoy4xdfin [ i + 1306 ] *
g5pzqldhbn * muDoubleScalarSin ( rtB . ooyuznughj_cl54gopm0x [ i + 1306 ] ) ;
} for ( i = 0 ; i < 36 ; i ++ ) { rtB . pcu42j55xs_mbvzarwird [ i + 1559 ] =
rtB . kyoy4xdfin [ i + 1559 ] * k4q33fn5wp * muDoubleScalarSin ( rtB .
ooyuznughj_cl54gopm0x [ i + 1559 ] ) ; } rtB . pcu42j55xs_mbvzarwird [ 1595 ]
= fug530bbhx * rtB . kyoy4xdfin [ 1595 ] * muDoubleScalarSin ( rtB .
ooyuznughj_cl54gopm0x [ 1595 ] ) ; rtB . pcu42j55xs_mbvzarwird [ 1596 ] =
fug530bbhx * rtB . kyoy4xdfin [ 1596 ] * muDoubleScalarSin ( rtB .
ooyuznughj_cl54gopm0x [ 1596 ] ) ; rtB . pcu42j55xs_mbvzarwird [ 1597 ] =
fug530bbhx * rtB . kyoy4xdfin [ 1597 ] * muDoubleScalarSin ( rtB .
ooyuznughj_cl54gopm0x [ 1597 ] ) ; rtB . pcu42j55xs_mbvzarwird [ 1598 ] =
fug530bbhx * rtB . kyoy4xdfin [ 1598 ] * muDoubleScalarSin ( rtB .
ooyuznughj_cl54gopm0x [ 1598 ] ) ; rtB . pcu42j55xs_mbvzarwird [ 1599 ] =
chxdtzje0j * rtB . kyoy4xdfin [ 1599 ] * muDoubleScalarSin ( rtB .
ooyuznughj_cl54gopm0x [ 1599 ] ) ; for ( s258_iter = 0 ; s258_iter < 1600 ;
s258_iter ++ ) { rtB . ooyuznughj_cl54gopm0x [ s258_iter ] =
muDoubleScalarCos ( rtB . ooyuznughj_cl54gopm0x [ s258_iter ] ) ; } memcpy (
& rtB . dv [ 0 ] , & rtP . Constant1_Value_jvyjyvnzqm [ 0 ] , 1306U * sizeof
( real_T ) ) ; for ( s258_iter = 0 ; s258_iter < 253 ; s258_iter ++ ) { rtB .
dv [ s258_iter + 1306 ] = g5pzqldhbn ; } for ( s258_iter = 0 ; s258_iter < 36
; s258_iter ++ ) { rtB . dv [ s258_iter + 1559 ] = k4q33fn5wp ; } rtB . dv [
1595 ] = fug530bbhx ; rtB . dv [ 1596 ] = fug530bbhx ; rtB . dv [ 1597 ] =
fug530bbhx ; rtB . dv [ 1598 ] = fug530bbhx ; rtB . dv [ 1599 ] = chxdtzje0j
; ohohv0ef3n = - 0.0 ; for ( i = 0 ; i < 1600 ; i ++ ) { oltw25yayb = rtB .
ooyuznughj_cl54gopm0x [ i ] * rtB . ou1vh1l3du [ i ] * rtB . dv [ i ] ;
jpewagwvqf_idx_0 = rtB . pcu42j55xs_mbvzarwird [ i ] + oltw25yayb ;
ohohv0ef3n += jpewagwvqf_idx_0 ; rtB . ooyuznughj_cl54gopm0x [ i ] =
oltw25yayb ; rtB . pcu42j55xs_mbvzarwird [ i ] = jpewagwvqf_idx_0 ; }
ohohv0ef3n = ( fqhdbem00h + ohohv0ef3n ) * rtP . Gain3_Gain_dyx0cwehu4 *
0.017453292519943295 ; fqhdbem00h = muDoubleScalarAtan2 ( bpuwpgpm3m ,
ohohv0ef3n ) ; k4q33fn5wp = ohohv0ef3n * ohohv0ef3n + bpuwpgpm3m * bpuwpgpm3m
; fug530bbhx = rtP . S0_Coefs_bgrvsqinkr [ 0 ] ; chxdtzje0j = g5pzqldhbn *
g5pzqldhbn ; i2lmhfpmzi = chxdtzje0j * g5pzqldhbn ; jpewagwvqf_idx_2 =
i2lmhfpmzi * g5pzqldhbn ; TRANS = 'N' ; M = 66LL ; N = 8LL ; oltw25yayb = 1.0
; LDA = 66LL ; for ( s258_iter = 0 ; s258_iter < 5 ; s258_iter ++ ) {
fug530bbhx = fug530bbhx * g5pzqldhbn + rtP . S0_Coefs_bgrvsqinkr [ s258_iter
+ 1 ] ; ijs1lor1qv [ s258_iter ] = n32jw4rqz5 [ s258_iter ] ; } ijs1lor1qv [
5 ] = n32jw4rqz5 [ 6 ] ; ijs1lor1qv [ 6 ] = n32jw4rqz5 [ 7 ] ; ijs1lor1qv [ 7
] = n32jw4rqz5 [ 13 ] ; INCX = 1LL ; jpewagwvqf_idx_0 = 0.0 ; INCY = 1LL ;
dgemv ( & TRANS , & M , & N , & oltw25yayb , & rtB . gkar21mdwf [ 0 ] , & LDA
, & ijs1lor1qv [ 0 ] , & INCX , & jpewagwvqf_idx_0 , & kiruj5xuq5 [ 0 ] , &
INCY ) ; for ( i = 0 ; i < 33 ; i ++ ) { f4ne12mlzi [ i ] = rtP .
Constant1_Value_kyneefazaj [ i ] * rtB . lu33o4w1r3 [ i ] * muDoubleScalarSin
( kiruj5xuq5 [ i ] ) ; } f4ne12mlzi [ 33 ] = g5pzqldhbn * rtB . lu33o4w1r3 [
33 ] * muDoubleScalarSin ( kiruj5xuq5 [ 33 ] ) ; f4ne12mlzi [ 34 ] =
g5pzqldhbn * rtB . lu33o4w1r3 [ 34 ] * muDoubleScalarSin ( kiruj5xuq5 [ 34 ]
) ; f4ne12mlzi [ 35 ] = g5pzqldhbn * rtB . lu33o4w1r3 [ 35 ] *
muDoubleScalarSin ( kiruj5xuq5 [ 35 ] ) ; for ( i = 0 ; i < 25 ; i ++ ) {
f4ne12mlzi [ i + 36 ] = rtB . lu33o4w1r3 [ i + 36 ] * chxdtzje0j *
muDoubleScalarSin ( kiruj5xuq5 [ i + 36 ] ) ; } f4ne12mlzi [ 61 ] =
i2lmhfpmzi * rtB . lu33o4w1r3 [ 61 ] * muDoubleScalarSin ( kiruj5xuq5 [ 61 ]
) ; f4ne12mlzi [ 62 ] = i2lmhfpmzi * rtB . lu33o4w1r3 [ 62 ] *
muDoubleScalarSin ( kiruj5xuq5 [ 62 ] ) ; f4ne12mlzi [ 63 ] = i2lmhfpmzi *
rtB . lu33o4w1r3 [ 63 ] * muDoubleScalarSin ( kiruj5xuq5 [ 63 ] ) ;
f4ne12mlzi [ 64 ] = i2lmhfpmzi * rtB . lu33o4w1r3 [ 64 ] * muDoubleScalarSin
( kiruj5xuq5 [ 64 ] ) ; f4ne12mlzi [ 65 ] = jpewagwvqf_idx_2 * rtB .
lu33o4w1r3 [ 65 ] * muDoubleScalarSin ( kiruj5xuq5 [ 65 ] ) ; for ( s258_iter
= 0 ; s258_iter < 66 ; s258_iter ++ ) { kiruj5xuq5 [ s258_iter ] =
muDoubleScalarCos ( kiruj5xuq5 [ s258_iter ] ) ; } memcpy ( & tmp [ 0 ] , &
rtP . Constant1_Value_kyneefazaj [ 0 ] , 33U * sizeof ( real_T ) ) ; tmp [ 33
] = g5pzqldhbn ; tmp [ 34 ] = g5pzqldhbn ; tmp [ 35 ] = g5pzqldhbn ; for (
s258_iter = 0 ; s258_iter < 25 ; s258_iter ++ ) { tmp [ s258_iter + 36 ] =
chxdtzje0j ; } tmp [ 61 ] = i2lmhfpmzi ; tmp [ 62 ] = i2lmhfpmzi ; tmp [ 63 ]
= i2lmhfpmzi ; tmp [ 64 ] = i2lmhfpmzi ; tmp [ 65 ] = jpewagwvqf_idx_2 ;
chxdtzje0j = - 0.0 ; for ( i = 0 ; i < 66 ; i ++ ) { oltw25yayb = kiruj5xuq5
[ i ] * rtB . drh3kx0c2g [ i ] * tmp [ i ] ; jpewagwvqf_idx_0 = f4ne12mlzi [
i ] + oltw25yayb ; chxdtzje0j += jpewagwvqf_idx_0 ; kiruj5xuq5 [ i ] =
oltw25yayb ; f4ne12mlzi [ i ] = jpewagwvqf_idx_0 ; } muDoubleScalarSinCos (
fqhdbem00h , & jpewagwvqf_idx_0 , & pz1213rdrt [ 0 ] ) ; muDoubleScalarSinCos
( muDoubleScalarAtan ( muDoubleScalarSqrt ( k4q33fn5wp / ( rtP .
Constant_Value_njviyc3nu4 - k4q33fn5wp ) ) ) , & oltw25yayb , & pz1213rdrt [
1 ] ) ; muDoubleScalarSinCos ( rtP . Gain1_Gain_o2ge0niozb * ( (
0.017453292519943295 * ( rtP . Gain2_Gain_gxogzjcxes * ( fug530bbhx +
chxdtzje0j ) ) - rtP . Gain5_Gain_m32aql5ryf * ( bpuwpgpm3m * ohohv0ef3n ) )
+ fqhdbem00h ) , & acweymdfsj , & pz1213rdrt [ 2 ] ) ; jxl2iyicpw [ 0 ] =
pz1213rdrt [ 0 ] * pz1213rdrt [ 2 ] * pz1213rdrt [ 1 ] - jpewagwvqf_idx_0 *
acweymdfsj ; jxl2iyicpw [ 1 ] = - pz1213rdrt [ 0 ] * pz1213rdrt [ 1 ] *
acweymdfsj - jpewagwvqf_idx_0 * pz1213rdrt [ 2 ] ; jxl2iyicpw [ 2 ] =
pz1213rdrt [ 0 ] * oltw25yayb ; jxl2iyicpw [ 3 ] = jpewagwvqf_idx_0 *
pz1213rdrt [ 2 ] * pz1213rdrt [ 1 ] + pz1213rdrt [ 0 ] * acweymdfsj ;
jxl2iyicpw [ 4 ] = - jpewagwvqf_idx_0 * pz1213rdrt [ 1 ] * acweymdfsj +
pz1213rdrt [ 0 ] * pz1213rdrt [ 2 ] ; jxl2iyicpw [ 5 ] = jpewagwvqf_idx_0 *
oltw25yayb ; jxl2iyicpw [ 6 ] = - oltw25yayb * pz1213rdrt [ 2 ] ; jxl2iyicpw
[ 7 ] = oltw25yayb * acweymdfsj ; jxl2iyicpw [ 8 ] = pz1213rdrt [ 1 ] ; for (
s258_iter = 0 ; s258_iter < 3 ; s258_iter ++ ) { for ( i = 0 ; i < 3 ; i ++ )
{ j5wb5jlzhj [ i + 3 * s258_iter ] = 0.0 ; j5wb5jlzhj [ i + 3 * s258_iter ]
+= jxl2iyicpw [ 3 * s258_iter ] * f1iitcpwuk [ i ] ; j5wb5jlzhj [ i + 3 *
s258_iter ] += jxl2iyicpw [ 3 * s258_iter + 1 ] * f1iitcpwuk [ i + 3 ] ;
j5wb5jlzhj [ i + 3 * s258_iter ] += jxl2iyicpw [ 3 * s258_iter + 2 ] *
f1iitcpwuk [ i + 6 ] ; } } for ( s258_iter = 0 ; s258_iter < 3 ; s258_iter ++
) { rtB . dglspl4jb5 [ s258_iter ] = 0.0 ; for ( i = 0 ; i < 3 ; i ++ ) {
f1iitcpwuk [ s258_iter + 3 * i ] = 0.0 ; f1iitcpwuk [ s258_iter + 3 * i ] +=
j5wb5jlzhj [ 3 * i ] * lah2koeql2 [ s258_iter ] ; f1iitcpwuk [ s258_iter + 3
* i ] += j5wb5jlzhj [ 3 * i + 1 ] * lah2koeql2 [ s258_iter + 3 ] ; f1iitcpwuk
[ s258_iter + 3 * i ] += j5wb5jlzhj [ 3 * i + 2 ] * lah2koeql2 [ s258_iter +
6 ] ; rtB . dglspl4jb5 [ s258_iter ] += f1iitcpwuk [ 3 * i + s258_iter ] *
rtB . lgajxwyfuf [ i ] ; } } rtB . hzrrfqxhaf = muDoubleScalarSqrt ( rtB .
dglspl4jb5 [ 0 ] * rtB . dglspl4jb5 [ 0 ] + rtB . dglspl4jb5 [ 1 ] * rtB .
dglspl4jb5 [ 1 ] ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { fbciyjdijr ( rtB
. hzrrfqxhaf , rtB . dglspl4jb5 [ 2 ] , rtB . dyisgf03lw , rtB . exuyfpbwx3 ,
rtB . iz3tczqrpq , rtB . fzk34rhf1c , & rtB . kaatsalz40 , & rtDW .
kaatsalz40 , & rtP . kaatsalz40 ) ; rtB . kcdpzzkbmw = rtDW . pttppk3jcp ; }
k4q33fn5wp = 57.295779513082323 * rtB . kaatsalz40 . injnyz4auw ; acweymdfsj
= 57.295779513082323 * muDoubleScalarAtan2 ( rtB . dglspl4jb5 [ 1 ] , rtB .
dglspl4jb5 [ 0 ] ) ; rtB . ewdeweoohc = rtP . Gain_Gain_b3c3odkt2h * rtB .
harzibozpz + rtB . igqwt1yjrx ; rtB . hllg2hyyik = rtB . ewdeweoohc - rtP .
epoch_Value ; rtB . lbv4bsnkdm = ( rtB . ewdeweoohc != rtB . kcdpzzkbmw ) ;
if ( acweymdfsj > rtP . u80deg_UpperSat ) { rtB . b22cbxmnlr = rtP .
u80deg_UpperSat ; } else if ( acweymdfsj < rtP . u80deg_LowerSat ) { rtB .
b22cbxmnlr = rtP . u80deg_LowerSat ; } else { rtB . b22cbxmnlr = acweymdfsj ;
} if ( k4q33fn5wp > rtP . u0deg_UpperSat ) { rtB . jo115loilo = rtP .
u0deg_UpperSat ; } else if ( k4q33fn5wp < rtP . u0deg_LowerSat ) { rtB .
jo115loilo = rtP . u0deg_LowerSat ; } else { rtB . jo115loilo = k4q33fn5wp ;
} muDoubleScalarSinCos ( 0.017453292519943295 * rtB . b22cbxmnlr , & rtB .
d1ba11mu0x [ 0 ] , & rtB . akmdakueie [ 0 ] ) ; muDoubleScalarSinCos (
0.017453292519943295 * rtB . jo115loilo , & rtB . d1ba11mu0x [ 1 ] , & rtB .
akmdakueie [ 1 ] ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . jcvum1cgbh
= rtDW . ay1crq4gjz ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtB .
b22cbxmnlr != rtB . jcvum1cgbh ) { if ( ! rtDW . mdd3waf5u2 ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . mdd3waf5u2 =
true ; } } else { if ( rtDW . mdd3waf5u2 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . mdd3waf5u2 =
false ; } } } } if ( rtDW . mdd3waf5u2 ) { rtB . oksalupnd3 = rtB .
d1ba11mu0x [ 0 ] ; rtB . kjpznrcgig = rtB . akmdakueie [ 0 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { for ( s307_iter = 1 ; s307_iter <= rtP .
ForIterator_IterationLimit ; s307_iter ++ ) { if ( s307_iter > rtP .
cpm1spm1_Threshold ) { fsyqxyxc3v_idx_0 = rtDW . jbiuzi4aai [ 0 ] ;
ihoigetibq_idx_0 = rtDW . jbiuzi4aai [ 1 ] ; } else { fsyqxyxc3v_idx_0 = rtB
. kjpznrcgig ; ihoigetibq_idx_0 = rtB . oksalupnd3 ; } chxdtzje0j =
fsyqxyxc3v_idx_0 * rtB . oksalupnd3 + ihoigetibq_idx_0 * rtB . kjpznrcgig ;
ohohv0ef3n = fsyqxyxc3v_idx_0 * rtB . kjpznrcgig - ihoigetibq_idx_0 * rtB .
oksalupnd3 ; if ( s307_iter == 1 ) { memcpy ( & e4gptqqsf3 [ 0 ] , & rtP .
Constant_Value_ehjzuhujix [ 0 ] , 11U * sizeof ( real_T ) ) ; memcpy ( &
fl4bb5kzfk [ 0 ] , & rtP . Constant1_Value_ailex5mif3 [ 0 ] , 11U * sizeof (
real_T ) ) ; } e4gptqqsf3 [ s307_iter - 1 ] = chxdtzje0j ; fl4bb5kzfk [
s307_iter - 1 ] = ohohv0ef3n ; rtDW . jbiuzi4aai [ 0 ] = ohohv0ef3n ; rtDW .
jbiuzi4aai [ 1 ] = chxdtzje0j ; } for ( i = 0 ; i < 11 ; i ++ ) { rtB .
f1xf35jyp4 [ i ] = rtP . Gain_Gain_oyuexaslet * fl4bb5kzfk [ i ] ; rtB .
hi1n54mcmc [ i ] = rtP . Gain1_Gain_bckqcimlak * e4gptqqsf3 [ i ] ; } } rtB .
p3gpuz1pzd [ 0 ] = rtP . cp1_Value ; rtB . p3gpuz1pzd [ 1 ] = rtB .
kjpznrcgig ; rtB . lqzgmigds5 [ 0 ] = rtP . sp1_Value ; rtB . lqzgmigds5 [ 1
] = rtB . oksalupnd3 ; memcpy ( & rtB . p3gpuz1pzd [ 2 ] , & rtB . f1xf35jyp4
[ 0 ] , 11U * sizeof ( real_T ) ) ; memcpy ( & rtB . lqzgmigds5 [ 2 ] , & rtB
. hi1n54mcmc [ 0 ] , 11U * sizeof ( real_T ) ) ; if ( ssIsMajorTimeStep ( rtS
) ) { srUpdateBC ( rtDW . dpoz2afmu5 ) ; } } if ( ssIsSampleHit ( rtS , 1 , 0
) ) { rtB . kzqylxrze2 = rtDW . cws51k2ewn ; muDoubleScalarSinCos ( rtB .
kaatsalz40 . injnyz4auw , & rtB . fq0qegja2w , & rtB . fouuflhqmj ) ;
fug530bbhx = rtB . fq0qegja2w * rtB . iz3tczqrpq ; rtB . i3roi2pfwn = rtP .
Constant1_Value_d2dwd3eskx / muDoubleScalarSqrt ( rtP . f_Value_d44rnukv0h -
fug530bbhx * rtB . fq0qegja2w ) ; rtB . arhxt0urom = fug530bbhx * rtB .
i3roi2pfwn ; } fug530bbhx = ( ( rtB . dglspl4jb5 [ 2 ] + rtB . arhxt0urom ) *
rtB . fq0qegja2w - rtB . i3roi2pfwn ) + rtB . fouuflhqmj * rtB . hzrrfqxhaf ;
if ( fug530bbhx > rtP . uto1000000m_UpperSat ) { i2lmhfpmzi = rtP .
uto1000000m_UpperSat ; } else if ( fug530bbhx < rtP . uto1000000m_LowerSat )
{ i2lmhfpmzi = rtP . uto1000000m_LowerSat ; } else { i2lmhfpmzi = fug530bbhx
; } rtB . lvq4s5cl0c = rtP . Gain_Gain_fazk34pq1p * i2lmhfpmzi ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . ceowdboxhi = rtDW . d4vvv2k2v3 ; }
rtB . czqjnchcew = ( ( rtB . jo115loilo != rtB . kzqylxrze2 ) || ( rtB .
lvq4s5cl0c != rtB . ceowdboxhi ) ) ; i2lmhfpmzi = rtB . d1ba11mu0x [ 1 ] *
rtB . d1ba11mu0x [ 1 ] ; fqhdbem00h = rtB . akmdakueie [ 1 ] * rtB .
akmdakueie [ 1 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) && ssIsMajorTimeStep (
rtS ) ) { if ( rtB . czqjnchcew ) { if ( ! rtDW . hgodhfyuxy ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . hgodhfyuxy =
true ; } } else { if ( rtDW . hgodhfyuxy ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . hgodhfyuxy =
false ; } } } if ( rtDW . hgodhfyuxy ) { ohohv0ef3n = muDoubleScalarSqrt (
rtB . ntw01syjjc - i2lmhfpmzi * rtB . a3gezjtvdu ) ; chxdtzje0j = ohohv0ef3n
* rtB . lvq4s5cl0c ; oltw25yayb = muDoubleScalarSqrt ( fqhdbem00h * rtB .
ntw01syjjc + rtB . oech2kz1cy * i2lmhfpmzi ) ; rtB . iqc2f25oqb =
muDoubleScalarSqrt ( ( rtB . fpa3tundiw - rtB . d0kea0dkjy * i2lmhfpmzi ) / (
ohohv0ef3n * ohohv0ef3n ) + ( rtP . Gain_Gain_ng3bwimtlt * chxdtzje0j + rtB .
lvq4s5cl0c * rtB . lvq4s5cl0c ) ) ; rtB . fqya1lnkpm = ( rtB . lvq4s5cl0c +
oltw25yayb ) / rtB . iqc2f25oqb ; ohohv0ef3n = rtB . ntw01syjjc + chxdtzje0j
; chxdtzje0j += rtB . oech2kz1cy ; rtB . kwlbg5jb4t = rtB . d1ba11mu0x [ 1 ]
/ muDoubleScalarSqrt ( ohohv0ef3n * ohohv0ef3n / ( chxdtzje0j * chxdtzje0j )
* fqhdbem00h + i2lmhfpmzi ) ; rtB . b0zlh5u3jc = rtB . evxijl2a3r / ( rtB .
iqc2f25oqb * oltw25yayb ) * rtB . akmdakueie [ 1 ] * rtB . d1ba11mu0x [ 1 ] ;
rtB . d2klb5ahil = muDoubleScalarSqrt ( rtP . Constant_Value_kgwutvsm35 - rtB
. kwlbg5jb4t * rtB . kwlbg5jb4t ) ; if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . c4fmxjrfvq ) ; } } rtB . gekakniexb = rtP . re_Value /
rtB . iqc2f25oqb ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . ogsulvdfqo = rtP
. UnitDelay_InitialCondition_dcdbfk2ii1 ; rtDW . o1a1coezrh [ 0 ] = rtP .
UnitDelay2_InitialCondition_boysunw0mm [ 0 ] ; rtDW . o1a1coezrh [ 1 ] = rtP
. UnitDelay2_InitialCondition_boysunw0mm [ 1 ] ; rtDW . o1a1coezrh [ 2 ] =
rtP . UnitDelay2_InitialCondition_boysunw0mm [ 2 ] ; rtDW . o1a1coezrh [ 3 ]
= rtP . UnitDelay2_InitialCondition_boysunw0mm [ 3 ] ; for ( s258_iter = 1 ;
s258_iter <= rtP . ForIterator_IterationLimit_guhgs4an2s ; s258_iter ++ ) {
if ( s258_iter > rtP . arn_Threshold ) { fsyqxyxc3v_idx_0 = rtDW . ogsulvdfqo
; } else { fsyqxyxc3v_idx_0 = rtB . gekakniexb * rtB . gekakniexb ; }
i2lmhfpmzi = fsyqxyxc3v_idx_0 * rtB . gekakniexb ; tmp_p = ( int64_T )
s258_iter + rtP . Constant_Value_af3lptv0f0 ; if ( tmp_p > 2147483647LL ) {
tmp_p = 2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } s307_iter = ( int32_T ) tmp_p ;
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . oghbzylezs = rtP
. UnitDelay1_InitialCondition_fhyfwa2bo2 ; rtDW . l31233tzs5 = rtP .
UnitDelay3_InitialCondition ; rtDW . oe4craxtsr = rtP .
UnitDelay2_InitialCondition ; rtDW . p3utuwbotk = rtP .
UnitDelay4_InitialCondition ; for ( i = 0 ; i < 6 ; i ++ ) { rtDW .
bahf1mm04g [ i ] = 1U ; } if ( s307_iter > 2147483646 ) { s307_iter =
2147483646 ; } else { if ( s307_iter < 0 ) { s307_iter = 0 ; } } for ( idx1 =
1 ; idx1 <= s307_iter ; idx1 ++ ) { tmp_p = ( int64_T ) idx1 - rtP .
Constant_Value_lm1w3twn51 ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } idx2 = ( int32_T ) tmp_p ; ejitfv2qt3 = rtB . lbv4bsnkdm ;
if ( rtB . lbv4bsnkdm ) { tmp_p = ( int64_T ) idx2 + rtP .
Constant1_Value_najrv2muau ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } j = ( int32_T ) tmp_p - 1 ; tmp_p = ( int64_T ) s258_iter
+ rtP . Constant_Value_arjprafmwa ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } i = ( int32_T ) tmp_p - 1 ; if ( rtDW . bahf1mm04g [ 4 ] <
2 ) { rtDW . bahf1mm04g [ 4 ] = 2U ; memcpy ( & rtB . mffykklb4e [ 0 ] , &
rtDW . m35wdbwfjk [ 0 ] , 169U * sizeof ( real_T ) ) ; } rtB . mffykklb4e [ j
+ 13 * i ] = rtP . cdmaxdefmaxdef_Value [ 13 * i + j ] * rtB . hllg2hyyik +
rtP . cmaxdefmaxdef_Value [ 13 * i + j ] ; if ( s258_iter > rtP .
tc_old_Threshold ) { memcpy ( & px5y01giei [ 0 ] , & rtDW . adfw0bsjev [ 0 ]
, 169U * sizeof ( real_T ) ) ; } else { memcpy ( & px5y01giei [ 0 ] , & rtP .
zerosmaxdef1maxdef1_Value [ 0 ] , 169U * sizeof ( real_T ) ) ; } if ( idx2 !=
0 ) { tmp_p = ( int64_T ) s258_iter + rtP . Constant_Value_eqqxeofgkc ; if (
tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if ( tmp_p < -
2147483648LL ) { tmp_p = - 2147483648LL ; } } j = ( int32_T ) tmp_p - 1 ; if
( rtDW . bahf1mm04g [ 5 ] < 2 ) { rtDW . bahf1mm04g [ 5 ] = 2U ; memcpy ( &
rtB . l5zqckp5ds [ 0 ] , & px5y01giei [ 0 ] , 169U * sizeof ( real_T ) ) ; }
rtB . l5zqckp5ds [ j + 13 * ( idx2 - 1 ) ] = rtP . cdmaxdefmaxdef_Value [ (
idx2 - 1 ) * 13 + j ] * rtB . hllg2hyyik + rtP . cmaxdefmaxdef_Value [ ( idx2
- 1 ) * 13 + j ] ; for ( i = 0 ; i < 169 ; i ++ ) { rtB . mkz3mctiwo [ i ] =
rtP . Gain_Gain_hcwuq2xoge * rtB . l5zqckp5ds [ i ] ; } rtDW . l4idmhenv4 = 4
; } else { memcpy ( & rtB . mkz3mctiwo [ 0 ] , & px5y01giei [ 0 ] , 169U *
sizeof ( real_T ) ) ; rtDW . dgmhfl0ejy = 4 ; } for ( i = 0 ; i < 169 ; i ++
) { rtB . pr4mmdkig3 [ i ] = rtB . mffykklb4e [ i ] + rtB . mkz3mctiwo [ i ]
; } rtDW . bjrkfcnwqe = 4 ; } fqhdbem00h = ( real_T ) idx2 + rtP .
Constant1_Value_najvdqclxi ; if ( idx2 == 0 ) { fsyqxyxc3v_idx_0 = ( real_T )
s258_iter + rtP . Constant_Value_orx13y04uz ; oltw25yayb = rtB . pr4mmdkig3 [
( ( ( int32_T ) fsyqxyxc3v_idx_0 - 1 ) * 13 + ( int32_T ) rtP .
Constant_Value_orx13y04uz ) - 1 ] * rtB . lqzgmigds5 [ ( int32_T ) fqhdbem00h
- 1 ] ; fqhdbem00h = rtB . pr4mmdkig3 [ ( ( ( int32_T ) fsyqxyxc3v_idx_0 - 1
) * 13 + ( int32_T ) rtP . Constant_Value_orx13y04uz ) - 1 ] * rtB .
p3gpuz1pzd [ ( int32_T ) fqhdbem00h - 1 ] * rtP . Gain1_Gain_lsmxz1cifj ;
oltw25yayb *= rtP . Gain2_Gain ; rtDW . onw1kj0tt3 = 4 ; } else { chxdtzje0j
= ( real_T ) s258_iter + rtP . Constant_Value_k3qkpci4uw ; oltw25yayb = (
real_T ) idx2 + rtP . Constant_Value_k3qkpci4uw ; fsyqxyxc3v_idx_0 = rtB .
pr4mmdkig3 [ ( ( ( int32_T ) chxdtzje0j - 1 ) * 13 + ( int32_T ) oltw25yayb )
- 1 ] * rtB . p3gpuz1pzd [ ( int32_T ) fqhdbem00h - 1 ] ; ihoigetibq_idx_0 =
rtB . pr4mmdkig3 [ ( ( ( int32_T ) chxdtzje0j - 1 ) * 13 + ( int32_T )
oltw25yayb ) - 1 ] * rtB . lqzgmigds5 [ ( int32_T ) fqhdbem00h - 1 ] ;
oltw25yayb = ( real_T ) s258_iter + rtP . Constant_Value_ky3cjgnuis ;
chxdtzje0j = rtB . pr4mmdkig3 [ ( ( idx2 - 1 ) * 13 + ( int32_T ) oltw25yayb
) - 1 ] * rtB . p3gpuz1pzd [ ( int32_T ) fqhdbem00h - 1 ] ; fqhdbem00h = rtB
. pr4mmdkig3 [ ( ( idx2 - 1 ) * 13 + ( int32_T ) oltw25yayb ) - 1 ] * rtB .
lqzgmigds5 [ ( int32_T ) fqhdbem00h - 1 ] + fsyqxyxc3v_idx_0 ; oltw25yayb =
ihoigetibq_idx_0 - chxdtzje0j ; rtDW . ouyhtippx4 = 4 ; } jbpxsrqdbv = rtB .
czqjnchcew ; if ( rtB . czqjnchcew ) { if ( s258_iter == idx2 ) { tmp_p = (
int64_T ) idx2 - rtP . Constant_Value_aqysgafcrf ; if ( tmp_p > 2147483647LL
) { tmp_p = 2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } tmp_p = ( int64_T ) rtP . Gain_Gain_kqxmnucevh * ( int32_T
) tmp_p ; if ( tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if (
tmp_p < - 2147483648LL ) { tmp_p = - 2147483648LL ; } } tmp_p = ( int64_T )
s258_iter + ( int32_T ) tmp_p ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } rtB . kvglegmnr2 = rtDW . bwjkpamfxw [ ( int32_T ) tmp_p -
1 ] * rtB . d2klb5ahil ; tmp_p = ( int64_T ) idx2 - rtP .
Constant_Value_aqysgafcrf ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } tmp_p = ( int64_T ) rtP . Gain_Gain_kqxmnucevh * ( int32_T
) tmp_p ; if ( tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if (
tmp_p < - 2147483648LL ) { tmp_p = - 2147483648LL ; } } tmp_p = ( int64_T )
s258_iter + ( int32_T ) tmp_p ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } rtB . clqi5421sn = rtDW . bdtrovn01a [ ( ( s258_iter - 1 )
* 13 + idx2 ) - 1 ] * rtB . d2klb5ahil + rtDW . bwjkpamfxw [ ( int32_T )
tmp_p - 1 ] * rtB . kwlbg5jb4t ; rtDW . jub4qa0tx5 = 4 ; } else if ( (
s258_iter == 1 ) && ( idx2 == 0 ) ) { rtB . kvglegmnr2 = rtDW . bwjkpamfxw [
0 ] * rtB . kwlbg5jb4t ; tmp_p = rtP . Constant_Value_jcfcwioaqx ; if ( tmp_p
> 2147483647LL ) { tmp_p = 2147483647LL ; } else { if ( tmp_p < -
2147483648LL ) { tmp_p = - 2147483648LL ; } } rtB . clqi5421sn = rtDW .
bdtrovn01a [ ( int32_T ) tmp_p - 1 ] * rtB . kwlbg5jb4t - rtDW . bwjkpamfxw [
0 ] * rtB . d2klb5ahil ; rtDW . ehevun3t0d = 4 ; } else { if ( ( s258_iter >
1 ) && ( s258_iter != idx2 ) ) { tmp_p = ( int64_T ) s258_iter + rtP .
Constant_Value_basbfgiofe ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } i = ( int32_T ) tmp_p ; tmp_p = ( int64_T ) idx2 + rtP .
Constant_Value_basbfgiofe ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } eah1nufwt4_idx_1 = ( int32_T ) tmp_p ; tmp_p = ( int64_T )
rtP . Gain_Gain_byj5eqpbwj * idx2 ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } j = ( int32_T ) tmp_p ; tmp_p = ( int64_T ) idx2 + rtP .
Constant_Value_ouqub0qmct ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } tmp_m = ( int64_T ) idx2 + rtP . Constant_Value_ouqub0qmct
; if ( tmp_m > 2147483647LL ) { tmp_m = 2147483647LL ; } else { if ( tmp_m <
- 2147483648LL ) { tmp_m = - 2147483648LL ; } } tmp_i = ( int64_T ) s258_iter
- rtP . Constant1_Value_cpkffern4z ; if ( tmp_i > 2147483647LL ) { tmp_i =
2147483647LL ; } else { if ( tmp_i < - 2147483648LL ) { tmp_i = -
2147483648LL ; } } tmp_e = ( int64_T ) s258_iter - rtP .
Constant1_Value_fcslbbq5ce ; if ( tmp_e > 2147483647LL ) { tmp_e =
2147483647LL ; } else { if ( tmp_e < - 2147483648LL ) { tmp_e = -
2147483648LL ; } } if ( ( ( int32_T ) tmp_e >= idx2 ) > rtP .
Switch_Threshold ) { fsyqxyxc3v_idx_0 = rtDW . bdtrovn01a [ ( ( ( int32_T )
tmp_i - 1 ) * 13 + ( int32_T ) tmp_m ) - 1 ] ; } else { fsyqxyxc3v_idx_0 =
rtP . Constant_Value_lvn1oam4ik ; } tmp_m = ( int64_T ) s258_iter + j ; if (
tmp_m > 2147483647LL ) { tmp_m = 2147483647LL ; } else { if ( tmp_m < -
2147483648LL ) { tmp_m = - 2147483648LL ; } } rtB . clqi5421sn = ( rtDW .
bdtrovn01a [ ( ( s258_iter - 1 ) * 13 + ( int32_T ) tmp_p ) - 1 ] * rtB .
kwlbg5jb4t - rtDW . bwjkpamfxw [ ( int32_T ) tmp_m - 1 ] * rtB . d2klb5ahil )
- rtP . k1313_Value_ml2ak2adft [ ( ( i - 1 ) * 13 + eah1nufwt4_idx_1 ) - 1 ]
* fsyqxyxc3v_idx_0 ; tmp_p = ( int64_T ) s258_iter - rtP .
Constant1_Value_auw1c2xpx2 ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } if ( ( ( int32_T ) tmp_p >= idx2 ) > rtP .
Switch1_Threshold ) { tmp_p = ( int64_T ) s258_iter - rtP .
Constant1_Value_ex4jpy2wye ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } tmp_p = ( int64_T ) ( int32_T ) tmp_p + j ; if ( tmp_p >
2147483647LL ) { tmp_p = 2147483647LL ; } else { if ( tmp_p < - 2147483648LL
) { tmp_p = - 2147483648LL ; } } fsyqxyxc3v_idx_0 = rtDW . bwjkpamfxw [ (
int32_T ) tmp_p - 1 ] ; } else { fsyqxyxc3v_idx_0 = rtP .
Constant1_Value_gaa0eg0oa1 ; } tmp_p = ( int64_T ) s258_iter + j ; if ( tmp_p
> 2147483647LL ) { tmp_p = 2147483647LL ; } else { if ( tmp_p < -
2147483648LL ) { tmp_p = - 2147483648LL ; } } rtB . kvglegmnr2 = rtDW .
bwjkpamfxw [ ( int32_T ) tmp_p - 1 ] * rtB . kwlbg5jb4t - rtP .
k1313_Value_ml2ak2adft [ ( ( i - 1 ) * 13 + eah1nufwt4_idx_1 ) - 1 ] *
fsyqxyxc3v_idx_0 ; rtDW . hafmo2yjxp = 4 ; } } tmp_p = ( int64_T ) s258_iter
+ rtP . Constant_Value_khatmokwmu ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } i = ( int32_T ) tmp_p ; tmp_p = ( int64_T ) idx2 + rtP .
Constant_Value_khatmokwmu ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } eah1nufwt4_idx_1 = ( int32_T ) tmp_p ; if ( rtDW .
bahf1mm04g [ 2 ] < 2 ) { rtDW . bahf1mm04g [ 2 ] = 2U ; memcpy ( & rtB .
orlxict5uw [ 0 ] , & rtDW . bdtrovn01a [ 0 ] , 169U * sizeof ( real_T ) ) ; }
rtB . orlxict5uw [ ( eah1nufwt4_idx_1 + 13 * ( i - 1 ) ) - 1 ] = rtB .
clqi5421sn ; if ( rtDW . bahf1mm04g [ 3 ] < 2 ) { rtDW . bahf1mm04g [ 3 ] =
2U ; memcpy ( & rtB . n2aonouljp [ 0 ] , & rtDW . bwjkpamfxw [ 0 ] , 169U *
sizeof ( real_T ) ) ; } tmp_p = ( int64_T ) eah1nufwt4_idx_1 - rtP .
Constant_Value_ncpxwdetam ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } tmp_p = ( int64_T ) rtP . Gain_Gain_aaddldlmbp * ( int32_T
) tmp_p ; if ( tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if (
tmp_p < - 2147483648LL ) { tmp_p = - 2147483648LL ; } } rtB . n2aonouljp [ (
i + ( int32_T ) tmp_p ) - 1 ] = rtB . kvglegmnr2 ; rtDW . g1gz2kwalm = 4 ; }
tmp_p = ( int64_T ) s258_iter + rtP . Constant_Value_hi2pwwd3bg ; if ( tmp_p
> 2147483647LL ) { tmp_p = 2147483647LL ; } else { if ( tmp_p < -
2147483648LL ) { tmp_p = - 2147483648LL ; } } tmp_m = ( int64_T ) idx2 + rtP
. Constant_Value_hi2pwwd3bg ; if ( tmp_m > 2147483647LL ) { tmp_m =
2147483647LL ; } else { if ( tmp_m < - 2147483648LL ) { tmp_m = -
2147483648LL ; } } chxdtzje0j = rtB . orlxict5uw [ ( ( ( int32_T ) tmp_p - 1
) * 13 + ( int32_T ) tmp_m ) - 1 ] ; tmp_p = ( int64_T ) rtP .
Gain_Gain_amt1zrm0bg * idx2 ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } tmp_p = ( ( int64_T ) rtP . Constant_Value_cuqs0rinpz +
s258_iter ) + ( int32_T ) tmp_p ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } ohohv0ef3n = rtB . n2aonouljp [ ( int32_T ) tmp_p - 1 ] *
i2lmhfpmzi ; tmp_p = ( int64_T ) s258_iter + rtP . Constant1_Value_dihg20h40t
; if ( tmp_p > 2147483647LL ) { tmp_p = 2147483647LL ; } else { if ( tmp_p <
- 2147483648LL ) { tmp_p = - 2147483648LL ; } } tmp_m = ( int64_T ) idx2 +
rtP . Constant1_Value_dihg20h40t ; if ( tmp_m > 2147483647LL ) { tmp_m =
2147483647LL ; } else { if ( tmp_m < - 2147483648LL ) { tmp_m = -
2147483648LL ; } } bpuwpgpm3m = rtP . fm_Value [ ( int32_T ) tmp_m - 1 ] ;
g5pzqldhbn = rtP . fn_Value [ ( int32_T ) tmp_p - 1 ] ; if ( ( rtB .
d2klb5ahil == rtP . Constant1_Value_c13gpoqm0c ) && ( rtP .
Constant_Value_klmtx5qfsr == idx2 ) ) { if ( ! rtDW . gzzht5dcba ) { if (
ssGetTaskTime ( rtS , 1 ) != ssGetTStart ( rtS ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } rtDW . gzzht5dcba =
true ; } if ( s258_iter == 1 ) { if ( rtDW . bahf1mm04g [ 0 ] < 2 ) { rtDW .
bahf1mm04g [ 0 ] = 2U ; memcpy ( & rtB . mqbqw1xcbl [ 0 ] , & rtDW .
gwnmkcjbc1 [ 0 ] , 13U * sizeof ( real_T ) ) ; } rtB . mqbqw1xcbl [ ( int32_T
) ( rtP . Constant_Value_b1kt1dquk2 + 1.0 ) - 1 ] = rtDW . gwnmkcjbc1 [ 0 ] ;
rtDW . a3mffltq2c = 4 ; } else { tmp_p = ( int64_T ) s258_iter - rtP .
Constant1_Value_gvjahuuruw ; if ( tmp_p > 2147483647LL ) { tmp_p =
2147483647LL ; } else { if ( tmp_p < - 2147483648LL ) { tmp_p = -
2147483648LL ; } } tmp_m = ( int64_T ) s258_iter + rtP .
Constant_Value_n2ukulrcmg ; if ( tmp_m > 2147483647LL ) { tmp_m =
2147483647LL ; } else { if ( tmp_m < - 2147483648LL ) { tmp_m = -
2147483648LL ; } } tmp_i = ( int64_T ) idx2 + rtP . Constant_Value_n2ukulrcmg
; if ( tmp_i > 2147483647LL ) { tmp_i = 2147483647LL ; } else { if ( tmp_i <
- 2147483648LL ) { tmp_i = - 2147483648LL ; } } if ( rtDW . bahf1mm04g [ 1 ]
< 2 ) { rtDW . bahf1mm04g [ 1 ] = 2U ; memcpy ( & rtB . bxaxpwfsdh [ 0 ] , &
rtDW . gwnmkcjbc1 [ 0 ] , 13U * sizeof ( real_T ) ) ; } tmp_e = ( int64_T )
s258_iter + rtP . Constant_Value_cqtnx0odgv ; if ( tmp_e > 2147483647LL ) {
tmp_e = 2147483647LL ; } else { if ( tmp_e < - 2147483648LL ) { tmp_e = -
2147483648LL ; } } rtB . bxaxpwfsdh [ ( int32_T ) tmp_e - 1 ] = rtDW .
gwnmkcjbc1 [ s258_iter - 1 ] * rtB . kwlbg5jb4t - rtP . k1313_Value [ ( ( (
int32_T ) tmp_m - 1 ) * 13 + ( int32_T ) tmp_i ) - 1 ] * rtDW . gwnmkcjbc1 [
( int32_T ) tmp_p - 1 ] ; rtDW . fob5v3qelm = 4 ; } rtB . nrovnhknzx [ 0 ] =
rtDW . gwnmkcjbc1 [ 0 ] ; rtB . nrovnhknzx [ 1 ] = rtB . mqbqw1xcbl [ 1 ] ;
memcpy ( & rtB . nrovnhknzx [ 2 ] , & rtB . bxaxpwfsdh [ 2 ] , 11U * sizeof (
real_T ) ) ; rtB . dhcl5bwk3d = rtB . nrovnhknzx [ ( int32_T ) ( ( real_T )
s258_iter + rtP . Constant1_Value_a5v5gggqhg ) - 1 ] * i2lmhfpmzi * rtP .
Constant_Value_fmdk3ml4vv * oltw25yayb ; rtDW . bqkqmfirk2 = 4 ; } else { if
( rtDW . gzzht5dcba ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ;
rtB . dhcl5bwk3d = rtP . bpp_Y0 ; rtDW . gzzht5dcba = false ; } } rtB .
adgz4bd3kf = rtDW . oghbzylezs - fqhdbem00h * chxdtzje0j * i2lmhfpmzi ; rtB .
cig0wmtt3m = ohohv0ef3n * bpuwpgpm3m * oltw25yayb + rtDW . l31233tzs5 ; rtB .
o21kbr4mgl = ohohv0ef3n * g5pzqldhbn * fqhdbem00h + rtDW . oe4craxtsr ; rtB .
bmbl2eeqey = rtDW . p3utuwbotk + rtB . dhcl5bwk3d ; if ( ejitfv2qt3 ) {
memcpy ( & rtDW . m35wdbwfjk [ 0 ] , & rtB . mffykklb4e [ 0 ] , 169U * sizeof
( real_T ) ) ; memcpy ( & rtDW . adfw0bsjev [ 0 ] , & rtB . mkz3mctiwo [ 0 ]
, 169U * sizeof ( real_T ) ) ; } if ( jbpxsrqdbv ) { memcpy ( & rtDW .
bdtrovn01a [ 0 ] , & rtB . orlxict5uw [ 0 ] , 169U * sizeof ( real_T ) ) ;
memcpy ( & rtDW . bwjkpamfxw [ 0 ] , & rtB . n2aonouljp [ 0 ] , 169U * sizeof
( real_T ) ) ; } if ( rtDW . gzzht5dcba ) { memcpy ( & rtDW . gwnmkcjbc1 [ 0
] , & rtB . nrovnhknzx [ 0 ] , 13U * sizeof ( real_T ) ) ; } rtDW .
oghbzylezs = rtB . adgz4bd3kf ; rtDW . l31233tzs5 = rtB . cig0wmtt3m ; rtDW .
oe4craxtsr = rtB . o21kbr4mgl ; rtDW . p3utuwbotk = rtB . bmbl2eeqey ; rtDW .
ozdacijjrc = 4 ; } rtB . kvihuxhnbc [ 0 ] = rtDW . o1a1coezrh [ 0 ] + rtB .
adgz4bd3kf ; rtB . kvihuxhnbc [ 1 ] = rtDW . o1a1coezrh [ 1 ] + rtB .
cig0wmtt3m ; rtB . kvihuxhnbc [ 2 ] = rtDW . o1a1coezrh [ 2 ] + rtB .
o21kbr4mgl ; rtB . kvihuxhnbc [ 3 ] = rtDW . o1a1coezrh [ 3 ] + rtB .
bmbl2eeqey ; rtDW . ogsulvdfqo = i2lmhfpmzi ; rtDW . o1a1coezrh [ 0 ] = rtB .
kvihuxhnbc [ 0 ] ; rtDW . o1a1coezrh [ 1 ] = rtB . kvihuxhnbc [ 1 ] ; rtDW .
o1a1coezrh [ 2 ] = rtB . kvihuxhnbc [ 2 ] ; rtDW . o1a1coezrh [ 3 ] = rtB .
kvihuxhnbc [ 3 ] ; } } if ( rtB . d2klb5ahil != 0.0 ) { i2lmhfpmzi = rtB .
kvihuxhnbc [ 1 ] / rtB . d2klb5ahil ; } else { i2lmhfpmzi = rtB . kvihuxhnbc
[ 3 ] ; } fqhdbem00h = ( 0.0 - rtB . fqya1lnkpm * rtB . kvihuxhnbc [ 0 ] ) -
rtB . kvihuxhnbc [ 2 ] * rtB . b0zlh5u3jc ; oltw25yayb = rtB . b0zlh5u3jc *
rtB . kvihuxhnbc [ 0 ] - rtB . kvihuxhnbc [ 2 ] * rtB . fqya1lnkpm ;
chxdtzje0j = i2lmhfpmzi * i2lmhfpmzi + fqhdbem00h * fqhdbem00h ;
muDoubleScalarSinCos ( 0.017453292519943295 * ( 57.295779513082323 *
muDoubleScalarAtan2 ( i2lmhfpmzi , fqhdbem00h ) ) , & fsyqxyxc3v_idx_0 , &
ihoigetibq_idx_0 ) ; muDoubleScalarSinCos ( 0.017453292519943295 * (
57.295779513082323 * muDoubleScalarAtan2 ( oltw25yayb , muDoubleScalarSqrt (
chxdtzje0j ) ) ) , & fsyqxyxc3v_idx_1 , & ihoigetibq_idx_1 ) ; i2lmhfpmzi =
muDoubleScalarSqrt ( oltw25yayb * oltw25yayb + chxdtzje0j ) ; fqhdbem00h =
ihoigetibq_idx_1 * i2lmhfpmzi ; pz1213rdrt [ 0 ] = ihoigetibq_idx_0 *
fqhdbem00h * rtP . nTtoT_Gain ; pz1213rdrt [ 1 ] = fsyqxyxc3v_idx_0 *
fqhdbem00h * rtP . nTtoT_Gain ; pz1213rdrt [ 2 ] = fsyqxyxc3v_idx_1 *
i2lmhfpmzi * rtP . nTtoT_Gain ; fqhdbem00h = k4q33fn5wp ; nsbxylmapa ( &
fqhdbem00h ) ; oltw25yayb = k4q33fn5wp ; be4dle1kpx ( & oltw25yayb ) ;
chxdtzje0j = acweymdfsj ; nsbxylmapa ( & chxdtzje0j ) ; ohohv0ef3n =
acweymdfsj ; be4dle1kpx ( & ohohv0ef3n ) ; bpuwpgpm3m = fqhdbem00h * -
pz1213rdrt [ 2 ] - oltw25yayb * pz1213rdrt [ 0 ] ; p0wrq0nzpv [ 0 ] =
chxdtzje0j * bpuwpgpm3m - ohohv0ef3n * pz1213rdrt [ 1 ] ; p0wrq0nzpv [ 1 ] =
ohohv0ef3n * bpuwpgpm3m + chxdtzje0j * pz1213rdrt [ 1 ] ; p0wrq0nzpv [ 2 ] =
oltw25yayb * - pz1213rdrt [ 2 ] + fqhdbem00h * pz1213rdrt [ 0 ] ; esmxkiztnv
( rtB . arkzj205og . otpij24kr0 , p0wrq0nzpv , & rtB . b02oakwn4y ) ;
jkspr0rgyw [ 0 ] = rtB . noxmrm1w5fh . elfsvtngpi [ 1 ] * rtB . b02oakwn4y .
ihykyxkclc [ 2 ] - rtB . noxmrm1w5fh . elfsvtngpi [ 2 ] * rtB . b02oakwn4y .
ihykyxkclc [ 1 ] ; jkspr0rgyw [ 1 ] = rtB . noxmrm1w5fh . elfsvtngpi [ 2 ] *
rtB . b02oakwn4y . ihykyxkclc [ 0 ] - rtB . noxmrm1w5fh . elfsvtngpi [ 0 ] *
rtB . b02oakwn4y . ihykyxkclc [ 2 ] ; jkspr0rgyw [ 2 ] = rtB . noxmrm1w5fh .
elfsvtngpi [ 0 ] * rtB . b02oakwn4y . ihykyxkclc [ 1 ] - rtB . noxmrm1w5fh .
elfsvtngpi [ 1 ] * rtB . b02oakwn4y . ihykyxkclc [ 0 ] ; esmxkiztnv ( rtB .
fy4zj3hhge . gaty2jlz2p , jkspr0rgyw , & rtB . f1ei3kfb3b ) ; fl3fthyqxf (
rtB . lj0sp02vlxl . fdh2hm3qwy , rtB . lgajxwyfuf , & rtB . fl3fthyqxfw ) ;
fqhdbem00h = muDoubleScalarSqrt ( ( rtB . fl3fthyqxfw . grgp0ja04k [ 0 ] *
rtB . fl3fthyqxfw . grgp0ja04k [ 0 ] + rtB . fl3fthyqxfw . grgp0ja04k [ 1 ] *
rtB . fl3fthyqxfw . grgp0ja04k [ 1 ] ) + rtB . fl3fthyqxfw . grgp0ja04k [ 2 ]
* rtB . fl3fthyqxfw . grgp0ja04k [ 2 ] ) ; pz1213rdrt [ 0 ] = rtB .
fl3fthyqxfw . grgp0ja04k [ 0 ] / fqhdbem00h ; pz1213rdrt [ 1 ] = rtB .
fl3fthyqxfw . grgp0ja04k [ 1 ] / fqhdbem00h ; pz1213rdrt [ 2 ] = rtB .
fl3fthyqxfw . grgp0ja04k [ 2 ] / fqhdbem00h ; fqhdbem00h = rtP .
CONSTANTS_par . mu_earth / muDoubleScalarPower ( fqhdbem00h , 3.0 ) * 3.0 ;
lah2koeql2 [ 0 ] = fqhdbem00h * 0.0 ; lah2koeql2 [ 3 ] = fqhdbem00h * -
pz1213rdrt [ 2 ] ; lah2koeql2 [ 6 ] = fqhdbem00h * pz1213rdrt [ 1 ] ;
lah2koeql2 [ 1 ] = fqhdbem00h * pz1213rdrt [ 2 ] ; lah2koeql2 [ 4 ] =
fqhdbem00h * 0.0 ; lah2koeql2 [ 7 ] = fqhdbem00h * - pz1213rdrt [ 0 ] ;
lah2koeql2 [ 2 ] = fqhdbem00h * - pz1213rdrt [ 1 ] ; lah2koeql2 [ 5 ] =
fqhdbem00h * pz1213rdrt [ 0 ] ; lah2koeql2 [ 8 ] = fqhdbem00h * 0.0 ; for (
s258_iter = 0 ; s258_iter < 3 ; s258_iter ++ ) { rtB . o3ah3cxi2g [ s258_iter
] = 0.0 ; for ( i = 0 ; i < 3 ; i ++ ) { j5wb5jlzhj [ s258_iter + 3 * i ] =
0.0 ; j5wb5jlzhj [ s258_iter + 3 * i ] += rtP . DYN_SC_par . inertia [ 3 * i
] * lah2koeql2 [ s258_iter ] ; j5wb5jlzhj [ s258_iter + 3 * i ] += rtP .
DYN_SC_par . inertia [ 3 * i + 1 ] * lah2koeql2 [ s258_iter + 3 ] ;
j5wb5jlzhj [ s258_iter + 3 * i ] += rtP . DYN_SC_par . inertia [ 3 * i + 2 ]
* lah2koeql2 [ s258_iter + 6 ] ; rtB . o3ah3cxi2g [ s258_iter ] += j5wb5jlzhj
[ 3 * i + s258_iter ] * pz1213rdrt [ i ] ; } } rtB . ets2sd1cpy [ 0 ] = ( rtB
. ajt3i13qwt [ 0 ] + rtB . f1ei3kfb3b . ihykyxkclc [ 0 ] ) + rtB . o3ah3cxi2g
[ 0 ] ; rtB . ets2sd1cpy [ 1 ] = ( rtB . ajt3i13qwt [ 1 ] + rtB . f1ei3kfb3b
. ihykyxkclc [ 1 ] ) + rtB . o3ah3cxi2g [ 1 ] ; rtB . ets2sd1cpy [ 2 ] = (
rtB . ajt3i13qwt [ 2 ] + rtB . f1ei3kfb3b . ihykyxkclc [ 2 ] ) + rtB .
o3ah3cxi2g [ 2 ] ; jpewagwvqf_idx_0 = rtB . lgajxwyfuf [ 1 ] * rtB .
dlialfoqve [ 2 ] - rtB . lgajxwyfuf [ 2 ] * rtB . dlialfoqve [ 1 ] ;
oltw25yayb = rtB . lgajxwyfuf [ 2 ] * rtB . dlialfoqve [ 0 ] - rtB .
lgajxwyfuf [ 0 ] * rtB . dlialfoqve [ 2 ] ; jpewagwvqf_idx_2 = rtB .
lgajxwyfuf [ 0 ] * rtB . dlialfoqve [ 1 ] - rtB . lgajxwyfuf [ 1 ] * rtB .
dlialfoqve [ 0 ] ; fqhdbem00h = 1.0 / ( muDoubleScalarSqrt ( (
jpewagwvqf_idx_0 * jpewagwvqf_idx_0 + oltw25yayb * oltw25yayb ) +
jpewagwvqf_idx_2 * jpewagwvqf_idx_2 ) + rtP . Normalization1_Bias ) ;
ftalipigpn [ 0 ] = jpewagwvqf_idx_0 * fqhdbem00h ; ftalipigpn [ 1 ] =
oltw25yayb * fqhdbem00h ; ftalipigpn [ 2 ] = jpewagwvqf_idx_2 * fqhdbem00h ;
fqhdbem00h = 1.0 / ( muDoubleScalarSqrt ( ( rtB . lgajxwyfuf [ 0 ] * rtB .
lgajxwyfuf [ 0 ] + rtB . lgajxwyfuf [ 1 ] * rtB . lgajxwyfuf [ 1 ] ) + rtB .
lgajxwyfuf [ 2 ] * rtB . lgajxwyfuf [ 2 ] ) + rtP . Normalization_Bias ) ;
jpewagwvqf_idx_0 = rtB . lgajxwyfuf [ 0 ] * fqhdbem00h ; oltw25yayb = rtB .
lgajxwyfuf [ 1 ] * fqhdbem00h ; jpewagwvqf_idx_2 = rtB . lgajxwyfuf [ 2 ] *
fqhdbem00h ; oc0abfogmk [ 0 ] = ftalipigpn [ 1 ] * jpewagwvqf_idx_2 -
ftalipigpn [ 2 ] * oltw25yayb ; oc0abfogmk [ 1 ] = ftalipigpn [ 0 ] ;
oc0abfogmk [ 2 ] = ftalipigpn [ 0 ] ; oc0abfogmk [ 3 ] = ftalipigpn [ 2 ] *
jpewagwvqf_idx_0 - ftalipigpn [ 0 ] * jpewagwvqf_idx_2 ; oc0abfogmk [ 4 ] =
ftalipigpn [ 1 ] ; oc0abfogmk [ 5 ] = ftalipigpn [ 1 ] ; oc0abfogmk [ 6 ] =
ftalipigpn [ 0 ] * oltw25yayb - ftalipigpn [ 1 ] * jpewagwvqf_idx_0 ;
oc0abfogmk [ 7 ] = ftalipigpn [ 2 ] ; oc0abfogmk [ 8 ] = ftalipigpn [ 2 ] ;
i41uiun02b ( oc0abfogmk , & rtB . i41uiun02b3 ) ; cc3vamisq4 ( rtB .
i41uiun02b3 . ny3pcenmal , & rtB . cc3vamisq4t ) ; ftalipigpn [ 0 ] = rtB .
cc3vamisq4t . gaty2jlz2p [ 1 ] ; ftalipigpn [ 1 ] = rtB . cc3vamisq4t .
gaty2jlz2p [ 2 ] ; ftalipigpn [ 2 ] = rtB . cc3vamisq4t . gaty2jlz2p [ 3 ] ;
jpewagwvqf_idx_2 = rtB . cc3vamisq4t . gaty2jlz2p [ 0 ] ; lah2koeql2 [ 0 ] =
0.0 ; lah2koeql2 [ 3 ] = - rtB . cc3vamisq4t . gaty2jlz2p [ 3 ] ; lah2koeql2
[ 6 ] = rtB . cc3vamisq4t . gaty2jlz2p [ 2 ] ; lah2koeql2 [ 1 ] = rtB .
cc3vamisq4t . gaty2jlz2p [ 3 ] ; lah2koeql2 [ 4 ] = 0.0 ; lah2koeql2 [ 7 ] =
- rtB . cc3vamisq4t . gaty2jlz2p [ 1 ] ; lah2koeql2 [ 2 ] = - rtB .
cc3vamisq4t . gaty2jlz2p [ 2 ] ; lah2koeql2 [ 5 ] = rtB . cc3vamisq4t .
gaty2jlz2p [ 1 ] ; lah2koeql2 [ 8 ] = 0.0 ; for ( s258_iter = 0 ; s258_iter <
3 ; s258_iter ++ ) { ltksehy2vp [ s258_iter ] = - ftalipigpn [ s258_iter ] ;
ltksehy2vp [ ( s258_iter + 1 ) << 2 ] = ( real_T ) b [ 3 * s258_iter ] *
jpewagwvqf_idx_2 - lah2koeql2 [ 3 * s258_iter ] ; ltksehy2vp [ ( ( s258_iter
+ 1 ) << 2 ) + 1 ] = ( real_T ) b [ 3 * s258_iter + 1 ] * jpewagwvqf_idx_2 -
lah2koeql2 [ 3 * s258_iter + 1 ] ; ltksehy2vp [ ( ( s258_iter + 1 ) << 2 ) +
2 ] = ( real_T ) b [ 3 * s258_iter + 2 ] * jpewagwvqf_idx_2 - lah2koeql2 [ 3
* s258_iter + 2 ] ; } ltksehy2vp [ 3 ] = rtB . cc3vamisq4t . gaty2jlz2p [ 0 ]
; ltksehy2vp [ 7 ] = rtB . cc3vamisq4t . gaty2jlz2p [ 1 ] ; ltksehy2vp [ 11 ]
= rtB . cc3vamisq4t . gaty2jlz2p [ 2 ] ; ltksehy2vp [ 15 ] = rtB .
cc3vamisq4t . gaty2jlz2p [ 3 ] ; for ( s258_iter = 0 ; s258_iter < 4 ;
s258_iter ++ ) { jpewagwvqf_idx_0 = ltksehy2vp [ s258_iter + 12 ] * rtB .
lj0sp02vlxl . fdh2hm3qwy [ 3 ] + ( ltksehy2vp [ s258_iter + 8 ] * rtB .
lj0sp02vlxl . fdh2hm3qwy [ 2 ] + ( ltksehy2vp [ s258_iter + 4 ] * rtB .
lj0sp02vlxl . fdh2hm3qwy [ 1 ] + ltksehy2vp [ s258_iter ] * rtB . lj0sp02vlxl
. fdh2hm3qwy [ 0 ] ) ) ; m2ldz44rx4 [ s258_iter ] = jpewagwvqf_idx_0 ; } rtB
. l31i4u50oo [ 0 ] = m2ldz44rx4 [ 1 ] ; rtB . l31i4u50oo [ 1 ] = m2ldz44rx4 [
2 ] ; rtB . l31i4u50oo [ 2 ] = m2ldz44rx4 [ 3 ] ; if ( ( rtDW . d2miu0jpen >=
ssGetT ( rtS ) ) && ( rtDW . pxvqpp25ev >= ssGetT ( rtS ) ) ) { rtB .
btzpl3o1sm [ 0 ] = 0.0 ; rtB . btzpl3o1sm [ 1 ] = 0.0 ; rtB . btzpl3o1sm [ 2
] = 0.0 ; rtB . btzpl3o1sm [ 3 ] = 0.0 ; } else { fqhdbem00h = rtDW .
d2miu0jpen ; lastU = & rtDW . bobp110c5u ; if ( rtDW . d2miu0jpen < rtDW .
pxvqpp25ev ) { if ( rtDW . pxvqpp25ev < ssGetT ( rtS ) ) { fqhdbem00h = rtDW
. pxvqpp25ev ; lastU = & rtDW . f1l0npvonb ; } } else { if ( rtDW .
d2miu0jpen >= ssGetT ( rtS ) ) { fqhdbem00h = rtDW . pxvqpp25ev ; lastU = &
rtDW . f1l0npvonb ; } } fqhdbem00h = ssGetT ( rtS ) - fqhdbem00h ; rtB .
btzpl3o1sm [ 0 ] = ( rtB . cc3vamisq4t . gaty2jlz2p [ 0 ] - ( * lastU ) [ 0 ]
) / fqhdbem00h ; rtB . btzpl3o1sm [ 1 ] = ( rtB . cc3vamisq4t . gaty2jlz2p [
1 ] - ( * lastU ) [ 1 ] ) / fqhdbem00h ; rtB . btzpl3o1sm [ 2 ] = ( rtB .
cc3vamisq4t . gaty2jlz2p [ 2 ] - ( * lastU ) [ 2 ] ) / fqhdbem00h ; rtB .
btzpl3o1sm [ 3 ] = ( rtB . cc3vamisq4t . gaty2jlz2p [ 3 ] - ( * lastU ) [ 3 ]
) / fqhdbem00h ; } if ( ( rtDW . hhrhjkqm2k >= ssGetT ( rtS ) ) && ( rtDW .
cqqd21gc1k >= ssGetT ( rtS ) ) ) { rtB . fogveq4aag [ 0 ] = 0.0 ; rtB .
fogveq4aag [ 1 ] = 0.0 ; rtB . fogveq4aag [ 2 ] = 0.0 ; rtB . fogveq4aag [ 3
] = 0.0 ; } else { fqhdbem00h = rtDW . hhrhjkqm2k ; lastU = & rtDW .
hy0scmn4pf ; if ( rtDW . hhrhjkqm2k < rtDW . cqqd21gc1k ) { if ( rtDW .
cqqd21gc1k < ssGetT ( rtS ) ) { fqhdbem00h = rtDW . cqqd21gc1k ; lastU = &
rtDW . gomv25feag ; } } else { if ( rtDW . hhrhjkqm2k >= ssGetT ( rtS ) ) {
fqhdbem00h = rtDW . cqqd21gc1k ; lastU = & rtDW . gomv25feag ; } } fqhdbem00h
= ssGetT ( rtS ) - fqhdbem00h ; rtB . fogveq4aag [ 0 ] = ( rtB . lj0sp02vlxl
. fdh2hm3qwy [ 0 ] - ( * lastU ) [ 0 ] ) / fqhdbem00h ; rtB . fogveq4aag [ 1
] = ( rtB . lj0sp02vlxl . fdh2hm3qwy [ 1 ] - ( * lastU ) [ 1 ] ) / fqhdbem00h
; rtB . fogveq4aag [ 2 ] = ( rtB . lj0sp02vlxl . fdh2hm3qwy [ 2 ] - ( * lastU
) [ 2 ] ) / fqhdbem00h ; rtB . fogveq4aag [ 3 ] = ( rtB . lj0sp02vlxl .
fdh2hm3qwy [ 3 ] - ( * lastU ) [ 3 ] ) / fqhdbem00h ; } rtB . msa15xsmdx [ 0
] = ( ( rtP . k1_Gain * rtB . ets2sd1cpy [ 0 ] + njxhrvfs1c_idx_0 ) + rtP .
k_Gain * rtB . l31i4u50oo [ 0 ] ) + ( rtB . fogveq4aag [ 1 ] - rtB .
btzpl3o1sm [ 1 ] ) * rtP . k2_Gain ; rtB . msa15xsmdx [ 1 ] = ( ( rtP .
k1_Gain * rtB . ets2sd1cpy [ 1 ] + njxhrvfs1c_idx_1 ) + rtP . k_Gain * rtB .
l31i4u50oo [ 1 ] ) + ( rtB . fogveq4aag [ 2 ] - rtB . btzpl3o1sm [ 2 ] ) *
rtP . k2_Gain ; rtB . msa15xsmdx [ 2 ] = ( ( rtP . k1_Gain * rtB . ets2sd1cpy
[ 2 ] + njxhrvfs1c_idx_2 ) + rtP . k_Gain * rtB . l31i4u50oo [ 2 ] ) + ( rtB
. fogveq4aag [ 3 ] - rtB . btzpl3o1sm [ 3 ] ) * rtP . k2_Gain ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . eksoft0ukx [ 0 ] = rtB . ets2sd1cpy
[ 0 ] + rtB . msa15xsmdx [ 0 ] ; rtB . eksoft0ukx [ 1 ] = rtB . ets2sd1cpy [
1 ] + rtB . msa15xsmdx [ 1 ] ; rtB . eksoft0ukx [ 2 ] = rtB . ets2sd1cpy [ 2
] + rtB . msa15xsmdx [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { }
fzzz0da3bp ( rtB . fy4zj3hhge . gaty2jlz2p , & rtB . fzzz0da3bpm ) ;
fl3fthyqxf ( rtB . fy4zj3hhge . gaty2jlz2p , rtB . lgajxwyfuf , & rtB .
i2hoddpqqn ) ; eeqgjz4lp4 ( rtB . i2hoddpqqn . grgp0ja04k , & rtB .
h3f4zqct5b , rtP . CONSTANTS_par . mu_earth ) ; esmxkiztnv ( rtB .
fzzz0da3bpm . otpij24kr0 , rtB . h3f4zqct5b . kfmst3u5d3 , & rtB .
esmxkiztnvh ) ; fl3fthyqxf ( rtB . lj0sp02vlxl . fdh2hm3qwy , rtB .
esmxkiztnvh . ihykyxkclc , & rtB . dtnb1odzgu ) ; rtB . etpc1qwkkl [ 0 ] =
rtB . dtnb1odzgu . grgp0ja04k [ 0 ] * rtP . DYN_SC_par . mass ; rtB .
etpc1qwkkl [ 1 ] = rtB . dtnb1odzgu . grgp0ja04k [ 1 ] * rtP . DYN_SC_par .
mass ; rtB . etpc1qwkkl [ 2 ] = rtB . dtnb1odzgu . grgp0ja04k [ 2 ] * rtP .
DYN_SC_par . mass ; fzzz0da3bp ( rtB . lj0sp02vlxl . fdh2hm3qwy , & rtB .
o2egb43grn ) ; esmxkiztnv ( rtB . o2egb43grn . otpij24kr0 , rtB . etpc1qwkkl
, & rtB . mb4psf2ogk ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB .
l4bftekmh5 = rtP . nTtoT1_Gain * i2lmhfpmzi ; if ( ssIsSampleHit ( rtS , 1 ,
0 ) ) { { double locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput
( rtS ) ) { { if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval (
ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) , locTime ) ) {
rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . gzbqcsyzkc . LoggedData , &
locTime , & rtB . lj0sp02vlxl . fdh2hm3qwy [ 0 ] ) ; } } } } } evg4tqc010 (
rtB . lj0sp02vlxl . fdh2hm3qwy , & rtB . evg4tqc010g ) ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { { double locTime = ssGetTaskTime ( rtS , 1 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . gtgmcfoi3f .
LoggedData , & locTime , & rtB . evg4tqc010g . pl0ikyvvgy [ 0 ] ) ; } } } } {
double locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) )
{ { if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS (
rtS ) -> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . dzb5en3ect . LoggedData , & locTime , & rtB .
lkurcisohk [ 0 ] ) ; } } } } } rtB . jqoxdyrcpe [ 0 ] = rtP .
Gain_Gain_moxmp2rie1 * rtB . lkurcisohk [ 0 ] ; rtB . jqoxdyrcpe [ 1 ] = rtP
. Gain_Gain_moxmp2rie1 * rtB . lkurcisohk [ 1 ] ; rtB . jqoxdyrcpe [ 2 ] =
rtP . Gain_Gain_moxmp2rie1 * rtB . lkurcisohk [ 2 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { { double locTime = ssGetTaskTime ( rtS , 1 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . id44yqi2er .
LoggedData , & locTime , & rtB . jqoxdyrcpe [ 0 ] ) ; } } } } { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if
( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . a1dzmttfkg . LoggedData , & locTime , & rtB .
fy4zj3hhge . gaty2jlz2p [ 0 ] ) ; } } } } { double locTime = ssGetTaskTime (
rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval
( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . jm4yyjoxrc .
LoggedData , & locTime , & rtB . kaa1h5fw2dm . apia2ki5qj [ 0 ] ) ; } } } } }
rtB . gfgjayhai0 [ 0 ] = 1.0 / rtP . DYN_SC_par . mass * rtB . mt5ejwesnp [ 0
] ; rtB . gfgjayhai0 [ 1 ] = 1.0 / rtP . DYN_SC_par . mass * rtB . mt5ejwesnp
[ 1 ] ; rtB . gfgjayhai0 [ 2 ] = 1.0 / rtP . DYN_SC_par . mass * rtB .
mt5ejwesnp [ 2 ] ; rtB . eqejlpzyjk [ 0 ] = rtB . gfgjayhai0 [ 0 ] + rtB .
esmxkiztnvh . ihykyxkclc [ 0 ] ; rtB . eqejlpzyjk [ 1 ] = rtB . gfgjayhai0 [
1 ] + rtB . esmxkiztnvh . ihykyxkclc [ 1 ] ; rtB . eqejlpzyjk [ 2 ] = rtB .
gfgjayhai0 [ 2 ] + rtB . esmxkiztnvh . ihykyxkclc [ 2 ] ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { { double locTime = ssGetTaskTime ( rtS , 1 ) ; ; if (
ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . ghseczrajd .
LoggedData , & locTime , & rtB . eqejlpzyjk [ 0 ] ) ; } } } } { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if
( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . mqvqz0mc3o . LoggedData , & locTime , & rtB .
mt5ejwesnp [ 0 ] ) ; } } } } { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . ffw1agfuzs .
LoggedData , & locTime , & rtB . ajt3i13qwt [ 0 ] ) ; } } } } { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if
( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . jxvmg11z51 . LoggedData , & locTime , & rtB .
gfgjayhai0 [ 0 ] ) ; } } } } { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . kuevle4fk1 .
LoggedData , & locTime , & rtB . mt5ejwesnp [ 0 ] ) ; } } } } { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if
( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . dj0y1a4rkp . LoggedData , & locTime , & rtB .
eksoft0ukx [ 0 ] ) ; } } } } { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . anhptlbpor .
LoggedData , & locTime , & rtB . esmxkiztnvh . ihykyxkclc [ 0 ] ) ; } } } } {
double locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) )
{ { if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS (
rtS ) -> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . nys0j5xotg . LoggedData , & locTime , & rtB .
etpc1qwkkl [ 0 ] ) ; } } } } { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . ot4oqlzgej .
LoggedData , & locTime , & rtB . mb4psf2ogk . ihykyxkclc [ 0 ] ) ; } } } } {
double locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) )
{ { if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS (
rtS ) -> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . ajfa0dqrat . LoggedData , & locTime , & rtB .
o3ah3cxi2g [ 0 ] ) ; } } } } { double locTime = ssGetTaskTime ( rtS , 1 ) ; ;
if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . gl2kjcpx0w .
LoggedData , & locTime , & rtB . p11ofm4mny [ 0 ] ) ; } } } } { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if
( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . aexra1pda3 . LoggedData , & locTime , & rtB .
b02oakwn4y . ihykyxkclc [ 0 ] ) ; } } } } { double locTime = ssGetTaskTime (
rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval
( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . hg1ul0ders .
LoggedData , & locTime , & rtB . l4bftekmh5 ) ; } } } } { double locTime =
ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if (
rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . kl2yhyienj . LoggedData , & locTime , & rtB .
f1ei3kfb3b . ihykyxkclc [ 0 ] ) ; } } } } { double locTime = ssGetTaskTime (
rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if ( rtwTimeInLoggingInterval
( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateStructLogVar ( ( StructLogVar * ) rtDW . bvz2m4kqbs .
LoggedData , & locTime , & rtB . lgajxwyfuf [ 0 ] ) ; } } } } { double
locTime = ssGetTaskTime ( rtS , 1 ) ; ; if ( ssGetLogOutput ( rtS ) ) { { if
( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateStructLogVar ( (
StructLogVar * ) rtDW . fmcrmebkkc . LoggedData , & locTime , & rtB .
dlialfoqve [ 0 ] ) ; } } } } } rtB . kpo0uqsydb = ( ( ! ( egmjspetb3 < rtP .
CheckdeltaT_minmax [ 0 ] ) ) && ( ! ( egmjspetb3 > rtP . CheckdeltaT_minmax [
1 ] ) ) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { assessmentPtrVar = ( void
* ) & assessmentVar ; if ( rtB . kpo0uqsydb != 0.0 ) { assessmentVar = 0 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . l5porott1o , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSWV2/DYN/DYN_AERO/ECI Position to LLA/Check deltaT/Assertion" , 2 ,
ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested ( rtS
, ( int ) ssGetT ( rtS ) ) ; assessmentVar = 1 ; rt_SlioAccessorUpdate ( 1 ,
3 , rtDW . l5porott1o , ssGetT ( rtS ) , assessmentPtrVar ) ; } } rtB .
lswkgkveua = ( ( ! ( egmjspetb3 < rtP . CheckdeltaT_minmax_iihlx1pzw0 [ 0 ] )
) && ( ! ( egmjspetb3 > rtP . CheckdeltaT_minmax_iihlx1pzw0 [ 1 ] ) ) ) ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { assessmentPtrVar = ( void * ) &
assessmentVar_p ; if ( rtB . lswkgkveua != 0.0 ) { assessmentVar_p = 0 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . emojxwu2oc , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
 "TST_RWSWV2/DYN/DYN_AERO/ECI Position to LLA/Direction Cosine Matrix ECI to ECEF/Check deltaT/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested
( rtS , ( int ) ssGetT ( rtS ) ) ; assessmentVar_p = 1 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . emojxwu2oc , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } } ltksehy2vp [ 0 ] = - 0.0 ; ltksehy2vp [ 4 ] = rtB .
lkurcisohk [ 2 ] ; ltksehy2vp [ 8 ] = - rtB . lkurcisohk [ 1 ] ; ltksehy2vp [
1 ] = - rtB . lkurcisohk [ 2 ] ; ltksehy2vp [ 5 ] = - 0.0 ; ltksehy2vp [ 9 ]
= rtB . lkurcisohk [ 0 ] ; ltksehy2vp [ 2 ] = rtB . lkurcisohk [ 1 ] ;
ltksehy2vp [ 6 ] = - rtB . lkurcisohk [ 0 ] ; ltksehy2vp [ 10 ] = - 0.0 ;
ltksehy2vp [ 12 ] = rtB . lkurcisohk [ 0 ] ; ltksehy2vp [ 3 ] = - rtB .
lkurcisohk [ 0 ] ; ltksehy2vp [ 13 ] = rtB . lkurcisohk [ 1 ] ; ltksehy2vp [
7 ] = - rtB . lkurcisohk [ 1 ] ; ltksehy2vp [ 14 ] = rtB . lkurcisohk [ 2 ] ;
ltksehy2vp [ 11 ] = - rtB . lkurcisohk [ 2 ] ; ltksehy2vp [ 15 ] = 0.0 ; for
( s258_iter = 0 ; s258_iter < 4 ; s258_iter ++ ) { jpewagwvqf_idx_2 =
ltksehy2vp [ s258_iter + 12 ] * psqdofqdfc [ 3 ] + ( ltksehy2vp [ s258_iter +
8 ] * psqdofqdfc [ 2 ] + ( ltksehy2vp [ s258_iter + 4 ] * psqdofqdfc [ 1 ] +
ltksehy2vp [ s258_iter ] * psqdofqdfc [ 0 ] ) ) ; rtB . j02du3klu3 [
s258_iter ] = rtP . Gain_Gain_i5aw4tqqra * jpewagwvqf_idx_2 ; } lawi0f5r5l (
rtB . p11ofm4mny , rtB . lkurcisohk , & rtB . lawi0f5r5l2 ) ; rtB .
ngqcqv0rct [ 0 ] = rtB . eksoft0ukx [ 0 ] + rtB . lawi0f5r5l2 . jgjuew1xpe [
0 ] ; rtB . ngqcqv0rct [ 1 ] = rtB . eksoft0ukx [ 1 ] + rtB . lawi0f5r5l2 .
jgjuew1xpe [ 1 ] ; rtB . ngqcqv0rct [ 2 ] = rtB . eksoft0ukx [ 2 ] + rtB .
lawi0f5r5l2 . jgjuew1xpe [ 2 ] ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
assessmentPtrVar = ( void * ) & assessmentVar_e ; if ( rtB . do0ide2rcv !=
0.0 ) { assessmentVar_e = 0 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW .
eph5mfdrkn , ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSWV2/DYN/DYN_EPHEM/Planetary Ephemeris/Check Epoch/Assertion" , 2 ,
ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested ( rtS
, ( int ) ssGetT ( rtS ) ) ; assessmentVar_e = 1 ; rt_SlioAccessorUpdate ( 1
, 3 , rtDW . eph5mfdrkn , ssGetT ( rtS ) , assessmentPtrVar ) ; } }
egmjspetb3 = rtB . odftn2hv1u + rtP . Bias_Bias_flmqlfoqqk ; i2lmhfpmzi =
muDoubleScalarFloor ( egmjspetb3 ) ; egmjspetb3 = ( egmjspetb3 - i2lmhfpmzi )
+ rtB . h5tjg3ytfz ; fqhdbem00h = muDoubleScalarFloor ( egmjspetb3 ) ;
egmjspetb3 -= fqhdbem00h ; i2lmhfpmzi = ( ( i2lmhfpmzi + rtB . cqv5xbg1eo ) +
rtP . Bias1_Bias_pmxtjmxgto ) + fqhdbem00h ; fqhdbem00h = muDoubleScalarFloor
( ( i2lmhfpmzi - rtP . Constant1_Value_bmlo5uuj5h [ 0 ] ) / rtP .
Constant1_Value_bmlo5uuj5h [ 2 ] ) + rtP . Bias2_Bias_olz25eww2t ; if (
ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( i2lmhfpmzi == rtP .
Constant1_Value_bmlo5uuj5h [ 1 ] ) ; rtDW . ottqmwv4ab = rtAction ; } else {
rtAction = rtDW . ottqmwv4ab ; } switch ( rtAction ) { case 0 : ikmey0rqcr =
fqhdbem00h + rtP . Bias1_Bias ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC
( rtDW . oyffazvwpp ) ; } break ; case 1 : ikmey0rqcr = fqhdbem00h ; if (
ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW . c3fesmoiak ) ; } break ; }
ikmey0rqcr = ( ( i2lmhfpmzi - ( ( ikmey0rqcr + rtP . Bias3_Bias ) * rtP .
Constant1_Value_bmlo5uuj5h [ 2 ] + rtP . Constant1_Value_bmlo5uuj5h [ 0 ] ) )
+ egmjspetb3 ) / rtP . Constant1_Value_bmlo5uuj5h [ 2 ] ; rtB . pzsslt1caj =
( muDoubleScalarMod ( ikmey0rqcr * rtP . Center_naPlanet , rtP .
Constant3_Value_bohdsdpayz ) + muDoubleScalarFloor ( ikmey0rqcr ) ) * rtP .
Gain_Gain_f4w25nzgog + rtP . Bias_Bias_p0shme04zp ; if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { if ( rtB . jijwwtb0yp < 2.147483648E+9 ) { if ( rtB .
jijwwtb0yp >= - 2.147483648E+9 ) { s258_iter = ( int32_T ) rtB . jijwwtb0yp ;
} else { s258_iter = MIN_int32_T ; } } else if ( rtB . jijwwtb0yp >=
2.147483648E+9 ) { s258_iter = MAX_int32_T ; } else { s258_iter = 0 ; } if (
s258_iter > 2147483646 ) { s258_iter = 2147483646 ; } else { if ( s258_iter <
0 ) { s258_iter = 0 ; } } for ( s307_iter = 1 ; s307_iter <= s258_iter ;
s307_iter ++ ) { if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
o5lwvvqufc ) ; } } for ( s258_iter = 1 ; s258_iter <= rtP . position_ncm ;
s258_iter ++ ) { } if ( rtB . nbtiislwyo < 2.147483648E+9 ) { if ( rtB .
nbtiislwyo >= - 2.147483648E+9 ) { s258_iter = ( int32_T ) rtB . nbtiislwyo ;
} else { s258_iter = MIN_int32_T ; } } else if ( rtB . nbtiislwyo >=
2.147483648E+9 ) { s258_iter = MAX_int32_T ; } else { s258_iter = 0 ; } if (
s258_iter > 2147483646 ) { s258_iter = 2147483646 ; } else { if ( s258_iter <
0 ) { s258_iter = 0 ; } } for ( s307_iter = 1 ; s307_iter <= s258_iter ;
s307_iter ++ ) { if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
it5tygcmno ) ; } } for ( s258_iter = 1 ; s258_iter <= rtP .
ncm_IterationLimit ; s258_iter ++ ) { } } egmjspetb3 += i2lmhfpmzi ; rtB .
lirx01d5pq = ( ( ! ( egmjspetb3 < rtP . Checkepoch_ephConstants . JED [ 0 ] )
) && ( ! ( egmjspetb3 > rtP . Checkepoch_ephConstants . JED [ 1 ] ) ) ) ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { assessmentPtrVar = ( void * ) &
assessmentVar_i ; if ( rtB . lirx01d5pq != 0.0 ) { assessmentVar_i = 0 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . aubnmf0jim , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSWV2/DYN/DYN_EPHEM/Planetary Ephemeris/Register/Check epoch/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested
( rtS , ( int ) ssGetT ( rtS ) ) ; assessmentVar_i = 1 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . aubnmf0jim , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } } rtB . ebsuxsvpmx = ( muDoubleScalarMod ( ikmey0rqcr
* rtP . Target_naMoon , rtP . Constant3_Value_ftxntawgwq ) +
muDoubleScalarFloor ( ikmey0rqcr ) ) * rtP . Gain_Gain_c30u4o0enn + rtP .
Bias_Bias_pi2fgfnx13 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { ok5kaek4lx (
rtS , rtB . juh0nqufwc , & rtDW . ok5kaek4lxs ) ; fq0ya2wvxm ( rtP .
position_ncm_ptclloauod ) ; cuzz03aam2 ( rtS , rtB . c2xk3hs0dm , & rtDW .
cuzz03aam2l ) ; ouhnihomld ( & rtP . ouhnihomlde ) ; } rtB . bkt40k0f2p = (
muDoubleScalarMod ( ikmey0rqcr * rtP . Target_naPlanet , rtP .
Constant3_Value_nntqaqmg1d ) + muDoubleScalarFloor ( ikmey0rqcr ) ) * rtP .
Gain_Gain_f5xiu22kap + rtP . Bias_Bias_glx5rwigzp ; if ( ssIsSampleHit ( rtS
, 1 , 0 ) ) { ok5kaek4lx ( rtS , rtB . hezxe4ft4m , & rtDW . favglkmcha ) ;
fq0ya2wvxm ( rtP . position_ncm_binq5apr4m ) ; cuzz03aam2 ( rtS , rtB .
ae4gpxobre , & rtDW . kugkutdkkw ) ; ouhnihomld ( & rtP . c4u0lt4ut5 ) ; if (
ssIsMajorTimeStep ( rtS ) ) { rtAction = ( int8_T ) ! ( rtP . kmflag_Value >
1.0 ) ; rtDW . mjjt5milxa = rtAction ; } else { rtAction = rtDW . mjjt5milxa
; } switch ( rtAction ) { case 0 : if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . kyqgjgbzfu ) ; } break ; case 1 : if ( ssIsMajorTimeStep
( rtS ) ) { srUpdateBC ( rtDW . khigjg54p1 ) ; } break ; } } rtB . ngdb14tcrd
= ( ( ! ( evfxmkblai < rtP . CheckdeltaT_minmax_fu5tpc2tet [ 0 ] ) ) && ( ! (
evfxmkblai > rtP . CheckdeltaT_minmax_fu5tpc2tet [ 1 ] ) ) ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { assessmentPtrVar = ( void * ) &
assessmentVar_m ; if ( rtB . ngdb14tcrd != 0.0 ) { assessmentVar_m = 0 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . ceonvoxabs , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSWV2/DYN/DYN_MAG/ECI Position to LLA/Check deltaT/Assertion" , 2 ,
ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested ( rtS
, ( int ) ssGetT ( rtS ) ) ; assessmentVar_m = 1 ; rt_SlioAccessorUpdate ( 1
, 3 , rtDW . ceonvoxabs , ssGetT ( rtS ) , assessmentPtrVar ) ; } } rtB .
dnw24xma2i = ( ( ! ( evfxmkblai < rtP . CheckdeltaT_minmax_gtfjjd3va0 [ 0 ] )
) && ( ! ( evfxmkblai > rtP . CheckdeltaT_minmax_gtfjjd3va0 [ 1 ] ) ) ) ; if
( ssIsSampleHit ( rtS , 1 , 0 ) ) { assessmentPtrVar = ( void * ) &
assessmentVar_g ; if ( rtB . dnw24xma2i != 0.0 ) { assessmentVar_g = 0 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . oeklz3vrcs , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
 "TST_RWSWV2/DYN/DYN_MAG/ECI Position to LLA/Direction Cosine Matrix ECI to ECEF/Check deltaT/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; ssSetStopRequested
( rtS , ( int ) ssGetT ( rtS ) ) ; assessmentVar_g = 1 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . oeklz3vrcs , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } } rtB . eba45de2d3 = ( ( rtP . CheckAltitude_min <=
fug530bbhx ) && ( fug530bbhx <= rtP . CheckAltitude_max ) ) ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { assessmentPtrVar = ( void * ) &
assessmentVar_j ; if ( rtB . eba45de2d3 ) { assessmentVar_j = 0 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . ewbbr1445y , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/Check Altitude/Assertion" ,
2 , ssGetT ( rtS ) ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ;
assessmentVar_j = 1 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . ewbbr1445y ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } } rtB . ctlrtezbkb = ( ( rtP .
CheckLatitude_min <= k4q33fn5wp ) && ( k4q33fn5wp <= rtP . CheckLatitude_max
) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { assessmentPtrVar = ( void * ) &
assessmentVar_f ; if ( rtB . ctlrtezbkb ) { assessmentVar_f = 0 ;
rt_SlioAccessorUpdate ( 1 , 3 , rtDW . hvp123ipm0 , ssGetT ( rtS ) ,
assessmentPtrVar ) ; } else { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/Check Latitude/Assertion" ,
2 , ssGetT ( rtS ) ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ;
assessmentVar_f = 1 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . hvp123ipm0 ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } } rtB . kfzrwtoo11 = ( ( rtP .
CheckLongitude_min <= acweymdfsj ) && ( acweymdfsj <= rtP .
CheckLongitude_max ) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
assessmentPtrVar = ( void * ) & assessmentVar_c ; if ( rtB . kfzrwtoo11 ) {
assessmentVar_c = 0 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . no4z2mnrxf ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5 ,
"TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/Check Longitude/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ;
assessmentVar_c = 1 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . no4z2mnrxf ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } } rtB . fmq50sce1p = ( ( rtP .
Istimewithinmodellimits_min <= rtB . hllg2hyyik ) && ( rtB . hllg2hyyik <=
rtP . Istimewithinmodellimits_max ) ) ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ assessmentPtrVar = ( void * ) & assessmentVar_k ; if ( rtB . fmq50sce1p ) {
assessmentVar_k = 0 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . c0fqulldoy ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } else { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:AssertionAssert" , 2 , 5 ,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/Is time within model limits/Assertion"
, 2 , ssGetT ( rtS ) ) ; rt_ssReportDiagnosticAsWarning ( S , diag ) ;
assessmentVar_k = 1 ; rt_SlioAccessorUpdate ( 1 , 3 , rtDW . c0fqulldoy ,
ssGetT ( rtS ) , assessmentPtrVar ) ; } { if ( ( rtDW . opv2domrvm .
AQHandles || rtDW . opv2domrvm . SlioLTF ) && ssGetLogOutput ( rtS ) ) {
sdiSlioSdiWriteSignal ( rtDW . opv2domrvm . AQHandles , rtDW . opv2domrvm .
SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . lgajxwyfuf [ 0 ]
+ 0 ) ; } } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID2 ( int_T tid )
{ int32_T i ; rtB . ol3bqwr21m = ( rtP . ECIPositiontoLLA_sec + rtP .
Bias_Bias_nkpxz13mna ) * rtP . secGain_Gain ; rtB . itueiehnrc = rtP .
gainVal_Gain * rtP . ECIPositiontoLLA_sec ; for ( i = 0 ; i < 8 ; i ++ ) {
memcpy ( & rtB . kvgnk3vwbl [ i * 66 ] , & rtP . Constant_Value_jg4kuwigu3 [
i * 66 + 198 ] , 66U * sizeof ( real_T ) ) ; } memcpy ( & rtB . jywa2bcbgw [
0 ] , & rtP . Constant_Value_jg4kuwigu3 [ 66 ] , 66U * sizeof ( real_T ) ) ;
memcpy ( & rtB . gp0yss5tss [ 0 ] , & rtP . Constant_Value_jg4kuwigu3 [ 132 ]
, 66U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB
. ogh5hr0p0j [ i * 1600 ] , & rtP . Constant_Value_b3j4g0lv2s [ i * 1600 +
4800 ] , 1600U * sizeof ( real_T ) ) ; } memcpy ( & rtB . nfpmyaudo5 [ 0 ] ,
& rtP . Constant_Value_b3j4g0lv2s [ 1600 ] , 1600U * sizeof ( real_T ) ) ;
memcpy ( & rtB . lglaedtr5a [ 0 ] , & rtP . Constant_Value_b3j4g0lv2s [ 3200
] , 1600U * sizeof ( real_T ) ) ; for ( i = 0 ; i < 14 ; i ++ ) { memcpy ( &
rtB . d5i5n2ctvl [ i * 1275 ] , & rtP . Constant_Value_blhzdoapdh [ i * 1275
+ 3825 ] , 1275U * sizeof ( real_T ) ) ; } memcpy ( & rtB . eetng5atfq [ 0 ]
, & rtP . Constant_Value_blhzdoapdh [ 1275 ] , 1275U * sizeof ( real_T ) ) ;
memcpy ( & rtB . judoxslscy [ 0 ] , & rtP . Constant_Value_blhzdoapdh [ 2550
] , 1275U * sizeof ( real_T ) ) ; rtB . afvb1ehg0t [ 0 ] = rtP .
Gain1_Gain_b53uubhwtd * 0.0 ; rtB . afvb1ehg0t [ 1 ] = rtP .
Gain1_Gain_b53uubhwtd * 0.0 ; rtB . hyyusjwwd0 = rtP .
Constant_Value_p1a403vys0 - rtP . Constant1_Value_mfchg4r0gl ; rtB .
ialvqzftpg = rtP . Constant_Value_j1ranlmwoh * rtB . hyyusjwwd0 ; rtB .
pf0kn2talc = rtP . Constant_Value_bvi4us34ks - rtB . hyyusjwwd0 * rtB .
hyyusjwwd0 ; rtB . cucbrhyluc = rtB . pf0kn2talc / ( rtP .
Constant_Value_i0bsfym50v - rtB . pf0kn2talc ) ; rtB . jv1d0qfy4m = ( ( rtP .
deltaAT_Value + rtP . DirectionCosineMatrixECItoECEF_sec ) + rtP .
Bias_Bias_hn0u5qqmwi ) * rtP . secGain_Gain_epta5goh22 ; rtB . a0ua2epli1 = (
rtP . DirectionCosineMatrixECItoECEF_sec + rtP . deltaUT1_Value ) * rtP .
gainVal_Gain_chmu2i0axw ; for ( i = 0 ; i < 8 ; i ++ ) { memcpy ( & rtB .
j1syazdgd4 [ i * 66 ] , & rtP . Constant_Value_cavkjd5ie3 [ i * 66 + 198 ] ,
66U * sizeof ( real_T ) ) ; } memcpy ( & rtB . gsgwdmkgku [ 0 ] , & rtP .
Constant_Value_cavkjd5ie3 [ 66 ] , 66U * sizeof ( real_T ) ) ; memcpy ( & rtB
. axbdr3x1fp [ 0 ] , & rtP . Constant_Value_cavkjd5ie3 [ 132 ] , 66U * sizeof
( real_T ) ) ; for ( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB . ag3iipcuzh [
i * 1600 ] , & rtP . Constant_Value_gty3wyfcoq [ i * 1600 + 4800 ] , 1600U *
sizeof ( real_T ) ) ; } memcpy ( & rtB . g22eqcolk1 [ 0 ] , & rtP .
Constant_Value_gty3wyfcoq [ 1600 ] , 1600U * sizeof ( real_T ) ) ; memcpy ( &
rtB . dw4fhg5i10 [ 0 ] , & rtP . Constant_Value_gty3wyfcoq [ 3200 ] , 1600U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB .
hs0i1v4xen [ i * 1275 ] , & rtP . Constant_Value_pdipd1st4u [ i * 1275 + 3825
] , 1275U * sizeof ( real_T ) ) ; } memcpy ( & rtB . bpam2luzqr [ 0 ] , & rtP
. Constant_Value_pdipd1st4u [ 1275 ] , 1275U * sizeof ( real_T ) ) ; memcpy (
& rtB . muwbjqqbz2 [ 0 ] , & rtP . Constant_Value_pdipd1st4u [ 2550 ] , 1275U
* sizeof ( real_T ) ) ; rtB . gm45wrvmmz [ 0 ] = rtP . Gain1_Gain_ebugzibmgy
* rtP . PolarMotion_Value [ 0 ] ; rtB . gm45wrvmmz [ 1 ] = rtP .
Gain1_Gain_ebugzibmgy * rtP . PolarMotion_Value [ 1 ] ; rtB . do0ide2rcv = (
( ! ( rtP . Epoch_Value < rtP . CheckEpoch_minmax [ 0 ] ) ) && ( ! ( rtP .
Epoch_Value > rtP . CheckEpoch_minmax [ 1 ] ) ) ) ; rtB . jijwwtb0yp = rtP .
forpc_ncf + rtP . Bias1_Bias_j2z3znjcsz ; rtB . nbtiislwyo = rtP . forvc_ncf
+ rtP . Bias1_Bias_bvg1k5rg0f ; rtB . cqv5xbg1eo = muDoubleScalarFloor ( rtP
. Epoch_Value ) ; rtB . h5tjg3ytfz = rtP . Epoch_Value - rtB . cqv5xbg1eo ;
rtB . juh0nqufwc = rtP . forpc_ncf_ph3jlcz4wu + rtP . Bias1_Bias_g55s220pw2 ;
rtB . c2xk3hs0dm = rtP . forvc_ncf_hr0ktg40xd + rtP . Bias1_Bias_lzvtas1qzq ;
rtB . hezxe4ft4m = rtP . forpc_ncf_af3025p2ex + rtP . Bias1_Bias_gv1ss5ckfh ;
rtB . ae4gpxobre = rtP . forvc_ncf_fk2zw2hgit + rtP . Bias1_Bias_mpyutg2drp ;
rtB . gli54111iq = ( rtP . ECIPositiontoLLA_sec_kfquz0jahd + rtP .
Bias_Bias_cjcrgmv0l3 ) * rtP . secGain_Gain_oylue433r5 ; rtB . ml34nkrhlq =
rtP . gainVal_Gain_bwdhfpid4p * rtP . ECIPositiontoLLA_sec_kfquz0jahd ; for (
i = 0 ; i < 8 ; i ++ ) { memcpy ( & rtB . gkar21mdwf [ i * 66 ] , & rtP .
Constant_Value_gzvtnl3xxy [ i * 66 + 198 ] , 66U * sizeof ( real_T ) ) ; }
memcpy ( & rtB . lu33o4w1r3 [ 0 ] , & rtP . Constant_Value_gzvtnl3xxy [ 66 ]
, 66U * sizeof ( real_T ) ) ; memcpy ( & rtB . drh3kx0c2g [ 0 ] , & rtP .
Constant_Value_gzvtnl3xxy [ 132 ] , 66U * sizeof ( real_T ) ) ; for ( i = 0 ;
i < 14 ; i ++ ) { memcpy ( & rtB . gbmpokz3zp [ i * 1600 ] , & rtP .
Constant_Value_g4grteekgh [ i * 1600 + 4800 ] , 1600U * sizeof ( real_T ) ) ;
} memcpy ( & rtB . kyoy4xdfin [ 0 ] , & rtP . Constant_Value_g4grteekgh [
1600 ] , 1600U * sizeof ( real_T ) ) ; memcpy ( & rtB . ou1vh1l3du [ 0 ] , &
rtP . Constant_Value_g4grteekgh [ 3200 ] , 1600U * sizeof ( real_T ) ) ; for
( i = 0 ; i < 14 ; i ++ ) { memcpy ( & rtB . mr1b0wzzg2 [ i * 1275 ] , & rtP
. Constant_Value_mbu4gju5a1 [ i * 1275 + 3825 ] , 1275U * sizeof ( real_T ) )
; } memcpy ( & rtB . obucup33bh [ 0 ] , & rtP . Constant_Value_mbu4gju5a1 [
1275 ] , 1275U * sizeof ( real_T ) ) ; memcpy ( & rtB . bixz4y4cs3 [ 0 ] , &
rtP . Constant_Value_mbu4gju5a1 [ 2550 ] , 1275U * sizeof ( real_T ) ) ; rtB
. lem3rvqyps [ 0 ] = rtP . Gain1_Gain_dvdyrqq1on * 0.0 ; rtB . lem3rvqyps [ 1
] = rtP . Gain1_Gain_dvdyrqq1on * 0.0 ; rtB . exuyfpbwx3 = rtP .
Constant_Value_dpnq5xi00x - rtP . Constant1_Value_pkdueqdvo3 ; rtB .
dyisgf03lw = rtP . Constant_Value_om4mc214qr * rtB . exuyfpbwx3 ; rtB .
iz3tczqrpq = rtP . Constant_Value_ctduzx5i1o - rtB . exuyfpbwx3 * rtB .
exuyfpbwx3 ; rtB . fzk34rhf1c = rtB . iz3tczqrpq / ( rtP .
Constant_Value_pbi1wqbyik - rtB . iz3tczqrpq ) ; rtB . ntw01syjjc = rtP .
a_Value * rtP . a_Value ; rtB . oech2kz1cy = rtP . b_Value * rtP . b_Value ;
rtB . a3gezjtvdu = rtB . ntw01syjjc - rtB . oech2kz1cy ; rtB . fpa3tundiw =
rtB . ntw01syjjc * rtB . ntw01syjjc ; rtB . d0kea0dkjy = rtB . fpa3tundiw -
rtB . oech2kz1cy * rtB . oech2kz1cy ; rtB . evxijl2a3r = rtB . ntw01syjjc -
rtB . oech2kz1cy ; if ( ssIsMajorTimeStep ( rtS ) ) { srUpdateBC ( rtDW .
c4fmxjrfvq ) ; srUpdateBC ( rtDW . dpoz2afmu5 ) ; } rtB . fqejnq5fml = rtP .
Gain1_Gain_ow0iqmdqvl * rtP . JDepoch_days_Value ; UNUSED_PARAMETER ( tid ) ;
} void MdlUpdate ( int_T tid ) { real_T ( * lastU ) [ 4 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . pttppk3jcp = rtB . ewdeweoohc ; rtDW
. ay1crq4gjz = rtB . b22cbxmnlr ; rtDW . cws51k2ewn = rtB . jo115loilo ; rtDW
. d4vvv2k2v3 = rtB . lvq4s5cl0c ; } if ( rtDW . d2miu0jpen == ( rtInf ) ) {
rtDW . d2miu0jpen = ssGetT ( rtS ) ; lastU = & rtDW . bobp110c5u ; } else if
( rtDW . pxvqpp25ev == ( rtInf ) ) { rtDW . pxvqpp25ev = ssGetT ( rtS ) ;
lastU = & rtDW . f1l0npvonb ; } else if ( rtDW . d2miu0jpen < rtDW .
pxvqpp25ev ) { rtDW . d2miu0jpen = ssGetT ( rtS ) ; lastU = & rtDW .
bobp110c5u ; } else { rtDW . pxvqpp25ev = ssGetT ( rtS ) ; lastU = & rtDW .
f1l0npvonb ; } ( * lastU ) [ 0 ] = rtB . cc3vamisq4t . gaty2jlz2p [ 0 ] ; ( *
lastU ) [ 1 ] = rtB . cc3vamisq4t . gaty2jlz2p [ 1 ] ; ( * lastU ) [ 2 ] =
rtB . cc3vamisq4t . gaty2jlz2p [ 2 ] ; ( * lastU ) [ 3 ] = rtB . cc3vamisq4t
. gaty2jlz2p [ 3 ] ; if ( rtDW . hhrhjkqm2k == ( rtInf ) ) { rtDW .
hhrhjkqm2k = ssGetT ( rtS ) ; lastU = & rtDW . hy0scmn4pf ; } else if ( rtDW
. cqqd21gc1k == ( rtInf ) ) { rtDW . cqqd21gc1k = ssGetT ( rtS ) ; lastU = &
rtDW . gomv25feag ; } else if ( rtDW . hhrhjkqm2k < rtDW . cqqd21gc1k ) {
rtDW . hhrhjkqm2k = ssGetT ( rtS ) ; lastU = & rtDW . hy0scmn4pf ; } else {
rtDW . cqqd21gc1k = ssGetT ( rtS ) ; lastU = & rtDW . gomv25feag ; } ( *
lastU ) [ 0 ] = rtB . lj0sp02vlxl . fdh2hm3qwy [ 0 ] ; ( * lastU ) [ 1 ] =
rtB . lj0sp02vlxl . fdh2hm3qwy [ 1 ] ; ( * lastU ) [ 2 ] = rtB . lj0sp02vlxl
. fdh2hm3qwy [ 2 ] ; ( * lastU ) [ 3 ] = rtB . lj0sp02vlxl . fdh2hm3qwy [ 3 ]
; UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> e5l2wmdpfb [ 0 ] = rtB
. ngqcqv0rct [ 0 ] ; _rtXdot -> mes33bxk5w [ 0 ] = rtB . dlialfoqve [ 0 ] ;
_rtXdot -> agflyx222j [ 0 ] = rtB . eqejlpzyjk [ 0 ] ; _rtXdot -> e5l2wmdpfb
[ 1 ] = rtB . ngqcqv0rct [ 1 ] ; _rtXdot -> mes33bxk5w [ 1 ] = rtB .
dlialfoqve [ 1 ] ; _rtXdot -> agflyx222j [ 1 ] = rtB . eqejlpzyjk [ 1 ] ;
_rtXdot -> e5l2wmdpfb [ 2 ] = rtB . ngqcqv0rct [ 2 ] ; _rtXdot -> mes33bxk5w
[ 2 ] = rtB . dlialfoqve [ 2 ] ; _rtXdot -> agflyx222j [ 2 ] = rtB .
eqejlpzyjk [ 2 ] ; _rtXdot -> mqqxdp0em5 [ 0 ] = rtB . j02du3klu3 [ 0 ] ;
_rtXdot -> mqqxdp0em5 [ 1 ] = rtB . j02du3klu3 [ 1 ] ; _rtXdot -> mqqxdp0em5
[ 2 ] = rtB . j02du3klu3 [ 2 ] ; _rtXdot -> mqqxdp0em5 [ 3 ] = rtB .
j02du3klu3 [ 3 ] ; } void MdlProjection ( void ) { } void MdlTerminate ( void
) { rtDW . l5porott1o = rt_SlioAccessorRelease ( 1 , 1 , rtDW . l5porott1o )
; rtDW . emojxwu2oc = rt_SlioAccessorRelease ( 1 , 1 , rtDW . emojxwu2oc ) ;
rtDW . eph5mfdrkn = rt_SlioAccessorRelease ( 1 , 1 , rtDW . eph5mfdrkn ) ;
rtDW . aubnmf0jim = rt_SlioAccessorRelease ( 1 , 1 , rtDW . aubnmf0jim ) ;
rtDW . ceonvoxabs = rt_SlioAccessorRelease ( 1 , 1 , rtDW . ceonvoxabs ) ;
rtDW . oeklz3vrcs = rt_SlioAccessorRelease ( 1 , 1 , rtDW . oeklz3vrcs ) ;
rtDW . ewbbr1445y = rt_SlioAccessorRelease ( 1 , 1 , rtDW . ewbbr1445y ) ;
rtDW . hvp123ipm0 = rt_SlioAccessorRelease ( 1 , 1 , rtDW . hvp123ipm0 ) ;
rtDW . no4z2mnrxf = rt_SlioAccessorRelease ( 1 , 1 , rtDW . no4z2mnrxf ) ;
rtDW . c0fqulldoy = rt_SlioAccessorRelease ( 1 , 1 , rtDW . c0fqulldoy ) ; {
if ( rtDW . opv2domrvm . AQHandles ) { sdiTerminateStreaming ( & rtDW .
opv2domrvm . AQHandles ) ; } if ( rtDW . opv2domrvm . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . opv2domrvm . SlioLTF ) ; } } if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 13 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 1543 ) ; ssSetNumBlockIO ( rtS , 197 ) ;
ssSetNumBlockParams ( rtS , 160521 ) ; } void MdlInitializeSampleTimes ( void
) { ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3474569553U ) ;
ssSetChecksumVal ( rtS , 1 , 1173510575U ) ; ssSetChecksumVal ( rtS , 2 ,
1738505644U ) ; ssSetChecksumVal ( rtS , 3 , 668405262U ) ; }
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
, & dtInfo ) ; dtInfo . numDataTypes = 29 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
TST_RWSWV2_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "TST_RWSWV2" ) ;
ssSetPath ( rtS , "TST_RWSWV2" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 5.256E+6 ) ; ssSetStepSize ( rtS , 1.0 ) ; ssSetFixedStepSize ( rtS ,
1.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
{ static int_T rt_LoggedStateWidths [ ] = { 3 , 3 , 3 , 4 , 2 , 1 , 4 , 1 , 1
, 1 , 1 , 169 , 169 , 169 , 169 , 13 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1
, 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 3 , 3 ,
3 , 4 , 2 , 1 , 4 , 1 , 1 , 1 , 1 , 169 , 169 , 169 , 169 , 13 } ; static
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
"TST_RWSWV2/DYN/DYN_ATT/Integrator" , "TST_RWSWV2/DYN/DYN_TRA/Integrator1" ,
"TST_RWSWV2/DYN/DYN_TRA/Integrator" ,
"TST_RWSWV2/DYN/DYN_ATT/DYN_ATT_KIN/Integrator" ,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Convert from geodetic to\n spherical coordinates\n/For Iterator\nSubsystem/Unit Delay1"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/Unit Delay"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/Unit Delay2"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Unit Delay1"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Unit Delay3"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Unit Delay2"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Unit Delay4"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Time adjust the gauss coefficients/Unit Delay"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Time adjust the gauss coefficients/if (m~=0)/Unit Delay"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Compute unnormalized associated \nlegendre polynomials and \nderivatives via recursion relations/Unit Delay"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Compute unnormalized associated \nlegendre polynomials and \nderivatives via recursion relations/Unit Delay1"
,
 "TST_RWSWV2/DYN/DYN_MAG/World Magnetic Model 2015/geomag/Compute magnetic vector in\nspherical coordinates/For Iterator\nSubsystem/Accumulate terms of the \nspherical harmonic expansion/Special case - North//South Geographic Pole/Unit Delay1"
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
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . e5l2wmdpfb [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . mes33bxk5w [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . agflyx222j [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . mqqxdp0em5 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) rtDW . jbiuzi4aai ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtDW . ogsulvdfqo ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) rtDW . o1a1coezrh ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtDW . oghbzylezs ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtDW . l31233tzs5 ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtDW . oe4craxtsr ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtDW . p3utuwbotk ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) rtDW . m35wdbwfjk ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) rtDW . adfw0bsjev ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) rtDW . bdtrovn01a ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) rtDW . bwjkpamfxw ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) rtDW . gwnmkcjbc1 ; }
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
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS , "ode3" ) ;
ssSetVariableStepSolver ( rtS , 0 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; ssSetContStateDisabled ( rtS , contStatesDisabled ) ; }
ssSetChecksumVal ( rtS , 0 , 3474569553U ) ; ssSetChecksumVal ( rtS , 1 ,
1173510575U ) ; ssSetChecksumVal ( rtS , 2 , 1738505644U ) ; ssSetChecksumVal
( rtS , 3 , 668405262U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 113 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = & rtAlwaysEnabled ;
systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = ( sysRanDType * ) &
rtDW . k3sfyh0c3kb . c5enzgh0ln ; systemRan [ 8 ] = ( sysRanDType * ) & rtDW
. eu5kqssxx5u . gmbejf1syu ; systemRan [ 9 ] = ( sysRanDType * ) & rtDW .
ep1krdw3c3 . c5enzgh0ln ; systemRan [ 10 ] = ( sysRanDType * ) & rtDW .
ausjujlz1d . gmbejf1syu ; systemRan [ 11 ] = & rtAlwaysEnabled ; systemRan [
12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = & rtAlwaysEnabled ; systemRan [
14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = & rtAlwaysEnabled ; systemRan [
16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = & rtAlwaysEnabled ; systemRan [
18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = & rtAlwaysEnabled ; systemRan [
20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = & rtAlwaysEnabled ; systemRan [
22 ] = & rtAlwaysEnabled ; systemRan [ 23 ] = & rtAlwaysEnabled ; systemRan [
24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] = ( sysRanDType * ) & rtDW .
ccrvxjn2zx . c5enzgh0ln ; systemRan [ 26 ] = ( sysRanDType * ) & rtDW .
fse3bizgct . gmbejf1syu ; systemRan [ 27 ] = ( sysRanDType * ) & rtDW .
f3bpn3lnkh . c5enzgh0ln ; systemRan [ 28 ] = ( sysRanDType * ) & rtDW .
cpe4p1nzlo . gmbejf1syu ; systemRan [ 29 ] = & rtAlwaysEnabled ; systemRan [
30 ] = & rtAlwaysEnabled ; systemRan [ 31 ] = & rtAlwaysEnabled ; systemRan [
32 ] = & rtAlwaysEnabled ; systemRan [ 33 ] = ( sysRanDType * ) & rtDW .
o5lwvvqufc ; systemRan [ 34 ] = & rtAlwaysEnabled ; systemRan [ 35 ] = &
rtAlwaysEnabled ; systemRan [ 36 ] = ( sysRanDType * ) & rtDW . it5tygcmno ;
systemRan [ 37 ] = & rtAlwaysEnabled ; systemRan [ 38 ] = & rtAlwaysEnabled ;
systemRan [ 39 ] = ( sysRanDType * ) & rtDW . oyffazvwpp ; systemRan [ 40 ] =
( sysRanDType * ) & rtDW . c3fesmoiak ; systemRan [ 41 ] = ( sysRanDType * )
& rtDW . ok5kaek4lxs . p0optqqzsf ; systemRan [ 42 ] = & rtAlwaysEnabled ;
systemRan [ 43 ] = & rtAlwaysEnabled ; systemRan [ 44 ] = ( sysRanDType * ) &
rtDW . cuzz03aam2l . d343bhqapn ; systemRan [ 45 ] = & rtAlwaysEnabled ;
systemRan [ 46 ] = & rtAlwaysEnabled ; systemRan [ 47 ] = ( sysRanDType * ) &
rtDW . favglkmcha . p0optqqzsf ; systemRan [ 48 ] = & rtAlwaysEnabled ;
systemRan [ 49 ] = & rtAlwaysEnabled ; systemRan [ 50 ] = ( sysRanDType * ) &
rtDW . kugkutdkkw . d343bhqapn ; systemRan [ 51 ] = & rtAlwaysEnabled ;
systemRan [ 52 ] = & rtAlwaysEnabled ; systemRan [ 53 ] = ( sysRanDType * ) &
rtDW . khigjg54p1 ; systemRan [ 54 ] = ( sysRanDType * ) & rtDW . kyqgjgbzfu
; systemRan [ 55 ] = & rtAlwaysEnabled ; systemRan [ 56 ] = & rtAlwaysEnabled
; systemRan [ 57 ] = & rtAlwaysEnabled ; systemRan [ 58 ] = & rtAlwaysEnabled
; systemRan [ 59 ] = & rtAlwaysEnabled ; systemRan [ 60 ] = & rtAlwaysEnabled
; systemRan [ 61 ] = & rtAlwaysEnabled ; systemRan [ 62 ] = & rtAlwaysEnabled
; systemRan [ 63 ] = & rtAlwaysEnabled ; systemRan [ 64 ] = & rtAlwaysEnabled
; systemRan [ 65 ] = & rtAlwaysEnabled ; systemRan [ 66 ] = & rtAlwaysEnabled
; systemRan [ 67 ] = & rtAlwaysEnabled ; systemRan [ 68 ] = & rtAlwaysEnabled
; systemRan [ 69 ] = & rtAlwaysEnabled ; systemRan [ 70 ] = & rtAlwaysEnabled
; systemRan [ 71 ] = & rtAlwaysEnabled ; systemRan [ 72 ] = ( sysRanDType * )
& rtDW . kvhpjeahvc . c5enzgh0ln ; systemRan [ 73 ] = ( sysRanDType * ) &
rtDW . cbgg0vjzsr . gmbejf1syu ; systemRan [ 74 ] = ( sysRanDType * ) & rtDW
. aoxobjloyv . c5enzgh0ln ; systemRan [ 75 ] = ( sysRanDType * ) & rtDW .
etw3qygazq . gmbejf1syu ; systemRan [ 76 ] = & rtAlwaysEnabled ; systemRan [
77 ] = & rtAlwaysEnabled ; systemRan [ 78 ] = & rtAlwaysEnabled ; systemRan [
79 ] = & rtAlwaysEnabled ; systemRan [ 80 ] = & rtAlwaysEnabled ; systemRan [
81 ] = & rtAlwaysEnabled ; systemRan [ 82 ] = & rtAlwaysEnabled ; systemRan [
83 ] = & rtAlwaysEnabled ; systemRan [ 84 ] = & rtAlwaysEnabled ; systemRan [
85 ] = & rtAlwaysEnabled ; systemRan [ 86 ] = & rtAlwaysEnabled ; systemRan [
87 ] = & rtAlwaysEnabled ; systemRan [ 88 ] = & rtAlwaysEnabled ; systemRan [
89 ] = ( sysRanDType * ) & rtDW . a3mffltq2c ; systemRan [ 90 ] = (
sysRanDType * ) & rtDW . fob5v3qelm ; systemRan [ 91 ] = ( sysRanDType * ) &
rtDW . bqkqmfirk2 ; systemRan [ 92 ] = ( sysRanDType * ) & rtDW . onw1kj0tt3
; systemRan [ 93 ] = ( sysRanDType * ) & rtDW . ouyhtippx4 ; systemRan [ 94 ]
= ( sysRanDType * ) & rtDW . jub4qa0tx5 ; systemRan [ 95 ] = ( sysRanDType *
) & rtDW . ehevun3t0d ; systemRan [ 96 ] = ( sysRanDType * ) & rtDW .
hafmo2yjxp ; systemRan [ 97 ] = ( sysRanDType * ) & rtDW . g1gz2kwalm ;
systemRan [ 98 ] = ( sysRanDType * ) & rtDW . bjrkfcnwqe ; systemRan [ 99 ] =
( sysRanDType * ) & rtDW . l4idmhenv4 ; systemRan [ 100 ] = ( sysRanDType * )
& rtDW . dgmhfl0ejy ; systemRan [ 101 ] = ( sysRanDType * ) & rtDW .
bjrkfcnwqe ; systemRan [ 102 ] = ( sysRanDType * ) & rtDW . ozdacijjrc ;
systemRan [ 103 ] = & rtAlwaysEnabled ; systemRan [ 104 ] = ( sysRanDType * )
& rtDW . c4fmxjrfvq ; systemRan [ 105 ] = ( sysRanDType * ) & rtDW .
dpoz2afmu5 ; systemRan [ 106 ] = ( sysRanDType * ) & rtDW . dpoz2afmu5 ;
systemRan [ 107 ] = & rtAlwaysEnabled ; systemRan [ 108 ] = & rtAlwaysEnabled
; systemRan [ 109 ] = & rtAlwaysEnabled ; systemRan [ 110 ] = &
rtAlwaysEnabled ; systemRan [ 111 ] = & rtAlwaysEnabled ; systemRan [ 112 ] =
& rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS )
, & ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr (
ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr (
ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } rtP .
CheckdeltaT_minmax [ 1 ] = rtInf ; rtP . CheckdeltaT_minmax_iihlx1pzw0 [ 1 ]
= rtInf ; rtP . CheckEpoch_minmax [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_fu5tpc2tet [ 1 ] = rtInf ; rtP .
CheckdeltaT_minmax_gtfjjd3va0 [ 1 ] = rtInf ; return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
