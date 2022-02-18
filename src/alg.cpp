// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value == 1)
    return false;
  for (int i = 2; i * i <= value; i++)
    if (value % i == 0)
      return false;
  return true;
}

uint64_t nPrime(uint64_t n) {
  int numberPrime = 0, value = 0;
  do {
    value++;
    if (checkPrime(value)) {
      numberPrime++;
    }
  } while (numberPrime < n);
  return value;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  if (checkPrime(value))
    return value;
  return nextPrime(value);
}

uint64_t sumPrime(uint64_t hbound) {
  hbound--;
  if (hbound == 1)
    return 0;
  if (checkPrime(hbound))
    return hbound + sumPrime(hbound);
  return sumPrime(hbound);
}
