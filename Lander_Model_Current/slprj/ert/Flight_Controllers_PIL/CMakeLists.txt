## This cmakelist.txt file was generated from
## the UAVToolbox Support Package for PX4 Autopilots

set(MAVLINK_LIBRARY_DIR "${CMAKE_BINARY_DIR}/mavlink")
set(MAVLINK_DIALECT_UAVIONIX "uAvionix")

add_definitions(
-DMODEL=Flight_Controllers_PIL -DNUMST=1 -DNCSTATES=0 -DHAVESTDIO -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0 -DCLASSIC_INTERFACE=0 -DALLOCATIONFCN=0 -DTID01EQ=0 -DTERMFCN=1 -DONESTEPFCN=1 -DMAT_FILE=0 -DMULTI_INSTANCE_CODE=0 -DINTEGER_CODE=0 -DMT=0 -DPX4 -DFMUv6x -DNULL=0 -DMW_PX4_NUTTX_BUILD -DEXTMODE_DISABLETESTING -DEXTMODE_DISABLEPRINTF -DEXTMODE_DISABLE_ARGS_PROCESSING=1 -D__linux__ -DXCP_PLATFORM_LINUX_NO_PIE_SUPPORT -DSTACK_SIZE=64 -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__ -DRT -DMW_PX4_DISABLE_MAVLINK=1 )

px4_add_module(
    MODULE modules__px4_simulink_app
    MAIN px4_simulink_app
    STACK_MAIN 2000
SRCS
   Flight_Controllers_PIL.cpp
   rtGetInf.h
   rtGetNaN.h
   rt_nonfinite.h
   Flight_Controllers_PIL.h
   Flight_Controllers_PIL_private.h
   Flight_Controllers_PIL_types.h
   rtw_continuous.h
   rtw_solver.h
   model_reference_types.h
   rtwtypes.h
   rtGetInf.cpp
   rtGetNaN.cpp
   rt_nonfinite.cpp
    COMPILE_FLAGS
       -fpermissive
       -Wno-narrowing
       -Wno-address-of-packed-member 
       -Wno-cast-align
    INCLUDES
       ${PX4_SOURCE_DIR}/src/modules/px4_simulink_app
       ${PX4_SOURCE_DIR}/src/modules/mavlink
       ${MAVLINK_LIBRARY_DIR}
       ${MAVLINK_LIBRARY_DIR}/${CONFIG_MAVLINK_DIALECT}
       ${MAVLINK_LIBRARY_DIR}/${MAVLINK_DIALECT_UAVIONIX}
)

get_target_property(PX4_SL_APP_COMPILE_FLAGS modules__px4_simulink_app COMPILE_OPTIONS)
list(REMOVE_ITEM PX4_SL_APP_COMPILE_FLAGS -Werror)
set_target_properties(modules__px4_simulink_app PROPERTIES COMPILE_OPTIONS "${PX4_SL_APP_COMPILE_FLAGS}")

