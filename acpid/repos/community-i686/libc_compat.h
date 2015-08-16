/*
 *  libc_compat.h - implement defs/macros missing from some libcs
 *
 *  Copyright (C) 1999-2000 Andrew Henroid
 *  Copyright (C) 2001 Sun Microsystems
 *  Portions Copyright (C) 2004 Tim Hockin (thockin@hockin.org)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef LIBC_COMPAT_H__
#define LIBC_COMPAT_H__

/* Evaluate EXPRESSION, and repeat as long as it returns -1 with `errno'
   set to EINTR. This macro is present on glibc/uclibc but may not be in other cases.  */

#ifndef ____GLIBC__
#ifndef TEMP_FAILURE_RETRY
#define TEMP_FAILURE_RETRY(expression) \
  (__extension__                                                             \
    ({ long int __result;                                                    \
       do __result = (long int) (expression);                                \
       while (__result == -1L && errno == EINTR);                            \
       __result; }))
#endif
#endif /* __GLIBC__ */

#endif /* LIBC_COMPAT_H__ */
