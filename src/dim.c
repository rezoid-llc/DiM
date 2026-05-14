/*
//
//    "Digital Implementation Machine" Official Emulation System
//    Written by Daniel Perez.
//
//    May 11th, 2026; 01:56 PM
//    Licensed utilizing the Apache License.
// 
*/


//  #include <stdio.h>
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

    uint32_t temporary_a = 0x00000000;

    if (DIM_MEMORY_MAXIMUM > DIM_MEMORY_PRESENT) {
      while (temporary_a <= DIM_MEMORY_PRESENT && temporary_a <= DIM_MEMORY_MAXIMUM) {
        memory[temporary_a] = 0x00;
        temporary_a += 0x01;
      } return 0x00;
    } else {
      return 0x01;
    }
    
}

int main (void) {

  dim_reset();
  return 0x00;
  
}
