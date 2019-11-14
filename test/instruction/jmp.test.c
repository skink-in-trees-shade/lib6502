#include "util.h"
#include "instruction/jmp.h"
#include "jmp.test.h"

void test_jmp(void) {
	cpu_t *actual = cpu_random();
	actual->operand = 0x24;

	cpu_t *expected = cpu_clone(actual);
	expected->program_counter = 0x24;

	jmp(actual);

	cpu_compare(expected, actual);

	cpu_destroy(expected);
	cpu_destroy(actual);
}