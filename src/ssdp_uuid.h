/*
 * Copyright (C) 2015 AIRTAME
 *
 * This file is part of airtme-cli.
 *
 *   Airtame-cli is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Airtame-cli is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Airtame-cli.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __H_SSDP_UUID__
#define __H_SSDP_UUID__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <uuid/uuid.h>
#endif


int airtame_load_uuid(char *uuid, int *len);
int airtame_save_uuid(char *uuid);
void airtame_generate_uuid(char *uuid, int *len);

#endif
