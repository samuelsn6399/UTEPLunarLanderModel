/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "Flight_Controllers_PIL_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_Flight_Controllers_PIL_ExpHW
#define CA_Actual_HWImpl               CA_Flight_Controllers_PIL_ActHW
#define CA_HWImpl_Results              CA_Flight_Controllers_PIL_HWRes
#define CA_PortableWordSizes_Results   CA_Flight_Controllers_PIL_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   Flight_Controllers_PIL_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
