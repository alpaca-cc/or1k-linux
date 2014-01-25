/*
 * OpenRISC Linux
 *
 * Linux architectural port borrowing liberally from similar works of
 * others.  All original copyrights apply as per the original source
 * declaration.
 *
 * OpenRISC implementation:
 * Copyright (C) 2003 Matjaz Breskvar <phoenix@bsemi.com>
 * Copyright (C) 2010-2011 Jonas Bonn <jonas@southpole.se>
 * et al.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#define __ARCH_HAVE_MMU

#define sys_mmap2 sys_mmap_pgoff

#define __ARCH_WANT_SYS_FORK
#define __ARCH_WANT_SYS_CLONE

#include <asm-generic/unistd.h>

/*
 * uint32 sys_or1k_atomic(uint32 op, ...)
 *
 * uint32 sys_or1k_atomic(SWAP, void *ptr1, void *ptr2)
 *   Atomically swap the values in pointers 1 and 2.
 *
 * uint32 sys_or1k_atomic(CMPXCHG, uint32 *mem, uint32 old, uint32 new)
 *   Writes new to *mem if *mem == old. Returns old *mem.
 *
 * uint32 sys_or1k_atomic(XCHG, uint32 *mem, uint32 new)
 *   Store NEW in *MEM and return the old value.
 *
 * uint32 sys_or1k_atomic(ADD, uint32 *mem, uint32 val)
 *   Add VAL to *MEM and return the old value of *MEM.
 *
 * uint32 sys_or1k_atomic(DECPOS, uint32 *mem)
 *   Decrement *MEM if it is > 0, and return the old value.
 *
 * uint32 sys_or1k_atomic(AND, uint32 *mem, uint32 mask)
 *   Atomically *mem &= mask and return the old value of *mem.
 *
 * uint32 sys_or1k_atomic(OR, uint32 *mem, uint32 mask)
 *   Atomically *mem |= mask and return the old value of *mem.
 *
 * uint32 sys_or1k_atomic(UMAX, uint32 *mem, uint32 max)
 *   If *mem < val, set *mem = max. Returns old value of *mem.
 *
 * uint32 sys_or1k_atomic(UMIN, uint32 *mem, uint32 min)
 *   If *mem > val, set *mem = min. Returns old value of *mem.
 */
#define SYS_OR1K_ATOMIC_SWAP	1
#define SYS_OR1K_ATOMIC_CMPXCHG	2
#define SYS_OR1K_ATOMIC_XCHG	3
#define SYS_OR1K_ATOMIC_ADD	4
#define SYS_OR1K_ATOMIC_DECPOS	5
#define SYS_OR1K_ATOMIC_AND	6
#define SYS_OR1K_ATOMIC_OR	7
#define SYS_OR1K_ATOMIC_UMAX	8
#define SYS_OR1K_ATOMIC_UMIN	9
#define SYS_OR1K_ATOMIC_COUNT	10

#define __NR_or1k_atomic __NR_arch_specific_syscall
__SYSCALL(__NR_or1k_atomic, sys_or1k_atomic)
