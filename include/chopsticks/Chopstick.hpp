#include "caf/all.hpp"
#include "configuration/Atoms.hpp"

using namespace caf;

namespace Chopsticks {

using Chopstick = typed_actor<
          replies_to<Configuration::take_atom>::with<Configuration::taken_atom, bool>,
          reacts_to<Configuration::put_atom>
        >;

} // Chopsticks