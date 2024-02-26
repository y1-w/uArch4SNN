#include "cluster_1.h"

#define CURRENT_CLUSTER_ID 					1
#define CURRENT_CLUSTER_SPIKEMEM 			spike_mem_1
#define CURRENT_CLUSTER_PRESPIKEMEM 		prespike_mem_1
#define CURRENT_CLUSTER_NUM_PRESPIKEMEM 	cur_addr_prespike_mem_1

#define DDR_ADDR_SHIFT_CLST					940800						//3763200/4
#define NUM_PRENEURON						1200

int cluster_1(volatile ap_int<32> *ddr_0, struct SpikeMemList *spike_mem_list, ap_uint<1> *cluster_done, ap_uint<1> *cluster_exit, ap_uint<WIDTH_INSTR_MEM_pointer> *idx_instr, ap_uint<32> *time_step, ap_uint<WIDTH_IN_MEM_pointer> in_mem_idx, int *test, Potential_Mem_Type_ *potential_mem_PE1, Potential_Mem_Type_ *potential_mem_PE2, Potential_Mem_Type_ *potential_mem_PE3, Potential_Mem_Type_ *potential_mem_PE4)
{
    Spike_Mem_Pointer_ num_spike_queue = 0;
    int ret;

    /*******************************************************************************/
	Spike_Mem_Type_ *spike_mem;
	Spike_Mem_Type_ *prespike_mem;

	//spike_mem = spike_mem_list->CURRENT_CLUSTER_SPIKEMEM;
	prespike_mem = spike_mem_list->CURRENT_CLUSTER_PRESPIKEMEM;

    /*******************************************************************************/
    ap_uint<WIDTH_WEIGHT_MEM> PE1_weight;
    Potential_Mem_Type_ PE1_cur_poten;
    Potential_Mem_Type_ PE1_next_poten[N_NEURONS_PER_PE];
    ap_uint<1> PE1_done;

    ap_uint<WIDTH_WEIGHT_MEM> PE2_weight;
    Potential_Mem_Type_ PE2_cur_poten;
    Potential_Mem_Type_ PE2_next_poten[N_NEURONS_PER_PE];
    ap_uint<1> PE2_done;

    ap_uint<WIDTH_WEIGHT_MEM> PE3_weight;
    Potential_Mem_Type_ PE3_cur_poten;
    Potential_Mem_Type_ PE3_next_poten[N_NEURONS_PER_PE];
    ap_uint<1> PE3_done;

    ap_uint<WIDTH_WEIGHT_MEM> PE4_weight;
    Potential_Mem_Type_ PE4_cur_poten;
    Potential_Mem_Type_ PE4_next_poten[N_NEURONS_PER_PE];
    ap_uint<1> PE4_done;

    /*******************************************************************************/
    ap_uint<WIDTH_SPIKE_MEM> reg_spike_PE1;
    ap_uint<WIDTH_SPIKE_MEM> reg_spike_PE2;
    ap_uint<WIDTH_SPIKE_MEM> reg_spike_PE3;
    ap_uint<WIDTH_SPIKE_MEM> reg_spike_PE4;
    reg_spike_PE1 = 0;
    reg_spike_PE2 = 0;
    reg_spike_PE3 = 0;
    reg_spike_PE4 = 0;

    /*******************************************************************************/
    ap_uint<WIDTH_SPIKE_MEM> rdi_reg;
    ap_uint<WIDTH_SPIKE_MEM> rds_reg;

    /*******************************************************************************/
    ap_uint<WIDTH_REG_FILE> reg_ldw_dest_addr;
    ap_uint<WIDTH_REG_FILE> reg_ldw_src_addr;
    ap_uint<WIDTH_REG_FILE> reg_ldw_size;

    /*******************************************************************************/
    ap_uint<NUM_CLUSTERS> reg_cluster_mask_PE1;
    ap_uint<NUM_CLUSTERS> reg_cluster_mask_PE2;
    ap_uint<NUM_CLUSTERS> reg_cluster_mask_PE3;
    ap_uint<NUM_CLUSTERS> reg_cluster_mask_PE4;
    ap_uint<1> done_spk_wrt_PE1=0;
    ap_uint<1> done_spk_wrt_PE2=0;
    ap_uint<1> done_spk_wrt_PE3=0;
    ap_uint<1> done_spk_wrt_PE4=0;

    /*******************************************************************************/
	ap_uint<WIDTH_INSTR_MEM> instr_mem[DEPTH_INSTR_MEM];
//#pragma HLS RESOURCE variable=instr_mem core=RAM_T2P_BRAM
	Weight_Mem_Type_ weight_mem_PE1[DEPTH_WEIGHT_MEM];
	//Potential_Mem_Type_ potential_mem_PE1[DEPTH_POTENTIAL_MEM];
	Weight_Mem_Type_ weight_mem_PE2[DEPTH_WEIGHT_MEM];
	//Potential_Mem_Type_ potential_mem_PE2[DEPTH_POTENTIAL_MEM];
	Weight_Mem_Type_ weight_mem_PE3[DEPTH_WEIGHT_MEM];
	//Potential_Mem_Type_ potential_mem_PE3[DEPTH_POTENTIAL_MEM];
	Weight_Mem_Type_ weight_mem_PE4[DEPTH_WEIGHT_MEM];
	//Potential_Mem_Type_ potential_mem_PE4[DEPTH_POTENTIAL_MEM];
	ap_uint<WIDTH_INPUT_MEM> input_mem[DEPTH_INPUT_MEM];
	ap_uint<WIDTH_REG_FILE> registerfile[DEPTH_REG_FILE];
#pragma HLS ARRAY_PARTITION variable=registerfile complete dim=0

    /*******************************************************************************/

    instr_mem[  0] = 0b00000000000010000000000000000000;    //mov done, #00, #0,
    instr_mem[  1] = 0b00000000011111000000000011111111;    //mov r31, #00, 0xFF,
    instr_mem[  2] = 0b00000000000011000000000000000000;    //mov src_id, #00, #0,
    instr_mem[  3] = 0b00000000000101000000000100101100;    //mov num, #00, d300,
    instr_mem[  4] = 0b10010001101010010010000000000000;    //rds src_id, spike_step, input_spike_idx,
    instr_mem[  5] = 0b01010101000000000000000000000111;    //beq spike_step, time_step, !HL1_handle_init,
    instr_mem[  6] = 0b01100101000000000000000000010010;    //bneq spike_step, time_step, !HL1_ckf_init,
    instr_mem[  7] = 0b00000000000110000000000000000000;    //mov potential_addr, #00, #0,
    instr_mem[  8] = 0b00100011100011000000000100101100;    //mul weight_ddr_addr, src_id, #00, d300
    instr_mem[  9] = 0b00000000001000000000000000000000;    //mov weight_addr, #00, #0, d300
    instr_mem[ 10] = 0b10100100000111001010000000001111;    //ldw weight_addr, weight_ddr_addr, num, #1111
    instr_mem[ 11] = 0b10110100000110000000000000001111;    //rwp weight_addr, potential_addr, #1111, #1111
    instr_mem[ 12] = 0b11000011000000000000000000001111;    //acc potential_addr, #1111, #1111, #1111
    instr_mem[ 13] = 0b00010011000110000000000000000001;    //add potential_addr, potential_addr, #00, #1
    instr_mem[ 14] = 0b00010100001000000000000000000001;    //add weight_addr, weight_addr, #00, #1
    instr_mem[ 15] = 0b01100011000101000000000000001011;    //bneq potential_addr, num, !HL1_handle, #1
    instr_mem[ 16] = 0b00010100101001000000000000000001;    //add input_spike_idx, input_spike_idx, #00, #1
    instr_mem[ 17] = 0b01110000000000000000000000000100;    //jmp !HL1_read_input_spikes, input_spike_idx, #00, #1
    instr_mem[ 18] = 0b00000000000100000000000000000000;    //mov potential_idx, #00, #0, #1
    instr_mem[ 19] = 0b11010010000000100000000000001111;    //ckf potential_idx, #0010000000000000, #1111, #1
    instr_mem[ 20] = 0b00010010000100000000000000000001;    //add potential_idx, potential_idx, #00, #1
    instr_mem[ 21] = 0b01100010000101000000000000010011;    //bneq potential_idx, num, !HL1_ckf, #1
    instr_mem[ 22] = 0b00000000000010000000000000000001;    //mov done, #00, #1, #1


    /*
    int idx_rst_ptn;
    for (idx_rst_ptn = 0 ; idx_rst_ptn < DEPTH_POTENTIAL_MEM; idx_rst_ptn++)
    {
    	potential_mem_PE1[idx_rst_ptn] = 0;
    	potential_mem_PE2[idx_rst_ptn] = 0;
    	potential_mem_PE3[idx_rst_ptn] = 0;
    	potential_mem_PE4[idx_rst_ptn] = 0;
    }
	*/


    /****************************************************************/
    registerfile[REG_FILE_TIMESTEP] = *time_step;
    registerfile[INPUT_MEM_IDX] = in_mem_idx;

    /****************************************************************/
    main_while:
    while (!(*cluster_exit) && !(*cluster_done))
    {
        //*test = instr_mem[(*idx_instr)](OPCODE_MSB, OPCODE_LSB);

        switch (instr_mem[(*idx_instr)](OPCODE_MSB, OPCODE_LSB))
        {
        case 0:
            //mov
            //(31,28)  (27,23)  (22,18)  (17,16)  (15,0)
            //opcode   00000    RB		 flag=00  IMM
            //(31,28)  (27,23)  (22,18)  (17,16)  (15,11)
            //opcode   00000    RB		 flag!=0  RD
            if (instr_mem[(*idx_instr)](FLAG_MSB, FLAG_LSB) == 0)
            {
                registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)] = instr_mem[(*idx_instr)](IMM_MSB, IMM_LSB);
            }
            else
            {
                registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)] = registerfile[instr_mem[(*idx_instr)](REG_D_MSB, REG_D_LSB)];
            }

            /***********************************************/
            if (registerfile[DONE_EXECUTION] == 1)
            {
                *cluster_done = 1;
                //*cluster_exit = 1;
                in_mem_idx = registerfile[INPUT_MEM_IDX];
            }

            (*idx_instr)++;
            break;

        case 1:
            //add
            //(31,28)  (27,23)  (22,18)  (17,16)  (15,0)
            //opcode   RA       RB       flag=00  IMM
            //(31,28)  (27,23)  (22,18)  (17,16)  (15,11)
            //opcode   RA       RB       flag!=0  RD
            if (instr_mem[(*idx_instr)](FLAG_MSB, FLAG_LSB) == 0)
            {
                registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] = ALU(registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)], instr_mem[(*idx_instr)](IMM_MSB, IMM_LSB), 0);
            }
            else
            {
                registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] = ALU(registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)], registerfile[instr_mem[(*idx_instr)](REG_D_MSB, REG_D_LSB)], 0);
            }

        	/***********************************************/
            in_mem_idx = registerfile[INPUT_MEM_IDX];

            (*idx_instr)++;
            break;

        case 2:
            //mul
            //(31,28)  (27,23)  (22,18)  (17,16)  (15,0)
            //opcode   RA       RB       flag=00  IMM
            //(31,28)  (27,23)  (22,18)  (17,16)  (15,11)
            //opcode   RA       RB       flag!=0  RD
            if (instr_mem[(*idx_instr)](FLAG_MSB, FLAG_LSB) == 0)
            {
                registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] = ALU(registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)], instr_mem[(*idx_instr)](IMM_MSB, IMM_LSB), 1);
            }
            else
            {
                registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] = ALU(registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)], registerfile[instr_mem[(*idx_instr)](REG_D_MSB, REG_D_LSB)], 1);
            }

            (*idx_instr)++;
            break;

        case 3:
            //sft
            //(31,28)  (27,23)  (15,0)
            //opcode   RA       IMM
            registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] = ALU(registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)], instr_mem[(*idx_instr)](IMM_MSB, IMM_LSB), 2);

            (*idx_instr)++;
            break;

        case 4:
            //mod
            //(31,28)  (27,23)  (15,0)
            //opcode   RA       IMM
            registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] = ALU(registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)], instr_mem[(*idx_instr)](IMM_MSB, IMM_LSB), 3);

            (*idx_instr)++;
            break;

        case 5:
            //beq
            //(31,28)  (27,23)  (22,18)  (15,0)
            //opcode   RA       RB       IMM
            if (registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] == registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)])
                (*idx_instr) = instr_mem[(*idx_instr)](IMM_MSB, IMM_LSB);
            else
                (*idx_instr)++;

            break;

        case 6:
            //bneq
            //(31,28)  (27,23)  (22,18)  (15,0)
            //opcode   RA       RB       IMM
            if (registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] != registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)])
                (*idx_instr) = instr_mem[(*idx_instr)](IMM_MSB, IMM_LSB);
            else
                (*idx_instr)++;

            break;

        case 7:
            //jmp
            //(31,28)  (15,0)
            //opcode   IMM
            (*idx_instr) = instr_mem[(*idx_instr)](IMM_MSB, IMM_LSB);

            break;

        case 8:
            //rdi
            //(31,28)  (27,23)  (22,18)  (17,13)
            //opcode   RA       RB		 RC
            rdi_reg = input_mem[registerfile[instr_mem[(*idx_instr)](REG_C_MSB, REG_C_LSB)]];                                    //read from input memory
            registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] = rdi_reg(NID_MSB, NID_LSB);     //nid
            registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)] = rdi_reg(TSTEP_MSB, TSTEP_LSB); //timestep

            (*idx_instr)++;
            break;

        case 9:
            //rds
            //(31,28)  (27,23)  (22,18)  (17,13)
            //opcode   RA       RB		 RC
            rds_reg = prespike_mem[registerfile[instr_mem[(*idx_instr)](REG_C_MSB, REG_C_LSB)]];
            registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] = rds_reg(NID_MSB, NID_LSB);     //nid
            registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)] = rds_reg(TSTEP_MSB, TSTEP_LSB); //timestep

            (*idx_instr)++;
            break;

        case 10:
            //ldw
            //(31,28)  (27,23)  (22,18)  (17,13)  (3,0)
            //opcode   RA       RB		 RC		  PEMASK
            reg_ldw_dest_addr = registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)];
            reg_ldw_src_addr = registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)];
            reg_ldw_size = registerfile[instr_mem[(*idx_instr)](REG_C_MSB, REG_C_LSB)];

            if (instr_mem[(*idx_instr)](0, 0))
            {
                memcpy(weight_mem_PE1 + reg_ldw_dest_addr, (const ap_int<32> *)(ddr_0 + BASE_ADDR_DDR / 4 + reg_ldw_src_addr + reg_ldw_size * NUM_PRENEURON * 0 + DDR_ADDR_SHIFT_CLST), reg_ldw_size * sizeof(ap_int<32>));
            }

            if (instr_mem[(*idx_instr)](1, 1))
            {
                memcpy(weight_mem_PE2 + reg_ldw_dest_addr, (const ap_int<32> *)(ddr_0 + BASE_ADDR_DDR / 4 + reg_ldw_src_addr + reg_ldw_size * NUM_PRENEURON * 1 + DDR_ADDR_SHIFT_CLST), reg_ldw_size * sizeof(ap_int<32>));
            }

            if (instr_mem[(*idx_instr)](2, 2))
            {
                memcpy(weight_mem_PE3 + reg_ldw_dest_addr, (const ap_int<32> *)(ddr_0 + BASE_ADDR_DDR / 4 + reg_ldw_src_addr + reg_ldw_size * NUM_PRENEURON * 2 + DDR_ADDR_SHIFT_CLST), reg_ldw_size * sizeof(ap_int<32>));
            }

            if (instr_mem[(*idx_instr)](3, 3))
            {
                memcpy(weight_mem_PE4 + reg_ldw_dest_addr, (const ap_int<32> *)(ddr_0 + BASE_ADDR_DDR / 4 + reg_ldw_src_addr + reg_ldw_size * NUM_PRENEURON * 3 + DDR_ADDR_SHIFT_CLST), reg_ldw_size * sizeof(ap_int<32>));
            }

            (*idx_instr)++;
            break;

        case 11:
            //rwp
            //(31,28)  (27,23)  (22,18)  (3,0)
            //opcode   RA       RB		 PE_MASK
            if (instr_mem[(*idx_instr)](0, 0))
            {
                PE1_weight = weight_mem_PE1[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]];
                PE1_cur_poten = potential_mem_PE1[registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)]];
            }

            if (instr_mem[(*idx_instr)](1, 1))
            {
                PE2_weight = weight_mem_PE2[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]];
                PE2_cur_poten = potential_mem_PE2[registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)]];
            }

            if (instr_mem[(*idx_instr)](2, 2))
            {
                PE3_weight = weight_mem_PE3[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]];
                PE3_cur_poten = potential_mem_PE3[registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)]];
            }

            if (instr_mem[(*idx_instr)](3,3))
            {
                PE4_weight = weight_mem_PE4[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]];
                PE4_cur_poten = potential_mem_PE4[registerfile[instr_mem[(*idx_instr)](REG_B_MSB, REG_B_LSB)]];
            }

            (*idx_instr)++;
            break;

        case 12:
            //acc
            //(31,28)  (27,23)  (3,0)
            //opcode   RA		PE_MASK
            if (instr_mem[(*idx_instr)](0, 0))
            {
                PE1_done = PE1(PE1_cur_poten, PE1_weight, registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)], PE1_next_poten);
            	potential_mem_PE1[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] = PE1_next_poten[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]];
            }

            if (instr_mem[(*idx_instr)](1, 1))
            {
                PE2_done = PE2(PE2_cur_poten, PE2_weight, registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)], PE2_next_poten);
                potential_mem_PE2[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] = PE2_next_poten[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]];
            }

            if (instr_mem[(*idx_instr)](2, 2))
            {
                PE3_done = PE3(PE3_cur_poten, PE3_weight, registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)], PE3_next_poten);
                potential_mem_PE3[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] = PE3_next_poten[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]];
            }

            if (instr_mem[(*idx_instr)](3, 3))
            {
                PE4_done = PE4(PE4_cur_poten, PE4_weight, registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)], PE4_next_poten);
                potential_mem_PE4[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] = PE4_next_poten[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]];
            }

            (*idx_instr)++;
            break;

        case 13:
            //ckf
            //(31,28)  (27,23)  (19,4)  (3,0)
            //opcode   RA		CL_MASK	PE_MASK
            if (instr_mem[(*idx_instr)](0, 0) && (PE1_next_poten[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] >= FIRING_THRESHOLD))
            {
                reg_spike_PE1(NID_MSB, NID_LSB) = registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] + registerfile[NUM_NEURONS_PERPE] * 0;
                reg_spike_PE1(TSTEP_MSB, TSTEP_LSB) = registerfile[REG_FILE_TIMESTEP];
                /*******************************************/
                //spike_mem[num_spike_queue] = reg_spike_PE1;
                /*******************************************/
                reg_cluster_mask_PE1=instr_mem[(*idx_instr)](CLUSTERMASK_MSB, CLUSTERMASK_LSB);
                while (!done_spk_wrt_PE1)
                {
                    done_spk_wrt_PE1 = SpikeController(spike_mem_list, reg_cluster_mask_PE1, reg_spike_PE1);
                }
                done_spk_wrt_PE1=0;
                potential_mem_PE1[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] = 0; //write back to the potential memory
                //num_spike_queue++;
            }

            if (instr_mem[(*idx_instr)](1, 1) && (PE2_next_poten[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] >= FIRING_THRESHOLD))
            {
                reg_spike_PE2(NID_MSB, NID_LSB) = registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] + registerfile[NUM_NEURONS_PERPE] * 1;
                reg_spike_PE2(TSTEP_MSB, TSTEP_LSB) = registerfile[REG_FILE_TIMESTEP];
                /*******************************************/
                //spike_mem[num_spike_queue] = reg_spike_PE2;
                /*******************************************/
                reg_cluster_mask_PE2=instr_mem[(*idx_instr)](CLUSTERMASK_MSB, CLUSTERMASK_LSB);
                while (!done_spk_wrt_PE2)
                {
                    done_spk_wrt_PE2 = SpikeController(spike_mem_list, reg_cluster_mask_PE2, reg_spike_PE2);
                }
                done_spk_wrt_PE2=0;
                potential_mem_PE2[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] = 0; //write back to the potential memory
                //num_spike_queue++;
            }

            if (instr_mem[(*idx_instr)](2, 2) && (PE3_next_poten[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] >= FIRING_THRESHOLD))
            {
                reg_spike_PE3(NID_MSB, NID_LSB) = registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] + registerfile[NUM_NEURONS_PERPE] * 2;
                reg_spike_PE3(TSTEP_MSB, TSTEP_LSB) = registerfile[REG_FILE_TIMESTEP];
                /*******************************************/
                //spike_mem[num_spike_queue] = reg_spike_PE3;
                /*******************************************/
                reg_cluster_mask_PE3=instr_mem[(*idx_instr)](CLUSTERMASK_MSB, CLUSTERMASK_LSB);
                while (!done_spk_wrt_PE3)
                {
                    done_spk_wrt_PE3 = SpikeController(spike_mem_list, reg_cluster_mask_PE3, reg_spike_PE3);
                }
                done_spk_wrt_PE3=0;
                potential_mem_PE3[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] = 0; //write back to the potential memory
                //num_spike_queue++;
            }

            if (instr_mem[(*idx_instr)](3, 3) && (PE4_next_poten[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] >= FIRING_THRESHOLD))
            {
                reg_spike_PE4(NID_MSB, NID_LSB) = registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)] + registerfile[NUM_NEURONS_PERPE] * 3;
                reg_spike_PE4(TSTEP_MSB, TSTEP_LSB) = registerfile[REG_FILE_TIMESTEP];
                /*******************************************/
                //spike_mem[num_spike_queue] = reg_spike_PE4;
                /*******************************************/
                reg_cluster_mask_PE4=instr_mem[(*idx_instr)](CLUSTERMASK_MSB, CLUSTERMASK_LSB);
                while (!done_spk_wrt_PE4)
                {
                    done_spk_wrt_PE4 = SpikeController(spike_mem_list, reg_cluster_mask_PE4, reg_spike_PE4);
                }
                done_spk_wrt_PE4=0;
                potential_mem_PE4[registerfile[instr_mem[(*idx_instr)](REG_A_MSB, REG_A_LSB)]] = 0; //write back to the potential memory
                //num_spike_queue++;
            }

            (*idx_instr)++;
            break;

        default:
            ret = 0;
            break;

        } //end of switch
    }     //end of while


    /******************************/
    int i_idx;
    for (i_idx=0; i_idx<N_NEURONS_PER_PE; i_idx++)
    {
        PE1_next_poten[i_idx] = 0;
        PE2_next_poten[i_idx] = 0;
        PE3_next_poten[i_idx] = 0;
        PE4_next_poten[i_idx] = 0;
    }

    /******************************/
    if (registerfile[DONE_EXECUTION] == 1)
    {
        *cluster_done = 1;
        //*cluster_exit = 1;
    }


    return in_mem_idx;

} //end of main function
