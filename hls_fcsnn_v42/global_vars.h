#ifndef _GLOBAL_CTRL_HEADER_
#define _GLOBAL_CTRL_HEADER_

#include "hls_stream.h"
#include "ap_int.h"
#include "ap_mem_if.h"
//#include "ap_cint.h"
//#include "sum_io.h"
//#include "pointer_stream_bad.h"

//about ddr
#define BASE_ADDR_DDR 0x000000000000

//number of instructions to be executed
#define NUM_CLUSTERS 16

//neuron allocation
#define N_NEURONS_PER_PE 300 //MAX_NUMBER

//hyper-parameter
#define FIRING_THRESHOLD 4194304

//registers for specific usage
#define REG_FILE_TIMESTEP 0
#define NUM_NEURONS_PERPE 5
#define DONE_EXECUTION 2
#define EXIT_EXECUTION 30
#define INPUT_MEM_IDX 9

//size of memory
#define DEPTH_INSTR_MEM 64
#define WIDTH_INSTR_MEM 32
#define DEPTH_WEIGHT_MEM 1024
#define WIDTH_WEIGHT_MEM 32
#define DEPTH_POTENTIAL_MEM 1024
#define WIDTH_POTENTIAL_MEM 32
#define DEPTH_INPUT_MEM 3072
#define WIDTH_INPUT_MEM 32
#define DEPTH_SPIKE_MEM 1024
#define WIDTH_SPIKE_MEM 32
#define WIDTH_SPIKE_MEM_pointer 10
#define WIDTH_IN_MEM_pointer 10
#define WIDTH_INSTR_MEM_pointer 10
#define DEPTH_REG_FILE 32
#define WIDTH_REG_FILE 32

//the data pattern in spike memory
#define NID_LSB 0
#define NID_MSB 15
#define TSTEP_LSB 16
#define TSTEP_MSB 23

//the data pattern in the instruction
#define PEMASK_LSB 0
#define PEMASK_MSB 3
#define CLUSTERMASK_LSB 4
#define CLUSTERMASK_MSB 19
#define IMM_LSB 0
#define IMM_MSB 15
#define REG_D_LSB 11
#define REG_D_MSB 15
#define FLAG_LSB 16
#define FLAG_MSB 17
#define REG_C_LSB 13
#define REG_C_MSB 17
#define REG_B_LSB 18
#define REG_B_MSB 22
#define REG_A_LSB 23
#define REG_A_MSB 27
#define OPCODE_LSB 28
#define OPCODE_MSB 31

//potential and weight memory type
#define Potential_Mem_Type_ ap_int<WIDTH_POTENTIAL_MEM>
#define Weight_Mem_Type_ ap_int<WIDTH_WEIGHT_MEM>
#define Spike_Mem_Type_ ap_uint<WIDTH_SPIKE_MEM>
#define Spike_Mem_Pointer_ ap_uint<WIDTH_SPIKE_MEM_pointer>

//define struct SpikeMemList

struct SpikeMemList {
	Spike_Mem_Type_ prespike_mem_0[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_1[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_2[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_3[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_4[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_5[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_6[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_7[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_8[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_9[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_10[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_11[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_12[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_13[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_14[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ prespike_mem_15[DEPTH_SPIKE_MEM];

	Spike_Mem_Pointer_ cur_addr_prespike_mem_0[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_1[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_2[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_3[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_4[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_5[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_6[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_7[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_8[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_9[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_10[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_11[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_12[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_13[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_14[1];
	Spike_Mem_Pointer_ cur_addr_prespike_mem_15[1];

	Spike_Mem_Pointer_ last_addr_prespike_mem_0[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_1[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_2[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_3[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_4[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_5[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_6[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_7[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_8[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_9[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_10[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_11[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_12[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_13[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_14[1];
	Spike_Mem_Pointer_ last_addr_prespike_mem_15[1];

	Spike_Mem_Type_ spike_mem_0[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_1[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_2[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_3[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_4[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_5[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_6[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_7[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_8[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_9[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_10[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_11[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_12[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_13[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_14[DEPTH_SPIKE_MEM];
	Spike_Mem_Type_ spike_mem_15[DEPTH_SPIKE_MEM];

	/*
	Spike_Mem_Pointer_ cur_addr_spike_mem_0[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_1[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_2[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_3[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_4[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_5[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_6[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_7[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_8[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_9[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_10[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_11[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_12[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_13[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_14[1];
	Spike_Mem_Pointer_ cur_addr_spike_mem_15[1];
	*/
};

#endif
