package com.ysrc.antiva;

import android.app.ActivityManager;
import android.content.Context;
import android.os.Process;
import android.text.TextUtils;

import java.util.List;

/**
 * Created by qtfreet00 on 2018/1/22.
 */

public class AntiVA {
    public static boolean isRunInVa(Context cxt) {
        if (cxt == null) {
            throw new IllegalArgumentException("context must be notnull");
        }
        int pid = Process.myPid();
        String process = getProcessName(cxt, pid);
        if (TextUtils.isEmpty(process)) {
            throw new RuntimeException("get process name failed");
        }
        String pkg = cxt.getPackageName();
        if (TextUtils.isEmpty(pkg)) {
            throw new RuntimeException("get package name failed");
        }
        return pkg.equals(process) && AntiVaNative.isRunInVa() > 0;
    }

    /**
     * 过滤当前非主进程的进程
     *
     * @param cxt
     * @param pid
     * @return
     */
    private static String getProcessName(Context cxt, int pid) {
        try {
            ActivityManager am = (ActivityManager) cxt.getSystemService(Context.ACTIVITY_SERVICE);
            List<ActivityManager.RunningAppProcessInfo> runningApps = am.getRunningAppProcesses();
            if (runningApps != null && !runningApps.isEmpty()) {
                for (ActivityManager.RunningAppProcessInfo procInfo : runningApps) {
                    if (procInfo.pid == pid) {
                        return procInfo.processName;
                    }
                }
            }
        } catch (Exception ignored) {
        }
        return null;
    }
}
