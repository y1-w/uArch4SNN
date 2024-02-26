#ifndef _CLS1_HEADER_
#define _CLS1_HEADER_

#include "global_vars.h"
#include "PE.h"
#include "ALU.h"
#include "SpikeController.h"
#include "SpikePointerReset.h"

int cluster_1(volatile ap_int<32> *ddr_0, struct SpikeMemList *spike_mem_list, ap_uint<1> *cluster_done, ap_uint<1> *cluster_exit, ap_uint<WIDTH_INSTR_MEM_pointer> *idx_instr, ap_uint<32> *time_step, ap_uint<WIDTH_IN_MEM_pointer> in_mem_idx, int *test, Potential_Mem_Type_ *potential_mem_PE1, Potential_Mem_Type_ *potential_mem_PE2, Potential_Mem_Type_ *potential_mem_PE3, Potential_Mem_Type_ *potential_mem_PE4);

#endif
