/*
//
//    "Digital Implementation Machine" Official Emulation System
//    Written by Daniel Perez.
//
//    May 11th, 2026; 01:56 PM
//    Licensed utilizing the Apache License.
// 
*/


#include <stdio.h>
#include <stdint.h>
#define DIM_MEMORY_MAXIMUM (1 << 24) - 1
#define DIM_MEMORY_PRESENT (1 << 16) - 1

uint16_t register_a;  //  General-Purpose "A" Register
uint16_t register_b;  //  General-Purpose "B" Register
uint16_t register_c;  //  General-Purpose "C" Register
uint16_t register_d;  //  General-Purpose "D" Register
uint32_t register_e;  //  Instruction Incrementer "E" Register
uint16_t register_f;  //  Flags "F" Register

uint8_t memory[DIM_MEMORY_PRESENT]; //  General-Purpose Memory  


uint8_t dim_reset (void) {

    register_a = 0x0000;
    register_b = 0x0000;
    register_c = 0x0000;
    register_d = 0x0000;
    register_e = 0x00000000;
    register_f = 0x0000;

    uint32_t increment = 0x00000000;

    if (DIM_MEMORY_MAXIMUM > DIM_MEMORY_PRESENT) {
      while (increment <= DIM_MEMORY_PRESENT && increment <= DIM_MEMORY_MAXIMUM) {
        memory[increment] = 0x00;
        increment += 0x01;
      } return 0x00;
    } else {
      return 0x01;
    }
    
}

void dim_step (void) {

    uint8_t opcode_byte = memory[register_e];
    uint8_t opcode_selection = opcode_byte & 0x3F;
    uint8_t register_selection = opcode_byte & 0xC0;

    printf("E: 0x%06X\n", register_e);

    switch (opcode_selection) {
        case (0x00):
            //  "NLL"
            register_e += 0x01;
            break;
        case (0x01):
            //  "HLT"
            register_f |= 0x0001;
            break;
        default:
            register_e += 0x01;
            break;
    }
    
}


int main (void) {

  dim_reset();

  memory[0x000000] = 0x00;
  memory[0x000001] = 0x01;

  while (register_e <= DIM_MEMORY_PRESENT && register_e <= DIM_MEMORY_MAXIMUM && (!(register_f & 0x01))) {
      dim_step();
  }

  return 0x00;
  
}
