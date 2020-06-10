#ifndef DMA_H
#define DMA_H

#include <stdint.h>
#include <stdbool.h>
#include "cpu/cpu.h"
#include "ppu/ppu.h"
#include "bus.h"
#include "device.h"

struct dma {
	struct device device;
	struct bus *bus;
	struct cpu *cpu;
	struct ppu *ppu;

	uint8_t cycle;
	uint8_t page;
	uint8_t address;
	uint8_t value;
	bool write_toggle;
};

struct dma *dma_new(void);
void dma_tick(struct dma *dma);
void dma_destroy(struct dma *dma);

#endif