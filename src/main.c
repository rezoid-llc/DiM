/*
//    "Digital Implementation Machine"
//    Official Emulation System:
//
//    "main.c"
*/


#include  <stdint.h>
#include  <stdio.h>
#define   MEM_MAX (1 << 24)
#define   MEM_INS (1 << 8)


uint16_t reg_a;         //  "General-Purpose (Register A)";
uint16_t reg_b;         //  "General-Purpose (Register B)";
uint16_t reg_c;         //  "General-Purpose (Register C)";
uint16_t reg_d;         //  "General-Purpose (Register D)";
uint32_t reg_e;         //  "Instruction Pointer (Register E)";
uint8_t  reg_f;         //  "Instruction-Executed Flags (Register F)";
uint32_t reg_g;         //  "Pointer (Register G)";
uint32_t reg_h;         //  "Pointer (Register H)";
uint8_t  mem[MEM_INS];  //  "General-Purpose (Memory)";




void DiM_LOAD (void) {

  mem[0x000000] = 0b00001100;
  
}


void DiM_RESET(void) {

  reg_a = 0x00;
  reg_b = 0x00;
  reg_c = 0x00;
  reg_d = 0x00;
  reg_e = 0x00;
  reg_f = 0x00;
  reg_g = 0x00;
  reg_h = 0x00;

  while (reg_e < MEM_MAX && reg_e < MEM_INS) {
    mem[reg_e] = 0x00;
    reg_e++;
  }

  reg_e = 0x00;

}


void DiM_REG_DUMP(void) {

  printf(">>  A: 0x%04X\n", reg_a);
  printf(">>  B: 0x%04X\n", reg_b);
  printf(">>  C: 0x%04X\n", reg_c);
  printf(">>  D: 0x%04X\n", reg_d);
  printf(">>  E: 0x%06X\n", reg_e);
  printf(">>  F: 0b%08B\n", reg_f);
  printf(">>  G: 0x%06X\n", reg_g);
  printf(">>  H: 0x%06X\n", reg_h);

}


void DiM_MEM_DUMP(void) {

  uint32_t row = 0x00;
  uint32_t col = 0x00;

  while (row < MEM_INS) {
  printf("##  0x%06X:", row);
      while (col < 0x10) {
      printf(" %04X", ((mem[col + row + 0x00] << 0x08) | (mem[col + row + 0x01])));
      col += 0x02; }
  printf("\n");
  col = 0x00;
  row += 0x10;
  }

}


void DiM_TICK(void) {
  /*  For when DiM has a clock.
      DiM currently runs immediately. */
}


void DiM_EXECUTE(void) {

  uint8_t ins = mem[reg_e];
  uint8_t opc = ((ins & 0xFC) >> 0x02);
  uint8_t set = (ins & 0x03);


  switch (opc) {

    case 0x00:
      NLL:; reg_e += 0x01; break;

    case 0x01:
      TRM:; reg_f |= 0x80; break;

    case 0x02:
      RST:; DiM_RESET(); break;

    case 0x03:
      LWI:;
      uint16_t nxt = (mem[reg_e + 0x01] << 0x08 | mem[reg_e + 0x02]);
      if (set == 0x00) { reg_a = nxt; }
      else if (set == 0x01) { reg_b = nxt; }
      else if (set == 0x02) { reg_c = nxt; }
      else if (set == 0x03) { reg_d = nxt; }
      reg_e += 0x02; break;

    default:
      printf("UNKNOWN INSTRUCTION: \"0x%02X\"\n", opc);
      goto TRM;


  }

}


void DiM_VALIDATE(void) {

  reg_a = reg_a & 0xFFFF;
  reg_b = reg_b & 0xFFFF;
  reg_c = reg_c & 0xFFFF;
  reg_d = reg_d & 0xFFFF;
  reg_e = reg_e & (MEM_MAX - 0x01);
  reg_f = reg_f & 0xFF;
  reg_g = reg_g & 0xFFFFFF;
  reg_h = reg_h & 0xFFFFFF;

}




int main(void) {

  DiM_RESET();
  DiM_LOAD();

  while (reg_e < (MEM_INS - 0x01) && reg_e < (MEM_MAX - 0x01) && (!(reg_f & 0x80))) {
    DiM_EXECUTE();
    DiM_VALIDATE();
    DiM_TICK();
  }

  printf("##  REGISTER DUMP:\n");
  DiM_REG_DUMP();
  printf("##  MEMORY DUMP:\n");
  DiM_MEM_DUMP();

  return 0x00;

}
