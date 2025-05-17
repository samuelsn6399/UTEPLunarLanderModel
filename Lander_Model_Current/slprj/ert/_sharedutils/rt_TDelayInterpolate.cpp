//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_TDelayInterpolate.cpp
//
// Code generated for Simulink model 'ColdGas_GNC_Model_PIL'.
//
// Model version                  : 15.36
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Mon Aug 12 10:35:08 2024
//
#include <float.h>
#include <math.h>
#include "rtwtypes.h"
#include "rt_TDelayInterpolate.h"

//
//  Time delay interpolation routine
//
//  The linear interpolation is performed using the formula:
//
//  (t2 - tMinusDelay)         (tMinusDelay - t1)
//  u(t)  =  ----------------- * u1  +  ------------------- * u2
//  (t2 - t1)                  (t2 - t1)

real_T rt_TDelayInterpolate(
  real_T tMinusDelay,                  // tMinusDelay = currentSimTime - delay
  real_T tStart,
  real_T *uBuf,
  int_T bufSz,
  int_T *lastIdx,
  int_T oldestIdx,
  int_T newIdx,
  real_T initOutput,
  boolean_T discrete,
  boolean_T minorStepAndTAtLastMajorOutput)
{
  int_T i;
  real_T yout, t1, t2, u1, u2;
  real_T* tBuf = uBuf + bufSz;

  //
  //  If there is only one data point in the buffer, this data point must be
  //  the t= 0 and tMinusDelay > t0, it ask for something unknown. The best
  //  guess if initial output as well

  if ((newIdx == 0) && (oldestIdx ==0 ) && (tMinusDelay > tStart))
    return initOutput;

  //
  //  If tMinusDelay is less than zero, should output initial value

  if (tMinusDelay <= tStart)
    return initOutput;

  // For fixed buffer extrapolation:
  //  if tMinusDelay is small than the time at oldestIdx, if discrete, output
  //  tailptr value,  else use tailptr and tailptr+1 value to extrapolate
  //  It is also for fixed buffer. Note: The same condition can happen for transport delay block where
  //  use tStart and and t[tail] other than using t[tail] and t[tail+1].
  //  See below

  if ((tMinusDelay <= tBuf[oldestIdx] ) ) {
    if (discrete) {
      return(uBuf[oldestIdx]);
    } else {
      int_T tempIdx= oldestIdx + 1;
      if (oldestIdx == bufSz-1)
        tempIdx = 0;
      t1= tBuf[oldestIdx];
      t2= tBuf[tempIdx];
      u1= uBuf[oldestIdx];
      u2= uBuf[tempIdx];
      if (t2 == t1) {
        if (tMinusDelay >= t2) {
          yout = u2;
        } else {
          yout = u1;
        }
      } else {
        real_T f1 = (t2-tMinusDelay) / (t2-t1);
        real_T f2 = 1.0 - f1;

        //
        //  Use Lagrange's interpolation formula.  Exact outputs at t1, t2.

        yout = f1*u1 + f2*u2;
      }

      return yout;
    }
  }

  //
  //  When block does not have direct feedthrough, we use the table of
  //  values to extrapolate off the end of the table for delays that are less
  //  than 0 (less then step size).  This is not completely accurate.  The
  //  chain of events is as follows for a given time t.  Major output - look
  //  in table.  Update - add entry to table.  Now, if we call the output at
  //  time t again, there is a new entry in the table. For very small delays,
  //  this means that we will have a different answer from the previous call
  //  to the output fcn at the same time t.  The following code prevents this
  //  from happening.

  if (minorStepAndTAtLastMajorOutput) {
    // pretend that the new entry has not been added to table
    if (newIdx != 0) {
      if (*lastIdx == newIdx) {
        (*lastIdx)--;
      }

      newIdx--;
    } else {
      if (*lastIdx == newIdx) {
        *lastIdx = bufSz-1;
      }

      newIdx = bufSz - 1;
    }
  }

  i = *lastIdx;
  if (tBuf[i] < tMinusDelay) {
    // Look forward starting at last index
    while (tBuf[i] < tMinusDelay) {
      // May occur if the delay is less than step-size - extrapolate
      if (i == newIdx)
        break;
      i = ( i < (bufSz-1) ) ? (i+1) : 0;// move through buffer
    }
  } else {
    //
    //  Look backwards starting at last index which can happen when the
    //  delay time increases.

    while (tBuf[i] >= tMinusDelay) {
      //
      //  Due to the entry condition at top of function, we
      //  should never hit the end.

      i = (i > 0) ? i-1 : (bufSz-1);   // move through buffer
    }

    i = ( i < (bufSz-1) ) ? (i+1) : 0;
  }

  *lastIdx = i;
  if (discrete) {
    //
    //  tempEps = 128 * eps;
    //  localEps = max(tempEps, tempEps*fabs(tBuf[i]))/2;

    double tempEps = (DBL_EPSILON) * 128.0;
    double localEps = tempEps * fabs(tBuf[i]);
    if (tempEps > localEps) {
      localEps = tempEps;
    }

    localEps = localEps / 2.0;
    if (tMinusDelay >= (tBuf[i] - localEps)) {
      yout = uBuf[i];
    } else {
      if (i == 0) {
        yout = uBuf[bufSz-1];
      } else {
        yout = uBuf[i-1];
      }
    }
  } else {
    if (i == 0) {
      t1 = tBuf[bufSz-1];
      u1 = uBuf[bufSz-1];
    } else {
      t1 = tBuf[i-1];
      u1 = uBuf[i-1];
    }

    t2 = tBuf[i];
    u2 = uBuf[i];
    if (t2 == t1) {
      if (tMinusDelay >= t2) {
        yout = u2;
      } else {
        yout = u1;
      }
    } else {
      real_T f1 = (t2-tMinusDelay) / (t2-t1);
      real_T f2 = 1.0 - f1;

      //
      //  Use Lagrange's interpolation formula.  Exact outputs at t1, t2.

      yout = f1*u1 + f2*u2;
    }
  }

  return(yout);
}

//
// File trailer for generated code.
//
// [EOF]
//
