// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_arcade.h for the primary calling header

#ifndef VERILATED_VTOP_ARCADE___024ROOT_H_
#define VERILATED_VTOP_ARCADE___024ROOT_H_  // guard

#include "verilated.h"

class Vtop_arcade__Syms;

class Vtop_arcade___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk_25,0,0);
        CData/*0:0*/ Top_template__DOT____Vcellinp__fb_mgr__resetN;
        VL_OUT8(VGA_B,3,0);
        VL_OUT8(VGA_G,3,0);
        VL_OUT8(VGA_HS,0,0);
        VL_OUT8(VGA_R,3,0);
        VL_OUT8(VGA_VS,0,0);
        VL_OUT8(disp_ena,0,0);
        VL_IN8(clk_50,0,0);
        VL_IN8(clk_100,0,0);
        VL_IN8(A,0,0);
        VL_IN8(B,0,0);
        VL_IN8(Select,0,0);
        VL_IN8(Start,0,0);
        VL_IN8(Right,0,0);
        VL_IN8(Left,0,0);
        VL_IN8(Up,0,0);
        VL_IN8(Down,0,0);
        CData/*0:0*/ Top_template__DOT__h_sync_wire;
        CData/*0:0*/ Top_template__DOT__v_sync_wire;
        CData/*0:0*/ Top_template__DOT__bf_write_active;
        CData/*0:0*/ Top_template__DOT__bf_write_awaited;
        CData/*0:0*/ Top_template__DOT__bf_write_source_sel;
        CData/*0:0*/ Top_template__DOT__Screen_control__DOT__frame_i;
        CData/*0:0*/ Top_template__DOT__fb_mgr__DOT__active_framebuffer;
        CData/*0:0*/ Top_template__DOT__fb_mgr__DOT__next_write_source_sel;
        CData/*0:0*/ Top_template__DOT__fb_mgr__DOT__next_active_framebuffer;
        CData/*0:0*/ Top_template__DOT__fb_mgr__DOT____VdfgTmp_h76e62aff__0;
        CData/*0:0*/ Top_template__DOT__Starfield_unit_inst__DOT__lfsr_en;
        CData/*0:0*/ Top_template__DOT__Starfield_unit_inst__DOT__lfsr_reset;
        CData/*5:0*/ Top_template__DOT__Starfield_unit_inst__DOT__star_addr;
        CData/*5:0*/ Top_template__DOT__Starfield_unit_inst__DOT__star_addr_next;
        CData/*0:0*/ Top_template__DOT__Starfield_unit_inst__DOT__star_out_of_draw_range;
        CData/*2:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h13f3044c__0;
        CData/*0:0*/ __Vtrigrprev__TOP__clk_25;
        CData/*0:0*/ __Vtrigrprev__TOP__Top_template__DOT____Vcellinp__fb_mgr__resetN;
        CData/*0:0*/ __VactContinue;
        VL_IN16(SW,9,0);
        VL_IN16(Wheel,11,0);
        VL_IN16(WheelY,11,0);
        SData/*8:0*/ Top_template__DOT__bf_draw_data;
        SData/*9:0*/ Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__h_count;
        SData/*9:0*/ Top_template__DOT__Screen_control__DOT__VGA_interface__DOT__v_count;
        SData/*8:0*/ Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_0;
        SData/*8:0*/ Top_template__DOT__fb_mgr__DOT__stored_read_color_fb_1;
        SData/*8:0*/ Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT____Vlvbound_h15d7246e__0;
        SData/*8:0*/ Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT____Vlvbound_h15d7246e__0;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_x;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT__space_view_center_y;
        SData/*14:0*/ Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x;
        SData/*14:0*/ Top_template__DOT__Starfield_unit_inst__DOT__lfsr_y;
        SData/*10:0*/ Top_template__DOT__Starfield_unit_inst__DOT__lfsr_z;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h50406ad9__0;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h0c23bae4__0;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__0;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h8766ef62__0;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h8766ef62__1;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h03ab28ff__0;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h03ab28ff__1;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__1;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__2;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h50406ad9__1;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h0c23bae4__1;
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__3;
    };
    struct {
        SData/*15:0*/ Top_template__DOT__Starfield_unit_inst__DOT____Vlvbound_h325a1028__4;
        VL_OUT(pxl_x,31,0);
        VL_OUT(pxl_y,31,0);
        IData/*31:0*/ Top_template__DOT__Screen_control__DOT__Pxl_x_e;
        IData/*31:0*/ Top_template__DOT__Screen_control__DOT__Pxl_y_e;
        IData/*16:0*/ Top_template__DOT__fb_mgr__DOT__fb_read_addr;
        IData/*16:0*/ Top_template__DOT__fb_mgr__DOT__fb_write_addr;
        IData/*31:0*/ Top_template__DOT__fb_mgr__DOT__wsrc_state;
        IData/*31:0*/ Top_template__DOT__fb_mgr__DOT__wsrc_state_next;
        IData/*31:0*/ Top_template__DOT__Starfield_unit_inst__DOT__sf_state;
        IData/*31:0*/ Top_template__DOT__Starfield_unit_inst__DOT__sf_state_next;
        IData/*31:0*/ __VstlIterCount;
        IData/*31:0*/ __VicoIterCount;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<SData/*8:0*/, 76800> Top_template__DOT__fb_mgr__DOT__stars_draw_fb_0__DOT__memory;
        VlUnpacked<SData/*8:0*/, 76800> Top_template__DOT__fb_mgr__DOT__stars_draw_fb_1__DOT__memory;
        VlUnpacked<SData/*15:0*/, 50> Top_template__DOT__Starfield_unit_inst__DOT__star_locs_x;
        VlUnpacked<SData/*15:0*/, 50> Top_template__DOT__Starfield_unit_inst__DOT__star_locs_y;
        VlUnpacked<SData/*15:0*/, 50> Top_template__DOT__Starfield_unit_inst__DOT__star_locs_z;
        VlUnpacked<SData/*15:0*/, 50> Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_x;
        VlUnpacked<SData/*15:0*/, 50> Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_y;
        VlUnpacked<CData/*2:0*/, 50> Top_template__DOT__Starfield_unit_inst__DOT__stars_draw_buffer_c;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop_arcade__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_arcade___024root(Vtop_arcade__Syms* symsp, const char* name);
    ~Vtop_arcade___024root();
    VL_UNCOPYABLE(Vtop_arcade___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
