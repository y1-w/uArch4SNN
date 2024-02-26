#include "SpikePointerReset.h"

void SpikePointerReset(struct SpikeMemList *spike_mem_list)
{

    *(spike_mem_list->last_addr_prespike_mem_0) = *(spike_mem_list->cur_addr_prespike_mem_0);
    *(spike_mem_list->last_addr_prespike_mem_1) = *(spike_mem_list->cur_addr_prespike_mem_1);
    *(spike_mem_list->last_addr_prespike_mem_2) = *(spike_mem_list->cur_addr_prespike_mem_2);
    *(spike_mem_list->last_addr_prespike_mem_3) = *(spike_mem_list->cur_addr_prespike_mem_3);
    *(spike_mem_list->last_addr_prespike_mem_4) = *(spike_mem_list->cur_addr_prespike_mem_4);
    *(spike_mem_list->last_addr_prespike_mem_5) = *(spike_mem_list->cur_addr_prespike_mem_5);
    *(spike_mem_list->last_addr_prespike_mem_6) = *(spike_mem_list->cur_addr_prespike_mem_6);
    *(spike_mem_list->last_addr_prespike_mem_7) = *(spike_mem_list->cur_addr_prespike_mem_7);
    *(spike_mem_list->last_addr_prespike_mem_8) = *(spike_mem_list->cur_addr_prespike_mem_8);
    *(spike_mem_list->last_addr_prespike_mem_9) = *(spike_mem_list->cur_addr_prespike_mem_9);
    *(spike_mem_list->last_addr_prespike_mem_10) = *(spike_mem_list->cur_addr_prespike_mem_10);
    *(spike_mem_list->last_addr_prespike_mem_11) = *(spike_mem_list->cur_addr_prespike_mem_11);
    *(spike_mem_list->last_addr_prespike_mem_12) = *(spike_mem_list->cur_addr_prespike_mem_12);
    *(spike_mem_list->last_addr_prespike_mem_13) = *(spike_mem_list->cur_addr_prespike_mem_13);
    *(spike_mem_list->last_addr_prespike_mem_14) = *(spike_mem_list->cur_addr_prespike_mem_14);
    *(spike_mem_list->last_addr_prespike_mem_15) = *(spike_mem_list->cur_addr_prespike_mem_15);

    *(spike_mem_list->cur_addr_prespike_mem_0) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_1) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_2) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_3) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_4) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_5) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_6) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_7) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_8) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_9) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_10) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_11) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_12) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_13) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_14) = 0;
    *(spike_mem_list->cur_addr_prespike_mem_15) = 0;

}
