/*
  Orbs, a little program that draws orbs going all over the place
  By Jessica Leyba, 2021
*/

#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ORBS 100

// Definitions
void drawTitle(void);
void drawOrbsScreen(void);
void updateOrbsScreen(void);
int getRandomValue(int min, int max);

// Structures
typedef struct Orb
{
        int x;
        int y;
        int rad;
        int col;
        int xspeed;
        int yspeed;
} Orb;

Orb orbs[NUM_ORBS];
int orbsMax = 1;
int orbsMin = -1;


int main(void)
{
        allegro_init();
        install_keyboard();
        set_gfx_mode(GFX_AUTODETECT,320,200,0,0);

        srand(time(0));


        // Setup orbs
        int i = 0;
        for (i = 0; i < NUM_ORBS; i++)
        {
                orbs[i].x = rand() % 320;
                orbs[i].y = rand() % 200;
                orbs[i].rad = 5;
                orbs[i].col = makecol(rand() % 255, rand() % 255, rand() % 255);
                // Set the x and y speed!
                orbs[i].xspeed = (rand() % (orbsMax + 1 - orbsMin)) + orbsMin;
                orbs[i].yspeed = (rand() % (orbsMax + 1 - orbsMin)) + orbsMin;
        }

        // Draw the title actually we will have two screens
        drawTitle();
        readkey();

        while (!key[KEY_ESC])
        {
                updateOrbsScreen();
                drawOrbsScreen();

        }



        return 0;

}

void drawTitle()
{
    clear_to_color(screen, makecol(0, 0, 0));
    textout_centre_ex(screen, font, "ORBS",SCREEN_W/2,SCREEN_H/2,
    makecol(255, 255, 255),-1);

    textout_centre_ex(screen,font,"Press a key to run program",
    SCREEN_W/2,SCREEN_H-16,makecol(255,255,255),-1);


}

void drawOrbsScreen()
{
        clear_to_color(screen, makecol(0, 0, 0));
        int i = 0;
        for (i = 0; i < NUM_ORBS; i++)
        {
                circlefill(screen, orbs[i].x, orbs[i].y, orbs[i].rad,
                orbs[i].col);
        }
}

void updateOrbsScreen()
{
        int i = 0;
        for (i = 0; i < NUM_ORBS; i++)
        {
                orbs[i].x += orbs[i].xspeed;
                orbs[i].y += orbs[i].yspeed;

                if ((orbs[i].xspeed == 0) && (orbs[i].yspeed) == 0)
                {
                     orbs[i].xspeed = getRandomValue(orbsMin, orbsMax);
                     orbs[i].yspeed = getRandomValue(orbsMin, orbsMax);
                }
                

                // If we go too far left spawn to right of screen
                if (orbs[i].x < -40)
                {
                        orbs[i].x = getRandomValue(320, 340);
                        orbs[i].xspeed = getRandomValue(orbsMin, orbsMax);
                        orbs[i].yspeed = getRandomValue(orbsMin, orbsMax);
                }
                // if we go too far right spwan to left of screen
                if (orbs[i].x > 380)
                {
                        orbs[i].x = getRandomValue(-40, 0);
                        orbs[i].xspeed = getRandomValue(orbsMin, orbsMax);
                        orbs[i].yspeed = getRandomValue(orbsMin, orbsMax);

                }
                if (orbs[i].y > 260)
                {
                        orbs[i].y = getRandomValue(-40, 0);
                        orbs[i].xspeed = getRandomValue(orbsMin, orbsMax);
                        orbs[i].yspeed = getRandomValue(orbsMin, orbsMax);

                }
                if (orbs[i].y < -80)
                {
                        orbs[i].y = getRandomValue(200, 240);
                        orbs[i].xspeed = getRandomValue(orbsMin, orbsMax);
                        orbs[i].yspeed = getRandomValue(orbsMin, orbsMax);

                }
        }
}

int getRandomValue(int min, int max)
{

        if (min > max)
        {
                int tmp = max;
                max = min;
                min = tmp;
        }

        int result = min + rand() % (max - min + 1);
        return result;

}
