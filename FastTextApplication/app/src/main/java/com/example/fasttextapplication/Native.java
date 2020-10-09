package com.example.fasttextapplication;

public class Native {
    static {

        System.loadLibrary("core");
    }
    public static native long nativeInit(String modelName);

    public static native void nativeLoadmodel(String path);

    public static native int nativePredictProcess(String text,int topk, float threshold);
}
