/**
 * @file src/mod.cpp
 *
 * @brief Implementation of the command packets.
 *
 * License: BSD
 *   https://raw.github.com/yujinrobot/kobuki_core/hydro-devel/kobuki_driver/LICENSE
**/

/*****************************************************************************
** Includes
*****************************************************************************/

#include "../include/mod.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace kobuki
{

/*****************************************************************************
** Static variables initialization
*****************************************************************************/

const unsigned char Cart_Command::header0 = 0xaa;
const unsigned char Cart_Command::header1 = 0x55;

/*****************************************************************************
** Implementation [Command Generators]
*****************************************************************************/


/*
 * Set one of the digital out pins available to the user.
 *
 * The LED arrays, bits 0~5
 * - LED Red        off: 0x0000, lit: 0x0001, blink(0.5s): 0x0002, blink(2s): 0x0003
 * - LED Yellow     off: 0x0000, lit: 0x0004, blink(0.5s): 0x0008, blink(2s): 0x000C
 * - LED Blue       off: 0x0000, lit: 0x0010, blink(0.5s): 0x0020, blink(2s): 0x0030
 * Melody tone, bits 6~7
 * - tone           off: 0x0000, on : 0x0040
 * - onRoute tone: 0x0000, warning tone: 0x0080
 * Speed Control, bit 9
 * - Control_1: 0x0000, Control_2: 0x0200
 * Error Control, bit 10
 * - indef value: 0x0000, error reset: 0x0400
 * Movement Control
 * - normal operation: 0x0000, emergency stop: 0x0800
 * Dendo pin
 * - fall:  0x0000, rise: 0x1000
 * Electric brakes
 * - released:  0x0000, trigered: 0x2000
 * Robot Modes transition
 * - standby: 0x0000, operational: 0x4000, charging:  0xC000
 *
 * @todo could use far better documentation here/example here.
 *
 * @param digital_output : mask and value to send
 * @param current_data : need to store settings as the gp_output command is a combo command
 * @return Command : the command to send down the wire.
 */

<<<<<<< HEAD
Command Command::Set_KeyCart_DigitalOutput(const DigitalOutput &digital_output, Cart_Command::Data &current_data)
{
  uint16_t values = 0x0000;
//  uint16_t clear_mask = 0xfff0;
  uint16_t clear_mask = 0x0000;
=======
Command Command::Set_KeyCart_DigitalOutput(const DigitalOutput &digital_output, Command::Data &current_data)
{
  uint16_t values = 0x0000;
  uint16_t clear_mask = 0xfff0;
>>>>>>> d84705cdf5b71649f6dc44a1036d4c7a19d8d6b6

  for ( unsigned int i = 0; i < 4; ++i ) {
    if ( digital_output.mask[i] ) {
      if ( digital_output.values[i] ) {
        values |= ( 1 << i );
      }
    } else {
      clear_mask |= ( 1 << i ); // don't clear this bit, so set a 1 here
    }
  }
  current_data.key_gpout = (current_data.key_gpout & clear_mask) | values;
  Command outgoing;
  outgoing.data = current_data;
  outgoing.data.command = Command::SetDigitalOut;
  return outgoing;
}


<<<<<<< HEAD
=======


>>>>>>> d84705cdf5b71649f6dc44a1036d4c7a19d8d6b6
//void KeyCartRos::subscribeKeyCartDigitalOutputCommand(const kobuki_msgs::DigitalOutputConstPtr msg){
//  DigitalOutput digital_output;
//  for ( unsigned int i = 0; i < 4; ++i ) {
//    digital_output.values[i] = msg->values[i];
//    digital_output.mask[i] = msg->mask[i];
//  }
//  kobuki.setDigitalOutput(digital_output);
//  return;

//}

//void subscribeKeyCartDigitalOutputCommand(const kobuki_msgs::DigitalOutputConstPtr msg)//
//{

//}


} // namespace kobuki
