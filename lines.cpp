#include <iostream>
#include <cstdint>
#include <random>

int main(int argc, char** argv) {
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0,6);
  auto roll = std::bind ( distribution, generator );

  uint32_t numEdges = 5000;

  std::cout.write(reinterpret_cast<const char*>(&numEdges), sizeof numEdges);

  for(uint32_t i = 0; i < numEdges; i++) {
    float x1 = (float)roll();
    float y1 = (float)roll();
    float z1 = (float)roll();

    float x2 = (float)roll();
    float y2 = (float)roll();
    float z2 = (float)roll();

    std::cout.write(reinterpret_cast<const char*>(&x1), sizeof x1);
    std::cout.write(reinterpret_cast<const char*>(&y1), sizeof y1);
    std::cout.write(reinterpret_cast<const char*>(&z1), sizeof z1);

    std::cout.write(reinterpret_cast<const char*>(&x2), sizeof x2);
    std::cout.write(reinterpret_cast<const char*>(&y2), sizeof y2);
    std::cout.write(reinterpret_cast<const char*>(&z2), sizeof z2);
  }
}
