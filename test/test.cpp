#define BOOST_TEST_MODULE helloworld_test_module

#include "../lib/app_version.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(helloworld_test_suite)

    BOOST_AUTO_TEST_CASE(majorVersionIsCorrect) {
        BOOST_CHECK(majorVersion() == "9");
    }

    BOOST_AUTO_TEST_CASE(minorVersionIsCorrect) {
        BOOST_CHECK(minorVersion() == "5");
    }

    BOOST_AUTO_TEST_CASE(patchVersionIsCorrect) {
        BOOST_CHECK(patchVersion() == "undefined");
    }

    BOOST_AUTO_TEST_CASE(applicationVersionIsCorrect) {
        BOOST_CHECK(applicationVersion() == "9.5.undefined");
    }

BOOST_AUTO_TEST_SUITE_END()
