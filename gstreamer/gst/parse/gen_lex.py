#!/usr/bin/env python3

import subprocess, sys, shlex

cfile = sys.argv[1]
hfile = sys.argv[2]
lfile = sys.argv[3]
tabhfile = sys.argv[4]

args = ['--header-file=' + hfile, '-o', cfile, '-Ppriv_gst_parse_yy', lfile]
flex = [r'/usr/bin/flex'] + shlex.split(r'')
subprocess.check_call(flex + args)

prefix = '''#ifdef HAVE_CONFIG_H
#include<config.h>
#endif
'''
parse_snippet = '''void priv_gst_parse_yyset_column (int column_no , void * yyscanner);
void priv_gst_parse_yyset_column (int column_no , void * yyscanner)
'''

contents = open(cfile).read()
if not 'priv_gst_parse_yyget_column' in contents:
    contents = parse_snippet + contents
contents = prefix + contents

open(cfile, 'w').write(contents)
