#include <iostream>
#include <cstddef>
#include <Windows.h>

void DisplayCharAt(std::size_t row, std::size_t column, char c)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos{ .X = static_cast<SHORT>(column), .Y = static_cast<SHORT>(row) };
	SetConsoleCursorPosition(h, pos);
	std::cout << c;
}