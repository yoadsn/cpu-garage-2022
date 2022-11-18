// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_arcade.h for the primary calling header

#include "verilated.h"

#include "Vtop_arcade__Syms.h"
#include "Vtop_arcade___024root.h"

void Vtop_arcade___024root___ctor_var_reset(Vtop_arcade___024root* vlSelf);

Vtop_arcade___024root::Vtop_arcade___024root(Vtop_arcade__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_arcade___024root___ctor_var_reset(this);
}

void Vtop_arcade___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_arcade___024root::~Vtop_arcade___024root() {
}
