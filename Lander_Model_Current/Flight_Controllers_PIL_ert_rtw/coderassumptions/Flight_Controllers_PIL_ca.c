/*
 * File: Flight_Controllers_PIL_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "Flight_Controllers_PIL_ca.h"

CA_HWImpl_TestResults CA_Flight_Controllers_PIL_HWRes;
CA_PWS_TestResults CA_Flight_Controllers_PIL_PWSRes;
const CA_HWImpl CA_Flight_Controllers_PIL_ExpHW = {

#ifdef PORTABLE_WORDSIZES

  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  64,                                  /* BitPerPointer */
  64,                                  /* BitPerSizeT */
  64,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */

#else

  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */

#endif

  1,                                   /* LongLongMode */
  1,                                   /* PortableWordSizes */
  "ARM Compatible->ARM Cortex",        /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DynamicMemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_Flight_Controllers_PIL_ActHW = {
  0,                                   /* BitPerChar */
  0,                                   /* BitPerShort */
  0,                                   /* BitPerInt */
  0,                                   /* BitPerLong */
  0,                                   /* BitPerLongLong */
  0,                                   /* BitPerFloat */
  0,                                   /* BitPerDouble */
  0,                                   /* BitPerPointer */
  0,                                   /* BitPerSizeT */
  0,                                   /* BitPerPtrDiffT */
  CA_UNSPECIFIED,                      /* Endianess */
  CA_UNDEFINED,                        /* IntDivRoundTo */
  0,                                   /* ShiftRightIntArith */
  0,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "",                                  /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DynamicMemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

void Flight_Controllers_PIL_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_Flight_Controllers_PIL_ActHW,
    &CA_Flight_Controllers_PIL_ExpHW, &CA_Flight_Controllers_PIL_PWSRes);
  caVerifyHWImpl(&CA_Flight_Controllers_PIL_ActHW,
                 &CA_Flight_Controllers_PIL_ExpHW,
                 &CA_Flight_Controllers_PIL_HWRes);
}
