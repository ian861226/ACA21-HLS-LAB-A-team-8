############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project automatic_balancing
set_top adder_tree_balanced
add_files hls_automatic_balancing/Automatic_tree_balancing.h
add_files hls_automatic_balancing/Automatic_tree_balancing.cpp
add_files -tb hls_automatic_balancing/Automatic_tree_balancingTester.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020-clg484-1}
create_clock -period 5 -name default
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -format ip_catalog
