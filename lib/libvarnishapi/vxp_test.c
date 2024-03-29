/*-
 * Copyright (c) 2014-2015 Varnish Software AS
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

#ifndef __FLEXELINT__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "miniobj.h"
#include "vdef.h"
#include "vqueue.h"
#include "vre.h"
#include "vas.h"

#include "vsb.h"

#include "vxp.h"

static void
usage(void)
{
	fprintf(stderr, "Usage: vxp_test -q <query-expression>\n");
	exit(1);
}

int
main(int argc, char * const *argv)
{
	struct vsb *vsb;
	struct vex *vex;
	char *q_arg = NULL;
	int opt;

	while ((opt = getopt(argc, argv, "q:")) != -1) {
		switch (opt) {
		case 'q':
			REPLACE(q_arg, optarg);
			break;
		default:
			usage();
		}
	}
	if (q_arg == NULL || optind != argc)
		usage();

	vsb = VSB_new_auto();
	AN(vsb);
	vex = vex_New(q_arg, vsb, 0);

	if (vex == NULL) {
		AZ(VSB_finish(vsb));
		fprintf(stderr, "Error:\n%s", VSB_data(vsb));
		VSB_destroy(&vsb);
		free(q_arg);
		exit(1);
	}
	VSB_destroy(&vsb);

	vex_Free(&vex);
	AZ(vex);
	free(q_arg);

	return (0);
}

#endif // __FLEXELINT__
