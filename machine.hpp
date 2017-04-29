/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#ifndef MACHINE_HPP
#define MACHINE_HPP

#include "test.hpp"
#include "string.hpp"
#include "vector.hpp"
#include "stack.hpp"


// Operation codes. These represent operations that can be executed
// by the virtual machine.
enum
{
  // Basic push/pop
  push_op,  // Push a constant operand
  pop_op,   // Pop an operand
  copy_op,  // Copy the top operand

  // Arithmetic
  add_op,   // Add the top two operands
  sub_op,   // Subtract the top from the lower operands
  mul_op,   // Multiply the top two operands
  div_op,   // Divide the lower from the top
  rem_op,   // Remainder of lower divided by the top

  // Misc.
  print_op, // Pop the top value and print.
  read_op,  // Read a value, push it.
  halt_op,  // Stop executing
};


// Represents an instruction. Every instruction has an operation
// code (one of the values above), and an integer operand.
struct Instruction
{
  Instruction(int o, int a)
    : op(o), arg(a)
  { }

  Instruction(int o)
    : op(o)
  { }

  int op;
  int arg;
};


// Represents the virtual machine. Each machine instance contains
// the source code for a single program.
struct Machine
{
  Machine(std::istream&);

  void run();

  // Program control
  Instruction fetch();

  // Operand stack methods
  int top() const;
  void push(int);
  int pop();

  // Operations
  void copy();
  void add();
  void sub();
  void mul();
  void div();
  void rem();
  void print();
  void read();
  void halt();

  Vector<Instruction> prog;  // A loaded program
  Stack<int>          stack; // The operand stack

  // Registers
  int pc;
};


#endif
