/*
 * AmpelTest.cpp
 *
 *  Created on: 26.11.2017
 *      Author: Gerd
 */

#include "../include/AmpelTest.h"

void AmpelTest::testBlinkend_aus(){
	SUT& sut = createSUT();

	rm.beginInit();
	initBlinkend_aus();
	rm.endInit();

	sut.flash();

	rm.beginTest();
	sut.off();
	rm.endTest();

	ASSERT_EQUAL(rm.getExpected(), rm.getResult());
//	ASSERT_EQUAL(true, rm.success());
}
