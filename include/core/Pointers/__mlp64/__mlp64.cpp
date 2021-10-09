#pragma once

#include <iostream>
#include "__mlp64.h"

#ifdef _WIN32
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>

#endif

#ifdef linux
    // No support
#endif

namespace MLP {

    __mlp64::__mlp64(
                std::vector<unsigned int> offsets,
                unsigned __int64  dataType,
                Context* context
                ) : dataType(dataType),  offsets(offsets), context(context)
    {

       // std::cout << "moduleAddress" << context->moduleAddress << std::endl;
    }

    void __mlp64::get_as(unsigned __int64 size_bytes){
    }

    void __mlp64::base_address_of_module(TCHAR* lpszModuleName){
    }
}


