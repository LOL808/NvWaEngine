////
////  Logger.h
////  NvWaEngine
////
////  Created by /help on 10/24/16.
////  Copyright © 2016 /help. All rights reserved.
////
//
//#ifndef _NVWA_ENGINE_UTILS_LOGGER_
//#define _NVWA_ENGINE_UTILS_LOGGER_
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <stdarg.h>
//#include <iostream>
//using namespace std;
//
//#define MAX_LOG_LENGTH 2048
//
//void _log(const char *format, va_list args)
//{
//    int bufferSize = MAX_LOG_LENGTH;
//    char* buf = nullptr;
//
//    do
//    {
//        buf = new (std::nothrow) char[bufferSize];
//        if (buf == nullptr)
//            return; // not enough memory
//
//        int ret = vsnprintf(buf, bufferSize - 3, format, args);
//        if (ret < 0)
//        {
//            bufferSize *= 2;
//
//            delete [] buf;
//        }
//        else
//            break;
//
//    } while (true);
//
//    strcat(buf, "\n");
//
//#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
////    __android_log_print(ANDROID_LOG_DEBUG, "cocos2d-x debug info", "%s", buf);
//
//#elif CC_TARGET_PLATFORM ==  CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
//
//    int pos = 0;
//    int len = strlen(buf);
//    char tempBuf[MAX_LOG_LENGTH + 1] = { 0 };
//    WCHAR wszBuf[MAX_LOG_LENGTH + 1] = { 0 };
//
//    do
//    {
//        std::copy(buf + pos, buf + pos + MAX_LOG_LENGTH, tempBuf);
//
//        tempBuf[MAX_LOG_LENGTH] = 0;
//
//        MultiByteToWideChar(CP_UTF8, 0, tempBuf, -1, wszBuf, sizeof(wszBuf));
//        OutputDebugStringW(wszBuf);
//        WideCharToMultiByte(CP_ACP, 0, wszBuf, -1, tempBuf, sizeof(tempBuf), nullptr, FALSE);
//        printf("%s", tempBuf);
//
//        pos += MAX_LOG_LENGTH;
//
//    } while (pos < len);
//    SendLogToWindow(buf);
//    fflush(stdout);
//#else
//    // Linux, Mac, iOS, etc
//    fprintf(stdout, "%s", buf);
//    fflush(stdout);
//#endif
//
////    Director::getInstance()->getConsole()->log(buf);
//    delete [] buf;
//}
//
//void log(const char * format, ...)
//{
//    va_list args;
//    va_start(args, format);
//    _log(format, args);
//    va_end(args);
//}
//
//#define BASICLOGGER(format, ... ) log(format, ##VA_ARGS)
//
//
//
//#endif /* _NVWA_ENGINE_UTILS_LOGGER_ */
