#ifndef RTW_HEADER_TST_RWSWV2_h_
#define RTW_HEADER_TST_RWSWV2_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef TST_RWSWV2_COMMON_INCLUDES_
#define TST_RWSWV2_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "TST_RWSWV2_types.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "mwmathutil.h"
#include "blas.h"
#include "rt_defines.h"
#define MODEL_NAME TST_RWSWV2
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (197) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (13)   
#elif NCSTATES != 13
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T ny3pcenmal [ 4 ] ; } guvq4wawov ; typedef struct {
real_T gaty2jlz2p [ 4 ] ; } pj0ihkypqf ; typedef struct { int8_T c5enzgh0ln ;
} hwtss1wbpv ; typedef struct { int8_T gmbejf1syu ; } f5ulhzmujf ; typedef
struct { real_T injnyz4auw ; } ksbim0l5cn ; typedef struct { real_T
kekyx2w2xd ; } a1psbvqfed ; typedef struct { real_T nkouc1qloz [ 4 ] ; }
m22jb12str ; typedef struct { real_T fdh2hm3qwy [ 4 ] ; } hkf1pxdbyl ;
typedef struct { real_T jgjuew1xpe [ 3 ] ; } a4l2akdomh ; typedef struct {
real_T gyjfwigx2h [ 9 ] ; } l5n2ev1vfg ; typedef struct { l5n2ev1vfg
mqozl5xj12 ; } fuvgor4n5v ; typedef struct { real_T apia2ki5qj [ 4 ] ; }
etjlh4l4yf ; typedef struct { int8_T p0optqqzsf ; } cv3otbwh2x ; typedef
struct { int8_T d343bhqapn ; } g4j2xx02c4 ; typedef struct { real_T
kfmst3u5d3 [ 3 ] ; } b2kmkl3wcw ; typedef struct { real_T otpij24kr0 [ 4 ] ;
} kzmuyenout ; typedef struct { real_T grgp0ja04k [ 3 ] ; } i2abnoyfrw ;
typedef struct { real_T ihykyxkclc [ 3 ] ; } gi1ufbotw1 ; typedef struct {
real_T elfsvtngpi [ 3 ] ; } pekwweku3r ; typedef struct { real_T pl0ikyvvgy [
3 ] ; } edmvwng2i4 ; typedef struct { real_T pcu42j55xs_mbvzarwird [ 1600 ] ;
real_T ooyuznughj_cl54gopm0x [ 1600 ] ; real_T dv [ 1600 ] ; real_T
m04ridjbke_kkiq3xxxve [ 1275 ] ; real_T pgqpd5ik4w_cxarnvbvui [ 1275 ] ;
real_T dv1 [ 1275 ] ; real_T p11ofm4mny [ 3 ] ; real_T lkurcisohk [ 3 ] ;
real_T kp2e2xb4cc ; real_T jfavnuvm3x ; real_T lgajxwyfuf [ 3 ] ; real_T
bbupnojfch [ 3 ] ; real_T f4iofc4dn5 ; real_T ewfw4ajeec ; real_T euvzemougu
; real_T jrebo5mrdq ; real_T mli0y4udzs ; real_T odftn2hv1u ; real_T
d2wjb40qki ; real_T bloxjw4yky [ 2 ] ; real_T ad2fwlvomc [ 9 ] ; real_T
dlialfoqve [ 3 ] ; real_T mt5ejwesnp [ 3 ] ; real_T ajt3i13qwt [ 3 ] ; real_T
k2m5cyjcxc ; real_T j5jwy3odai ; real_T m1xertokvw ; real_T h5tqcjnxlo ;
real_T dglspl4jb5 [ 3 ] ; real_T hzrrfqxhaf ; real_T ewdeweoohc ; real_T
hllg2hyyik ; real_T kcdpzzkbmw ; real_T b22cbxmnlr ; real_T jo115loilo ;
real_T d1ba11mu0x [ 2 ] ; real_T akmdakueie [ 2 ] ; real_T jcvum1cgbh ;
real_T kzqylxrze2 ; real_T fq0qegja2w ; real_T fouuflhqmj ; real_T i3roi2pfwn
; real_T arhxt0urom ; real_T lvq4s5cl0c ; real_T ceowdboxhi ; real_T
gekakniexb ; real_T ets2sd1cpy [ 3 ] ; real_T btzpl3o1sm [ 4 ] ; real_T
fogveq4aag [ 4 ] ; real_T msa15xsmdx [ 3 ] ; real_T eksoft0ukx [ 3 ] ; real_T
etpc1qwkkl [ 3 ] ; real_T l4bftekmh5 ; real_T jqoxdyrcpe [ 3 ] ; real_T
gfgjayhai0 [ 3 ] ; real_T eqejlpzyjk [ 3 ] ; real_T kpo0uqsydb ; real_T
lswkgkveua ; real_T j02du3klu3 [ 4 ] ; real_T ngqcqv0rct [ 3 ] ; real_T
pzsslt1caj ; real_T lirx01d5pq ; real_T ebsuxsvpmx ; real_T bkt40k0f2p ;
real_T ngdb14tcrd ; real_T dnw24xma2i ; real_T ol3bqwr21m ; real_T itueiehnrc
; real_T kvgnk3vwbl [ 528 ] ; real_T jywa2bcbgw [ 66 ] ; real_T gp0yss5tss [
66 ] ; real_T ogh5hr0p0j [ 22400 ] ; real_T nfpmyaudo5 [ 1600 ] ; real_T
lglaedtr5a [ 1600 ] ; real_T d5i5n2ctvl [ 17850 ] ; real_T eetng5atfq [ 1275
] ; real_T judoxslscy [ 1275 ] ; real_T afvb1ehg0t [ 2 ] ; real_T hyyusjwwd0
; real_T ialvqzftpg ; real_T pf0kn2talc ; real_T cucbrhyluc ; real_T
jv1d0qfy4m ; real_T a0ua2epli1 ; real_T j1syazdgd4 [ 528 ] ; real_T
gsgwdmkgku [ 66 ] ; real_T axbdr3x1fp [ 66 ] ; real_T ag3iipcuzh [ 22400 ] ;
real_T g22eqcolk1 [ 1600 ] ; real_T dw4fhg5i10 [ 1600 ] ; real_T hs0i1v4xen [
17850 ] ; real_T bpam2luzqr [ 1275 ] ; real_T muwbjqqbz2 [ 1275 ] ; real_T
gm45wrvmmz [ 2 ] ; real_T do0ide2rcv ; real_T jijwwtb0yp ; real_T nbtiislwyo
; real_T cqv5xbg1eo ; real_T h5tjg3ytfz ; real_T juh0nqufwc ; real_T
c2xk3hs0dm ; real_T hezxe4ft4m ; real_T ae4gpxobre ; real_T gli54111iq ;
real_T ml34nkrhlq ; real_T gkar21mdwf [ 528 ] ; real_T lu33o4w1r3 [ 66 ] ;
real_T drh3kx0c2g [ 66 ] ; real_T gbmpokz3zp [ 22400 ] ; real_T kyoy4xdfin [
1600 ] ; real_T ou1vh1l3du [ 1600 ] ; real_T mr1b0wzzg2 [ 17850 ] ; real_T
obucup33bh [ 1275 ] ; real_T bixz4y4cs3 [ 1275 ] ; real_T lem3rvqyps [ 2 ] ;
real_T exuyfpbwx3 ; real_T dyisgf03lw ; real_T iz3tczqrpq ; real_T fzk34rhf1c
; real_T fqejnq5fml ; real_T igqwt1yjrx ; real_T mokdwqn5tv ; real_T
jl0xq30mcu ; real_T f20ikslrr0 ; real_T kx5tkh0df0 ; real_T irruavepb4 ;
real_T harzibozpz ; real_T eawptovapg ; real_T oksalupnd3 ; real_T kjpznrcgig
; real_T f1xf35jyp4 [ 11 ] ; real_T hi1n54mcmc [ 11 ] ; real_T p3gpuz1pzd [
13 ] ; real_T lqzgmigds5 [ 13 ] ; real_T iqc2f25oqb ; real_T fqya1lnkpm ;
real_T kwlbg5jb4t ; real_T b0zlh5u3jc ; real_T d2klb5ahil ; real_T ntw01syjjc
; real_T oech2kz1cy ; real_T a3gezjtvdu ; real_T fpa3tundiw ; real_T
d0kea0dkjy ; real_T evxijl2a3r ; real_T kvihuxhnbc [ 4 ] ; real_T adgz4bd3kf
; real_T cig0wmtt3m ; real_T o21kbr4mgl ; real_T bmbl2eeqey ; real_T
mffykklb4e [ 169 ] ; real_T mkz3mctiwo [ 169 ] ; real_T pr4mmdkig3 [ 169 ] ;
real_T l5zqckp5ds [ 169 ] ; real_T clqi5421sn ; real_T orlxict5uw [ 169 ] ;
real_T kvglegmnr2 ; real_T n2aonouljp [ 169 ] ; real_T nrovnhknzx [ 13 ] ;
real_T dhcl5bwk3d ; real_T bxaxpwfsdh [ 13 ] ; real_T mqbqw1xcbl [ 13 ] ;
real_T o3ah3cxi2g [ 3 ] ; real_T l31i4u50oo [ 3 ] ; boolean_T lbv4bsnkdm ;
boolean_T czqjnchcew ; boolean_T eba45de2d3 ; boolean_T ctlrtezbkb ;
boolean_T kfzrwtoo11 ; boolean_T fmq50sce1p ; edmvwng2i4 evg4tqc010g ;
pekwweku3r noxmrm1w5fh ; gi1ufbotw1 b02oakwn4y ; gi1ufbotw1 f1ei3kfb3b ;
kzmuyenout pteoo54u1l ; kzmuyenout arkzj205og ; ksbim0l5cn kaatsalz40 ;
gi1ufbotw1 mb4psf2ogk ; i2abnoyfrw dtnb1odzgu ; gi1ufbotw1 esmxkiztnvh ;
i2abnoyfrw i2hoddpqqn ; i2abnoyfrw fl3fthyqxfw ; kzmuyenout o2egb43grn ;
kzmuyenout fzzz0da3bpm ; b2kmkl3wcw h3f4zqct5b ; pj0ihkypqf fy4zj3hhge ;
etjlh4l4yf kaa1h5fw2dm ; fuvgor4n5v evxgoynfhh1 ; a4l2akdomh lawi0f5r5l2 ;
hkf1pxdbyl lj0sp02vlxl ; m22jb12str bq3pldfcaqv ; ksbim0l5cn fbciyjdijrl ;
pj0ihkypqf cc3vamisq4t ; guvq4wawov i41uiun02b3 ; } B ; typedef struct {
real_T jbiuzi4aai [ 2 ] ; real_T ogsulvdfqo ; real_T o1a1coezrh [ 4 ] ;
real_T oghbzylezs ; real_T l31233tzs5 ; real_T oe4craxtsr ; real_T p3utuwbotk
; real_T m35wdbwfjk [ 169 ] ; real_T adfw0bsjev [ 169 ] ; real_T bdtrovn01a [
169 ] ; real_T bwjkpamfxw [ 169 ] ; real_T gwnmkcjbc1 [ 13 ] ; real_T
fa1es2nu0v ; real_T ii40oryl4u ; real_T krqhenkhky ; real_T fkzball0la ;
real_T pttppk3jcp ; real_T ay1crq4gjz ; real_T cws51k2ewn ; real_T d4vvv2k2v3
; real_T d2miu0jpen ; real_T bobp110c5u [ 4 ] ; real_T pxvqpp25ev ; real_T
f1l0npvonb [ 4 ] ; real_T hhrhjkqm2k ; real_T hy0scmn4pf [ 4 ] ; real_T
cqqd21gc1k ; real_T gomv25feag [ 4 ] ; struct { void * LoggedData ; }
p4bppyayaf ; struct { void * LoggedData [ 2 ] ; } aqkazdkkjm ; struct { void
* LoggedData [ 3 ] ; } pdpsn10pe2 ; struct { void * LoggedData [ 3 ] ; }
bswrru4emo ; struct { void * LoggedData [ 2 ] ; } fwxwh0v335 ; struct { void
* LoggedData [ 4 ] ; } bbbxj0wdhw ; struct { void * LoggedData [ 3 ] ; }
e1sqaw4ew1 ; struct { void * LoggedData ; } gzbqcsyzkc ; struct { void *
LoggedData ; } gtgmcfoi3f ; struct { void * LoggedData ; } dzb5en3ect ;
struct { void * LoggedData ; } id44yqi2er ; struct { void * LoggedData ; }
a1dzmttfkg ; struct { void * LoggedData ; } jm4yyjoxrc ; struct { void *
LoggedData ; } ghseczrajd ; struct { void * LoggedData ; } mqvqz0mc3o ;
struct { void * LoggedData ; } ffw1agfuzs ; struct { void * LoggedData ; }
jxvmg11z51 ; struct { void * LoggedData ; } kuevle4fk1 ; struct { void *
LoggedData ; } dj0y1a4rkp ; struct { void * LoggedData ; } anhptlbpor ;
struct { void * LoggedData ; } nys0j5xotg ; struct { void * LoggedData ; }
ot4oqlzgej ; struct { void * LoggedData ; } ajfa0dqrat ; struct { void *
LoggedData ; } gl2kjcpx0w ; struct { void * LoggedData ; } aexra1pda3 ;
struct { void * LoggedData ; } hg1ul0ders ; struct { void * LoggedData ; }
kl2yhyienj ; struct { void * LoggedData ; } bvz2m4kqbs ; struct { void *
LoggedData ; } fmcrmebkkc ; struct { void * LoggedData [ 10 ] ; } okwxiipreu
; struct { void * LoggedData [ 4 ] ; } jr141wnn22 ; struct { void *
LoggedData ; } owccnop0bp ; struct { void * LoggedData [ 2 ] ; } moa3truurv ;
void * l5porott1o ; void * emojxwu2oc ; void * eph5mfdrkn ; void * aubnmf0jim
; void * ceonvoxabs ; void * oeklz3vrcs ; void * ewbbr1445y ; void *
hvp123ipm0 ; void * no4z2mnrxf ; void * c0fqulldoy ; struct { void *
AQHandles ; void * SlioLTF ; } opv2domrvm ; int32_T jmztpvsjv0 ; int8_T
abs4jjv355 ; int8_T hxosnzpni0 ; int8_T pods3ngpuh ; int8_T dgi2ryavxf ;
int8_T ghsbqj1gdd ; int8_T fdkfwem5wv ; int8_T ottqmwv4ab ; int8_T mjjt5milxa
; int8_T dpoz2afmu5 ; int8_T c4fmxjrfvq ; int8_T ozdacijjrc ; int8_T
bjrkfcnwqe ; int8_T dgmhfl0ejy ; int8_T l4idmhenv4 ; int8_T g1gz2kwalm ;
int8_T hafmo2yjxp ; int8_T ehevun3t0d ; int8_T jub4qa0tx5 ; int8_T ouyhtippx4
; int8_T onw1kj0tt3 ; int8_T bqkqmfirk2 ; int8_T fob5v3qelm ; int8_T
a3mffltq2c ; int8_T khigjg54p1 ; int8_T kyqgjgbzfu ; int8_T c3fesmoiak ;
int8_T oyffazvwpp ; int8_T it5tygcmno ; int8_T o5lwvvqufc ; uint8_T
bahf1mm04g [ 6 ] ; boolean_T mdd3waf5u2 ; boolean_T hgodhfyuxy ; boolean_T
gzzht5dcba ; a1psbvqfed kaatsalz40 ; f5ulhzmujf etw3qygazq ; hwtss1wbpv
aoxobjloyv ; f5ulhzmujf cbgg0vjzsr ; hwtss1wbpv kvhpjeahvc ; g4j2xx02c4
kugkutdkkw ; cv3otbwh2x favglkmcha ; g4j2xx02c4 cuzz03aam2l ; cv3otbwh2x
ok5kaek4lxs ; f5ulhzmujf cpe4p1nzlo ; hwtss1wbpv f3bpn3lnkh ; f5ulhzmujf
fse3bizgct ; hwtss1wbpv ccrvxjn2zx ; a1psbvqfed fbciyjdijrl ; f5ulhzmujf
ausjujlz1d ; hwtss1wbpv ep1krdw3c3 ; f5ulhzmujf eu5kqssxx5u ; hwtss1wbpv
k3sfyh0c3kb ; } DW ; typedef struct { real_T e5l2wmdpfb [ 3 ] ; real_T
mes33bxk5w [ 3 ] ; real_T agflyx222j [ 3 ] ; real_T mqqxdp0em5 [ 4 ] ; } X ;
typedef struct { real_T e5l2wmdpfb [ 3 ] ; real_T mes33bxk5w [ 3 ] ; real_T
agflyx222j [ 3 ] ; real_T mqqxdp0em5 [ 4 ] ; } XDot ; typedef struct {
boolean_T e5l2wmdpfb [ 3 ] ; boolean_T mes33bxk5w [ 3 ] ; boolean_T
agflyx222j [ 3 ] ; boolean_T mqqxdp0em5 [ 4 ] ; } XDis ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct darponzt3g_ { real_T
Bias1_Bias ; real_T Bias_Bias ; } ; struct jz3icdjngh_ { real_T phi_Y0 ;
real_T Memory_InitialCondition ; real_T Constant1_Value ; int8_T
Switch_Threshold ; } ; struct odmcxr0cer_ { real_T position_Y0 ; real_T
ncf_IterationLimit ; } ; struct npiampupp5_ { real_T velocity_Y0 ; int32_T
ForIterator_IterationLimit ; } ; struct ihcbtoyfoc_ { real_T pci_Y0 ; real_T
Constant_Value ; real_T Constant1_Value [ 11 ] ; } ; struct ei12ezc1gi_ {
real_T position_Y0 ; odmcxr0cer kvr32gbyca ; } ; struct jhd2qraqgz_ { real_T
vci_Y0 ; real_T Gain_Gain ; real_T Gain1_Gain ; real_T Constant_Value ;
real_T Constant1_Value [ 10 ] ; real_T Constant2_Value ; } ; struct
cvvampj2zd_ { real_T velocity_Y0 ; int32_T ncm_IterationLimit ; npiampupp5
oy5rlkbq1z ; } ; struct P_ { struct_ZtKgq7qQgrOMpDzzLZ17RD DYN_ATT_par ;
struct_3OptKx60sX28Peciomd4EC DYN_SC_par ; struct_zvomUs9swg0LYolfrL6G0F
CONSTANTS_par ; struct_SSrbxNhDAwveKzBnq5y3AG DYN_TRA_par ;
struct_OQVIZ74DlhsweG9NoRv7dB DYN_AERO_par ; struct_XG5FAMxlkIOXT4puaiHssC
DYN_MAG_par ; struct_QshdnZq1fOlw6PdzPTqajC Checkepoch_ephConstants ; real_T
Normalization1_Bias ; real_T Normalization_Bias ; real_T
NRLMSISE00AtmosphereModel_action ; real_T JulianDateConversion_day ; real_T
JulianDateConversion_day_evmxw404ks ; real_T
JulianDateConversion_day_kmvymyt2gr ; real_T
JulianDateConversion_day_onhw3gbpmx ; real_T
JulianDateConversion_day_hqsimmntf5 ; real_T
JulianDateConversion_day_oibncvp13p ; real_T NRLMSISE00AtmosphereModel_flags
[ 23 ] ; real_T ECIPositiontoLLA_hour ; real_T
DirectionCosineMatrixECItoECEF_hour ; real_T ECIPositiontoLLA_hour_evxsy2hcpl
; real_T CheckAltitude_max ; real_T CheckLatitude_max ; real_T
CheckLongitude_max ; real_T Istimewithinmodellimits_max ; real_T
ECIPositiontoLLA_min ; real_T DirectionCosineMatrixECItoECEF_min ; real_T
ECIPositiontoLLA_min_dkkjuh05iq ; real_T CheckAltitude_min ; real_T
CheckLatitude_min ; real_T CheckLongitude_min ; real_T
Istimewithinmodellimits_min ; real_T CheckdeltaT_minmax [ 2 ] ; real_T
CheckdeltaT_minmax_iihlx1pzw0 [ 2 ] ; real_T CheckEpoch_minmax [ 2 ] ; real_T
CheckdeltaT_minmax_fu5tpc2tet [ 2 ] ; real_T CheckdeltaT_minmax_gtfjjd3va0 [
2 ] ; real_T JulianDateConversion_month ; real_T
JulianDateConversion_month_iotvngoujn ; real_T
JulianDateConversion_month_lojm1u4apm ; real_T
JulianDateConversion_month_a2eshsju1n ; real_T
JulianDateConversion_month_astih3gt22 ; real_T
JulianDateConversion_month_alwn00nkdo ; real_T Target_naMoon ; real_T
Center_naPlanet ; real_T Target_naPlanet ; real_T forpc_ncf ; real_T
forvc_ncf ; real_T forpc_ncf_ph3jlcz4wu ; real_T forvc_ncf_hr0ktg40xd ;
real_T forpc_ncf_af3025p2ex ; real_T forvc_ncf_fk2zw2hgit ; real_T
position_ncm ; real_T position_ncm_ptclloauod ; real_T
position_ncm_binq5apr4m ; real_T NRLMSISE00AtmosphereModel_oxygen_in ; real_T
ECIPositiontoLLA_sec ; real_T JulianDateConversion_sec ; real_T
JulianDateConversion_sec_jnhedb5ppd ; real_T
DirectionCosineMatrixECItoECEF_sec ; real_T
JulianDateConversion_sec_oypk4uawdh ; real_T
JulianDateConversion_sec_oc0zkhngk4 ; real_T ECIPositiontoLLA_sec_kfquz0jahd
; real_T JulianDateConversion_sec_dv4yi3hyps ; real_T
JulianDateConversion_sec_ehpmmr44me ; real_T LIB_ROT_MATINV_tol ; real_T
ECIPositiontoLLA_year ; real_T DirectionCosineMatrixECItoECEF_year ; real_T
ECIPositiontoLLA_year_hzfjhys0gc ; real_T LIB_ROT_QNORM_zero_tol ; real_T
pci_Y0 ; real_T Constant_Value ; real_T Constant1_Value [ 9 ] ; real_T
position_Y0 ; real_T vci_Y0 ; real_T Gain_Gain ; real_T Gain1_Gain ; real_T
Constant_Value_k0aahyxhxi ; real_T Constant1_Value_gtpo51gc3l [ 8 ] ; real_T
Constant2_Value ; real_T velocity_Y0 ; real_T Bias1_Bias ; real_T
Constant_Value_knu4z5qe0q ; real_T Gain_Gain_hwhx42bkkd ; real_T
Constant_Value_nykfggaff4 ; real_T pp13_Y0 [ 13 ] ; real_T
Constant_Value_b1kt1dquk2 ; real_T pp13_Y0_b320ukeyf3 [ 13 ] ; real_T
k1313_Value [ 169 ] ; real_T bpp_Y0 ; real_T UnitDelay1_InitialCondition [ 13
] ; real_T Constant_Value_fmdk3ml4vv ; real_T Constant1_Value_a5v5gggqhg ;
real_T Gain1_Gain_lsmxz1cifj ; real_T Gain2_Gain ; real_T
Constant_Value_orx13y04uz ; real_T Constant_Value_k3qkpci4uw ; real_T
Constant_Value_ky3cjgnuis ; real_T Switch_Threshold ; real_T
Switch1_Threshold ; real_T Constant_Value_lvn1oam4ik ; real_T
Constant1_Value_gaa0eg0oa1 ; real_T k1313_Value_ml2ak2adft [ 169 ] ; real_T
dp1313_Y0 [ 169 ] ; real_T snorm169_Y0 [ 169 ] ; real_T
UnitDelay_InitialCondition [ 169 ] ; real_T
UnitDelay1_InitialCondition_p1upzq1u1r [ 169 ] ; real_T Merge1_InitialOutput
; real_T Merge_InitialOutput ; real_T Gain_Gain_hcwuq2xoge ; real_T tc1313_Y0
[ 169 ] ; real_T UnitDelay_InitialCondition_gvr0gvtxcf [ 169 ] ; real_T
UnitDelay_InitialCondition_lns2pt5iyl [ 169 ] ; real_T cmaxdefmaxdef_Value [
169 ] ; real_T cdmaxdefmaxdef_Value [ 169 ] ; real_T
zerosmaxdef1maxdef1_Value [ 169 ] ; real_T bt_Y0 ; real_T bp_Y0 ; real_T
br_Y0 ; real_T bpp_Y0_fnr14vctj2 ; real_T Merge_InitialOutput_celikqymqe ;
real_T Merge1_InitialOutput_do1dtkc0vw ; real_T
UnitDelay1_InitialCondition_fhyfwa2bo2 ; real_T UnitDelay3_InitialCondition ;
real_T UnitDelay2_InitialCondition ; real_T UnitDelay4_InitialCondition ;
real_T Constant1_Value_najvdqclxi ; real_T fm_Value [ 13 ] ; real_T fn_Value
[ 13 ] ; real_T Constant1_Value_c13gpoqm0c ; real_T btbpbrbpp_Y0 [ 4 ] ;
real_T UnitDelay_InitialCondition_dcdbfk2ii1 ; real_T
UnitDelay2_InitialCondition_boysunw0mm [ 4 ] ; real_T r_Y0 ; real_T ct_Y0 ;
real_T st_Y0 ; real_T sa_Y0 ; real_T ca_Y0 ; real_T Gain_Gain_ng3bwimtlt ;
real_T a_Value ; real_T b_Value ; real_T Constant_Value_kgwutvsm35 ; real_T
sp11_Y0 [ 11 ] ; real_T cp11_Y0 [ 11 ] ; real_T ForIterator_IterationLimit ;
real_T UnitDelay1_InitialCondition_bu0v3y4mz0 ; real_T cpm1spm1_Threshold ;
real_T Constant_Value_ehjzuhujix [ 11 ] ; real_T Constant1_Value_ailex5mif3 [
11 ] ; real_T sp13_Y0 [ 13 ] ; real_T cp13_Y0 [ 13 ] ; real_T
Gain_Gain_oyuexaslet ; real_T Gain1_Gain_bckqcimlak ; real_T cp1_Value ;
real_T sp1_Value ; real_T Switch_Threshold_jy54w1qvbc ; real_T Kd_Gain ;
real_T Switch_Threshold_diu3nnmqns ; real_T BiasYear_Bias ; real_T
Gain_Gain_nnyck3ujwy ; real_T Bias1_Bias_jb4qn5y1yi ; real_T
Gain1_Gain_e0nbiop4h1 ; real_T Bias2_Bias ; real_T Gain2_Gain_ha2c5rnbap ;
real_T Gain3_Gain ; real_T BiasDay_Bias ; real_T Gain5_Gain ; real_T
Gain6_Gain ; real_T Gain4_Gain ; real_T Bias1_Bias_ji5kh02tmj ; real_T
Gain_Gain_n4zfmhpjdz ; real_T Gain_Gain_gwzumkg2ha ; real_T
BiasYear_Bias_d1bz4cwjem ; real_T Gain_Gain_nbkyysfa1j ; real_T
Bias1_Bias_jq03q5eepb ; real_T Gain1_Gain_khexcsxl3v ; real_T
Bias2_Bias_fpu32hl3sv ; real_T Gain2_Gain_pffca4otqi ; real_T
Gain3_Gain_jel0ucvuxl ; real_T BiasDay_Bias_pbwswhzoa4 ; real_T
Gain5_Gain_d4jo3mva53 ; real_T Gain6_Gain_bnnxaastma ; real_T
Gain4_Gain_i45flsg3or ; real_T Bias_Bias ; real_T Bias1_Bias_a5hamgvknt ;
real_T Gain_Gain_cy4gpaqjaz ; real_T Gain1_Gain_okow3nhbkn ; real_T Y0_Coefs
[ 6 ] ; real_T mMoon_Coefs [ 5 ] ; real_T mSun_Coefs [ 5 ] ; real_T
umMoon_Coefs [ 5 ] ; real_T dSun_Coefs [ 5 ] ; real_T omegaMoon_Coefs [ 5 ] ;
real_T Gain_Gain_anuil02gv5 ; real_T lMercury_Coefs [ 2 ] ; real_T
lVenus_Coefs [ 2 ] ; real_T lEarth_Coefs [ 2 ] ; real_T lMars_Coefs [ 2 ] ;
real_T lJupiter_Coefs [ 2 ] ; real_T lSaturn_Coefs [ 2 ] ; real_T
lUranus_Coefs [ 2 ] ; real_T lNeptune_Coefs [ 2 ] ; real_T pa_Coefs [ 3 ] ;
real_T Gain4_Gain_gob23x2gl0 ; real_T X0_Coefs [ 6 ] ; real_T
Gain3_Gain_nr4rdelyih ; real_T S0_Coefs [ 6 ] ; real_T Gain2_Gain_jynln5owt4
; real_T Gain5_Gain_c4ytvmivzm ; real_T Gain1_Gain_dhurlgsnhr ; real_T
Gain_Gain_o4i5m3le5k ; real_T Gain_Gain_ciwym1xe3o ; real_T
Switch1_Threshold_dixrx2rqvf ; real_T BiasYear_Bias_ekq2nttdv1 ; real_T
Gain_Gain_hlk0dlsuje ; real_T Bias1_Bias_jyp11st4jd ; real_T
Gain1_Gain_ij5fxr5f4u ; real_T Bias2_Bias_ldahvgkl0h ; real_T
Gain2_Gain_awbzl5swxl ; real_T Gain3_Gain_gcrs4a5en3 ; real_T
BiasDay_Bias_iyjzgz1krp ; real_T Gain5_Gain_lrl4u1x0vd ; real_T
Gain6_Gain_mqy3djvdly ; real_T Gain4_Gain_amkvwtlsmf ; real_T
Bias1_Bias_onjh0xywa3 ; real_T Gain_Gain_oej452fzct ; real_T
Gain_Gain_ndkkslk451 ; real_T BiasYear_Bias_imsh3ixp5m ; real_T
Gain_Gain_dzc5eq4jde ; real_T Bias1_Bias_bkfwxcvhlr ; real_T
Gain1_Gain_nqjbd4cvsr ; real_T Bias2_Bias_eu1ohcctud ; real_T
Gain2_Gain_l4tmhxbslq ; real_T Gain3_Gain_c5kepxotnq ; real_T
BiasDay_Bias_lsy34iafjp ; real_T Gain5_Gain_i2whnjgqrb ; real_T
Gain6_Gain_iu4xfjvn3q ; real_T Gain4_Gain_gionsmqgjc ; real_T
Bias_Bias_n53vi0dm2i ; real_T Bias1_Bias_k3tkuodmxy ; real_T
Gain_Gain_pfmppwunjf ; real_T Gain1_Gain_bnnhkcipw4 ; real_T
Y0_Coefs_bwrgfw3tef [ 6 ] ; real_T mMoon_Coefs_cidt3skfqi [ 5 ] ; real_T
mSun_Coefs_axhju4mj5r [ 5 ] ; real_T umMoon_Coefs_le3esxmyqt [ 5 ] ; real_T
dSun_Coefs_f3irhysq0t [ 5 ] ; real_T omegaMoon_Coefs_j5eu514zo1 [ 5 ] ;
real_T Gain_Gain_m2mgem3n4b ; real_T lMercury_Coefs_obscuuka2n [ 2 ] ; real_T
lVenus_Coefs_cx2zgmgsf0 [ 2 ] ; real_T lEarth_Coefs_d42olao44d [ 2 ] ; real_T
lMars_Coefs_pyrwksj5dw [ 2 ] ; real_T lJupiter_Coefs_gygbwhbo5q [ 2 ] ;
real_T lSaturn_Coefs_mcg0rrj2nd [ 2 ] ; real_T lUranus_Coefs_dx42eubvi2 [ 2 ]
; real_T lNeptune_Coefs_l1hxb3q0ll [ 2 ] ; real_T pa_Coefs_le1r1fm4yh [ 3 ] ;
real_T Gain4_Gain_pmnkzgmte0 ; real_T X0_Coefs_n5lp2rc1aa [ 6 ] ; real_T
Gain3_Gain_i1ru15t2mc ; real_T S0_Coefs_inc4sr1jg5 [ 6 ] ; real_T
Gain2_Gain_apmnxrfk2y ; real_T Gain5_Gain_aysc4s0m2h ; real_T
Gain1_Gain_nh5jhddhzf ; real_T BiasYear_Bias_plir0mxcin ; real_T
Gain_Gain_bjloitegmg ; real_T Bias1_Bias_lvr30dnevt ; real_T
Gain1_Gain_p2ht4xvqkz ; real_T Bias2_Bias_fje2l0fkwy ; real_T
Gain2_Gain_jnf0iavht0 ; real_T Gain3_Gain_f5ijzu0fzz ; real_T
BiasDay_Bias_hraprfl4su ; real_T Gain5_Gain_oi0yu20axd ; real_T
Gain6_Gain_czvyggzlcz ; real_T Gain4_Gain_ewzhaucagg ; real_T
Bias1_Bias_nj42g2wgiy ; real_T Gain_Gain_kptdtjyalj ; real_T
Gain_Gain_bv02jx33w5 ; real_T BiasYear_Bias_bmaluhvoe0 ; real_T
Gain_Gain_iv3vbucwzk ; real_T Bias1_Bias_jonuus30ns ; real_T
Gain1_Gain_nvuiwxw25a ; real_T Bias2_Bias_otf22zkp2b ; real_T
Gain2_Gain_p0xkrfvhky ; real_T Gain3_Gain_aoqhdoyxj4 ; real_T
BiasDay_Bias_grhohsed3v ; real_T Gain5_Gain_ah5345mcbz ; real_T
Gain6_Gain_cyiidsiez4 ; real_T Gain4_Gain_dqsev3qffw ; real_T
Bias_Bias_ixjbzntfcs ; real_T Bias1_Bias_dtr0arjo0k ; real_T
Gain_Gain_jz5ez0s5hy ; real_T Gain1_Gain_dhqy2eebus ; real_T
Y0_Coefs_ix5v1tp13f [ 6 ] ; real_T mMoon_Coefs_nxqjw1har2 [ 5 ] ; real_T
mSun_Coefs_bmvjcmjux3 [ 5 ] ; real_T umMoon_Coefs_kgcdo5cdpi [ 5 ] ; real_T
dSun_Coefs_gdwpgdottt [ 5 ] ; real_T omegaMoon_Coefs_eawixivbxh [ 5 ] ;
real_T Gain_Gain_jfjijmjqlv ; real_T lMercury_Coefs_pybetdv4eb [ 2 ] ; real_T
lVenus_Coefs_hv3qo3uo3w [ 2 ] ; real_T lEarth_Coefs_j0mivuewpj [ 2 ] ; real_T
lMars_Coefs_min3puad3h [ 2 ] ; real_T lJupiter_Coefs_hq4twgfzoz [ 2 ] ;
real_T lSaturn_Coefs_nvzevagca4 [ 2 ] ; real_T lUranus_Coefs_fxaxpx10pt [ 2 ]
; real_T lNeptune_Coefs_gkf5ct5aik [ 2 ] ; real_T pa_Coefs_cmmkm3cgb1 [ 3 ] ;
real_T Gain4_Gain_kkmqinuqik ; real_T X0_Coefs_lglvj03zib [ 6 ] ; real_T
Gain3_Gain_dyx0cwehu4 ; real_T S0_Coefs_bgrvsqinkr [ 6 ] ; real_T
Gain2_Gain_gxogzjcxes ; real_T Gain5_Gain_m32aql5ryf ; real_T
Gain1_Gain_o2ge0niozb ; real_T Gain_Gain_b3c3odkt2h ; real_T
otime_InitialCondition ; real_T u80deg_UpperSat ; real_T u80deg_LowerSat ;
real_T u0deg_UpperSat ; real_T u0deg_LowerSat ; real_T olon_InitialCondition
; real_T olat_InitialCondition ; real_T uto1000000m_UpperSat ; real_T
uto1000000m_LowerSat ; real_T Gain_Gain_fazk34pq1p ; real_T
oalt_InitialCondition ; real_T nTtoT_Gain ; real_T k1_Gain ; real_T k_Gain ;
real_T k2_Gain ; real_T nTtoT1_Gain ; real_T Gain_Gain_moxmp2rie1 ; real_T
Gain_Gain_i5aw4tqqra ; real_T Bias_Bias_flmqlfoqqk ; real_T
Bias1_Bias_pmxtjmxgto ; real_T Bias2_Bias_olz25eww2t ; real_T Bias3_Bias ;
real_T Gain_Gain_f4w25nzgog ; real_T Bias_Bias_p0shme04zp ; real_T
Gain_Gain_c30u4o0enn ; real_T Bias_Bias_pi2fgfnx13 ; real_T
Gain_Gain_f5xiu22kap ; real_T Bias_Bias_glx5rwigzp ; real_T
Bias_Bias_nkpxz13mna ; real_T Index_Value ; real_T sec2_Value [ 4 ] ; real_T
secGain_Gain ; real_T Constant_Value_bu55wk5sux ; real_T
Index_Value_ggtv1dsxam ; real_T sec2_Value_cqhhxc22cp [ 4 ] ; real_T
gainVal_Gain ; real_T Constant_Value_b2ijke2zch ; real_T
Constant_Value_fijgkcnnhd ; real_T Constant_Value_jg4kuwigu3 [ 726 ] ; real_T
Constant1_Value_cnmjmk0drt [ 33 ] ; real_T Constant2_Value_bxt5wo0uzz [ 3 ] ;
real_T Constant3_Value [ 25 ] ; real_T Constant4_Value [ 4 ] ; real_T
Constant_Value_b3j4g0lv2s [ 27200 ] ; real_T Constant1_Value_pnm1ckjvfq [
1306 ] ; real_T Constant2_Value_cjuzfuud4o [ 253 ] ; real_T
Constant3_Value_ojlaqcqlx0 [ 36 ] ; real_T Constant4_Value_o2xaxjmbtv [ 4 ] ;
real_T Constant_Value_blhzdoapdh [ 21675 ] ; real_T
Constant1_Value_oxaayczkra [ 962 ] ; real_T Constant2_Value_dxyf22cczo [ 277
] ; real_T Constant3_Value_lsq3lhwfbz [ 30 ] ; real_T
Constant4_Value_jzbjzkfov2 [ 5 ] ; real_T Constant_Value_hfl0axy5vc ; real_T
Constant1_Value_dacsesdqm3 [ 2 ] ; real_T Gain1_Gain_b53uubhwtd ; real_T
Constant_Value_j1ranlmwoh ; real_T Constant_Value_p1a403vys0 ; real_T
Constant1_Value_mfchg4r0gl ; real_T Constant1_Value_kkksjwcunb ; real_T
f_Value ; real_T Constant_Value_bvi4us34ks ; real_T Constant_Value_i0bsfym50v
; real_T aph_Value [ 7 ] ; real_T f107_Value ; real_T f107a_Value ; real_T
lst_Value ; real_T AddParam_Value [ 2 ] ; real_T deltaAT_Value ; real_T
Bias_Bias_hn0u5qqmwi ; real_T Index_Value_glfdv0gwi4 ; real_T
sec2_Value_jhtvjuwtd3 [ 4 ] ; real_T deltaUT1_Value ; real_T
secGain_Gain_epta5goh22 ; real_T Constant_Value_ksu35oenhl ; real_T
Index_Value_i2ivw01z5k ; real_T sec2_Value_pis0t02q3n [ 4 ] ; real_T
gainVal_Gain_chmu2i0axw ; real_T Constant_Value_ahtudx4mbv ; real_T
Constant_Value_m3svuae4lu ; real_T Constant_Value_cavkjd5ie3 [ 726 ] ; real_T
Constant1_Value_ouz0cwj015 [ 33 ] ; real_T Constant2_Value_joqtm3i1ro [ 3 ] ;
real_T Constant3_Value_pzheezzrpb [ 25 ] ; real_T Constant4_Value_etf5cd0qfd
[ 4 ] ; real_T Constant_Value_gty3wyfcoq [ 27200 ] ; real_T
Constant1_Value_fzzob5xizj [ 1306 ] ; real_T Constant2_Value_fx323wtlke [ 253
] ; real_T Constant3_Value_jtxiecy3de [ 36 ] ; real_T
Constant4_Value_baft5zrjbw [ 4 ] ; real_T Constant_Value_pdipd1st4u [ 21675 ]
; real_T Constant1_Value_dwv0tsukpb [ 962 ] ; real_T
Constant2_Value_p0ikssuc2q [ 277 ] ; real_T Constant3_Value_kvliqvxsps [ 30 ]
; real_T Constant4_Value_pe1oc2ribg [ 5 ] ; real_T Constant_Value_dkayhkb1ee
; real_T Constant1_Value_dvynw02bvl [ 2 ] ; real_T PolarMotion_Value [ 2 ] ;
real_T Gain1_Gain_ebugzibmgy ; real_T Epoch_Value ; real_T
Constant3_Value_bohdsdpayz ; real_T Bias1_Bias_j2z3znjcsz ; real_T
Bias1_Bias_bvg1k5rg0f ; real_T Constant1_Value_bmlo5uuj5h [ 3 ] ; real_T
Constant3_Value_ftxntawgwq ; real_T Bias1_Bias_g55s220pw2 ; real_T
Bias1_Bias_lzvtas1qzq ; real_T Constant3_Value_nntqaqmg1d ; real_T
Bias1_Bias_gv1ss5ckfh ; real_T Bias1_Bias_mpyutg2drp ; real_T
Constant_Value_evtvygkdoz [ 3 ] ; real_T kmflag_Value ; real_T
Bias_Bias_cjcrgmv0l3 ; real_T Index_Value_fz3uncvddf ; real_T
sec2_Value_nqa3admmuu [ 4 ] ; real_T secGain_Gain_oylue433r5 ; real_T
Constant_Value_feix0nt3zl ; real_T Index_Value_c2zywt0j1o ; real_T
sec2_Value_nvuz4xt0x0 [ 4 ] ; real_T gainVal_Gain_bwdhfpid4p ; real_T
Constant_Value_lct454zdoq ; real_T Constant_Value_njviyc3nu4 ; real_T
Constant_Value_gzvtnl3xxy [ 726 ] ; real_T Constant1_Value_kyneefazaj [ 33 ]
; real_T Constant2_Value_fkw2fr2rm3 [ 3 ] ; real_T Constant3_Value_k3nllpa1ws
[ 25 ] ; real_T Constant4_Value_arfcxix1wb [ 4 ] ; real_T
Constant_Value_g4grteekgh [ 27200 ] ; real_T Constant1_Value_jvyjyvnzqm [
1306 ] ; real_T Constant2_Value_fsrlndd3tn [ 253 ] ; real_T
Constant3_Value_jv1j31hcrt [ 36 ] ; real_T Constant4_Value_jczevvz331 [ 4 ] ;
real_T Constant_Value_mbu4gju5a1 [ 21675 ] ; real_T
Constant1_Value_gp2wuzxkly [ 962 ] ; real_T Constant2_Value_ibjkl43lcg [ 277
] ; real_T Constant3_Value_de40muvaty [ 30 ] ; real_T
Constant4_Value_fkcwiksbzk [ 5 ] ; real_T Constant_Value_b3n1xwnzjr ; real_T
Constant1_Value_f43klkerwg [ 2 ] ; real_T Gain1_Gain_dvdyrqq1on ; real_T
Constant_Value_om4mc214qr ; real_T Constant_Value_dpnq5xi00x ; real_T
Constant1_Value_pkdueqdvo3 ; real_T Constant1_Value_d2dwd3eskx ; real_T
f_Value_d44rnukv0h ; real_T Constant_Value_ctduzx5i1o ; real_T
Constant_Value_pbi1wqbyik ; real_T epoch_Value ; real_T re_Value ; real_T
JDepoch_days_Value ; real_T Gain1_Gain_ow0iqmdqvl ; int32_T
ncm_IterationLimit ; int32_T Constant_Value_cqtnx0odgv ; int32_T
Constant1_Value_gvjahuuruw ; int32_T Constant_Value_n2ukulrcmg ; int32_T
Gain_Gain_kqxmnucevh ; int32_T Constant_Value_aqysgafcrf ; int32_T
Gain_Gain_owuluxfoqk ; int32_T Constant_Value_jcfcwioaqx ; int32_T
Gain_Gain_byj5eqpbwj ; int32_T Constant1_Value_ex4jpy2wye ; int32_T
Constant_Value_basbfgiofe ; int32_T Constant_Value_ouqub0qmct ; int32_T
Constant1_Value_cpkffern4z ; int32_T Constant1_Value_fcslbbq5ce ; int32_T
Constant1_Value_auw1c2xpx2 ; int32_T Gain_Gain_aaddldlmbp ; int32_T
Constant_Value_khatmokwmu ; int32_T Constant_Value_ncpxwdetam ; int32_T
Constant_Value_arjprafmwa ; int32_T Constant1_Value_najrv2muau ; int32_T
Constant_Value_eqqxeofgkc ; int32_T tc_old_Threshold ; int32_T
Gain_Gain_amt1zrm0bg ; int32_T Constant_Value_hi2pwwd3bg ; int32_T
Constant1_Value_dihg20h40t ; int32_T Constant_Value_cuqs0rinpz ; int32_T
Constant_Value_klmtx5qfsr ; int32_T Constant_Value_lm1w3twn51 ; int32_T
ForIterator_IterationLimit_guhgs4an2s ; int32_T arn_Threshold ; int32_T
Constant_Value_af3lptv0f0 ; jz3icdjngh kaatsalz40 ; darponzt3g aoxobjloyv ;
darponzt3g kvhpjeahvc ; cvvampj2zd c4u0lt4ut5 ; jhd2qraqgz kugkutdkkw ;
ei12ezc1gi mjf0gtqzjp ; ihcbtoyfoc favglkmcha ; cvvampj2zd ouhnihomlde ;
jhd2qraqgz cuzz03aam2l ; ei12ezc1gi fq0ya2wvxmr ; ihcbtoyfoc ok5kaek4lxs ;
npiampupp5 lokzlwunnrr ; odmcxr0cer l4lx4n4let5 ; darponzt3g f3bpn3lnkh ;
darponzt3g ccrvxjn2zx ; jz3icdjngh fbciyjdijrl ; darponzt3g ep1krdw3c3 ;
darponzt3g k3sfyh0c3kb ; } ; extern const char * RT_MEMORY_ALLOCATION_ERROR ;
extern B rtB ; extern X rtX ; extern DW rtDW ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * TST_RWSWV2_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
