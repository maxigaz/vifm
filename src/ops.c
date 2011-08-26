/* vifm
 * Copyright (C) 2011 xaizek.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */

#include "config.h"
#include "macros.h"
#include "menus.h"
#include "undo.h"

#include "ops.h"

static int op_remove(void *data, const char *src, const char *dst);
static int op_delete(void *data, const char *src, const char *dst);
static int op_copy(void *data, const char *src, const char *dst);
static int op_move(void *data, const char *src, const char *dst);
static int op_chown(void *data, const char *src, const char *dst);
static int op_chgrp(void *data, const char *src, const char *dst);
static int op_chmod(void *data, const char *src, const char *dst);
static int op_asymlink(void *data, const char *src, const char *dst);
static int op_rsymlink(void *data, const char *src, const char *dst);

typedef int (*op_func)(void *data, const char *src, const char *dst);

static op_func op_funcs[] = {
	NULL,        /* OP_NONE */
	op_remove,   /* OP_REMOVE */
	op_delete,   /* OP_DELETE */
	op_copy,     /* OP_COPY */
	op_move,     /* OP_MOVE */
	op_move,     /* OP_MOVETMP0 */
	op_move,     /* OP_MOVETMP1 */
	op_move,     /* OP_MOVETMP2 */
	op_chown,    /* OP_CHOWN */
	op_chgrp,    /* OP_CHGRP */
	op_chmod,    /* OP_CHMOD */
	op_asymlink, /* OP_ASYMLINK */
	op_rsymlink, /* OP_RSYMLINK */
};

static int _gnuc_unused op_funcs_size_guard[
	(ARRAY_LEN(op_funcs) == OP_COUNT) ? 1 : -1
];

static int rm_rf_confirmed;

int
perform_operation(enum OPS op, void *data, const char *src, const char *dst)
{
	if(op == OP_NONE)
	{
		rm_rf_confirmed = 0;
		return 0;
	}
	return op_funcs[op](data, src, dst);
}

static int
op_remove(void *data, const char *src, const char *dst)
{
	if(cfg.confirm && !rm_rf_confirmed)
	{
		rm_rf_confirmed = query_user_menu("Permanent deletion",
				"Are you sure? If you want to see file names use :undolist! command");
		if(!rm_rf_confirmed)
			return SKIP_UNDO_REDO_OPERATION;
	}
	/* TODO: write code */
	return 0;
}

static int
op_delete(void *data, const char *src, const char *dst)
{
	/* TODO: write code */
	return 0;
}

static int
op_copy(void *data, const char *src, const char *dst)
{
	/* TODO: write code */
	return 0;
}

static int
op_move(void *data, const char *src, const char *dst)
{
	/* TODO: write code */
	return 0;
}

static int
op_chown(void *data, const char *src, const char *dst)
{
	/* TODO: write code */
	return 0;
}

static int
op_chgrp(void *data, const char *src, const char *dst)
{
	/* TODO: write code */
	return 0;
}

static int
op_chmod(void *data, const char *src, const char *dst)
{
	/* TODO: write code */
	return 0;
}

static int
op_asymlink(void *data, const char *src, const char *dst)
{
	/* TODO: write code */
	return 0;
}

static int
op_rsymlink(void *data, const char *src, const char *dst)
{
	/* TODO: write code */
	return 0;
}

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 : */