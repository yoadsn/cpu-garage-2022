#include <time.h>
#include <stdio.h>
#include <SDL.h>
#include <verilated.h>
#include "Vtop_arcade.h"
#include "Vtop_arcade___024root.h"

// screen dimensions
const int H_RES = 640;
const int V_RES = 480;
const int TOTAL_PIXELS = H_RES * V_RES;

typedef struct Pixel
{              // for SDL texture
    uint8_t a; // transparency
    uint8_t b; // blue
    uint8_t g; // green
    uint8_t r; // red
} Pixel;

const int MAX_WHEEL = 5000; // 4096

int main(int argc, char *argv[])
{
    Verilated::commandArgs(argc, argv);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL init failed.\n");
        return 1;
    }

    Pixel screenbuffer[TOTAL_PIXELS];
    int activePixelAddr = 0;

    SDL_Window *sdl_window = NULL;
    SDL_Renderer *sdl_renderer = NULL;
    SDL_Texture *sdl_texture = NULL;

    sdl_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, H_RES * 2, V_RES * 2,
                                  SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if (!sdl_window)
    {
        printf("Window creation failed: %s\n", SDL_GetError());
        return 1;
    }

    sdl_renderer = SDL_CreateRenderer(sdl_window, -1,
                                      SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!sdl_renderer)
    {
        printf("Renderer creation failed: %s\n", SDL_GetError());
        return 1;
    }

    sdl_texture = SDL_CreateTexture(sdl_renderer, SDL_PIXELFORMAT_RGBA8888,
                                    SDL_TEXTUREACCESS_TARGET, H_RES, V_RES);
    if (!sdl_texture)
    {
        printf("Texture creation failed: %s\n", SDL_GetError());
        return 1;
    }

    // reference SDL keyboard state array: https://wiki.libsdl.org/SDL_GetKeyboardState
    const Uint8 *keyb_state = SDL_GetKeyboardState(NULL);

    // Use mouse X axis movement as wheel turn
    int last_mouse_x, last_mouse_y;
    SDL_SetRelativeMouseMode(SDL_TRUE);

    // initialize Verilog module
    Vtop_arcade *top = new Vtop_arcade;

    /*  uint64_t clock_100 = 0;
     uint64_t clock_50 = 0;
     uint64_t clock_25 = 0; */

    vluint32_t prevx = 0;
    vluint32_t prevy = 0;
    uint64_t enaclicks = 0;
    int prevdisena = 0;
    short wheel_val = 0;

    // reset
    top->SW = 0; // Active low
    top->clk_25 = 0;
    top->eval();
    top->clk_25 = 1;
    top->eval();
    top->SW = 1;
    top->clk_25 = 0;
    top->eval();

    uint64_t frame_count = 0;
    uint64_t start_ticks = SDL_GetPerformanceCounter();
    while (1 /* enaclicks < 1500 */)
    {
        // cycle the clocks
        /* clock_100++;
        if (clock_100 % 2 == 0) {
            clock_50++;
        }
        if (clock_50 % 2 == 0) {
            clock_25++;
        } */

        top->clk_25 = 1;
        top->eval();
        top->clk_25 = 0;
        top->eval();

        // nanosleep((const struct timespec[]){{0, 100L}}, NULL);

        /* //if (top->rootp->Top_template__DOT__Screen_control__DOT__Pxl_y_i > 477 && top->rootp->Top_template__DOT__Screen_control__DOT__Pxl_x_i > 635)
        if (true)
        {
            nanosleep((const struct timespec[]){{0, 100000000L}}, NULL);
            //printf("%d\n", top->rootp->Top_template__DOT__Starfield_unit_inst__DOT__dbg_where);
            // check for quit event
            SDL_Event e;
            if (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                {
                    break;
                }
            }
            else if (keyb_state[SDL_SCANCODE_ESCAPE])
            {
                break;
            }
        } */

        /* if (prevdisena != top->disp_ena)
        {
            enaclicks++;
            // printf("%d %d\n", top->disp_ena, prevdisena);
            // printf("%llu\t", enaclicks);
            prevdisena = top->disp_ena;
        } */

        /* if ((top->pxl_x < 3 || top->pxl_x > 637) && (top->pxl_y < 2 || top->pxl_y > 478))
        {
            // printf("%dX%d(%d)\t", top->pxl_x, top->pxl_y, top->disp_ena);
            //  printf("%d %d %d\n", top->VGA_R, top->VGA_G, top->VGA_B);
        } */

        // update pixel if not in blanking interval
        // if (top->sdl_de) {
        if (top->disp_ena)
        {
            // Pixel *p = &screenbuffer[top->pxl_y * H_RES + top->pxl_x - RENDER_LAT];
            Pixel *p = &screenbuffer[activePixelAddr];
            p->a = 0xFF; // transparency
            p->b = (top->VGA_B << 4) | top->VGA_B;
            p->g = (top->VGA_G << 4) | top->VGA_G;
            p->r = (top->VGA_R << 4) | top->VGA_R;
            activePixelAddr++;
        }

        /* if (prevx != top->pxl_x || prevy != top->pxl_y)
        {
            // printf("PREV DIFF\n");
            if (top->pxl_x % 10 == 0)
            {
                // printf("%dX%d\t --", top->pxl_y, top->pxl_x);
            }
        } */

        /* if (frame_count % 10 == 0)
        {
            // printf("%d %d\n", prevx, prevy);
            //   printf("%d %d %d\n", top->VGA_R, top->VGA_G, top->VGA_B);
            // printf("%llu\n", frame_count);
        } */

        // update texture and keyboard input once per frame (last pixel before blank)
        // if (top->disp_ena && top->pxl_y == (V_RES - 1) && top->pxl_x == (H_RES - 1))
        if (activePixelAddr == TOTAL_PIXELS)
        {
            activePixelAddr = 0;
            // check for quit event
            SDL_Event e;
            if (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                {
                    break;
                }
            }
            else if (keyb_state[SDL_SCANCODE_ESCAPE])
            {
                break;
            }

            // update keyboard state
            top->Up = keyb_state[SDL_SCANCODE_UP];
            top->Down = keyb_state[SDL_SCANCODE_DOWN];
            top->Left = keyb_state[SDL_SCANCODE_LEFT];
            top->Right = keyb_state[SDL_SCANCODE_RIGHT];

            top->Select = keyb_state[SDL_SCANCODE_SPACE];
            top->Start = keyb_state[SDL_SCANCODE_RETURN];

            top->A = keyb_state[SDL_SCANCODE_Q];
            top->B = keyb_state[SDL_SCANCODE_W];

            SDL_GetRelativeMouseState(&last_mouse_x, &last_mouse_y);

            /* if (keyb_state[SDL_SCANCODE_P])
            {
                wheel_val += 50;
            }
            else if (keyb_state[SDL_SCANCODE_O])
            {
                wheel_val -= 50;
            } */
            wheel_val -= (last_mouse_x * 5);
            if (wheel_val < -MAX_WHEEL)
                wheel_val = -MAX_WHEEL;
            if (wheel_val > MAX_WHEEL)
                wheel_val = MAX_WHEEL;
            top->Wheel = wheel_val;

            if (frame_count % 30 == 0)
            {
                // printf("%d\n", wheel_val);
            }

            SDL_UpdateTexture(sdl_texture, NULL, screenbuffer, H_RES * sizeof(Pixel));
            SDL_RenderClear(sdl_renderer);
            SDL_RenderCopy(sdl_renderer, sdl_texture, NULL, NULL);
            SDL_RenderPresent(sdl_renderer);
            frame_count++;

            // printf("%d,%d\n", top->Top_template->Ghost_unit_inst__DOT__topLeft_x_ghost, top->Top_template->Ghost_unit_inst__DOT__topLeft_y_ghost);
            // printf("%d\n", top->rootp->Top_template__DOT__Starfield_unit_inst__DOT__dbg_where);
            // printf("%d\n", top->rootp->Top_template__DOT__Starfield_unit_inst__DOT__lfsr_x);
            // nanosleep((const struct timespec[]){{0, 100000000L}}, NULL);
        }
        /* else if (false && top->pxl_y == 0 && top->pxl_x == 0)
        {
            // check for quit event
            SDL_Event e;
            if (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT)
                {
                    break;
                }
            }
        } */

        /* prevx = top->pxl_x;
        prevy = top->pxl_y; */
    }
    uint64_t end_ticks = SDL_GetPerformanceCounter();
    double duration = ((double)(end_ticks - start_ticks)) / SDL_GetPerformanceFrequency();
    double fps = (double)frame_count / duration;
    printf("Frames per second: %.1f\n", fps);

    top->final(); // simulation done

    SDL_DestroyTexture(sdl_texture);
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
    return 0;
}
