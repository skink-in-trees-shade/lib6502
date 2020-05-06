#include <stdbool.h>
#include "util.h"
#include "instruction/lda.h"
#include "lda.test.h"

void test_lda(void) {
	struct cpu *actual = cpu_random();
	actual->operand = 0x48;

	struct cpu *expected = cpu_clone(actual);
	expected->accumulator = actual->operand;
	expected->zero = false;
	expected->negative = false;

	lda(actual);

	cpu_compare(expected, actual);

	cpu_destroy(expected);
	cpu_destroy(actual);
}

void test_lda_zero(void) {
	struct cpu *actual = cpu_random();
	actual->operand = 0x00;

	struct cpu *expected = cpu_clone(actual);
	expected->accumulator = actual->operand;
	expected->zero = true;
	expected->negative = false;

	lda(actual);

	cpu_compare(expected, actual);

	cpu_destroy(expected);
	cpu_destroy(actual);
}

void test_lda_negative(void) {
	struct cpu *actual = cpu_random();
	actual->operand = 0xF8;

	struct cpu *expected = cpu_clone(actual);
	expected->accumulator = actual->operand;
	expected->zero = false;
	expected->negative = true;

	lda(actual);

	cpu_compare(expected, actual);

	cpu_destroy(expected);
	cpu_destroy(actual);
}