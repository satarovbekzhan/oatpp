#include <iostream>
#include <string>

#include <fmt/format.h>
#include <spdlog/spdlog.h>

int main()
{
  const std::string welt = "Welt";
  const auto nachricht = fmt::format("Hallo {}!", welt);
  std::cout << nachricht << std::endl;
  std::cout << nachricht << '\n';
  spdlog::info(nachricht);
}