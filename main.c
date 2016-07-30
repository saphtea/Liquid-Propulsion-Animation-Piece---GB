#include <gb/gb.h>

#include "ct/sprA.h"
#include "ct/sprB.h"
#include "ct/sprC.h"
#include "ct/sprD.h"
#include "ct/sprE.h"
#include "ct/sprF.h"
#include "ct/sprG.h"
#include "ct/sprH.h"

void drawImage(unsigned char *tile, unsigned char *map){
        wait_vbl_done();

        // Load up the tile data
        set_bkg_data(0, 255, tile);

        // Switch to VRAM
        VBK_REG = 1;

        // Switch out of VRAM
        VBK_REG = 0;

        // Set screen x,y pos to 0,0 and draw the map 20, 18 (size of the screen)
        set_bkg_tiles(0, 0, 20, 18, map);

        // Show the background
        SHOW_BKG;

        // Turn the display on
        DISPLAY_ON;

        // I wish these number were as exact as they look ;-;
        delay(125);
}


void main() {

    while (1) {
        drawImage(sprA_tile_data, sprA_map_data);
        // Additional first frame delay
        delay(98);

        drawImage(sprB_tile_data, sprB_map_data);

        drawImage(sprC_tile_data, sprC_map_data);

        drawImage(sprD_tile_data, sprD_map_data);

        drawImage(sprE_tile_data, sprE_map_data);

        drawImage(sprG_tile_data, sprG_map_data);

        drawImage(sprH_tile_data, sprH_map_data);

    }
}
