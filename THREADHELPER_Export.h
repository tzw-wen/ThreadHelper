/*
 * Copyright 2015 ZHIHUI WEN (tzw.wen@gmail.com)

 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef WINDOWS
    #ifndef THREADHELPER_LIBRARY_STATIC

    #include "THREADHELPER_ExportDef.cpp"
    #include "THREADHELPER_ExportDef.h"

    #pragma warning( disable: 4251 )
    #pragma warning( disable: 4275 )
    //
    #ifdef class
    #undef class
    #endif
    #define class class THREADHELPER_DLLAPI
    //
    #ifdef struct
    #undef struct
    #endif
    #define struct struct THREADHELPER_DLLAPI
    //
    #ifdef extern
    #undef extern
    #endif
    #define extern extern THREADHELPER_DLLAPI

    #endif//!THREADHELPER_LIBRARY_STATIC
#endif //!WINDOWS
