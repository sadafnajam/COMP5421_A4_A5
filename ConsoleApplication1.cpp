#include<string>
#include<vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cctype>
#include <set>
#include<map>
#include <locale>

#include "ctype.h"

using std::cout;
using std::endl;

//Function Prototypes
void test_is_palindrome(); // Main funton to test is_plaindrome function

bool is_palindrome(const std::string & phrase); // To check whether given String is palindrome or not that returns boolean

bool check_alpha(char non_alpha); //To check give character is alphabet or not that returns boolean

void test_second_max(std::vector <int > vec); // To find second largets element in the container

template <class Iterator >std::pair < Iterator, bool > second_max(Iterator start, Iterator finish); // Iterator template taking start and finish range  and returning the second largest object

int countStringFreeFun(std::vector <std::string > vecstr, int n); // CountStrings as free function

int countStringLambda(std::vector <std::string > vecstr, int n); // CountStrings as Lambda expression

int countStringFunctor(std::vector <std::string > vecstr, int n); // CountStrings as Functor/function object

bool count_check(const std::string &str, std::string::size_type n); //Count check function

void charFrequency(); // To store and count frequency of each input character

void display_chrset(std::map<char, int> char_set); // Display Function

void multisetUsingMyComparator(); // Multiset using compare function

int group_comp(std::string lhs, std::string rhs); //For comparing ther LHS and RHS

int main() {
	// problem 1:
	test_is_palindrome();
	cout << "\n";

	// problem 2:
	std::vector <int > v1{ 1 }; // one element
	test_second_max(v1);

	std::vector <int > v2{ 1, 1}; // all elements equal
	test_second_max(v2);

	std::vector <int > v3{ 1, 1, 3, 3, 7, 7 }; // at least with two distict elements
	test_second_max(v3);
	cout << "\n";

	// problem 3:
	std::vector <std::string > vecstr
	{ "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
	  "range", "[first", "last)", "for", "which", "pred", "is", "true."
	};
	cout << countStringLambda(vecstr, 3) << endl;
	cout << countStringFreeFun(vecstr, 3) << endl;
	cout << countStringFunctor(vecstr, 3) << endl;
	cout << "\n";

	// problem 4:
	charFrequency();
	cout << "\n";
	// problem 5:

	multisetUsingMyComparator();
	cout << "\n";
	system("pause");
	return 0;
}

// problem 1:
void test_is_palindrome() {
	std::string str_i = std::string("Was it a car or a cat I saw?");
	std::string str_u = std::string("Was it a car or a cat U saw?");
	cout << " the phrase \"" + str_i + "\" is " +
		(is_palindrome(str_i) ? "" : "not ") + "a palindrome \n";
	cout << " the phrase \"" + str_u + "\" is " +
		(is_palindrome(str_u) ? "" : "not ") + "a palindrome \n";
}

bool is_palindrome(const std::string & phrase) {
	std::string temp;
	std::insert_iterator<std::string> ite(temp, temp.begin());
	std::remove_copy_if(phrase.begin(), phrase.end(), ite, check_alpha);
	std::string::iterator sitr = temp.begin();
	transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) {return std::tolower(c); });
	int half = temp.size() / 2;
	advance(sitr, half);
	bool is_palornot = equal(temp.begin(), sitr, temp.rbegin());
	return is_palornot;
}

bool check_alpha(char non_alpha) {
	bool isAlpha = (non_alpha >= 'A' && non_alpha <= 'Z') || (non_alpha >= 'a' && non_alpha <= 'z');
	return !isAlpha;
}



// problem 2:
void test_second_max(std::vector <int > vec) {
	// note : auto in the following statement is deduced as
	// std :: pair <std :: vector <int >:: iterator , bool >
	auto retval = second_max(vec.begin(), vec.end());
	if (retval.second)
	{
		cout << " The second largest element in vec is "
			<< *retval.first << endl;
	}
	else
	{
		if (retval.first == vec.end())
			cout << " List empty, no elements \n";
		else
			cout << " Container elements are all equal to "
			<< *retval.first << endl;
	}
}

template <class Iterator >
std::pair < Iterator, bool >
second_max(Iterator start, Iterator finish) {
	if (start == finish) {
		return make_pair(finish, false);
	}
	auto accum = start, large = start;
	for (auto i = start; i < finish; ++i) {
		if (*accum < *i) {
			large = accum;
			accum = i;
		}
	}
	if (*accum != *large) {
		return make_pair(large, true);
	}
	else {
		return make_pair(start, false);
	}

}


// problem 3:
int countStringLambda(std::vector <std::string > vecstr, int num) {
	int count = 0;
	count = count_if(vecstr.begin(), vecstr.end(), [num](const std::string &str) {
		int str_size = str.size();
		return str_size == num;
	});
	return count;
}

int countStringFreeFun(std::vector <std::string > vecstr, int num) {
	int count = 0;
	auto str_len = std::bind(count_check, std::placeholders::_1, num);
	count = count_if(vecstr.begin(), vecstr.end(), str_len);
	return count;
}

bool count_check(const std::string &str, std::string::size_type num) {
	int str_size = str.size();
	return str_size == num;
}

class countMatch {
private:
	int num;
public:
	countMatch(int n){
		num = n;
	}
	int operator () (const std::string str) const {
		int str_size = str.size();
		return str_size == num;
	}
};

int countStringFunctor(std::vector <std::string > vecstr, int num) {
	int count = 0;
	count = count_if(vecstr.begin(), vecstr.end(), countMatch(num));
	return count;
}


// problem 4:
void charFrequency() {
	cout << "Enter one or more lines of text."<<endl;
	cout << "To end input press Ctrl-Z in Windows and Ctrl-D in Linux"<<endl;
	std::istream_iterator<std::string> eos;
	std::istream_iterator<std::string> iit(std::cin);
	std::map<char, int> freq_count;
	for_each(iit, eos, [&freq_count](std::string str) {
		for_each(str.begin(), str.end(), [&freq_count](char ch) {
			char alpha = std::tolower(ch);
			if (freq_count.find(alpha) == freq_count.end()) {
				std::pair<char, int> temp_pair;
				temp_pair.first = alpha;
				temp_pair.second = 1;
				freq_count.insert(temp_pair);
			}
			else {
				freq_count.find(alpha)->second = freq_count.find(alpha)->second + 1;
			}
		});
	});
	display_chrset(freq_count);
}

void display_chrset(std::map<char, int> char_set) {
	for_each(char_set.begin(), char_set.end(), [](std::pair<char, int> pir) {
		cout << pir.first << " " << pir.second << endl;
	});
}


// problem 5:
void multisetUsingMyComparator() {
	int(*fn_pnt_comp)(std::string, std::string) = group_comp;
	std::multiset <std::string, int(*)(std::string, std::string)> strSet(fn_pnt_comp);
	std::vector <std::string > vec{ "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
	std::copy(vec.begin(), vec.end(), std::inserter(strSet, strSet.begin()));
	std::inserter(strSet, strSet.begin());
	std::ostream_iterator <std::string > out(cout, " ");
	std::copy(strSet.begin(), strSet.end(), out);
}

int group_comp(std::string lhs, std::string rhs) {
	if (rhs.size() > lhs.size() || (rhs > lhs && rhs.size() == lhs.size())) {
		return rhs.size();
	}
	else {
		return 0;
	}
}