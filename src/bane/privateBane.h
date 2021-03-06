/*
  Teem: Tools to process and visualize scientific data and images              
  Copyright (C) 2008, 2007, 2006, 2005  Gordon Kindlmann
  Copyright (C) 2004, 2003, 2002, 2001, 2000, 1999, 1998  University of Utah

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public License
  (LGPL) as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  The terms of redistributing and/or modifying this software also
  include exceptions to the LGPL that facilitate static linking.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef BANE_PRIVATE_HAS_BEEN_INCLUDED
#define BANE_PRIVATE_HAS_BEEN_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/* hvol.c */
extern int _baneAxisCheck(baneAxis *axis);

#define BANE_GKMS_CMD(name, info) \
unrrduCmd baneGkms_##name##Cmd = { #name, info, baneGkms_##name##Main }

/* USAGE, PARSE
   all copied from unrrdu/privateUnrrdu.h */
#define USAGE(info) \
  if (!argc) { \
    hestInfo(stderr, me, (info), hparm); \
    hestUsage(stderr, opt, me, hparm); \
    hestGlossary(stderr, opt, hparm); \
    airMopError(mop); \
    return 2; \
  }

#define PARSE() \
  if ((pret=hestParse(opt, argc, argv, &perr, hparm))) { \
    if (1 == pret) { \
      fprintf(stderr, "%s: %s\n", me, perr); free(perr); \
      hestUsage(stderr, opt, me, hparm); \
      airMopError(mop); \
      return 2; \
    } else { \
      /* ... like tears ... in rain. Time ... to die. */ \
      exit(1); \
    } \
  }

#ifdef __cplusplus
}
#endif

#endif /* BANE_PRIVATE_HAS_BEEN_INCLUDED */
