#ifndef EXROM_WRITE_PROGRAM_MODE_H
#define EXROM_WRITE_PROGRAM_MODE_H

#include <stdint.h>

void exrom_write_program_mode(void *device, uint16_t address, uint8_t value);

#endif