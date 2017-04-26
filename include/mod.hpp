/**
 * @file src/mod.cpp
 *
 * @brief Implementation of the command packets.
 *
 * License: BSD
 *   https://raw.github.com/yujinrobot/kobuki_core/hydro-devel/kobuki_driver/LICENSE
**/
/*****************************************************************************
** Preprocessor
*****************************************************************************/

#ifndef KEYCART_COMMAND_DATA_HPP__
#define KEYCART_COMMAND_DATA_HPP__

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ecl/containers.hpp>
#include <ecl/config/macros.hpp>
#include <ecl/config/ecl.hpp>
#include <kobuki_msgs/DigitalOutput.h>

//#include "packet_handler/payload_base.hpp"
//#include "modules/led_array.hpp"
//#include "modules.hpp"
//#include "macros.hpp"

/*****************************************************************************
** Declspecs
*****************************************************************************/

/*
 * Import/exports symbols for the library
 */
#ifdef ECL_HAS_SHARED_LIBS // ecl is being built around shared libraries
  #ifdef kobuki_EXPORTS // we are building a shared lib/dll
    #define kobuki_PUBLIC ECL_HELPER_EXPORT
    #define EXP_TEMPLATE
  #else // we are using shared lib/dll
    #define kobuki_PUBLIC ECL_HELPER_IMPORT
    #define EXP_TEMPLATE extern
  #endif
  #define kobuki_LOCAL ECL_HELPERS_LOCAL
#else // ecl is being built around static libraries
  #define kobuki_PUBLIC
  #define kobuki_LOCAL
  #define EXP_TEMPLATE
#endif 

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace KeyCart
{

class KeyCart_PUBLIC Cart_Command : public packet_handler::payloadBase
{
public:
    typedef ecl::PushAndPop<unsigned char> Buffer;
    typedef ecl::Stencil< Buffer > BufferStencil;

    enum Name
    {
        Set_KeyCart_DigitalOut = 20;
    };

    void subscribeKeyCartDigitalOutputCommand(const kobuki_msgs::DigitalOutputConstPtr);

private:
    static const unsigned char header0;
    static const unsigned char header1;



}

class  KeyCartRos
{
public:
    /*********************
    ** Ros Comms
    **********************/
    ros::Subscriber keycart_digital_output_subscriber;

private:

}

}