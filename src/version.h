#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)

#define VERSION_MAJOR               0
#define VERSION_MINOR               3
#define VERSION_REVISION            0
#define VERSION_BUILD               0

#define FILE_VERSION				VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_BUILD
#define FILE_VERSION_STR			STRINGIZE(VERSION_MAJOR)        \
                                    "." STRINGIZE(VERSION_MINOR)    \
                                    "." STRINGIZE(VERSION_REVISION) \
                                    "." STRINGIZE(VERSION_BUILD)    \

#define PRODUCT_VERSION				VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_BUILD
#define PRODUCT_VERSION_STR        STRINGIZE(VERSION_MAJOR)        \
                                    "." STRINGIZE(VERSION_MINOR)    \
                                    "." STRINGIZE(VERSION_REVISION)

#define FILE_OS						VOS_NT_WINDOWS32
#define FILE_TYPE					VFT_APP
#define FILE_SUBTYPE				VFT2_UNKNOWN
#ifdef _DEBUG
#define FILE_FLAGS					VS_FF_DEBUG
#else
#define FILE_FLAGS					0
#endif

#define COMPANY_NAME				"BetterDiscord - https://betterdiscord.net"
#define PRODUCT_NAME				"BetterDiscord Setup - https://betterdiscord.net"
#define FILE_DESCRIPTION			"BetterDiscord Setup - https://betterdiscord.net"
#define INTERNAL_NAME				"BDI"
#define ORIGINAL_FILENAME			"BDI.exe"
#define COPYRIGHT_STR				"Copyright (C) 2019 - Jiiks - https://github.com/jiiks"
