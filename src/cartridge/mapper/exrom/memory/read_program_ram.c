#include "cartridge/cartridge.h"
#include "cartridge/mapper/exrom/exrom.h"
#include "read_program_ram.h"

uint8_t exrom_read_program_ram(void *device, uint16_t address) {
	struct cartridge *cartridge = device;
	struct exrom *exrom = cartridge->mapper_data;
	return exrom->prg_ram[(exrom->prg_ram_bank << 13) | (address & 0x1FFF)];
}