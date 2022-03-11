#pragma once

#include <string_view>
#include <string>

void CitraPrint(std::string_view str);
void StartTiming();
void EndTiming();
void PrintTiming(std::string label);
