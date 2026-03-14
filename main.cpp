#include <iostream>
#include <string>
#include <thread>
#include <algorithm>
#include <condition_variable>
#include <stop_token>
#include <cstddef>
#include <conio.h>
#include "ring_buffer.hpp"

void DisplayCharAt(std::size_t, std::size_t, char);

int main()
{
	ring_buffer<char, 30> buffer;
	char c;

	auto displayFunc = [&](std::stop_token st) {
		std::string prevInput;

		while (!st.stop_requested())
		{
			std::string input;
			for (std::size_t i = 0; i < buffer.size(); ++i)
				input.push_back(buffer.get_by_value(i));

			if (input != prevInput)
			{
				const std::size_t iterCount = std::max(input.size(), prevInput.size());
				for (std::size_t i = 0; i < iterCount; ++i)
					DisplayCharAt(0, i, (i < input.size()) ? input[i] : ' ');

				prevInput = std::move(input);
			}
		}
	};

	std::jthread displayThread{ displayFunc };
	while ((c = _getch()) != '.')
		buffer.push(c);
}