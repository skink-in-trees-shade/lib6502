#include "cartridge/cartridge.h"
#include "cartridge/mapper/exrom/exrom.h"
#include "read_name_table.h"

uint8_t exrom_read_name_table(void *device, uint16_t address) {
	struct cartridge *cartridge = device;
	struct exrom *exrom = cartridge->mapper_data;
	return exrom->name_table[address & 0x07FF];
}