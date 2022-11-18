// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_arcade.h"
#include "Vtop_arcade__Syms.h"

//============================================================
// Constructors

Vtop_arcade::Vtop_arcade(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop_arcade__Syms(contextp(), _vcname__, this)}
    , clk_25{vlSymsp->TOP.clk_25}
    , VGA_B{vlSymsp->TOP.VGA_B}
    , VGA_G{vlSymsp->TOP.VGA_G}
    , VGA_HS{vlSymsp->TOP.VGA_HS}
    , VGA_R{vlSymsp->TOP.VGA_R}
    , VGA_VS{vlSymsp->TOP.VGA_VS}
    , disp_ena{vlSymsp->TOP.disp_ena}
    , clk_50{vlSymsp->TOP.clk_50}
    , clk_100{vlSymsp->TOP.clk_100}
    , A{vlSymsp->TOP.A}
    , B{vlSymsp->TOP.B}
    , Select{vlSymsp->TOP.Select}
    , Start{vlSymsp->TOP.Start}
    , Right{vlSymsp->TOP.Right}
    , Left{vlSymsp->TOP.Left}
    , Up{vlSymsp->TOP.Up}
    , Down{vlSymsp->TOP.Down}
    , SW{vlSymsp->TOP.SW}
    , Wheel{vlSymsp->TOP.Wheel}
    , WheelY{vlSymsp->TOP.WheelY}
    , pxl_x{vlSymsp->TOP.pxl_x}
    , pxl_y{vlSymsp->TOP.pxl_y}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop_arcade::Vtop_arcade(const char* _vcname__)
    : Vtop_arcade(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop_arcade::~Vtop_arcade() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop_arcade___024root___eval_debug_assertions(Vtop_arcade___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_arcade___024root___eval_static(Vtop_arcade___024root* vlSelf);
void Vtop_arcade___024root___eval_initial(Vtop_arcade___024root* vlSelf);
void Vtop_arcade___024root___eval_settle(Vtop_arcade___024root* vlSelf);
void Vtop_arcade___024root___eval(Vtop_arcade___024root* vlSelf);

void Vtop_arcade::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_arcade::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_arcade___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop_arcade___024root___eval_static(&(vlSymsp->TOP));
        Vtop_arcade___024root___eval_initial(&(vlSymsp->TOP));
        Vtop_arcade___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop_arcade___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
}

//============================================================
// Events and timing
bool Vtop_arcade::eventsPending() { return false; }

uint64_t Vtop_arcade::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop_arcade::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop_arcade___024root___eval_final(Vtop_arcade___024root* vlSelf);

VL_ATTR_COLD void Vtop_arcade::final() {
    Vtop_arcade___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop_arcade::hierName() const { return vlSymsp->name(); }
const char* Vtop_arcade::modelName() const { return "Vtop_arcade"; }
unsigned Vtop_arcade::threads() const { return 1; }
