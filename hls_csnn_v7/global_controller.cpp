#include "global_vars.h"
#include "cluster_0.h"
#include "misc.h"
#include "decoder.h"
#include "register_file.h"
#include "spike_scheduler.h"
#include "output_mem.h"
#include "PE.h"
#include "ALU.h"
#include "cluster_scheduler.h"
#include "cluster_1.h"
#include "cluster_2.h"
#include "cluster_3.h"
#include "cluster_4.h"
#include "cluster_5.h"
#include "cluster_6.h"
#include "cluster_7.h"
//#include <cstdio>

int SnnAcc(volatile ap_int<32> *ddr_0, int idx_ret, int testreg1, int testreg2, int in_mem_offset_0, int in_mem_length_0, int *clsf_result_0)
{
#pragma HLS INTERFACE m_axi depth=1200 port=ddr_0
#pragma HLS INTERFACE s_axilite port=return register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=idx_ret register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=testreg1 register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=testreg2 register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=in_mem_offset_0 register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=in_mem_length_0 register bundle=BUS_A
#pragma HLS INTERFACE s_axilite port=clsf_result_0 register bundle=BUS_A

	struct sClstInputPkg ClstInputPkg[NUM_TOTAL_CLUSTER];
	struct sClstOutputPkg ClstOutputPkg[NUM_TOTAL_CLUSTER];
	struct sOutputMemPkg OutputMemPkg[NUM_TOTAL_CLUSTER];
	struct sSpikeMemPkg SpikeMem[1];
    _reg_timestep GlobalTimeStep;
	int ret;

	/********************* initialize instruction memory ********************/
	InitInstrMem(ClstInputPkg);

    #ifdef TEST_LOG_PRINT
        printf("GLB--init instr memory finished. \n");
    #endif

	/********************* reset spike memory ********************/
	ResetSpikeMem(SpikeMem);
	ResetSpikeIdx(SpikeMem);

    #ifdef TEST_LOG_PRINT
        printf("GLB--init spike memory finished. \n");
    #endif

    /********************* reset output memory ********************/
    ResetOutputMem(OutputMemPkg, 0);
    ResetOutputMemIdx(OutputMemPkg, 0);

    #ifdef TEST_LOG_PRINT
        printf("GLB--init output memory finished. \n");
    #endif

	/********************* preparing input memory ********************/
	/*
    int retLoadImage = 0;
	while(!retLoadImage)
	{
		retLoadImage = LoadImage(ddr_0, ClstInputPkg->InputMem, in_mem_length_0, in_mem_offset_0);
	}
	 */
    InitSpikeMem(SpikeMem);

    #ifdef TEST_LOG_PRINT
        printf("GLB--input ---- omitted. \n");
    #endif

    #ifdef TEST_LOG_PRINT
        printf("GLB--run cluster begin. \n");
    #endif

	/********************* run cluster *************************/
    InitClstFlag(MASK_CLST_INIT_FLAG, ClstInputPkg, TIMESTEP_START_POINT);

    #ifdef TEST_LOG_PRINT
        int idxLoopNum = 0;
    #endif

    for (GlobalTimeStep = 1; GlobalTimeStep<=20; GlobalTimeStep++)
	{
        if (GlobalTimeStep<=testreg1)
        {
            RunCluster_0(0, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg);
            #ifdef TEST_FNL_PRINT
                printf("Timestep.%d, Clst.%d: %d spikes \n", int (GlobalTimeStep), 0, int(*(OutputMemPkg[0].IdxOutputMem)));
            #endif
            if (testreg2 == 0)
            {
                ret = *(OutputMemPkg[0].IdxOutputMem);
            }
            ScheduleSpikeMem(SpikeMem, OutputMemPkg, 0, 1);

            RunCluster_1(1, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg);
            #ifdef TEST_FNL_PRINT
                printf("Timestep.%d, Clst.%d: %d spikes \n", int (GlobalTimeStep), 1, int(*(OutputMemPkg[1].IdxOutputMem)));
            #endif
            if (testreg2 == 1)
            {
                ret = *(OutputMemPkg[1].IdxOutputMem);
            }
            ScheduleSpikeMem(SpikeMem, OutputMemPkg, 1, 1);
/*
            RunCluster_2(2, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg);
            #ifdef TEST_FNL_PRINT
                printf("Timestep.%d, Clst.%d: %d spikes \n", int (GlobalTimeStep), 2, int(*(OutputMemPkg[2].IdxOutputMem)));
            #endif
            if (testreg2 == 2)
            {
                ret = *(OutputMemPkg[2].IdxOutputMem);
            }
            ScheduleSpikeMem(SpikeMem, OutputMemPkg, 2, 1);

            RunCluster_3(3, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg);
            #ifdef TEST_FNL_PRINT
                printf("Timestep.%d, Clst.%d: %d spikes \n", int (GlobalTimeStep), 3, int(*(OutputMemPkg[3].IdxOutputMem)));
            #endif
            if (testreg2 == 3)
            {
                ret = *(OutputMemPkg[3].IdxOutputMem);
            }
            ScheduleSpikeMem(SpikeMem, OutputMemPkg, 3, 0);

            RunCluster_4(4, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg);
            #ifdef TEST_FNL_PRINT
                printf("Timestep.%d, Clst.%d: %d spikes \n", int (GlobalTimeStep), 4, int(*(OutputMemPkg[4].IdxOutputMem)));
            #endif
            if (testreg2 == 4)
            {
                ret = *(OutputMemPkg[4].IdxOutputMem);
            }
            ScheduleSpikeMem(SpikeMem, OutputMemPkg, 4, 1);

            RunCluster_5(5, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg);
            #ifdef TEST_FNL_PRINT
                printf("Timestep.%d, Clst.%d: %d spikes \n", int (GlobalTimeStep), 5, int(*(OutputMemPkg[5].IdxOutputMem)));
            #endif
            if (testreg2 == 5)
            {
                ret = *(OutputMemPkg[5].IdxOutputMem);
            }
*/
/*
            RunCluster_6(6, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg);
            #ifdef TEST_FNL_PRINT
                printf("Timestep.%d, Clst.%d: %d spikes \n", int (GlobalTimeStep), 6, int(*(OutputMemPkg[6].IdxOutputMem)));
            #endif
            if (testreg2 == 6)
            {
                ret = *(OutputMemPkg[6].IdxOutputMem);
            }

            RunCluster_7(7, ddr_0, ClstInputPkg, SpikeMem, OutputMemPkg, GlobalTimeStep, ClstOutputPkg);
            #ifdef TEST_FNL_PRINT
                printf("Timestep.%d, Clst.%d: %d spikes \n", int (GlobalTimeStep), 7, int(*(OutputMemPkg[7].IdxOutputMem)));
            #endif
            if (testreg2 == 7)
            {
                ret = *(OutputMemPkg[7].IdxOutputMem);
            }
*/
        }
    }

    #ifdef TEST_LOG_PRINT
        printf("GLB--classification ---- omitted. \n");
    #endif

    #ifdef TEST_FNL_PRINT
        printf("-------------------------------------------- Output C0 Print -------------------------------------- \n");

        int valNumOutput;
        valNumOutput = *(OutputMemPkg[0].IdxOutputMem);
        printf("Output spike of clst.0 number: %d. \n", valNumOutput);

        int PrintHigh;
        int PrintLow;

        int valRowOutput0;
        int valColOutput0;
        int valFeaOutput0;

        int idxOutputMem;
        for(idxOutputMem = 0; idxOutputMem < valNumOutput; idxOutputMem++)
        {
            PrintHigh = (OutputMemPkg[0].OutputMem[idxOutputMem])(63,32);
            PrintLow  = (OutputMemPkg[0].OutputMem[idxOutputMem])(31,0);

            valColOutput0 = (OutputMemPkg[0].OutputMem[idxOutputMem])(4,0);;
            valRowOutput0 = (OutputMemPkg[0].OutputMem[idxOutputMem])(9,5);
            valFeaOutput0 = (OutputMemPkg[0].OutputMem[idxOutputMem])(13,10);

            printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem, PrintHigh, PrintLow, valFeaOutput0+1, valRowOutput0+1, valColOutput0+1);
        }
    #endif


    #ifdef TEST_FNL_PRINT
    printf("-------------------------------------------- Output C1 Print -------------------------------------- \n");

    int valNumOutput1;
    valNumOutput1 = *(OutputMemPkg[1].IdxOutputMem);
    printf("Output spike of clst.1 number: %d. \n", valNumOutput1);

    int PrintHigh1;
    int PrintLow1;

    int valRowOutput1;
    int valColOutput1;
    int valFeaOutput1;

    int idxOutputMem1;
    for(idxOutputMem1 = 0; idxOutputMem1 < valNumOutput1; idxOutputMem1++)
    {
        PrintHigh1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(63,32);
        PrintLow1  = (OutputMemPkg[1].OutputMem[idxOutputMem1])(31,0);

        valColOutput1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(4,0);;
        valRowOutput1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(9,5);
        valFeaOutput1 = (OutputMemPkg[1].OutputMem[idxOutputMem1])(13,10);

        printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem1, PrintHigh1, PrintLow1, valFeaOutput1+1, valRowOutput1+1, valColOutput1+1);
    }
    #endif

    #ifdef TEST_FNL_PRINT
    printf("-------------------------------------------- Output C2 Print -------------------------------------- \n");

    int valNumOutput2;
    valNumOutput2 = *(OutputMemPkg[2].IdxOutputMem);
    printf("Output spike of clst.2 number: %d. \n", valNumOutput2);

    int PrintHigh2;
    int PrintLow2;

    int valRowOutput2;
    int valColOutput2;
    int valFeaOutput2;

    int idxOutputMem2;
    for(idxOutputMem2 = 0; idxOutputMem2 < valNumOutput2; idxOutputMem2++)
    {
        PrintHigh2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(63,32);
        PrintLow2  = (OutputMemPkg[2].OutputMem[idxOutputMem2])(31,0);

        valColOutput2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(3,0);;
        valRowOutput2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(7,4);
        valFeaOutput2 = (OutputMemPkg[2].OutputMem[idxOutputMem2])(14,8);

        printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem2, PrintHigh2, PrintLow2, valFeaOutput2+1, valRowOutput2+1, valColOutput2+1);
    }
    #endif


    #ifdef TEST_FNL_PRINT
    printf("-------------------------------------------- Output C3 Print -------------------------------------- \n");

    int valNumOutput3;
    valNumOutput3 = *(OutputMemPkg[3].IdxOutputMem);
    printf("Output spike of clst.3 number: %d. \n", valNumOutput3);

    int PrintHigh3;
    int PrintLow3;

    int valRowOutput3;
    int valColOutput3;
    int valFeaOutput3;

    int idxOutputMem3;
    for(idxOutputMem3 = 0; idxOutputMem3 < valNumOutput3; idxOutputMem3++)
    {
        PrintHigh3 = (OutputMemPkg[3].OutputMem[idxOutputMem3])(63,32);
        PrintLow3  = (OutputMemPkg[3].OutputMem[idxOutputMem3])(31,0);

        valColOutput3 = (OutputMemPkg[3].OutputMem[idxOutputMem3])(3,0);;
        valRowOutput3 = (OutputMemPkg[3].OutputMem[idxOutputMem3])(7,4);
        valFeaOutput3 = (OutputMemPkg[3].OutputMem[idxOutputMem3])(14,8);

        printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem3, PrintHigh3, PrintLow3, valFeaOutput3+1, valRowOutput3+1, valColOutput3+1);
    }
    #endif


#ifdef TEST_FNL_PRINT

    int valNumOutput4;
    int PrintHigh4;
    int PrintLow4;
    int valRowOutput4;
    int valColOutput4;
    int valFeaOutput4;
    int idxOutputMem4;
    int idx_clst_print_conv_output;

    for(idx_clst_print_conv_output=4; idx_clst_print_conv_output<8; idx_clst_print_conv_output++)
    {
        printf("-------------------------------------------- Output C%d Print -------------------------------------- \n", idx_clst_print_conv_output);

        valNumOutput4 = *(OutputMemPkg[idx_clst_print_conv_output].IdxOutputMem);
        printf("Output spike of clst.4 number: %d. \n", valNumOutput4);

        for(idxOutputMem4 = 0; idxOutputMem4 < valNumOutput4; idxOutputMem4++)
        {
            PrintHigh4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(63,32);
            PrintLow4  = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(31,0);

            valColOutput4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(3,0);;
            valRowOutput4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(7,4);
            valFeaOutput4 = (OutputMemPkg[idx_clst_print_conv_output].OutputMem[idxOutputMem4])(14,8);

            printf("OutputMem[%d] = 0x%x_%x. (%d,%d,%d). \n", idxOutputMem4, PrintHigh4, PrintLow4, valFeaOutput4+1, valRowOutput4+1, valColOutput4+1);
        }
    }

#endif

	/******************* output to the host **********************/
    //*clsf_result_0 = OutputMemPkg[testreg2].OutputMem[idx_ret];
	return ret;
}
