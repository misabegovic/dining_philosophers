#include "chopsticks/behaviors/Available.hpp"
#include "chopsticks/behaviors/Taken.hpp"
#include "configuration/Atoms.hpp"

namespace Chopsticks {
namespace Behaviors {

Chopstick::behavior_type Taken(Chopstick::pointer self,
                                         const strong_actor_ptr& user) {
  return {
    [](Configuration::take_atom) -> std::tuple<Configuration::taken_atom, bool> {
      // notify that this chopstick is already taken
      return std::make_tuple(
        Configuration::taken_atom::value,
        false
      );
    },
    [=](Configuration::put_atom) {
      if (self->current_sender() == user)
        self->become(Available(self));
    },
  };
}

} // Behaviors
} // Chopsticks