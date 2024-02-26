#include "cluster_scheduler.h"

void InitClstFlag(ap_uint<16> MaskClst, struct sClstInputPkg *ClstInputPkg, _reg_timestep InitTimeStep)
{
    ap_uint<5> idxClstID;

    for (idxClstID=0; idxClstID<NUM_TOTAL_CLUSTER; idxClstID++)
    {
        if(MaskClst[idxClstID]==1)
        {
            (ClstInputPkg+idxClstID)->ClstID = idxClstID;
            *((ClstInputPkg+idxClstID)->IdxInstrMem) = 0;
            *((ClstInputPkg+idxClstID)->ClstDone) = 0;
            *((ClstInputPkg+idxClstID)->ClstSync) = 0;
            *((ClstInputPkg+idxClstID)->TimeStep) = InitTimeStep;
        }
    }
}