#ifndef EXROM_WRITE_PROGRAM_ROM_H
#define EXROM_WRITE_PROGRAM_ROM_H

#include <stdint.h>

void exrom_write_program_rom(void *device, uint16_t address, uint8_t value);

#endif