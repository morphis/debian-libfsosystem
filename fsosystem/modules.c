/* modules.c generated by valac 0.14.2, the Vala compiler
 * generated from modules.vala, do not modify */

/*
 * Copyright (C) 2011 Michael 'Mickey' Lauer <mlauer@vanille-media.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gstdio.h>
#include <errno.h>
#include <fcntl.h>

#define _g_free0(var) (var = (g_free (var), NULL))

typedef enum  {
	SYSTEM_ERROR_ERROR
} SystemError;
#define SYSTEM_ERROR system_error_quark ()


GQuark system_error_quark (void);
glong init_module (void* data, gulong length, const gchar* options);
glong delete_module (const gchar* name, guint flags);
void fso_framework_kernel_insertModule (const gchar* filename, const gchar* options, GError** error);
void fso_framework_kernel_removeModule (const gchar* filename, gboolean wait, gboolean force, GError** error);
void fso_framework_kernel_probeModule (const gchar* modulename, const gchar* options);


GQuark system_error_quark (void) {
	return g_quark_from_static_string ("system_error-quark");
}


/**
 * Insert a module into the running kernel
 **/
static const gchar* string_to_string (const gchar* self) {
	const gchar* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


void fso_framework_kernel_insertModule (const gchar* filename, const gchar* options, GError** error) {
	guint8* contents = NULL;
	gint contents_length1 = 0;
	gint _contents_size_ = 0;
	const gchar* _tmp0_;
	guint8* _tmp1_ = NULL;
	size_t _tmp2_;
	guint8* _tmp3_;
	gint _tmp3__length1;
	guint8* _tmp4_;
	gint _tmp4__length1;
	const gchar* _tmp5_;
	glong _tmp6_ = 0L;
	glong ok;
	glong _tmp7_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (filename != NULL);
	_tmp0_ = filename;
	g_file_get_contents (_tmp0_, (gchar**) (&_tmp1_), &_tmp2_, &_inner_error_);
	contents = (g_free (contents), NULL);
	contents = _tmp1_;
	contents_length1 = _tmp2_;
	_contents_size_ = contents_length1;
	if (_inner_error_ != NULL) {
		g_propagate_error (error, _inner_error_);
		contents = (g_free (contents), NULL);
		return;
	}
	_tmp3_ = contents;
	_tmp3__length1 = contents_length1;
	_tmp4_ = contents;
	_tmp4__length1 = contents_length1;
	_tmp5_ = options;
	_tmp6_ = init_module (_tmp3_, (gulong) _tmp4__length1, _tmp5_);
	ok = _tmp6_;
	_tmp7_ = ok;
	if (_tmp7_ != ((glong) 0)) {
		gint _tmp8_;
		const gchar* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		gchar* _tmp12_;
		GError* _tmp13_;
		GError* _tmp14_;
		_tmp8_ = errno;
		_tmp9_ = g_strerror (_tmp8_);
		_tmp10_ = string_to_string (_tmp9_);
		_tmp11_ = g_strconcat ("Can't insert module: ", _tmp10_, NULL);
		_tmp12_ = _tmp11_;
		_tmp13_ = g_error_new_literal (SYSTEM_ERROR, SYSTEM_ERROR_ERROR, _tmp12_);
		_tmp14_ = _tmp13_;
		_g_free0 (_tmp12_);
		_inner_error_ = _tmp14_;
		g_propagate_error (error, _inner_error_);
		contents = (g_free (contents), NULL);
		return;
	}
	contents = (g_free (contents), NULL);
}


/**
 * Remove a module out of the running kernel
 **/
void fso_framework_kernel_removeModule (const gchar* filename, gboolean wait, gboolean force, GError** error) {
	guint flags;
	gboolean _tmp0_;
	gboolean _tmp2_;
	const gchar* _tmp4_;
	guint _tmp5_;
	glong _tmp6_ = 0L;
	glong ok;
	glong _tmp7_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (filename != NULL);
	flags = (guint) (O_EXCL | O_NONBLOCK);
	_tmp0_ = wait;
	if (_tmp0_) {
		guint _tmp1_;
		_tmp1_ = flags;
		flags = _tmp1_ & (~O_NONBLOCK);
	}
	_tmp2_ = force;
	if (_tmp2_) {
		guint _tmp3_;
		_tmp3_ = flags;
		flags = _tmp3_ | O_TRUNC;
	}
	_tmp4_ = filename;
	_tmp5_ = flags;
	_tmp6_ = delete_module (_tmp4_, _tmp5_);
	ok = _tmp6_;
	_tmp7_ = ok;
	if (_tmp7_ != ((glong) 0)) {
		gint _tmp8_;
		const gchar* _tmp9_ = NULL;
		const gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		gchar* _tmp12_;
		GError* _tmp13_;
		GError* _tmp14_;
		_tmp8_ = errno;
		_tmp9_ = g_strerror (_tmp8_);
		_tmp10_ = string_to_string (_tmp9_);
		_tmp11_ = g_strconcat ("Can't insert module: ", _tmp10_, NULL);
		_tmp12_ = _tmp11_;
		_tmp13_ = g_error_new_literal (SYSTEM_ERROR, SYSTEM_ERROR_ERROR, _tmp12_);
		_tmp14_ = _tmp13_;
		_g_free0 (_tmp12_);
		_inner_error_ = _tmp14_;
		g_propagate_error (error, _inner_error_);
		return;
	}
}


/**
 * Load a module and its dependencies into the running kernel
 **/
void fso_framework_kernel_probeModule (const gchar* modulename, const gchar* options) {
	GError* _tmp0_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (modulename != NULL);
	_tmp0_ = g_error_new_literal (SYSTEM_ERROR, SYSTEM_ERROR_ERROR, "Not yet implemented");
	_inner_error_ = _tmp0_;
	g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
	g_clear_error (&_inner_error_);
	return;
}



