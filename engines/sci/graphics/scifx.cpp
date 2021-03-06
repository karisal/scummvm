
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

static const PaletteMod paletteModsLSL2[] = {
	{    0,    0,    0 },
	{   32,   32,   32 },
	{  -13,  -13,  -13 },
	{  -38,  -38,  -38 },
	{   26,   26,   26 },
	{   13,   13,   13 },
	{  -51,  -51,  -51 },
	{  -13,    0,    0 },
	{  -64,  -64,  -64 },
	{  -26,  -26,  -26 },
	{  -51,  -13,    0 },
	{  -13,    0,   13 },
	{   38,   38,   38 },
	{  -19,  -19,  -19 },
	{   64,   64,   64 },
	{  -77,  -77,  -77 },
	{   13,    0,    0 }
};

static void doCustomPicLSL2(GfxScreen *screen, int x) {
	byte val = 0;
	// LSL2 per-resource palette configuration
	// Copyright (C) 2006 Matt Hargett
	// ego
	if (x == 28 || x == 99)
		val = 1;     // color * 1.25
	if (x == 96)
		val = 5;     // color * 1.1
	if (x == 92 || x == 93 || x == 18 || (x >= 20 && x <= 26) || x == 134 || x == 40 || x == 50 || (x >= 76 && x <= 82) || x == 181)
		val = 2;     // color * 0.9
	if ((x >= 114 && x <= 118) || x == 125 || (x >= 11 && x <= 17) || x == 19 || x == 43 || (x >= 70 && x <= 74) || x == 44 || x == 86 || (x >= 101 && x <= 104) || x == 32 || x == 33 || x == 35 || x == 36 || x == 95)
		val = 13;     // color * 0.85
	// titles
	if (x == 10 || x == 90 || x == 91)
		val = 15;     // color * 0.4
	// misc effects

	if (val)
		screen->setCurPaletteMapValue(val);
}

static void doCustomViewLSL2(GfxScreen *screen, int x, int y, int z) {
	byte val = 0;
	// LSL2 per-resource palette configuration
	// Copyright (C) 2006 Matt Hargett
	// ego
	if (x == 507 || x == 155 || x == 161 || x == 163 || x == 170 || x == 197 || x == 198 || x == 431 || x == 432 || (x >= 145 && x <= 159) || (x >= 131 && x <= 141) || x == 191 || x == 104 || x == 244 || x == 215 || x == 217 || x == 219 || x == 100 || x == 101 || x == 110 || x == 111 || x == 112 || x == 113 || x == 192 || x == 193 || x == 604 || (x >= 704 && x <= 706) || x == 717 || x == 718 || x == 818 || x == 819 || x == 822 || x == 823 || x == 824 || x == 831 || x == 832 || x == 833 || x == 834 || x == 835)
		val = 1;     // color * 1.25
	if (x == 218)
		if (y == 3)
			val = 1;     // color * 1.25
	if (x == 218)
		if ((y >= 0 && y <= 2))
			val = 2;     // color * 0.9
	if (x == 820)
		if (y == 0 || y == 1)
			val = 2;     // color * 0.9
	if (x == 227 || x == 224 || x == 206 || x == 208 || x == 209 || x == 220)
		val = 2;     // color * 0.9
	if (x == 221 || x == 254 || x == 252)
		val = 3;     // color * 0.7
	if (x == 820)
		if ((y >= 2 && y <= 4))
			val = 4;     // color * 1.2
	if (x == 816)
		if (y == 5)
			if (z == 0)
				val = 4;     // color * 1.2
	if (x == 516 || x == 509 || (x >= 501 && x <= 504) || (x >= 401 && x <= 403) || x == 408 || x == 409 || x == 411 || x == 413 || x == 414 || x == 417 || x == 418 || x == 419 || x == 430 || x == 310 || x == 302 || x == 303 || (x >= 120 && x <= 124) || x == 232 || x == 223 || x == 208 || x == 710 || x == 716 || x == 714)
		val = 5;     // color * 1.1
	if ((x >= 434 && x <= 438) || x == 311 || x == 313 || x == 316 || x == 319 || x == 321 || x == 323 || x == 324 || (x >= 306 && x <= 309) || x == 248 || x == 245 || x == 246 || (x >= 233 && x <= 235) || x == 237 || x == 226 || x == 229 || x == 222 || x == 203 || x == 204 || x == 205 || x == 600 || x == 525 || x == 524 || x == 523 || x == 522 || x == 520 || x == 602 || x == 605 || x == 608 || (x >= 707 && x <= 708))
		val = 4;     // color * 1.2
	if (x == 305)
		if (y == 4)
			val = 5;     // color * 1.1
	if (x == 305)
		if ((y >= 0 && y <= 3))
			val = 6;     // color * 0.6
	if (x == 661)
		if (y == 0 || y == 1 || (y >= 3 && y <= 5))
			val = 4;     // color * 1.2
	if (x == 661)
		if (y == 2)
			val = 3;     // color * 0.7
	if (x == 711 || x == 712 || x == 713 || x == 60)
		val = 7;     // color * (0.9, 1.0, 1.0)
	if (x == 816)
		if ((y >= 0 && y <= 4))
			val = 2;     // color * 0.9
	if (x == 506 || x == 508 || x == 500 || x == 252 || x == 803 || x == 804 || x == 433)
		val = 6;     // color * 0.6
	if (x == 513)
		if ((y >= 0 && y <= 5))
			val = 8;     // color * 0.5
	if ((x >= 240 && x <= 243) || x == 701 || x == 722)
		val = 9;     // color * 0.8
	if (x == 700)
		if (y == 1)
			val = 10;     // color * (0.6, 0.9, 1.0)
	if (x == 610 || x == 611)
		val = 11;     // color * (0.9, 1.0, 1.1)
	if (x == 607)
		if (y == 1)
			val = 9;     // color * 0.8
	if (x == 253 || x == 228 || x == 247 || x == 300 || x == 326)
		val = 9;     // color * 0.8
	if (x == 412)
		val = 12;     // color * 1.3
	// titles
	if (x == 800 || x == 801)
		val = 14;     // color * 1.5
	// misc effects
	if (x == 702)
		val = 16;     // color * (1.1, 1.0, 1.0)
	if (x == 519)
		val = 9;     // color * 0.8
	if (x == 200)
		if (y == 0)
			val = 3;     // color * 0.7
	if (x == 201 || x == 202)
		val = 9;     // color * 0.8

	if (val)
		screen->setCurPaletteMapValue(val);
}

static const PaletteMod paletteModsSQ3[] = {
	{    0,    0,    0 },
	{   32,   32,   32 },
	{   19,   19,   19 },
	{  -64,  -64,  -64 },
	{  -13,  -13,  -13 },
	{  -26,  -26,  -26 },
	{  -32,  -32,  -32 },
	{   26,   26,   26 },
	{  -38,  -38,  -38 },
	{  -51,  -51,  -51 },
	{   13,   13,   13 },
	{   64,   64,   64 }
};

static void doCustomPicSQ3(GfxScreen *screen, int x) {
	byte val = 0;
	// SQ3 per-resource palette configuration
	// Copyright (C) 2006 Matt Hargett
	// ego
	// ego on garbage lifter -- lighten but not so as to make the lifter be obviously weird
	// ego's shadow
	// ego's hands controlling robot
	if (x == 96)
		val = 2;     // color * 1.15
	// peeking at scumsoft
	if (x == 81 || x == 82)
		val = 2;     // color * 1.15
	// lifted by robot
	if (x == 430)
		val = 2;     // color * 1.15
	// computer controls
	if (x == 17 || x == 18 || (x >= 162 && x <= 164) || x == 170 || x == 180 || x == 191 || x == 300)
		val = 6;     // color * 0.75
	// title screen
	if (x == 1)
		val = 4;     // color * 0.9
	if (x == 926)
		val = 4;     // color * 0.9
	// humans(?)
	if (x == 117)
		val = 2;     // color * 1.15
	// ships, planets, and robots
	if ((x >= 205 && x <= 209) || (x >= 112 && x <= 115))
		val = 4;     // color * 0.9
	if ((x >= 60 && x <= 72))
		val = 4;     // color * 0.9
	if (x == 153)
		val = 5;     // color * 0.8
	if (x == 690)
		val = 4;     // color * 0.9
	// in the garbage scow
	if ((x >= 1 && x <= 20))
		val = 6;     // color * 0.75
	if (x == 157)
		val = 9;     // color * 0.6
	// rats
	// guys from andromeda
	// misc text bubbles, effects, etc

	if (val)
		screen->setCurPaletteMapValue(val);
}

static void doCustomViewSQ3(GfxScreen *screen, int x, int y, int z) {
	byte val = 0;
	// SQ3 per-resource palette configuration
	// Copyright (C) 2006 Matt Hargett
	// ego
	if (x == 0 || x == 8 || x == 11 || x == 12 || x == 14 || x == 68 || x == 17 || (x >= 22 && x <= 26) || x == 32 || x == 35 || x == 751 || x == 289 || x == 288 || x == 261 || x == 260 || x == 257 || x == 213 || x == 199 || x == 193 || x == 192 || x == 138 || x == 137 || x == 134 || x == 109 || x == 110 || x == 113 || x == 114 || x == 117 || x == 122 || x == 123 || x == 100 || x == 99 || x == 97 || x == 95 || x == 89 || x == 88 || x == 87 || x == 85 || x == 84 || x == 82 || x == 76 || x == 68 || x == 63 || x == 104)
		val = 1;     // color * 1.25
	if (x == 136)
		val = 2;     // color * 1.15
	if (x == 106)
		if (y == 4 || y == 5 || y == 9)
			val = 1;     // color * 1.25
	if (x == 105)
		if (y == 0 || y == 1)
			val = 1;     // color * 1.25
	// ego on garbage lifter -- lighten but not so as to make the lifter be obviously weird
	if (x == 13)
		if (y == 0)
			if (z == 2)
				val = 2;     // color * 1.15
	if (x == 31)
		val = 2;     // color * 1.15
	if (x == 15)
		if (y == 3)
			if (z == 0)
				val = 1;     // color * 1.25
	if (x == 16 || x == 19)
		if (y == 0)
			val = 1;     // color * 1.25
	if (x == 57)
		if ((y >= 5 && y <= 6))
			val = 1;     // color * 1.25
	if (x == 21)
		if (y == 1)
			val = 1;     // color * 1.25
	// ego's shadow
	if (x == 7 || x == 18)
		val = 3;     // color * 0.5
	if ((x >= 6 && x <= 8) || x == 18)
		val = 4;     // color * 0.9
	if (x == 901)
		val = 1;     // color * 1.25
	if (x == 751)
		val = 1;     // color * 1.25
	if (x == 750)
		if (y == 1)
			val = 1;     // color * 1.25
	if (x == 92)
		if (y == 4)
			val = 1;     // color * 1.25
	if (x == 83)
		if (y == 0)
			val = 1;     // color * 1.25
	if (x == 83)
		if (y == 1)
			if (z == 2)
				val = 2;     // color * 1.15
	if (x == 83)
		if (y == 2)
			if (z == 2)
				val = 2;     // color * 1.15
	if (x == 78)
		if (y == 3)
			val = 1;     // color * 1.25
	if (x == 64)
		if (y == 2 || y == 3)
			val = 1;     // color * 1.25
	// ego's hands controlling robot
	// peeking at scumsoft
	// lifted by robot
	// computer controls
	if (x == 40 || x == 41 || x == 42 || x == 149 || x == 146 || x == 141 || x == 151 || x == 152)
		val = 5;     // color * 0.8
	if (x == 70 || x == 2)
		val = 4;     // color * 0.9
	// title screen
	if (x == 900)
		val = 4;     // color * 0.9
	// humans(?)
	if (x == 593 || x == 93 || x == 103 || (x >= 131 && x <= 133) || x == 210 || x == 130 || x == 115)
		val = 7;     // color * 1.2
	if (x == 116)
		if ((y >= 1 && y <= 2))
			val = 7;     // color * 1.2
	// ships, planets, and robots
	if (x == 39)
		val = 4;     // color * 0.9
	if (x == 1)
		val = 6;     // color * 0.75
	if (x == 96)
		val = 4;     // color * 0.9
	if (x == 77)
		if ((y >= 0 && y <= 2))
			val = 8;     // color * 0.7
	if (x == 259)
		val = 2;     // color * 1.15
	// in the garbage scow
	if (x == 20)
		if (y == 0)
			val = 3;     // color * 0.5
	// rats
	if (x == 15)
		if (y == 0 || y == 1)
			val = 9;     // color * 0.6
	if (x == 34)
		val = 9;     // color * 0.6
	// guys from andromeda
	if (x == 128)
		val = 4;     // color * 0.9
	if (x == 601 || x == 602)
		val = 4;     // color * 0.9
	// misc text bubbles, effects, etc
	if (x == 94)
		val = 10;     // color * 1.1
	if (x == 91 || x == 73)
		val = 11;     // color * 1.5
	if (x == 57)
		if (y == 3 || y == 4)
			val = 11;     // color * 1.5
	if (x == 15)
		if (y == 4)
			val = 11;     // color * 1.5
	if (x == 64)
		if (y == 0)
			val = 11;     // color * 1.5
	if (x == 71)
		if (y == 8)
			val = 11;     // color * 1.5
	if (x == 10)
		if (y == 6)
			val = 11;     // color * 1.5

	if (val)
		screen->setCurPaletteMapValue(val);
}

void setupCustomPaletteMods(GfxScreen *screen) {
	switch (g_sci->getGameId()) {
	case GID_LSL2:
		screen->setPaletteMods(paletteModsLSL2, ARRAYSIZE(paletteModsLSL2));
		break;
	case GID_SQ3:
		screen->setPaletteMods(paletteModsSQ3, ARRAYSIZE(paletteModsSQ3));
		break;
	default:
		break;
	}
}

void doCustomViewPalette(GfxScreen *screen, int x, int y, int z) {
	switch (g_sci->getGameId()) {
	case GID_LSL2:
		doCustomViewLSL2(screen, x, y, z);
		break;
	case GID_SQ3:
		doCustomViewSQ3(screen, x, y, z);
		break;
	default:
		break;
	}
}

void doCustomPicPalette(GfxScreen *screen, int x) {
	switch (g_sci->getGameId()) {
	case GID_LSL2:
		doCustomPicLSL2(screen, x);
		break;
	case GID_SQ3:
		doCustomPicSQ3(screen, x);
		break;
	default:
		break;
	}
}

}
