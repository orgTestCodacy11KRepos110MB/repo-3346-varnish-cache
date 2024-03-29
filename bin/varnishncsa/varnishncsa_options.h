/*-
 * Copyright (c) 2013 Varnish Software AS
 * All rights reserved.
 *
 * Author: Martin Blix Grydeland <martin@varnish-software.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "vapi/vapi_options.h"
#include "vut_options.h"

#define NCSA_OPT_a							\
	VOPT("a", "[-a]", "Append to file",				\
	    "When writing output to a file, append to it rather than"	\
	    " overwrite it. This option has no effect without the -w"	\
	    " option."							\
	)

#define NCSA_OPT_F							\
	VOPT("F:", "[-F <format>]", "Set output format",		\
	    "Set the output log format string."				\
	)

#define NCSA_OPT_f							\
	VOPT("f:", "[-f <formatfile>]", "Read output format from file", \
	    "Read output format from a file. Will read a single line"   \
	    " from the specified file, and use that line as the"	\
	    " format."							\
	)


#define NCSA_OPT_g							\
	VOPT("g:", "[-g <request|vxid>]", "Grouping mode (default: vxid)", \
	    "The grouping of the log records. The default is to group"	\
	    " by vxid."							\
	)

#define NCSA_OPT_w							\
	VOPT("w:", "[-w <filename>]", "Output filename",		\
	    "Redirect output to file. The file will be overwritten"	\
	    " unless the -a option was specified. If the application"	\
	    " receives a SIGHUP in daemon mode the file will be"	\
	    " reopened allowing the old one to be rotated away. This"	\
	    " option is required when running in daemon mode. If the"	\
	    " filename is -, varnishncsa writes to the standard output"	\
	    " and cannot work as a daemon."				\
	)
#define NCSA_OPT_b							\
	VOPT("b", "[-b]", "Backend mode",				\
	    "Log backend requests. If -c is not specified, then only"	\
	    " backend requests will trigger log lines."			\
	)
#define NCSA_OPT_c							\
	VOPT("c", "[-c]", "Client mode",				\
	    "Log client requests. This is the default. If -b is"	\
	    " specified, then -c is needed to also log client requests"	\
	)
#define NCSA_OPT_E							\
	VOPT("E", "[-E]", "Show ESI requests",				\
	    "Show ESI requests, implies client mode."			\
	)
#define NCSA_OPT_j							\
	VOPT("j", "[-j]", "Make output JSON-compatible",		\
	    "Make format-specifier replacements JSON-compatible. When"	\
	    " escaping characters, use JSON-style \\\\uXXXX escape"	\
	    " sequences instead of C-style \\\\xXX sequences. Empty"	\
	    " strings will be replaced with \"\" instead of \"-\", and"	\
	    " empty integers will be replaced with null. Use -F or -f"	\
	    " in combination with -j to write JSON logs."		\
	)

NCSA_OPT_a
NCSA_OPT_b
NCSA_OPT_c
VSL_OPT_C
VUT_OPT_d
VUT_GLOBAL_OPT_D
NCSA_OPT_E
NCSA_OPT_F
NCSA_OPT_f
NCSA_OPT_g
VUT_OPT_h
NCSA_OPT_j
VUT_OPT_k
VSL_OPT_L
VUT_OPT_n
VUT_GLOBAL_OPT_P
VUT_OPT_Q
VUT_OPT_q
VUT_OPT_r
VSL_OPT_R
VUT_OPT_t
VUT_GLOBAL_OPT_V
NCSA_OPT_w
