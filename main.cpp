//#include <stdexcept>
//struct foo {
//    int val_;

//    operator int() const;
//    bool is_not_null() const;
//    void throws() const; // throws(std::logic_error)
//};



//#define BOOST_TEST_MODULE test_module_name
//#include <boost/test/unit_test.hpp>

//BOOST_AUTO_TEST_CASE(test_no_1) {
//    foo f1 = {1}, f2 = {2};
//    BOOST_CHECK(f1.is_not_null());

//    BOOST_CHECK_NE(f1, f2);

//    BOOST_CHECK_THROW(f1.throws(), std::logic_error);
//} // BOOST_AUTO_TEST_CASE(test_no_1)

//BOOST_AUTO_TEST_CASE(test_no_2) {
//    foo f1 = {1}, f2 = {2};
//    BOOST_REQUIRE_NE(f1, f2);
//    // ...
//} // BOOST_AUTO_TEST_CASE(test_no_2)

//#define DO_NOT_FAIL
//#ifdef DO_NOT_FAIL
//foo::operator int() const {
//    return val_;
//}

//bool foo::is_not_null() const {
//    return !!val_;
//}

//void foo::throws() const {
//    throw std::logic_error("Expected exception");
//}

//#else

//foo::operator int() const {
//    return 0;
//}

//bool foo::is_not_null() const {
//    return !val_;
//}

//void foo::throws() const {}

//#endif // DO_NOT_FAIL

#define BOOST_TEST_MODULE boost_test_macro2
#include <boost/test/included/unit_test.hpp>
#include <iostream>

static int foo(int a,int b){
    std::cout << "foo a: " << a << " , b: " << b << std::endl;
    return a-b;
}

static void throw_exception_(){
    throw std::runtime_error("throw_exception_");
}

BOOST_AUTO_TEST_CASE( test_op_precedence )
{
  int a = 13, b = 2, c = 12;
//  // left term of == is expanded in the logs
//  BOOST_TEST(a % b == c);
//  // right term of == is not expanded in the logs
//  BOOST_TEST(a == c % b);

  BOOST_TEST(foo(5, 4) > 0);

  BOOST_CHECK(foo(5, 4) > 0);

  BOOST_REQUIRE(foo(5, 4) > 0);
}

BOOST_AUTO_TEST_CASE( test_op_right_associative )
{
  int a = 1;
  BOOST_TEST(a);

  BOOST_CHECK_THROW(throw_exception_(), std::runtime_error);
//  BOOST_TEST(!a);
//  BOOST_TEST(--a);
}
