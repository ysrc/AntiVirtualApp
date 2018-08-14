package com.ysrc.antiva;

/**
 * Created by qtfreet00 on 2018/1/22.
 */

public class AntiVaNative {

    static {
        System.loadLibrary("antiva");
    }

    public native static int isRunInVa();

}
