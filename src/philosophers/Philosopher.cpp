#include "configuration/Atoms.hpp"
#include "philosophers/Philosopher.hpp"
#include <chrono>

namespace Philosophers {

  Philosopher::Philosopher(
    actor_config& cfg,
    std::string name,
    Chopsticks::Chopstick leftChopstick,
    Chopsticks::Chopstick rightChopstick)
    : event_based_actor(cfg),
      name_(std::move(name)),
      leftChopstick_(std::move(leftChopstick)),
      rightChopstick_(std::move(rightChopstick)) {
    // we only accept one message per state and skip others in the meantime
    set_default_handler(skip);
    makeThinkingBehavior();
    // wait for the first answer of a chopstick
    makeHungryBehavior();
    // philosopher was able to obtain the first chopstick
    makeGrantedBehavior();
    // philosopher was *not* able to obtain the first chopstick
    makeDeniedBehavior();
    // philosopher obtained both chopstick and eats (for five seconds)
    makeEatingBehavior();
  }


  const char* Philosopher::name() const {
    return name_.c_str();
  }

  behavior Philosopher::make_behavior() {
    // start thinking
    send(this, Configuration::think_atom::value);
    // philosophers start to think after receiving {think}
    return {
      [=](Configuration::think_atom) {
        aout(this) << name_ << " starts to think\n";
        delayed_send(this, std::chrono::seconds(secondsDelay_), Configuration::eat_atom::value);
        become(thinking_);
      },
    };
  }

  void Philosopher::makeThinkingBehavior(){
    thinking_.assign(
      [=](Configuration::eat_atom) {
        become(hungry_);
        send(leftChopstick_, Configuration::take_atom::value);
        send(rightChopstick_, Configuration::take_atom::value);
      }
    );
  }

  void Philosopher::makeHungryBehavior(){
    hungry_.assign(
      [=](Configuration::taken_atom, bool result) {
        if (result)
          become(granted_);
        else
          become(denied_);
      }
    );
  }

  void Philosopher::makeGrantedBehavior(){
    granted_.assign(
      [=](Configuration::taken_atom, bool result) {
        if (result) {
          aout(this) << name_ << " has picked up chopsticks with IDs "
                    << leftChopstick_->id() << " and " << rightChopstick_->id()
                    << " and starts to eat\n";
          // eat some time
          delayed_send(this, std::chrono::seconds(secondsDelay_), Configuration::think_atom::value);
          become(eating_);
        } else {
          send(
            current_sender() == leftChopstick_ ? rightChopstick_ : leftChopstick_,
            Configuration::put_atom::value
          );
          send(this, Configuration::eat_atom::value);
          become(thinking_);
        }
      }
    );
  }

  void Philosopher::makeDeniedBehavior() {
    denied_.assign(
      [=](Configuration::taken_atom, bool result) {
        if (result)
          send(
            current_sender() == leftChopstick_ ? leftChopstick_ : rightChopstick_,
            Configuration::put_atom::value
          );
        send(this, Configuration::eat_atom::value);
        become(thinking_);
      }
    );
  }

  void Philosopher::makeEatingBehavior() {
    eating_.assign(
      [=](Configuration::think_atom) {
        send(leftChopstick_, Configuration::put_atom::value);
        send(rightChopstick_, Configuration::put_atom::value);
        delayed_send(this, std::chrono::seconds(secondsDelay_), Configuration::eat_atom::value);
        aout(this) << name_ << " puts down his chopsticks and starts to think\n";
        become(thinking_);
      }
    );
  }

} // Philosophers