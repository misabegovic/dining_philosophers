#include "chopsticks/behaviors/Available.hpp"
#include "chopsticks/behaviors/Taken.hpp"
#include "configuration/Atoms.hpp"

namespace Chopsticks {
namespace Behaviors {

Chopstick::behavior_type Available(Chopstick::pointer self) {
  return {
    [=](Configuration::take_atom) -> std::tuple<Configuration::taken_atom, bool> {
      self->become(Taken(self, self->current_sender()));
      return std::make_tuple(
        Configuration::taken_atom::value,
        true
      );
    },
    [](Configuration::put_atom) { 
      std::cerr << "chopstick received unexpected 'put'" << std::endl;
    }
  };
}

} // Behaviors
} // Chopsticks