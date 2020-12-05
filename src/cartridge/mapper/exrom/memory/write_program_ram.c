#include "cartridge/cartridge.h"
#include "cartridge/mapper/exrom/exrom.h"
#include "write_program_ram.h"

void exrom_write_program_ram(void *device, uint16_t address, uint8_t value) {
	struct cartridge *cartridge = device;
	struct exrom *exrom = cartridge->mapper_data;
	exrom->prg_ram[(exrom->prg_ram_bank << 13) | (address & 0x1FFF)] = value;
}