/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 * Copyright (C) <2003> David A. Schleef <ds@schleef.org>
 * Copyright (C) <2006> Wim Taymans <wim@fluendo.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "gst/gst-i18n-plugin.h"

#include "gstisomp4elements.h"


static gboolean
plugin_init (GstPlugin * plugin)
{
  gboolean ret = FALSE;

#ifndef OHOS_EXT_FUNC
  /* ohos.ext.func.0032 remove the unused features */
  ret |= GST_ELEMENT_REGISTER (qtdemux, plugin);
  ret |= GST_ELEMENT_REGISTER (rtpxqtdepay, plugin);
  ret |= GST_ELEMENT_REGISTER (qtmux, plugin);
  ret |= GST_ELEMENT_REGISTER (qtmoovrecover, plugin);
#else
  ret |= GST_ELEMENT_REGISTER (qtdemux, plugin);
  ret |= GST_ELEMENT_REGISTER (qtmux, plugin);
#endif

  return ret;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    isomp4,
    "ISO base media file format support (mp4, 3gpp, qt, mj2)",
    plugin_init, VERSION, "LGPL", GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN);
