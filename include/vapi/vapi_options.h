/*-
 * Copyright (c) 2006 Verdens Gang AS
 * Copyright (c) 2006-2014 Varnish Software AS
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

/* VSL options */

#define VSL_iI_PS							\
	"If a tag include option is the first of any tag selection"	\
	" options, all tags are first marked excluded."

#define VSL_OPT_b							\
	VOPT("b", "[-b]", "Only display backend records",		\
	    "Only display transactions and log records coming from"	\
	    " backend communication."					\
	)

#define VSL_OPT_c							\
	VOPT("c", "[-c]", "Only display client records",		\
	    "Only display transactions and log records coming from"	\
	    " client communication."					\
	)

#define VSL_OPT_C							\
	VOPT("C", "[-C]", "Caseless regular expressions",		\
	    "Do all regular expression and string matching caseless."	\
	)

#define VSL_OPT_E							\
	VOPT("E", "[-E]", "Display ESI transactions",			\
	    "Display ESI transactions and other types of sub-requests."	\
	    " This implies the -c option and includes other client"	\
	    " transactions."						\
	)

#define VSL_OPT_i							\
	VOPT("i:", "[-i <taglist>]", "Include tags",			\
	    "Include log records of these tags in output. Taglist is"   \
	    " a comma-separated list of tag globs. Multiple -i"		\
	    " options may be given.\n"					\
	    "\n"							\
	    VSL_iI_PS							\
	)

#define VSL_OPT_I							\
	VOPT("I:", "[-I <[taglist:]regex>]", "Include by regex",	\
	    "Include by regex matching. Output only records matching"	\
	    " taglist and regular expression. Applies to any tag if"	\
	    " taglist is absent. Multiple -I options may be given.\n"	\
	    "\n"							\
	    VSL_iI_PS							\
	)

#define VSL_OPT_L							\
	VOPT("L:", "[-L <limit>]", "Incomplete transaction limit",	\
	    "Sets the upper limit of incomplete transactions kept"	\
	    " before the oldest transaction is force completed. A"	\
	    " warning record is synthesized when this happens. This"	\
	    " setting keeps an upper bound on the memory usage of"	\
	    " running queries. Defaults to 1000 transactions."		\
	)

#define VSL_OPT_R							\
	VOPT("R:", "[-R <limit[/duration]>]", "Output rate limit",	\
	    "Restrict the output to the specified limit."		\
	    " Transactions exceeding the limit will be suppressed."	\
	    " The limit is specified as the maximum number of"		\
	    " transactions (with respect to the chosen grouping"	\
	    " method) and an optional time period. If no duration"	\
	    " is specified, a default of ``s`` is used. The duration"	\
	    " field can be formatted as in VCL (e.g. ``-R 10/2m``) or"	\
	    " as a simple time period without the prefix (e.g."		\
	    " ``-R 5/m``)."						\
	    " When in ``-g raw`` grouping mode, this setting can"	\
	    " not be used alongside ``-i``, ``-I``, ``-x`` or "		\
	    "``-X``, and we advise using ``-q`` instead."		\
	)

#define VSL_OPT_T							\
	VOPT("T:", "[-T <seconds>]", "Transaction end timeout",		\
	    "Sets the transaction timeout in seconds. This defines the"	\
	    " maximum number of seconds elapsed between a Begin tag"	\
	    " and the End tag. If the timeout expires, a warning"	\
	    " record is synthesized and the transaction is force"	\
	    " completed. Defaults to 120 seconds."			\
	)

#define VSL_OPT_v							\
	VOPT("v", "[-v]", "Verbose record printing",			\
	    "Use verbose output on record set printing, giving the"	\
	    " VXID on every log line. Without this option, the VXID"	\
	    " will only be given on the header of that transaction."	\
	)

#define VSL_OPT_x							\
	VOPT("x:", "[-x <taglist>]", "Exclude tags",			\
	    "Exclude log records of these tags in output. Taglist is"   \
	    " a comma-separated list of tag globs. Multiple -x"		\
	    " options may be given.\n"					\
	)

#define VSL_OPT_X							\
	VOPT("X:", "[-X <[taglist:]regex>]", "Exclude by regex",	\
	    "Exclude by regex matching. Do not output records matching"	\
	    " taglist and regular expression. Applies to any tag if"	\
	    " taglist is absent. Multiple -X options may be given.\n"	\
	)

/* VSC options */

#define VSC_OPT_f							\
	VOPT("f:", "[-f <glob>]", "Legacy field filtering glob",	\
	    "Legacy field filtering glob."				\
	    " Use backslash to escape characters. If the argument"	\
	    " starts with '^' it is used as an exclusive glob."		\
	    " Multiple -f arguments may be given. Legacy filtering"	\
	    " globs are run along with inclusion globs (-I arguments)"	\
	    " and exclusion globs (-X arguments) in order on a"		\
	    " first-match basis."					\
	)

#define VSC_OPT_I							\
	VOPT("I:", "[-I <glob>]", "Field inclusion glob",		\
	    "Field inclusion glob."					\
	    " Use backslash to escape characters. Multiple -I "		\
	    " arguments may be given. Exclusion globs are run in"	\
	    " order along with exclusion globs (-X arguments) and"	\
	    " legacy filtering globs (-f arguments) on a first-match"	\
	    " basis."							\
	)

#define VSC_OPT_X							\
	VOPT("X:", "[-X <glob>]", "Field exclusion glob",		\
	    "Field exclusion glob."					\
	    " Use backslash to escape characters. Multiple -X "		\
	    " arguments may be given. Exclusion globs are run in"	\
	    " order along with inclusion globs (-I arguments) and"	\
	    " legacy filtering globs (-f arguments) on a first-match"	\
	    " basis."							\
	)
