#include "com_bentzn_tech_cppintegration_playground_Calculate.h"
#include "Calculate.cpp"
#include <iostream>

/*
 * Class:     com_baeldung_jni_HelloWorldJNI
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jint JNICALL Java_com_bentzn_tech_cppintegration_playground_Calculate_calculate(JNIEnv *env, jobject thisObject)
{
  jint n = calculatePythagoras();
  return n;
}
