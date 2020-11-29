#include "caf/all.hpp"
#include "configuration/Atoms.hpp"
#include "chopsticks/Chopstick.hpp"

using namespace caf;

namespace Philosophers {

class Philosopher : public event_based_actor {
  public:
    Philosopher(actor_config&, std::string, Chopsticks::Chopstick, Chopsticks::Chopstick);
  
    const char* name() const override;
  
  protected:
    behavior make_behavior() override;
  
  private:
    std::string name_;
    Chopsticks::Chopstick leftChopstick_;
    Chopsticks::Chopstick rightChopstick_;
    behavior thinking_; // initial behavior
    behavior hungry_;   // tries to take chopsticks
    behavior granted_;  // has one chopstick and waits for the second one
    behavior denied_;   // could not get first chopsticks
    behavior eating_;   // wait for some time, then go thinking again

    const int secondsDelay_ = 1;

    void makeThinkingBehavior();
    void makeHungryBehavior();
    void makeGrantedBehavior();
    void makeDeniedBehavior();
    void makeEatingBehavior();
};

} // Philosophers