#include "sty.h"

void sty(struct cpu *cpu) {
	cpu_poke(cpu, cpu->operand_address, cpu->y);
}