#include <stdlib.h>
#include "dma.h"

static void _dma_write(void *device, uint16_t address, uint8_t value) {
	(void)address;
	struct dma *dma = device;
	dma->cycle = 0x00;
	dma->address = value << 8;
	dma->write_toggle = true;
}

struct dma *dma_new(struct bus *bus) {
	struct dma *dma = calloc(1, sizeof(struct dma));

	dma->bus = bus;
	bus_register(dma->bus, dma, 0x4014, 0x4014, NULL, &_dma_write);

	return dma;
}

void dma_tick(struct dma *dma) {
	if (dma->write_toggle) {
		if (dma->cycle % 2 == 0) {
			dma->value = bus_read(dma->bus, dma->address++);
		} else {
			bus_write(dma->bus, 0x2004, dma->value);
		}

		dma->cycle++;
		dma->cpu->cycle++;

		if (dma->cycle == 0x201) {
			dma->write_toggle = false;
		}
	}
}

void dma_destroy(struct dma *dma) {
	free(dma);
}