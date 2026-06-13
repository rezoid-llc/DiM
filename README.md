#    "DiM"

##  Overview
This is the primary repository for the Digital Implementation Machine emulator, which is an implementation
of the "Diminished-Instruction-Set-Computer" architecture, albeit written in the "C" programming language.
The primary goal of the project is full compliance with the "DiSC" architecture in all areas as well as to
implement secondary features that further increase usability and allow for an expandable environment.

##  Specifications
These are the general specifications of the emulator, in compliance with the "DiSC" architecture.

+ `16,777,216` (accessible; 24-bit maximum) bytes of memory.
+ `65,536` (installed; 16-bit maximum) bytes of memory.
+ Eight total registers:
    + Four general-purpose registers. (`reg_a`, `reg_b`, `reg_c`, and `reg_d`)
    + Two pointer-purpose registers. (`reg_g` and `reg_h`)
    + One instruction-increment register. (`reg_e`)
    + One "flag" register. (`reg_f`)

These specifications are currently a work-in-progress and are subject to change over time.
