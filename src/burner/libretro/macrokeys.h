#ifndef MACROKEYS_H
#define MACROKEYS_H

#include <vector>
#include <string>
#include <cstdint>

// 声明多语言字符串
extern const char* neogeo_macro_desc;
extern const char* pgm_macro_desc;
extern const char* cps1_macro_desc;
extern const char* macro_info_general;

// 定义 macro_option_value 结构体
struct macro_option_value {
	const char* value;
	const char* label;
};

// 定义 macro_option 结构体
struct macro_option {
	const char* key;
	const char* button;
	const char* option_name;
	const char* info;
	const char* default_value;
	macro_option_value values[13]; // 每个宏选项下有12个子选项，还需要多加一个null项
};

// 定义 macro_category 结构体
struct macro_category {
	const char* system;
	const char* category_name;
	macro_option options[4]; // 每个类别下有4个宏选项
};

// 自定义宏键结构体
struct CustomMacroKey {
	std::string system;
	std::string button;
	std::string macroKey;
};

// 自定义宏键集合结构体
struct CustomMacroKeys {
	std::vector<CustomMacroKey> macrocontent;
};

// 函数声明
size_t get_macro_categories_size(); 
int get_macro_count(const char* system);
CustomMacroKeys LoadCustomMacroKeys(const char* system);
int AddMacroOptions(const char* system, int nbr_macros, int idx_var);
void set_macro_language_strings(uint32_t nLangcode);
void BindCustomMacroKeys(const CustomMacroKeys& macrosdata, char* description, int nPlayer, unsigned int* nDeviceType, struct GameInp * pgi);

// 外部变量声明
extern CustomMacroKeys macrodata;
extern macro_category var_fbneo_macro_categories[];

// 重载函数用于2键和4键基板
struct GameInp* AddMacroKeys(struct GameInp* pgi, int nPlayer, const char* system, int nButtons[][4], uint32_t& nMacroCount);
struct GameInp* AddMacroKeys(struct GameInp* pgi, int nPlayer, const char* system, int nButtons[][2], uint32_t& nMacroCount);

void AssignButtons(const char* system, const char* szName, const char* szInfo, int nPlayer, int i, int nButtons[][4]);
void AssignButtons(const char* system, const char* szName, const char* szInfo, int nPlayer, int i, int nButtons[][2]);

#define RETRO_DEVICE_ID_3RD_COL_BOTTOM (nDeviceType[nPlayer] == RETROPAD_MODERN ? RETRO_DEVICE_ID_JOYPAD_R2 : RETRO_DEVICE_ID_JOYPAD_R )
#define RETRO_DEVICE_ID_3RD_COL_TOP    (nDeviceType[nPlayer] == RETROPAD_MODERN ? RETRO_DEVICE_ID_JOYPAD_R  : RETRO_DEVICE_ID_JOYPAD_L )
#define RETRO_DEVICE_ID_4TH_COL_BOTTOM (nDeviceType[nPlayer] == RETROPAD_MODERN ? RETRO_DEVICE_ID_JOYPAD_L2 : RETRO_DEVICE_ID_JOYPAD_R2)
#define RETRO_DEVICE_ID_4TH_COL_TOP    (nDeviceType[nPlayer] == RETROPAD_MODERN ? RETRO_DEVICE_ID_JOYPAD_L  : RETRO_DEVICE_ID_JOYPAD_L2)

#endif // MACROKEYS_H