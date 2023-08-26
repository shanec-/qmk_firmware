// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define XXX KC_NO

#if defined (KEYBOARD_sofle)

#define MIRYOKU_LAYERMAPPING_BASE( \
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT(\
XXX, XXX, XXX, XXX, XXX,                XXX,                                            XXX, XXX, XXX, XXX, XXX, XXX,\
XXX, K00, K01, K02, K03,                K04,                                            K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13,                K14,                                            K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23,                K24,                XXX,                        XXX,                K25, K26, K27, K28, K29, XXX,\
          XXX, XXX, LT(U_MEDIA,KC_TAB), LT(U_NAV,KC_ESC),   LT(U_MOUSE,KC_ENT),         LT(U_NUM,KC_SPC),   K36, K37, XXX, XXX\
)

#endif


LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),   \
LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
