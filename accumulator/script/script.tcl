############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project acc2
set_top accumulator
add_files acc2/accumulator.cpp
add_files acc2/accumulator.h
add_files -tb acc2/accumulatortest.cpp
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 5 -name default
source "./acc2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all
export_design -format ip_catalog
