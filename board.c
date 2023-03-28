/*
 * memory.c
 *
 *  Created on: Jun 14, 2022
 *      Author: Joe Krachey
 */

#include <staff/game_board.h>


IMAGE_TYPE_t Game_Board[3][3] =
{
    { // Upper Row
      {MEGA_MAN},   // Upper Left
      {MONKEY},     // Upper Center
      {MONKEY}      // Upper Right
    },
    { // Middle Row
      {SMILE} ,     // Middle Left
      {MEGA_MAN} ,  // Middle Center
      {MONKEY}      // Middle Right
    },
    { // Lower Row
      {SMILE},      // Lower Left
      {MEGA_MAN},   // Lower Center
      {SMILE}       // Lower Right
    }
};



