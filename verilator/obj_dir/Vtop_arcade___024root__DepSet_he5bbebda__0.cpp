// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_arcade.h for the primary calling header

#include "verilated.h"

#include "Vtop_arcade__Syms.h"
#include "Vtop_arcade___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__ico(Vtop_arcade___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_arcade___024root___eval_triggers__ico(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_arcade___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__act(Vtop_arcade___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_arcade___024root___eval_triggers__act(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = ((IData)(vlSelf->clk_25) 
                                      & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk_25)));
    vlSelf->__VactTriggered.at(1U) = (((~ (IData)(vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN)) 
                                       & (IData)(vlSelf->__Vtrigrprev__TOP__Top_template__DOT____Vcellinp__fb_mgr__resetN)) 
                                      | ((IData)(vlSelf->clk_25) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk_25))));
    vlSelf->__Vtrigrprev__TOP__clk_25 = vlSelf->clk_25;
    vlSelf->__Vtrigrprev__TOP__Top_template__DOT____Vcellinp__fb_mgr__resetN 
        = vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_arcade___024root___dump_triggers__act(vlSelf);
    }
#endif
}
