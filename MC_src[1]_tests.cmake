add_test( StatusTest.statustest [==[/home/gnc/C++_practice/aerospace_cpp_onboarding/MC_src]==] [==[--gtest_filter=StatusTest.statustest]==] --gtest_also_run_disabled_tests)
set_tests_properties( StatusTest.statustest PROPERTIES WORKING_DIRECTORY [==[/home/gnc/C++_practice/aerospace_cpp_onboarding]==])
set( MC_src_TESTS StatusTest.statustest)
