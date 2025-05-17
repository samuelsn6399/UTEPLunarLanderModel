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

static XILIOData xil_fcnid0_task1_output_u[12];
static XILIOData xil_fcnid0_task1_y[15];
static XILIOData xil_fcnid0_init_y[15];
static XILIOData xil_fcnid0_ws_params[20];

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

  {
  }

  /* initialize output storage owned by In-the-Loop */
  /* Single In-the-Loop Component */
  if (xilFcnId == 0) {
    Flight_Controllers_PIL_initialize();
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
    /* No Function to Call */
    /* No Function to Call */
  } else {
    errorCode = XIL_INTERFACE_UNKNOWN_FCNID;
  }

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
   case XIL_PROCESS_PARAMS_COMMAND:
    {
      static int initComplete = 0;
      if (!initComplete) {
        uint32_T tableIdx = 0;

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_P.Cant_cosine_Loss);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Kd_LatPos);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Kd_LatVel);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Kd_Pitch);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Ki_LatPos);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Ki_LatVel);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Ki_Pitch);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Kp_LatPos);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Kp_LatVel);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.Kp_Pitch);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.N_LatPos);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.N_LatVel);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.N_Pitch);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.bOmega);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.g);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.g_Offset);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.mOmega);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.nFans);
          xil_fcnid0_ws_params[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_ws_params[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_P.tau_vCmd);
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
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.t);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.switchLines[0]);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 16 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.m);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.LandNowFl);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof
            (boolean_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.States_x);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.States_VxE);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.States_Theta);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.States_z);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_U.States_VzB);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_U.Sched_Vertical[0]);
          xil_fcnid0_task1_output_u[tableIdx].memUnitLength = 30 * sizeof(real_T);
          xil_fcnid0_task1_output_u[tableIdx++].address = (MemUnit_T *)
            dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_U.Sched_Lateral[0]);
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

XIL_INTERFACE_ERROR_CODE xilOutput(uint32_T xilFcnId, uint32_T xilTID)
{
  /* Single In-the-Loop Component */
  if (xilFcnId != 0) {
    return XIL_INTERFACE_UNKNOWN_FCNID;
  }

  switch (xilTID) {
   case 1:
    Flight_Controllers_PIL_step();
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
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.fireCmd);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.VertMode);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.Cntrl_telem[0]);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 10 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.Controls_xCmd);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_fire_Cmd);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.Controls_yCmd);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_OmegaCmds_M1);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_OmegaCmds_M2);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_OmegaCmds_M3);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_OmegaCmds_M4);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.MotorCmds.M1);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.MotorCmds.M2);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.MotorCmds.M3);
          xil_fcnid0_init_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_init_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.MotorCmds.M4);
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
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.fireCmd);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.VertMode);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.Cntrl_telem[0]);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 10 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.Controls_xCmd);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_fire_Cmd);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.Controls_yCmd);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_OmegaCmds_M1);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_OmegaCmds_M2);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_OmegaCmds_M3);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *)
            &(Flight_Controllers_PIL_Y.Controls_OmegaCmds_M4);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.MotorCmds.M1);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.MotorCmds.M2);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.MotorCmds.M3);
          xil_fcnid0_task1_y[tableIdx].memUnitLength = 1 * sizeof(real_T);
          xil_fcnid0_task1_y[tableIdx++].address = (MemUnit_T *) dataAddress;
        }

        {
          void * dataAddress = (void *) &(Flight_Controllers_PIL_Y.MotorCmds.M4);
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
  Flight_Controllers_PIL_terminate();

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
