#ifndef _PE_HEADER_
#define _PE_HEADER_

#include "global_vars.h"

//PE function declaration
int PE1(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, Potential_Mem_Type_ *next_poten);
int PE2(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, Potential_Mem_Type_ *next_poten);
int PE3(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, Potential_Mem_Type_ *next_poten);
int PE4(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, Potential_Mem_Type_ *next_poten);

#endif
