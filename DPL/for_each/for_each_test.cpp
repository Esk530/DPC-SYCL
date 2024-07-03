#include <iostream>
#include <vector>
#include <oneapi/dpl/algorithm>
#include <oneapi/dpl/tuple>
#include <oneapi/dpl/iterator>

int for_each_test1();


int main()
{
	std::vector<float> A(100, 1);
	std::vector<float> B(100, 2);
	std::vector<float> C(100, 2);

	auto begin = oneapi::dpl::make_zip_iterator(A.begin(), B.begin(), C.begin());
	auto end   = oneapi::dpl::make_zip_iterator(A.end(), B.end(), C.end());

	// 書き換えができるかの確認
	oneapi::dpl::for_each(begin, end, [](auto t) {// & をいれちゃだめ！
		auto [a, b, c] = t;
		a = 20;
		b = 40;
		c = 30;
	});

	// 出力の確認
	oneapi::dpl::for_each(begin, end, [](auto t) {// & をいれちゃだめ！
		auto [a, b, c] = t;
		std::cout << "(a,b,c) = (" << a << "," << b << "," << c << ")" << std::endl;
		});


}

/**
* @brief for_each のテスト
*/
int for_each_test1()
{
	const int N = 1000;
	std::vector<float> A(N);
	oneapi::dpl::for_each(A.begin(), A.end(), [](float& v) {v = 10.f; });
	oneapi::dpl::for_each(A.begin(), A.end(), [](const float& v) {std::cout << v << std::endl; });
}


