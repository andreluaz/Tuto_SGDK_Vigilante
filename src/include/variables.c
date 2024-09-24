#include <genesis.h>




#include "structures.h"








//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                  GENERAL VARIABLES                                   //
//                                                                                      //
//--------------------------------------------------------------------------------------//

char text_output[5];
u16 palette_64[64];


u8 G_COUNTER_LOGO;
u8 G_COUNTER_TITLE;




u8 G_SEQUENCE;
u8 G_LEVEL;
bool G_SEQUENCE_LOADED;


u16 G_ADR_VRAM_BG_B;
u16 G_ADR_VRAM_BG_A;
u16 G_ADR_VRAM_HUB;


s16 G_POS_X_CAMERA;




Map *map_BG_B;
Map *map_BG_A;




struct_PLAYER_ player;
bool player_AXIS;
bool G_REPEAT;
u8 G_INDEX_ANIM_PUNCH;









//--------------------------------------------------------------------------------------//
//                                                                                      //
//                                       SPRITES                                        //
//                                                                                      //
//--------------------------------------------------------------------------------------//

Sprite *sprite_PLAYER;



