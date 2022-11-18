CFLAGS = -O2
SDL_CFLAGS = `sdl2-config --cflags`
SDL_LDFLAGS = `sdl2-config --libs`

arcade: arcade.exe

%.exe: %.mk
	make -C ./obj_dir -f Vtop_$<

%.mk: top_%.sv
	verilator -I.. -cc $< --exe main_$(basename $@).cpp -o $(basename $@) \
		-CFLAGS "${CFLAGS} ${SDL_CFLAGS}" -LDFLAGS "${SDL_LDFLAGS}" --error-limit 5 \
		-Wno-TIMESCALEMOD \
		-Wno-WIDTH \
		-Wno-LITENDIAN

all: arcade

clean:
	rm -rf ./obj_dir

.PHONY: all clean
