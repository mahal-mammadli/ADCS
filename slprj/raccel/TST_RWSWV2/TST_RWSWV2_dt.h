#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_6pbsqoVKWVC6c9Si0vLrgD" , 14 ,
3623136 } , { "struct_QshdnZq1fOlw6PdzPTqajC" , 15 , 352 } , {
"struct_jchapTHRSDwq1p4Fcd3HGG" , 16 , 4281888 } , {
"struct_nnSY1v0mX1jIKI1gvugnaE" , 17 , 17127552 } , {
"struct_zvomUs9swg0LYolfrL6G0F" , 18 , 136 } , {
"struct_pRh2I6kb8EpGWYupLmWg4F" , 19 , 88 } , {
"struct_OQVIZ74DlhsweG9NoRv7dB" , 20 , 80 } , {
"struct_eYFdmadaAEbmfNbyeiZ4KH" , 21 , 396808 } , {
"struct_ZtKgq7qQgrOMpDzzLZ17RD" , 22 , 472 } , {
"struct_3OptKx60sX28Peciomd4EC" , 23 , 272 } , {
"struct_XG5FAMxlkIOXT4puaiHssC" , 24 , 24 } , {
"struct_SSrbxNhDAwveKzBnq5y3AG" , 25 , 128 } , { "int64_T" , 26 , 8 } , {
"int64_T" , 27 , 8 } , { "uint64_T" , 28 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( struct_6pbsqoVKWVC6c9Si0vLrgD ) , sizeof
( struct_QshdnZq1fOlw6PdzPTqajC ) , sizeof ( struct_jchapTHRSDwq1p4Fcd3HGG )
, sizeof ( struct_nnSY1v0mX1jIKI1gvugnaE ) , sizeof (
struct_zvomUs9swg0LYolfrL6G0F ) , sizeof ( struct_pRh2I6kb8EpGWYupLmWg4F ) ,
sizeof ( struct_OQVIZ74DlhsweG9NoRv7dB ) , sizeof (
struct_eYFdmadaAEbmfNbyeiZ4KH ) , sizeof ( struct_ZtKgq7qQgrOMpDzzLZ17RD ) ,
sizeof ( struct_3OptKx60sX28Peciomd4EC ) , sizeof (
struct_XG5FAMxlkIOXT4puaiHssC ) , sizeof ( struct_SSrbxNhDAwveKzBnq5y3AG ) ,
sizeof ( int64_T ) , sizeof ( int64_T ) , sizeof ( uint64_T ) } ; static
const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" ,
"uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" ,
"fcn_call_T" , "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"struct_6pbsqoVKWVC6c9Si0vLrgD" , "struct_QshdnZq1fOlw6PdzPTqajC" ,
"struct_jchapTHRSDwq1p4Fcd3HGG" , "struct_nnSY1v0mX1jIKI1gvugnaE" ,
"struct_zvomUs9swg0LYolfrL6G0F" , "struct_pRh2I6kb8EpGWYupLmWg4F" ,
"struct_OQVIZ74DlhsweG9NoRv7dB" , "struct_eYFdmadaAEbmfNbyeiZ4KH" ,
"struct_ZtKgq7qQgrOMpDzzLZ17RD" , "struct_3OptKx60sX28Peciomd4EC" ,
"struct_XG5FAMxlkIOXT4puaiHssC" , "struct_SSrbxNhDAwveKzBnq5y3AG" , "int64_T"
, "int64_T" , "uint64_T" } ; static DataTypeTransition rtBTransitions [ ] = {
{ ( char_T * ) ( & rtB . p11ofm4mny [ 0 ] ) , 0 , 0 , 141261 } , { ( char_T *
) ( & rtB . lbv4bsnkdm ) , 8 , 0 , 6 } , { ( char_T * ) ( & rtB . evg4tqc010g
. pl0ikyvvgy [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . noxmrm1w5fh .
elfsvtngpi [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . b02oakwn4y .
ihykyxkclc [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . f1ei3kfb3b .
ihykyxkclc [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . pteoo54u1l .
otpij24kr0 [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . arkzj205og .
otpij24kr0 [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . kaatsalz40 .
injnyz4auw ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . mb4psf2ogk . ihykyxkclc
[ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . dtnb1odzgu . grgp0ja04k [ 0
] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . esmxkiztnvh . ihykyxkclc [ 0 ] )
, 0 , 0 , 3 } , { ( char_T * ) ( & rtB . i2hoddpqqn . grgp0ja04k [ 0 ] ) , 0
, 0 , 3 } , { ( char_T * ) ( & rtB . fl3fthyqxfw . grgp0ja04k [ 0 ] ) , 0 , 0
, 3 } , { ( char_T * ) ( & rtB . o2egb43grn . otpij24kr0 [ 0 ] ) , 0 , 0 , 4
} , { ( char_T * ) ( & rtB . fzzz0da3bpm . otpij24kr0 [ 0 ] ) , 0 , 0 , 4 } ,
{ ( char_T * ) ( & rtB . h3f4zqct5b . kfmst3u5d3 [ 0 ] ) , 0 , 0 , 3 } , { (
char_T * ) ( & rtB . fy4zj3hhge . gaty2jlz2p [ 0 ] ) , 0 , 0 , 4 } , { (
char_T * ) ( & rtB . kaa1h5fw2dm . apia2ki5qj [ 0 ] ) , 0 , 0 , 4 } , { (
char_T * ) ( & rtB . evxgoynfhh1 . mqozl5xj12 . gyjfwigx2h [ 0 ] ) , 0 , 0 ,
9 } , { ( char_T * ) ( & rtB . lawi0f5r5l2 . jgjuew1xpe [ 0 ] ) , 0 , 0 , 3 }
, { ( char_T * ) ( & rtB . lj0sp02vlxl . fdh2hm3qwy [ 0 ] ) , 0 , 0 , 4 } , {
( char_T * ) ( & rtB . bq3pldfcaqv . nkouc1qloz [ 0 ] ) , 0 , 0 , 4 } , { (
char_T * ) ( & rtB . fbciyjdijrl . injnyz4auw ) , 0 , 0 , 1 } , { ( char_T *
) ( & rtB . cc3vamisq4t . gaty2jlz2p [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) (
& rtB . i41uiun02b3 . ny3pcenmal [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( &
rtDW . jbiuzi4aai [ 0 ] ) , 0 , 0 , 728 } , { ( char_T * ) ( & rtDW .
p4bppyayaf . LoggedData ) , 11 , 0 , 68 } , { ( char_T * ) ( & rtDW .
jmztpvsjv0 ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtDW . abs4jjv355 ) , 2 , 0 ,
29 } , { ( char_T * ) ( & rtDW . bahf1mm04g [ 0 ] ) , 3 , 0 , 6 } , { (
char_T * ) ( & rtDW . mdd3waf5u2 ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtDW .
kaatsalz40 . kekyx2w2xd ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtDW .
etw3qygazq . gmbejf1syu ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
aoxobjloyv . c5enzgh0ln ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
cbgg0vjzsr . gmbejf1syu ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
kvhpjeahvc . c5enzgh0ln ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
kugkutdkkw . d343bhqapn ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
favglkmcha . p0optqqzsf ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
cuzz03aam2l . d343bhqapn ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
ok5kaek4lxs . p0optqqzsf ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
cpe4p1nzlo . gmbejf1syu ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
f3bpn3lnkh . c5enzgh0ln ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
fse3bizgct . gmbejf1syu ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
ccrvxjn2zx . c5enzgh0ln ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
fbciyjdijrl . kekyx2w2xd ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtDW .
ausjujlz1d . gmbejf1syu ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
ep1krdw3c3 . c5enzgh0ln ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
eu5kqssxx5u . gmbejf1syu ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
k3sfyh0c3kb . c5enzgh0ln ) , 2 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 50U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . DYN_ATT_par ) , 22 , 0 , 1 }
, { ( char_T * ) ( & rtP . DYN_SC_par ) , 23 , 0 , 1 } , { ( char_T * ) ( &
rtP . CONSTANTS_par ) , 18 , 0 , 1 } , { ( char_T * ) ( & rtP . DYN_TRA_par )
, 25 , 0 , 1 } , { ( char_T * ) ( & rtP . DYN_AERO_par ) , 20 , 0 , 1 } , { (
char_T * ) ( & rtP . DYN_MAG_par ) , 24 , 0 , 1 } , { ( char_T * ) ( & rtP .
Checkepoch_ephConstants ) , 15 , 0 , 1 } , { ( char_T * ) ( & rtP .
Normalization1_Bias ) , 0 , 0 , 160389 } , { ( char_T * ) ( & rtP .
ncm_IterationLimit ) , 6 , 0 , 31 } , { ( char_T * ) ( & rtP . kaatsalz40 .
phi_Y0 ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtP . kaatsalz40 .
Switch_Threshold ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtP . aoxobjloyv .
Bias1_Bias ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . kvhpjeahvc . Bias1_Bias
) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . c4u0lt4ut5 . velocity_Y0 ) , 0 , 0
, 1 } , { ( char_T * ) ( & rtP . c4u0lt4ut5 . ncm_IterationLimit ) , 6 , 0 ,
1 } , { ( char_T * ) ( & rtP . c4u0lt4ut5 . oy5rlkbq1z . velocity_Y0 ) , 0 ,
0 , 1 } , { ( char_T * ) ( & rtP . c4u0lt4ut5 . oy5rlkbq1z .
ForIterator_IterationLimit ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtP .
kugkutdkkw . vci_Y0 ) , 0 , 0 , 15 } , { ( char_T * ) ( & rtP . mjf0gtqzjp .
position_Y0 ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP . mjf0gtqzjp .
kvr32gbyca . position_Y0 ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP .
favglkmcha . pci_Y0 ) , 0 , 0 , 13 } , { ( char_T * ) ( & rtP . ouhnihomlde .
velocity_Y0 ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP . ouhnihomlde .
ncm_IterationLimit ) , 6 , 0 , 1 } , { ( char_T * ) ( & rtP . ouhnihomlde .
oy5rlkbq1z . velocity_Y0 ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
ouhnihomlde . oy5rlkbq1z . ForIterator_IterationLimit ) , 6 , 0 , 1 } , { (
char_T * ) ( & rtP . cuzz03aam2l . vci_Y0 ) , 0 , 0 , 15 } , { ( char_T * ) (
& rtP . fq0ya2wvxmr . position_Y0 ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
fq0ya2wvxmr . kvr32gbyca . position_Y0 ) , 0 , 0 , 2 } , { ( char_T * ) ( &
rtP . ok5kaek4lxs . pci_Y0 ) , 0 , 0 , 13 } , { ( char_T * ) ( & rtP .
lokzlwunnrr . velocity_Y0 ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP .
lokzlwunnrr . ForIterator_IterationLimit ) , 6 , 0 , 1 } , { ( char_T * ) ( &
rtP . l4lx4n4let5 . position_Y0 ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP .
f3bpn3lnkh . Bias1_Bias ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . ccrvxjn2zx
. Bias1_Bias ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . fbciyjdijrl . phi_Y0
) , 0 , 0 , 3 } , { ( char_T * ) ( & rtP . fbciyjdijrl . Switch_Threshold ) ,
2 , 0 , 1 } , { ( char_T * ) ( & rtP . ep1krdw3c3 . Bias1_Bias ) , 0 , 0 , 2
} , { ( char_T * ) ( & rtP . k3sfyh0c3kb . Bias1_Bias ) , 0 , 0 , 2 } } ;
static DataTypeTransitionTable rtPTransTable = { 38U , rtPTransitions } ;
