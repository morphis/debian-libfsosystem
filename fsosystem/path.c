/* path.c generated by valac 0.14.2, the Vala compiler
 * generated from path.vala, do not modify */

/*
 * Copyright (C) 2011 Simon Busch <morphis@gravedo.de>
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
#include <sys/stat.h>


#define FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH (fso_framework_file_system_path_get_type ())
#define FSO_FRAMEWORK_FILE_SYSTEM_PATH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH, FsoFrameworkFileSystemPath))
#define FSO_FRAMEWORK_FILE_SYSTEM_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH, FsoFrameworkFileSystemPathClass))
#define FSO_FRAMEWORK_FILE_SYSTEM_IS_PATH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH))
#define FSO_FRAMEWORK_FILE_SYSTEM_IS_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH))
#define FSO_FRAMEWORK_FILE_SYSTEM_PATH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH, FsoFrameworkFileSystemPathClass))

typedef struct _FsoFrameworkFileSystemPath FsoFrameworkFileSystemPath;
typedef struct _FsoFrameworkFileSystemPathClass FsoFrameworkFileSystemPathClass;
typedef struct _FsoFrameworkFileSystemPathPrivate FsoFrameworkFileSystemPathPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _FsoFrameworkFileSystemPath {
	GObject parent_instance;
	FsoFrameworkFileSystemPathPrivate * priv;
};

struct _FsoFrameworkFileSystemPathClass {
	GObjectClass parent_class;
};

struct _FsoFrameworkFileSystemPathPrivate {
	gchar* _path;
};


static gpointer fso_framework_file_system_path_parent_class = NULL;

GType fso_framework_file_system_path_get_type (void) G_GNUC_CONST;
#define FSO_FRAMEWORK_FILE_SYSTEM_PATH_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH, FsoFrameworkFileSystemPathPrivate))
enum  {
	FSO_FRAMEWORK_FILE_SYSTEM_PATH_DUMMY_PROPERTY,
	FSO_FRAMEWORK_FILE_SYSTEM_PATH_PATH
};
FsoFrameworkFileSystemPath* fso_framework_file_system_path_new (const gchar* path);
FsoFrameworkFileSystemPath* fso_framework_file_system_path_construct (GType object_type, const gchar* path);
static void fso_framework_file_system_path_set_path (FsoFrameworkFileSystemPath* self, const gchar* value);
gboolean fso_framework_file_system_path_is_absolute (FsoFrameworkFileSystemPath* self);
const gchar* fso_framework_file_system_path_get_path (FsoFrameworkFileSystemPath* self);
gboolean fso_framework_file_system_path_is_mount_point (FsoFrameworkFileSystemPath* self);
static void fso_framework_file_system_path_finalize (GObject* obj);
static void _vala_fso_framework_file_system_path_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_fso_framework_file_system_path_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


FsoFrameworkFileSystemPath* fso_framework_file_system_path_construct (GType object_type, const gchar* path) {
	FsoFrameworkFileSystemPath * self = NULL;
	const gchar* _tmp0_;
	g_return_val_if_fail (path != NULL, NULL);
	self = (FsoFrameworkFileSystemPath*) g_object_new (object_type, NULL);
	_tmp0_ = path;
	fso_framework_file_system_path_set_path (self, _tmp0_);
	return self;
}


FsoFrameworkFileSystemPath* fso_framework_file_system_path_new (const gchar* path) {
	return fso_framework_file_system_path_construct (FSO_FRAMEWORK_FILE_SYSTEM_TYPE_PATH, path);
}


gboolean fso_framework_file_system_path_is_absolute (FsoFrameworkFileSystemPath* self) {
	gboolean result = FALSE;
	const gchar* _tmp0_;
	gboolean _tmp1_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_path;
	_tmp1_ = g_path_is_absolute (_tmp0_);
	result = _tmp1_;
	return result;
}


gboolean fso_framework_file_system_path_is_mount_point (FsoFrameworkFileSystemPath* self) {
	gboolean result = FALSE;
	struct stat a = {0};
	struct stat b = {0};
	const gchar* _tmp0_;
	gchar* _tmp1_ = NULL;
	gchar* parent_path;
	const gchar* _tmp2_;
	struct stat _tmp3_ = {0};
	gint _tmp4_ = 0;
	const gchar* _tmp5_;
	struct stat _tmp6_ = {0};
	gint _tmp7_ = 0;
	struct stat _tmp8_;
	dev_t _tmp9_;
	struct stat _tmp10_;
	dev_t _tmp11_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->priv->_path;
	_tmp1_ = g_path_get_dirname (_tmp0_);
	parent_path = _tmp1_;
	_tmp2_ = self->priv->_path;
	_tmp4_ = lstat (_tmp2_, &_tmp3_);
	a = _tmp3_;
	if (_tmp4_ < 0) {
		result = FALSE;
		_g_free0 (parent_path);
		return result;
	}
	_tmp5_ = parent_path;
	_tmp7_ = lstat (_tmp5_, &_tmp6_);
	b = _tmp6_;
	if (_tmp7_ < 0) {
		result = FALSE;
		_g_free0 (parent_path);
		return result;
	}
	_tmp8_ = a;
	_tmp9_ = _tmp8_.st_dev;
	_tmp10_ = b;
	_tmp11_ = _tmp10_.st_dev;
	result = _tmp9_ != _tmp11_;
	_g_free0 (parent_path);
	return result;
}


const gchar* fso_framework_file_system_path_get_path (FsoFrameworkFileSystemPath* self) {
	const gchar* result;
	const gchar* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_path;
	result = _tmp0_;
	return result;
}


static void fso_framework_file_system_path_set_path (FsoFrameworkFileSystemPath* self, const gchar* value) {
	const gchar* _tmp0_;
	gchar* _tmp1_;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = g_strdup (_tmp0_);
	_g_free0 (self->priv->_path);
	self->priv->_path = _tmp1_;
	g_object_notify ((GObject *) self, "path");
}


static void fso_framework_file_system_path_class_init (FsoFrameworkFileSystemPathClass * klass) {
	fso_framework_file_system_path_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (FsoFrameworkFileSystemPathPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_fso_framework_file_system_path_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_fso_framework_file_system_path_set_property;
	G_OBJECT_CLASS (klass)->finalize = fso_framework_file_system_path_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), FSO_FRAMEWORK_FILE_SYSTEM_PATH_PATH, g_param_spec_string ("path", "path", "path", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void fso_framework_file_system_path_instance_init (FsoFrameworkFileSystemPath * self) {
	self->priv = FSO_FRAMEWORK_FILE_SYSTEM_PATH_GET_PRIVATE (self);
}


static void fso_framework_file_system_path_finalize (GObject* obj) {
	FsoFrameworkFileSystemPath * self;
	self = FSO_FRAMEWORK_FILE_SYSTEM_PATH (obj);
	_g_free0 (self->priv->_path);
	G_OBJECT_CLASS (fso_framework_file_system_path_parent_class)->finalize (obj);
}


GType fso_framework_file_system_path_get_type (void) {
	static volatile gsize fso_framework_file_system_path_type_id__volatile = 0;
	if (g_once_init_enter (&fso_framework_file_system_path_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (FsoFrameworkFileSystemPathClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) fso_framework_file_system_path_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (FsoFrameworkFileSystemPath), 0, (GInstanceInitFunc) fso_framework_file_system_path_instance_init, NULL };
		GType fso_framework_file_system_path_type_id;
		fso_framework_file_system_path_type_id = g_type_register_static (G_TYPE_OBJECT, "FsoFrameworkFileSystemPath", &g_define_type_info, 0);
		g_once_init_leave (&fso_framework_file_system_path_type_id__volatile, fso_framework_file_system_path_type_id);
	}
	return fso_framework_file_system_path_type_id__volatile;
}


static void _vala_fso_framework_file_system_path_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	FsoFrameworkFileSystemPath * self;
	self = FSO_FRAMEWORK_FILE_SYSTEM_PATH (object);
	switch (property_id) {
		case FSO_FRAMEWORK_FILE_SYSTEM_PATH_PATH:
		g_value_set_string (value, fso_framework_file_system_path_get_path (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_fso_framework_file_system_path_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	FsoFrameworkFileSystemPath * self;
	self = FSO_FRAMEWORK_FILE_SYSTEM_PATH (object);
	switch (property_id) {
		case FSO_FRAMEWORK_FILE_SYSTEM_PATH_PATH:
		fso_framework_file_system_path_set_path (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



