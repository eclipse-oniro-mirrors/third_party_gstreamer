#!/usr/bin/env python3

import subprocess, sys, shlex

cfile = sys.argv[1]
hfile = sys.argv[2]
yfile = sys.argv[3]

args = ['-d', '-v', '-ppriv_gst_parse_yy', yfile, '-o', cfile]
bison = [r'/usr/bin/bison'] + shlex.split(r'')
subprocess.check_call(bison + args)

prefix = '''
#ifdef HAVE_CONFIG_H
#include<config.h>
#endif
'''

contents = open(cfile).read()
content = prefix + contents
open(cfile, 'w').write(contents)
