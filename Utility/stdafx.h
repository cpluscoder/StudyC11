// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  从 Windows 头文件中排除极少使用的信息



// TODO: 在此处引用程序需要的其他头文件
#include <Windows.h>

//禁用宏定义重复警报
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4005)
#include <intsafe.h>	//warning C4005: “UINT32_MAX”: 宏重定义
#include <stdint.h>
#pragma warning (pop)
#endif

/// http://www.cppstdlib.com/code/toc.html
/// http://www.cppstdlib.com/code/idx.html


