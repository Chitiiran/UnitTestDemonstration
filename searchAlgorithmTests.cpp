#include "baseCode.cpp"
#include <gtest/gtest.h>
#include <iostream>


class searchAlgoFixture: public ::testing::Test { 
public: 

	SearchAlgorithm sa = SearchAlgorithm();
	Pose2 pose = Pose2(1.0, 2.0, 0.5);
	Problem problem = Problem();
	searchAlgoFixture( ) { 
       // initialization code here
		 sa = SearchAlgorithm();
		 pose = Pose2(1.0, 2.0, 0.5);
		 problem = Problem();
	} 

	void SetUp( ) { 
       // code here will execute just before the test ensues 
	}

	void TearDown( ) { 
       // code here will be called just after the test completes
       // ok to through exceptions from here if need be
	}

	~searchAlgoFixture( )  { 
       // cleanup any pending stuff, but no exceptions allowed
	}

   // put in any custom data members that you need 
}; 

// Testing for reset  
TEST_F(searchAlgoFixture_reset, nullInput) { 
	problem = NULL;
	String expectedError_null = "expectedError_null"
	ASSERT_EQ (expectedError, sa.reset(problem));

	float a = 1.0;
	problem = a;
	String expectedError_invalidInput = "expectedError_invalidInput"
	ASSERT_EQ (expectedError, sa.reset(problem));
}

// Testing for update
TEST_F(searchAlgorithm_update_Test, nullInput) { 
	problem = NULL;
	String expectedError_null = "expectedError_null"
	ASSERT_EQ (expectedError, sa.update(problem));

	float a = 1.0;
	problem = a;
	String expectedError_invalidInput = "expectedError_invalidInput"
	ASSERT_EQ (expectedError, sa.update(problem));
}

// Testing for isSolutionFound
TEST_F(searchAlgorithm_isSolutionFound_Test, outputType) { 
	bool ans = sa.isSolutionFound();
	ASSERT_EQ (TRUE, ans);
	ASSERT_EQ (FALSE, ans);
	*_EQ(nullptr, ans);
}

// Testing for getPlan
TEST_F(searchAlgorithm_getPlan_Test, outputType) { 
	std::vector<Pose2> ans = sa.getPlan();
	ASSERT_EQ (typeid(pose).name(), ans);
	*_EQ(nullptr, ans);
}


// Testing for Plan
TEST(searchAlgorithm_plan_Test, timeCheck) { 
 // implemented in main at program level using ASSERT_LT
}


// Testing for replan
TEST(searchAlgorithm_replan_Test, timeCheck) { 
// implemented in main at program level using ASSERT_LT

}

// Testing for refine
TEST(searchAlgorithm_refine_Test, timeCheck) { 
// implemented in main at program level using ASSERT_LT
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	::testing::internal::TimeInMillis elapsed(
        ::testing::UnitTest::GetInstance()->elapsed_time());
    ASSERT_LT(elapsed, measurePerf ? 180 * 1000 : 215 * 1000);
    return result;
}