/*
 * Copyright (C) 2019 Harald Welte
 * File  : smpp34_heap.c
 * Author: Harald Welte <laforge@gnumonks.org>
 *
 * This file is part of libsmpp34 (c-open-smpp3.4 library).
 *
 * The libsmpp34 library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "smpp34_heap.h"

static void *smpp34_libc_malloc(size_t sz)
{
	return malloc(sz);
}

static void *smpp34_libc_realloc(void *ptr, size_t sz)
{
	return realloc(ptr, sz);
}

static void smpp34_libc_free(void *ptr)
{
	return free(ptr);
}

static bool allocator_used = false;

static struct smpp34_memory_functions smpp34_allocator = {
	.malloc_fun = smpp34_libc_malloc,
	.realloc_fun = smpp34_libc_realloc,
	.free_fun = smpp34_libc_free,
};

void smpp34_set_memory_functions(const struct smpp34_memory_functions *mf)
{
	if (allocator_used) {
		fprintf(stderr, "%s must be called before first use of smpp34_malloc\n", __func__);
		return;
	}
	smpp34_allocator = *mf;
}

void *smpp34_malloc(size_t sz)
{
	allocator_used = true;
	return smpp34_allocator.malloc_fun(sz);
}

void *smpp34_realloc(void *ptr, size_t sz)
{
	allocator_used = true;
	return smpp34_allocator.realloc_fun(ptr, sz);
}

void smpp34_free(void *ptr)
{
	smpp34_allocator.free_fun(ptr);
}
