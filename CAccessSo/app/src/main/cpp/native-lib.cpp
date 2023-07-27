#include <jni.h>
#include <string>

extern std::string helloWorldFun();
extern unsigned char* Init(int width, int height);
extern void InputXY(int x, int y);

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_caccessso_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    return env->NewStringUTF(helloWorldFun().c_str());
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}