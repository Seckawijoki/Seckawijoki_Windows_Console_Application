// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <iostream>
extern "C"
{
#include "..\lua51\lauxlib.h"
#include "..\lua51\lua.h"
#include "..\lua51\lualib.h"
}
#include <cstdio>
#include <tchar.h>
using namespace std;
typedef void(*Fun) (void);


// TODO: 在此处引用程序需要的其他头文件
