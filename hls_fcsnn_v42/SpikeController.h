#ifndef _SPKCTRL_HEADER_
#define _SPKCTRL_HEADER_

#include "global_vars.h"

int SpikeController(struct SpikeMemList *spike_mem_list, ap_uint<NUM_CLUSTERS> cluster_mask, ap_uint<WIDTH_SPIKE_MEM> input_spike);

#endif
