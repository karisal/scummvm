from __future__ import print_function
import sys

if len(sys.argv) < 2:
  print("Usage: python scifx_to_header.py [scifx files] > scifx.cpp")
  sys.exit(-1)

print("""
/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

// NB: This file is AUTO-GENERATED by devtools/sci/scifx/scifx_to_cpp.py
// from devtools/sci/scifx/*.scifx

#include "sci/graphics/helpers.h"
#include "sci/graphics/screen.h"

namespace Sci {
""")

def ModToIndex(m):
  try:
    return M.index(m)
  except ValueError:
    M.append(m)
    return len(M)-1

def PrintMods():
  L = [ "\t{ " + ", ".join( [ "%4d" % (round(128 * (val - 1)),) for val in m ] )  + " }" for m in M ]
  print("static const PaletteMod paletteMods" + GID + "[] = {")
  print( ",\n".join(L) )
  print("};")

def PrintPic(pic):
  print("static void doCustomPic" + GID + "(GfxScreen *screen, int x) {")
  print("\tbyte val = 0;")
  print(pic)
  print("\tif (val)")
  print("\t\tscreen->setCurPaletteMapValue(val);")
  print("}")

def PrintView(view):
  print("static void doCustomView" + GID + "(GfxScreen *screen, int x, int y, int z) {")
  print("\tbyte val = 0;")
  print(view)
  print("\tif (val)")
  print("\t\tscreen->setCurPaletteMapValue(val);")
  print("}")

def ParseList(l, v):
  assert(l[0] == '(')
  e = l.find(")")
  L = l[1:e].split(",")
  tests = ""
  for t in L:
    t = t.strip()
    ell = t.find('..')
    if ell >= 0:
      # interval
      test = "(" + v + " >= " + t[0:ell] + " && " + v + " <= " + t[ell+2:] + ")"
    else:
      test = v + " == " + t
    if tests:
      tests = tests + " || " + test
    else:
      tests = test
  tests = "(" + tests + ")"
  return l[e+1:], tests

def ParseTriple(l):
  assert(l[0] == '(')
  e = l.find(")")
  L = l[1:e].split(",")
  assert(len(L) == 3)
  return L

GIDs = []

for F in sys.argv[1:]:
  pic = ""
  view = ""
  M = [(1.,1.,1.)]
  GID=""

  for l in open(F, "r").readlines():
    l = l.strip()
    if len(l) == 0:
      continue
    if l[0] == '#':
      comment = l[1:].strip()
      pic += "	// " + comment + "\n"
      view += "	// " + comment + "\n"
      continue
    if l[0:6] == "gameid":
      assert(GID == "")
      l = l[6:].strip()
      l = l.strip()
      assert(l[0] == "=")
      assert(l[-1] == ";")
      l = l[1:-1].strip()
      GID = l
      continue
    if l[0:4] == "view":
      ruletype = "view"
      l = l[4:]
    elif l[0:3] == "pic":
      ruletype = "pic"
      l = l[3:]
    else:
      assert(False)
  
    S = ""
    l,t = ParseList(l, "x")
    S = S + "\tif " + t + "\n	"
    if l[0] == "(":
      l,t = ParseList(l, "y")
      S = S + "\tif " + t + "\n		"
    if l[0] == "(":
      l,t = ParseList(l, "z")
      S = S + "\tif " + t + "\n			"
    l = l.strip()
    assert(l[0:2] == "*=")
    assert(l[-1] == ";")
    l = l[2:-1].strip()
    if l[0] == "(":
      val = ParseTriple(l)
      val = (float(v) for v in val)
    else:
      val = (float(l), float(l), float(l))
    S = S + "\tval = " + str(ModToIndex(val)) + ";     // color * " + l + "\n"
    if ruletype == "pic":
      pic = pic + S
    elif ruletype == "view":
      view = view + S

  if GID == "":
    raise ValueError("No gameid specified")

  GIDs.append(GID)

  PrintMods()
  print()
  PrintPic(pic)
  print()
  PrintView(view)
  print()

print("void setupCustomPaletteMods(GfxScreen *screen) {")
print("\tswitch (g_sci->getGameId()) {")
for GID in GIDs:
  print("\tcase GID_" + GID + ":")
  print("\t\tscreen->setPaletteMods(paletteMods" + GID + ", ARRAYSIZE(paletteMods" + GID + "));")
  print("\t\tbreak;")
print("\tdefault:")
print("\t\tbreak;")
print("\t}")
print("}")
print()

print("void doCustomViewPalette(GfxScreen *screen, int x, int y, int z) {")
print("\tswitch (g_sci->getGameId()) {")
for GID in GIDs:
  print("\tcase GID_" + GID + ":")
  print("\t\tdoCustomView" + GID + "(screen, x, y, z);")
  print("\t\tbreak;")
print("\tdefault:")
print("\t\tbreak;")
print("\t}")
print("}")
print()

print("void doCustomPicPalette(GfxScreen *screen, int x) {")
print("\tswitch (g_sci->getGameId()) {")
for GID in GIDs:
  print("\tcase GID_" + GID + ":")
  print("\t\tdoCustomPic" + GID + "(screen, x);")
  print("\t\tbreak;")
print("\tdefault:")
print("\t\tbreak;")
print("\t}")
print("}")
print()

print("}")
