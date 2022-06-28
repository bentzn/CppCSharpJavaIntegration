#include "com_bentzn_tech_cpp_Calculate.h"
#include "Calculate.cpp"
#include <iostream>

JNIEXPORT jint JNICALL Java_com_bentzn_tech_cpp_Calculate_calculate(JNIEnv *env, jobject thisObject)
{
  jint n = calculatePythagoras();
  return n;
}
