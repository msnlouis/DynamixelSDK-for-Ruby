#! /usr/bin/env ruby
#  encoding: UTF-8
#
#  Program name : Example
#  Created by Louis Smith on Oct. 6, 2011.


# [ Add Load Path  ] #---------------------------------------------#
$LOAD_PATH.push( File.dirname(__FILE__) )

# [ Import Library ] #---------------------------------------------#
require 'Dynamixel'

Dynamixel::BROADCAST_ID
Dynamixel::INST_PING
Dynamixel::INST_READ
Dynamixel::INST_WRITE
Dynamixel::INST_REG_WRITE
Dynamixel::INST_ACTION
Dynamixel::INST_RESET
Dynamixel::INST_SYNC_WRITE
Dynamixel::MAXNUM_TXPARAM
Dynamixel::MAXNUM_RXPARAM
Dynamixel::ERRBIT_VOLTAGE
Dynamixel::ERRBIT_ANGLE
Dynamixel::ERRBIT_OVERHEAT
Dynamixel::ERRBIT_RANGE
Dynamixel::ERRBIT_CHECKSUM
Dynamixel::ERRBIT_OVERLOAD
Dynamixel::ERRBIT_INSTRUCTION
Dynamixel::COMM_TXSUCCESS
Dynamixel::COMM_RXSUCCESS
Dynamixel::COMM_TXFAIL
Dynamixel::COMM_RXFAIL
Dynamixel::COMM_TXERROR
Dynamixel::COMM_RXWAITING
Dynamixel::COMM_RXTIMEOUT
Dynamixel::COMM_RXCORRUPT
