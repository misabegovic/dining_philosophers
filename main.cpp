/******************************************************************************\
 * This example is an implementation of the classical Dining Philosophers     *
 * exercise using only libcaf's event-based actor implementation.             *
\******************************************************************************/
 
#include <iostream>
#include <map>
#include <sstream>
#include <thread>
#include <utility>
#include <vector>
 
#include "caf/all.hpp"
#include "configuration/Atoms.hpp"
#include "chopsticks/Chopstick.hpp"
#include "chopsticks/behaviors/Available.hpp"
#include "philosophers/Philosopher.hpp"
 
using namespace caf;
  
void caf_main(actor_system& system, const actor_system_config&) {
  scoped_actor self{system};
  // create five chopsticks
  aout(self) << "chopstick ids are:";
  std::vector<Chopsticks::Chopstick> chopsticks;
  for (size_t i = 0; i < 5; ++i) {
    chopsticks.push_back(self->spawn(Chopsticks::Behaviors::Available));
    aout(self) << " " << chopsticks.back()->id();
  }
  aout(self) << std::endl;
  // spawn five philosophers
  std::vector<std::string> names{"Plato", "Hume", "Kant", "Nietzsche",
                                 "Descartes"};
  for (size_t i = 0; i < 5; ++i)
    self->spawn<Philosophers::Philosopher>(names[i], chopsticks[i], chopsticks[(i + 1) % 5]);
}
 
CAF_MAIN()