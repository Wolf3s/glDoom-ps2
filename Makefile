EE_BIN = glDoom.elf

EE_OBJS = am_map.o d_console.o d_items.o d_main.o d_net.o doomdef.o doomstat.o doomlib.o dstrings.o \
entity.o f_finale.o f_wipe.o \
g_game.o GL_utils.o gl_video.o gl_wipe.o glsbar.o \
hu_lib.o hu_stuff.o \
i_net.o i_sdlmusic.o i_sdlsound.o i_sound.o i_system.o info.o m_argv.o m_bbox.o \
m_cheat.o m_fixed.o m_menu.o m_misc.o m_random.o m_swap.o mathlib.o mmus2mid.o p_ceilng.o \
p_doors.o p_enemy.o p_floor.o p_inter.o p_lights.o p_map.o p_maputl.o \
p_mobj.o p_plats.o p_pspr.o p_saveg.o p_setup.o p_sight.o p_spec.o \
p_switch.o p_telept.o p_tick.o p_user.o r_bsp.o r_data.o r_draw.o \
r_main.o r_plane.o r_segs.o r_sky.o r_things.o s_sound.o savepic.o sdl_input.o sdl_kbrd.o sdl_video.o sounds.o \
st_lib.o st_stuff.o sys_sdl.o tables.o v_video.o w_wad.o wi_stuff.o z_zone.o \

EE_INCS = -I$(PS2SDK)/ee/include -I$(PS2SDK)/ports/include/SDL2 -I$(PS2SDK)/ports/include -I$(GSKIT)/include -I$(GSKIT)/ee/dma/include -I$(GSKIT)/ee/gs/include -I$(GSKIT)/ee/toolkit/include 
EE_LDFLAGS = -L$(PS2SDK)/ports/lib -L$(PS2SDK)/iop/lib/ -L$(PS2SDK)/ee/lib/ -L$(PS2DEV)/gsKit/lib 
SDL2_LIBS = -lSDL2main -lSDL2_mixer -lSDL2 -lmodplug -lmikmod -logg -lopusfile -lopus -lstdc++ 
PS2GL_LIBS = -lps2glut -lps2gl -lps2stuff
EE_LIBS = $(SDL2_LIBS) $(PS2GL_LIBS) -lcdvd -lm -lps2ip -ldebug -lconfig -lmc -lc -lhdd -lpoweroff -lgskit -ldmakit -ldma -lps2_drivers -lps2_printf -lpatches 
EE_CFLAGS = -Wall -D__PS2__

# contains ee and iop modules 
#EE_ASM_OBJS = asm/poweroff.c asm/freesio2.c asm/iomanX.c asm/sio2man.c asm/freepad.c \
asm/mcman_irx.c asm/mcserv_irx.c asm/ps2dev9.c asm/ps2atad.c asm/ps2fs_irx.c asm/ps2hdd_irx.c \
asm/ps2ip-nm.c asm/ps2ips.c asm/netman.c asm/smap.c asm/ps2http.c asm/usbd_irx.c asm/usbhdfsd_irx.c \
asm/usbmass_bd.c

EE_ASM_OBJS = asm/iomanX.c

EE_ASM_DIR = asm/

EE_OBJS_DIR = obj/

BIN2S = $(PS2SDK)/bin/bin2c

$(EE_ASM_DIR):
	@mkdir -p $@

$(EE_OBJS_DIR):
	@mkdir -p $@
	mv $(EE_OBJS) obj/

all: $(EE_BIN) $(EE_ASM_DIR) $(EE_OBJS_DIR) $(EE_ASM_OBJS)
	@echo "$$HEADER"

#poweroff Module
asm/poweroff.c: $(PS2SDK)/iop/irx/poweroff.irx
	$(BIN2S) $< $@ poweroff_irx

#IRX Modules
asm/freesio2.c: $(PS2SDK)/iop/irx/freesio2.irx
	$(BIN2S) $< $@ freesio2_irx
	
asm/iomanX.c: $(PS2SDK)/iop/irx/iomanX.irx
	$(BIN2S) $< $@ iomanX_irx 

asm/sio2man.c: $(PS2SDK)/iop/irx/sio2man.irx
	$(BIN2S) $< $@ sio2man_irx

asm/freepad.c: $(PS2SDK)/iop/irx/freepad.irx
	$(BIN2S) $< $@ freepad_irx

asm/mcman_irx.c: $(PS2SDK)/iop/irx/mcman.irx
	$(BIN2S) $< $@ mcman_irx

asm/mcserv_irx.c: $(PS2SDK)/iop/irx/mcserv.irx
	$(BIN2S) $< $@ mcserv_irx

asm/ps2dev9.c: $(PS2SDK)/iop/irx/ps2dev9.irx
	$(BIN2S) $< $@ ps2dev9_irx 

asm/ps2atad.c: $(PS2SDK)/iop/irx/ps2atad.irx
	$(BIN2S) $< $@ ps2atad_irx

asm/ps2fs_irx.c: $(PS2SDK)/iop/irx/ps2fs-xosd.irx
	$(BIN2S) $< $@ ps2fs_irx

asm/ps2hdd_irx.c: $(PS2SDK)/iop/irx/ps2hdd-xosd.irx
	$(BIN2S) $< $@ ps2hdd_irx

asm/ps2ip-nm.c: $(PS2SDK)/iop/irx/ps2ip-nm.irx
	$(BIN2S) $< $@ ps2ip-nm_irx

asm/ps2ips.c: $(PS2SDK)/iop/irx/ps2ips.irx
	$(BIN2S) $< $@ ps2ips_irx 

asm/netman.c: $(PS2SDK)/iop/irx/netman.irx 
	$(BIN2S) $< $@ netman_irx 

asm/smap.c: $(PS2SDK)/iop/irx/smap.irx 
	$(BIN2S) $< $@ smap_irx 

asm/ps2http.c: $(PS2SDK)/iop/irx/ps2http.irx 
	$(BIN2S) $< $@ ps2http_irx

asm/usbd_irx.c: $(PS2SDK)/iop/irx/usbd.irx
	$(BIN2S) $< $@ usbd_irx

asm/usbhdfsd_irx.c: $(PS2SDK)/iop/irx/usbhdfsd.irx
	$(BIN2S) $< $@ usb_mass_irx

asm/usbmass_bd.c: $(PS2SDK)/iop/irx/usbmass_bd.irx
	$(BIN2S) $< $@ usbmass_bd_irx

clean: 
	rm -fr $(EE_BIN) $(EE_ASM_DIR) $(EE_OBJS_DIR)
run:
	cd bin; ps2client -h $(PS2LINK_IP) execee host$(EE_BIN)

reset:
	ps2client reset

# taken from tyra engine examples
pcsx2:
	taskkill.exe /f /t /im pcsx2.exe || true
	$(WSL_LINUX_PCSX2)/pcsx2.exe --elf=$(WSL_MAKE_WINDOWS)//root//ps2doom//$(EE_BIN)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal
