/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define ORYX_CONFIGURATOR

// how long in ms before a tap becomes a hold
#define TAPPING_TERM 150
// better handling of fast mod taps
#define PERMISSIVE_HOLD
// holding a dual tapping key outside timeout still sends
// tapping key if no other key is pressed
#define RETRO_TAPPING
// how long in ms a combo times out
#define COMBO_TERM 10
// backlight indicators for current layer
#define RGBLIGHT_LAYERS

// combined mouse accel+constant mode
#define MK_COMBINE

#define LEADER_TIMEOUT 300
