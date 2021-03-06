/*
  Teem: Tools to process and visualize scientific data and images              
  Copyright (C) 2008, 2007, 2006, 2005  Gordon Kindlmann
  Copyright (C) 2004, 2003, 2002, 2001, 2000, 1999, 1998  University of Utah

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
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


#include "../bane.h"

int
main(int argc, char *argv[]) {
  Nrrd *info;
  float sigma;

  AIR_UNUSED(argc);
  if (nrrdLoad(info=nrrdNew(), argv[1], NULL)) {
    fprintf(stderr, "trouble:\n%s\n", biffGet(BANE));
  }
  if (baneSigmaCalc(&sigma, info)) {
    fprintf(stderr, "trouble:\n%s\n", biffGet(BANE));
  }
  printf("%g\n", sigma);

  nrrdNuke(info);
  return 0;
}
