# Ring Buffer

A from-scratch thread-safe fixed-capacity ring buffer (circular buffer) written in modern C++.

## Features

- Header-only
- Fixed capacity (template parameter)
- Thread-safe (`std::mutex` + `std::condition_variable`)
- Overwrites oldest data when full
- Blocking pop / front / back

## Example

```cpp
#include "ring_buffer.hpp"

ring_buffer<int, 64> buffer;

buffer.push(42);

int value = buffer.blocking_pop();
```

## API

- `push(value)`
- `blocking_pop()`
- `blocking_front()` / `blocking_back()`
- `get_by_value(index)`
- `empty()` / `full()` / `size()` / `capacity()`
- `clear()`

## Build

```bash
g++ -std=c++20 main.cpp help.cpp -o ring_buffer
```

Note: The demo uses Windows-specific console APIs (`_getch`, `SetConsoleCursorPosition`).
