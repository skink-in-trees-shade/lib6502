#include "cartridge/cartridge.h"
#include "cartridge/mapper/exrom/exrom.h"
#include "select_program_ram_bank.h"

void exrom_select_program_ram_bank(void *device, uint16_t address, uint8_t value) {
	(void)address;

	struct cartridge *cartridge = device;
	struct exrom *exrom = cartridge->mapper_data;
	exrom->prg_ram_bank = value & 0x07;
}