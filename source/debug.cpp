#include "debug.hpp"

#include <3ds.h>

#define TICKS_PER_SEC 268123480.0

u64 tickStart = 0;
u64 tickEnd = 0;

void CitraPrint(std::string_view str) {
   svcOutputDebugString(str.data(), str.length());
}

// Functions used to time how long sections of code take to run
void StartTiming() {
  tickStart = svcGetSystemTick();
}

void EndTiming() {
  tickEnd = svcGetSystemTick();
}

void PrintTiming(std::string label) {
  double time = (tickEnd - tickStart)/TICKS_PER_SEC;
  auto m = label + ": " + std::to_string(time);
  CitraPrint(m);
}
