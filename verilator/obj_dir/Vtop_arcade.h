// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_ARCADE_H_
#define VERILATED_VTOP_ARCADE_H_  // guard

#include "verilated.h"

class Vtop_arcade__Syms;
class Vtop_arcade___024root;

// This class is the main interface to the Verilated model
class Vtop_arcade VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtop_arcade__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk_25,0,0);
    VL_OUT8(&VGA_B,3,0);
    VL_OUT8(&VGA_G,3,0);
    VL_OUT8(&VGA_HS,0,0);
    VL_OUT8(&VGA_R,3,0);
    VL_OUT8(&VGA_VS,0,0);
    VL_OUT8(&disp_ena,0,0);
    VL_IN8(&clk_50,0,0);
    VL_IN8(&clk_100,0,0);
    VL_IN8(&A,0,0);
    VL_IN8(&B,0,0);
    VL_IN8(&Select,0,0);
    VL_IN8(&Start,0,0);
    VL_IN8(&Right,0,0);
    VL_IN8(&Left,0,0);
    VL_IN8(&Up,0,0);
    VL_IN8(&Down,0,0);
    VL_IN16(&SW,9,0);
    VL_IN16(&Wheel,11,0);
    VL_IN16(&WheelY,11,0);
    VL_OUT(&pxl_x,31,0);
    VL_OUT(&pxl_y,31,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtop_arcade___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtop_arcade(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop_arcade(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtop_arcade();
  private:
    VL_UNCOPYABLE(Vtop_arcade);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
