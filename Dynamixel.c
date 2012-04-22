/*----------------------------------------------
#  Extension Name : Dynamixel
#  Created by Louis Smith on Oct. 10, 2011.
----------------------------------------------*/

#if defined(__cplusplus)
extern "C" {
#endif


#include <stdio.h>
#include <stdlib.h>
#include <ruby.h>
#include <dynamixel.h>


static VALUE cDynamixel;


/* Device Control Methods */
static VALUE
dynamixel_initialize( VALUE self, VALUE devIndex, VALUE baudnum )
{
     return INT2FIX( dxl_initialize( FIX2INT(devIndex), FIX2INT(baudnum) ) );
}

static VALUE
dynamixel_terminate( VALUE self )
{
     dxl_terminate();
     return Qnil;
}


/* Set/Get Packet Methods */
static VALUE
dynamixel_set_txpacket_id( VALUE self, VALUE id )
{
     dxl_set_txpacket_id( FIX2INT(id) );
     return Qnil;
}

static VALUE
dynamixel_set_txpacket_instruction( VALUE self, VALUE instruction )
{
     dxl_set_txpacket_instruction( FIX2INT(instruction) );
     return Qnil;
}

static VALUE
dynamixel_set_txpacket_parameter( VALUE self, VALUE index, VALUE value )
{
     dxl_set_txpacket_parameter( FIX2INT(index), FIX2INT(value) );
     return Qnil;
}

static VALUE
dynamixel_set_txpacket_length( VALUE self, VALUE length )
{
     dxl_set_txpacket_length( FIX2INT(length) );
     return Qnil;
}

static VALUE
dynamixel_get_rxpacket_error( VALUE self, VALUE errbit )
{
     return INT2FIX( dxl_get_rxpacket_error( FIX2INT(errbit) ) );
}

static VALUE
dynamixel_get_rxpacket_parameter( VALUE self, VALUE index )
{
     return INT2FIX( dxl_get_rxpacket_parameter( FIX2INT(index) ) );
}

static VALUE
dynamixel_get_rxpacket_length( VALUE self )
{
     return INT2FIX( dxl_get_rxpacket_length() );
}


/* Utility for Value */
static VALUE
dynamixel_makeword( VALUE self, VALUE lowbyte, VALUE highbyte )
{
     return INT2FIX( dxl_makeword( FIX2INT(lowbyte), FIX2INT(highbyte) ) );
}

static VALUE
dynamixel_get_lowbyte( VALUE self, VALUE word )
{
     return INT2FIX( dxl_get_lowbyte( FIX2INT(word) ) );
}

static VALUE
dynamixel_get_highbyte( VALUE self, VALUE word )
{
     return INT2FIX( dxl_get_highbyte( FIX2INT(word) ) );
}


/* Packet Communication Methods */
static VALUE
dynamixel_tx_packet( VALUE self )
{
     dxl_tx_packet();
     return Qnil;
}

static VALUE
dynamixel_rx_packet( VALUE self )
{
     dxl_rx_packet();
     return Qnil;
}

static VALUE
dynamixel_txrx_packet( VALUE self )
{
     dxl_txrx_packet();
     return Qnil;
}

static VALUE
dynamixel_get_result( VALUE self )
{
     return INT2FIX( dxl_get_result() );
}


/* High Communication Methods */
static VALUE
dynamixel_ping( VALUE self, VALUE id )
{
     dxl_ping( FIX2INT(id) );
     return Qnil;
}

static VALUE
dynamixel_read_byte( VALUE self, VALUE id, VALUE address )
{
     return INT2FIX( dxl_read_byte( FIX2INT(id), FIX2INT(address) ) );
}

static VALUE
dynamixel_write_byte( VALUE self, VALUE id, VALUE address, VALUE value )
{
     dxl_write_byte( FIX2INT(id), FIX2INT(address), FIX2INT(value) );
     return Qnil;
}

static VALUE
dynamixel_read_word( VALUE self, VALUE id, VALUE address )
{
     return INT2FIX( dxl_read_word( FIX2INT(id), FIX2INT(address) ) );
}

static VALUE
dynamixel_write_word( VALUE self, VALUE id, VALUE address, VALUE value )
{
     dxl_write_word( FIX2INT(id), FIX2INT(address), FIX2INT(value) );
     return Qnil;
}


/* Ruby Define ------------------------------------------------------------------------------------------------ */
void Init_Dynamixel()
{
     /* Ruby Class */
     cDynamixel = rb_define_class("Dynamixel", rb_cObject);

     /* Constant */
     rb_define_const(cDynamixel, "BROADCAST_ID"      , INT2FIX(BROADCAST_ID));
     rb_define_const(cDynamixel, "INST_PING"         , INT2FIX(INST_PING));
     rb_define_const(cDynamixel, "INST_READ"         , INT2FIX(INST_READ));
     rb_define_const(cDynamixel, "INST_WRITE"        , INT2FIX(INST_WRITE));
     rb_define_const(cDynamixel, "INST_REG_WRITE"    , INT2FIX(INST_REG_WRITE));
     rb_define_const(cDynamixel, "INST_ACTION"       , INT2FIX(INST_ACTION));
     rb_define_const(cDynamixel, "INST_RESET"        , INT2FIX(INST_RESET));
     rb_define_const(cDynamixel, "INST_SYNC_WRITE"   , INT2FIX(INST_SYNC_WRITE));
     rb_define_const(cDynamixel, "MAXNUM_TXPARAM"    , INT2FIX(MAXNUM_TXPARAM));
     rb_define_const(cDynamixel, "MAXNUM_RXPARAM"    , INT2FIX(MAXNUM_RXPARAM));
     rb_define_const(cDynamixel, "ERRBIT_VOLTAGE"    , INT2FIX(ERRBIT_VOLTAGE));
     rb_define_const(cDynamixel, "ERRBIT_ANGLE"      , INT2FIX(ERRBIT_ANGLE));
     rb_define_const(cDynamixel, "ERRBIT_OVERHEAT"   , INT2FIX(ERRBIT_OVERHEAT));
     rb_define_const(cDynamixel, "ERRBIT_RANGE"      , INT2FIX(ERRBIT_RANGE));
     rb_define_const(cDynamixel, "ERRBIT_CHECKSUM"   , INT2FIX(ERRBIT_CHECKSUM));
     rb_define_const(cDynamixel, "ERRBIT_OVERLOAD"   , INT2FIX(ERRBIT_OVERLOAD));
     rb_define_const(cDynamixel, "ERRBIT_INSTRUCTION", INT2FIX(ERRBIT_INSTRUCTION));
     rb_define_const(cDynamixel, "COMM_TXSUCCESS"    , INT2FIX(COMM_TXSUCCESS));
     rb_define_const(cDynamixel, "COMM_RXSUCCESS"    , INT2FIX(COMM_RXSUCCESS));
     rb_define_const(cDynamixel, "COMM_TXFAIL"       , INT2FIX(COMM_TXFAIL));
     rb_define_const(cDynamixel, "COMM_RXFAIL"       , INT2FIX(COMM_RXFAIL));
     rb_define_const(cDynamixel, "COMM_TXERROR"      , INT2FIX(COMM_TXERROR));
     rb_define_const(cDynamixel, "COMM_RXWAITING"    , INT2FIX(COMM_RXWAITING));
     rb_define_const(cDynamixel, "COMM_RXTIMEOUT"    , INT2FIX(COMM_RXTIMEOUT));
     rb_define_const(cDynamixel, "COMM_RXCORRUPT"    , INT2FIX(COMM_RXCORRUPT));
     
     /* Class Method */
     rb_define_module_function(cDynamixel, "initialize"              , RUBY_METHOD_FUNC(dynamixel_initialize              ), 2);
     rb_define_module_function(cDynamixel, "terminate"               , RUBY_METHOD_FUNC(dynamixel_terminate               ), 0);
     rb_define_module_function(cDynamixel, "set_txpacket_id"         , RUBY_METHOD_FUNC(dynamixel_set_txpacket_id         ), 1);
     rb_define_module_function(cDynamixel, "set_txpacket_instruction", RUBY_METHOD_FUNC(dynamixel_set_txpacket_instruction), 1);
     rb_define_module_function(cDynamixel, "set_txpacket_parameter"  , RUBY_METHOD_FUNC(dynamixel_set_txpacket_parameter  ), 2);
     rb_define_module_function(cDynamixel, "set_txpacket_length"     , RUBY_METHOD_FUNC(dynamixel_set_txpacket_length     ), 1);
     rb_define_module_function(cDynamixel, "get_rxpacket_error"      , RUBY_METHOD_FUNC(dynamixel_get_rxpacket_error      ), 1);
     rb_define_module_function(cDynamixel, "get_rxpacket_parameter"  , RUBY_METHOD_FUNC(dynamixel_get_rxpacket_parameter  ), 1);
     rb_define_module_function(cDynamixel, "get_rxpacket_length"     , RUBY_METHOD_FUNC(dynamixel_get_rxpacket_length     ), 0);
     rb_define_module_function(cDynamixel, "makeword"                , RUBY_METHOD_FUNC(dynamixel_makeword                ), 2);
     rb_define_module_function(cDynamixel, "get_lowbyte"             , RUBY_METHOD_FUNC(dynamixel_get_lowbyte             ), 1);
     rb_define_module_function(cDynamixel, "get_highbyte"            , RUBY_METHOD_FUNC(dynamixel_get_highbyte            ), 1);
     rb_define_module_function(cDynamixel, "tx_packet"               , RUBY_METHOD_FUNC(dynamixel_tx_packet               ), 0);
     rb_define_module_function(cDynamixel, "rx_packet"               , RUBY_METHOD_FUNC(dynamixel_rx_packet               ), 0);
     rb_define_module_function(cDynamixel, "txrx_packet"             , RUBY_METHOD_FUNC(dynamixel_txrx_packet             ), 0);
     rb_define_module_function(cDynamixel, "get_result"              , RUBY_METHOD_FUNC(dynamixel_get_result              ), 0);
     rb_define_module_function(cDynamixel, "ping"                    , RUBY_METHOD_FUNC(dynamixel_ping                    ), 1);
     rb_define_module_function(cDynamixel, "read_byte"               , RUBY_METHOD_FUNC(dynamixel_read_byte               ), 2);
     rb_define_module_function(cDynamixel, "write_byte"              , RUBY_METHOD_FUNC(dynamixel_write_byte              ), 3);
     rb_define_module_function(cDynamixel, "read_word"               , RUBY_METHOD_FUNC(dynamixel_read_word               ), 2);
     rb_define_module_function(cDynamixel, "write_word"              , RUBY_METHOD_FUNC(dynamixel_write_word              ), 3);
}


#if defined(__cplusplus)
}
#endif
