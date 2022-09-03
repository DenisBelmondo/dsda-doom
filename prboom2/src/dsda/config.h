//
// Copyright(C) 2020 by Ryan Krafnick
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	DSDA Config
//

#ifndef __DSDA_CONFIG__
#define __DSDA_CONFIG__

#include <stdio.h>

#include "doomtype.h"

typedef enum {
  dsda_config_none,
  dsda_config_realtic_clock_rate,
  dsda_config_count,
} dsda_config_identifier_t;

typedef enum {
  dsda_config_int,
  dsda_config_string,
} dsda_config_type_t;

typedef union {
  int v_int;
  char* v_string;
} dsda_config_value_t;

typedef struct {
  const char* name;
  dsda_config_type_t type;
  int lower_limit;
  int upper_limit;
  dsda_config_value_t default_value;
  int strict_value;
  void (*onUpdate)(void);
  dsda_config_value_t transient_value;
  dsda_config_value_t persistent_value;
} dsda_config_t;

void dsda_InitConfig(void);
dboolean dsda_ReadConfig(const char* name, const char* string_param, int int_param);
void dsda_WriteConfig(dsda_config_identifier_t id, int key_length, FILE* file);
int dsda_ToggleConfig(dsda_config_identifier_t id, dboolean persist);
int dsda_CycleConfig(dsda_config_identifier_t id, dboolean persist);
int dsda_UpdateIntConfig(dsda_config_identifier_t id, int value, dboolean persist);
const char* dsda_UpdateStringConfig(dsda_config_identifier_t id, const char* value, dboolean persist);
int dsda_IntConfig(dsda_config_identifier_t id);
int dsda_PersistentIntConfig(dsda_config_identifier_t id);
const char* dsda_StringConfig(dsda_config_identifier_t id);
const char* dsda_PersistentStringConfig(dsda_config_identifier_t id);

#endif
