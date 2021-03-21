/*
 * AmpelReferenceTest.h
 *
 *  Created on: 26.11.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_TRAFFICLIGHTREFERENCETEST_H_
#define INCLUDE_TRAFFICLIGHTREFERENCETEST_H_

#include "TrafficLightReference.hpp"

#include "TrafficLightTest.h"

template<class SUTImplementation_ = TrafficLightReference>
class TrafficLightReferenceTest : public TrafficLightTest<SUTImplementation_>
{
public:
	using SUTImplementation = SUTImplementation_;
	using this_type = TrafficLightReferenceTest<SUTImplementation>;
	using base_type = TrafficLightTest<SUTImplementation>;
	using SUT = typename base_type::SUT;
	using base_type::red;
	using base_type::yellow;
	using base_type::green;
	using base_type::timer;

	TrafficLightReferenceTest()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
//	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		return base_type::template make_suite<this_type>();
	}
protected:
	std::unique_ptr<SUT> createSUT() {
		return std::unique_ptr<SUT>(
				new SUTImplementation(red, yellow, green, timer)
		);
	}
	// init tests
	void initConstructor() { allOff(); this->timer.setCallback(nullptr);	}
	void initFlashing_off() { allOff();	}
	void initOff_flash() { /* 6 ticks */
		allOff();
		yellow.on(); yellow.off(); yellow.on();  yellow.off(); yellow.on();  yellow.off();
	}
	// helper
	void allOff(){ red.off(); yellow.off(); green.off();}
private:

};



#endif /* INCLUDE_TRAFFICLIGHTREFERENCETEST_H_ */
