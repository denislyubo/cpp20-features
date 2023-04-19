#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <format>
#include <random>
#include <thread>
#include <atomic>

using namespace::std::literals;

int main()
{
	std::array<int, 1000> values;
	std::fill_n(values.begin(), values.size(), 100);

	std::stop_source allStopSource;
	std::stop_token allStopToken{ allStopSource.get_token() };

	std::vector<std::jthread> threads;
	for (int i = 0; i < 9; ++i)	{
		threads.push_back(std::jthread{ [&values](std::stop_token st) {
					std::mt19937 eng{std::random_device{}()};
					std::uniform_int_distribution distr{ 0, int(values.size() - 1) };

					while (!st.stop_requested()) {
						int idx = distr(eng);

						std::atomic_ref val{ values[idx] };

						--val;
						if (val <= 0) {
							std::cout << std::format("index {} is zero\n", idx);
						}
					}
				},
				allStopToken
			}
		);

	}

	std::this_thread::sleep_for(0.5s);
	std::cout << "\nSTOP\n";
	allStopSource.request_stop();


	return 0;
}