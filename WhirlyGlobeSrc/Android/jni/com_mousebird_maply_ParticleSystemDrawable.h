/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_mousebird_maply_ParticleSystemDrawable */

#ifndef _Included_com_mousebird_maply_ParticleSystemDrawable
#define _Included_com_mousebird_maply_ParticleSystemDrawable
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    getLocalMbr
 * Signature: ()Lcom/mousebird/maply/Mbr;
 */
JNIEXPORT jobject JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_getLocalMbr
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    getDrawPriority
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_getDrawPriority
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setDrawPriority
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setDrawPriority
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    getProgram
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_getProgram
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setProgram
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setProgram
  (JNIEnv *, jobject, jlong);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    isOn
 * Signature: (Lcom/mousebird/maply/RendererFrameInfo;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_isOn
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setOnOff
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setOnOff
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setBaseTime
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setBaseTime
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setPointSize
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setPointSize
  (JNIEnv *, jobject, jfloat);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setLifeTime
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setLifeTime
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    getLifeTime
 * Signature: ()D
 */
JNIEXPORT jdouble JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_getLifeTime
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setTexIDs
 * Signature: (Ljava/util/List;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setTexIDs
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setupGL
 * Signature: (Lcom/mousebird/maply/WhirlyKitGLSetupInfo;Lcom/mousebird/maply/OpenGLMemManager;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setupGL
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    teardownGL
 * Signature: (Lcom/mousebird/maply/OpenGLMemManager;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_teardownGL
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    draw
 * Signature: (Lcom/mousebird/maply/RendererFrameInfo;Lcom/mousebird/maply/Scene;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_draw
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    updateRenderer
 * Signature: (Lcom/mousebird/maply/SceneRendererES;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_updateRenderer
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    getRequestZBuffer
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_getRequestZBuffer
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setRequestZBuffer
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setRequestZBuffer
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    getWriteZbuffer
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_getWriteZbuffer
  (JNIEnv *, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    setWriteZbuffer
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_setWriteZbuffer
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    addAttributeData
 * Signature: (Ljava/util/List;Lcom/mousebird/maply/Batch;)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_addAttributeData
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    findEmptyBatch
 * Signature: (Lcom/mousebird/maply/Batch;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_findEmptyBatch
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    updateBatches
 * Signature: (D)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_updateBatches
  (JNIEnv *, jobject, jdouble);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    nativeInit
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_nativeInit
  (JNIEnv *, jclass);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    initialize
 * Signature: (Ljava/lang/String;Ljava/util/Vector;IIZZ)V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_initialize
  (JNIEnv *, jobject, jstring, jobject, jint, jint, jboolean, jboolean);

/*
 * Class:     com_mousebird_maply_ParticleSystemDrawable
 * Method:    dispose
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_mousebird_maply_ParticleSystemDrawable_dispose
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif