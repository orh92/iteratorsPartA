/**
 * A demo program for itertools.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

#include <typeinfo>
#include <iostream>
#include <string>
#include "product.hpp"
#include "powerset.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "badkan.hpp"
#define COMMA ,
using std::string;
using namespace std;
using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

//range tests
		//test int range
		string intRange = "";
		for (int i : range(1, 5)) {
			intRange += to_string(i);
		}
		//end int test 

				//test double range
		string doubleRange = "";
		for (double i : range(1.1, 5.1)) {
			doubleRange += to_string(i);
		}
		string doubleans = "1.1000002.1000003.1000004.100000";
		//end double test

		//chars range test
		string charsRange = "";
		string charsAns = "abcd";
		for (char i : range('a', 'e')) {
			charsRange += i;
		}
		//end chars range test


		//string range test
		string strRange = "";
		string strAns = "helloworld";
		for (char i : string("helloworld")) {
			strRange += i;
		}
		//end string range test
//end range tests



//chain tests
		//int chain test
		string intChain = "";
		string intChainAns = "123789";
		for (int i : chain(range(1, 4), range(7, 10))) {
			intChain += to_string(i);
		}
		//end int chain


		//char and string chain
		string charChain = "";
		string charChainAns = "abcdhello";
		for (char i : chain(range('a', 'e'), string("hello"))) { charChain += i; }
		//end char and string chain
//end chain tests



//zip tests

		//int  and string zip
		string intStringZip = "";
		string intStringZipAns = "1h2e3l4l5o";
		//12345		//hello
		for (auto pair : zip(range(1, 6), string("hello"))) {
			int a = 0;
			string st = "";
			if (typeid(a) == typeid(pair)) { intStringZip += to_string(pair.first);}
			if (typeid(st) == typeid(pair)) {  intStringZip += pair.second;}
			
		}

		//char , char zip
		string charStringZip = "";
		string charStringZipAns = "ambncodpeqfr";
		//abcdef	//mnopqr
		for (auto pair : zip(range('a', 'g'), range('m', 's'))) {
			int a = 0;
			string st = "";
			if (typeid(a) == typeid(pair)) { charStringZip += to_string(pair.first);}
			if (typeid(st) == typeid(pair)) {  charStringZip += pair.second;}
		}

//end zip tests


//product tests
		//double , string product
		string intStringProduct = "";
		string intStringProductAns = "1c1p1p2c2p2p";
		for (auto pair : product(range(1, 3), string("cpp"))) {
			int a = 0;
			string st = "";
			bool flag = true;
			if (typeid(a) == typeid(pair)) { flag = true; }
			if (typeid(st) == typeid(pair)) { flag = false; }
			if (flag == true) {
				intStringProduct += to_string(pair.first);
			}
			else { intStringProduct += pair.second; }
		}

		string intcharProduct = "";
		string intcharProductAns = "9e9f9g10e10f10g11e11f11g";
						//9,12		//efg
		for (auto pair : product(range(9, 12), range('e','h'))) {

			int a ;
			char c;
			bool flag = true;
			if (typeid(a) == typeid(pair)) { flag = true; }
			if (typeid(c) == typeid(pair)) { flag = false; }
			if (flag == true) {
				intcharProduct += to_string(pair.first);
			}
			else { intcharProduct += pair.second; }
			}

//end product tests



//powerset tests
/*
		//int set powerset
		string intPowerSet = "";
		string intPowerSetAns = "{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}";
		for (auto subset : powerset(range(1, 4))) {
			intPowerSet += to_string(subset);
		}


		//char char powerset
		string charcharPowerSet = "";
		string charcharPowerSetAns = "{}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y}";
		for (auto subset : powerset(chain(range('a', 'c'), range('x', 'z')))){charcharPowerSet+=subset;}
		*/	 
//end powerset tests




	//@@TESTS
		testcase.setname("iterators")

			//range tests
			.CHECK_EQUAL(intRange, to_string(1234))//check int range
			.CHECK_EQUAL(doubleRange, doubleans)//check double range(for now its casting to int)
			.CHECK_EQUAL(charsRange, charsAns)//chars check of range
			.CHECK_EQUAL(strRange, strAns)//string check 		

			//chain tests
			.CHECK_EQUAL(intChain, intChainAns)//check chain (range int ,range int)
			.CHECK_EQUAL(charChain, charChainAns)//check chain (range char and string)


			//zip tests
			.CHECK_EQUAL(intStringZip, intStringZipAns)//(range int and string) zip test
			.CHECK_EQUAL(charStringZip, charStringZipAns)//(range char , range char) zip test

			//product tests
			.CHECK_EQUAL(intStringProduct, intStringProductAns)// (range 123 ,  string cpp) product
			.CHECK_EQUAL(intcharProduct, intcharProductAns)//range1,3 char e,h product

			//powerset tests
			//.CHECK_EQUAL(intPowerSet, intPowerSetAns) //range(1,4) powerset
			//.CHECK_EQUAL(charcharPowerSet, charcharPowerSetAns) //char a,c ~ char x,z powerset




			;//end TESTS

		grade = testcase.grade();
	}
	else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	return 0;
}
