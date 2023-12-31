/* GStreamer
 * Copyright (C) <2020> The GStreamer Contributors.
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


#ifndef __GST_CURL_ELEMENTS_H__
#define __GST_CURL_ELEMENTS_H__

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gst/gst.h>

void curl_element_init (GstPlugin * plugin);

#ifndef OHOS_EXT_FUNC
/* ohos.ext.func.0024 support https:
 */
GST_ELEMENT_REGISTER_DECLARE (curlfilesink);
GST_ELEMENT_REGISTER_DECLARE (curlftpsink);
GST_ELEMENT_REGISTER_DECLARE (curlhttpsink);
GST_ELEMENT_REGISTER_DECLARE (curlhttpsrc);
GST_ELEMENT_REGISTER_DECLARE (curlsftpsink);
GST_ELEMENT_REGISTER_DECLARE (curlsmtpsink);
#else
GST_ELEMENT_REGISTER_DECLARE (curlhttpsrc);
#endif

#endif /* __GST_CURL_ELEMENT_H__ */
