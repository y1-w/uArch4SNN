#include "SpikeController.h"

int SpikeController(struct SpikeMemList *spike_mem_list, ap_uint<NUM_CLUSTERS> cluster_mask, ap_uint<WIDTH_SPIKE_MEM> input_spike)
{
    Spike_Mem_Type_ *prespike_mem_0;
    Spike_Mem_Type_ *prespike_mem_1;
    Spike_Mem_Type_ *prespike_mem_2;
    Spike_Mem_Type_ *prespike_mem_3;
    Spike_Mem_Type_ *prespike_mem_4;
    Spike_Mem_Type_ *prespike_mem_5;
    Spike_Mem_Type_ *prespike_mem_6;
    Spike_Mem_Type_ *prespike_mem_7;
    Spike_Mem_Type_ *prespike_mem_8;
    Spike_Mem_Type_ *prespike_mem_9;
    Spike_Mem_Type_ *prespike_mem_10;
    Spike_Mem_Type_ *prespike_mem_11;
    Spike_Mem_Type_ *prespike_mem_12;
    Spike_Mem_Type_ *prespike_mem_13;
    Spike_Mem_Type_ *prespike_mem_14;
    Spike_Mem_Type_ *prespike_mem_15;

    prespike_mem_0 = spike_mem_list->prespike_mem_0;
    prespike_mem_1 = spike_mem_list->prespike_mem_1;
    prespike_mem_2 = spike_mem_list->prespike_mem_2;
    prespike_mem_3 = spike_mem_list->prespike_mem_3;
    prespike_mem_4 = spike_mem_list->prespike_mem_4;
    prespike_mem_5 = spike_mem_list->prespike_mem_5;
    prespike_mem_6 = spike_mem_list->prespike_mem_6;
    prespike_mem_7 = spike_mem_list->prespike_mem_7;
    prespike_mem_8 = spike_mem_list->prespike_mem_8;
    prespike_mem_9 = spike_mem_list->prespike_mem_9;
    prespike_mem_10 = spike_mem_list->prespike_mem_10;
    prespike_mem_11 = spike_mem_list->prespike_mem_11;
    prespike_mem_12 = spike_mem_list->prespike_mem_12;
    prespike_mem_13 = spike_mem_list->prespike_mem_13;
    prespike_mem_14 = spike_mem_list->prespike_mem_14;
    prespike_mem_15 = spike_mem_list->prespike_mem_15;

    Spike_Mem_Pointer_ *cur_addr_prespike_mem_0;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_1;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_2;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_3;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_4;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_5;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_6;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_7;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_8;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_9;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_10;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_11;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_12;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_13;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_14;
    Spike_Mem_Pointer_ *cur_addr_prespike_mem_15;

    cur_addr_prespike_mem_0 = spike_mem_list->cur_addr_prespike_mem_0;
    cur_addr_prespike_mem_1 = spike_mem_list->cur_addr_prespike_mem_1;
    cur_addr_prespike_mem_2 = spike_mem_list->cur_addr_prespike_mem_2;
    cur_addr_prespike_mem_3 = spike_mem_list->cur_addr_prespike_mem_3;
    cur_addr_prespike_mem_4 = spike_mem_list->cur_addr_prespike_mem_4;
    cur_addr_prespike_mem_5 = spike_mem_list->cur_addr_prespike_mem_5;
    cur_addr_prespike_mem_6 = spike_mem_list->cur_addr_prespike_mem_6;
    cur_addr_prespike_mem_7 = spike_mem_list->cur_addr_prespike_mem_7;
    cur_addr_prespike_mem_8 = spike_mem_list->cur_addr_prespike_mem_8;
    cur_addr_prespike_mem_9 = spike_mem_list->cur_addr_prespike_mem_9;
    cur_addr_prespike_mem_10 = spike_mem_list->cur_addr_prespike_mem_10;
    cur_addr_prespike_mem_11 = spike_mem_list->cur_addr_prespike_mem_11;
    cur_addr_prespike_mem_12 = spike_mem_list->cur_addr_prespike_mem_12;
    cur_addr_prespike_mem_13 = spike_mem_list->cur_addr_prespike_mem_13;
    cur_addr_prespike_mem_14 = spike_mem_list->cur_addr_prespike_mem_14;
    cur_addr_prespike_mem_15 = spike_mem_list->cur_addr_prespike_mem_15;

    if (cluster_mask(15,15)==1)
    {
        prespike_mem_0[*cur_addr_prespike_mem_0] = input_spike;
        (*cur_addr_prespike_mem_0)++;
    }

    if (cluster_mask(14, 14) == 1)
    {
        prespike_mem_1[*cur_addr_prespike_mem_1] = input_spike;
        (*cur_addr_prespike_mem_1)++;
    }

    if (cluster_mask(13, 13) == 1)
    {
        prespike_mem_2[*cur_addr_prespike_mem_2] = input_spike;
        (*cur_addr_prespike_mem_2)++;
    }

    if (cluster_mask(12, 12) == 1)
    {
        prespike_mem_3[*cur_addr_prespike_mem_3] = input_spike;
        (*cur_addr_prespike_mem_3)++;
    }

    if (cluster_mask(11, 11) == 1)
    {
        prespike_mem_4[*cur_addr_prespike_mem_4] = input_spike;
        (*cur_addr_prespike_mem_4)++;
    }

    if (cluster_mask(10, 10) == 1)
    {
        prespike_mem_5[*cur_addr_prespike_mem_5] = input_spike;
        (*cur_addr_prespike_mem_5)++;
    }

    if (cluster_mask(9, 9) == 1)
    {
        prespike_mem_6[*cur_addr_prespike_mem_6] = input_spike;
        (*cur_addr_prespike_mem_6)++;
    }

    if (cluster_mask(8, 8) == 1)
    {
        prespike_mem_7[*cur_addr_prespike_mem_7] = input_spike;
        (*cur_addr_prespike_mem_7)++;
    }

    if (cluster_mask(7, 7) == 1)
    {
        prespike_mem_8[*cur_addr_prespike_mem_8] = input_spike;
        (*cur_addr_prespike_mem_8)++;
    }

    if (cluster_mask(6, 6) == 1)
    {
        prespike_mem_9[*cur_addr_prespike_mem_9] = input_spike;
        (*cur_addr_prespike_mem_9)++;
    }

    if (cluster_mask(5, 5) == 1)
    {
        prespike_mem_10[*cur_addr_prespike_mem_10] = input_spike;
        (*cur_addr_prespike_mem_10)++;
    }

    if (cluster_mask(4, 4) == 1)
    {
        prespike_mem_11[*cur_addr_prespike_mem_11] = input_spike;
        (*cur_addr_prespike_mem_11)++;
    }

    if (cluster_mask(3, 3) == 1)
    {
        prespike_mem_12[*cur_addr_prespike_mem_12] = input_spike;
        (*cur_addr_prespike_mem_12)++;
    }

    if (cluster_mask(2, 2) == 1)
    {
        prespike_mem_13[*cur_addr_prespike_mem_13] = input_spike;
        (*cur_addr_prespike_mem_13)++;
    }

    if (cluster_mask(1, 1) == 1)
    {
        prespike_mem_14[*cur_addr_prespike_mem_14] = input_spike;
        (*cur_addr_prespike_mem_14)++;
    }

    if (cluster_mask(0, 0) == 1)
    {
        prespike_mem_15[*cur_addr_prespike_mem_15] = input_spike;
        (*cur_addr_prespike_mem_15)++;
    }
    return 1;
}
