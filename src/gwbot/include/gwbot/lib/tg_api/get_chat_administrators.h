// SPDX-License-Identifier: GPL-2.0-only
/*
 *  src/gwbot/include/gwbot/lib/tg_api/get_chat_administrators.h
 *
 *  Get chat administrators API for GNUWeebBot
 *
 *  Copyright (C) 2021  Ammar Faizi
 */

#ifndef GWBOT__LIB__TG_API__GET_CHAT_ADMINISTRATORS_H
#define GWBOT__LIB__TG_API__GET_CHAT_ADMINISTRATORS_H

#include <gwbot/lib/tg_api.h>
#include <json-c/json.h>

int tga_get_chat_admins(tga_handle_t *handle, int64_t chat_id);
int parse_tga_admins(json_object *obj, struct tga_chat_member **admins,
		     size_t *admin_cp);

#endif /* #ifndef GWBOT__LIB__TG_API__GET_CHAT_ADMINISTRATORS_H */
