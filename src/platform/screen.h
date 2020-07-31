#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>

struct screen;

struct screen *screen_new(char *title, int width, int height);
void screen_pixel(struct screen *screen, uint8_t x, uint8_t y, uint8_t color_id);
void screen_update(struct screen *screen);
void screen_destroy(struct screen *screen);

#endif