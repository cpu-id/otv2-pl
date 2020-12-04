#include "SectionAccessor.hpp"

//Full reconstruction of native IAT section.
//Author: 0x000cb & wzn.
std::map <std::string, std::vector <AdditionalRuntime::ImportDefinition>> SectionAccessor::IAT = {

        //NTDLL.
        { "ntdll",

                {

                    { "RtlInitializeSListHead",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x47889 } } }
                    }

                }

        },

        //KERNEL32.
        { "kernel32",

                {

                        { "CreateFileA",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x1A7D8, 0x6C116, 0xE0F66

                            } },

                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142068

                            } }
                          }
                        },
                        { "FindFirstFileA",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1C2FF, 0x6C1E6, 0xE1036, 0xE2167 } } }
                        },
                        { "FindClose",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1CA4A, 0x6C82D, 0xE167D, 0xE280C } } }
                        },
                        { "FindNextFileA",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1CA3B, 0x6C81A, 0xE166A, 0xE27FD } } }
                        },
                        { "WritePrivateProfileStringA",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x2CE8E, 0x2D1AE, 0x2D4AE, 0x2D93E,
                                0x2DC6E, 0x2E10E, 0x2E41E, 0x2E72E,
                                0x2EA3E, 0xE17F5

                            } }
                          }
                        },
                        { "Sleep",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x34315 } } }
                        },
                        { "GetPrivateProfileStringA",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x2CF65, 0x2D270, 0x2D585, 0x2D702,
                                0x2DA30, 0x2DD46, 0x2DEC8, 0x2E1DE,
                                0x2E4E8, 0x2E7F8, 0x2EB02, 0xE18B7

                            } }
                          }
                        },
                        { "RtlCaptureContext",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x2F042, 0x2F43C, 0xE1A05, 0xE1C02,
                                0xE1C49, 0xE295B, 0xE29A9, 0xE2AAD

                            } },
                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142058

                            } }
                          }
                        },
                        { "IsDebuggerPresent",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47712 } } }
                        },
                        { "SetUnhandledExceptionFilter",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47732, 0x4792D } } }
                        },
                        { "SetPriorityClass",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xE1D59 } } }
                        },
                        { "UnhandledExceptionFilter",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x4773C, 0x47936 } } }
                        },
                        { "GetSystemTimeAsFileTime",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x477FE } } }
                        },
                        { "GetCurrentProcess",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47941 } } }
                        },
                        { "GetCurrentThreadId",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x4780D } } }
                        },
                        { "GetCurrentProcessId",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47816 } } }
                        },
                        { "QueryPerformanceCounter",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47823 } } }
                        },
                        { "TerminateProcess",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47948 } } }
                        },
                        { "IsProcessorFeaturePresent",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47ABB } } }
                        },
                        { "GetWindowsDirectoryA",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x624D1 } } }
                        },
                        { "FormatMessageW",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x6040B, 0x6045A } } }
                        },
                        { "GetLastError",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x60415, 0x60713 } } }
                        },
                        { "WideCharToMultiByte",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x60706, 0x60745 } } }
                        },
                        { "MulDiv",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x616C2, 0x62230 } } }
                        },
                        { "GetTickCount",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x6289D

                            } },

                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142080

                            } }
                          }
                        },
                        { "MultiByteToWideChar",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x139EF7

                            } },

                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142088

                            } }
                          }
                        },

                }

        },

        //VCRUNTIME140.
        { "vcruntime140",

                {

                        { "_except_handler4_common",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A61 } } }
                        },
                        { "__std_exception_copy",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x11DD0, 0x11E10, 0x45EC1, 0x45F11,
                                0x461F9

                            } }
                          }
                        },
                        { "__std_exception_destroy",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11D5C, 0x11D82, 0x460C2, 0x47A4F } } }
                        },
                        { "_CxxThrowException",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A55 } } }
                        },
                        { "strstr",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x1C69E,  0x57219,  0x57362,  0x57460,
                                0x590A0,  0x5911A,  0x5918F,  0x6446A,
                                0x6475A,  0x6C4FB,  0xE134B,  0xE2511,
                                0x115EE7, 0x131CB8, 0x13DE63, 0x13E68A

                            } },

                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x1421B4

                            } }
                          }
                        },
                        { "__std_type_info_destroy_list",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A67 } } }
                        },
                        { "_purecall",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A49 } } }
                        },
                        { "memset",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A5B } } }
                        },
                        { "__CxxFrameHandler3",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x140189 } } }
                        },
                        { "memchr",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x14018F } } }
                        },
                        { "memcpy",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x140195 } } }
                        },
                        { "memmove",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x14019B } } }
                        }

                }

        },

        //MSVCP140.
        { "msvcp140",

                {

                        { "?_Xbad_function_call@std@@YAXXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x13D1ED, 0x13D419, 0x13D85B } } }
                        },
                        { "?_Xlength_error@std@@YAXPBD@Z",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x3747,  0x5BE7,  0x71D7,  0xBED0,
                                0x134B8, 0x13E56, 0x142F8, 0x14AF1,
                                0x14CA7, 0x1590D, 0x15B55, 0x15BAA,
                                0x16103, 0x178A5, 0x1D226, 0x1E030,
                                0x3350E, 0x3BF7E, 0x3C29E, 0x127F4D,
                                0x128E06
                            } }
                          }
                        },
                        { "?in@?$codecvt@DDU_Mbstatet@@@std@@QBEHAAU_Mbstatet@@PBD1AAPBDPAD3AAPAD@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E5FB } } }
                        },
                        { "?_Xout_of_range@std@@YAXPBD@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x3137, 0x63B7, 0x31EE7 } } }
                        },
                        { "_Mtx_init_in_situ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x2B19 } } }
                        },
                        { "?_Fiopen@std@@YAPAU_iobuf@@PBDHH@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B25C } } }
                        },
                        { "_Cnd_init_in_situ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x2B24 } } }
                        },
                        { "?_Getcat@?$codecvt@DDU_Mbstatet@@@std@@SAIPAPBVfacet@locale@2@PBV42@@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1EC5B } } }
                        },
                        { "?_Xbad_alloc@std@@YAXXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x2C8E } } }
                        },
                        { "?_Gettrue@_Locinfo@std@@QBEPBDXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11CCD } } }
                        },
                        { "?_Getfalse@_Locinfo@std@@QBEPBDXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11CBB } } }
                        },
                        { "?_Getgloballocale@locale@std@@CAPAV_Locimp@12@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11C02, 0x1EC3A } } }
                        },
                        { "??0?$basic_ostream@DU?$char_traits@D@std@@@std@@QAE@PAV?$basic_streambuf@DU?$char_traits@D@std@@@1@_N@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B03B } } }
                        },
                        { "?_Getlconv@_Locinfo@std@@QBEPBUlconv@@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11C75 } } }
                        },
                        { "?_Init@locale@std@@CAPAV_Locimp@12@_N@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xCEA8, 0x60159 } } }
                        },
                        { "_Mtx_destroy_in_situ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x141527 } } }
                        },
                        { "?_Gninc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEPADXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E526 } } }
                        },
                        { "??0?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAE@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B071 } } }
                        },
                        { "??Bid@locale@std@@QAEIXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11BDA, 0x1EC16 } } }
                        },
                        { "_Thrd_join",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x13D647 } } }
                        },
                        { "??1_Lockit@std@@QAE@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11C24, 0x11D08, 0x1EC88 } } }
                        },
                        { "??0_Lockit@std@@QAE@H@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11BC8, 0x1EC02 } } }
                        },
                        { "??0_Locinfo@std@@QAE@PBD@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11C5E } } }
                        },
                        { "?_Getcvt@_Locinfo@std@@QBE?AU_Cvtvec@@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11C81, 0x11CA5 } } }
                        },
                        { "??1_Locinfo@std@@QAE@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x11CE9 } } }
                        },
                        { "?_Throw_Cpp_error@std@@YAXH@Z",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x458F2, 0xE1E2F, 0x13D57F, 0x13D681,
                                0x13D689
                            } }
                          }
                        },
                        { "_Query_perf_frequency",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1305E } } }
                        },
                        { "?always_noconv@codecvt_base@std@@QBE_NXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B299, 0x1EBC5 } } }
                        },
                        { "_Query_perf_counter",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1306B } } }
                        },
                        { "??0?$basic_ios@DU?$char_traits@D@std@@@std@@IAE@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B022 } } }
                        },
                        { "?_Incref@facet@locale@std@@UAEXXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x46C5A } } }
                        },
                        { "?_Init@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEXXZ",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x1B099, 0x1B2BE, 0x1EBE1, 0x1EEB8,
                                0x1EF6B

                            } }
                          }
                        },
                        { "_Mtx_unlock",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x457D8,  0x13D3E0, 0x13D433, 0x13D66B,
                                0x13D700, 0x13D809

                            } },
                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142164

                            } }
                          }
                        },
                        { "?setstate@?$basic_ios@DU?$char_traits@D@std@@@std@@QAEXH_N@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B315, 0x1B51B } } }
                        },
                        { "?getloc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@QBE?AVlocale@2@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B288 } } }
                        },
                        { "?clear@?$basic_ios@DU?$char_traits@D@std@@@std@@QAEXH_N@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B2F6, 0x1B4EF } } }
                        },
                        { "_Cnd_destroy_in_situ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x14151C } } }
                        },
                        { "_Cnd_broadcast",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x13D3A2, 0x13D609, 0x13D7BF } } }
                        },
                        { "?xsputn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAE_JPBD_J@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E89F } } }
                        },
                        { "??1?$basic_streambuf@DU?$char_traits@D@std@@@std@@UAE@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1CB5F, 0x1E353 } } }
                        },
                        { "??1?$basic_ios@DU?$char_traits@D@std@@@std@@UAE@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1CB72 } } }
                        },
                        { "??1?$basic_ostream@DU?$char_traits@D@std@@@std@@UAE@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1CB68 } } }
                        },
                        { "?xsgetn@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAE_JPAD_J@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E748 } } }
                        },
                        { "?_Pninc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@IAEPADXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1ED14 } } }
                        },
                        { "?out@?$codecvt@DDU_Mbstatet@@@std@@QBEHAAU_Mbstatet@@PBD1AAPBDPAD3AAPAD@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1ED7A } } }
                        },
                        { "?unshift@?$codecvt@DDU_Mbstatet@@@std@@QBEHAAU_Mbstatet@@PAD1AAPAD@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1EE37 } } }
                        },
                        { "?_Throw_C_error@std@@YAXH@Z",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x457E6,  0x13D441, 0x13D5CA, 0x13D617,
                                0x13D679, 0x13D6B9, 0x13D70E, 0x13D792,
                                0x13D7CD, 0x13D817

                            } }
                          }
                        },
                        { "_Cnd_do_broadcast_at_thread_exit",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x45E80 } } }
                        },
                        { "_Thrd_hardware_concurrency",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xE1C8A } } }
                        },
                        { "?_Decref@facet@locale@std@@UAEPAV_Facet_base@3@XZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x46C54 } } }
                        },
                        { "?_Syserror_map@std@@YAPBDH@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x45F7A } } }
                        },
                        { "?_Execute_once@std@@YAHAAUonce_flag@1@P6GHPAX1PAPAX@Z1@Z",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x46087 } } }
                        },
                        { "?showmanyc@?$basic_streambuf@DU?$char_traits@D@std@@@std@@MAE_JXZ",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x46CE4 } } }
                        },
                        { "_Mtx_lock",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x13D239, 0x13D29F, 0x13D348, 0x13D5BC,
                                0x13D6AB, 0x13D784
								
                            } }
                          }
                        },
                        { "_Cnd_wait",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x13D26F

                            } },
                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142184

                            } }
                          }
                        },
                        { "??_7facet@locale@std@@6B@",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x1420B0 } } }
                        },
                        { "??_7_Facet_base@std@@6B@",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x1420B4 } } }
                        },
                        { "?id@?$numpunct@D@std@@2V0locale@2@A",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x1420E8 } } }
                        },
                        { "?id@?$codecvt@DDU_Mbstatet@@@std@@2V0locale@2@A",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x142118 } } }
                        },
                        { "?GetCurrentThreadId@platform@details@Concurrency@@YAJXZ",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x142178 } } }
                        }

                }

        },

        //UCRTBASE.
        { "ucrtbase",

                {

                        { "__stdio_common_vsprintf",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xC363, 0x2EFF1, 0x139EBC } } }
                        },
                        { "_invalid_parameter_noinfo_noreturn",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                              0x2bc3,   0x2c07,   0x2f2c,   0x3061,
                              0x3110,   0x318d,   0x3209,   0x3244,
                              0x34c9,   0x3716,   0x54ec,   0x5661,
                              0x5c23,   0x5c77,   0x5ce7,   0x5e82,
                              0x5fdf,   0x6099,   0x6126,   0x6246,
                              0x6382,   0x6416,   0x646f,   0x6562,
                              0x6953,   0x6b49,   0x6dae,   0x6e5f,
                              0x700e,   0x71c4,   0x7590,   0x8935,
                              0x89de,   0x8a8e,   0x8b6f,   0x8c4f,
                              0x8d33,   0x9102,   0x924a,   0x97d3,
                              0x996e,   0x99cd,   0x9a42,   0x9ae1,
                              0x9b7e,   0x9d1d,   0x9d69,   0x9daa,
                              0x9de9,   0xa0e8,   0xa2b0,   0xa4c9,
                              0xa589,   0xab2a,   0xaea5,   0xaf76,
                              0xb40e,   0xb6a2,   0xb9c2,   0xbc80,
                              0xc2fe,   0xc776,   0xc7ca,   0xc85f,
                              0xc996,   0xca94,   0xcb02,   0xcc0c,
                              0xccdb,   0xcd94,   0xce67,   0xd05e,
                              0xfd9f,   0x1014a,  0x122a1,  0x12396,
                              0x1246f,  0x124cf,  0x12df9,  0x12e8e,
                              0x13bea,  0x14080,  0x14160,  0x14200,
                              0x158cf,  0x171f7,  0x17307,  0x17417,
                              0x17527,  0x1855b,  0x187b9,  0x18962,
                              0x18c78,  0x18f72,  0x19032,  0x191a0,
                              0x19276,  0x19329,  0x19574,  0x1aa20,
                              0x1abf3,  0x1afd6,  0x1b4c8,  0x1b5dd,
                              0x1bc06,  0x1bdf9,  0x1bfa7,  0x1c09c,
                              0x1c1a0,  0x1c346,  0x1cf13,  0x1cf69,
                              0x1cfc7,  0x1d019,  0x1d1d8,  0x1ddf2,
                              0x1e69d,  0x1f0d7,  0x1f159,  0x1f27c,
                              0x1f330,  0x1f721,  0x2ceba,  0x2cf91,
                              0x2d1da,  0x2d29c,  0x2d4da,  0x2d5b1,
                              0x2d72e,  0x2d96a,  0x2da5c,  0x2dc9a,
                              0x2dd72,  0x2def4,  0x2e13a,  0x2e20a,
                              0x2e44a,  0x2e514,  0x2e75a,  0x2e824,
                              0x2ea6a,  0x2eb2e,  0x2ef62,  0x2f5be,
                              0x31029,  0x3110d,  0x314ed,  0x31742,
                              0x31d9a,  0x31e9b,  0x324e0,  0x326e2,
                              0x32919,  0x339f3,  0x33bf9,  0x33ca2,
                              0x33d1f,  0x34088,  0x34088,  0x34172,
                              0x34a3b,  0x34e32,  0x34f13,  0x34ff1,
                              0x350d0,  0x35196,  0x35270,  0x35389,
                              0x35486,  0x368ce,  0x36a6e,  0x36ac9,
                              0x36b27,  0x37ed9,  0x3891e,  0x3b1d2,
                              0x3c644,  0x3c70c,  0x3cf14,  0x3dfe9,
                              0x3e0c6,  0x3e124,  0x3efac,  0x3f184,
                              0x3f4a8,  0x3f63e,  0x40343,  0x40389,
                              0x405a5,  0x40edf,  0x40f59,  0x41101,
                              0x41fcb,  0x420d0,  0x42913,  0x42b61,
                              0x42c1e,  0x4304f,  0x432b7,  0x4344e,
                              0x43604,  0x43ae3,  0x44837,  0x44aed,
                              0x45157,  0x4543e,  0x45741,  0x457bb,
                              0x45879,  0x45aaa,  0x45cc4,  0x4619a,
                              0x4622e,  0x46276,  0x46887,  0x46ab6,
                              0x5074f,  0x509c9,  0x5af2a,  0x5b009,
                              0x5b536,  0x5b681,  0x5b6bf,  0x5b79c,
                              0x5b856,  0x5d8c3,  0x5d982,  0x5da1e,
                              0x5dac0,  0x5db5a,  0x5eeab,  0x6035a,
                              0x60630,  0x60681,  0x62335,  0x62676,
                              0x62708,  0x63eef,  0x644f5,  0x64cdf,
                              0x65397,  0x65447,  0x6566a,  0x65835,
                              0x65abb,  0x66b16,  0x66ba7,  0x670cc,
                              0x6715e,  0x676de,  0x677df,  0x67ca3,
                              0x67f0b,  0x68945,  0x691b2,  0x693db,
                              0x69ce4,  0x69e25,  0x6a15c,  0x6a3ca,
                              0x6a65a,  0x6b37f,  0x6b496,  0x6bba8,
                              0x6bf52,  0x6c21b,  0xe106b,  0xe1821,
                              0xe18e3,  0xe1e69,  0xe1f63,  0xe200d,
                              0xe21ae,  0xe309c,  0xe4f7e,  0xe5cd7,
                              0xec8c1,  0xec9eb,  0xecfa1,  0xed6c1,
                              0xf25a7,  0xf3bf7,  0xfdce7,  0x110d9c,
                              0x110ea9, 0x1138f9, 0x1143fa, 0x115ddd,
                              0x11dda0, 0x11fd1f, 0x1252fe, 0x128dfb,
                              0x133481, 0x133d6d, 0x1353d6, 0x137d7c,
                              0x13b907, 0x13e6bb, 0x13f66b, 0x14062e,
                              0x1408c1, 0x140921, 0x140aa1, 0x140d61,
                              0x140e81, 0x1410fe, 0x14115e, 0x1411be,
                              0x141269, 0x1412b1, 0x1414a3, 0x1415a3
                            } }
                          }
                        },
                        { "fputc",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1ED96 } } }
                        },
                        { "fflush",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1EB9A } } }
                        },
                        { "clock",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x13A25, 0x13C25, 0x13CC5, 0x14535,
                                0x145F5, 0x148C5, 0x14965, 0x14D35,
                                0x14DF5, 0x15A12, 0x16685, 0x16735,
                                0x16833, 0x16872, 0x4634B, 0x6BDE7
                            } },
                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x14232C

                            } }
                          }
                        },
                        { "_dtest",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xE996, 0xE9F2 } } }
                        },
                        { "ispunct",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xFDADE, 0x110F7D } } }
                        },
                        { "_initialize_narrow_environment",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A8B } } }
                        },
                        { "_dsign",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xE92F, 0xEB8F } } }
                        },
                        { "_fdtest",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x56AF, 0x5A6F4, 0x5A712, 0x1255B4,
                                0x12676B

                            } },
                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142240

                            } }
                          }
                        },
                        { "calloc",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x2C7F } } }
                        },
                        { "_lock_file",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E37A } } }
                        },
                        { "__stdio_common_vsnprintf_s",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xC933, 0x11DA25 } } }
                        },
                        { "isalnum",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xFDB00, 0x110F9F } } }
                        },
                        { "isdigit",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x340F3, 0xEC506, 0xEC546 } } }
                        },
                        { "_unlock_file",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E38A } } }
                        },
                        { "__stdio_common_vsprintf_s",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x6D01, 0x8F60 } } }
                        },
                        { "strerror_s",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x601E6, 0x61660 } } }
                        },
                        { "roundf",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x5B22, 0x5B3F, 0x147AA, 0x4C7EA,
                                0x4C879

                            } }
                          }
                        },
                        { "_ldtest",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xEBF6, 0xEC52 } } }
                        },
                        { "fgetpos",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E9E2 } } }
                        },
                        { "strncpy_s",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x15EB3, 0x46561, 0x46600, 0x66879,
                                0x66CC5

                            } },
                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142308

                            } }
                          }
                        },
                        { "atoi",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x18F25, 0x18FE5, 0xEC5CC } } }
                        },
                        { "fwrite",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x1E949, 0x1EDC3, 0x1EE6C, 0x626A3

                            } }
                          }
                        },
                        { "tolower",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x503C7, 0x50887, 0xFDB12, 0x110FB1

                            } },
                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x1422F4

                            } }
                          }
                        },
                        { "_cexit",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47AA9 } } }
                        },
                        { "strncmp",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1A4BB, 0x11D6A8 } } }
                        },
                        { "fmaxf",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x124D03 } } }
                        },
                        { "remove",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1B76E, 0x625E1, 0x626D9 } } }
                        },
                        { "ungetc",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x1E3EA, 0x1E4AB

                            } },

                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x1422E8

                            } }
                          }
                        },
                        { "fgetc",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E56F, 0x1E59C, 0x1E65C } } }
                        },
                        { "_fseeki64",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1E9CD } } }
                        },
                        { "fopen",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x62645 } } }
                        },
                        { "fsetpos",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1EA9A } } }
                        },
                        { "setvbuf",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1EB5B } } }
                        },
                        { "_CIfmod",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401A7 } } }
                        },
                        { "_get_stream_buffer_pointers",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1EEE7 } } }
                        },
                        { "fclose",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1EF51, 0x626AA } } }
                        },
                        { "strcpy_s",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x1F816, 0x1F896, 0x110E7A, 0x1111BA

                            } }
                          }
                        },
                        { "_libm_sse2_asin_precise",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401AD } } }
                        },
                        { "toupper",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0xE2C39, 0xE3EA6, 0xE3F66 } } }
                        },
                        { "fminf",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x124D42 } } }
                        },
                        { "_execute_onexit_table",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A9D } } }
                        },
                        { "__stdio_common_vsscanf",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x2EFBD } } }
                        },
                        { "terminate",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x457B5, 0x458A3, 0x45AA4, 0x46094

                            } }
                          }
                        },
                        { "_initialize_onexit_table",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A91 } } }
                        },
                        { "_beginthreadex",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x458DF, 0xE1CF5, 0x13D52F } } }
                        },
                        { "malloc",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A79 } } }
                        },
                        { "free",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0x47A6D

                            } },

                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142208

                            } }
                          }
                        },
                        { "_callnewh",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A73 } } }
                        },
                        { "_seh_filter_dll",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A7F } } }
                        },
                        { "_configure_narrow_argv",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A85 } } }
                        },
                        { "_CIatan2",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401A1 } } }
                        },
                        { "_register_onexit_function",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47A97 } } }
                        },
                        { "strftime",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x12D369 } } }
                        },
                        { "rand",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x4C549, 0xE0F02, 0x11330F } } }
                        },
                        { "_crt_atexit",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47AA3 } } }
                        },
                        { "_initterm",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47AAF } } }
                        },
                        { "towupper",
                          {
                            { AdditionalRuntime::ImportType::PUBLIC, {

                                0xE2B86, 0xE42B6, 0xE9FC6

                            } },

                            { AdditionalRuntime::ImportType::INTERNAL, {

                                0x142320

                            } }
                          }
                        },
                        { "_initterm_e",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x47AB5 } } }
                        },
                        { "abort",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x628B2 } } }
                        },
                        { "strtol",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x66B42 } } }
                        },
                        { "strtoul",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x1421F0 } } }
                        },
                        { "_time64",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x12CE84, 0x12D2F5 } } }
                        },
                        { "_localtime64",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x12CE93, 0x12D308 } } }
                        },
                        { "__stdio_common_vswprintf",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x139DBD } } }
                        },
                        { "_libm_sse2_atan_precise",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401B3 } } }
                        },
                        { "_libm_sse2_cos_precise",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401B9 } } }
                        },
                        { "_libm_sse2_exp_precise",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401BF } } }
                        },
                        { "_libm_sse2_pow_precise",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401C5 } } }
                        },
                        { "_libm_sse2_sin_precise",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401CB } } }
                        },
                        { "_libm_sse2_sqrt_precise",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401D1 } } }
                        },
                        { "_libm_sse2_tan_precise",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401D7 } } }
                        },
                        { "ceil",
                          { { AdditionalRuntime::ImportType::PUBLIC, { 0x1401DD } } }
                        },
                        { "fread",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x1422C8 } } }
                        },
                        { "towlower",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x142300 } } }
                        },
                        { "isspace",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x14230C } } }
                        },
                        { "strcat_s",
                          { { AdditionalRuntime::ImportType::INTERNAL, { 0x14231C } } }
                        }

                } },


                //GDI32.
                { "gdi32",

                  {

                    { "CreateCompatibleDC",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x6169F } } }
                    },
                    { "SetMapMode",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x616B5 } } }
                    },
                    { "SetBkColor",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x61818 } } }
                    },
                    { "GetTextExtentPoint32A",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x6205D, 0x620D5 } } }
                    },
                    { "CreateFontA",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x61717, 0x62285 } } }
                    },
                    { "SetTextAlign",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x61821 } } }
                    },
                    { "CreateDIBSection",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x617E7 } } }
                    },
                    { "SetTextColor",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x6180F } } }
                    },
                    { "DeleteDC",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x618D2 } } }
                    },
                    { "AddFontMemResourceEx",
                      {
                        { AdditionalRuntime::ImportType::PUBLIC, {

                            0x623DF, 0x62471

                        } },

                        { AdditionalRuntime::ImportType::INTERNAL, {

                            0x142004

                        } }
                      }
                    },
                    { "ExtTextOutA",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x62146 } } }
                    },
                    { "AddFontResourceExA",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x626C3 } } }
                    },
                    { "DeleteObject",
                      { { AdditionalRuntime::ImportType::INTERNAL, { 0x14200C } } }
                    },
                    { "SelectObject",
                      { { AdditionalRuntime::ImportType::INTERNAL, { 0x142020 } } }
                    }

                  }

                },

                //USER32.
                { "user32",

                  {

                    { "FindWindowA",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0xECF70 } } }
                    },
                    { "GetActiveWindow",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x13E7BA } } }
                    },
                    { "SetWindowLongA",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0xEE51F, 0xEFACC } } }
                    },
                    { "CallWindowProcA",
                      { { AdditionalRuntime::ImportType::PUBLIC, { 0x13EA59 } } }
                    }

                  }

                }
};