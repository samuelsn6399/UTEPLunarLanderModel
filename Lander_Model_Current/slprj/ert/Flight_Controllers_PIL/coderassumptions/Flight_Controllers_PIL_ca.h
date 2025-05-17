/*
 * File: Flight_Controllers_PIL_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef FLIGHT_CONTROLLERS_PIL_CA_H
#define FLIGHT_CONTROLLERS_PIL_CA_H

/* preprocessor validation checks */
#include "Flight_Controllers_PIL_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_Flight_Controllers_PIL_HWRes;
extern CA_PWS_TestResults CA_Flight_Controllers_PIL_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_Flight_Controllers_PIL_ExpHW;
extern CA_HWImpl CA_Flight_Controllers_PIL_ActHW;

/* entry point function to run tests */
void Flight_Controllers_PIL_caRunTests(void);

#endif                                 /* FLIGHT_CONTROLLERS_PIL_CA_H */
