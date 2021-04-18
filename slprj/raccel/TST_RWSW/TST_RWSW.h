#ifndef RTW_HEADER_TST_RWSW_h_
#define RTW_HEADER_TST_RWSW_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef TST_RWSW_COMMON_INCLUDES_
#define TST_RWSW_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "TST_RWSW_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "blas.h"
#include "rtGetInf.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#define MODEL_NAME TST_RWSW
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (602) 
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
typedef struct { int8_T j4omgsrsfr ; } k4w2om5spu ; typedef struct { int8_T
k2tbsd51jk ; } lzsl4d3ncw ; typedef struct { real_T pmiuvoq3bk ; } k503avwxjn
; typedef struct { real_T lodlplndji ; } kwb1dp5oh3 ; typedef struct { real_T
nm24payncx [ 4 ] ; } e42udnywi5 ; typedef struct { real_T ehs4r2hz2y [ 3 ] ;
} pwekmvsjkf ; typedef struct { real_T cmzu1jjbu1 [ 4 ] ; } f5p4lyabrn ;
typedef struct { real_T do5ugpkgof [ 4 ] ; } ih3fopwm3i ; typedef struct {
real_T nkm03paxwo [ 3 ] ; } o41qhtemcd ; typedef struct { real_T nxsqtyhezz [
9 ] ; } oj1osi3mrn ; typedef struct { oj1osi3mrn ivoxddha1s ; } cvp4al0icj ;
typedef struct { real_T ekmxe1wuqt [ 4 ] ; } jf3t2hxsbw ; typedef struct {
real_T jtgcw4sbk0 [ 4 ] ; } d3abumwlqi ; typedef struct { real_T gafarm32k2 [
3 ] ; } aa02bbdgo4 ; typedef struct { real_T bogcyvs5ln [ 3 ] ; } nla0xfnlgl
; typedef struct { real_T gzi3omxt3y [ 3 ] ; } cqptmcnrgi ; typedef struct {
real_T mbuf3ttyoj ; real_T hxtmxsk1r0 ; real_T f4wdtbi41r ; real_T pwktwrqihs
[ 4 ] ; real_T eylpy53wuw ; real_T mhu3lkxx2s [ 4 ] ; real_T bk4wge0g1b ;
real_T jvjueq3cte [ 4 ] ; real_T pmf1oqvthd [ 4 ] ; real_T khkmvj0ylx ;
real_T lfsxpbmqdv ; real_T huld2q2tsx ; real_T g2sezxeq2k ; real_T gniutc4hwr
; real_T mfnhetnqeo ; real_T at0dtswx00 ; real_T dlirszzxgg ; real_T
cz2v4vvp2n ; real_T hdu0h34vcb ; real_T mhpfazun14 ; real_T cb3r40lwqu [ 3 ]
; real_T dftfd1z0ex [ 9 ] ; real_T fulaf1ayid ; real_T kjvdimqymn [ 4 ] ;
real_T cig0rl2lyw [ 4 ] ; real_T ddzjlmailu [ 4 ] ; real_T pfz3ztc0aa ;
real_T cptpe15cmc ; real_T anscqj5wy0 ; real_T b3yl3z2rka ; real_T oyzvd1f5ao
; real_T h0tiwbztwo ; real_T chb3eqlmms ; real_T eyb331g3p5 ; real_T
pam2p3b0ad ; real_T bfxopgu15t ; real_T fic4arbej2 ; real_T d0cdubtpzj ;
real_T gg1oewnt1e ; real_T m2aqnjsjrj [ 3 ] ; real_T g1k5nkpeqc [ 9 ] ;
real_T ggb00pezms ; real_T j3qs3rtxbi [ 277 ] ; real_T pw4jsriyp1 [ 277 ] ;
real_T kfexapzgyq [ 30 ] ; real_T dnk13ajoih ; real_T juyq5mtkcv [ 30 ] ;
real_T ojkqeip3ax [ 5 ] ; real_T c0u5fnz03z ; real_T loucsklpgo [ 5 ] ;
real_T k25mqcg024 ; real_T mijk0jy3sa ; real_T hfdypcubls ; real_T esfcef3azq
; real_T mn3s24s3fm ; real_T pshojpczoz ; real_T bylf4abebi [ 5 ] ; real_T
jxbg2l2dpg ; real_T a5zapblmlm ; real_T ksuihwdjar ; real_T chrfbb5slz ;
real_T dy53a5i4is ; real_T hgtydaf3wb ; real_T b0ye04xznx ; real_T e1a0f24tac
; real_T mi0kf0nlq1 ; real_T iy3g4iiyx4 [ 14 ] ; real_T ocpmool2nu [ 1275 ] ;
real_T pye21wjxiw [ 1275 ] ; real_T mtxqqdefaw [ 1275 ] ; real_T j3jqtykmpk [
1275 ] ; real_T ek4mj4efp0 ; real_T dwwgcalsvu ; real_T gx5j4ct1re ; real_T
ci2by4lmgt ; real_T cunu5mdzng ; real_T dt2yrgmbaw [ 253 ] ; real_T
h3ldrmwz0b [ 253 ] ; real_T cddpx32jsg [ 36 ] ; real_T ojluphtxxy ; real_T
gqd3rauuos [ 36 ] ; real_T b0kerzcyjt [ 4 ] ; real_T gtyhy2ohqs ; real_T
j1aaxufdsc [ 4 ] ; real_T anf1qrweu5 ; real_T k0nwwxnjlb [ 1600 ] ; real_T
gqcueq3quv [ 1600 ] ; real_T kmawkdgie3 [ 1600 ] ; real_T mjdl5wxrno [ 1600 ]
; real_T ejeeb2lpaq ; real_T hcyqujov3f ; real_T lm1hmpqqev ; real_T
ejp4cdox4v ; real_T jcawbpdl3k ; real_T o2cqohhb5c ; real_T aev5oguouy ;
real_T fmxwlh45zk ; real_T a3fxqbdoc2 [ 3 ] ; real_T p0yx405sxq [ 3 ] ;
real_T d1fpbrwfhb [ 25 ] ; real_T ivwsn315e4 ; real_T nieusgoeqj [ 25 ] ;
real_T kz2hijpe2h [ 4 ] ; real_T k124dm0xlv ; real_T cktaicpds5 [ 4 ] ;
real_T bj3em3wxmz ; real_T b3nffv5x1e [ 8 ] ; real_T ft0uwvnwf5 [ 66 ] ;
real_T jfqolzrdei [ 66 ] ; real_T ohi0wofqpa [ 66 ] ; real_T idkgjvvbkw [ 66
] ; real_T dnqnvk3id0 ; real_T kku0y3djhe ; real_T b4xys0hny1 ; real_T
pnplagmggb ; real_T blpvfajcob ; real_T jmeheyx5wd ; real_T dk4w0dsybe ;
real_T lmx1lmqzrw ; real_T cprds4vjro [ 3 ] ; real_T jcwg21yjxx [ 9 ] ;
real_T l1qtdzo5qs [ 9 ] ; real_T hzfvnqhqh4 [ 3 ] ; real_T kahiazkhjq [ 3 ] ;
real_T alojqq4waj ; real_T dq4ghxvamu ; real_T iv1obja41p ; real_T bgphx4r2ap
; real_T mkutzgjcja ; real_T kj4a4skaqt ; real_T bgmsguohbo ; real_T
ogdbiskhax ; real_T lplpcks1xr ; real_T hlblpeadwl ; real_T haub2ujqzk ;
real_T a34kq0qnht ; real_T na202onqkw [ 3 ] ; real_T fvzcriyu2k ; real_T
azz1yrsj30 ; real_T b55xgieqba ; real_T dqm0kbpewz [ 2 ] ; real_T otj1lt2fyb
[ 9 ] ; real_T kmoplxzlxz [ 8 ] ; real_T mfk4darvmz [ 9 ] ; real_T g1i4pov3fb
[ 3 ] ; real_T oohaox0ofe ; real_T pyqk4ufp53 ; real_T ggvanenkks ; real_T
esq14j0ci4 [ 3 ] ; real_T dlf3gf11iq [ 3 ] ; real_T h20r5jewxu ; real_T
fib5r0ervc [ 4 ] ; real_T eu1nemp2kx [ 4 ] ; real_T il51pe3lbo [ 4 ] ; real_T
psddpbcsbo ; real_T c3fw2cjyqe ; real_T dfsexdekjn ; real_T edm2r4bopy ;
real_T ihmxg05jq2 ; real_T d14sd1spcd ; real_T pj1tyqws1q ; real_T jo1znsl5t1
; real_T bhrxinv1w4 ; real_T dm2o2p1lc4 ; real_T lemqdujdtt ; real_T
dghprq20g3 [ 3 ] ; real_T fjiyyvaugo [ 9 ] ; real_T ifwzxts3py ; real_T
izmkrq2px5 [ 4 ] ; real_T meg2w5bizp [ 4 ] ; real_T oju5efmo34 [ 4 ] ; real_T
btpnvv5r13 ; real_T kvotuhl1zl ; real_T nzbd5ihkko ; real_T m4jvoihqrw ;
real_T is4mkewv1b ; real_T hxqcavcwua ; real_T fuwwapn1xa ; real_T kgo0mhc5nv
; real_T b3iuwc5zih ; real_T kvzow0nzav ; real_T ax1elxl2af ; real_T
hbcseuiqv1 ; real_T nlvrugau3g ; real_T oxspixiypd [ 3 ] ; real_T obxsdxvebf
[ 9 ] ; real_T h14powxwoq ; real_T adnsiqq2dm [ 277 ] ; real_T f35oij5vwg [
277 ] ; real_T ndlhvo3dyr [ 30 ] ; real_T lrbpscjc5u ; real_T pxi1bjg1g4 [ 30
] ; real_T jmdg0cvfrp [ 5 ] ; real_T eb5rjonudc ; real_T dpyla2yxww [ 5 ] ;
real_T iu5lzrgxsp ; real_T k4vkef0d22 ; real_T kzkglygxvh ; real_T j1bfbdcgsv
; real_T l3wuaxnxut ; real_T n1sqhnkie1 ; real_T bxueqfeu55 [ 5 ] ; real_T
cgpbdfxjn1 ; real_T epfzdghm10 ; real_T ft0z0s4aqu ; real_T fpjnzmjefc ;
real_T g5vytyje2h ; real_T cvfz50cwau ; real_T ewxwkkl5da ; real_T ao0glnhvoj
; real_T ackvpr0z3u ; real_T czcmpilucx [ 14 ] ; real_T icgnte4qpu [ 1275 ] ;
real_T fbvatilagf [ 1275 ] ; real_T jkznnytsnd [ 1275 ] ; real_T dl4v0kmdgn [
1275 ] ; real_T pqctaujvgo ; real_T l5lcc4xttr ; real_T ewumm1020z ; real_T
fu0xgsqmwl ; real_T maoihm1jvn ; real_T aoao3w0eik [ 253 ] ; real_T
alyqymjndu [ 253 ] ; real_T kw5rtltfk0 [ 36 ] ; real_T ggzu4svw5t ; real_T
p2ozldg0jj [ 36 ] ; real_T dzmi0pkdb0 [ 4 ] ; real_T mhxp0yhl3s ; real_T
jqcdjat5ix [ 4 ] ; real_T fgvxet2oux ; real_T ptm33kspwu [ 1600 ] ; real_T
pyvkiskhah [ 1600 ] ; real_T m0vxd3rvog [ 1600 ] ; real_T l2s0i5fm5h [ 1600 ]
; real_T mcp1wxjj5w ; real_T nlfpuwtzr5 ; real_T kqsiph1ehy ; real_T
jfgmo4o2up ; real_T bjevpalkzl ; real_T nxb04j0yva ; real_T a2b3wwkimh ;
real_T os1rarrsrr ; real_T jsrj0v34ul [ 3 ] ; real_T arfcpmaykn [ 3 ] ;
real_T hgcuynlons [ 25 ] ; real_T k104yccunc ; real_T ijx5xzvxig [ 25 ] ;
real_T dyfmpxj3ck [ 4 ] ; real_T fzmd1gnkjj ; real_T hbjigi0xxg [ 4 ] ;
real_T ezjkzzqpsv ; real_T fmdigjnac2 [ 8 ] ; real_T miunog0axq [ 66 ] ;
real_T du2d0zc4qu [ 66 ] ; real_T gkyovuu3aw [ 66 ] ; real_T nlpb2qzl3l [ 66
] ; real_T gop12iuzpq ; real_T fsryokpcdy ; real_T pslqjgdapi ; real_T
jsqufalwzt ; real_T d10chwuyqe ; real_T kfllrbq4fx ; real_T nawdlquz5z ;
real_T i0ney05wxx ; real_T jz2wzvcqsl [ 3 ] ; real_T fkhy5353dd [ 9 ] ;
real_T emfuz3ubwz [ 9 ] ; real_T kqaoyphs3d [ 3 ] ; real_T cufcoe2lw0 [ 3 ] ;
real_T f3zlxaswiq [ 3 ] ; real_T k13h5jbvy1 ; real_T n3k1ob3xmx ; real_T
m5hmz43bo1 ; real_T n5mij1y5vn ; real_T pg1djboonx ; real_T ch1525kggw ;
real_T nmtuh2ebbi [ 3 ] ; real_T opfb3c3zmg [ 3 ] ; real_T h0udz1lb32 [ 3 ] ;
real_T lmiox3ymu0 [ 3 ] ; real_T k5tl50qmt2 ; real_T kelhke2kzj ; real_T
ik0l3bbokb ; real_T ihrru2lok0 ; real_T jt3qqeoksu [ 4 ] ; real_T gomgada3tp
; real_T bchm14jynu [ 4 ] ; real_T oeonbo5wiu [ 4 ] ; real_T jcwv54bt5g ;
real_T givjyfbihc ; real_T mzs0l31kl4 ; real_T fh4044woqy ; real_T fvqajiieaf
; real_T ojgkh1ufyo ; real_T bpi5ji4ru4 ; real_T dijekv3sgz ; real_T
db2rrc0lim ; real_T bjskyfp2d2 ; real_T iyjspgwu2k ; real_T llimplwwny [ 3 ]
; real_T ibcdw3x2ct [ 9 ] ; real_T b5owf0343w ; real_T lwpxz30c2m [ 4 ] ;
real_T plrbsgnpf3 [ 4 ] ; real_T a5fkzjoruy [ 4 ] ; real_T adk4hpyanr ;
real_T n52wovcqpw ; real_T oz3sdgz4se ; real_T jkjdxfb5pu ; real_T gkxtpmrveh
; real_T mh5r3c5rbk ; real_T cpzufd55v4 ; real_T kjh05ehjak ; real_T
kgspknbz4q ; real_T l0spyqlnju ; real_T f4xismy11n ; real_T cvgtcoepc0 ;
real_T or0rtimhyl ; real_T d2rz3rfikp [ 3 ] ; real_T ghml2vzc1i [ 9 ] ;
real_T ptvwzl42uo ; real_T exvdt03ija [ 277 ] ; real_T dlix0rrcbv [ 277 ] ;
real_T gpwnegfrzn [ 30 ] ; real_T e04iqkf4nx ; real_T ooe1dsmblv [ 30 ] ;
real_T f1bb1owktv [ 5 ] ; real_T kpn540m4nj ; real_T fko3lxf0hl [ 5 ] ;
real_T nxwznbqhbl ; real_T hi1gg5qnn1 ; real_T jffr4vztjz ; real_T cmkynrmz0q
; real_T lkciksoosk ; real_T od3egvwk5i ; real_T hcdnpgpsx3 [ 5 ] ; real_T
hlxfhbo13t ; real_T hcgycykbvb ; real_T p4zzzpfwuc ; real_T nsr33ghlnl ;
real_T jslmljr52n ; real_T cfuz5azyhs ; real_T bp5zla3buu ; real_T dx4y0dpyzb
; real_T ggnfhqi10o ; real_T o02puwzmeq [ 14 ] ; real_T b4mcjoq3pm [ 1275 ] ;
real_T dxqhfqss0v [ 1275 ] ; real_T a00jzbvsry [ 1275 ] ; real_T eba3zreb1v [
1275 ] ; real_T cvgoybhrct ; real_T jussrigxo5 ; real_T objuddsoqo ; real_T
n00asbe0cr ; real_T ggzhenojhj ; real_T ksl4bwwthm [ 253 ] ; real_T
j4sa44oemc [ 253 ] ; real_T puj5ufcgar [ 36 ] ; real_T j1ddyrfz02 ; real_T
h14ca55sib [ 36 ] ; real_T jw50knhr32 [ 4 ] ; real_T o5ociv4loy ; real_T
h4qpwqrsbp [ 4 ] ; real_T hk5ddbrna2 ; real_T l20wnp13pi [ 1600 ] ; real_T
gilhtaxxr4 [ 1600 ] ; real_T mptzwf152z [ 1600 ] ; real_T krwr1yxnkb [ 1600 ]
; real_T dy4bikxriy ; real_T mo4slycvom ; real_T m3xwdo0hga ; real_T
owxe21jvfm ; real_T kcof4nf0ik ; real_T hpubuefce4 ; real_T e2t2weucbk ;
real_T h1b3wfya1d ; real_T d2lucuzp5c [ 3 ] ; real_T ocfwq55xsq [ 3 ] ;
real_T e0whfm2h5c [ 25 ] ; real_T d0bf53zj5j ; real_T gw0k5m2uam [ 25 ] ;
real_T k3hijpifwv [ 4 ] ; real_T ekkw4jo0wu ; real_T fva02g052r [ 4 ] ;
real_T icglrbob3m ; real_T fdi0wyedh2 [ 8 ] ; real_T c1at2baqh4 [ 66 ] ;
real_T lq1pcb3a12 [ 66 ] ; real_T p5pw32yemt [ 66 ] ; real_T dtxacc1epz [ 66
] ; real_T kupdujq45v ; real_T pc4w1nqdrk ; real_T a3loymxutw ; real_T
glxtjxd4tz ; real_T e2ossr2k3s ; real_T n5b55f5xhn ; real_T dqtv3p4m0t ;
real_T eemwer0jti ; real_T ntsaohnf5w [ 3 ] ; real_T nhjqtovl12 [ 9 ] ;
real_T hb0ecjv4tk [ 9 ] ; real_T dzwrbcq5j0 [ 3 ] ; real_T digpgjvs5w ;
real_T blg5blm30r ; real_T as5apg3ex2 ; real_T dtewnjw5oh ; real_T jy2zhwllxu
; real_T fmtrkmmqhe ; real_T cs2usie1fh ; real_T pjgxtmydfn ; real_T
n3vsd5osmw ; real_T fwnvn1evsn ; real_T mfp1uwxokr ; real_T cz3y22ipue ;
real_T b32j4milfx ; real_T ekrc3dfwk4 ; real_T elheedzzl0 [ 2 ] ; real_T
nxn4eoqw55 [ 2 ] ; real_T f3foywtd4b ; real_T dv0v3nmzor ; real_T birqe40e5n
; real_T mpmwb1rvos ; real_T alwtmvsmpo ; real_T eaidw1cpku ; real_T
ht0irk4tfp ; real_T p22qd4031z ; real_T dd2mp1s2kq ; real_T fowi1an3oi ;
real_T fx3ccbyxgc ; real_T mcwsqdc35c ; real_T k0yud3ty5b ; real_T b405iv50yi
; real_T i0h1yamdil ; real_T ejj102e0vx ; real_T olaxcbkzda ; real_T
lmokjh52p3 ; real_T giciwpdamg ; real_T gci5dtecc3 ; real_T d3g3axp2rz ;
real_T m4psq12wv1 ; real_T bvqq5sazyw ; real_T d35rtk4pom ; real_T pdwghfu5fu
; real_T lzu3uo0n3g [ 3 ] ; real_T iupw2x5jk0 ; real_T ibjjmy50pj [ 6 ] ;
real_T ccswgitxvj [ 3 ] ; real_T pai3e3zarf [ 3 ] ; real_T kdc5rm1ohd [ 3 ] ;
real_T era5e4fmzn [ 4 ] ; real_T bnkjf4wemf [ 4 ] ; real_T d52cu0jrec [ 3 ] ;
real_T nhbdb1hyqs [ 3 ] ; real_T itxjzsphm3 [ 3 ] ; real_T oodz4urbyp ;
real_T kvg2t5qrcf ; real_T g3a150ehbv [ 528 ] ; real_T fzxfo4voq2 [ 66 ] ;
real_T gh1fvty1e2 [ 66 ] ; real_T nvlun450q4 [ 22400 ] ; real_T mbqkewozo3 [
1600 ] ; real_T ily4igf2cj [ 1600 ] ; real_T bthtxqpdik [ 17850 ] ; real_T
ptev4zopsv [ 1275 ] ; real_T cpq0p1komv [ 1275 ] ; real_T edzfllldyc [ 2 ] ;
real_T nifycbgi5p ; real_T hakectrr15 ; real_T loketsez3q ; real_T mmsgyz3vfm
; real_T lchtvpgg01 ; real_T aizqp2ntxc ; real_T nfidzfrt02 [ 528 ] ; real_T
chnbedf2rz [ 66 ] ; real_T kufhg2pmkw [ 66 ] ; real_T ek1ampu0qf [ 22400 ] ;
real_T omstdtrdeg [ 1600 ] ; real_T omav200po3 [ 1600 ] ; real_T btwrco0qwd [
17850 ] ; real_T kd1rv3iov0 [ 1275 ] ; real_T j2dweaustf [ 1275 ] ; real_T
dal2neiedt [ 2 ] ; real_T je3saqysdi ; real_T bkdmnk0pty ; real_T a4g2vzyhvm
[ 528 ] ; real_T n5ozyxl2ea [ 66 ] ; real_T hqiyhoklio [ 66 ] ; real_T
eygirkdnjo [ 22400 ] ; real_T l5e405bn0t [ 1600 ] ; real_T pfdallhby2 [ 1600
] ; real_T a0dijuavlp [ 17850 ] ; real_T j4ooexe14u [ 1275 ] ; real_T
juhn3ctbqj [ 1275 ] ; real_T ftmbjsdwjt [ 2 ] ; real_T avmjjgc2jq ; real_T
hxuxvq3zag ; real_T imfg2yay3n ; real_T b3q33e3m3g ; real_T as41rna3ij ;
real_T j3bgt3ayxw ; real_T dk4mi1twyg ; real_T gpytux1hqf ; real_T msop4tmgui
; real_T kc4lodg3w4 ; real_T k14q0a10oi ; real_T mrdffjtdaz ; real_T
f103l2lac4 ; real_T pnkvvhogf2 [ 3 ] ; real_T nmpjtwlnon ; real_T hkurduz0au
; real_T k2e4po1rpr ; real_T gs0fs41pgc ; real_T jutgmhmp2z ; real_T
jcs20b5wfh ; real_T acuo1yvmj5 [ 11 ] ; real_T flj1dzerqr [ 11 ] ; real_T
pggd3p1kfa [ 13 ] ; real_T dp5osgsbrh [ 13 ] ; real_T arzgsm2ap5 ; real_T
d2kgi00523 ; real_T gshcaiqn50 ; real_T mpmnl0a2zz ; real_T ln2ggwhvzq ;
real_T jg34eicxwk ; real_T ha53xgy2uq ; real_T n15a0llump ; real_T pipw2nejuz
; real_T a5ywvserm5 ; real_T hms0mdlueo ; real_T o0kix50z3l ; real_T
gs1k0f4cz1 ; real_T bdk3pcqskh ; real_T bzfp2p0tab ; real_T ff5eism403 ;
real_T g1dfem4a45 ; real_T h4j3u4lsho ; real_T ouk0sd2oau ; real_T e2zmxl5mfm
; real_T lqv2v5iao3 ; real_T c1rynmct4z ; real_T e4i5mtlz0g ; real_T
n4mqntadxa ; real_T a2zv22y3vl ; real_T oipikmy4vw ; real_T fhwx15i2ya ;
real_T gsshebwjge ; real_T c0lgenxrhk ; real_T lholmb3e4u ; real_T eepk5vi4ia
; real_T obqhwmks5n ; real_T arvpirinaz ; real_T jgul4ugkjp ; real_T
awbmrd3k3c [ 4 ] ; real_T e1s2agf3sl ; real_T k1dyohghpp ; real_T ctx2gmm5rx
; real_T bjwvgrv5ph ; real_T cep0acxp4f ; real_T nc2canpxds ; real_T
j0eelvbmwd [ 169 ] ; real_T hezmbi5h34 [ 169 ] ; real_T jzrcpmvzbm [ 169 ] ;
real_T g1vw4aqlya [ 169 ] ; real_T osvuulzthg ; real_T ozswcsd4u3 [ 169 ] ;
real_T dumv41hbdf ; real_T dihmarvgf1 [ 169 ] ; real_T pfif2ru53r [ 13 ] ;
real_T cafvg0zdey ; real_T cvl0iqdxpn [ 13 ] ; real_T e14uz2pq5j [ 13 ] ;
real_T edtfmju3qt [ 3 ] ; boolean_T l0jloknu45 ; boolean_T gmdzlbahaz ;
boolean_T n0c1cwwurd ; cqptmcnrgi czqbc2hafpz ; pwekmvsjkf f2f5asy2qj ;
pwekmvsjkf cwkeianlye ; e42udnywi5 jse42y33cf ; e42udnywi5 glvqkwfsgg ;
k503avwxjn hdy13qwuxo ; pwekmvsjkf gzjgdvz5xb ; nla0xfnlgl ep1nysc0kg ;
pwekmvsjkf iuykey3bat ; nla0xfnlgl onhb0tophc ; nla0xfnlgl hh4puuamknj ;
e42udnywi5 px30n50fob ; e42udnywi5 ncfvgzcbsa ; aa02bbdgo4 kfmgjpcbo0 ;
d3abumwlqi oa2h4lycyto ; jf3t2hxsbw pqreim41fnf ; cvp4al0icj eehz0nr2kbd ;
o41qhtemcd j5jrka03lep ; ih3fopwm3i nlh1krt5jh2 ; f5p4lyabrn od5ryzaqzvr ;
pwekmvsjkf meldjycwis ; e42udnywi5 bq4wkncpnch ; k503avwxjn mlcpngipio4 ; } B
; typedef struct { real_T obcjv3kxjy [ 2 ] ; real_T pkxcgdmvhn ; real_T
kjg3l4zk5v [ 4 ] ; real_T oor1kyyfva ; real_T jscepyc3up ; real_T heflbpch1o
; real_T ksxubnoebg ; real_T jbpr4falgz [ 169 ] ; real_T h5cjobt13t [ 169 ] ;
real_T e4yokmhfao [ 169 ] ; real_T kcfi4cmlhd [ 169 ] ; real_T at05wcm525 [
13 ] ; real_T aic2hlfea0 ; real_T esy5tsm3ee ; real_T g55xueop5g ; real_T
myivyj5gij ; real_T j14ebrdltq ; real_T mpzjv2x2qj ; real_T p13ptnzy3r ;
real_T olub4b3luy ; struct { void * LoggedData [ 10 ] ; } n3envtb3nh ; struct
{ void * LoggedData [ 4 ] ; } cnovvbsxwn ; struct { void * LoggedData [ 3 ] ;
} e1b5qt1uwm ; struct { void * LoggedData [ 2 ] ; } p5yjgacqg1 ; struct {
void * LoggedData [ 3 ] ; } epcbxwnywg ; struct { void * LoggedData [ 3 ] ; }
hhp5doeay4 ; struct { void * LoggedData [ 2 ] ; } mb3c3cck1l ; struct { void
* LoggedData [ 2 ] ; } iv1jh1vdpx ; void * k1im3nzvaa ; void * kdyvdf55ga ;
void * iiujy2f33w ; void * fodvlcmywy ; void * jm0wxqrcug ; void * gq0nld4wdg
; void * b010mugrdz ; void * epf4xhkmwj ; int32_T puckbncoc1 ; int_T
fmtbmkiyrg ; int_T pqbzdxzmmn ; int_T a5xxu4ouzd ; int8_T ou4mxpicy1 ; int8_T
arhjxoel23 ; int8_T lnkokfcmam ; int8_T nbibucftep ; int8_T o4nqlaod2d ;
int8_T dbsyarjlzj ; int8_T pdbx5fzllt ; int8_T dwpkqcic1h ; int8_T a4hao0xdt0
; int8_T hvtie0034r ; int8_T asg4lqag0n ; int8_T gubyv1x2xq ; int8_T
fojyv4gldg ; int8_T kuwonxbzmn ; int8_T a1xwiuwg2w ; int8_T d4p0jrfexh ;
int8_T m5sp20k3wx ; int8_T klnvxdk0zo ; int8_T gqm3ezc0kt ; int8_T brol3yumog
; int8_T nde44yxft0 ; int8_T pbwiaz4fg0 ; int8_T b4mdlatzxs ; int8_T
gofjuybrne ; int8_T anrree0xau ; int8_T a1ezypvm4e ; int8_T juk5yec0yu ;
int8_T pfulaza2sz ; int8_T nyw4c2tuhv ; int8_T lkylelnm2t ; int8_T hxe31sma1e
; int8_T jxlgxqsvbl ; int8_T lwuzl0ygua ; int8_T cfsnxzglwr ; int8_T
lgblsj3t4q ; int8_T eznk3o5xwu ; int8_T nhcu04wvy3 ; int8_T mgjysjngq1 ;
int8_T p5zu1sk310 ; uint8_T gmx32akt1l [ 6 ] ; boolean_T onsfiqzaxb ;
boolean_T m30jrqnd0d ; boolean_T jzhzjymezd ; boolean_T dcldc3j5cw ;
boolean_T p1fsih3dwg ; boolean_T a1m5kq3kzu ; boolean_T i4ltbzqbwy ;
boolean_T dv2dewa5ej ; boolean_T dhy1luj35e ; boolean_T cjf2rcprnb ;
boolean_T g0lbtdq2uw ; boolean_T lmcvixutc1 ; boolean_T knywovw04o ;
boolean_T htejeb43jp ; boolean_T muhrn4an4s ; boolean_T avbyw4pngn ;
boolean_T ht5wxzfvhb ; boolean_T njspbenauj ; boolean_T hlczhahkiw ;
boolean_T bdynxuedph ; boolean_T jz5y5fp0m1 ; boolean_T e4gacfnnoi ;
boolean_T hzkby4wwto ; boolean_T nzerztgxqu ; boolean_T lpbtnh0h20 ;
boolean_T ktyptafnjn ; boolean_T d1x4fhglbc ; boolean_T a5xidqthyv ;
boolean_T kycuklig1k ; boolean_T danlzm034o ; boolean_T hfy3m5qgqx ;
boolean_T mcctp5x10a ; boolean_T kch0bl4hze ; boolean_T jms1o03b1m ;
boolean_T j2aja4lihr ; boolean_T far5xhf1km ; boolean_T iubpiqse3a ;
boolean_T cxt5grgy1s ; boolean_T mf0i505azj ; boolean_T ieumzhiu2f ;
kwb1dp5oh3 hdy13qwuxo ; lzsl4d3ncw nw3ycnua5h ; k4w2om5spu lwyp5so3rz ;
lzsl4d3ncw ku4t4kttcb ; k4w2om5spu cbthz0gwcs ; lzsl4d3ncw bxw5fabqqg ;
k4w2om5spu njjq1lvqsq ; lzsl4d3ncw hvkk5ldfab ; k4w2om5spu kfz4qm0ehh ;
kwb1dp5oh3 mlcpngipio4 ; lzsl4d3ncw p4zw5pk3wy ; k4w2om5spu j2qjlobs3y ;
lzsl4d3ncw ebq2is5hcrm ; k4w2om5spu oasjptnaiz4 ; } DW ; typedef struct {
real_T hmz1jwrnco [ 4 ] ; real_T oxda0i4vgt [ 3 ] ; real_T mxzg4wj1qp [ 3 ] ;
real_T pz5d015liz [ 3 ] ; } X ; typedef struct { real_T hmz1jwrnco [ 4 ] ;
real_T oxda0i4vgt [ 3 ] ; real_T mxzg4wj1qp [ 3 ] ; real_T pz5d015liz [ 3 ] ;
} XDot ; typedef struct { boolean_T hmz1jwrnco [ 4 ] ; boolean_T oxda0i4vgt [
3 ] ; boolean_T mxzg4wj1qp [ 3 ] ; boolean_T pz5d015liz [ 3 ] ; } XDis ;
typedef struct { real_T hmz1jwrnco [ 4 ] ; real_T oxda0i4vgt [ 3 ] ; real_T
mxzg4wj1qp [ 3 ] ; real_T pz5d015liz [ 3 ] ; } CStateAbsTol ; typedef struct
{ real_T hmz1jwrnco [ 4 ] ; real_T oxda0i4vgt [ 3 ] ; real_T mxzg4wj1qp [ 3 ]
; real_T pz5d015liz [ 3 ] ; } CXPtMin ; typedef struct { real_T hmz1jwrnco [
4 ] ; real_T oxda0i4vgt [ 3 ] ; real_T mxzg4wj1qp [ 3 ] ; real_T pz5d015liz [
3 ] ; } CXPtMax ; typedef struct { real_T on04gpzde4 ; real_T gixsda4bxe ;
real_T pstgm24b14 ; real_T bfa53nlxor ; real_T ggpzo3g3ic ; real_T mljdm35a2w
; real_T hvejtfx4tk ; real_T ccjttm4k14 ; real_T mpoeljukju ; real_T
blcdcm45ox ; real_T jv04uxmnal ; real_T mzzwkdtdk4 ; real_T ltam3jfqj2 ;
real_T o4qsalpqnc ; real_T nb3e0bn3ca ; real_T crvlqxhw14 ; real_T j3mgw4p0ga
; real_T ilr1vcrggp ; real_T esafw32dui ; real_T hc5z5aewkq ; real_T
coa53myf45 ; real_T i0cqq3wjwo ; real_T htdzalrmgh ; real_T ot00lnpbu1 ;
real_T gko1wm0t2f ; real_T p4bmzbeppo ; real_T j1dtem3dil ; real_T bio0cc2b5u
; real_T et2pdibc2o ; real_T e20bracmkl ; real_T o3or5rxznj ; real_T
pg1djeo2ng ; real_T mvyygymfw5 ; real_T komr1smdon ; real_T bohzvnaelj ;
real_T eouq0giui5 ; real_T nzjskho3pt ; real_T h45rrcffpf ; real_T c13ojsfep0
; real_T csknh51wia ; real_T jdnz4mw0kx ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct bbhpdcgcgo_ { real_T
Bias1_Bias ; real_T Bias_Bias ; } ; struct n3egxfz4sp_ { real_T phi_Y0 ;
real_T Memory_InitialCondition ; real_T Constant1_Value ; int8_T
Switch_Threshold ; } ; struct P_ { struct_ZtKgq7qQgrOMpDzzLZ17RD DYN_ATT_par
; struct_zvomUs9swg0LYolfrL6G0F CONSTANTS_par ; struct_SSrbxNhDAwveKzBnq5y3AG
DYN_TRA_par ; struct_6abjlDkQyd29d22lQVv5wH DYN_AERO_par ;
struct_N7noyS7OhT495NXnZH8zAG DYN_SC_par ; real_T
AerodynamicForcesandMoments_S ; real_T NRLMSISE00AtmosphereModel_action ;
real_T AerodynamicForcesandMoments_b ; real_T
AerodynamicForcesandMoments_cbar ; real_T JulianDateConversion_day ; real_T
JulianDateConversion_day_m0mo1gjmhe ; real_T
JulianDateConversion_day_e45v40wquc ; real_T
JulianDateConversion_day_oxofdgm3xl ; real_T
JulianDateConversion_day_as4zhjks20 ; real_T
JulianDateConversion_day_b3uyqw452t ; real_T NRLMSISE00AtmosphereModel_flags
[ 23 ] ; real_T ECIPositiontoLLA_hour ; real_T
DirectionCosineMatrixECItoECEF_hour ; real_T ECIPositiontoLLA_hour_hxz4j5ftiz
; real_T CheckAltitude_max ; real_T CheckLatitude_max ; real_T
CheckLongitude_max ; real_T Istimewithinmodellimits_max ; real_T
ECIPositiontoLLA_min ; real_T DirectionCosineMatrixECItoECEF_min ; real_T
ECIPositiontoLLA_min_b32vidcx4h ; real_T CheckAltitude_min ; real_T
CheckLatitude_min ; real_T CheckLongitude_min ; real_T
Istimewithinmodellimits_min ; real_T CheckdeltaT_minmax [ 2 ] ; real_T
CheckdeltaT_minmax_l5hvbzxump [ 2 ] ; real_T CheckdeltaT_minmax_igedlwrre3 [
2 ] ; real_T CheckdeltaT_minmax_ccepsw5qgq [ 2 ] ; real_T
CheckdeltaT_minmax_nxemqbvh1w [ 2 ] ; real_T CheckdeltaT_minmax_a2tgpuyjmr [
2 ] ; real_T CheckdeltaT_minmax_cnwv0n4cpc [ 2 ] ; real_T
CheckdeltaT_minmax_axwixcj3v5 [ 2 ] ; real_T CheckdeltaT_minmax_iczlyigkah [
2 ] ; real_T CheckdeltaT_minmax_o0fimawo5l [ 2 ] ; real_T
CheckdeltaT_minmax_cn2hd0jnck [ 2 ] ; real_T JulianDateConversion_month ;
real_T JulianDateConversion_month_hlb3dhxm04 ; real_T
JulianDateConversion_month_cojprbcmrr ; real_T
JulianDateConversion_month_ddckzl0a5p ; real_T
JulianDateConversion_month_dygyg541u0 ; real_T
JulianDateConversion_month_jjko0tg2mn ; real_T
NRLMSISE00AtmosphereModel_oxygen_in ; real_T ECIPositiontoLLA_sec ; real_T
JulianDateConversion_sec ; real_T JulianDateConversion_sec_jtb5mx1osm ;
real_T DirectionCosineMatrixECItoECEF_sec ; real_T
JulianDateConversion_sec_ognsdwmsdd ; real_T
JulianDateConversion_sec_l3vfkmpzlh ; real_T ECIPositiontoLLA_sec_hg1n4hn3po
; real_T JulianDateConversion_sec_gdeswoz3p0 ; real_T
JulianDateConversion_sec_ipkurkj5eg ; real_T LIB_ROT_MATINV_tol ; real_T
ECIPositiontoLLA_year ; real_T DirectionCosineMatrixECItoECEF_year ; real_T
ECIPositiontoLLA_year_puex1wafy5 ; real_T LIB_ROT_QNORM_zero_tol ; real_T
pp13_Y0 [ 13 ] ; real_T Constant_Value ; real_T pp13_Y0_kswnfuenys [ 13 ] ;
real_T k1313_Value [ 169 ] ; real_T bpp_Y0 ; real_T
UnitDelay1_InitialCondition [ 13 ] ; real_T Constant_Value_iuv5na0ase ;
real_T Constant1_Value ; real_T Gain1_Gain ; real_T Gain2_Gain ; real_T
Constant_Value_ojjvjervs2 ; real_T Constant_Value_gsdkcwgkjf ; real_T
Constant_Value_ci50fad5pe ; real_T Switch_Threshold ; real_T
Switch1_Threshold ; real_T Constant_Value_kxvhj2k0q1 ; real_T
Constant1_Value_oob1ufgc1x ; real_T k1313_Value_lpuwbdf0we [ 169 ] ; real_T
dp1313_Y0 [ 169 ] ; real_T snorm169_Y0 [ 169 ] ; real_T
UnitDelay_InitialCondition [ 169 ] ; real_T
UnitDelay1_InitialCondition_pstroo2j12 [ 169 ] ; real_T Merge1_InitialOutput
; real_T Merge_InitialOutput ; real_T Gain_Gain ; real_T tc1313_Y0 [ 169 ] ;
real_T UnitDelay_InitialCondition_pndmycisf3 [ 169 ] ; real_T
UnitDelay_InitialCondition_czov4a5uix [ 169 ] ; real_T cmaxdefmaxdef_Value [
169 ] ; real_T cdmaxdefmaxdef_Value [ 169 ] ; real_T
zerosmaxdef1maxdef1_Value [ 169 ] ; real_T bt_Y0 ; real_T bp_Y0 ; real_T
br_Y0 ; real_T bpp_Y0_pfjanwvnvp ; real_T Merge_InitialOutput_myeiq12cia ;
real_T Merge1_InitialOutput_mn1mvqmvlz ; real_T
UnitDelay1_InitialCondition_e0xnht2pv2 ; real_T UnitDelay3_InitialCondition ;
real_T UnitDelay2_InitialCondition ; real_T UnitDelay4_InitialCondition ;
real_T Constant1_Value_hhsbgiwfw4 ; real_T fm_Value [ 13 ] ; real_T fn_Value
[ 13 ] ; real_T Constant1_Value_c3qzhrjczc ; real_T btbpbrbpp_Y0 [ 4 ] ;
real_T UnitDelay_InitialCondition_mllgrjaacn ; real_T
UnitDelay2_InitialCondition_iiychjgimi [ 4 ] ; real_T r_Y0 ; real_T ct_Y0 ;
real_T st_Y0 ; real_T sa_Y0 ; real_T ca_Y0 ; real_T Gain_Gain_md0oerbgpc ;
real_T a_Value ; real_T b_Value ; real_T Constant_Value_a3at3ko0th ; real_T
sp11_Y0 [ 11 ] ; real_T cp11_Y0 [ 11 ] ; real_T ForIterator_IterationLimit ;
real_T UnitDelay1_InitialCondition_g1fqgjuntl ; real_T cpm1spm1_Threshold ;
real_T Constant_Value_hwgeqimqs5 [ 11 ] ; real_T Constant1_Value_h1wxj304y3 [
11 ] ; real_T sp13_Y0 [ 13 ] ; real_T cp13_Y0 [ 13 ] ; real_T
Gain_Gain_lhdtz4jp1s ; real_T Gain1_Gain_gog3k4xq4w ; real_T cp1_Value ;
real_T sp1_Value ; real_T Gain_Gain_b3taeuvvdg ; real_T BiasYear_Bias ;
real_T Gain_Gain_abz5gz4hcy ; real_T Bias1_Bias ; real_T
Gain1_Gain_jz0t0f0y5u ; real_T Bias2_Bias ; real_T Gain2_Gain_oajgjiov5c ;
real_T Gain3_Gain ; real_T BiasDay_Bias ; real_T Gain5_Gain ; real_T
Gain6_Gain ; real_T Gain4_Gain ; real_T Bias1_Bias_afrqardpnr ; real_T
Gain_Gain_bimerhfkin ; real_T Gain_Gain_aimd1pmlgi ; real_T
BiasYear_Bias_flvwpd23tq ; real_T Gain_Gain_af2qteq0md ; real_T
Bias1_Bias_bqcafx2zzl ; real_T Gain1_Gain_cxzipu4bih ; real_T
Bias2_Bias_hygu35zh3z ; real_T Gain2_Gain_ego3bowjsc ; real_T
Gain3_Gain_fa5ervkb4p ; real_T BiasDay_Bias_ka2dudb0f5 ; real_T
Gain5_Gain_po5tiefu4u ; real_T Gain6_Gain_bquoj5efzi ; real_T
Gain4_Gain_c1bog0ixkx ; real_T Bias_Bias ; real_T Bias1_Bias_hsuhmxu2kn ;
real_T Gain_Gain_eslt4lguf0 ; real_T Gain1_Gain_lrbrtfzz2g ; real_T Y0_Coefs
[ 6 ] ; real_T mMoon_Coefs [ 5 ] ; real_T mSun_Coefs [ 5 ] ; real_T
umMoon_Coefs [ 5 ] ; real_T dSun_Coefs [ 5 ] ; real_T omegaMoon_Coefs [ 5 ] ;
real_T Gain_Gain_mtidtwrn1n ; real_T lMercury_Coefs [ 2 ] ; real_T
lVenus_Coefs [ 2 ] ; real_T lEarth_Coefs [ 2 ] ; real_T lMars_Coefs [ 2 ] ;
real_T lJupiter_Coefs [ 2 ] ; real_T lSaturn_Coefs [ 2 ] ; real_T
lUranus_Coefs [ 2 ] ; real_T lNeptune_Coefs [ 2 ] ; real_T pa_Coefs [ 3 ] ;
real_T Gain4_Gain_jn1efyybdb ; real_T X0_Coefs [ 6 ] ; real_T
Gain3_Gain_owqano1n1j ; real_T S0_Coefs [ 6 ] ; real_T Gain2_Gain_hfcaz1phbz
; real_T Gain5_Gain_fsuar2mnaj ; real_T Gain1_Gain_k5feilsibt ; real_T
Gain_Gain_hdhhylvzeo ; real_T BiasYear_Bias_n4w3ry1u0i ; real_T
Gain_Gain_hiumlrr1tu ; real_T Bias1_Bias_k25uehi4dt ; real_T
Gain1_Gain_hi1zqgx4wm ; real_T Bias2_Bias_fh1a5p4eyh ; real_T
Gain2_Gain_bz2f2drozo ; real_T Gain3_Gain_ocwqkavwvj ; real_T
BiasDay_Bias_h4d4xzeixu ; real_T Gain5_Gain_cw0at02a10 ; real_T
Gain6_Gain_asg4eux1fd ; real_T Gain4_Gain_cgs3mxx1hh ; real_T
Bias1_Bias_nrxfej55lg ; real_T Gain_Gain_ftqmvwc1lk ; real_T
Gain_Gain_ek2ohtwn1h ; real_T BiasYear_Bias_dq4wgw0ext ; real_T
Gain_Gain_pz3cjiymq0 ; real_T Bias1_Bias_asv15o3c1b ; real_T
Gain1_Gain_nlkud5skgo ; real_T Bias2_Bias_govedqbcfa ; real_T
Gain2_Gain_cfgj3jd2t1 ; real_T Gain3_Gain_c4zdbsr3gi ; real_T
BiasDay_Bias_ea0r5csp12 ; real_T Gain5_Gain_obezikmpam ; real_T
Gain6_Gain_jbudznuq5c ; real_T Gain4_Gain_c4zgm5t2w1 ; real_T
Bias_Bias_l532sun3ix ; real_T Bias1_Bias_o2qxjaezc1 ; real_T
Gain_Gain_ak5fpqqeh4 ; real_T Gain1_Gain_detstoozi4 ; real_T
Y0_Coefs_cma4ntrpt3 [ 6 ] ; real_T mMoon_Coefs_jtz0tcft3i [ 5 ] ; real_T
mSun_Coefs_diyd15g1wp [ 5 ] ; real_T umMoon_Coefs_plrarhxgq3 [ 5 ] ; real_T
dSun_Coefs_dmufayevgi [ 5 ] ; real_T omegaMoon_Coefs_isubkliji5 [ 5 ] ;
real_T Gain_Gain_onjpfk2fzl ; real_T lMercury_Coefs_lxucr4qhwu [ 2 ] ; real_T
lVenus_Coefs_fxotok2s3d [ 2 ] ; real_T lEarth_Coefs_bya2kolugl [ 2 ] ; real_T
lMars_Coefs_kkf443jqvl [ 2 ] ; real_T lJupiter_Coefs_aa0qdlhuxf [ 2 ] ;
real_T lSaturn_Coefs_nm4emcptmd [ 2 ] ; real_T lUranus_Coefs_esv1bkthff [ 2 ]
; real_T lNeptune_Coefs_krgackraim [ 2 ] ; real_T pa_Coefs_lemnaykgb3 [ 3 ] ;
real_T Gain4_Gain_hg3t1ixrrd ; real_T X0_Coefs_kgh01blu1x [ 6 ] ; real_T
Gain3_Gain_j3zv55r1ur ; real_T S0_Coefs_no3ka1dr5l [ 6 ] ; real_T
Gain2_Gain_jdtrerikvn ; real_T Gain5_Gain_bm1bslfrzz ; real_T
Gain1_Gain_o1mxdlp2ab ; real_T Gain_Gain_muxufnpnzm ; real_T
otime_InitialCondition ; real_T BiasYear_Bias_aliio05ag5 ; real_T
Gain_Gain_at2pdfq0hn ; real_T Bias1_Bias_lbt1eqslp3 ; real_T
Gain1_Gain_ioogsj5ido ; real_T Bias2_Bias_loapkssk0r ; real_T
Gain2_Gain_inyn5mztkh ; real_T Gain3_Gain_n3ofo4trun ; real_T
BiasDay_Bias_kx23oa5fos ; real_T Gain5_Gain_ilan1xzgqo ; real_T
Gain6_Gain_ak51j1uaxi ; real_T Gain4_Gain_mg3e432ign ; real_T
Bias1_Bias_mxqwso2h41 ; real_T Gain_Gain_dt3fpswwfk ; real_T
Gain_Gain_m1qcgs5t0k ; real_T BiasYear_Bias_brnbdy2n1d ; real_T
Gain_Gain_dkcretjodz ; real_T Bias1_Bias_mil2ojwnu2 ; real_T
Gain1_Gain_o50kjiguet ; real_T Bias2_Bias_ecpwnq22vr ; real_T
Gain2_Gain_ncg4ehfczr ; real_T Gain3_Gain_i00ghwtvfa ; real_T
BiasDay_Bias_l15sc5nzd1 ; real_T Gain5_Gain_nf1m5uawcw ; real_T
Gain6_Gain_ktkaikrz20 ; real_T Gain4_Gain_bvjyiveudp ; real_T
Bias_Bias_czbwtteptn ; real_T Bias1_Bias_dtaubxtyxe ; real_T
Gain_Gain_eoz4cwquy4 ; real_T Gain1_Gain_kz5th20k0g ; real_T
Y0_Coefs_j4edtdbmce [ 6 ] ; real_T mMoon_Coefs_fhtgxhqslm [ 5 ] ; real_T
mSun_Coefs_k5qfpcaq4v [ 5 ] ; real_T umMoon_Coefs_k1lhkptrx0 [ 5 ] ; real_T
dSun_Coefs_mr3dhrfpf4 [ 5 ] ; real_T omegaMoon_Coefs_phytzpyn2y [ 5 ] ;
real_T Gain_Gain_iqbwobzmbk ; real_T lMercury_Coefs_m5snryadyd [ 2 ] ; real_T
lVenus_Coefs_odwx0v3t1k [ 2 ] ; real_T lEarth_Coefs_e2uao4qeak [ 2 ] ; real_T
lMars_Coefs_fxog3atqyg [ 2 ] ; real_T lJupiter_Coefs_kshyeufjur [ 2 ] ;
real_T lSaturn_Coefs_fnnhe3ezq1 [ 2 ] ; real_T lUranus_Coefs_lk0nrkh0ol [ 2 ]
; real_T lNeptune_Coefs_owth3gnsft [ 2 ] ; real_T pa_Coefs_db5dntr30p [ 3 ] ;
real_T Gain4_Gain_oppsulm5sy ; real_T X0_Coefs_e20wt0lj1b [ 6 ] ; real_T
Gain3_Gain_j2smucdy5e ; real_T S0_Coefs_fabprfntsi [ 6 ] ; real_T
Gain2_Gain_pjm2hegrql ; real_T Gain5_Gain_j0ximqlaqo ; real_T
Gain1_Gain_iweoiyfcch ; real_T u80deg_UpperSat ; real_T u80deg_LowerSat ;
real_T u0deg_UpperSat ; real_T u0deg_LowerSat ; real_T olon_InitialCondition
; real_T olat_InitialCondition ; real_T uto1000000m_UpperSat ; real_T
uto1000000m_LowerSat ; real_T Gain_Gain_c532tabdaz ; real_T
oalt_InitialCondition ; real_T nTtoT_Gain ; real_T nTtoT1_Gain ; real_T
Gain_Gain_d4wyhwnizf ; real_T Constant_Value_j0j5kt5zqt [ 3 ] ; real_T
coefAdjust_Gain [ 3 ] ; real_T Bias_Bias_muto2udg1i ; real_T Index_Value ;
real_T sec2_Value [ 4 ] ; real_T secGain_Gain ; real_T
Constant_Value_hp2sqou0mh ; real_T Index_Value_d3cukp2ka0 ; real_T
sec2_Value_chxskdyj2l [ 4 ] ; real_T gainVal_Gain ; real_T
Constant_Value_ffojnsp0xh ; real_T Constant_Value_bpqcpfxkh2 ; real_T
Constant_Value_mv2kh0yrpo [ 726 ] ; real_T Constant1_Value_hgicfsjrdx [ 33 ]
; real_T Constant2_Value [ 3 ] ; real_T Constant3_Value [ 25 ] ; real_T
Constant4_Value [ 4 ] ; real_T Constant_Value_bln5ascixh [ 27200 ] ; real_T
Constant1_Value_cz2wizjcpi [ 1306 ] ; real_T Constant2_Value_n3pjai40y1 [ 253
] ; real_T Constant3_Value_okgyhbkfgz [ 36 ] ; real_T
Constant4_Value_emg2dxpi3k [ 4 ] ; real_T Constant_Value_o4yfykzqvt [ 21675 ]
; real_T Constant1_Value_b052naa0vc [ 962 ] ; real_T
Constant2_Value_gsi2svh5ar [ 277 ] ; real_T Constant3_Value_adwr3klyjx [ 30 ]
; real_T Constant4_Value_mfq4qaouzv [ 5 ] ; real_T Constant_Value_gal33glcsm
; real_T Constant1_Value_gl5rj15yqg [ 2 ] ; real_T Gain1_Gain_ehl1l35w02 ;
real_T Constant_Value_fe02n3dwap ; real_T Constant_Value_eqdvpf4fte ; real_T
Constant1_Value_mtln531pzy ; real_T Constant1_Value_omeg2wr434 ; real_T
f_Value ; real_T Constant_Value_khf3n3ma2u ; real_T Constant_Value_gl3cqlwg4c
; real_T aph_Value [ 7 ] ; real_T f107_Value ; real_T f107a_Value ; real_T
lst_Value ; real_T AddParam_Value [ 2 ] ; real_T deltaAT_Value ; real_T
Bias_Bias_gbleru4jry ; real_T Index_Value_mnrgh2annx ; real_T
sec2_Value_itv23ykpn0 [ 4 ] ; real_T deltaUT1_Value ; real_T
secGain_Gain_biw3ghlj4z ; real_T Constant_Value_j2nbb2jcp2 ; real_T
Index_Value_hht33xgv1j ; real_T sec2_Value_euqqqma0wu [ 4 ] ; real_T
gainVal_Gain_loj5c3zibi ; real_T Constant_Value_psn3rbk20o ; real_T
Constant_Value_gktmyn3mcb ; real_T Constant_Value_i1xx5cbvq3 [ 726 ] ; real_T
Constant1_Value_ddiex05etl [ 33 ] ; real_T Constant2_Value_by5smj3iox [ 3 ] ;
real_T Constant3_Value_hgeiisjifi [ 25 ] ; real_T Constant4_Value_i4zhyp3snv
[ 4 ] ; real_T Constant_Value_mip0qup14w [ 27200 ] ; real_T
Constant1_Value_inkvfz0zew [ 1306 ] ; real_T Constant2_Value_jrq2zowv3b [ 253
] ; real_T Constant3_Value_a315iwbeaf [ 36 ] ; real_T
Constant4_Value_hyps5wis0w [ 4 ] ; real_T Constant_Value_ivophock2i [ 21675 ]
; real_T Constant1_Value_axzvxccr3e [ 962 ] ; real_T
Constant2_Value_a4evmfwszo [ 277 ] ; real_T Constant3_Value_jz2c5abeqb [ 30 ]
; real_T Constant4_Value_o1opkhecub [ 5 ] ; real_T Constant_Value_m2yb3ytgqq
; real_T Constant1_Value_naue5nbsm0 [ 2 ] ; real_T PolarMotion_Value [ 2 ] ;
real_T Gain1_Gain_jzrkdwkcmc ; real_T Bias_Bias_fimxdpcz0r ; real_T
Index_Value_n204t4hl2h ; real_T sec2_Value_fqezgz3otg [ 4 ] ; real_T
secGain_Gain_hlnp40tcco ; real_T Constant_Value_ozxjypgv2m ; real_T
Index_Value_h3h5j0d243 ; real_T sec2_Value_b0uh2kaims [ 4 ] ; real_T
gainVal_Gain_jepzmrn5us ; real_T Constant_Value_mrgcwyt01m ; real_T
Constant_Value_oxv42c3du0 ; real_T Constant_Value_arzpnbb4jz [ 726 ] ; real_T
Constant1_Value_pcoochrvub [ 33 ] ; real_T Constant2_Value_l2txdzslhh [ 3 ] ;
real_T Constant3_Value_hcq30unaft [ 25 ] ; real_T Constant4_Value_lpkraygrx1
[ 4 ] ; real_T Constant_Value_ghtelgcmbm [ 27200 ] ; real_T
Constant1_Value_a0dc2utvkp [ 1306 ] ; real_T Constant2_Value_nyqacrfyzs [ 253
] ; real_T Constant3_Value_idwt3uxkw3 [ 36 ] ; real_T
Constant4_Value_eeff0ovks2 [ 4 ] ; real_T Constant_Value_j10ooefofa [ 21675 ]
; real_T Constant1_Value_k4qbtajenz [ 962 ] ; real_T
Constant2_Value_fzij21kslz [ 277 ] ; real_T Constant3_Value_i3i3sbnskz [ 30 ]
; real_T Constant4_Value_l3velnslc1 [ 5 ] ; real_T Constant_Value_bdzjiale0j
; real_T Constant1_Value_d3hr30tnd3 [ 2 ] ; real_T Gain1_Gain_ptxpgc3l5h ;
real_T Constant_Value_pppnc2td4g ; real_T Constant_Value_cg2soit4am ; real_T
Constant1_Value_o0v0cp40lz ; real_T Constant1_Value_o24g21izud ; real_T
f_Value_a0qm3q0swb ; real_T Constant_Value_nqner0e4l0 ; real_T
Constant_Value_lprh1udy0r ; real_T epoch_Value ; real_T re_Value ; real_T
JDepoch_days_Value ; real_T Gain1_Gain_jiyxhgzckp ; int32_T
Constant_Value_pkbx0wcdbg ; int32_T Constant1_Value_jfvsd5kyuk ; int32_T
Constant_Value_n0idaqzggt ; int32_T Gain_Gain_anntbiv2hw ; int32_T
Constant_Value_f2xoku0mnk ; int32_T Gain_Gain_h5zkzhoa3l ; int32_T
Constant_Value_jhaknhjhno ; int32_T Gain_Gain_f4ahrvji4n ; int32_T
Constant1_Value_afnplzfoow ; int32_T Constant_Value_bwlzvps1l5 ; int32_T
Constant_Value_bwahynpith ; int32_T Constant1_Value_kfgfurqslu ; int32_T
Constant1_Value_bvd3altyqr ; int32_T Constant1_Value_otjdz3c2iu ; int32_T
Gain_Gain_jpwaeoydvw ; int32_T Constant_Value_bsq4tggw3b ; int32_T
Constant_Value_jjv34c5bzq ; int32_T Constant_Value_mxbsfvifbk ; int32_T
Constant1_Value_m2x0xcbmle ; int32_T Constant_Value_okfmr3g0bv ; int32_T
tc_old_Threshold ; int32_T Gain_Gain_o2vpnzrawe ; int32_T
Constant_Value_nqlsv55lik ; int32_T Constant1_Value_i5o3wxnos4 ; int32_T
Constant_Value_oq3ogp0hba ; int32_T Constant_Value_egtb2jjfml ; int32_T
Constant_Value_c31cs1qspe ; int32_T ForIterator_IterationLimit_axxrp1ixpm ;
int32_T arn_Threshold ; int32_T Constant_Value_ozyzchp131 ; n3egxfz4sp
hdy13qwuxo ; bbhpdcgcgo lwyp5so3rz ; bbhpdcgcgo cbthz0gwcs ; bbhpdcgcgo
njjq1lvqsq ; bbhpdcgcgo kfz4qm0ehh ; n3egxfz4sp mlcpngipio4 ; bbhpdcgcgo
j2qjlobs3y ; bbhpdcgcgo oasjptnaiz4 ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
TST_RWSW_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
