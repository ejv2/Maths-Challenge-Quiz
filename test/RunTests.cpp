/* Maths challenge quiz
   Copyright Ethan Marshall - 2019

   Licensed under the GPL V.3.0
*/

/*
	MATHS CHALLENGE QUIZ - Testing System
	=====================================

	This file contains the testing system used by MCQ.

	The testing system used is called "catch2" (located in catch.h) and is
   licensed under the Boost Software Licence (copy enclosed in
   Catch2_Licence.txt).

	- To build the test script, run `make build`.
	- To build and run the test script, run `make run`.
	- To build and run the test script and then clean up the results, run `make
   test`

	The testing executable will be generated in the build folder.
*/

// Include and configure catch
#define CATCH_CONFIG_MAIN
#include "catch2/catch.h"

#include <tuple>
#include <vector>

#include "include/Constants.h"
#include "include/Scoring.h"
#include "include/Util.h"

#include "include/round/Round.h"
#include "include/round/RoundUtils.h"

#define TEST_PRACTICE_ACCEPTANCE_STRING                                        \
	"I accept my non-genuine, training result"
#define TEST_REGULAR_ACCEPTANCE_STRING "I accept my result"

#define TEST_BASE_ACCEPTANCE_PROMPT_0 "Please enter '"
#define TEST_BASE_ACCEPTANCE_PROMPT_1 "' to continue:"
#define TEST_SECONDARY_ACCEPTANCE_PROMPT_0 "Just enter '"
#define TEST_SECONDARY_ACCEPTANCE_PROMPT_1                                     \
	"' already, I won't exit until you do:"
#define TEST_TERTIARY_ACCEPTANCE_PROMPT_0 "I'm bored, enter '"
#define TEST_TERTIARY_ACCEPTANCE_PROMPT_1 "' or I might just give up:"

#define TEST_UPPERCASE "TEST"
#define TEST_MIXED "TeSt"
#define TEST_EMPTY_STRING ""
#define TEST_LOWERCASE "test"

#define TEST_VALID_NUMBER "5"
#define TEST_INVALID_NUMBER "test"
#define TEST_FLOAT_NUMBER "5.5"

#define RNG_SEQUENCE_CAP 10

// Version checks
#if CATCH_VERSION_MAJOR < 2
#error "MCQ Requires catch V.2 or later"
#endif

// ==================== [BEGIN TESTS] ====================
TEST_CASE("Acceptance string", "[scoring]") {
	SECTION("Correct acceptance string for training") {
		REQUIRE(scoring::getAcceptanceString(-5) ==
				TEST_PRACTICE_ACCEPTANCE_STRING);
	}

	SECTION("Correct acceptance string for regular game") {
		REQUIRE(scoring::getAcceptanceString(1) ==
				TEST_REGULAR_ACCEPTANCE_STRING);
	}
}

TEST_CASE("Prompt string", "[scoring]") {
	SECTION("Correct prompt string when attempts <5") {
		std::tuple<std::string, std::string> promptString =
			scoring::getPromptString(0);

		CHECK(std::get<0>(promptString) == TEST_BASE_ACCEPTANCE_PROMPT_0);
		CHECK(std::get<1>(promptString) == TEST_BASE_ACCEPTANCE_PROMPT_1);
	}

	SECTION("Correct prompt string when attempts <10 but >5") {
		std::tuple<std::string, std::string> promptString =
			scoring::getPromptString(6);

		CHECK(std::get<0>(promptString) == TEST_SECONDARY_ACCEPTANCE_PROMPT_0);
		CHECK(std::get<1>(promptString) == TEST_SECONDARY_ACCEPTANCE_PROMPT_1);
	}

	SECTION("Correct prompt string when attempts >10") {
		std::tuple<std::string, std::string> promptString =
			scoring::getPromptString(11);

		CHECK(std::get<0>(promptString) == TEST_TERTIARY_ACCEPTANCE_PROMPT_0);
		CHECK(std::get<1>(promptString) == TEST_TERTIARY_ACCEPTANCE_PROMPT_1);
	}
}

TEST_CASE("Final result", "[scoring]") {
	SECTION("Result is classified as 'Awful' if no points were scored") {
		REQUIRE(scoring::getFinalResult(0, 0) == scoring::OverallResult::awful);
	}

	SECTION(
		"Result is classified as 'Perfect' if a perfect score is achieved") {
		REQUIRE(scoring::getFinalResult(1, 1) ==
				scoring::OverallResult::perfect);
	}

	SECTION(
		"A negative score is handled correctly and is recognised as 'Awful'") {
		REQUIRE(scoring::getFinalResult(-100, 1) ==
				scoring::OverallResult::awful);
	}
}

TEST_CASE("String to lower", "[util]") {
	SECTION("An upper case string is successfully transformed to a lower case "
			"one") {
		std::string string = TEST_UPPERCASE;
		util::stringLower(&string);
		REQUIRE(string == TEST_LOWERCASE);
	}

	SECTION(
		"A mixed case string is successfully transformed to a lower case one") {
		std::string string = TEST_MIXED;
		util::stringLower(&string);
		REQUIRE(string == TEST_LOWERCASE);
	}

	SECTION("A lower case string is unaffected by the to lower function") {
		std::string string = TEST_LOWERCASE;
		util::stringLower(&string);
		REQUIRE(string == TEST_LOWERCASE);
	}

	SECTION("An empty string is handled correctly") {
		std::string string = TEST_EMPTY_STRING;
		util::stringLower(&string);
		REQUIRE(string == TEST_EMPTY_STRING);
	}
}

TEST_CASE("Number validation", "[util]") {
	SECTION("A valid number is detected correctly") {
		REQUIRE(util::isValidNumber(TEST_VALID_NUMBER));
	}

	SECTION("An invalid number is detected correctly") {
		REQUIRE(!util::isValidNumber(TEST_INVALID_NUMBER));
	}

	SECTION("A number containing a floating point is handled correctly") {
		REQUIRE(util::isValidNumber(TEST_FLOAT_NUMBER));
	}
}

TEST_CASE("Random seeding and RNG", "[util]") {
	SECTION("RNG can be seeded multiple times") {
		util::setupRandomSeed();

		REQUIRE_NOTHROW(util::setupRandomSeed());
	}

	SECTION("RNG will not give the same sequence when seeded different times") {
		util::setupRandomSeed();
		std::vector<int> origSequence;
		for (int i = 0; i < RNG_SEQUENCE_CAP; i++) {
			origSequence.push_back(std::rand());
		}

		util::sleep(1); /* Sleep to ensure that the system time value will be
						   different */

		util::setupRandomSeed();
		std::vector<int> newSequence;
		for (int i = 0; i < RNG_SEQUENCE_CAP; i++) {
			newSequence.push_back(std::rand());
		}

		bool equal = std::equal(origSequence.begin(), origSequence.end(),
								newSequence.begin());
		REQUIRE(!equal);
	}
}
// ====================  [END TESTS]  ====================
