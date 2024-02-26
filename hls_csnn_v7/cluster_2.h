#ifndef _CLS2_HEADER_
#define _CLS2_HEADER_

#include "global_vars.h"
#include "PE.h"
#include "ALU.h"
#include "spike_scheduler.h"
#include "decoder.h"
#include "register_file.h"
#include "output_mem.h"
#include "weight_init.h"
#include "potential_init.h"
#include "executer.h"

sClstOutputPkg Cluster_2(volatile ap_int<32> *ddr_0, struct sClstInputPkg *ClstInputPkg, struct sSpikeMemPkg *SpikeMemPkg, struct sOutputMemPkg OutputMemPkg);
void RunCluster_2(ap_uint<4> ClusterID, volatile ap_int<32> *ddr_0, struct sClstInputPkg *ClstInputPkg, struct sSpikeMemPkg *SpikeMemPkg, struct sOutputMemPkg *OutputMemPkg, _reg_timestep GlobalTimeStep, struct sClstOutputPkg *ClstOutputPkg);

#endif
