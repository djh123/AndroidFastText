//
// Created by djh on 20-9-24.
//

#include <jni.h>
#include<android/log.h>
#include<PredictTool.h>
#define LOG_TAG  "android_jni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
PredictTool tool;
#include <stdio.h>
extern "C" JNIEXPORT jlong JNICALL
Java_com_example_fasttextapplication_Native_nativeInit(JNIEnv *env, jclass type, jstring modelName_) {

    LOGI("nativeInit");
    return 0;
}


//extern "C" JNIEXPORT jlong JNICALL
//Java_com_example_fasttextapplication_Native_nativeLoadmodel(JNIEnv *env, jclass type, jstring modelName_) {
//
//    LOGI("loadmodel");
//    //先把debug的问题解决好，环境的问题。
////    std::ifstream ifs("/sdcard/model.bin", std::ifstream::binary);
//
//    //const char *modelName = env->GetStringUTFChars(modelName_, 0);
//    tool.loadModel("/sdcard/model.bin");
//    return 0;
//}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_fasttextapplication_Native_nativeLoadmodel(JNIEnv *env, jclass type,
                                                            jstring path_) {
    const char *path = env->GetStringUTFChars(path_, 0);

    // TODO
//    std::string filename("/sdcard/model.bin");
    std::string filename("/sdcard/modelyule.bin");


//    std::ifstream ifs(filename, std::ifstream::binary);
//    if (!ifs.is_open()) {
//        throw std::invalid_argument(filename + " cannot be opened for loading!");
//    }

    tool.loadModel(filename);

    env->ReleaseStringUTFChars(path_, path);
}

//void printPredictions(
//        const std::vector<std::pair<float , std::string>>& predictions,
//        bool printProb,
//        bool multiline) {
//    bool first = true;
//    for (const auto& prediction : predictions) {
//        if (!first && !multiline) {
//            std::cout << " ";
//        }
//        first = false;
//        std::cout << prediction.second;
//        if (printProb) {
//            std::cout << " " << prediction.first;
//        }
//        if (multiline) {
//            std::cout << std::endl;
//        }
//    }
//    if (!multiline) {
//        std::cout << std::endl;
//    }
//}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_fasttextapplication_Native_nativePredictProcess(JNIEnv *env, jclass type,
                                                                 jstring text_, jint topk,
                                                                 jfloat threshold) {
    const char *text = env->GetStringUTFChars(text_, 0);

    // TODO
    std::string s1 = text;


//    for (int i = 0; i < 50 ; ++i) {
//        s += "李白杜甫李白杜甫杜甫杜甫";
//    }
//    std::string s1("最 近 有 传 说 ， 接 吻 不 仅 护 齿 止 痛 ， 甚 至 还 可 以 减 肥 呢\n");
//    s1+="\n";
    std::vector<std::pair<float, std::string>> predictions = tool.predictProcess(s1, 1, 0.0);

//    const auto& prediction = predictions.begin();
    int isClass = -1;
    for (const auto& prediction : predictions) {
        std::string classpredict = (std::string)prediction.second;

        std::string nvxing = "__label__nvxing1.txt";
        std::string wenxue = "__label__wenxue1.txt";
        std::string xiaoyuan = "__label__xiaoyuan1.txt";
        std::string tiyu = "__label__tiyu1.txt";

        if (strcmp(classpredict.c_str(), nvxing.c_str()) == 0) {
            isClass = 0;
        } else if (strcmp(classpredict.c_str(), wenxue.c_str()) == 0) {
            isClass = 1;
        } else if (strcmp(classpredict.c_str(), xiaoyuan.c_str()) == 0) {
            isClass = 2;
        } else if (strcmp(classpredict.c_str(), tiyu.c_str()) == 0) {
            isClass = 3;
        }
    }
    env->ReleaseStringUTFChars(text_, text);
    return isClass;
}