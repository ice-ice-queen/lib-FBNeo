#ifndef MACROKEYS_H
#define MACROKEYS_H

#include <vector>
#include <string>
#include "retro_common.h"

// 声明多语言字符串
extern const char* neogeo_macro_desc;
extern const char* pgm_macro_desc;
extern const char* cps1_macro_desc;
extern const char* streetfighter_macro_desc;
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
	macro_option_value values[20]; // 目前最大可能出現15個按鍵組合，加上"取消"和"NULL"
};

// 定义 macro_category 结构体
struct macro_category {
	const char* system;
	const char* category_name;
	macro_option options[4]; // 每个类别下预设有4个键位对应的宏选项
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
void set_macro_language_strings(UINT32 nLangcode);
void BindCustomMacroKeys(const CustomMacroKeys& macrosdata, char* description, int nPlayer, unsigned int* nDeviceType, struct GameInp * pgi);

// 外部变量声明
extern CustomMacroKeys macrodata;
extern macro_category var_fbneo_macro_categories[];


struct GameInp* AddMacroKeys(struct GameInp* pgi, int nPlayer, int nButtonsTwo[][2], int nButtonsFour[][4], int nPunchInputs[][3], int nKickInputs[][3], const char* system, UINT32& nMacroCount);
void AssignButtons(const char* system, const char* szName, const char* szInfo, int nPlayer, int i, int nButtons[][4]);
void AssignButtons(const char* system, const char* szName, const char* szInfo, int nPlayer, int i, int nButtons[][2]);

#endif // MACROKEYS_H