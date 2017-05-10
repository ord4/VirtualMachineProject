/*
	Orion Davis (3003072) ord4@zips.uakron.edu
	The University of Akron
	Computer Science II, Prof. Will
	Project 2: Virtual Machine
*/
#include "machine.hpp"

#include <map>
#include <iostream>
#include <sstream>


// Returns the op code found in the first n characters of s. Throws an
// exception if the operation name is invalid.
static int
get_op(String const& s)
{
  // A lookup table that maps from strings to opcodes.
  static std::map<String, int> ops {
    {"push", push_op},
    {"pop", pop_op},
    {"copy", copy_op},
    {"add", add_op},
    {"sub", sub_op},
    {"mul", mul_op},
    {"div", div_op},
    {"rem", rem_op},
    {"print", print_op},
    {"read", read_op},
    {"halt", halt_op},
  };

  auto iter = ops.find(s);
  if (iter == ops.end()) {
    String msg = "no such opcode '" + s + "'";
    throw std::runtime_error(msg);
  }
  return iter->second;
}


int
get_arg(String const& s)
{
  if (s.empty())
    return 0;
  else
    return std::stoi(s);
}


Machine::Machine(std::istream& is)
{
  // Parse instructions from input.
  while (is) {
    String s;
    getline(is, s);
    if (!is)
      break;

    // Search for a ';', indicating a comment and strip that from the line.
    std::size_t k = s.find(';');
    if (k != String::npos)
      s = s.substr(0, k);

    // Skip empty lines.
    if (s.empty())
      continue;

    // Parse out the opcode and operand.
    std::stringstream ss(s);
    std::string opstr, argstr;
    ss >> opstr >> argstr;

    int op = get_op(opstr);
    int arg = get_arg(argstr);
    Instruction ins(op, arg);
    prog.push_back(ins);
  }
}


void
Machine::run()
{
  // Start the pc at the first instruction.
  pc = 0;

  while (pc != prog.size()) {

    // Get the next instruction.
    Instruction ins = fetch();

    // "Decode" and execute the instruction.
    switch (ins.op) {
      case push_op:
        push(ins.arg);
        break;
      case pop_op:
        pop();
        break;
      case copy_op:
        copy();
        break;
      case add_op:
        add();
        break;
      case sub_op:
        sub();
        break;
      case mul_op:
        mul();
        break;
      case div_op:
        div();
        break;
      case rem_op:
        rem();
        break;
      case print_op:
        print();
        break;
      case read_op:
        read();
        break;
      case halt_op:
        halt();
        break;
    }
  }
}


Instruction
Machine::fetch()
{
  return prog[pc++];
}


int
Machine::top() const
{
  stack.top();
  throw std::logic_error("not implemented");
}


void
Machine::push(int n)
{
	stack.push_front(n);
  throw std::logic_error("not implemented");
}


int
Machine::pop()
{
	stack.pop();
  throw std::logic_error("not implemented");
}


void
Machine::copy()
{
  stack.push_front(stack.returnTop());
  throw std::logic_error("not implemented");
}


void
Machine::add()
{
	int num, sum;

   stack.pop(sum);
   stack.pop(num);
   sum += num;

   // Push sum back onto the stack.
   stack.push_front(sum);
  throw std::logic_error("not implemented");
}


void
Machine::sub()
{
  // TODO: Implement me!
  throw std::logic_error("not implemented");
}


void
Machine::mul()
{
  // TODO: Implement me!
  throw std::logic_error("not implemented");
}


void
Machine::div()
{
  // TODO: Implement me!
  throw std::logic_error("not implemented");
}


void
Machine::rem()
{
  // TODO: Implement me!
  throw std::logic_error("not implemented");
}


void
Machine::print()
{
  // TODO: Implement me!
  throw std::logic_error("not implemented");
}


void
Machine::read()
{
  // TODO: Implement me!
  throw std::logic_error("not implemented");
}


void
Machine::halt()
{
  pc = prog.size();
}
