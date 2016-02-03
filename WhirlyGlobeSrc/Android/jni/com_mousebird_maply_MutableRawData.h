/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_mousebird_maply_MutableRawData */

#ifndef _Included_com_mousebird_maply_MutableRawData
#define _Included_com_mousebird_maply_MutableRawData
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    getRawData
 * Signature: ()C
 */
JNIEXPORT jchar JNICALL Java_com_mousebird_maply_MutableRawData_getRawData
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    getLen
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_mousebird_maply_MutableRawData_getLen
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    addInt
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MutableRawData_addInt
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    addDouble
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MutableRawData_addDouble
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    addString
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MutableRawData_addString
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MutableRawData_nativeInit
  (JNIEnv *, jclass);

/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    initialise
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MutableRawData_initialise__
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    initialise
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MutableRawData_initialise__I
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_mousebird_maply_MutableRawData
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_MutableRawData_dispose
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif