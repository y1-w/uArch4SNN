#include "SpikeMemReset.h"

void SpikeMemReset(struct SpikeMemList *spike_mem_list)
{
	int i;

	for(i=0; i<DEPTH_SPIKE_MEM; i++)
	{
		*((spike_mem_list->prespike_mem_0)+i) = 0;
		*((spike_mem_list->prespike_mem_1)+i) = 0;
		*((spike_mem_list->prespike_mem_2)+i) = 0;
		*((spike_mem_list->prespike_mem_3)+i) = 0;
		*((spike_mem_list->prespike_mem_4)+i) = 0;
		*((spike_mem_list->prespike_mem_5)+i) = 0;
		*((spike_mem_list->prespike_mem_6)+i) = 0;
		*((spike_mem_list->prespike_mem_7)+i) = 0;
		*((spike_mem_list->prespike_mem_8)+i) = 0;
		*((spike_mem_list->prespike_mem_9)+i) = 0;
		*((spike_mem_list->prespike_mem_10)+i) = 0;
		*((spike_mem_list->prespike_mem_12)+i) = 0;
		*((spike_mem_list->prespike_mem_13)+i) = 0;
		*((spike_mem_list->prespike_mem_14)+i) = 0;
		*((spike_mem_list->prespike_mem_15)+i) = 0;
	}
}
