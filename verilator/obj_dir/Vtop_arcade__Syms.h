// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP_ARCADE__SYMS_H_
#define VERILATED_VTOP_ARCADE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop_arcade.h"

// INCLUDE MODULE CLASSES
#include "Vtop_arcade___024root.h"

// SYMS CLASS (contains all model state)
class Vtop_arcade__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop_arcade* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop_arcade___024root          TOP;

    // CONSTRUCTORS
    Vtop_arcade__Syms(VerilatedContext* contextp, const char* namep, Vtop_arcade* modelp);
    ~Vtop_arcade__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
