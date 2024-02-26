#include "global_vars.h"
#include "SpikePointerReset.h"
#include "SpikeMemReset.h"
#include "cluster_0.h"
#include "cluster_1.h"
#include "cluster_2.h"
//#include <cstdio>

int SnnAcc(volatile ap_int<32> *ddr_0, int idx_ret, int idx_spkm, int test, int in_mem_offset_0, int in_mem_length_0, int *clsf_result_0)
{
#pragma HLS INTERFACE m_axi depth=1200 port=ddr_0
#pragma HLS INTERFACE s_axilite port=return register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=test register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=idx_ret register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=idx_spkm register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=in_mem_offset_0 register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=in_mem_length_0 register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=clsf_result_0 register bundle=BUS_A

	/********************* cluster 0 ********************/
	ap_uint<1> cluster_0_done_src;
	ap_uint<1> *cluster_0_done;
	cluster_0_done = &cluster_0_done_src;

	ap_uint<1> cluster_0_exit_src;
	ap_uint<1> *cluster_0_exit;
	cluster_0_exit = &cluster_0_exit_src;

	ap_uint<WIDTH_INSTR_MEM_pointer> idx_instr_cluster_0_src;
	ap_uint<WIDTH_INSTR_MEM_pointer> *idx_instr_cluster_0;
	idx_instr_cluster_0 = &idx_instr_cluster_0_src;

	ap_uint<WIDTH_IN_MEM_pointer> in_mem_idx_0_src;
	ap_uint<WIDTH_IN_MEM_pointer> *in_mem_idx_0;
	in_mem_idx_0 = &in_mem_idx_0_src;

	Potential_Mem_Type_ potential_mem_PE0_cls0[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE1_cls0[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE2_cls0[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE3_cls0[DEPTH_POTENTIAL_MEM];

	ap_uint<WIDTH_INPUT_MEM> input_mem_cls0[DEPTH_INPUT_MEM];

    int idx_rst_ptn;
    for (idx_rst_ptn = 0 ; idx_rst_ptn < DEPTH_POTENTIAL_MEM; idx_rst_ptn++)
    {
    	potential_mem_PE0_cls0[idx_rst_ptn] = 0;
    	potential_mem_PE1_cls0[idx_rst_ptn] = 0;
    	potential_mem_PE2_cls0[idx_rst_ptn] = 0;
    	potential_mem_PE3_cls0[idx_rst_ptn] = 0;
    }

	/********************* cluster 1 ********************/
	ap_uint<1> cluster_1_done_src;
	ap_uint<1> *cluster_1_done;
	cluster_1_done = &cluster_1_done_src;

	ap_uint<1> cluster_1_exit_src;
	ap_uint<1> *cluster_1_exit;
	cluster_1_exit = &cluster_1_exit_src;

	ap_uint<WIDTH_INSTR_MEM_pointer> idx_instr_cluster_1_src;
	ap_uint<WIDTH_INSTR_MEM_pointer> *idx_instr_cluster_1;
	idx_instr_cluster_1 = &idx_instr_cluster_1_src;

	ap_uint<WIDTH_IN_MEM_pointer> in_mem_idx_1_src;
	ap_uint<WIDTH_IN_MEM_pointer> *in_mem_idx_1;
	in_mem_idx_1 = &in_mem_idx_1_src;

	Potential_Mem_Type_ potential_mem_PE0_cls1[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE1_cls1[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE2_cls1[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE3_cls1[DEPTH_POTENTIAL_MEM];

    for (idx_rst_ptn = 0 ; idx_rst_ptn < DEPTH_POTENTIAL_MEM; idx_rst_ptn++)
    {
    	potential_mem_PE0_cls1[idx_rst_ptn] = 0;
    	potential_mem_PE1_cls1[idx_rst_ptn] = 0;
    	potential_mem_PE2_cls1[idx_rst_ptn] = 0;
    	potential_mem_PE3_cls1[idx_rst_ptn] = 0;
    }

	/********************* cluster 2 ********************/
	ap_uint<1> cluster_2_done_src;
	ap_uint<1> *cluster_2_done;
	cluster_2_done = &cluster_2_done_src;

	ap_uint<1> cluster_2_exit_src;
	ap_uint<1> *cluster_2_exit;
	cluster_2_exit = &cluster_2_exit_src;

	ap_uint<WIDTH_INSTR_MEM_pointer> idx_instr_cluster_2_src;
	ap_uint<WIDTH_INSTR_MEM_pointer> *idx_instr_cluster_2;
	idx_instr_cluster_2 = &idx_instr_cluster_2_src;

	ap_uint<WIDTH_IN_MEM_pointer> in_mem_idx_2_src;
	ap_uint<WIDTH_IN_MEM_pointer> *in_mem_idx_2;
	in_mem_idx_2 = &in_mem_idx_2_src;

	Potential_Mem_Type_ potential_mem_PE0_cls2[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE1_cls2[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE2_cls2[DEPTH_POTENTIAL_MEM];
	Potential_Mem_Type_ potential_mem_PE3_cls2[DEPTH_POTENTIAL_MEM];

    for (idx_rst_ptn = 0 ; idx_rst_ptn < DEPTH_POTENTIAL_MEM; idx_rst_ptn++)
    {
    	potential_mem_PE0_cls2[idx_rst_ptn] = 0;
    	potential_mem_PE1_cls2[idx_rst_ptn] = 0;
    	potential_mem_PE2_cls2[idx_rst_ptn] = 0;
    	potential_mem_PE3_cls2[idx_rst_ptn] = 0;
    }


	/********************* global argument ********************/
	ap_uint<32> time_step_src;
	ap_uint<32> *time_step;
	time_step = &time_step_src;

	int ret;
	int ret_cluster_0;
	int ret_cluster_1;
	int ret_cluster_2;

	/*
	int cur_state;
	int next_state;
	ap_uint<1> flag_cur_tsp_unfinished;
	*/

	struct SpikeMemList spike_mem_list;
	struct SpikeMemList *spike_mem_list_handler;
	spike_mem_list_handler = &spike_mem_list;

	/********************* spike related reset ********************/
	SpikePointerReset(spike_mem_list_handler);
	SpikeMemReset(spike_mem_list_handler);

	/********************* processing per timestep ********************/
	in_mem_idx_0_src = 0;
	in_mem_idx_1_src = 0;
	in_mem_idx_2_src = 0;


	/********************* preparing input memory ********************/
	float inmem_cpy_times;
	int inmem_cpy_times_ceil;
	inmem_cpy_times = in_mem_length_0/300;
	inmem_cpy_times_ceil = ceil(inmem_cpy_times);
	int inmem_cpy_idx;


	for (inmem_cpy_idx=0; inmem_cpy_idx < 10; inmem_cpy_idx++)
	{
		if (inmem_cpy_idx < inmem_cpy_times_ceil)
		{
			memcpy(input_mem_cls0 + 300 * inmem_cpy_idx, (const ap_int<32> *)(ddr_0 + BASE_ADDR_DDR / 4 + 10000000 / 4 + in_mem_offset_0 + 300 * inmem_cpy_idx), 300 * sizeof(ap_int<32>));
		}
	}



	for (time_step_src = 1; time_step_src<= 35; time_step_src++)
	{
		/*****************************************/
		*idx_instr_cluster_0 = 0;
		*cluster_0_done = 0;
		*cluster_0_exit = 0;

		ret_cluster_0 = cluster_0(ddr_0, spike_mem_list_handler, cluster_0_done, cluster_0_exit, idx_instr_cluster_0, time_step, in_mem_idx_0_src, &test, potential_mem_PE0_cls0, potential_mem_PE1_cls0, potential_mem_PE2_cls0, potential_mem_PE3_cls0, input_mem_cls0);
		in_mem_idx_0_src = ret_cluster_0;

		/*****************************************/
		*idx_instr_cluster_1 = 0;
		*cluster_1_done = 0;
		*cluster_1_exit = 0;

		ret_cluster_1 = cluster_1(ddr_0, spike_mem_list_handler, cluster_1_done, cluster_1_exit, idx_instr_cluster_1, time_step, in_mem_idx_1_src, &test, potential_mem_PE0_cls1, potential_mem_PE1_cls1, potential_mem_PE2_cls1, potential_mem_PE3_cls1);
		in_mem_idx_1_src = ret_cluster_1;

		/*****************************************/
		*idx_instr_cluster_2 = 0;
		*cluster_2_done = 0;
		*cluster_2_exit = 0;

		ret_cluster_2 = cluster_2(ddr_0, spike_mem_list_handler, cluster_2_done, cluster_2_exit, idx_instr_cluster_2, time_step, in_mem_idx_2_src, &test, potential_mem_PE0_cls2, potential_mem_PE1_cls2, potential_mem_PE2_cls2, potential_mem_PE3_cls2);
		in_mem_idx_2_src = ret_cluster_2;
	}




	/*****************************************/
	SpikePointerReset(spike_mem_list_handler);


	/*****************************************/
	int clsf_rslt_cnt;
	int clsf_rslt_max_cnt = 0;
	int clsf_rslt_idx;
	int clsf_rslt_idx_inner;

	for(clsf_rslt_idx=0; clsf_rslt_idx < *(spike_mem_list_handler->last_addr_prespike_mem_3); clsf_rslt_idx++)
	{
		clsf_rslt_cnt = 1;
		for(clsf_rslt_idx_inner = clsf_rslt_idx+1; clsf_rslt_idx_inner < *(spike_mem_list_handler->last_addr_prespike_mem_3); clsf_rslt_idx_inner++)
		{
			if ((*((spike_mem_list_handler->prespike_mem_3) + clsf_rslt_idx_inner))(15,0)==(*((spike_mem_list_handler->prespike_mem_3) + clsf_rslt_idx))(15,0))
			{
				clsf_rslt_cnt++;
				if(clsf_rslt_cnt>clsf_rslt_max_cnt)
				{
					clsf_rslt_max_cnt = clsf_rslt_cnt;
					*clsf_result_0 = (*((spike_mem_list_handler->prespike_mem_3) + clsf_rslt_idx_inner))(15,0);
				}
			}
		}
	}


	/*****************************************/
	switch (idx_ret)
	{
	case 0:
	{
	    if (test >= 900)
	    	ret = potential_mem_PE3_cls0[test - 900];
	    else if (test >= 600)
	        ret = potential_mem_PE2_cls0[test - 600];
	    else if (test >= 300)
	        ret = potential_mem_PE1_cls0[test - 300];
	    else
	        ret = potential_mem_PE0_cls0[test];
	}
		break;

	case 1:
		ret = *(spike_mem_list_handler->last_addr_prespike_mem_1);
		break;

	case 2:
		ret = *((spike_mem_list_handler->prespike_mem_1) + idx_spkm);
		break;

	case 3:
	{
	    if (test >= 900)
	    	ret = potential_mem_PE3_cls1[test - 900];
	    else if (test >= 600)
	        ret = potential_mem_PE2_cls1[test - 600];
	    else if (test >= 300)
	        ret = potential_mem_PE1_cls1[test - 300];
	    else
	        ret = potential_mem_PE0_cls1[test];
	}
		break;

	case 4:
		ret = *(spike_mem_list_handler->last_addr_prespike_mem_2);
		break;

	case 5:
		ret = *((spike_mem_list_handler->prespike_mem_2) + idx_spkm);
		break;

	case 6:
	{
	    if (test >= 900)
	    	ret = potential_mem_PE3_cls2[test - 900];
	    else if (test >= 600)
	        ret = potential_mem_PE2_cls2[test - 600];
	    else if (test >= 300)
	        ret = potential_mem_PE1_cls2[test - 300];
	    else
	        ret = potential_mem_PE0_cls2[test];
	}
		break;

	case 7:
		ret = *(spike_mem_list_handler->last_addr_prespike_mem_3);
		break;

	case 8:
		ret = *((spike_mem_list_handler->prespike_mem_3) + idx_spkm);
		break;

	default:
		ret = 666;
		break;

	}

	return ret;
}
