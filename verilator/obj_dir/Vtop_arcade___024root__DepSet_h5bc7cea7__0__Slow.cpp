// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_arcade.h for the primary calling header

#include "verilated.h"

#include "Vtop_arcade___024root.h"

VL_ATTR_COLD void Vtop_arcade___024root___eval_static__TOP(Vtop_arcade___024root* vlSelf);

VL_ATTR_COLD void Vtop_arcade___024root___eval_static(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_static\n"); );
    // Body
    Vtop_arcade___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtop_arcade___024root___eval_static__TOP(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->Top_template__DOT__fb_mgr__DOT__next_write_source_sel = 0U;
}

VL_ATTR_COLD void Vtop_arcade___024root___eval_initial(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk_25 = vlSelf->clk_25;
    vlSelf->__Vtrigrprev__TOP__Top_template__DOT____Vcellinp__fb_mgr__resetN 
        = vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN;
}

VL_ATTR_COLD void Vtop_arcade___024root___eval_final(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtop_arcade___024root___eval_triggers__stl(Vtop_arcade___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__stl(Vtop_arcade___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___eval_stl(Vtop_arcade___024root* vlSelf);

VL_ATTR_COLD void Vtop_arcade___024root___eval_settle(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vtop_arcade___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if ((0x64U < vlSelf->__VstlIterCount)) {
#ifdef VL_DEBUG
                Vtop_arcade___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("top_arcade.sv", 26, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vtop_arcade___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__stl(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_arcade___024root___stl_sequent__TOP__0(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___stl_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ Top_template__DOT____Vcellout__fb_mgr__read_color_data;
    SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_hbca619ae__0;
    SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_h9af5e858__0;
    // Body
    vlSelf->VGA_HS = vlSelf->Top_template__DOT__h_sync_wire;
    vlSelf->VGA_VS = vlSelf->Top_template__DOT__v_sync_wire;
    vlSelf->pxl_x = vlSelf->Top_template__DOT__Screen_control__DOT__Pxl_x_e;
    vlSelf->pxl_y = vlSelf->Top_template__DOT__Screen_control__DOT__Pxl_y_e;
    vlSelf->Top_template__DOT__fb_mgr__DOT__fb_read_addr 
        = (0x1ffffU & (((IData)(0x140U) * (0xffU & 
                                           (vlSelf->Top_template__DOT__Screen_control__DOT__Pxl_y_e 
                                            >> 1U))) 
                       + (0x1ffU & (vlSelf->Top_template__DOT__Screen_control__DOT__Pxl_x_e 
                                    >> 1U))));
    vlSelf->Top_template__DOT__bf_draw_data = ((((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                                  ? 0U
                                                  : 
                                                 ((((0x31U 
                                                     >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                     ? 
                                                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c
                                                    [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                     : 0U) 
                                                   << 6U) 
                                                  | ((((0x31U 
                                                        >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                        ? 
                                                       vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c
                                                       [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                        : 0U) 
                                                      << 3U) 
                                                     | ((0x31U 
                                                         >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                         ? 
                                                        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c
                                                        [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                         : 0U)))) 
                                                & ((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                                    ? 0U
                                                    : 0x1ffU)) 
                                               & ((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                                   ? 0U
                                                   : 0x1ffU));
    vlSelf->Top_template__DOT__bf_write_active = ((~ (IData)(vlSelf->Top_template__DOT__bf_write_source_sel)) 
                                                  & (6U 
                                                     == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state));
    Top_template__DOT____Vcellout__fb_mgr__read_color_data 
        = ((IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer)
            ? (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_1)
            : (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_0));
    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
        Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_hbca619ae__0 
            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y
            [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr];
        Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_h9af5e858__0 
            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x
            [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr];
    } else {
        Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_hbca619ae__0 = 0U;
        Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_h9af5e858__0 = 0U;
    }
    vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN 
        = (1U & (~ (IData)(vlSelf->A)));
    if (vlSelf->disp_ena) {
        vlSelf->VGA_B = (0xeU & ((IData)(Top_template__DOT____Vcellout__fb_mgr__read_color_data) 
                                 << 1U));
        vlSelf->VGA_G = (0xeU & ((IData)(Top_template__DOT____Vcellout__fb_mgr__read_color_data) 
                                 >> 2U));
        vlSelf->VGA_R = (0xeU & ((IData)(Top_template__DOT____Vcellout__fb_mgr__read_color_data) 
                                 >> 5U));
    } else {
        vlSelf->VGA_B = 0U;
        vlSelf->VGA_G = 0U;
        vlSelf->VGA_R = 0U;
    }
    vlSelf->Top_template__DOT__fb_mgr__DOT__fb_write_addr 
        = (0x1ffffU & (((IData)(0x140U) * (0xffU & 
                                           (((((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                                ? 0U
                                                : (IData)(Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_hbca619ae__0)) 
                                              & ((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                                  ? 0U
                                                  : 0xffffffffU)) 
                                             & ((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                                 ? 0U
                                                 : 0xffffffffU)) 
                                            >> 1U))) 
                       + (0x1ffU & (((((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                        ? 0U : (IData)(Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_h9af5e858__0)) 
                                      & ((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                          ? 0U : 0xffffffffU)) 
                                     & ((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                                         ? 0U : 0xffffffffU)) 
                                    >> 1U))));
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_out_of_draw_range 
        = (VL_GTS_III(32, 0U, VL_EXTENDS_II(32,16, (IData)(Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_h9af5e858__0))) 
           | (VL_LTES_III(32, 0x280U, VL_EXTENDS_II(32,16, (IData)(Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_h9af5e858__0))) 
              | (VL_GTS_III(32, 0U, VL_EXTENDS_II(32,16, (IData)(Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_hbca619ae__0))) 
                 | VL_LTES_III(32, 0x1e0U, VL_EXTENDS_II(32,16, (IData)(Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_hbca619ae__0))))));
    vlSelf->Top_template__DOT__fb_mgr__DOT__next_write_source_sel 
        = vlSelf->Top_template__DOT__bf_write_source_sel;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next = 0U;
    if ((0U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        if ((1U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next 
                = ((0x31U > (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                    ? (0x3fU & ((IData)(1U) + (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr)))
                    : 0U);
        } else if ((2U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            if ((3U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next 
                    = ((0x31U > (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                        ? (0x3fU & ((IData)(1U) + (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr)))
                        : 0U);
            } else if ((4U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next 
                    = ((0x31U > (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                        ? (0x3fU & ((IData)(1U) + (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr)))
                        : 0U);
            } else if ((5U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                if ((6U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next 
                        = ((0x31U > (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                            ? (0x3fU & ((IData)(1U) 
                                        + (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr)))
                            : 0U);
                }
            }
        }
    }
    if ((0U != vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__next_active_framebuffer 
            = vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer;
        if ((1U != vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
            if ((2U != vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
                if ((3U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
                    vlSelf->Top_template__DOT__fb_mgr__DOT__next_write_source_sel 
                        = ((IData)(vlSelf->Top_template__DOT__bf_write_source_sel) 
                           & ((IData)(1U) + (IData)(vlSelf->Top_template__DOT__bf_write_source_sel)));
                }
                if ((3U != vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
                    if ((4U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
                        vlSelf->Top_template__DOT__fb_mgr__DOT__next_active_framebuffer 
                            = (1U & ((IData)(vlSelf->Top_template__DOT__Screen_control__DOT__frame_i)
                                      ? (~ (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer))
                                      : (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer)));
                    }
                }
            }
        }
    } else {
        vlSelf->Top_template__DOT__fb_mgr__DOT__next_active_framebuffer 
            = vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer;
    }
    vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next = 0U;
    if ((0U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next = 1U;
    } else if ((1U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next 
            = ((IData)(vlSelf->Top_template__DOT__bf_write_active)
                ? 2U : 1U);
    } else if ((2U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next 
            = ((IData)(vlSelf->Top_template__DOT__bf_write_active)
                ? 2U : 3U);
    } else if ((3U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next 
            = ((IData)(vlSelf->Top_template__DOT__bf_write_source_sel)
                ? 0U : 4U);
    } else if ((4U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next 
            = ((IData)(vlSelf->Top_template__DOT__Screen_control__DOT__frame_i)
                ? 0U : 4U);
    }
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 0U;
    if ((0U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 1U;
    } else if ((1U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next 
            = ((0x31U > (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                ? 1U : 2U);
    } else if ((2U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 3U;
    } else if ((3U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next 
            = ((0x31U > (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                ? 3U : 4U);
    } else if ((4U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next 
            = ((0x31U > (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                ? 4U : 5U);
    } else if ((5U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next 
            = (((~ (IData)(vlSelf->Top_template__DOT__bf_write_source_sel)) 
                & (IData)(vlSelf->Top_template__DOT__bf_write_awaited))
                ? 6U : 5U);
    } else if ((6U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 6U;
        if ((0x31U == (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
            vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 3U;
        }
    } else {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 0U;
    }
    if ((1U & (~ (IData)(vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN)))) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__next_write_source_sel = 0U;
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next = 0U;
        vlSelf->Top_template__DOT__fb_mgr__DOT__next_active_framebuffer = 0U;
        vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next = 0U;
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 0U;
    }
    vlSelf->Top_template__DOT__fb_mgr__DOT____VdfgTmp_h76e62aff__0 
        = ((~ ((~ (IData)(vlSelf->Top_template__DOT__bf_write_source_sel)) 
               & (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_out_of_draw_range))) 
           & (IData)(vlSelf->Top_template__DOT__bf_write_active));
}

VL_ATTR_COLD void Vtop_arcade___024root___eval_stl(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vtop_arcade___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__ico(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__act(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk_25)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge Top_template.__Vcellinp__fb_mgr__resetN or posedge clk_25)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__nba(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk_25)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge Top_template.__Vcellinp__fb_mgr__resetN or posedge clk_25)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_arcade___024root___ctor_var_reset(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->SW = VL_RAND_RESET_I(10);
    vlSelf->VGA_B = VL_RAND_RESET_I(4);
    vlSelf->VGA_G = VL_RAND_RESET_I(4);
    vlSelf->VGA_HS = VL_RAND_RESET_I(1);
    vlSelf->VGA_R = VL_RAND_RESET_I(4);
    vlSelf->VGA_VS = VL_RAND_RESET_I(1);
    vlSelf->pxl_x = VL_RAND_RESET_I(32);
    vlSelf->pxl_y = VL_RAND_RESET_I(32);
    vlSelf->disp_ena = VL_RAND_RESET_I(1);
    vlSelf->clk_25 = VL_RAND_RESET_I(1);
    vlSelf->clk_50 = VL_RAND_RESET_I(1);
    vlSelf->clk_100 = VL_RAND_RESET_I(1);
    vlSelf->A = VL_RAND_RESET_I(1);
    vlSelf->B = VL_RAND_RESET_I(1);
    vlSelf->Select = VL_RAND_RESET_I(1);
    vlSelf->Start = VL_RAND_RESET_I(1);
    vlSelf->Right = VL_RAND_RESET_I(1);
    vlSelf->Left = VL_RAND_RESET_I(1);
    vlSelf->Up = VL_RAND_RESET_I(1);
    vlSelf->Down = VL_RAND_RESET_I(1);
    vlSelf->Wheel = VL_RAND_RESET_I(12);
    vlSelf->WheelY = VL_RAND_RESET_I(12);
    vlSelf->Top_template__DOT__h_sync_wire = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__v_sync_wire = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__bf_draw_data = VL_RAND_RESET_I(9);
    vlSelf->Top_template__DOT__bf_write_active = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__bf_write_awaited = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__bf_write_source_sel = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__Screen_control__DOT__Pxl_x_e = VL_RAND_RESET_I(32);
    vlSelf->Top_template__DOT__Screen_control__DOT__Pxl_y_e = VL_RAND_RESET_I(32);
    vlSelf->Top_template__DOT__Screen_control__DOT__frame_i = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count = VL_RAND_RESET_I(10);
    vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count = VL_RAND_RESET_I(10);
    vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__fb_mgr__DOT__fb_read_addr = VL_RAND_RESET_I(17);
    vlSelf->Top_template__DOT__fb_mgr__DOT__fb_write_addr = VL_RAND_RESET_I(17);
    vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_0 = VL_RAND_RESET_I(9);
    vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_1 = VL_RAND_RESET_I(9);
    vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state = 0;
    vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next = 0;
    vlSelf->Top_template__DOT__fb_mgr__DOT__next_write_source_sel = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__fb_mgr__DOT__next_active_framebuffer = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__fb_mgr__DOT____VdfgTmp_h76e62aff__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 76800; ++__Vi0) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT____Vlvbound_h15d7246e__0 = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 76800; ++__Vi0) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory[__Vi0] = VL_RAND_RESET_I(9);
    }
    vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT____Vlvbound_h15d7246e__0 = VL_RAND_RESET_I(9);
    for (int __Vi0 = 0; __Vi0 < 50; ++__Vi0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 50; ++__Vi0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 50; ++__Vi0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z[__Vi0] = 0;
    }
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_y = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_en = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_reset = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x = VL_RAND_RESET_I(15);
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y = VL_RAND_RESET_I(15);
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z = VL_RAND_RESET_I(11);
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr = VL_RAND_RESET_I(6);
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next = VL_RAND_RESET_I(6);
    for (int __Vi0 = 0; __Vi0 < 50; ++__Vi0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 50; ++__Vi0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 50; ++__Vi0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c[__Vi0] = VL_RAND_RESET_I(3);
    }
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_out_of_draw_range = VL_RAND_RESET_I(1);
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h50406ad9__0 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h0c23bae4__0 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__0 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h8766ef62__0 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h8766ef62__1 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h03ab28ff__0 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h03ab28ff__1 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h13f3044c__0 = VL_RAND_RESET_I(3);
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__1 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__2 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h50406ad9__1 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h0c23bae4__1 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__3 = 0;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__4 = 0;
    vlSelf->__VstlIterCount = 0;
    vlSelf->__VicoIterCount = 0;
    vlSelf->__Vtrigrprev__TOP__clk_25 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__Top_template__DOT____Vcellinp__fb_mgr__resetN = VL_RAND_RESET_I(1);
    vlSelf->__VactIterCount = 0;
    vlSelf->__VactContinue = 0;
}
