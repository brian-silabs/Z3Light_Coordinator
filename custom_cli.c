#include "sl_cli.h"
#include "sl_cli_config.h"
#include "sl_cli_command.h"
#include "sl_cli_arguments.h"
#include "sl_cli_handles.h"

#include "trust-center-nwk-key-update-broadcast.h"

void cliSeparatorHack(sl_cli_command_arg_t *arguments);

void changeNwkKey(sl_cli_command_arg_t *args)
{
  sl_zigbee_af_trust_center_start_network_key_update();
}

static const sl_cli_command_info_t cli_cmd__changeNwkKey = \
  SL_CLI_COMMAND(changeNwkKey,
                 "Starts the Update NWK Key Procedure manually, switch event is set for SL_ZIGBEE_BROADCAST_TABLE_TIMEOUT_QS",
                 SL_CLI_UNIT_SEPARATOR,
                 {SL_CLI_ARG_END, });

static const sl_cli_command_info_t cli_cmd___________________________ = \
  SL_CLI_COMMAND(cliSeparatorHack,
                "",
                  "",
                {SL_CLI_ARG_END, });

// Define the command table
const sl_cli_command_entry_t cli_custom_command_table[] = {
  { "___________________________", &cli_cmd___________________________, false },
  { "changeNwkKey", &cli_cmd__changeNwkKey, false },
  { "___________________________", &cli_cmd___________________________, false },
  { NULL, NULL, false },
};

sl_cli_command_group_t cli_custom_command_group =
{
  { NULL },
  false,
  cli_custom_command_table
};

void custom_cli_init(void)
{
  sl_cli_command_add_command_group(sl_cli_example_handle, &cli_custom_command_group);
}

void cliSeparatorHack(sl_cli_command_arg_t *args)
{
  (void) args;
}