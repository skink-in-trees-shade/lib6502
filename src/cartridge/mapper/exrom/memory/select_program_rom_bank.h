#ifndef EXROM_SELECT_PROGRAM_ROM_BANK_H
#define EXROM_SELECT_PROGRAM_ROM_BANK_H

#include <stdint.h>

void exrom_select_program_rom_bank(void *device, uint16_t address, uint8_t value);

#endif