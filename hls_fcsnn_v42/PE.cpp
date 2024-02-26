#include "PE.h"

//int PE1(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, volatile Potential_Mem_Type_ next_poten[N_NEURONS_PER_PE])
int PE1(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, Potential_Mem_Type_ *next_poten)
{
    *(next_poten + index) = cur_poten + 1 * weight;
    return 1;
}

int PE2(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, Potential_Mem_Type_ *next_poten)
{
    *(next_poten + index) = cur_poten + 1 * weight;
    return 1;
}

int PE3(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, Potential_Mem_Type_ *next_poten)
{
    *(next_poten + index) = cur_poten + 1 * weight;
    return 1;
}

int PE4(Potential_Mem_Type_ cur_poten, Weight_Mem_Type_ weight, ap_uint<WIDTH_REG_FILE> index, Potential_Mem_Type_ *next_poten)
{
    *(next_poten + index) = cur_poten + 1 * weight;
    return 1;
}
