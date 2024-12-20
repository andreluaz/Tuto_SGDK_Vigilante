#include <genesis.h>



#include "custom_tools.h"
#include "structures.h"
#include "variables.h"




#include "maps_TITLE.h"


#include "musics.h"


#include "palettes.h"



#include "joypad_BUTTONS.h"







void sequence_TITLE()
{
    // TITLE SCROLLING //
    if(G_POS_X_CAMERA < 256)
    {
        G_POS_X_CAMERA += 1;

        VDP_setHorizontalScrollVSync(BG_B,G_POS_X_CAMERA);
        VDP_setHorizontalScrollVSync(BG_A,G_POS_X_CAMERA);

        
        if(G_POS_X_CAMERA == 256)
        {
            // DISPLAY PRESS START BUTTON //
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 39, 19, 39, 28, 18, 1, DMA_QUEUE);

            // DISPLAY LEVEL //
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 44, 21, 59, 28, 5, 1, DMA_QUEUE);

            // DISPLAY LEVEL NUMBER //
            VDP_drawIntEx_BG_A_QUEUE(G_LEVEL,1,51,21,PAL0);

            // DISPLAY LIVES //
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 44, 23, 19, 28, 5, 1, DMA_QUEUE);

            // DISPLAY LIVES NUMBER //
            VDP_drawIntEx_BG_A_QUEUE(G_NUMBER_LIVES,1,51,23,PAL0);

            // SELECTION ARROW //
            SPR_setPosition(sprite_ARROW , 72 , 168);

            // PLAY MUSIC //
            u8 music_state = XGM_isPlaying();

            if(music_state != 64)
            {
                XGM_startPlay(MUSIC_TITLE);
            }
        }
    }

    // PRESS START BUTTON BLINKING //
    else
    {        
        if(G_COUNTER_TITLE == 0)
        {
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 39, 19, 39, 28, 18, 1, DMA_QUEUE);
        }

        else if(G_COUNTER_TITLE == 15)
        {
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 39, 19, 39, 21, 18, 1, DMA_QUEUE);
        }

        else if(G_COUNTER_TITLE == 30)
        {
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 39, 19, 39, 28, 18, 1, DMA_QUEUE);
        }

        else if(G_COUNTER_TITLE == 45)
        {
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 39, 19, 39, 21, 18, 1, DMA_QUEUE);
        }

        else if(G_COUNTER_TITLE == 60)
        {
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 39, 19, 39, 28, 18, 1, DMA_QUEUE);
        }

        else if(G_COUNTER_TITLE == 75)
        {
            VDP_setTileMapEx(BG_A, image_TITLE_BG_B.tilemap, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, G_ADR_VRAM_BG_B), 39, 19, 39, 21, 18, 1, DMA_QUEUE);
        }

        G_COUNTER_TITLE += 1;

        if(G_COUNTER_TITLE == 89)
        {
            G_COUNTER_TITLE = 0;
        }


        G_TIMER += 1;

        if(G_TIMER == 534)
        {
            JOY_setEventHandler(disable_Callback);
            
            G_TIMER = 0;

            PAL_setPalette(PAL0,palette_BLACK.data,DMA_QUEUE);
            PAL_setPalette(PAL1,palette_BLACK.data,DMA_QUEUE);

            // STOP MUSIC //
            //XGM_stopPlay();

            SYS_doVBlankProcess();

            // CLEAR PLANES //
            VDP_clearPlane(BG_B,TRUE);
            VDP_clearPlane(BG_A,TRUE);

            // RELEASE ALL SPRITES //
            SPR_reset();

            G_SEQUENCE = SEQUENCE_RANKING;

            G_SEQUENCE_LOADED = FALSE;

            SYS_doVBlankProcess();
        }
    }
}