/*
 * Copyright (c) 2015 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <vlib/vlib.h>
#include <app/version.h>

static char * vpe_version_string = 
    "vpp v" VPP_BUILD_VER 
    " built by " VPP_BUILD_USER 
    " on " VPP_BUILD_HOST 
    " at " VPP_BUILD_DATE;
static char * vpe_dir_string = "Built in " VPP_BUILD_TOPDIR;

static clib_error_t *
show_vpe_version_command_fn (vlib_main_t * vm,
		 unformat_input_t * input,
		 vlib_cli_command_t * cmd)
{
  vlib_cli_output (vm, "%s", vpe_version_string);
  if (unformat (input, "verbose")){
     vlib_cli_output (vm, "%s", vpe_dir_string);
  }
  return 0;
}

VLIB_CLI_COMMAND (show_vpe_version_command, static) = {
  .path = "show version",
  .short_help = "show version information",
  .function = show_vpe_version_command_fn,
};

char * vpe_api_get_build_directory (void) 
{
  return VPP_BUILD_TOPDIR;
}

char * vpe_api_get_version (void) 
{
  return VPP_BUILD_VER;
}
char * vpe_api_get_build_date (void) 
{
  return VPP_BUILD_DATE;
}
