#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_zvomUs9swg0LYolfrL6G0F" , 14 ,
136 } , { "struct_HTzNQs22w6v5kWcLiyRtWD" , 15 , 288 } , {
"struct_n3IamyhlWwVYarjrpVpPbF" , 16 , 288 } , {
"struct_6abjlDkQyd29d22lQVv5wH" , 17 , 96 } , {
"struct_eYFdmadaAEbmfNbyeiZ4KH" , 18 , 396808 } , {
"struct_ZtKgq7qQgrOMpDzzLZ17RD" , 19 , 472 } , {
"struct_N7noyS7OhT495NXnZH8zAG" , 20 , 80 } , {
"struct_SSrbxNhDAwveKzBnq5y3AG" , 21 , 128 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( struct_zvomUs9swg0LYolfrL6G0F ) , sizeof
( struct_HTzNQs22w6v5kWcLiyRtWD ) , sizeof ( struct_n3IamyhlWwVYarjrpVpPbF )
, sizeof ( struct_6abjlDkQyd29d22lQVv5wH ) , sizeof (
struct_eYFdmadaAEbmfNbyeiZ4KH ) , sizeof ( struct_ZtKgq7qQgrOMpDzzLZ17RD ) ,
sizeof ( struct_N7noyS7OhT495NXnZH8zAG ) , sizeof (
struct_SSrbxNhDAwveKzBnq5y3AG ) } ; static const char_T * rtDataTypeNames [ ]
= { "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "struct_zvomUs9swg0LYolfrL6G0F" ,
"struct_HTzNQs22w6v5kWcLiyRtWD" , "struct_n3IamyhlWwVYarjrpVpPbF" ,
"struct_6abjlDkQyd29d22lQVv5wH" , "struct_eYFdmadaAEbmfNbyeiZ4KH" ,
"struct_ZtKgq7qQgrOMpDzzLZ17RD" , "struct_N7noyS7OhT495NXnZH8zAG" ,
"struct_SSrbxNhDAwveKzBnq5y3AG" } ; static DataTypeTransition rtBTransitions
[ ] = { { ( char_T * ) ( & rtB . mbuf3ttyoj ) , 0 , 0 , 180969 } , { ( char_T
* ) ( & rtB . l0jloknu45 ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtB .
czqbc2hafpz . gzi3omxt3y [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
f2f5asy2qj . ehs4r2hz2y [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
cwkeianlye . ehs4r2hz2y [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
jse42y33cf . nm24payncx [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB .
glvqkwfsgg . nm24payncx [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB .
hdy13qwuxo . pmiuvoq3bk ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . gzjgdvz5xb
. ehs4r2hz2y [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . ep1nysc0kg .
bogcyvs5ln [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . iuykey3bat .
ehs4r2hz2y [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . onhb0tophc .
bogcyvs5ln [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . hh4puuamknj .
bogcyvs5ln [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . px30n50fob .
nm24payncx [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . ncfvgzcbsa .
nm24payncx [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . kfmgjpcbo0 .
gafarm32k2 [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . oa2h4lycyto .
jtgcw4sbk0 [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . pqreim41fnf .
ekmxe1wuqt [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB . eehz0nr2kbd .
ivoxddha1s . nxsqtyhezz [ 0 ] ) , 0 , 0 , 9 } , { ( char_T * ) ( & rtB .
j5jrka03lep . nkm03paxwo [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
nlh1krt5jh2 . do5ugpkgof [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB .
od5ryzaqzvr . cmzu1jjbu1 [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB .
meldjycwis . ehs4r2hz2y [ 0 ] ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB .
bq4wkncpnch . nm24payncx [ 0 ] ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtB .
mlcpngipio4 . pmiuvoq3bk ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtDW .
obcjv3kxjy [ 0 ] ) , 0 , 0 , 708 } , { ( char_T * ) ( & rtDW . n3envtb3nh .
LoggedData [ 0 ] ) , 11 , 0 , 37 } , { ( char_T * ) ( & rtDW . puckbncoc1 ) ,
6 , 0 , 1 } , { ( char_T * ) ( & rtDW . fmtbmkiyrg ) , 10 , 0 , 3 } , { (
char_T * ) ( & rtDW . ou4mxpicy1 ) , 2 , 0 , 39 } , { ( char_T * ) ( & rtDW .
gmx32akt1l [ 0 ] ) , 3 , 0 , 6 } , { ( char_T * ) ( & rtDW . onsfiqzaxb ) , 8
, 0 , 40 } , { ( char_T * ) ( & rtDW . hdy13qwuxo . lodlplndji ) , 0 , 0 , 1
} , { ( char_T * ) ( & rtDW . nw3ycnua5h . k2tbsd51jk ) , 2 , 0 , 1 } , { (
char_T * ) ( & rtDW . lwyp5so3rz . j4omgsrsfr ) , 2 , 0 , 1 } , { ( char_T *
) ( & rtDW . ku4t4kttcb . k2tbsd51jk ) , 2 , 0 , 1 } , { ( char_T * ) ( &
rtDW . cbthz0gwcs . j4omgsrsfr ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
bxw5fabqqg . k2tbsd51jk ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
njjq1lvqsq . j4omgsrsfr ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
hvkk5ldfab . k2tbsd51jk ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
kfz4qm0ehh . j4omgsrsfr ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
mlcpngipio4 . lodlplndji ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtDW .
p4zw5pk3wy . k2tbsd51jk ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
j2qjlobs3y . j4omgsrsfr ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
ebq2is5hcrm . k2tbsd51jk ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
oasjptnaiz4 . j4omgsrsfr ) , 2 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 46U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . DYN_ATT_par ) , 19 , 0 , 1 }
, { ( char_T * ) ( & rtP . CONSTANTS_par ) , 14 , 0 , 1 } , { ( char_T * ) (
& rtP . DYN_TRA_par ) , 21 , 0 , 1 } , { ( char_T * ) ( & rtP . DYN_AERO_par
) , 17 , 0 , 1 } , { ( char_T * ) ( & rtP . DYN_SC_par ) , 20 , 0 , 1 } , { (
char_T * ) ( & rtP . AerodynamicForcesandMoments_S ) , 0 , 0 , 160331 } , { (
char_T * ) ( & rtP . Constant_Value_pkbx0wcdbg ) , 6 , 0 , 30 } , { ( char_T
* ) ( & rtP . hdy13qwuxo . phi_Y0 ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtP .
hdy13qwuxo . Switch_Threshold ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtP .
lwyp5so3rz . Bias1_Bias ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . cbthz0gwcs
. Bias1_Bias ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . njjq1lvqsq .
Bias1_Bias ) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . kfz4qm0ehh . Bias1_Bias
) , 0 , 0 , 2 } , { ( char_T * ) ( & rtP . mlcpngipio4 . phi_Y0 ) , 0 , 0 , 3
} , { ( char_T * ) ( & rtP . mlcpngipio4 . Switch_Threshold ) , 2 , 0 , 1 } ,
{ ( char_T * ) ( & rtP . j2qjlobs3y . Bias1_Bias ) , 0 , 0 , 2 } , { ( char_T
* ) ( & rtP . oasjptnaiz4 . Bias1_Bias ) , 0 , 0 , 2 } } ; static
DataTypeTransitionTable rtPTransTable = { 17U , rtPTransitions } ;
