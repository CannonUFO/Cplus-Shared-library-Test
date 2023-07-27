#include <jni.h>
#include <string>

extern std::string helloWorldFun();

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_buildso_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    return env->NewStringUTF(helloWorldFun().c_str());

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}