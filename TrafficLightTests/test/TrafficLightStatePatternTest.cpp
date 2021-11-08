#include "TrafficLightMiddleEuropeTestPolicy.h"
#include "TrafficLightTestFixture.h"
#include <TCS/TrafficLightStatePattern.hpp>

class TrafficLightStatePatternSUT : public TCS::TrafficLightStatePattern {
public:
  using Timer = SimplePeriodicTimer::PeriodicTimer<TrafficLightStatePatternSUT>;
  TrafficLightStatePatternSUT(Lamp & /* red */, Lamp & /* yellow */,
                              Lamp & /* green */, Timer & /*  timer */)
      : TCS::TrafficLightStatePattern() {}
};

template <> struct TestPolicyLookup<TrafficLightStatePatternSUT> {
  using PolicyType = TrafficLightMiddleEuropeTestPolicy;
};

INSTANTIATE_TYPED_TEST_SUITE_P(TrafficLightStatePatternTest,
                               TrafficLightTestFixture,
                               TrafficLightStatePatternSUT);
