﻿/*-----------------------------------------------------------------------------------------
**
** 版权(Copyright): Inory, 2022~
**
** 文件名(File Name): kernelInterface.h
**
** 描述(Description): 本文件定义Status接口,对状态操作进行接口定义
**                      定义Event接口,对事件操作进行接口定义
**                      定义Context接口,对应用程序的运行环境进行接口定义
**                      定义Processor类,该类为模块处理器基类
**
** 设计注记(Design Annotation):
**
** 作者(Author):
**		Inory, 2022年7月23日开始编写本文件
**
** 更改历史(Modification History):
**		Inory, 2022年7月23日 创建本文件
**		$Revision$
**		$Date$
**		$Author$
**		$Log$
**
**-----------------------------------------------------------------------------------------
*/
#ifndef KERNELINTERFACE_H
#define KERNELINTERFACE_H

/*-----------------------------------------------------------------------------------------
**										   Include
**-----------------------------------------------------------------------------------------
*/
#include "global.h"
#include <string>
#include <functional>
#include <list>

using std::string;
using std::function;
using std::list;
using std::bad_alloc;

/*-----------------------------------------------------------------------------------------
**									   Macro Definition
**-----------------------------------------------------------------------------------------
*/
/* 事件ID等宏定义 */
#define EVENT_ID_MODULE_MIN         (0)         /* 模块间事件标识最小值 */
#define EVENT_ID_MODULE_MAX         (59999)     /* 模块间事件标识最大值 */
#define EVENT_ID_MODULE_NUM_MAX     (60000)     /* 模块间事件个数最大值 */
/* 时钟事件:60000-60063 */
#define EVENT_ID_CLOCK_MIN          (60000)     /* 时钟事件标识最小值 */
#define EVENT_ID_CLOCK_MAX          (60063)     /* 时钟事件标识最大值 */
#define EVENT_ID_CLOCK_10MS         (60000)     /* 10ms定时事件标识 */
#define EVENT_ID_CLOCK_20MS         (60001)     /* 20ms定时事件标识 */
#define EVENT_ID_CLOCK_30MS         (60002)     /* 30ms定时事件标识 */
#define EVENT_ID_CLOCK_40MS         (60003)     /* 40ms定时事件标识 */
#define EVENT_ID_CLOCK_50MS         (60004)     /* 50ms定时事件标识 */
#define EVENT_ID_CLOCK_100MS        (60005)     /* 100ms定时事件标识 */
#define EVENT_ID_CLOCK_200MS        (60006)     /* 200ms定时事件标识 */
#define EVENT_ID_CLOCK_500MS        (60007)     /* 500ms定时事件标识 */
#define EVENT_ID_CLOCK_1S           (60008)     /* 1s定时事件标识 */
/* 状态同步事件:60064-60127 */
#define EVENT_ID_STATUS_MIN         (60064)     /* 状态同步事件标识最小值 */
#define EVENT_ID_STATUS_MAX         (60127)     /* 状态同步事件标识最大值 */
/* 系统控制事件:60128-60255 */
#define EVENT_ID_CONTROL_MIN        (60128)     /* 系统控制事件标识最小值 */
#define EVENT_ID_CONTROL_MAX        (60255)     /* 系统控制事件标识最大值 */
#define EVENT_ID_CONTROL_EXIT       (60128)     /* 程序退出事件标识 */
/* 备用:60256-65534 */
#define EVENT_ID_MIN                (0)         /* 事件ID最小值 */
#define EVENT_ID_MAX                (65534)     /* 事件ID最大值 */
#define EVENT_ID_NUM_MAX            U16_MAX     /* 事件ID个数最大值 */
/* 无效事件标识 */
#define EVENT_ID_INVALID            U16_MAX
/* 事件消息最大长度 */
#define EVENT_MSG_SIZE_MAX          (65536)

/* 状态宏定义 */
/* 无效状态 */
#define STATUS_INVALID              I32_MAX

/* 模块数最大值 */
#define MODULE_NUM_MAX              256

/* 日志宏定义 */
/* 日志信息最大长度 */
#define LOG_INFO_SIZE               256
/* 记录日志 */
#define LOGF(...)                   {char errStr[LOG_INFO_SIZE] = {0}; sprintf(errStr, __VA_ARGS__); _context->log(errStr); }

/*-----------------------------------------------------------------------------------------
**									   Type Definition
**-----------------------------------------------------------------------------------------
*/
/* function类型定义 */
/* 命令行函数类型 */
typedef function<void(int argc, char* argv[])> CmdHandler;

/*-----------------------------------------------------------------------------------------
**									   Class Definition
**-----------------------------------------------------------------------------------------
*/
/* <类描述> */
/* 1)事件操作接口 */
/* 2) */
class Event
{
public:
    /* 获取事件标识 */
    virtual unsigned int id() = 0;
    /* 获取事件消息指针 */
    virtual const unsigned char* message() = 0;
    /* 获取事件消息长度 */
    virtual unsigned int messageLength() = 0;
    /* 判断是否为模块间事件 */
    virtual bool isModuleEvent() = 0;
    /* 判断是否为时钟事件 */
    virtual bool isClockEvent() = 0;
    /* 判断是否为系统控制事件 */
    virtual bool isControlEvent() = 0;
};

#endif /* KERNELINTERFACE_H */