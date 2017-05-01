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

#include <ros/ros.h>
#include "../../../_cart_core_/kobuki_driver/include/kobuki_driver/packet_handler/payload_base.hpp"
//#include "../../../_cart_/kobuki_node/include/kobuki_node/kobuki_ros.hpp"

//#include "modules/led_array.hpp"
//#include "modules.hpp"
//#include "macros.hpp"
#include <functional>

/*****************************************************************************
** Declspecs
*****************************************************************************/

/*
 * Import/exports symbols for the library
 */
/*#ifdef ECL_HAS_SHARED_LIBS // ecl is being built around shared libraries
  #ifdef KeyCart_EXPORTS // we are building a shared lib/dll
    #define KeyCart_PUBLIC ECL_HELPER_EXPORT
    #define EXP_TEMPLATE
  #else // we are using shared lib/dll
    #define KeyCart_PUBLIC ECL_HELPER_IMPORT
    #define EXP_TEMPLATE extern
  #endif
  #define KeyCart_LOCAL ECL_HELPERS_LOCAL
#else // ecl is being built around static libraries
  #define KeyCart_PUBLIC
  #define KeyCart_LOCAL
  #define EXP_TEMPLATE
#endif 
*/

/*****************************************************************************
** Namespace
*****************************************************************************/
namespace kobuki
{

   // ros::Subscriber keycart_digital_output_subscriber;


<<<<<<< HEAD
class KeyCart_PUBLIC Cart_Command : public packet_handler::payloadBase
=======
class kobuki_PUBLIC Cart_Command : public packet_handler::payloadBase
>>>>>>> d84705cdf5b71649f6dc44a1036d4c7a19d8d6b6
{
public:
    typedef ecl::PushAndPop<unsigned char> Buffer;
    typedef ecl::Stencil< Buffer > BufferStencil;

    enum Name
    {
        test = 19, Set_KeyCart_DigitalOut = 20
    };

    struct Data
    {
      
      Name command;

      // KeyCart gp_out
      uint16_t key_gpout;

<<<<<<< HEAD
    };

    Data data;
//    virtual ~_Cart_() {}

//    static _Cart_ Set_KeyCart_DigitalOutput(const DigitalOutput &digital_output, Cart_Command::Data &current_data);
=======
    }

    static Cart_Command SetDigitalOutput(const DigitalOutput &digital_output, Command::Data &current_data);
>>>>>>> d84705cdf5b71649f6dc44a1036d4c7a19d8d6b6

private:
    static const unsigned char header0;
    static const unsigned char header1;
};

class KeyCartRos
{
public:
<<<<<<< HEAD
=======

>>>>>>> d84705cdf5b71649f6dc44a1036d4c7a19d8d6b6
  void cart_subscribeTopics(ros::NodeHandle& nh);
  void subscribeKeyCartDigitalOutputCommand(const kobuki_msgs::DigitalOutputConstPtr);

private:
//  void subscribeKeyCartDigitalOutputCommand(const kobuki_msgs::DigitalOutputConstPtr);
};

} // namespace kobuki

#endif /* KEYCART_COMMAND_DATA_HPP__ */
