/***************************************************************************//**
 * @file sl_cli_command_table.c
 * @brief Declarations of relevant command structs for cli framework.
 * @version x.y.z
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#include <stdlib.h>

#include "sl_cli_config.h"
#include "sl_cli_command.h"
#include "sl_cli_arguments.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 *****************************   TEMPLATED FILE   ******************************
 ******************************************************************************/

/*******************************************************************************
 * Example syntax (.slcc or .slcp) for populating this file:
 *
 *   template_contribution:
 *     - name: cli_command          # Register a command
 *       value:
 *         name: status             # Name of command
 *         handler: status_command  # Function to be called. Must be defined
 *         help: "Prints status"    # Optional help description
 *         shortcuts:               # Optional shorcut list
 *           - name: st
 *         argument:                # Argument list, if apliccable
 *           - type: uint8          # Variable type
 *             help: "Channel"      # Optional description
 *           - type: string
 *             help: "Text"
 *     - name: cli_group            # Register a group
 *       value:
 *         name: shell              # Group name
 *         help: "Shell commands"   # Optional help description
 *         shortcuts:               # Optional shorcuts
 *           - name: sh
 *     - name: cli_command
 *       value:
 *         name: repeat
 *         handler: repeat_cmd
 *         help: "Repeat commands"
 *         shortcuts:
 *           - name: r
 *           - name: rep
 *         group: shell            # Associate command with group
 *         argument:
 *           - type: string
 *             help: "Text"
 *           - type: additional
 *             help: "More text"
 *
 * For subgroups, an optional unique id can be used to allow a particular name to
 * be used more than once. In the following case, from the command line the
 * following commands are available:
 *
 * >  root_1 shell status
 * >  root_2 shell status
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_1             # Group name
 *
 *     - name: cli_group            # Register a group
 *       value:
 *         name: root_2             # Group name
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_1         # Optional unique id for group
 *         group: root_1            # Add group to root_1 group
 *
 *    - name: cli_group             # Register a group
 *       value:
 *         name: shell              # Group name
 *         id: shell_root_2         # Optional unique id for group
 *         group: root_2            # Add group to root_1 group
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_1
 *         group: shell_root_1      # id of subgroup
 *
 *    - name: cli_command           # Register a command
 *       value:
 *         name: status
 *         handler: status_2
 *         group: shell_root_2      # id of subgroup
 *
 ******************************************************************************/

// Provide function declarations
void emberAfPluginAddressTableAddCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginAddressTableSetCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginAddressTableRemoveCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginAddressTableLookupCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginAddressTablePrintCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginIdleSleepStatusCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginIdleSleepStayAwakeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginIdleSleepAwakeWhenNotJoinedCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleHelloCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleGetAddressCommand(sl_cli_command_arg_t *arguments);
void sl_dmp_print_connections(sl_cli_command_arg_t *arguments);
void emberAfPluginBleStopAdvertising(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSetGapModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSetBt5GapModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleGapDiscoverCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleGapConnectionOpenCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSetAdvertisementParamsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleGapSetConnectionParamsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleConnectionSetParamsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSecurityManagerIncreaseSecurityCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSecurityManagerListAllBondingsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSecurityManagerDeleteBondingCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSecurityManagerConfigureCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSecurityManagerDeleteAllBondingsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSecurityManagerSetBondableModeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSecurityManagerConfirmPasskeyCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSecurityManagerEnterPasskeyCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleGattDiscoverPrimaryServicesCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleGattDiscoverCharacteristicsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleGattSetCharacteristicNotificationCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleGattWriteCharacteristicValueCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleConnectionCloseCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginBleSetTxPowerCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginConcentratorStatus(sl_cli_command_arg_t *arguments);
void emberAfPluginConcentratorStartDiscoveryCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginConcentratorStopDiscoveryCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginConcentratorAggregationCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginConcentratorPrintSourceRouteTable(sl_cli_command_arg_t *arguments);
void emberAfPluginConcentratorSetRouterBehaviorCommand(sl_cli_command_arg_t *arguments);
void emAfCliInfoCommand(sl_cli_command_arg_t *arguments);
void printAllLibraryStatus(sl_cli_command_arg_t *arguments);
void emAfCliBsendCommand(sl_cli_command_arg_t *arguments);
void sli_zigbee_cli_send_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_zcl_read_cli_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_zcl_write_cli_command(sl_cli_command_arg_t *arguments);
void resetCommand(sl_cli_command_arg_t *arguments);
void emAfCliRawCommand(sl_cli_command_arg_t *arguments);
void sli_zigbee_cli_send_command(sl_cli_command_arg_t *arguments);
void emAfCliSendUsingMulticastBindingCommand(sl_cli_command_arg_t *arguments);
void emAfCliTimesyncCommand(sl_cli_command_arg_t *arguments);
void sli_get_pti_radio_config(sl_cli_command_arg_t *arguments);
void sli_zigbee_cli_config_cca_mode_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_cli_version_command(sl_cli_command_arg_t *arguments);
void endpointPrint(sl_cli_command_arg_t *arguments);
void enableDisableEndpoint(sl_cli_command_arg_t *arguments);
void enableDisableEndpoint(sl_cli_command_arg_t *arguments);
void printEvents(sl_cli_command_arg_t *arguments);
void getSetMfgToken(sl_cli_command_arg_t *arguments);
void getSetMfgToken(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersPrintCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCounterPrintCounterTypeCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersSimplePrintCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersClear(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersPrintThresholdsCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersSetThresholdCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersResetThresholds(sl_cli_command_arg_t *arguments);
void emberAfPluginCountersSendRequestCommand(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_stack_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_core_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_app_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_zcl_type_command(sl_cli_command_arg_t *arguments);
void sli_zigbee_debug_print_enable_legacy_af_debug_type_command(sl_cli_command_arg_t *arguments);
void emberAfPluginFindAndBindTargetStartCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientSetProxyEntry(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientAddSink(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientAddGroupcastSink(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientRemoveProxyTableEntry(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientAddSink(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientPrintProxyTable(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientClearProxyTable(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientDuplicateFilteringTest(sl_cli_command_arg_t *arguments);
void emberAfPluginGreenPowerClientSetKey(sl_cli_command_arg_t *arguments);
void emAfGroupsServerCliPrint(sl_cli_command_arg_t *arguments);
void emAfGroupsServerCliClear(sl_cli_command_arg_t *arguments);
void emAfPluginIdentifyCliPrint(sl_cli_command_arg_t *arguments);
void emAfInterpanEnableCommand(sl_cli_command_arg_t *arguments);
void emAfInterpanDisableCommand(sl_cli_command_arg_t *arguments);
void emAfInterpanFragmentTestCommand(sl_cli_command_arg_t *arguments);
void emAfInterpanSetMessageTimeoutCommand(sl_cli_command_arg_t *arguments);
void emAfInterpanGroupShortCommand(sl_cli_command_arg_t *arguments);
void emAfInterpanGroupShortCommand(sl_cli_command_arg_t *arguments);
void emAfInterpanLongCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginNetworkCreatorStartCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginNetworkCreatorStop(sl_cli_command_arg_t *arguments);
void emberAfPluginNetworkCreatorFormCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginNetworkCreatorChannelMaskCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginNetworkCreatorChannelMaskCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginNetworkCreatorChannelMaskCommand(sl_cli_command_arg_t *arguments);
void emberAfPluginNetworkCreatorStatusCommand(sl_cli_command_arg_t *arguments);
void emAfPluginNetworkCreatorSecuritySetJoiningLinkKeyCommand(sl_cli_command_arg_t *arguments);
void emAfPluginNetworkCreatorSecurityClearJoiningLinkKeyCommand(sl_cli_command_arg_t *arguments);
void emAfPluginNetworkCreatorSecurityOpenOrCloseNetworkCommand(sl_cli_command_arg_t *arguments);
void emAfPluginNetworkCreatorSecurityOpenOrCloseNetworkCommand(sl_cli_command_arg_t *arguments);
void emAfPluginNetworkCreatorSecurityOpenNetworkWithKeyCommand(sl_cli_command_arg_t *arguments);
void emAfPluginNetworkCreatorSecurityConfigureDistributedKey(sl_cli_command_arg_t *arguments);
void emAfPluginReportingCliPrint(sl_cli_command_arg_t *arguments);
void emAfPluginReportingCliClear(sl_cli_command_arg_t *arguments);
void emAfPluginReportingCliRemove(sl_cli_command_arg_t *arguments);
void emAfPluginReportingCliAdd(sl_cli_command_arg_t *arguments);
void emAfPluginReportingCliClearLastReportTime(sl_cli_command_arg_t *arguments);
void emAfPluginReportingCliTestTiming(sl_cli_command_arg_t *arguments);
void sli_plugin_scenes_server_print_info(sl_cli_command_arg_t *arguments);
void sli_plugin_scenes_server_clear(sl_cli_command_arg_t *arguments);
void networkFormCommand(sl_cli_command_arg_t *arguments);
void networkJoinCommand(sl_cli_command_arg_t *arguments);
void networkPermitJoinCommand(sl_cli_command_arg_t *arguments);
void networkLeaveCommand(sl_cli_command_arg_t *arguments);
void networkRejoinCommand(sl_cli_command_arg_t *arguments);
void networkRejoinDiffDeviceTypeCommand(sl_cli_command_arg_t *arguments);
void networkExtendedPanIdCommand(sl_cli_command_arg_t *arguments);
void networkCheckPjoinCommand(sl_cli_command_arg_t *arguments);
void networkPermitJoinCommand(sl_cli_command_arg_t *arguments);
void findJoinableNetworkCommand(sl_cli_command_arg_t *arguments);
void findUnusedPanIdCommand(sl_cli_command_arg_t *arguments);
void networkChangeChannelCommand(sl_cli_command_arg_t *arguments);
void networkSetCommand(sl_cli_command_arg_t *arguments);
void networkInitCommand(sl_cli_command_arg_t *arguments);
void networkIdCommand(sl_cli_command_arg_t *arguments);
void changeKeepAliveModeCommand(sl_cli_command_arg_t *arguments);
void networkChangeChildTimeoutOptionMaskCommand(sl_cli_command_arg_t *arguments);
void networkMultiPhyStartCommand(sl_cli_command_arg_t *arguments);
void networkMultiPhyStopCommand(sl_cli_command_arg_t *arguments);
void keysPrintCommand(sl_cli_command_arg_t *arguments);
void keysClearCommand(sl_cli_command_arg_t *arguments);
void optionBindingTablePrintCommand(sl_cli_command_arg_t *arguments);
void optionBindingTableClearCommand(sl_cli_command_arg_t *arguments);
void optionBindingTableSetCommand(sl_cli_command_arg_t *arguments);
void optionPrintRxCommand(sl_cli_command_arg_t *arguments);
void optionPrintRxCommand(sl_cli_command_arg_t *arguments);
void optionRegisterCommand(sl_cli_command_arg_t *arguments);
void optionDiscoveryTargetCommand(sl_cli_command_arg_t *arguments);
void optionDiscoverCommand(sl_cli_command_arg_t *arguments);
void optionEndDeviceBindCommand(sl_cli_command_arg_t *arguments);
void optionApsRetryCommand(sl_cli_command_arg_t *arguments);
void optionApsRetryCommand(sl_cli_command_arg_t *arguments);
void optionApsRetryCommand(sl_cli_command_arg_t *arguments);
void optionApsSecurityCommand(sl_cli_command_arg_t *arguments);
void optionApsSecurityCommand(sl_cli_command_arg_t *arguments);
void optionSecurityAllowTrustCenterRejoinUsingWellKnownKey(sl_cli_command_arg_t *arguments);
void optionSecurityAllowTrustCenterRejoinUsingWellKnownKeyTimeout(sl_cli_command_arg_t *arguments);
void optionSecuritySetKeyRequestPolicy(sl_cli_command_arg_t *arguments);
void changeKeyCommand(sl_cli_command_arg_t *arguments);
void changeKeyCommand(sl_cli_command_arg_t *arguments);
void optionLinkCommand(sl_cli_command_arg_t *arguments);
void optionInstallCodeCommand(sl_cli_command_arg_t *arguments);
void zdoRouteRequestCommand(sl_cli_command_arg_t *arguments);
void zdoPowerDescriptorRequestCommand(sl_cli_command_arg_t *arguments);
void zdoMgmtLqiCommand(sl_cli_command_arg_t *arguments);
void zdoMgmtBindCommand(sl_cli_command_arg_t *arguments);
void zdoLeaveRequestCommand(sl_cli_command_arg_t *arguments);
void zdoUnbindGroupCommand(sl_cli_command_arg_t *arguments);
void zdoUnbindUnicastCommand(sl_cli_command_arg_t *arguments);
void zdoActiveEpCommand(sl_cli_command_arg_t *arguments);
void zdoBindCommand(sl_cli_command_arg_t *arguments);
void zdoNodeCommand(sl_cli_command_arg_t *arguments);
void zdoMatchCommand(sl_cli_command_arg_t *arguments);
void zdoSimpleCommand(sl_cli_command_arg_t *arguments);
void zdoIeeeAddressRequestCommand(sl_cli_command_arg_t *arguments);
void zdoNwkAddressRequestCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateScanCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateSetCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateScanCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateChannelCommand(sl_cli_command_arg_t *arguments);
void zdoNetworkUpdateChannelCommand(sl_cli_command_arg_t *arguments);
void zdoAddClusterCommand(sl_cli_command_arg_t *arguments);
void zdoClearClusterCommand(sl_cli_command_arg_t *arguments);
void zdoAddClusterCommand(sl_cli_command_arg_t *arguments);
void zdoClearClusterCommand(sl_cli_command_arg_t *arguments);
void emberAfPrintAttributeTable(sl_cli_command_arg_t *arguments);
void printTimeCommand(sl_cli_command_arg_t *arguments);
void formNetwork(sl_cli_command_arg_t *arguments);
void scanTouchLink(sl_cli_command_arg_t *arguments);
void scanTouchLink(sl_cli_command_arg_t *arguments);
void scanTouchLink(sl_cli_command_arg_t *arguments);
void abortTouchLink(sl_cli_command_arg_t *arguments);
void initiateTouchLink(sl_cli_command_arg_t *arguments);
void setIdentifyDuration(sl_cli_command_arg_t *arguments);
void endpointInformation(sl_cli_command_arg_t *arguments);
void getGroupIdentifiersRequest(sl_cli_command_arg_t *arguments);
void getEndpointListRequest(sl_cli_command_arg_t *arguments);
void printZllTokens(sl_cli_command_arg_t *arguments);
void setScanChannel(sl_cli_command_arg_t *arguments);
void setSecondaryScanChannel(sl_cli_command_arg_t *arguments);
void setScanMask(sl_cli_command_arg_t *arguments);
void statusCommand(sl_cli_command_arg_t *arguments);
void joinable(sl_cli_command_arg_t *arguments);
void unused(sl_cli_command_arg_t *arguments);
void emberAfZllResetToFactoryNew(sl_cli_command_arg_t *arguments);
void noTouchlinkForNFN(sl_cli_command_arg_t *arguments);
void noResetForNFN(sl_cli_command_arg_t *arguments);
void disable(sl_cli_command_arg_t *arguments);
void enable(sl_cli_command_arg_t *arguments);
void setRxOn(sl_cli_command_arg_t *arguments);
void cancelRxOn(sl_cli_command_arg_t *arguments);
void rxOnStatus(sl_cli_command_arg_t *arguments);

// Command structs. Names are in the format : cli_cmd_{command group name}_{command name}
// In order to support hyphen in command and group name, every occurence of it while
// building struct names will be replaced by "_hyphen_"
static const sl_cli_command_info_t cli_cmd_address_hyphen_table_add = \
  SL_CLI_COMMAND(emberAfPluginAddressTableAddCommand,
                 "",
                  "Entry to be added" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_address_hyphen_table_set = \
  SL_CLI_COMMAND(emberAfPluginAddressTableSetCommand,
                 "Sets an entry in the address table according to the arguments specified.",
                  "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_address_hyphen_table_remove = \
  SL_CLI_COMMAND(emberAfPluginAddressTableRemoveCommand,
                 "Removes an entry from the address table.",
                  "Entry to be removed" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_address_hyphen_table_lookup = \
  SL_CLI_COMMAND(emberAfPluginAddressTableLookupCommand,
                 "Looks up an entry in the address table.",
                  "Entry to be looked up" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_address_hyphen_table_print = \
  SL_CLI_COMMAND(emberAfPluginAddressTablePrintCommand,
                 "Prints the address table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_idle_hyphen_sleep_status = \
  SL_CLI_COMMAND(emberAfPluginIdleSleepStatusCommand,
                 "Display the sleep status",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_idle_hyphen_sleep_force_hyphen_awake = \
  SL_CLI_COMMAND(emberAfPluginIdleSleepStayAwakeCommand,
                 "Set or clear force awake",
                  "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_idle_hyphen_sleep_awake_hyphen_when_hyphen_not_hyphen_joined = \
  SL_CLI_COMMAND(emberAfPluginIdleSleepAwakeWhenNotJoinedCommand,
                 "Set or clear stay awake when not joined",
                  "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_ble_hello = \
  SL_CLI_COMMAND(emberAfPluginBleHelloCommand,
                 "Checks if the Bluetooth LE stack is functional",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_get_address = \
  SL_CLI_COMMAND(emberAfPluginBleGetAddressCommand,
                 "Displays the Bluetooth LE address of the node.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_print_hyphen_connections = \
  SL_CLI_COMMAND(sl_dmp_print_connections,
                 "Prints active connections.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_stop_hyphen_advertising = \
  SL_CLI_COMMAND(emberAfPluginBleStopAdvertising,
                 "Stops advertising on advertising handle.",
                  "Advertisement handle" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_set_hyphen_mode = \
  SL_CLI_COMMAND(emberAfPluginBleSetGapModeCommand,
                 "Sets the GAP mode (advertising handle,discoverable, connectable).",
                  "Advertising handle" SL_CLI_UNIT_SEPARATOR "The GAP discoverable mode 0=non discoverable, 1=limited discoverable, 2=general discoverable, 3=broadcast, 4=user data" SL_CLI_UNIT_SEPARATOR "The GAP connectable mode 0=non-connectable, 1=directed connectable, 2=undirected connectable, 3=scannable non connectable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_set_hyphen_bt5_hyphen_mode = \
  SL_CLI_COMMAND(emberAfPluginBleSetBt5GapModeCommand,
                 "Sets the BT5 GAP mode (advertising handle,discoverable, connectable, max-events, address-type).",
                  "Advertising handle" SL_CLI_UNIT_SEPARATOR "The GAP discoverable mode: 0=non discoverable, 1=limited discoverable, 2=general discoverable, 3=broadcast, 4=user data" SL_CLI_UNIT_SEPARATOR "The GAP connectable mode: 0=non connectable, 1=directed connectable, 2=undirected connectable, 3=scannable non connectable" SL_CLI_UNIT_SEPARATOR "The maximum number of events to process" SL_CLI_UNIT_SEPARATOR "Address type: 0=public, 1=random, 2=public identity, 3=random identity, 16=classic bluetooth" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_discover = \
  SL_CLI_COMMAND(emberAfPluginBleGapDiscoverCommand,
                 "Starts the GAP Discovery procedure (discovery_mode).",
                  "The GAP discovery mode: 0=only limited discoverable devices, 1=limited and generic discoverable devices, 2=all devices" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_conn_hyphen_open = \
  SL_CLI_COMMAND(emberAfPluginBleGapConnectionOpenCommand,
                 "Opens GAP Connection (address, address_type).",
                  "The BLE address of the target device" SL_CLI_UNIT_SEPARATOR "The address type: 0=public, 1=random, 2=public resolved by the stack, 3=public resolved by the stack, 16=classic bluetooth" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_set_hyphen_adv_hyphen_params = \
  SL_CLI_COMMAND(emberAfPluginBleSetAdvertisementParamsCommand,
                 "Sets the GAP advertisement parameters (advertising handle,min-interval, max-interval, channel-map).",
                  "Advertising handle" SL_CLI_UNIT_SEPARATOR "Minimum connection interval" SL_CLI_UNIT_SEPARATOR "Maximum connection interval" SL_CLI_UNIT_SEPARATOR "Channel map indicating which of three channels will be used" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_set_hyphen_conn_hyphen_params = \
  SL_CLI_COMMAND(emberAfPluginBleGapSetConnectionParamsCommand,
                 "Sets the GAP advertisement parameters (min-interval, max-interval, slave-latency, supervision-timeout).",
                  "Minimum connection event interval" SL_CLI_UNIT_SEPARATOR "Maximum connection event interval" SL_CLI_UNIT_SEPARATOR "Number of connection intervals the slave can skip" SL_CLI_UNIT_SEPARATOR "Time before the connection is dropped" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gap_update_hyphen_conn_hyphen_params = \
  SL_CLI_COMMAND(emberAfPluginBleConnectionSetParamsCommand,
                 "Sets the GAP advertisement parameters (connection handle, min-interval, max-interval, slave-latency, supervision-timeout).",
                  "Connection handle" SL_CLI_UNIT_SEPARATOR "Minimum connection event interval" SL_CLI_UNIT_SEPARATOR "Maximum connection event interval" SL_CLI_UNIT_SEPARATOR "Number of connection intervals the slave can skip" SL_CLI_UNIT_SEPARATOR "Time before the connection is dropped" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_sm_increase_hyphen_security = \
  SL_CLI_COMMAND(emberAfPluginBleSecurityManagerIncreaseSecurityCommand,
                 "Increases the security level (conn handle).",
                  "Connection handle for which we want to increase the security level" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_sm_list_hyphen_all_hyphen_bondings = \
  SL_CLI_COMMAND(emberAfPluginBleSecurityManagerListAllBondingsCommand,
                 "Sends a command to get all the current bondings.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_sm_delete_hyphen_bonding = \
  SL_CLI_COMMAND(emberAfPluginBleSecurityManagerDeleteBondingCommand,
                 "Deletes bonding (bonding handle).",
                  "The bonding handle to be deleted" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_sm_configure = \
  SL_CLI_COMMAND(emberAfPluginBleSecurityManagerConfigureCommand,
                 "Configures security requirements and I/O capabilities of the systemc(flags, io_capability).",
                  "Security requirement bitmask." SL_CLI_UNIT_SEPARATOR "I/O Capabilities" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_sm_delete_hyphen_all_hyphen_bondings = \
  SL_CLI_COMMAND(emberAfPluginBleSecurityManagerDeleteAllBondingsCommand,
                 "Deletes all bondings.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_sm_set_hyphen_bondable_hyphen_mode = \
  SL_CLI_COMMAND(emberAfPluginBleSecurityManagerSetBondableModeCommand,
                 "Sets the bondable mode.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_sm_confirm_hyphen_passkey = \
  SL_CLI_COMMAND(emberAfPluginBleSecurityManagerConfirmPasskeyCommand,
                 "Accepts or rejects the reported passkey confirm value (connection-handle, confirm/reject).",
                  "Connection handle" SL_CLI_UNIT_SEPARATOR "Confirm = 1, Reject = 0" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_sm_enter_hyphen_passkey = \
  SL_CLI_COMMAND(emberAfPluginBleSecurityManagerEnterPasskeyCommand,
                 "Enters a passkey after receiving a passkey request event (connection, passkey).",
                  "Connection handle" SL_CLI_UNIT_SEPARATOR "Passkey" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gatt_discover_hyphen_primary_hyphen_services = \
  SL_CLI_COMMAND(emberAfPluginBleGattDiscoverPrimaryServicesCommand,
                 "GATT discovery of primary services (connection-handle).",
                  "Connection handle on which discovery should be performed" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gatt_discover_hyphen_characteristics = \
  SL_CLI_COMMAND(emberAfPluginBleGattDiscoverCharacteristicsCommand,
                 "GATT discovery of characteristics (connection-handle).",
                  "Connection handle on which discovery should be performed" SL_CLI_UNIT_SEPARATOR "Service handle on which discovery should be performed" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gatt_set_hyphen_characteristic_hyphen_notification = \
  SL_CLI_COMMAND(emberAfPluginBleGattSetCharacteristicNotificationCommand,
                 "GATT set characteristic notification (connection-handle, characteristic-handle, flags).",
                  "Connection handle for which the notification should be set" SL_CLI_UNIT_SEPARATOR "Characteristic handle to set notification for" SL_CLI_UNIT_SEPARATOR "0=disable, 1=notification, 2=indication" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gatt_write_hyphen_characteristic = \
  SL_CLI_COMMAND(emberAfPluginBleGattWriteCharacteristicValueCommand,
                 "GATT write characteristic value (connection-handle, characteristic-handle, value-len, value-data).",
                  "Connection handle" SL_CLI_UNIT_SEPARATOR "Characteristic handle" SL_CLI_UNIT_SEPARATOR "Length of data" SL_CLI_UNIT_SEPARATOR "Value of data" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_gatt_close = \
  SL_CLI_COMMAND(emberAfPluginBleConnectionCloseCommand,
                 "Closes BLE connection (connection-handle).",
                  "Connection handle" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_system_set_hyphen_tx_hyphen_power = \
  SL_CLI_COMMAND(emberAfPluginBleSetTxPowerCommand,
                 "Sets the TX power (tx-power).",
                  "TX power to be set in 0.1dBm steps" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_concentrator_status = \
  SL_CLI_COMMAND(emberAfPluginConcentratorStatus,
                 "Prints current status and configured parameters of the concentrator.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_concentrator_start = \
  SL_CLI_COMMAND(emberAfPluginConcentratorStartDiscoveryCommand,
                 "Starts the periodic broadcast of MTORRs.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_concentrator_stop = \
  SL_CLI_COMMAND(emberAfPluginConcentratorStopDiscoveryCommand,
                 "Stops the periodic broadcast of MTORRs.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_concentrator_agg = \
  SL_CLI_COMMAND(emberAfPluginConcentratorAggregationCommand,
                 "(Requires Concentrator Support to be enabled on this device.) Schedules a Zigbee PRO Many-To-One Route Request (MTORR) to be sent out at the next opportunity, which will cause aggregation (many-to-one) routes to be created towards this concentrator.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_concentrator_print_hyphen_table = \
  SL_CLI_COMMAND(emberAfPluginConcentratorPrintSourceRouteTable,
                 "Prints the SoC/NCP source route table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_concentrator_set_hyphen_router_hyphen_behavior = \
  SL_CLI_COMMAND(emberAfPluginConcentratorSetRouterBehaviorCommand,
                 "This command allows the user to set the router behavior for this component. The argument values come from concentrator-support.h in the enum with members starting with EMBER_AF_PLUGIN_CONCENTRATOR_ROUTER_BEHAVIOR_.",
                  "The value of an EMBER_AF_PLUGIN_CONCENTRATOR_ROUTER_BEHAVIOR_ enum member" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__info = \
  SL_CLI_COMMAND(emAfCliInfoCommand,
                 "Prints information about the network state, clusters, and endpoints.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__libs = \
  SL_CLI_COMMAND(printAllLibraryStatus,
                 "Lists which optional libraries of the stack are implemented on this device.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__bsend = \
  SL_CLI_COMMAND(emAfCliBsendCommand,
                 "Sends a message.",
                  "Source endpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__send = \
  SL_CLI_COMMAND(sli_zigbee_cli_send_command,
                 "Sends a message.",
                  "Destination" SL_CLI_UNIT_SEPARATOR "Source endpoint" SL_CLI_UNIT_SEPARATOR "Destination endpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__read = \
  SL_CLI_COMMAND(sli_zigbee_zcl_read_cli_command,
                 "Reads a message.",
                  "Endpoint" SL_CLI_UNIT_SEPARATOR "Cluster ID" SL_CLI_UNIT_SEPARATOR "Attribute ID" SL_CLI_UNIT_SEPARATOR "1 if server direction, 0 if client direction" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__write = \
  SL_CLI_COMMAND(sli_zigbee_zcl_write_cli_command,
                 "Writes a message.",
                  "Endpoint" SL_CLI_UNIT_SEPARATOR "Cluster ID" SL_CLI_UNIT_SEPARATOR "Attribute ID" SL_CLI_UNIT_SEPARATOR "Mask" SL_CLI_UNIT_SEPARATOR "Data type" SL_CLI_UNIT_SEPARATOR "Data byte" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__reset = \
  SL_CLI_COMMAND(resetCommand,
                 "Resets the node.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__raw = \
  SL_CLI_COMMAND(emAfCliRawCommand,
                 "Creates a message by specifying the raw bytes. Use the send command to send the message once it has been created. Ex: raw 0x000F {00 0A 00 11 22 33 44 55} sends a message to cluster 15 (0x000F) of length 8 which includes the ZCL header.",
                  "ClusterId" SL_CLI_UNIT_SEPARATOR "Data" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__send_multicast = \
  SL_CLI_COMMAND(sli_zigbee_cli_send_command,
                 "Sends a pre-buffered multicast message to a given group ID from a given endpoint.",
                  "groupId" SL_CLI_UNIT_SEPARATOR "src-endpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__send_hyphen_using_hyphen_multicast_hyphen_binding = \
  SL_CLI_COMMAND(emAfCliSendUsingMulticastBindingCommand,
                 "When sending using a binding, specifies whether a multicast binding should be used.",
                  "useMulticastBinding" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__timesync = \
  SL_CLI_COMMAND(emAfCliTimesyncCommand,
                 "Sends a read attr for the time of the device specified. It sets a flag so when it gets the response it writes the time to its own time attr.",
                  "Id" SL_CLI_UNIT_SEPARATOR "srcEndpoint" SL_CLI_UNIT_SEPARATOR "destEndpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__get_hyphen_pti_hyphen_radio_hyphen_config = \
  SL_CLI_COMMAND(sli_get_pti_radio_config,
                 "Returns PTI radio config information to determine the PHY type being used by RAIL. return value is enum RAIL_IEEE802154_PtiRadioConfig_t e.g  RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ = 0x00U RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_ANTDIV = 0x01U RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_COEX = 0x02U RAIL_IEEE802154_PTI_RADIO_CONFIG_2P4GHZ_ANTDIV_COEX = 0x03U",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__config_hyphen_cca_hyphen_mode = \
  SL_CLI_COMMAND(sli_zigbee_cli_config_cca_mode_command,
                 "Set the configured 802.15.4 CCA mode in the radio. See documentation regarding RAIL_IEEE802154_CcaMode_t.",
                  "A RAIL_IEEE802154_CcaMode_t value" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__version = \
  SL_CLI_COMMAND(sli_zigbee_cli_version_command,
                 "Shows the version of the software.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_endpoints_print = \
  SL_CLI_COMMAND(endpointPrint,
                 "Print status of endpoints.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_endpoints_enable = \
  SL_CLI_COMMAND(enableDisableEndpoint,
                 "Enables the endpoint for ZCL messages.",
                  "Endpoint index" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_endpoints_disable = \
  SL_CLI_COMMAND(enableDisableEndpoint,
                 "Disable the endpoint for ZCL messages.",
                  "Endpoint index" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd__events = \
  SL_CLI_COMMAND(printEvents,
                 "Print active events.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_mfg_hyphen_token_get = \
  SL_CLI_COMMAND(getSetMfgToken,
                 "Print MFG token.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_mfg_hyphen_token_set = \
  SL_CLI_COMMAND(getSetMfgToken,
                 "Set MFG token, CANNOT BE UNSET BY CLI.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_print = \
  SL_CLI_COMMAND(emberAfPluginCountersPrintCommand,
                 "Prints all counter values and clears them.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_print_hyphen_counter_hyphen_type = \
  SL_CLI_COMMAND(emberAfPluginCounterPrintCounterTypeCommand,
                 "Prints the value of this particular counter.",
                  "The counter type to print" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_simple_hyphen_print = \
  SL_CLI_COMMAND(emberAfPluginCountersSimplePrintCommand,
                 "Prints all counter values.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_clear = \
  SL_CLI_COMMAND(emberAfPluginCountersClear,
                 "Clears all counter values.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_print_hyphen_thresholds = \
  SL_CLI_COMMAND(emberAfPluginCountersPrintThresholdsCommand,
                 "Prints the thresholds of all the counters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_set_hyphen_threshold = \
  SL_CLI_COMMAND(emberAfPluginCountersSetThresholdCommand,
                 "Sets a threshold value for a particular type of counter.",
                  "Type of counter" SL_CLI_UNIT_SEPARATOR "Threshold Value" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_reset_hyphen_thresholds = \
  SL_CLI_COMMAND(emberAfPluginCountersResetThresholds,
                 "Resets all thresholds values to 0xFFFF.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_counters_send_hyphen_request = \
  SL_CLI_COMMAND(emberAfPluginCountersSendRequestCommand,
                 "Sends a request for OTA counters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_stack = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_stack_type_command,
                 "Enable/disable debug `stack` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_core = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_core_type_command,
                 "Enable/disable debug `core` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_app = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_app_type_command,
                 "Enable/disable debug `app` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_zcl = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_zcl_type_command,
                 "Enable/disable debug `zcl` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_enable_type_legacy_af_debug = \
  SL_CLI_COMMAND(sli_zigbee_debug_print_enable_legacy_af_debug_type_command,
                 "Enable/disable debug `legacy app framework debug` print type.",
                  "Enable/disable" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_find_and_bind_target = \
  SL_CLI_COMMAND(emberAfPluginFindAndBindTargetStartCommand,
                 "Makes this node start identifying as a target for binding with an initiator node.",
                  "The endpoint on which to begin the Finding and Binding target process" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_set_hyphen_proxy_hyphen_entry = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientSetProxyEntry,
                 "Sets a proxy table entry.",
                  "Index to proxy table" SL_CLI_UNIT_SEPARATOR "GPD Source ID" SL_CLI_UNIT_SEPARATOR "Sinks node address" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_add_hyphen_sink = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientAddSink,
                 "Adds a sink for a given GPD.",
                  "GPD Source ID" SL_CLI_UNIT_SEPARATOR "Sinks IEEE address" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_add_hyphen_group_hyphen_sink = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientAddGroupcastSink,
                 "Adds a groupcast sink for a given GPD.",
                  "GPD Source ID" SL_CLI_UNIT_SEPARATOR "Sink group" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_rm_hyphen_gpd = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientRemoveProxyTableEntry,
                 "Removes a given GPD from the proxy table.",
                  "GPD Source ID" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_rm_hyphen_sink = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientAddSink,
                 "Removes a sink for a given GPD.  If it is the last sink, removes the proxy table entry.",
                  "GPD Source ID" SL_CLI_UNIT_SEPARATOR "Sinks IEEE address" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_print_hyphen_proxy_hyphen_table = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientPrintProxyTable,
                 "Prints the proxy table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_clear_hyphen_proxy_hyphen_table = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientClearProxyTable,
                 "Clears the proxy table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_duplicate_hyphen_filter_hyphen_test = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientDuplicateFilteringTest,
                 "Used to instrument the current device receiving a message, in order to test the duplicate message filtering functionality.",
                  "" SL_CLI_UNIT_SEPARATOR "Source ID of the fake incoming message" SL_CLI_UNIT_SEPARATOR "" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_green_hyphen_power_hyphen_client_set_hyphen_key = \
  SL_CLI_COMMAND(emberAfPluginGreenPowerClientSetKey,
                 "Used to set the key for a proxy table entry.",
                  "" SL_CLI_UNIT_SEPARATOR "Source ID of the fake incoming message" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_groups_hyphen_server_print = \
  SL_CLI_COMMAND(emAfGroupsServerCliPrint,
                 "Prints information about the contents of the groups table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_groups_hyphen_server_clear = \
  SL_CLI_COMMAND(emAfGroupsServerCliClear,
                 "Clears the groups table on every endpoint",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_identify_print = \
  SL_CLI_COMMAND(emAfPluginIdentifyCliPrint,
                 "Print which endpoints are reporting.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_interpan_enable = \
  SL_CLI_COMMAND(emAfInterpanEnableCommand,
                 "Enables inter-PAN globally.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_interpan_disable = \
  SL_CLI_COMMAND(emAfInterpanDisableCommand,
                 "Disables inter-PAN globally.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_interpan_fragment_hyphen_test = \
  SL_CLI_COMMAND(emAfInterpanFragmentTestCommand,
                 "Sends a message of specified length of random values to target device over inter-PAN.",
                  "The PAN ID that the target is located on" SL_CLI_UNIT_SEPARATOR "The targets EUI64 (big endian)" SL_CLI_UNIT_SEPARATOR "The cluster ID that the sample message should contain" SL_CLI_UNIT_SEPARATOR "The length of the randomly-filled message to be sent across inter-PAN" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_interpan_set_hyphen_msg_hyphen_timeout = \
  SL_CLI_COMMAND(emAfInterpanSetMessageTimeoutCommand,
                 "Sets the timeout for inter-PAN messages sent and received.",
                  "Message timeout in seconds" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_interpan_group = \
  SL_CLI_COMMAND(emAfInterpanGroupShortCommand,
                 "Send an interpan message to a group id.",
                  "Group ID" SL_CLI_UNIT_SEPARATOR "Destination PAN ID" SL_CLI_UNIT_SEPARATOR "Destination Profile ID" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_interpan_short = \
  SL_CLI_COMMAND(emAfInterpanGroupShortCommand,
                 "Send an interpan message to a short id.",
                  "Short ID" SL_CLI_UNIT_SEPARATOR "Destination PAN ID" SL_CLI_UNIT_SEPARATOR "Destination Profile ID" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_interpan_long = \
  SL_CLI_COMMAND(emAfInterpanLongCommand,
                 "Send an interpan message to an 8-byte EUI64.",
                  "Long ID" SL_CLI_UNIT_SEPARATOR "Destination PAN ID" SL_CLI_UNIT_SEPARATOR "Destination Profile ID" SL_CLI_UNIT_SEPARATOR "Encrypt Options" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_start = \
  SL_CLI_COMMAND(emberAfPluginNetworkCreatorStartCommand,
                 "Starts the network formation process.",
                  "Whether or not to form a centralized network. If this value is false, the device will attempt to join a distributed network." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_stop = \
  SL_CLI_COMMAND(emberAfPluginNetworkCreatorStop,
                 "Stops the network formation process.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_form = \
  SL_CLI_COMMAND(emberAfPluginNetworkCreatorFormCommand,
                 "Forms a network with specified parameters.",
                  "Whether or not to form a centralized network. If this value is false, the device will attempt to join a distributed network." SL_CLI_UNIT_SEPARATOR "PanID of the network to be formed" SL_CLI_UNIT_SEPARATOR "Tx power of the network to be formed" SL_CLI_UNIT_SEPARATOR "Channel of the network to be formed" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_INT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_INT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_mask_add = \
  SL_CLI_COMMAND(emberAfPluginNetworkCreatorChannelMaskCommand,
                 "Adds a channel to the channel mask of choice.",
                  "The mask to which to add the channel. 1 chooses the primary channel mask, any other argument chooses the secondary channel mask." SL_CLI_UNIT_SEPARATOR "The channel to add to the channel mask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_mask_subtract = \
  SL_CLI_COMMAND(emberAfPluginNetworkCreatorChannelMaskCommand,
                 "Subtracts a channel from the channel mask of choice.",
                  "The mask from which to subtract the channel. 1 chooses the primary channel mask. Any other argument chooses the secondary channel mask." SL_CLI_UNIT_SEPARATOR "The channel to subtract from the channel mask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_mask_set = \
  SL_CLI_COMMAND(emberAfPluginNetworkCreatorChannelMaskCommand,
                 "Sets a channel mask.",
                  "The mask  to set. 1 chooses the primary channel mask. Any other argument chooses the secondary channel mask." SL_CLI_UNIT_SEPARATOR "The bit mask to which to set the chosen channel mask." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_status = \
  SL_CLI_COMMAND(emberAfPluginNetworkCreatorStatusCommand,
                 "Prints the status of the network-creator component.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_hyphen_security_set_hyphen_joining_hyphen_link_hyphen_key = \
  SL_CLI_COMMAND(emAfPluginNetworkCreatorSecuritySetJoiningLinkKeyCommand,
                 "Sets the link key that a specific joining device will use when joining the network. This command can be also be used to add install code-derived link keys. If all FFs are entered for the EUI64 for the joining device, then this link key will be used for all joining devices without a joining key entry.",
                  "The EUI64 of the joining device" SL_CLI_UNIT_SEPARATOR "The link key that the joining device will use to enter the network" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_hyphen_security_clear_hyphen_joining_hyphen_link_hyphen_keys = \
  SL_CLI_COMMAND(emAfPluginNetworkCreatorSecurityClearJoiningLinkKeyCommand,
                 "Clears all of the joining link keys stored in the stack.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_hyphen_security_open_hyphen_network = \
  SL_CLI_COMMAND(emAfPluginNetworkCreatorSecurityOpenOrCloseNetworkCommand,
                 "Opens the network for joining.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_hyphen_security_close_hyphen_network = \
  SL_CLI_COMMAND(emAfPluginNetworkCreatorSecurityOpenOrCloseNetworkCommand,
                 "Closes the network for joining.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_hyphen_security_open_hyphen_with_hyphen_key = \
  SL_CLI_COMMAND(emAfPluginNetworkCreatorSecurityOpenNetworkWithKeyCommand,
                 "Opens the network that would only allow the node with the specified EUI and link key pair to join.",
                  "The EUI64 of the joining device" SL_CLI_UNIT_SEPARATOR "The link key that the joining device will use to enter the network" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_hyphen_creator_hyphen_security_set_hyphen_distributed_hyphen_key = \
  SL_CLI_COMMAND(emAfPluginNetworkCreatorSecurityConfigureDistributedKey,
                 "Sets the TC Link key for a distributed network.",
                  "The pre-configured distributed key that the joining device will use to enter the network" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_reporting_print = \
  SL_CLI_COMMAND(emAfPluginReportingCliPrint,
                 "Prints the report table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_reporting_clear = \
  SL_CLI_COMMAND(emAfPluginReportingCliClear,
                 "Clears all entries from the report table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_reporting_remove = \
  SL_CLI_COMMAND(emAfPluginReportingCliRemove,
                 "Removes an entry from the report table.",
                  "The index of the report to be removed" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_reporting_add = \
  SL_CLI_COMMAND(emAfPluginReportingCliAdd,
                 "Adds a new entry to the report table.",
                  "The local endpoint from which the attribute is reported" SL_CLI_UNIT_SEPARATOR "The cluster where the attribute is located" SL_CLI_UNIT_SEPARATOR "The ID of the attribute being reported" SL_CLI_UNIT_SEPARATOR "0 for client-side attributes or 1 for server-side attributes" SL_CLI_UNIT_SEPARATOR "The minimum reporting interval, measured in seconds." SL_CLI_UNIT_SEPARATOR "The maximum reporting interval, measured in seconds." SL_CLI_UNIT_SEPARATOR "The minimum change to the attribute that will result in a report being sent." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_reporting_clear_hyphen_last_hyphen_report_hyphen_time = \
  SL_CLI_COMMAND(emAfPluginReportingCliClearLastReportTime,
                 "Clears the last report time of attributes.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_reporting_test_hyphen_timing = \
  SL_CLI_COMMAND(emAfPluginReportingCliTestTiming,
                 "FOR TESTING PURPOSES - gather timing metrics for reporting table operations.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_scenes_print = \
  SL_CLI_COMMAND(sli_plugin_scenes_server_print_info,
                 "Prints information about the contents of the scenes table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_scenes_clear = \
  SL_CLI_COMMAND(sli_plugin_scenes_server_clear,
                 "Clears the scenes table on every endpoint.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_form = \
  SL_CLI_COMMAND(networkFormCommand,
                 "Forms a network on a given channel, with a given TX Power and PAN ID.",
                  "The channel on which to form the network" SL_CLI_UNIT_SEPARATOR "One-byte signed value indicating the TX Power that the radio should be set to" SL_CLI_UNIT_SEPARATOR "The PAN ID on which to form the network" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_join = \
  SL_CLI_COMMAND(networkJoinCommand,
                 "Joins a network on a given channel, with a given TX Power and PAN ID.",
                  "The channel on which to join the network" SL_CLI_UNIT_SEPARATOR "One-byte signed value indicating the TX Power that the radio should be set to" SL_CLI_UNIT_SEPARATOR "The PAN ID on which to join the network" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_pjoin = \
  SL_CLI_COMMAND(networkPermitJoinCommand,
                 "Turns permit joining on for the amount of time indicated.",
                  "A single byte indicating how long the device should have permit joining turn on for. A value of 0xff turns permit join indefinitely." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_leave = \
  SL_CLI_COMMAND(networkLeaveCommand,
                 "Leaves a network.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_rejoin = \
  SL_CLI_COMMAND(networkRejoinCommand,
                 "ReJoins a network.",
                  "Boolean network key availability" SL_CLI_UNIT_SEPARATOR "Channel mask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_rejoin_hyphen_diff_hyphen_device_hyphen_type = \
  SL_CLI_COMMAND(networkRejoinDiffDeviceTypeCommand,
                 "Rejoins an existing network in a secure or insecure manner with a different device type.",
                  "Boolean network key availability" SL_CLI_UNIT_SEPARATOR "Channel mask" SL_CLI_UNIT_SEPARATOR "An enumeration indicating the device type to rejoin as.The stack only accepts EMBER_END_DEVICE and EMBER_SLEEPY_END_DEVICE." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT32, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_extpanid = \
  SL_CLI_COMMAND(networkExtendedPanIdCommand,
                 "Writes the extended pan ID for the device.",
                  "extpanid" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_isopen = \
  SL_CLI_COMMAND(networkCheckPjoinCommand,
                 "Checks network pjoin status.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_broad_hyphen_pjoin = \
  SL_CLI_COMMAND(networkPermitJoinCommand,
                 "Permits joining on the network for a given number of seconds AND broadcasts a ZDO Mgmt Permit Joining request to all routers.",
                  "A single byte indicating how long the device should have permit joining turned on for. A value of 0xff turns on permit join indefinitely." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_find_joinable = \
  SL_CLI_COMMAND(findJoinableNetworkCommand,
                 "findJoinableNetwork",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_find_unused = \
  SL_CLI_COMMAND(findUnusedPanIdCommand,
                 "findUnusedPanId",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_change_hyphen_channel = \
  SL_CLI_COMMAND(networkChangeChannelCommand,
                 "Attempts to change device over to a different channel given in the channel argument.",
                  "The channel to change to" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_set = \
  SL_CLI_COMMAND(networkSetCommand,
                 "Sets the network index used by all future CLI commands.  Before executing a CLI command, the framework switches to this network.  After the command finishes executing, the framework switches back to the previous network.  The CLI uses the same network index until the device resets or it is changed through this command.",
                  "index" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_init = \
  SL_CLI_COMMAND(networkInitCommand,
                 "Initializes a network; this is a test command used for tc-swap-out testing.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_id = \
  SL_CLI_COMMAND(networkIdCommand,
                 "Prints the current Node ID, EUI64, and Pan ID.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_change_hyphen_keep_hyphen_alive_hyphen_mode = \
  SL_CLI_COMMAND(changeKeepAliveModeCommand,
                 "Switches between different keep alive modes supported by a router.",
                  "Keep alive mode" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_timeout_hyphen_option_hyphen_mask = \
  SL_CLI_COMMAND(networkChangeChildTimeoutOptionMaskCommand,
                 "Attempts to change the child timeout option mask to filter out undesirable values (e.g. no more than 3 days).",
                  "timeout option mask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_multi_hyphen_phy_hyphen_start = \
  SL_CLI_COMMAND(networkMultiPhyStartCommand,
                 "Used to start multi-PHY interface other than native and form the network. The stack uses same PanId as native radio network.",
                  "page" SL_CLI_UNIT_SEPARATOR "channel" SL_CLI_UNIT_SEPARATOR "power" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_INT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_network_multi_hyphen_phy_hyphen_stop = \
  SL_CLI_COMMAND(networkMultiPhyStopCommand,
                 "Terminates the multi-PHY interface",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_keys_print = \
  SL_CLI_COMMAND(keysPrintCommand,
                 "Prints all security keys.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_keys_clear = \
  SL_CLI_COMMAND(keysClearCommand,
                 "Clears all security keys.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_binding_hyphen_table_print = \
  SL_CLI_COMMAND(optionBindingTablePrintCommand,
                 "Prints the binding table to the command line.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_binding_hyphen_table_clear = \
  SL_CLI_COMMAND(optionBindingTableClearCommand,
                 "Clears the binding table.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_binding_hyphen_table_set = \
  SL_CLI_COMMAND(optionBindingTableSetCommand,
                 "Sets the binding table",
                  "index" SL_CLI_UNIT_SEPARATOR "cluster" SL_CLI_UNIT_SEPARATOR "localEp" SL_CLI_UNIT_SEPARATOR "remoteEp" SL_CLI_UNIT_SEPARATOR "eui64" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_print_hyphen_rx_hyphen_msgs_enable = \
  SL_CLI_COMMAND(optionPrintRxCommand,
                 "Enables printing of Rx messages.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_print_hyphen_rx_hyphen_msgs_disable = \
  SL_CLI_COMMAND(optionPrintRxCommand,
                 "Disables printing of Rx messages.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_register = \
  SL_CLI_COMMAND(optionRegisterCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_target = \
  SL_CLI_COMMAND(optionDiscoveryTargetCommand,
                 "",
                  "targetId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_disc = \
  SL_CLI_COMMAND(optionDiscoverCommand,
                 "",
                  "profileId" SL_CLI_UNIT_SEPARATOR "clusterId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_edb = \
  SL_CLI_COMMAND(optionEndDeviceBindCommand,
                 "",
                  "endpointId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_apsretry_on = \
  SL_CLI_COMMAND(optionApsRetryCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_apsretry_off = \
  SL_CLI_COMMAND(optionApsRetryCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_apsretry_default = \
  SL_CLI_COMMAND(optionApsRetryCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_aps_on = \
  SL_CLI_COMMAND(optionApsSecurityCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_aps_off = \
  SL_CLI_COMMAND(optionApsSecurityCommand,
                 "",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_security_set_hyphen_allow_hyphen_trust_hyphen_center_hyphen_rejoin_hyphen_using_hyphen_well_hyphen_known_hyphen_key = \
  SL_CLI_COMMAND(optionSecurityAllowTrustCenterRejoinUsingWellKnownKey,
                 "",
                  "Bool: allow trust center rejoin using well-known key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_security_set_hyphen_allow_hyphen_trust_hyphen_center_hyphen_rejoin_hyphen_using_hyphen_well_hyphen_known_hyphen_key_hyphen_timeout = \
  SL_CLI_COMMAND(optionSecurityAllowTrustCenterRejoinUsingWellKnownKeyTimeout,
                 "",
                  "timeout" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_security_set_hyphen_key_hyphen_request_hyphen_policy = \
  SL_CLI_COMMAND(optionSecuritySetKeyRequestPolicy,
                 "",
                  "TC link key request policy" SL_CLI_UNIT_SEPARATOR "App link key request policy" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_changekey_link = \
  SL_CLI_COMMAND(changeKeyCommand,
                 "",
                  "key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_changekey_network = \
  SL_CLI_COMMAND(changeKeyCommand,
                 "",
                  "key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_link = \
  SL_CLI_COMMAND(optionLinkCommand,
                 "",
                  "index" SL_CLI_UNIT_SEPARATOR "eui64" SL_CLI_UNIT_SEPARATOR "key" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_option_install_hyphen_code = \
  SL_CLI_COMMAND(optionInstallCodeCommand,
                 "",
                  "index" SL_CLI_UNIT_SEPARATOR "eui64" SL_CLI_UNIT_SEPARATOR "installCode" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_HEX, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_route = \
  SL_CLI_COMMAND(zdoRouteRequestCommand,
                 "Sends a ZDO route request command to the target.",
                  "target" SL_CLI_UNIT_SEPARATOR "index" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_power = \
  SL_CLI_COMMAND(zdoPowerDescriptorRequestCommand,
                 "Sends a ZDO Power Descriptor Request to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_mgmt_hyphen_lqi = \
  SL_CLI_COMMAND(zdoMgmtLqiCommand,
                 "Sends a ZDO MGMT-LQI (LQI Table) Request to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "startIndex" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_mgmt_hyphen_bind = \
  SL_CLI_COMMAND(zdoMgmtBindCommand,
                 "Sends a ZDO MGMT-Bind (Binding Table) Request to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "startIndex" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_leave = \
  SL_CLI_COMMAND(zdoLeaveRequestCommand,
                 "Sends a ZDO Management Leave command to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "removeChildren" SL_CLI_UNIT_SEPARATOR "rejoin" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_unbind_group = \
  SL_CLI_COMMAND(zdoUnbindGroupCommand,
                 "Sends an unbind request for a multicast binding to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "source eui64" SL_CLI_UNIT_SEPARATOR "source endpoint" SL_CLI_UNIT_SEPARATOR "clusterID" SL_CLI_UNIT_SEPARATOR "groupAddress" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_unbind_unicast = \
  SL_CLI_COMMAND(zdoUnbindUnicastCommand,
                 "Sends an unbind request for a unicast binding to the target device.",
                  "target" SL_CLI_UNIT_SEPARATOR "source eui64" SL_CLI_UNIT_SEPARATOR "source endpoint" SL_CLI_UNIT_SEPARATOR "clusterID" SL_CLI_UNIT_SEPARATOR "destinationEUI64" SL_CLI_UNIT_SEPARATOR "destination endpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_active = \
  SL_CLI_COMMAND(zdoActiveEpCommand,
                 "Sends an active endpoint request to the device with the given short ID.",
                  "nodeId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_bind = \
  SL_CLI_COMMAND(zdoBindCommand,
                 "Sends a ZDO Bind command to a device specified in the command arguments.",
                  "Destination" SL_CLI_UNIT_SEPARATOR "Source endpoint" SL_CLI_UNIT_SEPARATOR "Destination endpoint" SL_CLI_UNIT_SEPARATOR "clusterID" SL_CLI_UNIT_SEPARATOR "remoteEUI64" SL_CLI_UNIT_SEPARATOR "destEUI64" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_HEX, SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_node = \
  SL_CLI_COMMAND(zdoNodeCommand,
                 "Sends a node descriptor request to a given target device.",
                  "target" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_match = \
  SL_CLI_COMMAND(zdoMatchCommand,
                 "Sends a matchDescriptorsRequest to the given destination with the given profile.",
                  "nodeId" SL_CLI_UNIT_SEPARATOR "profile" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_simple = \
  SL_CLI_COMMAND(zdoSimpleCommand,
                 "Sends a simple descriptor request for the short address and endpoint specified.",
                  "dest" SL_CLI_UNIT_SEPARATOR "targetEndpoint" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_ieee = \
  SL_CLI_COMMAND(zdoIeeeAddressRequestCommand,
                 "Requests an IEEE address based on a given node ID.",
                  "nodeId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zdo_nwk = \
  SL_CLI_COMMAND(zdoNwkAddressRequestCommand,
                 "Sends a network address request for the given IEEE address.",
                  "ieee" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_HEX, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_scan_hyphen_chan_hyphen_mask = \
  SL_CLI_COMMAND(zdoNetworkUpdateScanCommand,
                 "Performs an energy scan on given channel mask.",
                  "targetNodeId" SL_CLI_UNIT_SEPARATOR "scanDuration" SL_CLI_UNIT_SEPARATOR "scanCount" SL_CLI_UNIT_SEPARATOR "channelMask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_set = \
  SL_CLI_COMMAND(zdoNetworkUpdateSetCommand,
                 "Broadcasts the ID of the new network manager and active channels.",
                  "nwkMgeId" SL_CLI_UNIT_SEPARATOR "channelMask" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_scan = \
  SL_CLI_COMMAND(zdoNetworkUpdateScanCommand,
                 "Performs an energy scan.",
                  "targetNodeId" SL_CLI_UNIT_SEPARATOR "scanDuration" SL_CLI_UNIT_SEPARATOR "scanCount" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_chanPg = \
  SL_CLI_COMMAND(zdoNetworkUpdateChannelCommand,
                 "Sends an update channel page req. The stack sends nwk enhanced update req for non-zero page.",
                  "channel" SL_CLI_UNIT_SEPARATOR "page" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_nwk_hyphen_upd_chan = \
  SL_CLI_COMMAND(zdoNetworkUpdateChannelCommand,
                 "Sends an update channel request.",
                  "channel" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_out_hyphen_cl_hyphen_list_add = \
  SL_CLI_COMMAND(zdoAddClusterCommand,
                 "Adds clusters to the known client (out) clusters on this device.",
                  "clusterId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_out_hyphen_cl_hyphen_list_clear = \
  SL_CLI_COMMAND(zdoClearClusterCommand,
                 "Clears the ZDO list of client (out) clusters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_in_hyphen_cl_hyphen_list_add = \
  SL_CLI_COMMAND(zdoAddClusterCommand,
                 "Adds clusters to the known client (in) clusters on this device.",
                  "clusterId" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_in_hyphen_cl_hyphen_list_clear = \
  SL_CLI_COMMAND(zdoClearClusterCommand,
                 "Clears the ZDO list of client (in) clusters.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_print_attr = \
  SL_CLI_COMMAND(emberAfPrintAttributeTable,
                 "Prints attribute.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_print_time = \
  SL_CLI_COMMAND(printTimeCommand,
                 "Prints time.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_form = \
  SL_CLI_COMMAND(formNetwork,
                 "Forms a ZLL network.",
                  "The channel on which to form the network" SL_CLI_UNIT_SEPARATOR "The power setting for network transmissions" SL_CLI_UNIT_SEPARATOR "The PAN identifier for the network" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_INT8, SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_scan_device = \
  SL_CLI_COMMAND(scanTouchLink,
                 "Initiates a Touchlink for the purpose of retrieving information about a target device.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_scan_identify = \
  SL_CLI_COMMAND(scanTouchLink,
                 "Initiates a Touchlink for the purpose of causing a target device to identify itself.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_scan_reset = \
  SL_CLI_COMMAND(scanTouchLink,
                 "Initiates a Touchlink for the purpose of resetting a target device.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_abort = \
  SL_CLI_COMMAND(abortTouchLink,
                 "Aborts the Touchlink procedure.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_link = \
  SL_CLI_COMMAND(initiateTouchLink,
                 "Initiates the Touchlink procedure.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_identify = \
  SL_CLI_COMMAND(setIdentifyDuration,
                 "Sets the duration that a target device should remain in identify mode during touchlinking.",
                  "The duration (in tenths of a second) of identify mode or 0xFFFF to indicate that the target should use its own application-specific duration." SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_info = \
  SL_CLI_COMMAND(endpointInformation,
                 "Sends an EndpointInformationRequest to a client.",
                  "The network address of the device to which the request will be sent" SL_CLI_UNIT_SEPARATOR "The source endpoint from which the request will be sent" SL_CLI_UNIT_SEPARATOR "The destination endpoint to which the request will be sent" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_groups = \
  SL_CLI_COMMAND(getGroupIdentifiersRequest,
                 "Sends a GroupIdentifiersRequest to a server.",
                  "The network address of the device to which the request will be sent" SL_CLI_UNIT_SEPARATOR "The source endpoint from which the request will be sent" SL_CLI_UNIT_SEPARATOR "The destination endpoint to which the request will be sent" SL_CLI_UNIT_SEPARATOR "The group table index at which to start retrieving data" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_endpoints = \
  SL_CLI_COMMAND(getEndpointListRequest,
                 "Sends a GetEndpointListRequest to a server.",
                  "The network address of the device to which the request will be sent" SL_CLI_UNIT_SEPARATOR "The source endpoint from which the request will be sent" SL_CLI_UNIT_SEPARATOR "The destination endpoint to which the request will be sent" SL_CLI_UNIT_SEPARATOR "The endpoint index at which to start retrieving data" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT16, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_tokens = \
  SL_CLI_COMMAND(printZllTokens,
                 "Print the ZLL tokens.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_channel = \
  SL_CLI_COMMAND(setScanChannel,
                 "Sets the scan channel used by the ZLL Commissioning plugin.",
                  "The primary channel to be used" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_secondary_hyphen_channel = \
  SL_CLI_COMMAND(setSecondaryScanChannel,
                 "Sets the scan channel used by the ZLL Commissioning plugin.",
                  "The secondary channel to be used" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_mask = \
  SL_CLI_COMMAND(setScanMask,
                 "Sets the scan channel set used by the ZLL Commissioning component. An index of 0 sets the primary ZLL channel set, 1 is the +1 channel set, 2 is the +2 channel set, 3 is the +3 channel set, and 4 is all Zigbee channels.",
                  "The index of the channel mask to be used" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT8, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_status = \
  SL_CLI_COMMAND(statusCommand,
                 "Prints the ZLL channel set and tokens",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_joinable = \
  SL_CLI_COMMAND(joinable,
                 "Scans for joinable networks and attempts to join if a network is found.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_unused = \
  SL_CLI_COMMAND(unused,
                 "Scans for an unused PAN identifier and forms a new ZLL network.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_reset = \
  SL_CLI_COMMAND(emberAfZllResetToFactoryNew,
                 "Resets the local device to factory new.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_notouchlink_hyphen_nfn = \
  SL_CLI_COMMAND(noTouchlinkForNFN,
                 "Disables Touchlinking (stealing) for an NFN device.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_noreset_hyphen_nfn = \
  SL_CLI_COMMAND(noResetForNFN,
                 "Disables reset for an NFN device on a centralized security network.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_disable = \
  SL_CLI_COMMAND(disable,
                 "Disables Touchlinking. This overrides the notouchlink-nfn and noreset-nfn commands.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_enable = \
  SL_CLI_COMMAND(enable,
                 "Enables Touchlinking. This overrides the notouchlink-nfn and noreset-nfn commands.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_set_hyphen_rx_hyphen_on = \
  SL_CLI_COMMAND(setRxOn,
                 "Sets Rx On When Idle duration.",
                  "The duration for the Rx On period" SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_UINT32, SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_cancel_hyphen_rx_hyphen_on = \
  SL_CLI_COMMAND(cancelRxOn,
                 "Cancels Rx On When Idle.",
                  "",
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd_zll_hyphen_commissioning_rx_hyphen_on_hyphen_active = \
  SL_CLI_COMMAND(rxOnStatus,
                 "Gets Rx On When Idle status.",
                  "",
                 {SL_CLI_ARG_END, });


// Create group command tables and structs if cli_groups given
// in template. Group name is suffixed with _group_table for tables
// and group commands are cli_cmd_grp_( group name )
static const sl_cli_command_entry_t address_hyphen_table_group_table[] = {
  { "add", &cli_cmd_address_hyphen_table_add, false },
  { "set", &cli_cmd_address_hyphen_table_set, false },
  { "remove", &cli_cmd_address_hyphen_table_remove, false },
  { "lookup", &cli_cmd_address_hyphen_table_lookup, false },
  { "print", &cli_cmd_address_hyphen_table_print, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_address_hyphen_table = \
  SL_CLI_COMMAND_GROUP(address_hyphen_table_group_table, "");

static const sl_cli_command_entry_t idle_hyphen_sleep_group_table[] = {
  { "status", &cli_cmd_idle_hyphen_sleep_status, false },
  { "force-awake", &cli_cmd_idle_hyphen_sleep_force_hyphen_awake, false },
  { "awake-when-not-joined", &cli_cmd_idle_hyphen_sleep_awake_hyphen_when_hyphen_not_hyphen_joined, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_idle_hyphen_sleep = \
  SL_CLI_COMMAND_GROUP(idle_hyphen_sleep_group_table, "Commands to control idling/sleeping of the device");

static const sl_cli_command_entry_t get_group_table[] = {
  { "address", &cli_cmd_get_address, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_get = \
  SL_CLI_COMMAND_GROUP(get_group_table, "Gets command group.");

static const sl_cli_command_entry_t gap_group_table[] = {
  { "print-connections", &cli_cmd_gap_print_hyphen_connections, false },
  { "stop-advertising", &cli_cmd_gap_stop_hyphen_advertising, false },
  { "set-mode", &cli_cmd_gap_set_hyphen_mode, false },
  { "set-bt5-mode", &cli_cmd_gap_set_hyphen_bt5_hyphen_mode, false },
  { "discover", &cli_cmd_gap_discover, false },
  { "conn-open", &cli_cmd_gap_conn_hyphen_open, false },
  { "set-adv-params", &cli_cmd_gap_set_hyphen_adv_hyphen_params, false },
  { "set-conn-params", &cli_cmd_gap_set_hyphen_conn_hyphen_params, false },
  { "update-conn-params", &cli_cmd_gap_update_hyphen_conn_hyphen_params, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_gap = \
  SL_CLI_COMMAND_GROUP(gap_group_table, "Generic Access Profile (GAP) related CLI commands");

static const sl_cli_command_entry_t sm_group_table[] = {
  { "increase-security", &cli_cmd_sm_increase_hyphen_security, false },
  { "list-all-bondings", &cli_cmd_sm_list_hyphen_all_hyphen_bondings, false },
  { "delete-bonding", &cli_cmd_sm_delete_hyphen_bonding, false },
  { "configure", &cli_cmd_sm_configure, false },
  { "delete-all-bondings", &cli_cmd_sm_delete_hyphen_all_hyphen_bondings, false },
  { "set-bondable-mode", &cli_cmd_sm_set_hyphen_bondable_hyphen_mode, false },
  { "confirm-passkey", &cli_cmd_sm_confirm_hyphen_passkey, false },
  { "enter-passkey", &cli_cmd_sm_enter_hyphen_passkey, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_sm = \
  SL_CLI_COMMAND_GROUP(sm_group_table, "Security related commands - See https://docs.silabs.com/bluetooth/latest/sm");

static const sl_cli_command_entry_t gatt_group_table[] = {
  { "discover-primary-services", &cli_cmd_gatt_discover_hyphen_primary_hyphen_services, false },
  { "discover-characteristics", &cli_cmd_gatt_discover_hyphen_characteristics, false },
  { "set-characteristic-notification", &cli_cmd_gatt_set_hyphen_characteristic_hyphen_notification, false },
  { "write-characteristic", &cli_cmd_gatt_write_hyphen_characteristic, false },
  { "close", &cli_cmd_gatt_close, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_gatt = \
  SL_CLI_COMMAND_GROUP(gatt_group_table, "Generic Attribute Profile (GATT) commands.");

static const sl_cli_command_entry_t system_group_table[] = {
  { "set-tx-power", &cli_cmd_system_set_hyphen_tx_hyphen_power, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_system = \
  SL_CLI_COMMAND_GROUP(system_group_table, "Bluetooth LE system commands.");

static const sl_cli_command_entry_t ble_group_table[] = {
  { "hello", &cli_cmd_ble_hello, false },
  { "get", &cli_cmd_grp_get, false },
  { "gap", &cli_cmd_grp_gap, false },
  { "sm", &cli_cmd_grp_sm, false },
  { "gatt", &cli_cmd_grp_gatt, false },
  { "system", &cli_cmd_grp_system, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_ble = \
  SL_CLI_COMMAND_GROUP(ble_group_table, "Contributes CLI commands to be used for initiating actions at the Bluetooth LE stack.");

static const sl_cli_command_entry_t concentrator_group_table[] = {
  { "status", &cli_cmd_concentrator_status, false },
  { "start", &cli_cmd_concentrator_start, false },
  { "stop", &cli_cmd_concentrator_stop, false },
  { "agg", &cli_cmd_concentrator_agg, false },
  { "print-table", &cli_cmd_concentrator_print_hyphen_table, false },
  { "set-router-behavior", &cli_cmd_concentrator_set_hyphen_router_hyphen_behavior, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_concentrator = \
  SL_CLI_COMMAND_GROUP(concentrator_group_table, "concentrator related commands.");

static const sl_cli_command_entry_t endpoints_group_table[] = {
  { "print", &cli_cmd_endpoints_print, false },
  { "enable", &cli_cmd_endpoints_enable, false },
  { "disable", &cli_cmd_endpoints_disable, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_endpoints = \
  SL_CLI_COMMAND_GROUP(endpoints_group_table, "endpoint related commands.");

static const sl_cli_command_entry_t mfg_hyphen_token_group_table[] = {
  { "get", &cli_cmd_mfg_hyphen_token_get, false },
  { "set", &cli_cmd_mfg_hyphen_token_set, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_mfg_hyphen_token = \
  SL_CLI_COMMAND_GROUP(mfg_hyphen_token_group_table, "Get/set MFG token.");

static const sl_cli_command_entry_t aps_group_table[] = {
  { "on", &cli_cmd_aps_on, false },
  { "off", &cli_cmd_aps_off, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_aps = \
  SL_CLI_COMMAND_GROUP(aps_group_table, "Security aps related commands.");

static const sl_cli_command_entry_t security_group_table[] = {
  { "set-allow-trust-center-rejoin-using-well-known-key", &cli_cmd_security_set_hyphen_allow_hyphen_trust_hyphen_center_hyphen_rejoin_hyphen_using_hyphen_well_hyphen_known_hyphen_key, false },
  { "set-allow-trust-center-rejoin-using-well-known-key-timeout", &cli_cmd_security_set_hyphen_allow_hyphen_trust_hyphen_center_hyphen_rejoin_hyphen_using_hyphen_well_hyphen_known_hyphen_key_hyphen_timeout, false },
  { "set-key-request-policy", &cli_cmd_security_set_hyphen_key_hyphen_request_hyphen_policy, false },
  { "mfg-token", &cli_cmd_grp_mfg_hyphen_token, false },
  { "aps", &cli_cmd_grp_aps, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_security = \
  SL_CLI_COMMAND_GROUP(security_group_table, "security related commands");

static const sl_cli_command_entry_t counters_group_table[] = {
  { "print", &cli_cmd_counters_print, false },
  { "print-counter-type", &cli_cmd_counters_print_hyphen_counter_hyphen_type, false },
  { "simple-print", &cli_cmd_counters_simple_hyphen_print, false },
  { "clear", &cli_cmd_counters_clear, false },
  { "print-thresholds", &cli_cmd_counters_print_hyphen_thresholds, false },
  { "set-threshold", &cli_cmd_counters_set_hyphen_threshold, false },
  { "reset-thresholds", &cli_cmd_counters_reset_hyphen_thresholds, false },
  { "send-request", &cli_cmd_counters_send_hyphen_request, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_counters = \
  SL_CLI_COMMAND_GROUP(counters_group_table, "counters related commands.");

static const sl_cli_command_entry_t enable_type_group_table[] = {
  { "stack", &cli_cmd_enable_type_stack, false },
  { "core", &cli_cmd_enable_type_core, false },
  { "app", &cli_cmd_enable_type_app, false },
  { "zcl", &cli_cmd_enable_type_zcl, false },
  { "legacy_af_debug", &cli_cmd_enable_type_legacy_af_debug, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_enable_type = \
  SL_CLI_COMMAND_GROUP(enable_type_group_table, "");

static const sl_cli_command_entry_t zigbee_print_group_table[] = {
  { "enable_type", &cli_cmd_grp_enable_type, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_zigbee_print = \
  SL_CLI_COMMAND_GROUP(zigbee_print_group_table, "");

static const sl_cli_command_entry_t find_and_bind_group_table[] = {
  { "target", &cli_cmd_find_and_bind_target, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_find_and_bind = \
  SL_CLI_COMMAND_GROUP(find_and_bind_group_table, "Find and bind related commands.");

static const sl_cli_command_entry_t green_hyphen_power_hyphen_client_group_table[] = {
  { "set-proxy-entry", &cli_cmd_green_hyphen_power_hyphen_client_set_hyphen_proxy_hyphen_entry, false },
  { "add-sink", &cli_cmd_green_hyphen_power_hyphen_client_add_hyphen_sink, false },
  { "add-group-sink", &cli_cmd_green_hyphen_power_hyphen_client_add_hyphen_group_hyphen_sink, false },
  { "rm-gpd", &cli_cmd_green_hyphen_power_hyphen_client_rm_hyphen_gpd, false },
  { "rm-sink", &cli_cmd_green_hyphen_power_hyphen_client_rm_hyphen_sink, false },
  { "print-proxy-table", &cli_cmd_green_hyphen_power_hyphen_client_print_hyphen_proxy_hyphen_table, false },
  { "clear-proxy-table", &cli_cmd_green_hyphen_power_hyphen_client_clear_hyphen_proxy_hyphen_table, false },
  { "duplicate-filter-test", &cli_cmd_green_hyphen_power_hyphen_client_duplicate_hyphen_filter_hyphen_test, false },
  { "set-key", &cli_cmd_green_hyphen_power_hyphen_client_set_hyphen_key, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_green_hyphen_power_hyphen_client = \
  SL_CLI_COMMAND_GROUP(green_hyphen_power_hyphen_client_group_table, "green-power-client related commands");

static const sl_cli_command_entry_t groups_hyphen_server_group_table[] = {
  { "print", &cli_cmd_groups_hyphen_server_print, false },
  { "clear", &cli_cmd_groups_hyphen_server_clear, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_groups_hyphen_server = \
  SL_CLI_COMMAND_GROUP(groups_hyphen_server_group_table, "groups-server related commands.");

static const sl_cli_command_entry_t identify_group_table[] = {
  { "print", &cli_cmd_identify_print, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_identify = \
  SL_CLI_COMMAND_GROUP(identify_group_table, "identify related commands");

static const sl_cli_command_entry_t interpan_group_table[] = {
  { "enable", &cli_cmd_interpan_enable, false },
  { "disable", &cli_cmd_interpan_disable, false },
  { "fragment-test", &cli_cmd_interpan_fragment_hyphen_test, false },
  { "set-msg-timeout", &cli_cmd_interpan_set_hyphen_msg_hyphen_timeout, false },
  { "group", &cli_cmd_interpan_group, false },
  { "short", &cli_cmd_interpan_short, false },
  { "long", &cli_cmd_interpan_long, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_interpan = \
  SL_CLI_COMMAND_GROUP(interpan_group_table, "interpan related commands.");

static const sl_cli_command_entry_t mask_group_table[] = {
  { "add", &cli_cmd_mask_add, false },
  { "subtract", &cli_cmd_mask_subtract, false },
  { "set", &cli_cmd_mask_set, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_mask = \
  SL_CLI_COMMAND_GROUP(mask_group_table, "mask related commands");

static const sl_cli_command_entry_t network_hyphen_creator_group_table[] = {
  { "start", &cli_cmd_network_hyphen_creator_start, false },
  { "stop", &cli_cmd_network_hyphen_creator_stop, false },
  { "form", &cli_cmd_network_hyphen_creator_form, false },
  { "status", &cli_cmd_network_hyphen_creator_status, false },
  { "mask", &cli_cmd_grp_mask, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_network_hyphen_creator = \
  SL_CLI_COMMAND_GROUP(network_hyphen_creator_group_table, "network-creator related commands.");

static const sl_cli_command_entry_t network_hyphen_creator_hyphen_security_group_table[] = {
  { "set-joining-link-key", &cli_cmd_network_hyphen_creator_hyphen_security_set_hyphen_joining_hyphen_link_hyphen_key, false },
  { "clear-joining-link-keys", &cli_cmd_network_hyphen_creator_hyphen_security_clear_hyphen_joining_hyphen_link_hyphen_keys, false },
  { "open-network", &cli_cmd_network_hyphen_creator_hyphen_security_open_hyphen_network, false },
  { "close-network", &cli_cmd_network_hyphen_creator_hyphen_security_close_hyphen_network, false },
  { "open-with-key", &cli_cmd_network_hyphen_creator_hyphen_security_open_hyphen_with_hyphen_key, false },
  { "set-distributed-key", &cli_cmd_network_hyphen_creator_hyphen_security_set_hyphen_distributed_hyphen_key, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_network_hyphen_creator_hyphen_security = \
  SL_CLI_COMMAND_GROUP(network_hyphen_creator_hyphen_security_group_table, "network-creator-security related commands.");

static const sl_cli_command_entry_t reporting_group_table[] = {
  { "print", &cli_cmd_reporting_print, false },
  { "clear", &cli_cmd_reporting_clear, false },
  { "remove", &cli_cmd_reporting_remove, false },
  { "add", &cli_cmd_reporting_add, false },
  { "clear-last-report-time", &cli_cmd_reporting_clear_hyphen_last_hyphen_report_hyphen_time, false },
  { "test-timing", &cli_cmd_reporting_test_hyphen_timing, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_reporting = \
  SL_CLI_COMMAND_GROUP(reporting_group_table, "reporting related commands.");

static const sl_cli_command_entry_t scenes_group_table[] = {
  { "print", &cli_cmd_scenes_print, false },
  { "clear", &cli_cmd_scenes_clear, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_scenes = \
  SL_CLI_COMMAND_GROUP(scenes_group_table, "scenes related commands.");

static const sl_cli_command_entry_t scan_group_table[] = {
  { "device", &cli_cmd_scan_device, false },
  { "identify", &cli_cmd_scan_identify, false },
  { "reset", &cli_cmd_scan_reset, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_scan = \
  SL_CLI_COMMAND_GROUP(scan_group_table, "scan related commands");

static const sl_cli_command_entry_t zll_hyphen_commissioning_group_table[] = {
  { "form", &cli_cmd_zll_hyphen_commissioning_form, false },
  { "abort", &cli_cmd_zll_hyphen_commissioning_abort, false },
  { "link", &cli_cmd_zll_hyphen_commissioning_link, false },
  { "identify", &cli_cmd_zll_hyphen_commissioning_identify, false },
  { "info", &cli_cmd_zll_hyphen_commissioning_info, false },
  { "groups", &cli_cmd_zll_hyphen_commissioning_groups, false },
  { "endpoints", &cli_cmd_zll_hyphen_commissioning_endpoints, false },
  { "tokens", &cli_cmd_zll_hyphen_commissioning_tokens, false },
  { "channel", &cli_cmd_zll_hyphen_commissioning_channel, false },
  { "secondary-channel", &cli_cmd_zll_hyphen_commissioning_secondary_hyphen_channel, false },
  { "mask", &cli_cmd_zll_hyphen_commissioning_mask, false },
  { "status", &cli_cmd_zll_hyphen_commissioning_status, false },
  { "joinable", &cli_cmd_zll_hyphen_commissioning_joinable, false },
  { "unused", &cli_cmd_zll_hyphen_commissioning_unused, false },
  { "reset", &cli_cmd_zll_hyphen_commissioning_reset, false },
  { "notouchlink-nfn", &cli_cmd_zll_hyphen_commissioning_notouchlink_hyphen_nfn, false },
  { "noreset-nfn", &cli_cmd_zll_hyphen_commissioning_noreset_hyphen_nfn, false },
  { "disable", &cli_cmd_zll_hyphen_commissioning_disable, false },
  { "enable", &cli_cmd_zll_hyphen_commissioning_enable, false },
  { "set-rx-on", &cli_cmd_zll_hyphen_commissioning_set_hyphen_rx_hyphen_on, false },
  { "cancel-rx-on", &cli_cmd_zll_hyphen_commissioning_cancel_hyphen_rx_hyphen_on, false },
  { "rx-on-active", &cli_cmd_zll_hyphen_commissioning_rx_hyphen_on_hyphen_active, false },
  { "scan", &cli_cmd_grp_scan, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_zll_hyphen_commissioning = \
  SL_CLI_COMMAND_GROUP(zll_hyphen_commissioning_group_table, "zll-commissioning related commands");

static const sl_cli_command_entry_t plugin_group_table[] = {
  { "address-table", &cli_cmd_grp_address_hyphen_table, false },
  { "idle-sleep", &cli_cmd_grp_idle_hyphen_sleep, false },
  { "ble", &cli_cmd_grp_ble, false },
  { "concentrator", &cli_cmd_grp_concentrator, false },
  { "counters", &cli_cmd_grp_counters, false },
  { "find_and_bind", &cli_cmd_grp_find_and_bind, false },
  { "green-power-client", &cli_cmd_grp_green_hyphen_power_hyphen_client, false },
  { "groups-server", &cli_cmd_grp_groups_hyphen_server, false },
  { "identify", &cli_cmd_grp_identify, false },
  { "interpan", &cli_cmd_grp_interpan, false },
  { "network-creator", &cli_cmd_grp_network_hyphen_creator, false },
  { "network-creator-security", &cli_cmd_grp_network_hyphen_creator_hyphen_security, false },
  { "reporting", &cli_cmd_grp_reporting, false },
  { "scenes", &cli_cmd_grp_scenes, false },
  { "zll-commissioning", &cli_cmd_grp_zll_hyphen_commissioning, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_plugin = \
  SL_CLI_COMMAND_GROUP(plugin_group_table, "");

static const sl_cli_command_entry_t find_group_table[] = {
  { "joinable", &cli_cmd_find_joinable, false },
  { "unused", &cli_cmd_find_unused, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_find = \
  SL_CLI_COMMAND_GROUP(find_group_table, "network find commands.");

static const sl_cli_command_entry_t network_group_table[] = {
  { "form", &cli_cmd_network_form, false },
  { "join", &cli_cmd_network_join, false },
  { "pjoin", &cli_cmd_network_pjoin, false },
  { "leave", &cli_cmd_network_leave, false },
  { "rejoin", &cli_cmd_network_rejoin, false },
  { "rejoin-diff-device-type", &cli_cmd_network_rejoin_hyphen_diff_hyphen_device_hyphen_type, false },
  { "extpanid", &cli_cmd_network_extpanid, false },
  { "isopen", &cli_cmd_network_isopen, false },
  { "broad-pjoin", &cli_cmd_network_broad_hyphen_pjoin, false },
  { "change-channel", &cli_cmd_network_change_hyphen_channel, false },
  { "set", &cli_cmd_network_set, false },
  { "init", &cli_cmd_network_init, false },
  { "id", &cli_cmd_network_id, false },
  { "change-keep-alive-mode", &cli_cmd_network_change_hyphen_keep_hyphen_alive_hyphen_mode, false },
  { "timeout-option-mask", &cli_cmd_network_timeout_hyphen_option_hyphen_mask, false },
  { "multi-phy-start", &cli_cmd_network_multi_hyphen_phy_hyphen_start, false },
  { "multi-phy-stop", &cli_cmd_network_multi_hyphen_phy_hyphen_stop, false },
  { "find", &cli_cmd_grp_find, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_network = \
  SL_CLI_COMMAND_GROUP(network_group_table, "Network related commands.");

static const sl_cli_command_entry_t keys_group_table[] = {
  { "print", &cli_cmd_keys_print, false },
  { "clear", &cli_cmd_keys_clear, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_keys = \
  SL_CLI_COMMAND_GROUP(keys_group_table, "Security keys related commands.");

static const sl_cli_command_entry_t binding_hyphen_table_group_table[] = {
  { "print", &cli_cmd_binding_hyphen_table_print, false },
  { "clear", &cli_cmd_binding_hyphen_table_clear, false },
  { "set", &cli_cmd_binding_hyphen_table_set, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_binding_hyphen_table = \
  SL_CLI_COMMAND_GROUP(binding_hyphen_table_group_table, "Binding table related commands.");

static const sl_cli_command_entry_t print_hyphen_rx_hyphen_msgs_group_table[] = {
  { "enable", &cli_cmd_print_hyphen_rx_hyphen_msgs_enable, false },
  { "disable", &cli_cmd_print_hyphen_rx_hyphen_msgs_disable, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_print_hyphen_rx_hyphen_msgs = \
  SL_CLI_COMMAND_GROUP(print_hyphen_rx_hyphen_msgs_group_table, "Enables/Disables printing of Rx messages.");

static const sl_cli_command_entry_t apsretry_group_table[] = {
  { "on", &cli_cmd_apsretry_on, false },
  { "off", &cli_cmd_apsretry_off, false },
  { "default", &cli_cmd_apsretry_default, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_apsretry = \
  SL_CLI_COMMAND_GROUP(apsretry_group_table, "APS retry flag force commands");

static const sl_cli_command_entry_t option_group_table[] = {
  { "register", &cli_cmd_option_register, false },
  { "target", &cli_cmd_option_target, false },
  { "disc", &cli_cmd_option_disc, false },
  { "edb", &cli_cmd_option_edb, false },
  { "link", &cli_cmd_option_link, false },
  { "install-code", &cli_cmd_option_install_hyphen_code, false },
  { "binding-table", &cli_cmd_grp_binding_hyphen_table, false },
  { "print-rx-msgs", &cli_cmd_grp_print_hyphen_rx_hyphen_msgs, false },
  { "apsretry", &cli_cmd_grp_apsretry, false },
  { "security", &cli_cmd_grp_security, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_option = \
  SL_CLI_COMMAND_GROUP(option_group_table, "Option related commands.");

static const sl_cli_command_entry_t changekey_group_table[] = {
  { "link", &cli_cmd_changekey_link, false },
  { "network", &cli_cmd_changekey_network, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_changekey = \
  SL_CLI_COMMAND_GROUP(changekey_group_table, "changekey related commands.");

static const sl_cli_command_entry_t unbind_group_table[] = {
  { "group", &cli_cmd_unbind_group, false },
  { "unicast", &cli_cmd_unbind_unicast, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_unbind = \
  SL_CLI_COMMAND_GROUP(unbind_group_table, "Zdo unbind related commands.");

static const sl_cli_command_entry_t nwk_hyphen_upd_group_table[] = {
  { "scan-chan-mask", &cli_cmd_nwk_hyphen_upd_scan_hyphen_chan_hyphen_mask, false },
  { "set", &cli_cmd_nwk_hyphen_upd_set, false },
  { "scan", &cli_cmd_nwk_hyphen_upd_scan, false },
  { "chanPg", &cli_cmd_nwk_hyphen_upd_chanPg, false },
  { "chan", &cli_cmd_nwk_hyphen_upd_chan, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_nwk_hyphen_upd = \
  SL_CLI_COMMAND_GROUP(nwk_hyphen_upd_group_table, "Zdo nwk-upd related commands.");

static const sl_cli_command_entry_t out_hyphen_cl_hyphen_list_group_table[] = {
  { "add", &cli_cmd_out_hyphen_cl_hyphen_list_add, false },
  { "clear", &cli_cmd_out_hyphen_cl_hyphen_list_clear, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_out_hyphen_cl_hyphen_list = \
  SL_CLI_COMMAND_GROUP(out_hyphen_cl_hyphen_list_group_table, "Zdo out-cl-list related commands.");

static const sl_cli_command_entry_t in_hyphen_cl_hyphen_list_group_table[] = {
  { "add", &cli_cmd_in_hyphen_cl_hyphen_list_add, false },
  { "clear", &cli_cmd_in_hyphen_cl_hyphen_list_clear, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_in_hyphen_cl_hyphen_list = \
  SL_CLI_COMMAND_GROUP(in_hyphen_cl_hyphen_list_group_table, "Zdo in-cl-list related commands.");

static const sl_cli_command_entry_t zdo_group_table[] = {
  { "route", &cli_cmd_zdo_route, false },
  { "power", &cli_cmd_zdo_power, false },
  { "mgmt-lqi", &cli_cmd_zdo_mgmt_hyphen_lqi, false },
  { "mgmt-bind", &cli_cmd_zdo_mgmt_hyphen_bind, false },
  { "leave", &cli_cmd_zdo_leave, false },
  { "active", &cli_cmd_zdo_active, false },
  { "bind", &cli_cmd_zdo_bind, false },
  { "node", &cli_cmd_zdo_node, false },
  { "match", &cli_cmd_zdo_match, false },
  { "simple", &cli_cmd_zdo_simple, false },
  { "ieee", &cli_cmd_zdo_ieee, false },
  { "nwk", &cli_cmd_zdo_nwk, false },
  { "unbind", &cli_cmd_grp_unbind, false },
  { "nwk-upd", &cli_cmd_grp_nwk_hyphen_upd, false },
  { "out-cl-list", &cli_cmd_grp_out_hyphen_cl_hyphen_list, false },
  { "in-cl-list", &cli_cmd_grp_in_hyphen_cl_hyphen_list, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_zdo = \
  SL_CLI_COMMAND_GROUP(zdo_group_table, "Zdo related commands.");

static const sl_cli_command_entry_t print_group_table[] = {
  { "attr", &cli_cmd_print_attr, false },
  { "time", &cli_cmd_print_time, false },
  { NULL, NULL, false },
};
static const sl_cli_command_info_t cli_cmd_grp_print = \
  SL_CLI_COMMAND_GROUP(print_group_table, "print related commands.");

// Create root command table
const sl_cli_command_entry_t sl_cli_default_command_table[] = {
  { "info", &cli_cmd__info, false },
  { "libs", &cli_cmd__libs, false },
  { "bsend", &cli_cmd__bsend, false },
  { "send", &cli_cmd__send, false },
  { "read", &cli_cmd__read, false },
  { "write", &cli_cmd__write, false },
  { "reset", &cli_cmd__reset, false },
  { "raw", &cli_cmd__raw, false },
  { "send_multicast", &cli_cmd__send_multicast, false },
  { "send-using-multicast-binding", &cli_cmd__send_hyphen_using_hyphen_multicast_hyphen_binding, false },
  { "timesync", &cli_cmd__timesync, false },
  { "get-pti-radio-config", &cli_cmd__get_hyphen_pti_hyphen_radio_hyphen_config, false },
  { "config-cca-mode", &cli_cmd__config_hyphen_cca_hyphen_mode, false },
  { "version", &cli_cmd__version, false },
  { "events", &cli_cmd__events, false },
  { "endpoints", &cli_cmd_grp_endpoints, false },
  { "security", &cli_cmd_grp_security, false },
  { "zigbee_print", &cli_cmd_grp_zigbee_print, false },
  { "plugin", &cli_cmd_grp_plugin, false },
  { "network", &cli_cmd_grp_network, false },
  { "net", &cli_cmd_grp_network, true },
  { "keys", &cli_cmd_grp_keys, false },
  { "option", &cli_cmd_grp_option, false },
  { "opt", &cli_cmd_grp_option, true },
  { "plugin", &cli_cmd_grp_plugin, false },
  { "plug", &cli_cmd_grp_plugin, true },
  { "changekey", &cli_cmd_grp_changekey, false },
  { "changek", &cli_cmd_grp_changekey, true },
  { "zdo", &cli_cmd_grp_zdo, false },
  { "print", &cli_cmd_grp_print, false },
  { NULL, NULL, false },
};


#ifdef __cplusplus
}
#endif
