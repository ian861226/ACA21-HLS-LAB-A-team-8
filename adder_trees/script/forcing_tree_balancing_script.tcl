############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project forcing_balancing
set_top adder_tree_rebalanced
add_files hls_forcing_balancing/Forcing_tree_balancing.cpp
add_files hls_forcing_balancing/Forcing_tree_balancing.h
add_files -tb hls_forcing_balancing/Forcing_tree_balancingTester.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "ap_none_input"
set_part {xc7z020-clg484-1}
create_clock -period 5 -name default
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -format ip_catalog
