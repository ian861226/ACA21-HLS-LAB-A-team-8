############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab_A
set_top lut
add_files lab_A/src/data.inc
add_files lab_A/src/log2ceil.h
add_files lab_A/src/lut.cpp
add_files lab_A/src/lut.h
add_files -tb lab_A/src/lutTest.cpp
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 5 -name default
config_sdx -target none
config_export -vivado_optimization_level 2
#source "./lab_A/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -rtl verilog -format ip_catalog
