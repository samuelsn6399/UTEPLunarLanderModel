/*
 * File: xil_interface.cpp
 *
 * SIL generated interface for code: "Flight_Controllers_PIL"
 *
 */

#include "Flight_Controllers_PIL.h"
#include "Flight_Controllers_PIL_private.h"
#include "xil_interface.h"

/* Functions with a C call interface */
#ifdef __cplusplus

extern "C"
{

#endif

#include "xil_data_stream.h"
#ifdef __cplusplus

}

#endif

#include <string.h>

/* interface data */
real_T i_t;

/* interface data */
real_T i_switchLines[16];

/* interface data */
real_T i_m;

/* interface data */
boolean_T LandNowFl;

/* interface data */
real_T i_States_x;

/* interface data */
real_T i_States_VxE;

/* interface data */
real_T i_States_Theta;

/* interface data */
real_T i_States_z;

/* interface data */
real_T i_States_VzB;

/* interface data */
real_T i_Sched_Vertical[30];

/* interface data */
real_T i_Sched_Lateral[40];

/* interface data */
real_T o_fireCmd;

/* interface data */
real_T o_VertMode;

/* interface data */
real_T o_Cntrl_telem[10];

/* interface data */
real_T o_Controls_xCmd;

/* interface data */
real_T o_Controls_fire_Cmd;

/* interface data */
real_T o_Controls_yCmd;

/* interface data */
real_T o_Controls_OmegaCmds_M1;

/* interface data */
real_T o_Controls_OmegaCmds_M2;

/* interface data */
real_T o_Controls_OmegaCmds_M3;

/* interface data */
real_T o_Controls_OmegaCmds_M4;

/* interface data */
real_T o_MotorCmds_M1;

/* interface data */
real_T o_MotorCmds_M2;

/* interface data */
real_T o_MotorCmds_M3;

/* interface data */
real_T o_MotorCmds_M4;

/* interface data */
real_T rtP_Cant_cosine_Loss;

/* interface data */
real_T rtP_Kd_LatPos;

/* interface data */
real_T rtP_Kd_LatVel;

/* interface data */
real_T rtP_Kd_Pitch;

/* interface data */
real_T rtP_Ki_LatPos;

/* interface data */
real_T rtP_Ki_LatVel;

/* interface data */
real_T rtP_Ki_Pitch;

/* interface data */
real_T rtP_Kp_LatPos;

/* interface data */
real_T rtP_Kp_LatVel;

/* interface data */
real_T rtP_Kp_Pitch;

/* interface data */
real_T rtP_N_LatPos;

/* interface data */
real_T rtP_N_LatVel;

/* interface data */
real_T rtP_N_Pitch;

/* interface data */
real_T rtP_bOmega;

/* interface data */
real_T rtP_g;

/* interface data */
real_T rtP_g_Offset;

/* interface data */
real_T rtP_mOmega;

/* interface data */
real_T rtP_nFans;

/* interface data */
real_T rtP_tau_vCmd;

#define mdlref_TID0                    0

/* initialize error status as a null pointer */
static const char_T * rt_errorStatus_tgt_var = ((const char_T *) 0);
static const char_T ** rt_errorStatus = &rt_errorStatus_tgt_var;

/* define timingBridge */
static rtTimingBridge timingBridge_tgt_var;
static const rtTimingBridge * timingBridge = &timingBridge_tgt_var;

/* define Timing structure */
static struct {
  uint32_T clockTick0;
  struct {
    uint32_T TID[1];
  } TaskCounters;
} XILTimingData;

static uint32_T InitialTaskCounterOffset[1];

/* XILFirstInitCond will be updated by xilInitialize and xilSystemInitialize */
static boolean_T XILFirstInitCond = 0;

/* interface data */
MdlrefDW_Flight_Controllers_P_T Flight_Controllers_PIL_MdlrefDW;

/* interface (pointer) data */
RT_MODEL_Flight_Controllers_P_T * RTModel_ptr =
  &(Flight_Controllers_PIL_MdlrefDW.rtm);
static XILIOData xil_fcnid0_task1_output_u[12];
static XILIOData xil_fcnid0_task1_y[15];
static XILIOData xil_fcnid0_init_u[2];
static XILIOData xil_fcnid0_init_y[15];
static XILIOData xil_fcnid0_ws_params[20];
static XILIOData xil_fcnid0_system_initialize_y[15];

/* In-the-Loop Interface functions - see xil_interface.h */
XIL_INTERFACE_ERROR_CODE xilProcessParams(uint32_T xilFcnId)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilGetDataTypeInfo(void)
{
  {
    /* send response id code */
    MemUnit_T memUnitData = XIL_RESPONSE_TYPE_SIZE;
    if (xilWriteData(&memUnitData, sizeof(memUnitData)) !=
        XIL_DATA_STREAM_SUCCESS) {
      return XIL_INTERFACE_COMMS_FAILURE;
    }

    /* send type id */
    memUnitData = 0;
    if (xilWriteData(&memUnitData, sizeof(memUnitData)) !=
        XIL_DATA_STREAM_SUCCESS) {
      return XIL_INTERFACE_COMMS_FAILURE;
    }

    /* PIL_DOUBLE_SIZE should only be already defined for MathWorks testing */
#ifndef PIL_DOUBLE_SIZE
#define PIL_DOUBLE_SIZE                sizeof(double)
#endif

    /* send size in bytes */
    memUnitData = (MemUnit_T) PIL_DOUBLE_SIZE;

#ifndef HOST_WORD_ADDRESSABLE_TESTING

    /* convert MemUnits to bytes */
    memUnitData *= MEM_UNIT_BYTES;

#endif

    if (xilWriteData(&memUnitData, sizeof(memUnitData)) !=
        XIL_DATA_STREAM_SUCCESS) {
      return XIL_INTERFACE_COMMS_FAILURE;
    }
  }

  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilInitialize(uint32_T xilFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;

  /* initialize XILTimingData */
  (void) memset((void *) &XILTimingData, 0, sizeof(XILTimingData));

  {
    static uint32_T *clockTickPtrs[1];
    memcpy(XILTimingData.TaskCounters.TID, InitialTaskCounterOffset, sizeof
           (InitialTaskCounterOffset));
    static uint32_T *taskCounterPtrs;
    taskCounterPtrs = &(XILTimingData.TaskCounters.TID[0]);
    timingBridge_tgt_var.taskCounter = taskCounterPtrs;
    clockTickPtrs[0] = &(XILTimingData.clockTick0);
    timingBridge_tgt_var.clockTick = clockTickPtrs;
    timingBridge_tgt_var.clockTickH = (uint32_T **) 0;
    timingBridge_tgt_var.nTasks = 1;
  }

  timingBridge_tgt_var.firstInitCond = &XILFirstInitCond;

  /* firstInitCond should be true until after the first InitCond call */
  XILFirstInitCond = 1;

  {
  }

  /* initialize output storage owned by In-the-Loop */
  {
    o_fireCmd = 0;
  }

  {
    o_VertMode = 0;
  }

  {
    {
      uint32_T elementIdx_0;
      for (elementIdx_0 = 0; elementIdx_0 < 10; elementIdx_0++) {
        o_Cntrl_telem[elementIdx_0] = 0;
      }                                /* for */
    }
  }

  {
    o_Controls_xCmd = 0;
  }

  {
    o_Controls_fire_Cmd = 0;
  }

  {
    o_Controls_yCmd = 0;
  }

  {
    o_Controls_OmegaCmds_M1 = 0;
  }

  {
    o_Controls_OmegaCmds_M2 = 0;
  }

  {
    o_Controls_OmegaCmds_M3 = 0;
  }

  {
    o_Controls_OmegaCmds_M4 = 0;
  }

  {
    o_MotorCmds_M1 = 0;
  }

  {
    o_MotorCmds_M2 = 0;
  }

  {
    o_MotorCmds_M3 = 0;
  }

  {
    o_MotorCmds_M4 = 0;
  }

  /* Single In-the-Loop Component */
  if (xilFcnId == 0) {
    /* Call all Set class methods */
    Flight_Controllers_P_initialize(rt_errorStatus, timingBridge, mdlref_TID0,
      RTModel_ptr);

    /* Call all Get class methods */
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilPause(uint32_T xilFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;
  if (xilFcnId == 0) {
    /* Nothing to do */
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }                                    /* if */

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilSystemInitialize(uint32_T xilFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;

  /* Single In-the-Loop Component */
  if (xilFcnId == 0) {
    Flight_Controllers_PIL_Init(&(Flight_Controllers_PIL_MdlrefDW.rtdw));
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }

  /* firstInitCond should be false after the first InitCond call */
  XILFirstInitCond = 0;
  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilSystemReset(uint32_T xilFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;

  /* Single In-the-Loop Component */
  if (xilFcnId == 0) {
    /* No Function to Call */
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }

  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilGetHostToTargetData(uint32_T xilFcnId,
  XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData
  ** xilIOData)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;
  *xilIOData = 0;

  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
    return errorCode;
  }

  switch (xilCommandType) {
   case XIL_INITIALIZE_COMMAND:
    {
      static int initComplete = 0;
      if (!initComplete) {
        uint32_T tableIdx = 0;

        {
          void * dataAddress = (void *) &(InitialTaskCounterOffset[0]);
          xil_fcnid0_init_u[tableIdx].memUnitLength = 1 * sizeof(uint32_T);
          xil_fcnid0_init_u[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        xil_fcnid0_init_u[tableIdx].memUnitLength = 0;
        xil_fcnid0_init_u[tableIdx++].address = (MemUnit_T *) 0;
        initComplete = 1;
      }                                /* if */

      *xilIOData = &xil_fcnid0_init_u[0];
      break;
    }

   case XIL_PROCESS_PARAMS_COMMAND:
    {
      static int initComplete = 0;
      if (!initComplete) {
        uint32_T tableIdx = 0;

        {
          void * dataAddress = (void *) &(rtP_Cant_cosine_Loss);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Kd_LatPos);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Kd_LatVel);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Kd_Pitch);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Ki_LatPos);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Ki_LatVel);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Ki_Pitch);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Kp_LatPos);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Kp_LatVel);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_Kp_Pitch);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_N_LatPos);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_N_LatVel);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_N_Pitch);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_bOmega);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_g);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_g_Offset);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_mOmega);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_nFans);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(rtP_tau_vCmd);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        xil_fcnid0_ws_params[tableIdx].memUnitLength = 0;
        xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) 0;
        initComplete = 1;
      }                                /* if */

      *xilIOData = &xil_fcnid0_ws_params[0];
      break;
    }

   case XIL_OUTPUT_COMMAND:
    {
      static int initComplete = 0;
      if (!initComplete) {
        uint32_T tableIdx = 0;

        {
          void * dataAddress = (void *) &(i_t);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_switchLines[0]);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 16 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_m);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(LandNowFl);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof
            (boolean_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_States_x);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_States_VxE);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_States_Theta);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_States_z);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_States_VzB);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_Sched_Vertical[0]);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 30 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(i_Sched_Lateral[0]);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 40 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 0;
        xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *) 0;
        initComplete = 1;
      }                                /* if */

      *xilIOData = &xil_fcnid0_task1_output_u[0];
      break;
    }

   default:
    errorCode = XIL_INTERFACE_UNKNOWN_TID;
    break;
  }

  UNUSED_PARAMETER(xilCommandIdx);
  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilGetTargetToHostPreData(uint32_T xilFcnId,
  XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData
  ** xilIOData, MemUnit_T responseId, uint32_T serverFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;
  *xilIOData = 0;
  if (xilFcnId != 0) {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
    return errorCode;
  }                                    /* if */

  errorCode = XIL_INTERFACE_UNKNOWN_TID;
  UNUSED_PARAMETER(xilCommandType);
  UNUSED_PARAMETER(xilCommandIdx);
  UNUSED_PARAMETER(responseId);
  UNUSED_PARAMETER(serverFcnId);
  return errorCode;
}

static void rate_scheduler(void)
{
}

XIL_INTERFACE_ERROR_CODE xilOutput(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  switch (xilTID) {
   case 1:
    /* Call all Set class methods */
    Flight_Controllers_PIL(RTModel_ptr, &(i_t), i_switchLines, &(i_m),
      &(i_States_x), &(i_States_VxE), &(i_States_Theta), &(i_States_z),
      &(i_States_VzB), i_Sched_Vertical, i_Sched_Lateral, &(o_fireCmd),
      &(o_VertMode), o_Cntrl_telem, &(o_Controls_xCmd), &(o_Controls_fire_Cmd),
      &(o_Controls_yCmd), &(o_Controls_OmegaCmds_M1), &(o_Controls_OmegaCmds_M2),
      &(o_Controls_OmegaCmds_M3), &(o_Controls_OmegaCmds_M4), &(o_MotorCmds_M1),
      &(o_MotorCmds_M2), &(o_MotorCmds_M3), &(o_MotorCmds_M4),
      &(Flight_Controllers_PIL_MdlrefDW.rtb),
      &(Flight_Controllers_PIL_MdlrefDW.rtdw));

    /* Update absolute time */
    XILTimingData.clockTick0++;

    /* call scheduler */
    rate_scheduler();

    /* Call all Get class methods */
    break;

   default:
    return XIL_INTERFACE_UNKNOWN_TID;
  }

  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilUpdate(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  /* No Update Function */
  UNUSED_PARAMETER(xilTID);
  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilGetTargetToHostData(uint32_T xilFcnId,
  XIL_COMMAND_TYPE_ENUM xilCommandType, uint32_T xilCommandIdx, XILIOData
  ** xilIOData, MemUnit_T responseId, uint32_T serverFcnId)
{
  XIL_INTERFACE_ERROR_CODE errorCode = XIL_INTERFACE_SUCCESS;

  /* Single In-the-Loop Component */
  *xilIOData = 0;
  if (xilFcnId != 0) {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
    return errorCode;
  }

  switch (xilCommandType) {
   case XIL_INITIALIZE_COMMAND:
    {
      static int initComplete = 0;
      if (!initComplete) {
        uint32_T tableIdx = 0;

        {
          void * dataAddress = (void *) &(o_fireCmd);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_VertMode);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Cntrl_telem[0]);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 10 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_xCmd);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_fire_Cmd);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_yCmd);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M1);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M2);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M3);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M4);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M1);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M2);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M3);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M4);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        xil_fcnid0_init_y[tableIdx].memUnitLength = 0;
        xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) 0;
        initComplete = 1;
      }                                /* if */

      {
        if (xilWriteData(&responseId, sizeof(responseId)) !=
            XIL_DATA_STREAM_SUCCESS) {
          return XIL_INTERFACE_COMMS_FAILURE;
        }                              /* if */

        if (responseId == XIL_RESPONSE_CS_REQUEST_SERVICE) {
          if (xilWriteData((MemUnit_T *) &serverFcnId, sizeof(serverFcnId)) !=
              XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
          }                            /* if */
        }                              /* if */
      }

      *xilIOData = &xil_fcnid0_init_y[0];
      break;
    }

   case XIL_OUTPUT_COMMAND:
    {
      static int initComplete = 0;
      if (!initComplete) {
        uint32_T tableIdx = 0;

        {
          void * dataAddress = (void *) &(o_fireCmd);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_VertMode);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Cntrl_telem[0]);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 10 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_xCmd);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_fire_Cmd);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_yCmd);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M1);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M2);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M3);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M4);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M1);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M2);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M3);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M4);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        xil_fcnid0_task1_y[tableIdx].memUnitLength = 0;
        xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) 0;
        initComplete = 1;
      }                                /* if */

      {
        if (xilWriteData(&responseId, sizeof(responseId)) !=
            XIL_DATA_STREAM_SUCCESS) {
          return XIL_INTERFACE_COMMS_FAILURE;
        }                              /* if */

        if (responseId == XIL_RESPONSE_CS_REQUEST_SERVICE) {
          if (xilWriteData((MemUnit_T *) &serverFcnId, sizeof(serverFcnId)) !=
              XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
          }                            /* if */
        }                              /* if */
      }

      *xilIOData = &xil_fcnid0_task1_y[0];
      break;
    }

   case XIL_SYSTEM_INITIALIZE_COMMAND:
    {
      static int initComplete = 0;
      if (!initComplete) {
        uint32_T tableIdx = 0;

        {
          void * dataAddress = (void *) &(o_fireCmd);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_VertMode);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Cntrl_telem[0]);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 10 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_xCmd);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_fire_Cmd);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_yCmd);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M1);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M2);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M3);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_Controls_OmegaCmds_M4);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M1);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M2);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M3);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(o_MotorCmds_M4);
          xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 1 * sizeof
            (real_T);
          xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        xil_fcnid0_system_initialize_y[tableIdx].memUnitLength = 0;
        xil_fcnid0_system_initialize_y[tableIdx++].address = (MemUnit_T *) 0;
        initComplete = 1;
      }                                /* if */

      {
        if (xilWriteData(&responseId, sizeof(responseId)) !=
            XIL_DATA_STREAM_SUCCESS) {
          return XIL_INTERFACE_COMMS_FAILURE;
        }                              /* if */

        if (responseId == XIL_RESPONSE_CS_REQUEST_SERVICE) {
          if (xilWriteData((MemUnit_T *) &serverFcnId, sizeof(serverFcnId)) !=
              XIL_DATA_STREAM_SUCCESS) {
            return XIL_INTERFACE_COMMS_FAILURE;
          }                            /* if */
        }                              /* if */
      }

      *xilIOData = &xil_fcnid0_system_initialize_y[0];
      break;
    }

   default:
    errorCode = XIL_INTERFACE_UNKNOWN_TID;
    break;
  }

  UNUSED_PARAMETER(xilCommandIdx);
  UNUSED_PARAMETER(responseId);
  UNUSED_PARAMETER(serverFcnId);
  return errorCode;
}

XIL_INTERFACE_ERROR_CODE xilTerminate(uint32_T xilFcnId)
{
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }                                    /* if */

  /* Invoke any terminate Function */
  /* No Function to Call */

  /* Free Opaque Region Based Data */
  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilInitTargetData(void)
{
  return XIL_INTERFACE_SUCCESS;
}

XIL_INTERFACE_ERROR_CODE xilEnable(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  UNUSED_PARAMETER(xilTID);

  /* No Enable Function - this function should never be called */
  return XIL_INTERFACE_UNKNOWN_TID;
}

XIL_INTERFACE_ERROR_CODE xilDisable(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  UNUSED_PARAMETER(xilTID);

  /* No Disable Function - this function should never be called */
  return XIL_INTERFACE_UNKNOWN_TID;
}
