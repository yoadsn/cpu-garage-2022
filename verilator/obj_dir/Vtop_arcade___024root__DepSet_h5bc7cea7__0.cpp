// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_arcade.h for the primary calling header

#include "verilated.h"

#include "Vtop_arcade___024root.h"

VL_INLINE_OPT void Vtop_arcade___024root___ico_sequent__TOP__0(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN 
        = (1U & (~ (IData)(vlSelf->A)));
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
}

void Vtop_arcade___024root___eval_ico(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop_arcade___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop_arcade___024root___eval_act(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop_arcade___024root___nba_sequent__TOP__0(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ Top_template__DOT____Vcellout__fb_mgr__read_color_data;
    SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_hbca619ae__0;
    SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____VdfgTmp_h9af5e858__0;
    SData/*9:0*/ __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count;
    SData/*9:0*/ __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count;
    IData/*16:0*/ __Vdlyvdim0__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0;
    SData/*8:0*/ __Vdlyvval__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0;
    IData/*16:0*/ __Vdlyvdim0__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0;
    SData/*8:0*/ __Vdlyvval__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1;
    SData/*15:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1;
    CData/*5:0*/ __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0;
    CData/*2:0*/ __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0;
    CData/*0:0*/ __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0;
    SData/*14:0*/ __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x;
    SData/*14:0*/ __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y;
    SData/*10:0*/ __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z;
    // Body
    __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count 
        = vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count;
    __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count 
        = vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count;
    __Vdlyvset__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0 = 0U;
    __Vdlyvset__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0 = 0U;
    __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z 
        = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z;
    __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y 
        = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y;
    __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x 
        = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0 = 0U;
    __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1 = 0U;
    if (((~ (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer)) 
         & (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT____VdfgTmp_h76e62aff__0))) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT____Vlvbound_h15d7246e__0 
            = vlSelf->Top_template__DOT__bf_draw_data;
        if ((0x12bffU >= vlSelf->Top_template__DOT__fb_mgr__DOT__fb_write_addr)) {
            __Vdlyvval__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0 
                = vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT____Vlvbound_h15d7246e__0;
            __Vdlyvset__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0 = 1U;
            __Vdlyvdim0__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0 
                = vlSelf->Top_template__DOT__fb_mgr__DOT__fb_write_addr;
        }
    }
    if (((IData)(vlSelf->Top_template__DOT__fb_mgr__DOT____VdfgTmp_h76e62aff__0) 
         & (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer))) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT____Vlvbound_h15d7246e__0 
            = vlSelf->Top_template__DOT__bf_draw_data;
        if ((0x12bffU >= vlSelf->Top_template__DOT__fb_mgr__DOT__fb_write_addr)) {
            __Vdlyvval__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0 
                = vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT____Vlvbound_h15d7246e__0;
            __Vdlyvset__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0 = 1U;
            __Vdlyvdim0__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0 
                = vlSelf->Top_template__DOT__fb_mgr__DOT__fb_write_addr;
        }
    }
    if (vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_en) {
        __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z 
            = ((0x3ffU & ((IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z) 
                          >> 1U)) ^ ((1U & (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z))
                                      ? 0x500U : 0U));
        __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y 
            = ((0x3fffU & ((IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y) 
                           >> 1U)) ^ ((1U & (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y))
                                       ? 0x6000U : 0U));
        __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x 
            = ((0x3fffU & ((IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x) 
                           >> 1U)) ^ ((1U & (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x))
                                       ? 0x6000U : 0U));
    }
    if (vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_reset) {
        __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z = 0x143U;
        __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y = 0x17U;
        __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x = 0x15b3U;
    }
    if ((0x12bffU >= vlSelf->Top_template__DOT__fb_mgr__DOT__fb_read_addr)) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_1 
            = vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory
            [vlSelf->Top_template__DOT__fb_mgr__DOT__fb_read_addr];
        vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_0 
            = vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory
            [vlSelf->Top_template__DOT__fb_mgr__DOT__fb_read_addr];
    } else {
        vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_1 = 0U;
        vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_0 = 0U;
    }
    vlSelf->Top_template__DOT__bf_write_source_sel 
        = vlSelf->Top_template__DOT__fb_mgr__DOT__next_write_source_sel;
    if ((0x31fU > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count))) {
        __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count)));
    } else {
        __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count 
            = ((0x20cU > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count))
                ? (0x3ffU & ((IData)(1U) + (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count)))
                : 0U);
        __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count = 0U;
    }
    vlSelf->Top_template__DOT__h_sync_wire = ((0x291U 
                                               > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count)) 
                                              | (0x2f1U 
                                                 < (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count)));
    vlSelf->Top_template__DOT__v_sync_wire = ((0x1eaU 
                                               > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count)) 
                                              | (0x1ecU 
                                                 < (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count)));
    if ((0x281U > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count))) {
        if ((0x280U > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count))) {
            vlSelf->Top_template__DOT__Screen_control__DOT__Pxl_x_e 
                = vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count;
        }
    }
    if ((0x1e0U > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count))) {
        vlSelf->Top_template__DOT__Screen_control__DOT__Pxl_y_e 
            = vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count;
    }
    vlSelf->Top_template__DOT__Screen_control__DOT__frame_i 
        = ((0x27fU == (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count)) 
           & (0x1dfU == (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count)));
    vlSelf->disp_ena = (((1U <= (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count)) 
                         & (0x281U > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count))) 
                        & (0x1e0U > (IData)(vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count)));
    if ((0U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        if ((1U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            if ((2U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                if ((3U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h13f3044c__0 = 7U;
                    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                        __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h13f3044c__0;
                        __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0 = 1U;
                        __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                    }
                }
            }
        }
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c__v0;
    }
    if ((0U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        if ((1U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h0c23bae4__0 
                = (0xffffU & (VL_MODDIV_III(32, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y), (IData)(0x2580U)) 
                              - (IData)(0x12c0U)));
            vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h50406ad9__0 
                = (0xffffU & (((IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x) 
                               + VL_MODDIV_III(32, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x), (IData)(0x3200U))) 
                              - (IData)(0x1900U)));
            vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__0 
                = (0xffffU & VL_MODDIV_III(32, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z), (IData)(0x2bcU)));
            if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0 
                    = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h0c23bae4__0;
                __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0 = 1U;
                __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0 
                    = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0 
                    = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h50406ad9__0;
                __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0 = 1U;
                __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0 
                    = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0 
                    = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__0;
                __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0 = 1U;
                __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0 
                    = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
            }
        } else if ((2U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            if ((3U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                if ((4U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                    if (vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_out_of_draw_range) {
                        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h0c23bae4__1 
                            = (0xffffU & (VL_MODDIV_III(32, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y), (IData)(0x2580U)) 
                                          - (IData)(0x12c0U)));
                        if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                            __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1 
                                = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h0c23bae4__1;
                            __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1 = 1U;
                            __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1 
                                = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                        }
                    }
                }
            }
            if ((3U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                if (VL_GTES_III(16, ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                      ? vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x
                                     [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                      : 0U), (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x))) {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h8766ef62__0 
                        = (0xffffU & ((IData)(0x140U) 
                                      + VL_DIVS_III(32, 
                                                    VL_MULS_III(32, (IData)(0xaU), 
                                                                (VL_EXTENDS_II(32,16, 
                                                                               ((0x31U 
                                                                                >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                                                 ? 
                                                                                vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x
                                                                                [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                                                 : 0U)) 
                                                                 - 
                                                                 VL_EXTENDS_II(32,16, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x)))), 
                                                    VL_EXTENDS_II(32,16, 
                                                                  ((0x31U 
                                                                    >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                                    ? 
                                                                   vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z
                                                                   [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                                    : 0U)))));
                    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                        __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h8766ef62__0;
                        __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0 = 1U;
                        __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                    }
                } else {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h8766ef62__1 
                        = (0xffffU & ((IData)(0x140U) 
                                      - VL_DIVS_III(32, 
                                                    VL_MULS_III(32, (IData)(0xaU), 
                                                                (VL_EXTENDS_II(32,16, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x)) 
                                                                 - 
                                                                 VL_EXTENDS_II(32,16, 
                                                                               ((0x31U 
                                                                                >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                                                 ? 
                                                                                vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x
                                                                                [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                                                 : 0U)))), 
                                                    VL_EXTENDS_II(32,16, 
                                                                  ((0x31U 
                                                                    >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                                    ? 
                                                                   vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z
                                                                   [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                                    : 0U)))));
                    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                        __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h8766ef62__1;
                        __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1 = 1U;
                        __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                    }
                }
                if (VL_GTES_III(16, ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                      ? vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y
                                     [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                      : 0U), (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_y))) {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h03ab28ff__0 
                        = (0xffffU & ((IData)(0xf0U) 
                                      + VL_DIVS_III(32, 
                                                    VL_MULS_III(32, (IData)(0xaU), 
                                                                (VL_EXTENDS_II(32,16, 
                                                                               ((0x31U 
                                                                                >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                                                 ? 
                                                                                vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y
                                                                                [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                                                 : 0U)) 
                                                                 - 
                                                                 VL_EXTENDS_II(32,16, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_y)))), 
                                                    VL_EXTENDS_II(32,16, 
                                                                  ((0x31U 
                                                                    >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                                    ? 
                                                                   vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z
                                                                   [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                                    : 0U)))));
                    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                        __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h03ab28ff__0;
                        __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0 = 1U;
                        __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                    }
                } else {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h03ab28ff__1 
                        = (0xffffU & ((IData)(0xf0U) 
                                      - VL_DIVS_III(32, 
                                                    VL_MULS_III(32, (IData)(0xaU), 
                                                                (VL_EXTENDS_II(32,16, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_y)) 
                                                                 - 
                                                                 VL_EXTENDS_II(32,16, 
                                                                               ((0x31U 
                                                                                >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                                                 ? 
                                                                                vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y
                                                                                [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                                                 : 0U)))), 
                                                    VL_EXTENDS_II(32,16, 
                                                                  ((0x31U 
                                                                    >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                                    ? 
                                                                   vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z
                                                                   [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                                    : 0U)))));
                    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                        __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h03ab28ff__1;
                        __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1 = 1U;
                        __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                    }
                }
            } else if ((4U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                if (VL_GTES_III(32, 5U, VL_EXTENDS_II(32,16, 
                                                      ((0x31U 
                                                        >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                        ? 
                                                       vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z
                                                       [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                        : 0U)))) {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__1 
                        = (0xffffU & ((IData)(0x2bcU) 
                                      - VL_MODDIV_III(32, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z), (IData)(0xe9U))));
                    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                        __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__1;
                        __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1 = 1U;
                        __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                    }
                } else {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__2 
                        = (0xffffU & (VL_EXTENDS_II(16,16, 
                                                    ((0x31U 
                                                      >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                      ? 
                                                     vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z
                                                     [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                      : 0U)) 
                                      - (IData)(5U)));
                    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                        __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__2;
                        __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2 = 1U;
                        __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                    }
                }
                if (vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_out_of_draw_range) {
                    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h50406ad9__1 
                        = (0xffffU & (((IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x) 
                                       + VL_MODDIV_III(32, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x), (IData)(0x3200U))) 
                                      - (IData)(0x1900U)));
                    if (VL_GTES_III(32, 0xe9U, VL_EXTENDS_II(32,16, 
                                                             ((0x31U 
                                                               >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                               ? 
                                                              vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z
                                                              [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                               : 0U)))) {
                        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__3 
                            = (0xffffU & ((IData)(0x2bcU) 
                                          - VL_MODDIV_III(32, (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z), (IData)(0xe9U))));
                        if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                            __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3 
                                = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__3;
                            __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3 = 1U;
                            __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3 
                                = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                        }
                    } else {
                        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__4 
                            = (0xffffU & ((IData)(0xafU) 
                                          + VL_EXTENDS_II(16,16, 
                                                          ((0x31U 
                                                            >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))
                                                            ? 
                                                           vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z
                                                           [vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr]
                                                            : 0U))));
                        if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                            __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4 
                                = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__4;
                            __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4 = 1U;
                            __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4 
                                = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                        }
                    }
                    if ((0x31U >= (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr))) {
                        __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h50406ad9__1;
                        __Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1 = 1U;
                        __Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1 
                            = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
                    }
                }
            }
        }
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y 
            = __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y;
    } else {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y 
            = __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y;
    }
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x 
        = __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x;
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z 
        = __Vdly__Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z;
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v0;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y__v1;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v0;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x__v1;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v0;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v1;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v2;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v3;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z__v4;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v0;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x__v1;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v0;
    }
    if (__Vdlyvset__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y[__Vdlyvdim0__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1] 
            = __Vdlyvval__Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y__v1;
    }
    if (__Vdlyvset__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory[__Vdlyvdim0__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0] 
            = __Vdlyvval__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory__v0;
    }
    if (__Vdlyvset__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory[__Vdlyvdim0__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0] 
            = __Vdlyvval__Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory__v0;
    }
    vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count 
        = __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count;
    vlSelf->Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count 
        = __Vdly__Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count;
    vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer 
        = vlSelf->Top_template__DOT__fb_mgr__DOT__next_active_framebuffer;
    if ((0U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_reset = 1U;
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x = 0U;
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_y = 0U;
    } else {
        if ((1U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_reset = 0U;
        }
        if ((1U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            if ((2U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                if ((3U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                    if ((4U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x 
                            = ((1U & (IData)(vlSelf->SW))
                                ? 0x3e8U : 0xfc18U);
                        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_y 
                            = ((2U & (IData)(vlSelf->SW))
                                ? 0x3e8U : 0xfc18U);
                    }
                }
            }
        }
    }
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr 
        = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next;
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
    Top_template__DOT____Vcellout__fb_mgr__read_color_data 
        = ((IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__active_framebuffer)
            ? (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_1)
            : (IData)(vlSelf->Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_0));
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
    if ((0U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
        if ((1U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_en = 1U;
        } else if ((2U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_en = 0U;
        } else if ((3U != vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
            if ((4U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_en = 1U;
            } else if ((5U == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state)) {
                vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_en = 0U;
            }
        }
    }
    vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state 
        = vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next;
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
    if ((1U & (~ (IData)(vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN)))) {
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next = 0U;
    }
    vlSelf->Top_template__DOT__bf_write_active = ((~ (IData)(vlSelf->Top_template__DOT__bf_write_source_sel)) 
                                                  & (6U 
                                                     == vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state));
    vlSelf->Top_template__DOT__fb_mgr__DOT____VdfgTmp_h76e62aff__0 
        = ((~ ((~ (IData)(vlSelf->Top_template__DOT__bf_write_source_sel)) 
               & (IData)(vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__star_out_of_draw_range))) 
           & (IData)(vlSelf->Top_template__DOT__bf_write_active));
}

VL_INLINE_OPT void Vtop_arcade___024root___nba_sequent__TOP__1(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN) {
        if ((0U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
            vlSelf->Top_template__DOT__bf_write_awaited = 1U;
        } else if ((2U == vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state)) {
            vlSelf->Top_template__DOT__bf_write_awaited = 0U;
        }
    } else {
        vlSelf->Top_template__DOT__bf_write_awaited = 0U;
    }
}

VL_INLINE_OPT void Vtop_arcade___024root___nba_sequent__TOP__2(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state 
        = vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next;
    vlSelf->Top_template__DOT__fb_mgr__DOT__next_write_source_sel 
        = vlSelf->Top_template__DOT__bf_write_source_sel;
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
    if ((1U & (~ (IData)(vlSelf->Top_template__DOT____Vcellinp__fb_mgr__resetN)))) {
        vlSelf->Top_template__DOT__fb_mgr__DOT__next_write_source_sel = 0U;
        vlSelf->Top_template__DOT__fb_mgr__DOT__next_active_framebuffer = 0U;
        vlSelf->Top_template__DOT__fb_mgr__DOT__wsrc_state_next = 0U;
    }
}

VL_INLINE_OPT void Vtop_arcade___024root___nba_comb__TOP__0(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___nba_comb__TOP__0\n"); );
    // Body
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
        vlSelf->Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next = 0U;
    }
}

void Vtop_arcade___024root___eval_nba(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop_arcade___024root___nba_sequent__TOP__0(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vtop_arcade___024root___nba_sequent__TOP__1(vlSelf);
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop_arcade___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((vlSelf->__VnbaTriggered.at(0U) | vlSelf->__VnbaTriggered.at(1U))) {
        Vtop_arcade___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vtop_arcade___024root___eval_triggers__ico(Vtop_arcade___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__ico(Vtop_arcade___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_arcade___024root___eval_triggers__act(Vtop_arcade___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__act(Vtop_arcade___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_arcade___024root___dump_triggers__nba(Vtop_arcade___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_arcade___024root___eval(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop_arcade___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if ((0x64U < vlSelf->__VicoIterCount)) {
#ifdef VL_DEBUG
                Vtop_arcade___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("top_arcade.sv", 26, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop_arcade___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop_arcade___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if ((0x64U < vlSelf->__VactIterCount)) {
#ifdef VL_DEBUG
                    Vtop_arcade___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("top_arcade.sv", 26, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop_arcade___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if ((0x64U < __VnbaIterCount)) {
#ifdef VL_DEBUG
                Vtop_arcade___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("top_arcade.sv", 26, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop_arcade___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop_arcade___024root___eval_debug_assertions(Vtop_arcade___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_arcade__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_arcade___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->SW & 0xfc00U))) {
        Verilated::overWidthError("SW");}
    if (VL_UNLIKELY((vlSelf->clk_25 & 0xfeU))) {
        Verilated::overWidthError("clk_25");}
    if (VL_UNLIKELY((vlSelf->clk_50 & 0xfeU))) {
        Verilated::overWidthError("clk_50");}
    if (VL_UNLIKELY((vlSelf->clk_100 & 0xfeU))) {
        Verilated::overWidthError("clk_100");}
    if (VL_UNLIKELY((vlSelf->A & 0xfeU))) {
        Verilated::overWidthError("A");}
    if (VL_UNLIKELY((vlSelf->B & 0xfeU))) {
        Verilated::overWidthError("B");}
    if (VL_UNLIKELY((vlSelf->Select & 0xfeU))) {
        Verilated::overWidthError("Select");}
    if (VL_UNLIKELY((vlSelf->Start & 0xfeU))) {
        Verilated::overWidthError("Start");}
    if (VL_UNLIKELY((vlSelf->Right & 0xfeU))) {
        Verilated::overWidthError("Right");}
    if (VL_UNLIKELY((vlSelf->Left & 0xfeU))) {
        Verilated::overWidthError("Left");}
    if (VL_UNLIKELY((vlSelf->Up & 0xfeU))) {
        Verilated::overWidthError("Up");}
    if (VL_UNLIKELY((vlSelf->Down & 0xfeU))) {
        Verilated::overWidthError("Down");}
    if (VL_UNLIKELY((vlSelf->Wheel & 0xf000U))) {
        Verilated::overWidthError("Wheel");}
    if (VL_UNLIKELY((vlSelf->WheelY & 0xf000U))) {
        Verilated::overWidthError("WheelY");}
}
#endif  // VL_DEBUG
