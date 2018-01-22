package com.ysrc.antiva;

/**
 * Created by qtfreet00 on 2018/1/22.
 */

public class JniHelper {

    static {
        System.loadLibrary("antiva");
    }

    public native static boolean isRunInVa();
}
