#include "macrokeys.h"
#include "retro_common.h"
#include "retro_input.h"
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>

const char* neogeo_macro_desc;
const char* pgm_macro_desc;
const char* cps1_macro_desc;
const char* streetfighter_macro_desc;
const char* macro_info_general;
char* R_button_description;
char* L_button_description;
char* R2_button_description;
char* L2_button_description;
char* R3_button_description;
char* L3_button_description;

macro_category var_fbneo_macro_categories[4];

// 更新多语言字符串的函数
void set_macro_language_strings(UINT32 nLangcode) {

	const char* macro_desc_button_l_options[] = {
		"Shoulder Button L",
		"肩键 L",
		"肩鍵 L"
	};
	const char* macro_desc_button_r_options[] = {
		"Shoulder Button R",
		"肩键 R",
		"肩鍵 R"
	};
	const char* macro_desc_button_l2_options[] = {
		"Shoulder Button L2",
		"肩键 L2",
		"肩鍵 L2"
	};
	const char* macro_desc_button_r2_options[] = {
		"Shoulder Button R2",
		"肩键 R2",
		"肩鍵 R2"
	};
	const char* macro_desc_button_l3_options[] = {
		"LeftStick Button L3",
		"左摇杆键 L3",
		"左搖桿鍵 L3"
	};
	const char* macro_desc_button_r3_options[] = {
		"RightStick Button R3",
		"右摇杆键 R3",
		"右搖桿鍵 R3"
	};
	const char* macro_info_button_options[] = {
		"Note: Keyboard users, please confirm the corresponding keys in <Quick Menu → Control>",
		"注：键盘使用者请于<快捷菜单→控制>中确认对应键",
		"註：鍵盤使用者請於<快捷選单→控制器>中確認對應鍵"
	};
	const char* macro_disabled_options[] = {
		"Disable Combination",
		"取消组合键",
		"取消組合鍵"
	};
	const char* neogeo_macro_desc_options[] = {
		"Neo-Geo Combinations",
		"Neo-Geo 组合键",
		"Neo-Geo 組合鍵"
	};
	const char* pgm_macro_desc_options[] = {
		"PGM Combinations",
		"PGM 组合键",
		"PGM 組合鍵"
	};
	const char* cps1_macro_desc_options[] = {
		"CPS1 Combinations",
		"CPS1 组合键",
		"CPS1 組合鍵"
	};
	const char* streetfighter_macro_desc_options[] = {
		"6keys-Layout Combinations",
		"6键布局 组合键",
		"6鍵佈局 組合鍵"
	};
	const char* macro_info_general_options[] = {
		"Set and reload or reset game to take effect.",
		"设定完毕后重新载入或重启游戏使其生效",
		"設定完畢後重新載入或重啓游戲使其生效"
	};

	const char* macro_desc_button_l = macro_desc_button_l_options[nLangcode];
	const char* macro_desc_button_r = macro_desc_button_r_options[nLangcode];
	const char* macro_desc_button_l2 = macro_desc_button_l2_options[nLangcode];
	const char* macro_desc_button_r2 = macro_desc_button_r2_options[nLangcode];
	const char* macro_desc_button_l3 = macro_desc_button_l3_options[nLangcode];
	const char* macro_desc_button_r3 = macro_desc_button_r3_options[nLangcode];
	const char* macro_info_button = macro_info_button_options[nLangcode];
	const char* macro_disabled = macro_disabled_options[nLangcode];
	neogeo_macro_desc = neogeo_macro_desc_options[nLangcode];
	pgm_macro_desc = pgm_macro_desc_options[nLangcode];
	cps1_macro_desc = cps1_macro_desc_options[nLangcode];
	streetfighter_macro_desc = streetfighter_macro_desc_options[nLangcode];
	macro_info_general = macro_info_general_options[nLangcode];

	// 初始化宏选项,目前包含3个系统
	macro_category temp_var_fbneo_macro_categories[4] = {
		{
			// 全部的11种组合中"Buttons ACD"用不上-感谢ppx的jjsnake帮助查询整理
			"pgm", "pgm_macro",
			{
				{ "fbneo-pgm-macro-l", "L", macro_desc_button_l, macro_info_button, "Buttons CD",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-pgm-macro-r", "R", macro_desc_button_r, macro_info_button, "Buttons AB",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-pgm-macro-l2", "L2", macro_desc_button_l2, macro_info_button, "Buttons BC",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-pgm-macro-r2", "R2", macro_desc_button_r2, macro_info_button, "Buttons ABC",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } }
			}
		},
		{
			// 全部的11种组合中"Buttons ACD"用不上-感谢ppx的jjsnake帮助查询整理
			"neogeo", "neogeo_macro",
			{
				{ "fbneo-neogeo-macro-l", "L", macro_desc_button_l, macro_info_button, "Buttons CD",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-neogeo-macro-r", "R", macro_desc_button_r, macro_info_button, "Buttons AB",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-neogeo-macro-l2", "L2", macro_desc_button_l2, macro_info_button, "Buttons BCD",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-neogeo-macro-r2", "R2", macro_desc_button_r2, macro_info_button, "Buttons ABC",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } }
			}
		},
		{
			"cps1", "cps1_macro",
			{
				{ "fbneo-cps1-macro-l", "L", macro_desc_button_l, macro_info_button, macro_disabled,
					{ { "Buttons AB", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-cps1-macro-r", "R", macro_desc_button_r, macro_info_button, macro_disabled,
					{ { "Buttons AB", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-cps1-macro-l2", "L2", macro_desc_button_l2, macro_info_button, macro_disabled,
					{ { "Buttons AB", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-cps1-macro-r2", "R2", macro_desc_button_r2, macro_info_button, "Buttons AB",
					{ { "Buttons AB", NULL }, { macro_disabled, NULL }, { NULL, NULL } } }
			}
		},
		/*6键的57种组合可能，用不上这么多，但是先存着吧
		{
			"streetfighter", "streetfighter_macro",
			{
				{ "fbneo-streetfighter-macro-l2", "L2", macro_desc_button_l2, macro_info_button, "Buttons ABC",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons AE", NULL }, { "Buttons AF", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons BE", NULL }, { "Buttons BF", NULL }, { "Buttons CD", NULL }, { "Buttons CE", NULL }, { "Buttons CF", NULL }, { "Buttons DE", NULL }, { "Buttons DF", NULL }, { "Buttons EF", NULL },
					{ "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ABE", NULL }, { "Buttons ABF", NULL }, { "Buttons ACD", NULL }, { "Buttons ACE", NULL }, { "Buttons ACF", NULL }, { "Buttons ADE", NULL }, { "Buttons ADF", NULL }, { "Buttons AEF", NULL }, { "Buttons BCD", NULL }, { "Buttons BCE", NULL }, { "Buttons BCF", NULL }, { "Buttons BDE", NULL }, { "Buttons BDF", NULL }, { "Buttons BEF", NULL }, { "Buttons CDE", NULL }, { "Buttons CDF", NULL }, { "Buttons CEF", NULL }, { "Buttons DEF", NULL },
					{ "Buttons ABCD", NULL }, { "Buttons ABCE", NULL }, { "Buttons ABCF", NULL }, { "Buttons ABDE", NULL }, { "Buttons ABDF", NULL }, { "Buttons ABEF", NULL }, { "Buttons ACDE", NULL }, { "Buttons ACDF", NULL }, { "Buttons ACEF", NULL }, { "Buttons ADEF", NULL }, { "Buttons BCDE", NULL }, { "Buttons BCDF", NULL }, { "Buttons BCEF", NULL }, { "Buttons BDEF", NULL }, { "Buttons CDEF", NULL },
					{ "Buttons ABCDE", NULL }, { "Buttons ABCDF", NULL }, { "Buttons ABCEF", NULL }, { "Buttons ABDEF", NULL }, { "Buttons ACDEF", NULL }, { "Buttons BCDEF", NULL }, { "Buttons ABCDEF", NULL }, { macro_disabled, NULL }, { NULL, NULL } }
				},
				{ "fbneo-streetfighter-macro-r2", "R2", macro_desc_button_r2, macro_info_button, "Buttons DEF",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons AE", NULL }, { "Buttons AF", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons BE", NULL }, { "Buttons BF", NULL }, { "Buttons CD", NULL }, { "Buttons CE", NULL }, { "Buttons CF", NULL }, { "Buttons DE", NULL }, { "Buttons DF", NULL }, { "Buttons EF", NULL },
					{ "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ABE", NULL }, { "Buttons ABF", NULL }, { "Buttons ACD", NULL }, { "Buttons ACE", NULL }, { "Buttons ACF", NULL }, { "Buttons ADE", NULL }, { "Buttons ADF", NULL }, { "Buttons AEF", NULL }, { "Buttons BCD", NULL }, { "Buttons BCE", NULL }, { "Buttons BCF", NULL }, { "Buttons BDE", NULL }, { "Buttons BDF", NULL }, { "Buttons BEF", NULL }, { "Buttons CDE", NULL }, { "Buttons CDF", NULL }, { "Buttons CEF", NULL }, { "Buttons DEF", NULL },
					{ "Buttons ABCD", NULL }, { "Buttons ABCE", NULL }, { "Buttons ABCF", NULL }, { "Buttons ABDE", NULL }, { "Buttons ABDF", NULL }, { "Buttons ABEF", NULL }, { "Buttons ACDE", NULL }, { "Buttons ACDF", NULL }, { "Buttons ACEF", NULL }, { "Buttons ADEF", NULL }, { "Buttons BCDE", NULL }, { "Buttons BCDF", NULL }, { "Buttons BCEF", NULL }, { "Buttons BDEF", NULL }, { "Buttons CDEF", NULL },
					{ "Buttons ABCDE", NULL }, { "Buttons ABCDF", NULL }, { "Buttons ABCEF", NULL }, { "Buttons ABDEF", NULL }, { "Buttons ACDEF", NULL }, { "Buttons BCDEF", NULL }, { "Buttons ABCDEF", NULL }, { macro_disabled, NULL }, { NULL, NULL } }
				}
			}
		}
		*/
		{
			// 全部的57种组合中下述13种组合大概率有效-感谢ppx的jjsnake帮助查询整理
			"streetfighter", "streetfighter_macro",
			{
				{ "fbneo-streetfighter-macro-l2", "L2", macro_desc_button_l2, macro_info_button, "Buttons ABC",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BE", NULL }, { "Buttons CD", NULL }, { "Buttons CE", NULL }, { "Buttons CF", NULL }, { "Buttons DE", NULL }, { "Buttons DF", NULL }, { "Buttons EF", NULL },
					{ "Buttons ABC", NULL }, { "Buttons DEF", NULL }, { macro_disabled, NULL }, { NULL, NULL } }
				},
				{ "fbneo-streetfighter-macro-r2", "R2", macro_desc_button_r2, macro_info_button, "Buttons DEF",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BE", NULL }, { "Buttons CD", NULL }, { "Buttons CE", NULL }, { "Buttons CF", NULL }, { "Buttons DE", NULL }, { "Buttons DF", NULL }, { "Buttons EF", NULL },
					{ "Buttons ABC", NULL }, { "Buttons DEF", NULL }, { macro_disabled, NULL }, { NULL, NULL } }
				},
				{ "fbneo-streetfighter-macro-l3", "L3", macro_desc_button_l3, macro_info_button, macro_disabled,
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BE", NULL }, { "Buttons CD", NULL }, { "Buttons CE", NULL }, { "Buttons CF", NULL }, { "Buttons DE", NULL }, { "Buttons DF", NULL }, { "Buttons EF", NULL },
					{ "Buttons ABC", NULL }, { "Buttons DEF", NULL }, { macro_disabled, NULL }, { NULL, NULL } }
				},
				{ "fbneo-streetfighter-macro-r3", "R3", macro_desc_button_r3, macro_info_button, macro_disabled,
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BE", NULL }, { "Buttons CD", NULL }, { "Buttons CE", NULL }, { "Buttons CF", NULL }, { "Buttons DE", NULL }, { "Buttons DF", NULL }, { "Buttons EF", NULL },
					{ "Buttons ABC", NULL }, { "Buttons DEF", NULL }, { macro_disabled, NULL }, { NULL, NULL } }
				}
			}
		}
	};

	memcpy(var_fbneo_macro_categories, temp_var_fbneo_macro_categories, sizeof(temp_var_fbneo_macro_categories));
}

// 计算 var_fbneo_macro_categories 的大小
size_t get_macro_categories_size() {
	return sizeof(var_fbneo_macro_categories) / sizeof(var_fbneo_macro_categories[0]);
}

// 得到宏按键的数量（也即是预设的L R L2 R2有多少，做成函数获得）
int get_macro_count(const char* system) {
	int count = 0;
	for (int i = 0; i < sizeof(var_fbneo_macro_categories) / sizeof(var_fbneo_macro_categories[0]); i++) {
		if (strcmp(var_fbneo_macro_categories[i].system, system) == 0) {
			count = sizeof(var_fbneo_macro_categories[i].options) / sizeof(var_fbneo_macro_categories[i].options[0]);
			break;
		}
	}
	return count;
}

// 添加核心选项
int AddMacroOptions(const char* system, int nbr_macros, int idx_var) {
	size_t macro_categories_size = get_macro_categories_size();
	for (size_t i = 0; i < macro_categories_size; i++) {
		if (strcmp(var_fbneo_macro_categories[i].system, system) == 0) {
			for (int macro_idx = 0; macro_idx < nbr_macros; macro_idx++) {
				macro_option* option = &var_fbneo_macro_categories[i].options[macro_idx];
				option_defs_us[idx_var].key = option->key;
				option_defs_us[idx_var].desc = option->option_name;
				option_defs_us[idx_var].desc_categorized = option->option_name;
				option_defs_us[idx_var].info = option->info;
				option_defs_us[idx_var].category_key = var_fbneo_macro_categories[i].category_name;
				for (int value_idx = 0; option->values[value_idx].value != NULL; value_idx++) {
					option_defs_us[idx_var].values[value_idx].value = option->values[value_idx].value;
				}
				option_defs_us[idx_var].default_value = option->default_value;
				idx_var++;
			}
		}
	}
	return idx_var;
}

// 把核心选项变量中的按键所设定的组合键宏的值提取出来
void ProcessMacroContents(const char* system, int nbr_macros, int num_categories, CustomMacroKeys& macrodata) {
	for (int i = 0; i < num_categories; i++) {
		if (strcmp(var_fbneo_macro_categories[i].system, system) == 0) {
			for (int macro_idx = 0; macro_idx < nbr_macros; macro_idx++) {
				macro_option* option = &var_fbneo_macro_categories[i].options[macro_idx];
				struct retro_variable var = {0};
				var.key = option->key;

				if (environ_cb(RETRO_ENVIRONMENT_GET_VARIABLE, &var) && var.value) {
					CustomMacroKey macroKey;
					macroKey.system = var_fbneo_macro_categories[i].system;
					macroKey.button = option->button; // 使用 button 成员存储宏选项的描述
					macroKey.macroKey = var.value; // 使用 key 成员存储用户选择的值
					macrodata.macrocontent.push_back(macroKey);
				}
			}
		}
	}
}

// 按系统值运行ProcessMacroContents提取出对应的宏设置
CustomMacroKeys LoadCustomMacroKeys(const char* system) {
	CustomMacroKeys macrodata;

	int num_categories = sizeof(var_fbneo_macro_categories) / sizeof(var_fbneo_macro_categories[0]);

	for (int i = 0; i < num_categories; i++) {
		int nbr_macros = get_macro_count(var_fbneo_macro_categories[i].system);

		if (strcmp(var_fbneo_macro_categories[i].system, system) == 0) {
			ProcessMacroContents(system, nbr_macros, num_categories, macrodata);
		}
	}

	return macrodata;
}

// 绑定宏到RA输入设备
INT32 GameInpDigital2RetroInpKey(struct GameInp* pgi, unsigned port, unsigned id, char *szn, unsigned device, unsigned nInput);
void BindCustomMacroKeys(const CustomMacroKeys& macrosdata, char* description, int nPlayer, unsigned int* nDeviceType, struct GameInp * pgi) {
	std::map<std::string, int> keyCount; //储存比如<buttons AB>这样的key的出现的当前次数

	for (int i = 0; i < macrosdata.macrocontent.size(); ++i) {
		std::string key = macrosdata.macrocontent[i].macroKey;
		const char* button = macrosdata.macrocontent[i].button.c_str();

		// 计算key的当前出现次数并添加后缀(比如Buttons AB01)
		if (keyCount.find(key) == keyCount.end()) {
			keyCount[key] = 1;
		} else {
			keyCount[key]++;
		}
		char keyWithSuffix[50];
		sprintf(keyWithSuffix, "%s%02d", key.c_str(), keyCount[key]);
		
		if (strcmp(keyWithSuffix, description) == 0) {
			if (strcmp("R", button) == 0) {
				// 此全局变量的创立实为无奈之举，RA手柄会一直刷新，description必须常驻，否则字符串丢失
				// 前端显示"Buttons AB01-04"有些膈应
				R_button_description = new char[macrosdata.macrocontent[i].macroKey.size() + 1];
				strcpy(R_button_description, macrosdata.macrocontent[i].macroKey.c_str());
				GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_JOYPAD_R, R_button_description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
			}
			if (strcmp("L", button) == 0) {
				L_button_description = new char[macrosdata.macrocontent[i].macroKey.size() + 1];
				strcpy(L_button_description, macrosdata.macrocontent[i].macroKey.c_str());
				GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_JOYPAD_L, L_button_description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
			}
			if (strcmp("R2", button) == 0) {
				R2_button_description = new char[macrosdata.macrocontent[i].macroKey.size() + 1];
				strcpy(R2_button_description, macrosdata.macrocontent[i].macroKey.c_str());
				GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_JOYPAD_R2, R2_button_description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
			}
			if (strcmp("L2", button) == 0) {
				L2_button_description = new char[macrosdata.macrocontent[i].macroKey.size() + 1];
				strcpy(L2_button_description, macrosdata.macrocontent[i].macroKey.c_str());
				GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_JOYPAD_L2, L2_button_description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
			}
			if (strcmp("R3", button) == 0) {
				R3_button_description = new char[macrosdata.macrocontent[i].macroKey.size() + 1];
				strcpy(R3_button_description, macrosdata.macrocontent[i].macroKey.c_str());
				GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_JOYPAD_R3, R3_button_description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
			}
			if (strcmp("L3", button) == 0) {
				L3_button_description = new char[macrosdata.macrocontent[i].macroKey.size() + 1];
				strcpy(L3_button_description, macrosdata.macrocontent[i].macroKey.c_str());
				GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_JOYPAD_L3, L3_button_description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
			}
		}
	}
}

// 预设按键
// 重载函数-4键
void AssignButtons(const char* system, const char* szName, const char* szInfo, int nPlayer, int i, int nButtons[][4]) {
	if (strcmp(system, "neogeo") == 0) {
		if (_stricmp(" Button A", szName + 2) == 0) {
			nButtons[nPlayer][0] = i;
		}
		if (_stricmp(" Button B", szName + 2) == 0) {
			nButtons[nPlayer][1] = i;
		}
		if (_stricmp(" Button C", szName + 2) == 0) {
			nButtons[nPlayer][2] = i;
		}
		if (_stricmp(" Button D", szName + 2) == 0) {
			nButtons[nPlayer][3] = i;
		}
	} else if (strcmp(system, "pgm") == 0) {
		if (_stricmp(" fire 1", szInfo + 2) == 0) {
			nButtons[nPlayer][0] = i;
		}
		if (_stricmp(" fire 2", szInfo + 2) == 0) {
			nButtons[nPlayer][1] = i;
		}
		if (_stricmp(" fire 3", szInfo + 2) == 0) {
			nButtons[nPlayer][2] = i;
		}
		if (_stricmp(" fire 4", szInfo + 2) == 0) {
			nButtons[nPlayer][3] = i;
		}
	}
}
// 重载函数-2键
void AssignButtons(const char* system, const char* szName, const char* szInfo, int nPlayer, int i, int nButtons[][2]) {
	if (strcmp(system, "cps1") == 0) {
		if (_stricmp(" fire 1", szInfo + 2) == 0) {
			nButtons[nPlayer][0] = i;
		}
		if (_stricmp(" fire 2", szInfo + 2) == 0) {
			nButtons[nPlayer][1] = i;
		}
	}
}

// 批量设定全部组合键
struct GameInp* AddMacroKeys(struct GameInp* pgi, int nPlayer, int nButtonsTwo[][2], int nButtonsFour[][4], int nPunchInputs[][3], int nKickInputs[][3], const char* system, UINT32& nMacroCount) {
	struct BurnInputInfo bii;
	// 从预设结构体中获得组合键组合
	macro_category* category = NULL;
	size_t num_categories = get_macro_categories_size();
	for (size_t i = 0; i < num_categories; i++) {
		if (strcmp(var_fbneo_macro_categories[i].system, system) == 0) {
			category = &var_fbneo_macro_categories[i];
			break;
		}
	}

	if (!category) {
		// 如果没有找到对应的系统，返回
		return pgi;
	}

	int num_prebindkeys = get_macro_count(system);// 实体键的数量，比如L R L2 R2则是4
	int num_combs = 0;
	while (category->options[0].values[num_combs].value != NULL && strncmp(category->options[0].values[num_combs].value, "Buttons ", 8) == 0) {
		num_combs++;
	}

	// 分配数组内存大小
	const char** macros = (const char**)malloc(num_combs * sizeof(const char*));
	int** button_combinations = (int**)malloc(num_combs * sizeof(int*));

	// 填充组合键的数组和按键值的数组
	for (int i = 0; i < num_combs; i++) {
		macros[i] = category->options[0].values[i].value;
		button_combinations[i] = (int*)malloc(7 * sizeof(int)); // 最大6键+1=7是为了存储 -1 终止符

		int j = 0;
		if (strstr(macros[i], "A") != NULL) button_combinations[i][j++] = 0;
		if (strstr(macros[i], "B") != NULL) button_combinations[i][j++] = 1;
		if (strstr(macros[i], "C") != NULL) button_combinations[i][j++] = 2;
		if (strstr(macros[i], "D") != NULL) button_combinations[i][j++] = 3;
		if (strstr(macros[i], "E") != NULL) button_combinations[i][j++] = 4;
		if (strstr(macros[i], "F") != NULL) button_combinations[i][j++] = 5;
		button_combinations[i][j] = -1; // 终止符
	}


	for (int i = 0; i < num_combs; i++) {
		// 为了确保重复L R L2 R2等可以重复绑定，预设和按键数量一模一样的N个组合键
		// 此处曾做过尝试从预设的RA核心选项环境变量中动态预设组合键
		// 但是因为读取序列问题，在执行这个分配的时候，环境变量值还不能获取到，
		// 故而硬编码和按键数量一模一样的N个组合键*n个player,大约100多个组合键，
		// 实属浪费，但是未能找到其他方案，暂时如此！
		for (int k = 1; k <= num_prebindkeys; k++) { // 创建"buttons AB01"-"buttons AB0n"，也就是L和R等等的数量
			pgi->nInput = GIT_MACRO_AUTO;
			pgi->nType = BIT_DIGITAL;
			pgi->Macro.nMode = 0;
			sprintf(pgi->Macro.szName, "P%i %s%02d", nPlayer + 1, macros[i], k);

			for (int j = 0; j < 7 && button_combinations[i][j] != -1; j++) { // 最大6个按键循环7次(含-1终止符)或者遇到-1占位符停止
				if (nButtonsTwo != NULL) {
					BurnDrvGetInputInfo(&bii, nButtonsTwo[nPlayer][button_combinations[i][j]]); // 传递进来2键
				} else if (nButtonsFour != NULL) {
					BurnDrvGetInputInfo(&bii, nButtonsFour[nPlayer][button_combinations[i][j]]); // 传递进来4键
				} else if (nPunchInputs != NULL && nKickInputs != NULL) {
					if (button_combinations[i][j] < 3) { // ABC时候从拳取键值
						BurnDrvGetInputInfo(&bii, nPunchInputs[nPlayer][button_combinations[i][j]]); // 传递进来6键
					} else { // DEF时候从踢取键值
						BurnDrvGetInputInfo(&bii, nKickInputs[nPlayer][button_combinations[i][j] - 3]);
					}
				}
				pgi->Macro.pVal[j] = bii.pVal;
				pgi->Macro.nVal[j] = 1;
			}

			nMacroCount++;
			pgi++;
		}
	}

	//释放内存
	for (int i = 0; i < num_combs; i++) {
		free(button_combinations[i]);
	}
	free(button_combinations);
	free(macros);

	return pgi;
}