
#pragma once
#include <vector>

#include "core/Context/Context.h"

#ifdef _WIN32
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>

#endif

#ifdef linux
    // No support
#endif

namespace MLP {

    class __mlp64
    {
        private:
            std::vector<unsigned int> offsets;
            unsigned __int64  dataType;
            Context* context;

        public:
            __mlp64(
                std::vector<unsigned int> offsets,
                unsigned __int64 dataType,
                Context* context
                );


        private:
            unsigned __int64 obtain_dynamic_address();      

            void base_address_of_module(
                TCHAR* lpszModuleName
                );

        public:
            // gets as parameter the address size in bytes
            void get_as(
                unsigned __int64 size_bytes
                );

        };


    /*namespace datatype {

        // byte size used by default for an integer
        int Int = sizeof(int); 
        int Int4 = 4;
        int Int8 = 8;

        // byte size used by default a float
        int Float = sizeof(float);  
        
        // byte size used by default for a double
        int Double = sizeof(double);  
    }*/
}

