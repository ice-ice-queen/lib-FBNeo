#include "macrokeys.h"
#include "retro_common.h"
#include "retro_input.h"
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>


const char* neogeo_macro_desc;
const char* pgm_macro_desc;
const char* cps1_macro_desc;
const char* macro_info_general;

macro_category var_fbneo_macro_categories[3];

// 更新多语言字符串的函数
void set_macro_language_strings(uint32_t nLangcode) {
	// 更新多语言字符串
	const char* macro_desc_shoulder_button_l_options[] = {
		"Shoulder Button L",
		"肩键 L",
		"肩鍵 L"
	};
	const char* macro_desc_shoulder_button_r_options[] = {
		"Shoulder Button R",
		"肩键 R",
		"肩鍵 R"
	};
	const char* macro_desc_shoulder_button_l2_options[] = {
		"Shoulder Button L2",
		"肩键 L2",
		"肩鍵 L2"
	};
	const char* macro_desc_shoulder_button_r2_options[] = {
		"Shoulder Button R2",
		"肩键 R2",
		"肩鍵 R2"
	};
	const char* macro_info_shoulder_button_options[] = {
		"Note: Duplicate binding is ineffective here.\nNeed to check this in <Quick Menu→controls>.",
		"注：重复绑定在此处无效\n需要于<快捷菜单→控制>中操作",
		"注：重複綁定在此處無效\n需要於<快捷選单→控制器>中操作"
	};
	const char* macro_disabled_options[] = {
		"Macro disabled",
		"取消组合键",
		"取消組合鍵"
	};
	const char* neogeo_macro_desc_options[] = {
		"Neogeo Macros",
		"Neogeo 组合键",
		"Neogeo 組合鍵"
	};
	const char* pgm_macro_desc_options[] = {
		"PGM Macros",
		"PGM 组合键",
		"PGM 組合鍵"
	};
	const char* cps1_macro_desc_options[] = {
		"CPS1 Macros",
		"CPS1 组合键",
		"CPS1 組合鍵"
	};
	const char* macro_info_general_options[] = {
		"Set and reload(not reset) game to take effect.",
		"设定完毕后关闭游戏重新进入使其生效",
		"設定完畢後關閉遊戲重新進入使其生效"
	};

	const char* macro_desc_shoulder_button_l = macro_desc_shoulder_button_l_options[nLangcode];
	const char* macro_desc_shoulder_button_r = macro_desc_shoulder_button_r_options[nLangcode];
	const char* macro_desc_shoulder_button_l2 = macro_desc_shoulder_button_l2_options[nLangcode];
	const char* macro_desc_shoulder_button_r2 = macro_desc_shoulder_button_r2_options[nLangcode];
	const char* macro_info_shoulder_button = macro_info_shoulder_button_options[nLangcode];
	const char* macro_disabled = macro_disabled_options[nLangcode];
	neogeo_macro_desc = neogeo_macro_desc_options[nLangcode];
	pgm_macro_desc = pgm_macro_desc_options[nLangcode];
	cps1_macro_desc = cps1_macro_desc_options[nLangcode];
	macro_info_general = macro_info_general_options[nLangcode];

	// 初始化宏选项,目前包含3个系统
	macro_category temp_var_fbneo_macro_categories[3] = {
		{
			"pgm", "pgm_macro",
			{
				{ "fbneo-pgm-macro-l", "L", macro_desc_shoulder_button_l, macro_info_shoulder_button, "Buttons CD",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ACD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-pgm-macro-r", "R", macro_desc_shoulder_button_r, macro_info_shoulder_button, "Buttons AB",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ACD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-pgm-macro-l2", "L2", macro_desc_shoulder_button_l2, macro_info_shoulder_button, "Buttons BC",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ACD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-pgm-macro-r2", "R2", macro_desc_shoulder_button_r2, macro_info_shoulder_button, "Buttons ABC",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ACD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } }
			}
		},
		{
			"neogeo", "neogeo_macro",
			{
				{ "fbneo-neogeo-macro-l", "L", macro_desc_shoulder_button_l, macro_info_shoulder_button, "Buttons CD",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ACD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-neogeo-macro-r", "R", macro_desc_shoulder_button_r, macro_info_shoulder_button, "Buttons AB",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ACD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-neogeo-macro-l2", "L2", macro_desc_shoulder_button_l2, macro_info_shoulder_button, "Buttons BCD",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ACD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-neogeo-macro-r2", "R2", macro_desc_shoulder_button_r2, macro_info_shoulder_button, "Buttons ABC",
					{ { "Buttons AB", NULL }, { "Buttons AC", NULL }, { "Buttons AD", NULL }, { "Buttons BC", NULL }, { "Buttons BD", NULL }, { "Buttons CD", NULL }, { "Buttons ABC", NULL }, { "Buttons ABD", NULL }, { "Buttons ACD", NULL }, { "Buttons BCD", NULL }, { "Buttons ABCD", NULL }, { macro_disabled, NULL }, { NULL, NULL } } }
			}
		},
		{
			"cps1", "cps1_macro",
			{
				{ "fbneo-cps1-macro-l", "L", macro_desc_shoulder_button_l, macro_info_shoulder_button, macro_disabled,
					{ { "Buttons AB", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-cps1-macro-r", "R", macro_desc_shoulder_button_r, macro_info_shoulder_button, macro_disabled,
					{ { "Buttons AB", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-cps1-macro-l2", "L2", macro_desc_shoulder_button_l2, macro_info_shoulder_button, macro_disabled,
					{ { "Buttons AB", NULL }, { macro_disabled, NULL }, { NULL, NULL } } },
				{ "fbneo-cps1-macro-r2", "R2", macro_desc_shoulder_button_r2, macro_info_shoulder_button, "Buttons AB",
					{ { "Buttons AB", NULL }, { macro_disabled, NULL }, { NULL, NULL } } }
			}
		}
	};

	memcpy(var_fbneo_macro_categories, temp_var_fbneo_macro_categories, sizeof(temp_var_fbneo_macro_categories));
}

// 计算 var_fbneo_macro_categories 的大小
size_t get_macro_categories_size() {
	return sizeof(var_fbneo_macro_categories) / sizeof(var_fbneo_macro_categories[0]);
}

// 得到宏按键的数量（目前其实是固定的4=4个肩键，为防止以后变化，做成函数获得）
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

		if ((bIsPgmCartGame && strcmp(var_fbneo_macro_categories[i].system, "pgm") == 0) ||
			(bIsNeogeoCartGame || (nGameType == RETRO_GAME_TYPE_NEOCD)) ||
			(bIsCps1CartGame && strcmp(var_fbneo_macro_categories[i].system, "cps1") == 0)) {
			ProcessMacroContents(var_fbneo_macro_categories[i].system, nbr_macros, num_categories, macrodata);
		}
	}

	return macrodata;
}

// 绑定宏到RA设备
INT32 GameInpDigital2RetroInpKey(struct GameInp* pgi, unsigned port, unsigned id, char *szn, unsigned device, unsigned nInput);
void BindCustomMacroKeys(const CustomMacroKeys& macrosdata, char* description, int nPlayer, unsigned int* nDeviceType, struct GameInp * pgi) {
	for (int i = 0; i < macrosdata.macrocontent.size(); ++i) {
		const char* system = macrosdata.macrocontent[i].system.c_str();
		const char* key = macrosdata.macrocontent[i].macroKey.c_str();
		const char* button = macrosdata.macrocontent[i].button.c_str();

		if (strcmp(key, description) == 0) {
			if (strcmp("R", button) == 0) {
				if (nDeviceType[nPlayer] == RETROPAD_MODERN) {
					GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_3RD_COL_TOP, description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
				} else {
					GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_3RD_COL_BOTTOM, description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
				}
			}
			if (strcmp("L", button) == 0) {
				if (nDeviceType[nPlayer] == RETROPAD_MODERN) {
					GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_4TH_COL_TOP, description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
				} else {
					GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_3RD_COL_TOP, description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
				}
			}
			if (strcmp("R2", button) == 0) {
				if (nDeviceType[nPlayer] == RETROPAD_MODERN) {
					GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_4TH_COL_BOTTOM, description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
				} else {
					GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_JOYPAD_R2, description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
				}
			}
			if (strcmp("L2", button) == 0) {
				if (nDeviceType[nPlayer] == RETROPAD_MODERN) {
					GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_4TH_COL_TOP, description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
				} else {
					GameInpDigital2RetroInpKey(pgi, nPlayer, RETRO_DEVICE_ID_JOYPAD_L2, description, RETRO_DEVICE_JOYPAD, GIT_MACRO_AUTO);
				}
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
// 重载函数-4键
struct GameInp* AddMacroKeys(struct GameInp* pgi, int nPlayer, const char* system, int nButtons[][4], UINT32& nMacroCount) {
	struct BurnInputInfo bii;

	if (strcmp(system, "neogeo") == 0) {
		// 这里注释下面数组作用：
		// 0 对应按钮 A
		// 1 对应按钮 B
		// 2 对应按钮 C
		// 3 对应按钮 D
		// -1 表示停止设置组合键,直接截断

		// Neogeo宏
		const char* macros[] = {"AB", "AC", "AD", "BC", "BD", "CD", "ABC", "ABD", "ACD", "BCD", "ABCD"};
		int button_combinations[][4] = {
			{0, 1, -1}, {0, 2, -1}, {0, 3, -1}, {1, 2, -1}, {1, 3, -1}, {2, 3, -1},
			{0, 1, 2, -1}, {0, 1, 3, -1}, {0, 2, 3, -1}, {1, 2, 3, -1}, {0, 1, 2, 3}
		};

		for (int i = 0; i < sizeof(macros) / sizeof(macros[0]); i++) {
			pgi->nInput = GIT_MACRO_AUTO;
			pgi->nType = BIT_DIGITAL;
			pgi->Macro.nMode = 0;
			sprintf(pgi->Macro.szName, "P%i Buttons %s", nPlayer + 1, macros[i]);

			for (int j = 0; j < 4 && button_combinations[i][j] != -1; j++) {
				BurnDrvGetInputInfo(&bii, nButtons[nPlayer][button_combinations[i][j]]);
				pgi->Macro.pVal[j] = bii.pVal;
				pgi->Macro.nVal[j] = 1;
			}

			nMacroCount++;
			pgi++;
		}
	}

	if (strcmp(system, "pgm") == 0) {
		// PGM宏
		const char* macros[] = {"AB", "AC", "AD", "BC", "BD", "CD", "ABC", "ABD", "ACD", "BCD", "ABCD"};
		int button_combinations[][4] = {
			{0, 1, -1}, {0, 2, -1}, {0, 3, -1}, {1, 2, -1}, {1, 3, -1}, {2, 3, -1},
			{0, 1, 2, -1}, {0, 1, 3, -1}, {0, 2, 3, -1}, {1, 2, 3, -1}, {0, 1, 2, 3}
		};

		for (int i = 0; i < sizeof(macros) / sizeof(macros[0]); i++) {
			pgi->nInput = GIT_MACRO_AUTO;
			pgi->nType = BIT_DIGITAL;
			pgi->Macro.nMode = 0;
			sprintf(pgi->Macro.szName, "P%i Buttons %s", nPlayer + 1, macros[i]);

			for (int j = 0; j < 4 && button_combinations[i][j] != -1; j++) {
				BurnDrvGetInputInfo(&bii, nButtons[nPlayer][button_combinations[i][j]]);
				pgi->Macro.pVal[j] = bii.pVal;
				pgi->Macro.nVal[j] = 1;
			}

			nMacroCount++;
			pgi++;
		}
	}
	return pgi;
}
// 重载函数-2键
struct GameInp* AddMacroKeys(struct GameInp* pgi, int nPlayer, const char* system, int nButtons[][2], UINT32& nMacroCount) {
	struct BurnInputInfo bii;

	if (strcmp(system, "cps1") == 0) {
		// CPS1宏
		const char* macros[] = {"AB"};
		int button_combinations[][4] = {
			{0, 1, -1}
		};

		for (int i = 0; i < sizeof(macros) / sizeof(macros[0]); i++) {
			pgi->nInput = GIT_MACRO_AUTO;
			pgi->nType = BIT_DIGITAL;
			pgi->Macro.nMode = 0;
			sprintf(pgi->Macro.szName, "P%i Buttons %s", nPlayer + 1, macros[i]);

			for (int j = 0; j < 4 && button_combinations[i][j] != -1; j++) {
				BurnDrvGetInputInfo(&bii, nButtons[nPlayer][button_combinations[i][j]]);
				pgi->Macro.pVal[j] = bii.pVal;
				pgi->Macro.nVal[j] = 1;
			}

			nMacroCount++;
			pgi++;
		}
	}
	return pgi;
}