#ifndef _MISC_HEADER_
#define _MISC_HEADER_

#include "global_vars.h"

void InitInstrMem(struct sClstInputPkg *ClstInputPkg);
void InitSpikeMem(struct sSpikeMemPkg *SpikeMemPkg);
//int LoadImage(volatile ap_int<32> *ddr_0, _input_mem *InputMem, int in_mem_length_0, int in_mem_offset_0);
//int FinalClassify(_idx_spike_mem *numSpikeTotal, _spike_mem *SpikeMem);

#endif
