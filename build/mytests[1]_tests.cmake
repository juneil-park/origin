add_test( GetNumberOfRowTest.Matrix /home/gnc/PracticeGtest/build/mytests [==[--gtest_filter=GetNumberOfRowTest.Matrix]==] --gtest_also_run_disabled_tests)
set_tests_properties( GetNumberOfRowTest.Matrix PROPERTIES WORKING_DIRECTORY /home/gnc/PracticeGtest/build)
add_test( AddMatricesTest.Matrix /home/gnc/PracticeGtest/build/mytests [==[--gtest_filter=AddMatricesTest.Matrix]==] --gtest_also_run_disabled_tests)
set_tests_properties( AddMatricesTest.Matrix PROPERTIES WORKING_DIRECTORY /home/gnc/PracticeGtest/build)
add_test( MultiplyMatricesTest.Matrix /home/gnc/PracticeGtest/build/mytests [==[--gtest_filter=MultiplyMatricesTest.Matrix]==] --gtest_also_run_disabled_tests)
set_tests_properties( MultiplyMatricesTest.Matrix PROPERTIES WORKING_DIRECTORY /home/gnc/PracticeGtest/build)
set( mytests_TESTS GetNumberOfRowTest.Matrix AddMatricesTest.Matrix MultiplyMatricesTest.Matrix)